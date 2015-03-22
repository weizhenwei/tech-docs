#include <stdio.h>

// typedef struct _short_test1 {
// 	unsigned int a:2;
// 	unsigned int b:3;
// 	unsigned int c:4;
// } short_test1;

typedef struct _short_test1 {
	unsigned int a:2;
	unsigned int b:3;
	unsigned int c:4;
} short_test1;



int main(int argc, char *argv[])
{
	short_test1 test;
	test.a = 3;
	test.b = 7;
	test.c = 10;
	printf("sizeof:%ld\n", sizeof(short_test1));
	printf("test.a:%d\n", test.a);
	printf("test.b:%d\n", test.b);
	printf("test.c:%d\n\n", test.c);

	printf("test.a:%u\n", test.a);
	printf("test.b:%u\n", test.b);
	printf("test.c:%u\n\n", test.c);

	return 0;
}
