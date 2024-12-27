#include <stdio.h>
#include <conio.h>
#include<windows.h>



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
    printf("\n\t     PERSONAL TASK MANAGEMENT SYSTEM : QUICKSPACE   \n");
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
    printf("\n\t             PERSONAL TASK MANAGEMENT SYSTEM : QUICKSPACE  \n");
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


