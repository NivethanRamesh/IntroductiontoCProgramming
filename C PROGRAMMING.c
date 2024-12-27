#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include<windows.h>
#include<time.h>

void ADDNEWTASK();
void VIEWTASK();
void DELETETASK();
void UPDATETASK();
void EDITPASSWORD();
void VIEWCALENDAR(void);
void VIEWCURRENTDATEANDTIME();

//Defining a user login function to store user authentication details.
void userlogin() 
{
  #define NAME "NIVETHAN" 
  FILE *ufp;
  ufp=fopen("Userpass.txt", "r");
  char password[30],pd[30];
  fscanf(ufp, "%s",password);
  printf("\n\t\t\t                   WELCOME TO THE PERSONAL TASK MANAGEMENT !! \t");
  printf("\n\t\t\t                   You can put in all of your tasks and make your life easy here !\t");
  printf("\nENTER YOUR PASSWORD :   ");
  gets(pd);
  if((strcmp(password,pd)==0))
  {
      printf("\n\nYOUR PASSWORD IS CORRECT ! ENJOY!");
      printf("\nWELCOME TO QUICKSPACE %s !!", NAME);
      Sleep(1000);
  }
  else
  {
      printf("\n\nYOUR PASSWORD IS INCORRECT ! TRY AGAIN!");
      Sleep(1000);
      exit(0);
  }
  return;
}

//This is structure called Task.
struct Task
{
    char TASKNAME[10];
    char TASKDESCRIPTION[15];
    char DUEDATE[10];
    char CATEGORY[10];
    char PRIORITY[10];
    char STATUS[12];
};

// This is union called Task
union password
{
    char Welcoming[200];
};

// This logic defines the main function of the personal task management project.
int main()
{
    userlogin(); // if the login is succesful, it would direct here.
    char option;
top:
    system("cls");
    printf("\n\n\n\t\t\t");
    for (int i = 0; i < 62; i++)
    {
        printf("%c", 20);
    }
    printf("\n\t\t                      PERSONAL TASK MANAGEMENT SYSTEM           \n\t\t");
    printf("\n\t\t                          WELCOME TO THE QUICKSPACE !           \n\t\t");
    for (int i = 0; i < 62; i++)
    {
        printf("%c", 20);
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
        printf("%c", 20);
    }
    printf("\n\t\t\t                            Pick An Option:                  \n\t\t\t");
    for (int i = 0; i < 62; i++)
    {
        printf("%c", 20);
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
        goto top;
        break;
    case '2':
        VIEWTASK();
        goto top;
        break;
    case '3':
        UPDATETASK();
        goto top;
        break;
    case '4':
        DELETETASK();
        goto top;
        break;
    case '5':
        EDITPASSWORD();
        goto top;
        break;
    case '6':
        VIEWCALENDAR();
        goto top;
        break;
    case '7':
        VIEWCURRENTDATEANDTIME();
        goto top;
        break;
    case '8':
        printf("\n\n\t The system is closing.\n");
        for (int j = 0; j < 50; j++)
        {
            for (int i = 0; i < 11111111; i++)
            {
            }
            printf("%c", 20);
        }
        for (int j = 0; j < 50; j++)
        {
            printf("%c", 20);
        }
        system("cls");
        break;
    default:
        system("cls");
        printf("\n\n\t\t");
        for (int i = 0; i < 62; i++)
        {
            printf("%c", 20);
        }
        printf("\n\n\t\t                      PERSONAL TASK MANAGEMENT SYSTEM             \n\t\t");
        for (int i = 0; i < 62; i++)
        {
            printf("%c", 20);
        }
        printf("\n\n\t\t                     [X]:Invalid Input :                          \n\t\t");
        for (int i = 0; i < 62; i++)
        {
            printf("%c", 20);
        }
        printf("\n\n\t\t                          PRESS YOUR OPTION :                  \n\t\t");
        for (int i = 0; i < 62; i++)
        {
            printf("%c", 20);
        }
        printf("\n");
        break;
    }
}

// This function can add new tasks to the system. 
void ADDNEWTASK()
{
    struct Task Add;
    FILE *lfp;
    lfp = fopen("TASKFILE.txt", "a");
    system("cls");    
    printf("\n\n\t\t");
    printf("\n\t                    PERSONAL TASK MANAGEMENT SYSTEM             \n\t", 2);
    printf("\n\t 1) ENTER THE NEW TASK NAME:    ");
    fflush(stdin);
    gets(Add.TASKNAME);
    printf("\n\t 2) ENTER THE TASK DESCRIPTION:    ");
    fflush(stdin);
    gets(Add.TASKDESCRIPTION);
    printf("\n\t 3) ENTER THE DUE DATE OF THE TASK(yyyymmdd):   ");
    fflush(stdin);
    gets(Add.DUEDATE);
    printf("\n\t 4) ENTER THE CATEGORY OF THE NEW TASK:   ");
    fflush(stdin);
    gets(Add.CATEGORY);
    printf("\n\t 5) STATE THE PRIORITY(HIGH OR LOW):    ");
    fflush(stdin);
    gets(Add.PRIORITY);
    printf("\n\t 6) ENTER THE STATUS(INPROGRESS OR COMPLETED):  ");
    fflush(stdin);
    gets(Add.STATUS);
    printf("\n\n Saving the data. Please wait.\n\n");
    printf("\n\n The new task is added. Thank you. ");
    fwrite(&Add, sizeof(Add), 1, lfp);
    fprintf(lfp, "\n");
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
    fclose(lfp);
}


// This function can sort and view tasks in ascendng order with reference to the due date, category or etc.
void VIEWTASK()
{
    struct Task View;
    FILE *fp;
    int number, taskcount = 1;
    fp = fopen("TASKFILE.txt", "r");
    if (fp == NULL)
    {
        printf("\n\t\t         File is missing or unidentified."     );
        exit(1);
    }
    system("cls");
    printf("\n\n\t");
    printf("\n\t          PERSONAL TASK MANAGEMENT SYSTEM   \n", 2);
    for (int i = 1; fread(&View, sizeof(View),1, fp) != 0; i++)
    {
        printf("\n\tLIST OF TASK(S) %d) : %s\t%s\t%s\t%s\t%s\t%s", i, View.TASKNAME, View.TASKDESCRIPTION, View.DUEDATE, View.CATEGORY, View.PRIORITY, View.STATUS);
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("\n\n\t THE LIST ABOVE SHOWS THE RECORD OF TASKS IN THE DIRECTORY.");
    printf("\n\n\t Choose your option to view the information in task specifically. \n\t  ENTER THE TASK NUMBER:  ");
    scanf("%d", &number);
    fp = fopen("TASKFILE.txt", "r");
    if (fp == NULL)
    {
        printf("\n\t\t File is missing or unidentified !");
        exit(1);
    }
    system("cls");
    printf("\n\n\t");
    printf("\n\t                    PERSONAL TASK MANAGEMENT SYSTEM   \n", 2);
    for (taskcount; fread(&View, sizeof(View), 1, fp) != 0; taskcount++)
    {
        fprintf(fp, "\n");
        if (taskcount == number)
        {
            printf("\n\t             TASKNAME : %s",View.TASKNAME);
            printf("\n\t             TASKDESCRIPTION : %s",View.TASKDESCRIPTION);
            printf("\n\t             DueDate : %s",View.DUEDATE);
            printf("\n\t             Category : %s",View.CATEGORY);
            printf("\n\t             Priority : %s",View.PRIORITY);
            printf("\n\t             STATUS : %s",View.STATUS);
            break;
        }
    }
    fclose(fp);
    if (taskcount != number)
    {
        printf("\n\t The data does not match to each other. PLEASE TRY AGAIN !");
    }
    printf("\n\n\t\t\t\t*************************************************************");
    printf("\n\n\t\t\t\t That is all from this function. Thank you.");
    printf("\n\n\t\t\t\t*************************************************************");
    printf("\n\n\t\t\t\t Press any key to exit !");
    getch();
}

// This function can delete any unwanted tasks or data entry mistakes.
void DELETETASK()
{
  FILE* zfp;
  FILE* vfp;

  char character;
  int line = 0;
  int temp = 1;
  zfp = fopen("TASKFILE.txt", "r");
  if (zfp == NULL) {
        printf("\nTHE FILE IS UNABLE TO OPEN. PLEASE CHECK.\n");
        return ;
  }
  while (!feof(zfp)) {
        character = getc(zfp);
  }
  rewind(zfp);
  printf("\n**********************************");
  printf("\nEnter number of which task that you want to delete(example: 1 or 2): ");
  scanf("%d", &line);
  vfp = fopen("temp.txt", "w");
  while (!feof(zfp)) {
      character = getc(zfp);
      if (character == '\n')
            temp++;
      if (temp != line)
            putc(character, vfp);
  }
  rewind(vfp);
  fclose(zfp);
  fclose(vfp);
  remove("TASKFILE.txt");
  rename("temp.txt", "TASKFILE.txt");
  printf("\nChanged or Updated file:\n");
  zfp = fopen("TASKFILE.txt", "r");
  if (zfp == NULL) {
      printf("\nTHE FILE IS UNABLE TO OPEN.PLEASE CHECK\n");
      return;
  }
  while (!feof(zfp)) {
      character = getc(zfp);
  }
  rewind(zfp);
  fclose(zfp);
  printf("\n");
  return;
}

// This function can update information about tasks- name, category and etc.
void UPDATETASK()
{
    struct Task Update;
    system("cls");
    FILE *fp ;
    char TASKNAME[20],option,TASKFILE[14];
    int number,tally=0;

    printf("\n\n\t\t*******************************\n");
    printf("\t\t        UPDATE YOUR TASK HERE ");
    printf("\n\n\t\t*******************************\n");

    do
    {
        printf("\n\tENTER THE DATE OF TASK TO BE UPDATED IN THE FORMAT PROVIDED:[yyyymmdd]:");
        fflush(stdin);
        gets(TASKFILE);
        printf("\n\tENTER TASK NAME:");
        gets(TASKNAME);
        fp = fopen ( "TASKFILE.txt", "rb+" ) ;
      


        if ( fp == NULL )
        {
            printf( "\nTHE DATA IS MISSING OR UNIDENTIFIED !" ) ;
            printf("\nPRESS ANY KEY TO GO BACKWARD.");
            getch();
            return;
        }
        while ( fread ( &Update, sizeof ( Update ), 1, fp ) == 1 )
       {
            if(strcmp(Update.TASKNAME,TASKNAME)==0)
            {
                printf("\nTHE OLD OR CURRENT DATA IS :");
                printf("\nTASK NAME: %s",Update.TASKNAME);
                printf("\nTASK DESCRIPTION: %s",Update.TASKDESCRIPTION);
                printf("\nDUE DATE: %s",Update.DUEDATE);
                printf("\nTHE CATEGORY: %s",Update.CATEGORY);
                printf("\nPRIORITY: %s",Update.PRIORITY);
                printf("\nSTATUS: %s",Update.STATUS);
                printf("\n\n\t\tUPDATE THE NEW DATA BELOW: ");
                printf("\n1.TASK NAME.");
                printf("\n2.TASK DESCRIPTION.");
                printf("\n3.DUE DATE.");
                printf("\n4.THE CATEGORY.");
                printf("\n5.PRIORITY.");
                printf("\n6.STATUS.");
                printf("\n7.ENTIRE TASK.");
                printf("\n8.RETURN BACK TO THE MAIN MENU SYSTEM.");

                do
                {
                    printf("\n\tENTER YOUR OPTION:");
                    fflush(stdin);
                    scanf("%d",&number);
                    fflush(stdin);
                    switch(number)
                    {
                    case 1:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nNEW TASK NAME:");
                        gets(Update.TASKNAME);
                        break;
                    case 2:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nNEW TASK DESCRIPTION:");
                        gets(Update.TASKDESCRIPTION);
                        break;
                    case 3:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nNEW DUE DATE:");
                        gets(Update.DUEDATE);
                        break;
                    case 4:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nNEW CATEGORY:");
                        gets(Update.CATEGORY);
                        break;
                    case 5:
                        printf("ENTER THE NEW DATA:");
                        printf("\nNEW PRIORITY(HIGH OR LOW):");
                        gets(Update.PRIORITY);
                        break;
                    case 6:
                        printf("ENTER THE NEW DATA:");
                        printf("\nNEW STATUS(INPROGRESS OR COMPLETED):");
                        gets(Update.STATUS);
                        break;
                    case 7:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nNEW TASK NAME:");
                        gets(Update.TASKNAME);
                        printf("\nNEW TASK DESCRIPTION:");
                        gets(Update.TASKDESCRIPTION);
                        printf("\nNEW DUE DATE:");
                        gets(Update.DUEDATE);
                        printf("\nNEW CATEGORY:");
                        gets(Update.CATEGORY);
                        printf("\nNEW PRIORITY(HIGH OR LOW):");
                        gets(Update.PRIORITY);
                        printf("\nNEW STATUS(INPROGRESS OR COMPLETED):");
                        gets(Update.STATUS);
                        break;
                    case 8:
                        printf("\nPRESS ANY KEY TO GO BACK TO THE SYSTEM.\n");
                        getch();
                        return ;
                        break;
                    default:
                        printf("\nYOUR INPUT IS WRONG.TRY AGAIN !\n");
                        break;
                    }

                }
                while(number < 1 || number > 8);
                fseek(fp, sizeof(Update),SEEK_CUR);
                fwrite(&Update,sizeof(Update),1,fp);
                fprintf(fp, "\n");
                fseek(fp, sizeof(Update),SEEK_CUR);
                fread(&Update,sizeof(Update),1,fp);
                option=5;
                break;
            }
        }
        if(option==5)
        {
            system("cls");
            printf("\n\t\tChanges are done to the data. Enjoy !\n");
            printf("***********************\n");
            printf("THE NEW DATA IS: \n");
            printf("***********************\n");
            printf("\nTASK NAME: %s",Update.TASKNAME);
            printf("\nTASK DESCRIPTION: %s",Update.TASKDESCRIPTION);
            printf("\nDUE DATE: %s",Update.DUEDATE);
            printf("\nCATEGORY: %s",Update.CATEGORY);
            printf("\nPRIORITY: %s",Update.PRIORITY);
            printf("\nSTATUS: %s",Update.STATUS);
            fclose(fp);
            printf("\n\n\tIS THERE ANY WISH TO UPDATE ANOTHER DATA ? (Y/N)");
            scanf("%c",&option);
            tally++;
        }
        else
        {
            printf("\n\tTHE DATA IS MISSING OR UNIDENTIFIED IN THE DIRECTORY.");
            printf("\n\tDO YOU WISH TO TRY AGAIN ?(Y/N)");
            scanf("%c",&option);
        }
    }
    while(option=='Y'||option=='y');
    fclose (fp);
    if(tally==1)
        printf("\n%d DATA IS UPDATED.\n",tally);
    else if(tally>1)
        printf("\n%d DATA ARE UPDATED.\n",tally);
    else
        printf("\nDATA IS NOT UPDATED.\n");

    printf("\n\tThe command has been fulfilled. Enjoy !");
    Sleep(1000);
    printf("\n\tPRESS ENTER TO EXIT THE UPDATETASK MENU.");
    getch();
}

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
     goto end3;
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
        goto end3;
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
end3: fclose(wfp);
printf("\n\n\t\t YOUR COMMAND HAS BEEN FULFILLED. ENJOY!");
Sleep(1000);
getch();
}

//This function can help users view the current date and time to ease their workspace.
void VIEWCURRENTDATEANDTIME()
{
    time_t te;
    time(&te);
    printf("Current Date and Time = %s", ctime(&te));
    printf("\nPress any key to exit.......");
    getch();
    return;
}

int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
	" ",
	"\n\n\nJanuary",
	"\n\n\nFebruary",
	"\n\n\nMarch",
	"\n\n\nApril",
	"\n\n\nMay",
	"\n\n\nJune",
	"\n\n\nJuly",
	"\n\n\nAugust",
	"\n\n\nSeptember",
	"\n\n\nOctober",
	"\n\n\nNovember",
	"\n\n\nDecember"
};


int inputYEAR(void)
{
	int YEAR;
	printf("\n\tPlease enter a year (EXAMPLE:2002) : ");
	scanf("%d", &YEAR);
	return YEAR;
}

int determinedaycode(int YEAR)
{
  int daycode;
  daycode = (YEAR + (YEAR-1)/4 - (YEAR-1)/100 + (YEAR-1)/400) % 7;
  return daycode;
}


void determineLEAPYEAR(int YEAR)
{
   if((YEAR %4==FALSE && YEAR %100!=FALSE) || (YEAR %400==FALSE))
     days_in_month[1]=29;
}



void CALENDAR(int YEAR, int daycode)
{
	int MONTH, DAYS;
	for ( MONTH = 1; MONTH <= 12; MONTH++ )
	{
		printf("%s", months[MONTH]);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );				
		for ( DAYS = 1; DAYS <= 1 + daycode * 5; DAYS++ )
		{
			printf(" ");
		}				
		for ( DAYS = 1; DAYS <= days_in_month[MONTH]; DAYS++ )
		{
			printf("%2d", DAYS );		
			if ( ( DAYS + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}			
			daycode = ( daycode + days_in_month[MONTH] ) % 7;
	}
}

//This function can help users view the calendar to ease their workspace.
void VIEWCALENDAR(void)
{
	int YEAR, daycode, LEAPYEAR;
    printf("******************");
	printf("/n This is the calendar to view.");
    printf("*****************");
	YEAR = inputYEAR();
	daycode = determinedaycode(YEAR);
	determineLEAPYEAR(YEAR);
	CALENDAR(YEAR, daycode);
	printf("\n");
    Sleep(20000);
}
