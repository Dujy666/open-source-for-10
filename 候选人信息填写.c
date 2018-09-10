#include <stdio.h>
#include <stdlib.h>  
int find()
{
    FILE * fp = fopen("data.xls", "r");
	int a[7];
	int i=0;
    if (fp == NULL) {
        printf("找不到文件\n");
		exit(0);
    }
	while(i<7){
		
		fscanf(fp, "%d", &a[i]);
		i++;
	}
	fclose(fp);
    return (a[4]);
}

void main()
{
	FILE * fp1 = fopen("People_data.xls", "w");
	int n,i;
	int phone,code;
	char s[100]={0};
	n = find();
	i = 1;
	printf("本次参与人数为：%d。\n",n);
	printf("-------------------------------\n");
	while(i<=n){
		printf("编号%d：\n姓名：",i);
		scanf("%s",s);
		printf("电话：");
		scanf("%d",&phone);
		printf("学号：");
		scanf("%d",&code);
		fprintf(fp1,"%d\t%s\t%d\t%d\n",i,s,phone,code);
		i++;
		s[100]=0;
		printf("-------------------------------\n");
	}
	fclose(fp1);
}


		

