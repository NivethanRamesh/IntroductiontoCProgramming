#include <stdio.h>
#include<windows.h>


//Defining a user login function to store user authentication details.
void userlogin() 
{
  #define NAME "NIVETHAN" 
  FILE *ufp;
  ufp=fopen("Userpass.txt", "r");
  char password[30],userpass[30];
  fscanf(ufp, "%s",password);
  printf("\n\t\t\t                 WELCOME TO THE PERSONAL TASK MANAGEMENT !! \t");
  printf("\n\t\t\t                 You can put in all of your tasks and make your life easy here !\t");
  printf("\nENTER YOUR PASSWORD :   ");
  gets(userpass);
  if((strcmp(password,userpass)==0))
  {
      printf("\n\nYOUR PASSWORD IS CORRECT ! ENJOY!");
      printf("\nWELCOME TO QUICKSPACE %s !!", NAME);
      Sleep(1500);
  }
  else
  {
      printf("\n\nYOUR PASSWORD IS INCORRECT ! TRY AGAIN!");
      Sleep(1500);
      userlogin();
  }
  return;
}


