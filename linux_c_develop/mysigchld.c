//������ʹ��SICCHLD�ź���ɶ��ӽ��̵Ļ���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void waitchild1(int signo)
{
	pid_t wpid;

	//�����ӽ���
	while (1)
	{
		wpid = waitpid(-1, NULL, WNOHANG);
		if (wpid > 0)
		{
			printf("child is quit, wpid==[%d]\n", wpid);
		}
		else if (wpid == 0)
		{
			printf("child is living, wpid==[%d]\n", wpid);
			break;
		}
		else if (wpid == -1)
		{
			printf("no child is living, wpid==[%d]\n", wpid);
			break;
		}
	}
}

int main43()
{
	int i = 0;
	int n = 3;

	//��SIGCHLD�ź�����
	sigset_t mask;
	sigemptyset(&mask);
	sigaddset(&mask, SIGCHLD);
	sigprocmask(SIG_BLOCK, &mask, NULL);

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
		//ע���źŴ�����
		struct sigaction act;
		act.sa_handler = waitchild1;
		sigemptyset(&act.sa_mask);
		act.sa_flags = 0;
		sleep(5);
		sigaction(SIGCHLD, &act, NULL);

		//�����SIGCHLD�źŵ�����
		sigprocmask(SIG_UNBLOCK, &mask, NULL);

		while (1)
		{
			sleep(1);
		}
	}

	//��1���ӽ���
	if (i == 0)
	{
		printf("[%d]:child: cpid==[%d]\n", i, getpid());
		//sleep(1);
	}

	//��2���ӽ���
	if (i == 1)
	{
		printf("[%d]:child: cpid==[%d]\n", i, getpid());
		sleep(1);
	}

	//��3���ӽ���
	if (i == 2)
	{
		printf("[%d]:child: cpid==[%d]\n", i, getpid());
		sleep(1);
	}

	return 0;
}
