//�����̵���wait������ɶ��ӽ��̵Ļ���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int args,char * argv[])
{
	//�����ӽ���
	pid_t pid = fork();

	if (pid < 0) //forkʧ�ܵ����
	{
		perror("fork error");
		return -1;
	}
	else if (pid > 0)//������
	{
		pid_t pid1 = fork();
		if (pid1 == 0) {
			printf("pid1=%d\n", getpid());
			sleep(5);
			return 0;
		}
		printf("father: [%d], pid==[%d], fpid==[%d]\n", pid, getpid(), getppid());
		int status;
		pid_t wpid = 1;

		while (wpid!=-1) {

			wpid = waitpid(0, &status, WUNTRACED);
			printf("wpid==[%d]\n", wpid);

			if (WIFEXITED(status)) //�����˳�
			{
				printf("child normal exit, status==[%d]\n", WEXITSTATUS(status));
			}
			else if (WIFSIGNALED(status)) //���ź�ɱ��
			{
				printf("child killed by signal, signo==[%d]\n", WTERMSIG(status));
			}

		}
		}
		else if (pid == 0) //�ӽ���
		{

			printf("child: pid==[%d], fpid==[%d]\n", getpid(), getppid());
			sleep(60);
			return 9;
		}

		return 0;
	}
