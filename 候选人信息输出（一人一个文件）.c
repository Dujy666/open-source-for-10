#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	FILE *fp1;
	int n = find();
	int i = 1;
	int num;
	int age;
	int phone;
	int student;
	int check_sex = 0;
	char name[20]={0};
	char sex[10]={0};
	char person[100]={0};
	char s[10];

	printf(" All participants :%d\n\n",n);
	while (i<=n){
		printf("No.%d participator:\n",i);
		printf("Student Number?");
		scanf("%d",&student);
		sprintf(s, "%d",student);
		fp1=fopen(s,"w");
		printf("Name:");
		fflush(stdin);
		scanf("%*c");
		scanf("%[^\n]",name);
		printf("sex (male:0 female:1):");
		scanf("%d",&check_sex);
		if(check_sex==1){
			strcpy(sex,"female");
		}else{
			strcpy(sex,"male");
		}
		printf("Age?");
		scanf("%d",&age);
		printf("Phone numbers?");
		scanf("%d",&phone);
		printf("Individual resume?");
		fflush(stdin);
		scanf("%*c");
		scanf("%[^\n]",person);
		

		fprintf(fp1,"%s\n%s\n%d\n%d\n%s",name,sex,age,phone,person);
		name[20]=0;
		sex[10]=0;
		person[100]=0;

		i++;
		fclose(fp1);
		printf("\n\n");
	}
}






