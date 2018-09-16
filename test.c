//test fopen("data.txt", "r")

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char name[20];
	char s;
	FILE *fp = NULL;
//	printf("Enter file name: \n");
//	fgets(name, 20, stdin);
	if((fp = fopen("data.txt", "r")) == NULL)
		printf("Fail");
	while(fgets(name, 20, fp))
	{
		printf("%s", name);
	}
	fclose(fp);
	return 0;
}
