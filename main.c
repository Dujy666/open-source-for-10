//File name:Lottery_main.c
//Author:Group 10
//Annotation:2018.10.9


#include<stdio.h>
#include"function.h"

//User selection page
void Interface(void)
{
    printf("---------------Lottery Program------------\n");
    printf("                 1.Rules                  \n");
    printf("                 2.Sign Up                \n");
    printf("                 3.Check                  \n");
    printf("                 4.Start                  \n");
    printf("                 5.Result                 \n");
    printf("                 6.Exit                   \n");
    printf("------------------------------------------\n");
}	

//User selection and return
void Choose_Interface(void)
{
    int choice1, choice2;
	int flag = 0;
    while (1)
    {
        scanf("%d", &choice1);
       
        switch (choice1)
        {
            case 1: system("clear");
	            Display_Rules();
                    break;
            case 2:system("clear"); 
	           Sign_Up();
                    break;
            case 3:system("clear"); 
	           Check();
                    break;
	    case 4:system("clear");
		    start();
		    break;
	    case 5:system("clear");
		    Result();
		    break;
	    case 6:system("reset");
	            flag = 1;
		    break;
        }
	if(flag!=1){	
		printf("Press 0 to return.");
        	scanf("%d", &choice2);
        	if(choice2 == 0)
        	{
        	    system("clear");
        	    Interface();
        	}
        }else{
            break;
	}
    }
}

//main function
int main()
{
    Interface();
    Choose_Interface();

    return 0;
}
