//����offset�������Խṹ���Ա������ƫ����
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main2(void)
{
	struct s
	{
		int i;
		char c;
		double d;
		char a[1];
	};

	/* Output is compiler dependent */

	printf("offsets: i=%zd; c=%zd; d=%zd a=%zd\n",
		offsetof(struct s, i), offsetof(struct s, c),
		offsetof(struct s, d), offsetof(struct s, a));
	printf("sizeof(struct s)=%zd\n", sizeof(struct s));

	return 0;
}
