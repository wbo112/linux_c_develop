//signal函数测试---注册信号处理函数
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

//信号处理函数
void sighandler2(int signo)
{
	printf("signo==[%d]\n", signo);
}

int main38()
{
	//注册信号处理函数
	signal(SIGINT, sighandler2);


	while (1)
	{
		sleep(1);
		kill(getpid(), SIGINT);
	}

	return 0;
}
