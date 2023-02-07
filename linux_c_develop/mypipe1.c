#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main21()
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
	printf("fd[0]=%d\t,fd[1]=%d\n", fd[0], fd[1]);
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
		sleep(5);
		write(fd[1], "hello world", strlen("hello world"));



		wait(NULL);
	}
	else
	{
	;
		//�ر�д��
		close(fd[1]);

		char buf[64];
		memset(buf, 0x00, sizeof(buf));
		ssize_t n = read(fd[0], buf, sizeof(buf));
		printf("read over, n==[%d], buf==[%s]\n", n, buf);

	}

	return 0;
}
