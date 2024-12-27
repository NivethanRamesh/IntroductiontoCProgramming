#include <stdio.h>
#include <conio.h>
#include<windows.h>


// This is union called password
union password
{
    char Welcoming[200];
};


// This function can edit password of their account anytime for security purposes.
void EDITPASSWORD()
{
  union password Welcome;
  char NAMEOFFILE[20],connect;
  FILE *wfp;
  strcpy (Welcome.Welcoming, "WELCOME USER !!\n THIS IS EDIT PASSWORD FUNCTION.");
  printf (" %s\n", Welcome.Welcoming);
  printf("\n\tENTER Userpass.txt: ");
  scanf("%s",NAMEOFFILE);
  wfp=fopen(NAMEOFFILE,"r");
  if(wfp==NULL)
  {
     printf("\n\tFile not found!");
     goto close;
  }
  while(!feof(wfp))
  {
   connect=getc(wfp);
  }
  fclose(wfp);
  printf("\n\tInsert your new password and press 'Ctrl+S' to confirm.\n");
  wfp=fopen(NAMEOFFILE,"w");
  while(1)
  {
   connect=getch();
   if(connect==19)
        goto close;
   if(connect==13)
   {
       connect='\n';
       printf("\n\t");
       fputc(connect,wfp);
   }
   else
   {
       printf("%c",connect);
       fputc(connect,wfp);
   }
  }
close: fclose(wfp);
printf("\n\n\t\t YOUR COMMAND HAS BEEN FULFILLED. ENJOY!");
Sleep(1000);
getch();
}
