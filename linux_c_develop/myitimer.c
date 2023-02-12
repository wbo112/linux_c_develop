#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
void sighandler1(int no) {
	time_t now; //实例化time_t结构    
	struct tm* timenow; //实例化tm结构指针    

	time(&now);
	//time函数读取现在的时间(国际标准时间非北京时间)，然后传值给now    

	timenow = localtime(&now);
	//localtime函数把从time取得的时间now换算成你电脑中的时间(就是你设置的地区)    

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