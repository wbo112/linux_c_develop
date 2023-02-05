//fork��������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main12()
{
	printf("before fork, pid:[%d]\n", getpid());
	//�����ӽ���
	//pid_t fork(void);
	pid_t pid = fork();
	if (pid < 0) //forkʧ�ܵ����
	{
		perror("fork error");
		return -1;
	}
	else if (pid > 0)//������
	{
		printf("father: [%d], pid==[%d], fpid==[%d]\n", pid, getpid(), getppid());
		//sleep(1);
	}
	else if (pid == 0) //�ӽ���
	{
		printf("child: pid==[%d], fpid==[%d]\n", getpid(), getppid());
	}

	printf("after fork, pid:[%d]\n", getpid());

	return 0;
}
