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
        printf("�޷����ļ� " );  
        exit(0);  
    }
	printf("�齱����\n");
	printf("------------------------------------------------------\n");
	printf("�齱��Ϣ��飺");
	scanf("%s",main_info);
	fprintf(fp,"�齱��Ϣ���\t   %s\n",main_info);
	printf("\n\n");
	printf("------------------------------------------------------\n");
	printf("��������");
	printf("\n");

	printf("һ�Ƚ�������");
	scanf("%d",&No1);
	printf("һ�Ƚ���Ʒ��");
	scanf("%s",No1_info);
	printf("\n");

	printf("���Ƚ�������");
	scanf("%d",&No2);
	printf("���Ƚ���Ʒ��");
	scanf("%s",No2_info);
	printf("\n");

	printf("���Ƚ�������");
	scanf("%d",&No3);
	printf("���Ƚ���Ʒ��");
	scanf("%s",No3_info);
	printf("\n");

	fprintf(fp,"һ�Ƚ�����\t   %d\n",No1);
	fprintf(fp,"һ�Ƚ���Ʒ\t   %s\n",No1_info);

	fprintf(fp,"���Ƚ�����\t   %d\n",No2);
	fprintf(fp,"���Ƚ���Ʒ\t   %s\n",No2_info);

	fprintf(fp,"���Ƚ�����\t   %d\n",No3);
	fprintf(fp,"���Ƚ���Ʒ\t   %s\n",No3_info);

	Prize_total=No1+No2+No3;
	printf("\n\n");
	printf("------------------------------------------------------\n");
	printf("��������");
	printf("\n");


	printf("�齱������������ڵ���%d����",Prize_total);
	scanf("%d",&People_total);
	while(People_total<Prize_total){
		printf("�������룺");
		scanf("%d",&People_total);
	}
	fprintf(fp,"�齱������\t   %d\n",People_total);
	printf("\n\n");
	printf("------------------------------------------------------\n");
	printf("��������");
	printf("\n");

	printf("�н���Ϣ�Ƿ��������=1 n=0����");
	scanf("%d",&Roll);
	fprintf(fp,"����\t   %d\n",Roll);
	printf("\n");

	printf("�н���Ϣ��ʾ��ʽ��\n��Ϣȫ����ʾ��1\n����+ѧ�ţ�2\n����+�绰��3\n���ַ�ʽ��");
	scanf("%d",&output);
	fprintf(fp,"��ʽ\t   %d\n",output);
	printf("\n\n");
	printf("------------------------------------------------------\n");
	fprintf(fp1,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t",No1,No2,No3,Prize_total,People_total,Roll,output);
    fclose(fp);
	fclose(fp1);
    return 0;  
}  