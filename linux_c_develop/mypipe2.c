#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
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
	printf("pipe size==[%ld]\n", fpathconf(fd[0], _PC_PIPE_BUF));
	printf("pipe size==[%ld]\n", fpathconf(fd[1], _PC_PIPE_BUF));

	//close(fd[0]);
	//write(fd[1], "hello world", strlen("hello world"));	

	//�ر�д��
	close(fd[1]);

	//���ùܵ��Ķ���Ϊ������
	//int flag = fcntl(fd[0], F_GETFL);
	//flag |= O_NONBLOCK;
	//fcntl(fd[0], F_SETFL, flag);

	char buf[64];
	memset(buf, 0x00, sizeof(buf));
	int n = read(fd[0], buf, sizeof(buf)); //����Ĭ�ϲ�����?
	printf("read over, n==[%d], buf==[%s]\n", n, buf);

	return 0;
}
