//File name:function.c
//Author:Group 10
//Annotation:2018.10.9


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<termios.h>
#include<curses.h>
#include<term.h>
#include<string.h>

static struct termios initial_settings,new_settings;
static int peek_character=-1;
static int alltimes;

//Configure the terminal at the beginning of the program.
void init_keyboard(){
	tcgetattr(0,&initial_settings);
	new_settings=initial_settings;
	new_settings.c_lflag &=~ICANON;
	new_settings.c_lflag &=~ECHO;
	new_settings.c_lflag &=~ISIG;
	new_settings.c_cc[VMIN]=1;
	new_settings.c_cc[VTIME]=0;
	tcsetattr(0,TCSANOW,&new_settings);
}

//Detection keyboard
int kbhit(){
	char ch;
	int nread;
	if(peek_character !=-1) return -1;
	new_settings.c_cc[VMIN]=0;
	tcsetattr(0,TCSANOW,&new_settings);
	nread=read(0,&ch,1);
	new_settings.c_cc[VMIN]=1;
	tcsetattr(0,TCSANOW,&new_settings);
	if(nread==1){
		peek_character=ch;
		return 1;
	}
	return 0;
}

//Configure the terminal at the end of the program.
void close_keyboard(){
	tcsetattr(0,TCSANOW,&initial_settings);
}

//Buffer clear
void buffer_clear()
{
	fflush(stdin);
	scanf("%*c");
}

//Read the data in the lottery Settings from the data.xls
int get_data(int n)
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
    return (a[n]);
}

//Check files
void Check()
{
	
   	int choice1;
	char filename[80];
	FILE *fpcheck;
	char check1[20];
	char put;
	int i = 1;
	printf("1:Check files\n2:Go back\n");
    	while (1)
    	{
    	    scanf("%d", &choice1);
    	    system("clear");
    	    switch (choice1)
    	    {
    	        case 1: 
			while(i==1){
				//User enter a file's name,find and check.
				printf("Enter file's name to check:");
				scanf("%s",check1);
				fpcheck = fopen(check1,"r");
				while((put=fgetc(fpcheck))!=EOF)
       					fputc(put,stdout);
				fclose(fpcheck);

				//Asking for a new run.
				printf("\nKeep checking?(Y:1 N:0):");
				scanf("%d",&i);
			}
			system("clear");
			Check();
    	                break;
    	        case 2: system("clear");
			break;
        }
        }
}

//Scroll and lottery 
void rollandprint(char x[],int y,int jde,int info)
{
	int ch=0;
	char d[10];
	int a,b;
	//Initialization keyboard and random seed.
	init_keyboard();
	srand(time(NULL));

	
	a=x[rand()%y];
	
	printf("\n");

	//If user wants to roll
	if(jde==1){
		while(!kbhit()){
			a=x[rand()%y];
			usleep(100000);
			printf("\033[2A\n");
			printf("\033[31m %d\033[47m\n",a);
			printf("\033[0m");
		}
	}

	//If a number was selected,then deleted it.
	b = a;
	for(int i=0;i<y;i++){
		if(b==x[i]){
			for(int j=i;j<y;j++)
			x[j]=x[j+1];
			x[y-1]=0;
			break;
		}
	}
	printf("\n");
	
	sprintf(d, "%d",b);
	FILE *fp1 = fopen(d,"r");

	FILE *fp2 = fopen("result.txt","a");
	char chd;
	char line[1024];
	char line1[1024];
	char blank[] = "\n";
	int i=0;
	if(info == 1){
		while((chd=fgetc(fp1))!=EOF)
       			fputc(chd,stdout);
		rewind(fp1);//Reset the pointer
		while(i<5){
			fgets(line1,1024,fp1); //read a line and locate to next line
			fprintf(fp2,"%s",line1);//write into result.txt
			i++;
			}
			fprintf(fp2,"%s",blank);//Add a \n
	}
	if(info == 2){
		while(!feof(fp1)){
			if(i==1){
				fgets(line,1024,fp1);//read a line 
				printf("%s",line);
				fprintf(fp2,"%s",line);
			}
			fgets(line,1024,fp1);//read a line and locate to next line.Lower part the same.   
			i++;
		}
		rewind(fp1);
		i = 0;
		while(!feof(fp1)){
			if(i==0){
				fgets(line,1024,fp1);
				printf("%s",line);
				fprintf(fp2,"%s\n",line);
			}
			fgets(line,1024,fp1);
			i++;
		}
	}
	if(info == 3){
		while(!feof(fp1)){
			if(i==1){
				fgets(line,1024,fp1);
				printf("%s",line);
				fprintf(fp2,"%s",line);
			}
			fgets(line,1024,fp1);
			i++;
		}
		rewind(fp1);
		i = 0;
		while(!feof(fp1)){
			if(i==4){
				fgets(line,1024,fp1);
				printf("%s",line);
				fprintf(fp2,"%s\n",line);
			}
			fgets(line,1024,fp1);
			i++;
		}
	}
	
 
	close_keyboard();
	fclose(fp1);
	fclose(fp2);
	printf("\n");
	
	
}



//Carry out lottery settings
void Display_Rules()
{
    FILE *fp, *fp1;
    int No1, No2, No3, Prize_total, People_total, Roll, output;
    char main_info[100], No1_info[50], No2_info[50], No3_info[50];
    fp = fopen("options.xls", "w");
    fp1 = fopen("data.xls", "w");

    if(fp == NULL)
    {
        printf("Could not open file!");
        exit(0);
    }
    if(fp1 == NULL)
    {
        printf("Could not open file!");
        exit(0);
    }

    
    printf("Lottery setting\n");
    printf("------------------------------------------------------\n");

    //Enter lottery info and write into file
    printf("Lottery info：");
    scanf("%*c");
    scanf("%[^\n]", main_info);
    fprintf(fp, "抽奖信息简介\t   %s\n", main_info);

    printf("\n\n");
    printf("------------------------------------------------------\n");

    //Set your awards and write into file.
    printf("Award setting");
    printf("\n");

    printf("The number of the first prize：");
    scanf("%d", &No1);
    printf("The prizes of the first prize：");
    scanf("%*c");
    scanf("%[^\n]", No1_info);
    printf("\n");

    printf("The number of the second prize：");
    scanf("%d", &No2);
    printf("The prizes of the second prize：");
    scanf("%*c");
    scanf("%[^\n]", No2_info);
    printf("\n");

    printf("The number of the third prize：");
    scanf("%d", &No3);
    printf("The prizes of the third prize：");
    scanf("%*c");
    scanf("%[^\n]", No3_info);
    printf("\n");

    fprintf(fp, "一等奖数量\t   %d\n", No1);
    fprintf(fp, "一等奖奖品\t   %s\n", No1_info);

    fprintf(fp, "二等奖数量\t   %d\n", No2);
    fprintf(fp, "二等奖奖品\t   %s\n", No2_info);

    fprintf(fp, "三等奖数量\t   %d\n", No3);
    fprintf(fp, "三等奖奖品\t   %s\n", No3_info);

	
    Prize_total = No1 + No2 + No3;
    printf("\n\n");
    printf("------------------------------------------------------\n");
    printf("Participants setting");
    printf("\n");

    //Number of participants
    printf("The number of participant（must be >= %d）：", Prize_total);
    scanf("%d", &People_total);
    while(People_total < Prize_total){
        printf("Enter again：");
        scanf("%d", &People_total);
    }
    fprintf(fp, "抽奖总人数\t   %d\n", People_total);

    printf("\n\n");
    printf("------------------------------------------------------\n");

    printf("Other setting");
    printf("\n");

    //Roll selection
    printf("Winners' info roll or not?（Y = 1 N = 0）：");
    scanf("%d", &Roll);
    fprintf(fp, "滚动\t   %d\n", Roll);
    printf("\n");

    //Winning message display format 
    printf("The format of winners' info：\nall of info：1\n"
           "Name + Student No.：2\nName + Tel：3\nWhat kind of format "
           "do you like？");
    scanf("%d", &output);
    fprintf(fp, "格式\t   %d\n", output);

    printf("\n\n");
    printf("------------------------------------------------------\n");

    //Write all options into file
    fprintf(fp1, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t", No1, No2, No3, Prize_total,
            People_total, Roll, output);
    
    fclose(fp);
    fclose(fp1);
  
}

//Enter candidate information(one man,one file)
void Sign_Up()
{
    
	FILE *fp2;
	int n = get_data(4);
	int i = 1;
	int num;
	int age;
	char phone[20]={0};
	char student[20]={0};
	int check_sex = 0;
	char name[20]={0};
	char sex[10]={0};
	char person[100]={0};
	char s[10];

	printf(" All participants :%d\n\n",n);
	while (i<=n){
		buffer_clear();
		
		//Enter student number
		printf("No.%d participator:\n",i);
		printf("Student Number?");
		scanf("%[^\n]",student);
		buffer_clear();

		//Creat a candidate information file with the name of the candidate number
		sprintf(s, "%d",i);
		fp2=fopen(s,"w");

		//Enter student's name
		printf("Name:");
		buffer_clear();
		scanf(" %[^\n]",name);

		//Sex selection
		printf("sex (male:0 female:1):");
		scanf("%d",&check_sex);
		if(check_sex==1){
			strcpy(sex,"female");
		}else{
			strcpy(sex,"male");
		}

		//Enter age
		printf("Age?");
		scanf("%d",&age);

		//Enter phone number
		printf("Phone numbers?");
		buffer_clear();
		scanf("%[^\n]",phone);

		//Enter personal resume
		printf("Individual resume?");
		buffer_clear();
		scanf("%[^\n]",person);
		
		//Write all informaitons into candidate's file
		fprintf(fp2,"Student number:%s\nName：%s\nSex：%s\nAge：%d\nPhone：%s\nResume：%s",student,name,sex,age,phone,person);
		name[20]=0;
		sex[10]=0;
		person[100]=0;
		phone[20]=0;
		student[20]=0;

		i++;
		fclose(fp2);
		printf("\n\n");
	
	}
}


//Active lottery and save results.
void start()
{
	int first = get_data(0);
	int second = get_data(1);
	int third = get_data(2);
	int i;
	int nums = get_data(4);
	int roll = get_data(5);
	int print = get_data(6);
	char jishu[nums];
	int chs = 0; 
	char first_prize[] = "一等奖";
	char second_prize[] = "二等奖";
	char third_prize[] = "三等奖";
	
	FILE *fp = fopen("result.txt","w");
	fprintf(fp,"%s\n",third_prize);
	fclose(fp);
	for(int k=1;k<=nums;k++){
		jishu[chs]=k;
		chs++;
	}
	
	for(i=0;i<third;i++){
		rollandprint(jishu,nums,roll,print);
		printf("Congratulations! You got third prize!\n");
		nums--;
		buffer_clear();
		printf("------------------------------------------\n");
	}
	FILE *fp1 = fopen("result.txt","a");
	fprintf(fp1,"%s\n",second_prize);
	fclose(fp1);
	i=0;
	for(i=0;i<second;i++){
		
		rollandprint(jishu,nums,roll,print);
		printf("Congratulations! You got second prize!\n");
		nums--;
		buffer_clear();
		printf("-----------------------------------------\n");
	}
	FILE *fp2 = fopen("result.txt","a");
	fprintf(fp2,"%s\n",first_prize);
	fclose(fp2);
	i=0;
	for(i=0;i<first;i++){
		
		rollandprint(jishu,nums,roll,print);	
		printf("Congratulations! You got first prize!\n");
		nums--;
		buffer_clear();
		printf("-----------------------------------------\n");
	}
	
}

//Check result and delete.
void Result()
{
	FILE *fp=fopen("result.txt","r");
	char chd;
	int s;
	while((chd=fgetc(fp))!=EOF)
       		fputc(chd,stdout);
		fclose(fp);
	printf("\nDo you want to delete?(Y:1 N:0)\n");
	scanf("%d",&s);
	if(s==1){
		if(remove("result.txt") == 0)
			printf("Removed result.\n");
		else
			printf("fail to remove");
		printf("press 0 to return.");
	}
	if(s==0){
		printf("press 0 to return.");
	}
			
		

}
	


