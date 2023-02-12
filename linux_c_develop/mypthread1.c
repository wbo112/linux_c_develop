#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <unistd.h>
#include <sys/syscall.h>


void* p(void* c) {
	printf("thread id=%d\n", pthread_self());
	printf("tid=%d\n", syscall(SYS_gettid));
	pid_t tid;

	tid = syscall(SYS_gettid);
	tid = syscall(SYS_tgkill, getpid(), tid);

	printf("ttid=%ld\n", tid);

}

int main33() {
	printf("pid=%d\n", getpid());
	pthread_t pthread;
	int n = pthread_create(&pthread, NULL, p, NULL);
	printf("n=%d\n", n);
	int retval;


	int ret = pthread_join(pthread, &retval);
	if (ret == 0) {
		printf("retval=%d\n", retval);
	}

	return 0;

}