//signal��������---ע���źŴ�����
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

//�źŴ�����
void sighandler2(int signo)
{
	printf("signo==[%d]\n", signo);
}

int main38()
{
	//ע���źŴ�����
	signal(SIGINT, sighandler2);


	while (1)
	{
		sleep(1);
		kill(getpid(), SIGINT);
	}

	return 0;
}
