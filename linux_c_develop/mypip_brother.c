#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

int main39()
{
	int fd[2];
	int ret;
	pid_t pid;

	//����һ���ܵ�
	ret = pipe(fd);
	if (ret < 0)
	{
		perror("pipe error");
		return -1;
	}

	int i = 0;
	int n = 2;
	for (i = 0; i < n; i++)
	{
		//�����ӽ���
		pid = fork();
		if (pid < 0)
		{
			perror("fork error");
			return -1;
		}
		else if (pid == 0)
		{
			break;
		}

	}

	if (i == n)
	{
		close(fd[0]);
		close(fd[1]);

		pid_t wpid;
		int status;

		while (1)
		{
			//�ȴ������ӽ���
			wpid = waitpid(-1, &status, WNOHANG);
			if (wpid == 0) //û���ӽ����˳�
			{
				sleep(1);
				continue;
			}
			else if (wpid == -1) //�Ѿ�û���ӽ���
			{
				printf("no child is living, wpid==[%d]\n", wpid);
				exit(0);
			}
			else if (wpid > 0)
			{
				if (WIFEXITED(status)) //�����˳�
				{
					printf("child normal exited, status==[%d]\n", WEXITSTATUS(status));
				}
				else if (WIFSIGNALED(status)) //���ź�ɱ��
				{
					printf("child killed by signo==[%d]\n", WTERMSIG(status));
				}
			}

		}
	}

	//��һ���ӽ���
	if (i == 0)
	{

		close(fd[0]);

		//����׼����ض��򵽹ܵ���д��
		dup2(fd[1], STDOUT_FILENO);
		execlp("ps", "ps", "aux", NULL);
		perror("execlp error");

		close(fd[1]);
	}

	//�ڶ����ӽ���
	if (i == 1)
	{
		printf("child: fpid==[%d], cpid==[%d]\n", getppid(), getpid());
		close(fd[1]);

		//����׼�����ض��򵽹ܵ�������
		dup2(fd[0], STDIN_FILENO);
		execlp("grep", "grep", "--color", "bash", NULL);
		perror("execlp error");

		close(fd[0]);
	}

	return 0;
}
