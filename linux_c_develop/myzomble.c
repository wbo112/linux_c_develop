//��ʬ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main18()
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
		sleep(100);
		printf("father: [%d], pid==[%d], fpid==[%d]\n", pid, getpid(), getppid());
	}
	else if (pid == 0) //�ӽ���
	{

		printf("child: pid==[%d], fpid==[%d]\n", getpid(), getppid());
	}


	return 0;
}
