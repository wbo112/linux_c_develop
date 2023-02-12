//����fork���������ӽ���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void waitchild(int signo)
{
	printf("signo==[%d]\n", signo);
}

int main37()
{
	int i = 0;
	int n = 3;

	for (i = 0; i < n; i++)
	{
		//fork�ӽ���
		pid_t pid = fork();
		if (pid < 0) //forkʧ�ܵ����
		{
			perror("fork error");
			return -1;
		}
		else if (pid > 0) //������
		{
			printf("father: fpid==[%d], cpid==[%d]\n", getpid(), pid);
			sleep(1);
		}
		else if (pid == 0) //�ӽ���
		{
			printf("child: fpid==[%d], cpid==[%d]\n", getppid(), getpid());
			break;
		}
	}

	//������
	if (i == 3)
	{
		printf("[%d]:father: fpid==[%d]\n", i, getpid());
		//signal(SIGCHLD, waitchild);

		while (1)
		{
			sleep(10);
			//ɱ��һ��������
			kill(0, SIGKILL);
		}
	}

	//��1���ӽ���
	if (i == 0)
	{
		printf("[%d]:child: cpid==[%d]\n", i, getpid());
		sleep(100);
	}

	//��2���ӽ���
	if (i == 1)
	{
		printf("[%d]:child: cpid==[%d]\n", i, getpid());
		sleep(100);
	}

	//��3���ӽ���
	if (i == 2)
	{
		printf("[%d]:child: cpid==[%d]\n", i, getpid());
		sleep(100);
	}

	return 0;
}
