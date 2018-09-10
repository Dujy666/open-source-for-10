#include <stdio.h>  
#include <stdlib.h>  
int main()  
{  
    FILE *fp,*fp1;  
    int No1,No2,No3,Prize_total,People_total,Roll,output;
	char main_info[100],No1_info[50],No2_info[50],No3_info[50];
    fp=fopen("options.xls","w");
	fp1=fopen("data.xls","w");
    if(fp==NULL)  
    {  
        printf("无法打开文件 " );  
        exit(0);  
    }
	printf("抽奖设置\n");
	printf("------------------------------------------------------\n");
	printf("抽奖信息简介：");
	scanf("%s",main_info);
	fprintf(fp,"抽奖信息简介\t   %s\n",main_info);
	printf("\n\n");
	printf("------------------------------------------------------\n");
	printf("奖项设置");
	printf("\n");

	printf("一等奖数量：");
	scanf("%d",&No1);
	printf("一等奖奖品：");
	scanf("%s",No1_info);
	printf("\n");

	printf("二等奖数量：");
	scanf("%d",&No2);
	printf("二等奖奖品：");
	scanf("%s",No2_info);
	printf("\n");

	printf("三等奖数量：");
	scanf("%d",&No3);
	printf("三等奖奖品：");
	scanf("%s",No3_info);
	printf("\n");

	fprintf(fp,"一等奖数量\t   %d\n",No1);
	fprintf(fp,"一等奖奖品\t   %s\n",No1_info);

	fprintf(fp,"二等奖数量\t   %d\n",No2);
	fprintf(fp,"二等奖奖品\t   %s\n",No2_info);

	fprintf(fp,"三等奖数量\t   %d\n",No3);
	fprintf(fp,"三等奖奖品\t   %s\n",No3_info);

	Prize_total=No1+No2+No3;
	printf("\n\n");
	printf("------------------------------------------------------\n");
	printf("人数设置");
	printf("\n");


	printf("抽奖总人数（需大于等于%d）：",Prize_total);
	scanf("%d",&People_total);
	while(People_total<Prize_total){
		printf("重新输入：");
		scanf("%d",&People_total);
	}
	fprintf(fp,"抽奖总人数\t   %d\n",People_total);
	printf("\n\n");
	printf("------------------------------------------------------\n");
	printf("杂项设置");
	printf("\n");

	printf("中奖信息是否滚动（是=1 n=0）：");
	scanf("%d",&Roll);
	fprintf(fp,"滚动\t   %d\n",Roll);
	printf("\n");

	printf("中奖信息显示格式：\n信息全部显示：1\n姓名+学号：2\n姓名+电话：3\n那种方式？");
	scanf("%d",&output);
	fprintf(fp,"格式\t   %d\n",output);
	printf("\n\n");
	printf("------------------------------------------------------\n");
	fprintf(fp1,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t",No1,No2,No3,Prize_total,People_total,Roll,output);
    fclose(fp);
	fclose(fp1);
    return 0;  
}  