#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Interface(void)
{
    printf("---------------Lottery Program------------\n");
    printf("                 1.Rules                  \n");
    printf("                 2.Sign Up                \n");
    printf("                 3.Check                  \n");
    printf("                 4.Clear                  \n");
    printf("                 5.Star                   \n");
    printf("                 6.Result                 \n");
    printf("                 7.Exit                   \n");
    printf("------------------------------------------\n");
}

void Display_Rules(void)
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
    printf("Lottery setting\n");
    printf("------------------------------------------------------\n");
    printf("Lottery info：");
    scanf("%*c");
    scanf("%[^\n]", main_info);
    fprintf(fp, "抽奖信息简介\t   %s\n", main_info);
    printf("\n\n");
    printf("------------------------------------------------------\n");
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

    printf("Winners' info roll or not?（Y = 1 N = 0）：");
    scanf("%d", &Roll);
    fprintf(fp, "滚动\t   %d\n", Roll);
    printf("\n");

    printf("The format of winners' info：\nall of info：1\n"
           "Name + Student No.：2\nName + Tel：3\nWhat kind of format "
           "do you like？");
    scanf("%d", &output);
    fprintf(fp, "格式\t   %d\n", output);
    printf("\n\n");
    printf("------------------------------------------------------\n");
    fprintf(fp1, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t", No1, No2, No3, Prize_total,
            People_total, Roll, output);
    fclose(fp);
    fclose(fp1);
}

void Sign_Up(void)
{
    printf(".................\n");
    printf(".................\n");
    printf(".................\n");
}

void Check(void)
{
    printf(".................\n");
    printf(".................\n");
    printf(".................\n");
}

void Quit(void)
{
    printf("You have exit the program!\n");
}

void Choose_Interface(void)
{
    int choice1, choice2;
    while (1)
    {
        scanf("%d", &choice1);
        system("clear");
        switch (choice1)
        {
            case 1: Display_Rules();
                    break;
            case 2: Sign_Up();
                    break;
            case 3: Check();
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
