//�źż���غ�������
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

//�źŴ�����
void sighandler7(int signo)
{
	printf("signo==[%d]\n", signo);
}

int main47()
{

	//ע��SIGINT��SIGQUIT���źŴ�����
	signal(SIGINT, sighandler7);
	signal(SIGQUIT, sighandler7);

	//����sigset_t���͵ı���
	sigset_t pending, mask, oldmask;

	//��ʼ��
	sigemptyset(&pending);
	sigemptyset(&mask);
	sigemptyset(&oldmask);

	//��SIGINT��SIGQUIT���뵽�����źż���
	sigaddset(&mask, SIGINT);
	sigaddset(&mask, SIGQUIT);

	//��mask�е�SIGINT��SIGQUIT�źż��뵽�����źż���
	//sigprocmask(SIG_BLOCK, &mask, NULL);
	sigprocmask(SIG_BLOCK, &mask, &oldmask);

	int i = 1;
	int k = 1;
	while (1)
	{
		//��ȡδ���źż�
		sigpending(&pending);

		for (i = 1; i < 32; i++)
		{
			//�ж�ĳ���ź��Ƿ��ڼ�����
			if (sigismember(&pending, i) == 1)
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
		}
		printf("\n");

		if (k++ % 10 == 0)
		{
			//�������źż��н����SIGINT��SIGQUIT������
			//sigprocmask(SIG_UNBLOCK, &mask, NULL);	
			sigprocmask(SIG_SETMASK, &oldmask, NULL);
		}
		else
		{
			sigprocmask(SIG_BLOCK, &mask, NULL);
		}

		sleep(1);
	}

	return 0;
}
