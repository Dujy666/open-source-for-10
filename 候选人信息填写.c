#include <stdio.h>
#include <stdlib.h>  
int find()
{
    FILE * fp = fopen("data.xls", "r");
	int a[7];
	int i=0;
    if (fp == NULL) {
        printf("�Ҳ����ļ�\n");
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
	printf("���β�������Ϊ��%d��\n",n);
	printf("-------------------------------\n");
	while(i<=n){
		printf("���%d��\n������",i);
		scanf("%s",s);
		printf("�绰��");
		scanf("%d",&phone);
		printf("ѧ�ţ�");
		scanf("%d",&code);
		fprintf(fp1,"%d\t%s\t%d\t%d\n",i,s,phone,code);
		i++;
		s[100]=0;
		printf("-------------------------------\n");
	}
	fclose(fp1);
}


		

