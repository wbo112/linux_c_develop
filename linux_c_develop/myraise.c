//raise��abort������-
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

//�źŴ�����
void sighandler4(int signo)
{
	printf("signo==[%d]\n", signo);
}

int main40()
{
	//ע���źŴ�����
	signal(SIGINT, sighandler4);

	//����ǰ���̷���SIGINT�ź�
	raise(SIGINT);

	//����ǰ���̷���SIGABRT
	abort();

	while (1)
	{
		sleep(10);
	}

	return 0;
}
