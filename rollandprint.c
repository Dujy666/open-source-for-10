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

void close_keyboard(){
	tcsetattr(0,TCSANOW,&initial_settings);
}


void rollandprint(char x[],int y,int jde,int info)
{
	int ch=0;
	char d[10];
	int a,b;
	init_keyboard();
	srand(time(NULL));
	a=x[rand()%y];
	
	printf("\n");
	if(jde==1){
		while(!kbhit()){
			a=x[rand()%y];
			usleep(100000);
			printf("\033[2A\n");
			printf("\033[31m %d\033[47m\n",a);
			printf("\033[0m");
		}
	}
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
	int i=0;
	if(info == 1){
		while((chd=fgetc(fp1))!=EOF)
       			fputc(chd,stdout);
	}
	if(info == 2){
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
		fflush(stdin);
		scanf("%*c");
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
		fflush(stdin);
		scanf("%*c");
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
		fflush(stdin);
		scanf("%*c");
		printf("-----------------------------------------\n");
	}
	
}
