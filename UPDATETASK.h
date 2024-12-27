#include <stdio.h>
#include<windows.h>
#include <conio.h>
#include <stdbool.h>



// This function can update information about tasks- name, category and etc.
void UPDATETASK()
{
    #define BUFFER_SIZE 1000
    FILE *ftemporary;
    char buffer[BUFFER_SIZE];
    int line, count;
    struct Task Update;
    system("cls");
    FILE *fp ;
    char TASKNAME[20],option,TASKFILE[14];
    int number,tally=0;

    printf("\n\n\t\t*******************************\n");
    printf("\t\t  MODIFY THE AVAILABLE TASKS IN THIS FUNCTION. ");
    printf("\n\n\t\t*******************************\n");

    do
    {
        printf("\n\tENTER THE DATE OF TASK TO BE UPDATED IN THE FORMAT PROVIDED:[yyyymmdd]:");
        fflush(stdin);
        gets(TASKFILE);
        printf("\n\tENTER CURRENT TASK NAME:");
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
                ftemporary = fopen("TEMPORARY.txt","w");
                fseek(fp, sizeof(Update),SEEK_CUR);
                fwrite(&Update,sizeof(Update),1,ftemporary);
                count = 0;
                while ((fgets(buffer, BUFFER_SIZE, fp)) != NULL)
                {
                   count++;
                   if (count == 1)
                   fputs(buffer, ftemporary);
                }
                
                fclose(fp);
                fclose(ftemporary);
                remove("TASKFILE.txt");
                fprintf(fp, "/n");
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
            fclose(ftemporary);
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
    rename("TEMPORARY.txt", "TASKFILE.txt");
    Sleep(1000);
    printf("\n\tPRESS ENTER TO EXIT THE UPDATETASK MENU.");
    getch();
}
