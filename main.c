#include<stdio.h>
#include"function.h"


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

void Choose_Interface(void)
{
    int choice1, choice2;
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
		    break;
        }
        scanf("%d", &choice2);
        if(choice2 == 0)
        {
            system("clear");
            Interface();
        }
        else
            break;
    }
}


int main()
{
    Interface();
    Choose_Interface();

    return 0;
}
