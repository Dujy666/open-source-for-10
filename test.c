//fopen("%s.txt", "r") error

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char name[20];
	char s;
	FILE *fp = NULL;
	printf("Enter file name: \n");
	fgets(name, 20, stdin);
	fp = fopen("%s.txt", "r");
	while((fgetc(fp)) != EOF)
		putchar(s);
	fclose(fp);
	return 0;
}
