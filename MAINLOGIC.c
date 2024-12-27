#include <stdio.h>
#include<windows.h>
#include <stdbool.h>
#include <conio.h>
#include<time.h>
#include "EDITPASSWORD.h"
#include "USERLOGIN.h"
#include "ADDNEWTASK.h"
#include "VIEWTASK.h"
#include "UPDATETASK.h"
#include "DELETETASK.h"
#include "VIEWCALENDAR.h"
#include "VIEWCURRENTDATEANDTIME.h"



void ADDNEWTASK();
void VIEWTASK();
void DELETETASK();
void UPDATETASK();
void EDITPASSWORD();
void VIEWCALENDAR(void);
void VIEWCURRENTDATEANDTIME();

// This logic defines the main function of the personal task management project.
int main()
{
    userlogin(); // if the login is succesful, it would direct here.
    char option;
above:
    system("cls");
    printf("\n\n\n\t\t\t");
    for (int i = 0; i < 62; i++)
    {
        printf("%c", 30);
    }
    printf("\n\t\t                      PERSONAL TASK MANAGEMENT SYSTEM           \n\t\t");
    printf("\n\t\t                          WELCOME TO THE QUICKSPACE !           \n\t\t");
    for (int i = 0; i < 62; i++)
    {
        printf("%c", 30);
    }
    printf("\n\t\t\t\t PRESS[1]:Add New Task");
    printf("\n\t\t\t\t PRESS[2]:View Task");
    printf("\n\t\t\t\t PRESS[3]:Update Task");
    printf("\n\t\t\t\t PRESS[4]:Delete Task");
    printf("\n\t\t\t\t PRESS[5]:Edit Password");
    printf("\n\t\t\t\t PRESS[6]:View Calendar");
    printf("\n\t\t\t\t PRESS[7]:View Current Date And Time ");
    printf("\n\t\t\t\t PRESS[8]:Exit Program\n\t\t");
    for (int i = 0; i < 62; i++)
    {
        printf("%c", 30);
    }
    printf("\n\t\t\t                            Pick An Option:                  \n\t\t\t");
    for (int i = 0; i < 62; i++)
    {
        printf("%c", 30);
    }
    printf("\n");
    fflush(stdin);
    option = getch();
    printf("The option that you chose is: ");
    Sleep(1000);
    switch (option)
    {
    case '1':
        ADDNEWTASK();
        break;
    case '2':
        VIEWTASK();
        break;
    case '3':
        UPDATETASK();
        break;
    case '4':
        DELETETASK();
        break;
    case '5':
        EDITPASSWORD();
        break;
    case '6':
        VIEWCALENDAR();
        break;
    case '7':
        VIEWCURRENTDATEANDTIME();
        break;
    case '8':
        printf("\n\n\t The system is closing.\n");
        for (int j = 0; j < 50; j++)
        {
            for (int i = 0; i < 11111111; i++)
            {
            }
            printf("%c", 10);
        }
        for (int j = 0; j < 50; j++)
        {
            printf("%c", 10);
        }
        exit(0);
    default:
        system("cls");
        printf("\n\n\t\t");
        for (int i = 0; i < 62; i++)
        {
            printf("%c", 30);
        }
        printf("\n\n\t\t                      PERSONAL TASK MANAGEMENT SYSTEM             \n\t\t");
        for (int i = 0; i < 62; i++)
        {
            printf("%c", 30);
        }
        printf("\n\n\t\t       Incorrect Option. Try Again by choosing given options from the above.                     \n\t\t");
        Sleep(2000);
        for (int i = 0; i < 62; i++)
        {
            printf("%c", 30);
        }
        printf("\n\n\t\t                          PRESS YOUR OPTION :                  \n\t\t");
        for (int i = 0; i < 62; i++)
        {
            printf("%c", 30);
        }
        printf("\n");
        break;

    }
    goto above;
}
