#include<time.h>
#include <stdio.h>
#include <conio.h>



//This function can help users view the current date and time to ease their workspace.
void VIEWCURRENTDATEANDTIME()
{
    time_t datentime;
    time(&datentime);
    printf("Current Date and Time = %s", ctime(&datentime));
    printf("\nPress any key to exit.......");
    getch();
    return;
}