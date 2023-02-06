//ʹ��pipe���ps aux | grep bash����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main22()
{
	//�����ܵ�
	//int pipe(int pipefd[2]);
	int fd[2];
	int ret = pipe(fd);
	if (ret < 0)
	{
		perror("pipe error");
		return -1;
	}

	//�����ӽ���
	pid_t pid = fork();
	if (pid < 0)
	{
		perror("fork error");
		return -1;
	}
	else if (pid > 0)
	{
		//�رն���
		close(fd[0]);

		//����׼����ض��򵽹ܵ���д��
		dup2(fd[1], STDOUT_FILENO);

		execlp("ps", "ps", "aux", NULL);

		perror("execlp error");
	}
	else
	{
		//�ر�д��
		close(fd[1]);

		//����׼�����ض��򵽹ܵ��Ķ���
		dup2(fd[0], STDIN_FILENO);

		execlp("grep", "grep", "--color=auto", "bash", NULL);

		perror("execlp error");
	}

	return 0;
}
