//clear original meau

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Interface(void)
{
	printf("-----------------Lottery-------------------\n");
	printf("                 1.Rules                  \n");
	printf("                 2.Sign Up                \n");
	printf("                 3.Check                  \n");
	printf("                 4.Clear                  \n");
	printf("                 5.Star                   \n");
	printf("                 6.Result                 \n");
	printf("                 7.Exit                   \n");
	printf("-------------------------------------------\n");
}

void Display_Rules(void)
{
	printf(".................\n");
	printf(".................\n");
	printf(".................\n");
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

void Choose_Interface(int enter)
{
	switch (enter)
        {
		case 1: Display_Rules();
			break;
		case 2: Sign_Up();
			break;
		case 3: Check();
			break;
		default:
			break;
        }
}

int main()
{
	Interface();

	int enter;
	scanf("%d", &enter);
	system("clear");
	Choose_Interface(enter);

	return 0;
}

