#include <stdio.h>
#include<windows.h>


int DAYSMONTH[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *MONTHS[]=
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


int insertyear(void)
{
	int year;
	printf("INSERT A YEAR TO VIEW THE YEAR CALENDAR (example: 2002) : ");
	scanf("%d", &year);
	return year;
}

int knowdaycode(int year)
{
  int daycode;
  daycode = (year + (year-1)/4 - (year-1)/100 + (year-1)/400) % 7;
  return daycode;
}


void knowleapyear(int year)
{
   if((year%4==FALSE && year%100!=FALSE) || (year%400==FALSE))
     DAYSMONTH[1]=29;
}



void calendar(int year, int daycode)
{
	int month, day;
	for ( month = 1; month <= 12; month++ )
	{
		printf("%s", MONTHS[month]);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		}
		for ( day = 1; day <= DAYSMONTH[month]; day++ )
		{
			printf("%2d", day );	
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}
			daycode = ( daycode + DAYSMONTH[month] ) % 7;
	}
}

//This function can help users view the calendar to ease their workspace.

void VIEWCALENDAR(void)
{
	int year, daycode, leapyear;
	year = insertyear();
	printf("*****************************");
	printf("\n\nThis is the calendar to view.");
	printf("\n\n*****************************");
	daycode = knowdaycode(year);
	knowleapyear(year);
	calendar(year, daycode);
	printf("\n");
    Sleep(20000);
}


