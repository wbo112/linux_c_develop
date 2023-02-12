//ʹ��mmap���������������ɽ��̼�ͨ��
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main29()
{
	//ʹ��mmap������������ӳ����
	//void *mmap(void *addr, size_t length, int prot, int flags,
	//              int fd, off_t offset);
	int fd = open("./test.log", O_RDWR);
	if (fd < 0)
	{
		perror("open error");
		return -1;
	}

	int len = lseek(fd, 0, SEEK_END);

	//��������ӳ����
	void* addr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); //len��ӳ�������С
	if (addr == MAP_FAILED)
	{
		perror("mmap error");
		return -1;
	}

	memcpy(addr, "0123456789", 10);
	sleep(60);
	return 0;
}
