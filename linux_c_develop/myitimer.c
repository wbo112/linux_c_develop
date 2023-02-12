#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
void sighandler1(int no) {
	time_t now; //ʵ����time_t�ṹ    
	struct tm* timenow; //ʵ����tm�ṹָ��    

	time(&now);
	//time������ȡ���ڵ�ʱ��(���ʱ�׼ʱ��Ǳ���ʱ��)��Ȼ��ֵ��now    

	timenow = localtime(&now);
	//localtime�����Ѵ�timeȡ�õ�ʱ��now�����������е�ʱ��(���������õĵ���)    

	printf("Local time is %s/n", asctime(timenow));

	printf("alarm %d\n", no);
}

int main36() {
	struct itimerval val, old_val;
	struct timeval it_val, it_interval;

	it_val.tv_sec = 0;
	it_val.tv_usec = 1;
	it_interval.tv_sec = 1;
	it_interval.tv_usec = 1;
	val.it_interval = it_interval;
	val.it_value = it_val;
	signal(SIGALRM, sighandler1);
	setitimer(ITIMER_REAL, &val, &old_val);
	while (1) {
		sleep(1);
	}
	return 0;

}