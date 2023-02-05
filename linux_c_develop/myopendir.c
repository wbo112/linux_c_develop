//Ŀ¼��������: opendir readdir closedir
#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
//#define __USE_MISC

int main11(int argc, char* argv1[])
{
	char* argv[] = { "","." };
	//��Ŀ¼
	//DIR *opendir(const char *name);
	DIR* pDir = opendir(argv[1]);
	if (pDir == NULL)
	{
		perror("opendir error");
		return -1;
	}

	//ѭ����ȡĿ¼��
	//struct dirent *readdir(DIR *dirp);
	struct dirent* pDent = NULL;
	while ((pDent = readdir(pDir)) != NULL)
	{
		//���˵�.��..�ļ�
		if (strcmp(pDent->d_name, ".") == 0 || strcmp(pDent->d_name, "..") == 0)
		{
			continue;
		}

		printf("[%s]---->", pDent->d_name);

		//�ж��ļ�����,��Ҫ��Ӻ�_BSD_SOURCE
		switch (pDent->d_type)
		{
		case DT_REG:
			printf("��ͨ�ļ�");
			break;

		case DT_DIR:
			printf("Ŀ¼�ļ�");
			break;

		case DT_LNK:
			printf("�����ļ�");
			break;

		default:
			printf("δ֪�ļ�");
		}

		printf("\n");
	}

	//�ر�Ŀ¼
	closedir(pDir);

	return 0;
}
