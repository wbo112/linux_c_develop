//stat��������: ��ȡ�ļ���С, �ļ���������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main5(int argc, char* argv1[])
{
	char* argv[] = { "","a.txt" };
	//int stat(const char *pathname, struct stat *buf);
	struct stat st;
	stat(argv[1], &st);
	printf("size:[%d], uid:[%d], gid:[%d]\n", st.st_size, st.st_uid, st.st_gid);

	return 0;
}
