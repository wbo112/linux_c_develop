//ѭ������n���ӽ���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main13()
{
	int i = 0;
	for (i = 0; i < 3; i++)
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
			printf("father: pid==[%d], fpid==[%d]\n", getpid(), getppid());
			//sleep(1);
		}
		else if (pid == 0) //�ӽ���
		{
			printf("child: pid==[%d], fpid==[%d]\n", getpid(), getppid());
			break;
		}
	}

	//��1���ӽ���
	if (i == 0)
	{
		printf("[%d]--[%d]: child\n", i, getpid());
	}

	//��2���ӽ���
	if (i == 1)
	{
		printf("[%d]--[%d]: child\n", i, getpid());
	}
	//��3���ӽ���
	if (i == 2)
	{
		printf("[%d]--[%d]: child\n", i, getpid());
	}
	//������
	if (i == 3)
	{
		printf("[%d]--[%d]: child\n", i, getpid());
	}
	sleep(10);

	return 0;
}
