//sigaction��������---ע���źŴ�����
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

//�źŴ�����
void sighandler5(int signo)
{
	printf("signo==[%d]\n", signo);
	sleep(4);
}

int main45()
{
	//ע���źŴ�����
	struct sigaction act;
	act.sa_handler = sighandler5;
	sigemptyset(&act.sa_mask);  //���źŴ�����ִ���ڼ�, �������κ��ź�
	sigaddset(&act.sa_mask, SIGQUIT);
	act.sa_flags = 0;
	sigaction(SIGINT, &act, NULL);


	signal(SIGQUIT, sighandler5);

	while (1)
	{
		sleep(10);
	}

	return 0;
}
