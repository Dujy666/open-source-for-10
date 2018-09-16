//normal output

#include <stdio.h>

int main(void)
{
	char enter[1000] = {0};
	char info[1000];
	FILE *fp = NULL;
	printf("Enter the student No. that you want to check:  \n");
	scanf("%s", enter);
	if((fp = fopen(enter, "r")) == NULL)
		printf("Fail");
	while(fgets(info, sizeof(info), fp))
		printf("%s", info);
	fclose(fp);
	return 0;
}

