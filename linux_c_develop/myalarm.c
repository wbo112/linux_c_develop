//signal��������---ע���źŴ�����
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

//�źŴ�����
void sighandler(int signo)
{
	printf("signo==[%d]\n", signo);
}

int main34()
{
	//ע���źŴ�����
	//signal(SIGINT, sighandler);
	signal(SIGALRM, sighandler);

	int n = alarm(5);
	printf("first: n==[%d]\n", n);

	sleep(2);
	n = alarm(5);
	//n = alarm(0); //ȡ��ʱ��
	printf("second: n==[%d]\n", n);


	sleep(10);//alarm�źŻ�ʹsleep��ǰ����


	return 0;
}
