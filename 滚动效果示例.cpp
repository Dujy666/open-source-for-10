#include <stdio.h>
#include <windows.h>

void main()
{
	char str[]="hello world";
	int len;
	int j,k,s;
	k = 0;
	len = strlen(str);
	while(k < 5){
		for (int i = 0;i < len;i++){
			printf("%c",str[i]);
			Sleep(100);
		}
		Sleep(100);
		for (j = 0;j < len;j++){
			printf("\b");
		}
		for (s = 0;s < len;s++){
			printf(" ");
		}
		k++;
		Sleep(300);
		}
	
}