//测试1秒钟可以数多少数字
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <unistd.h>
int main35()
{
	char buf[1024];
	getcwd(buf,1024-1);
	printf("cwd =%s\n", buf);
	alarm(1);
	int i = 0;
	while (1)
	{
		printf("[%d]", i++);
	}

	return 0;
}
