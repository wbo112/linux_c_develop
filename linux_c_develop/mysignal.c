//signal��������---ע���źŴ�����
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

//�źŴ�����
void sighandler6(int signo)
{
	printf("signo==[%d]\n", signo);
}

int main46()
{
	//ע���źŴ�����
	signal(SIGINT, sighandler6);

	//while(1)
	{
		sleep(10);
	}

	return 0;
}
