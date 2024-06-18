#include <stdio.h>
int main()
{
char week;
printf("Enter week number(1 7): ");
scanf("%s", &week);
switch(week)
{
case 'm':
printf
("Monday");
break;
case 't':
printf
("Tuesday");
break;
case 'w':
printf
("Wednesday");
break;
case 'T':
printf
("Thursday");
break;
case 'f':
printf
("Friday");
break;
case 's':
printf
("Saturday");
break;
case 'S':
printf
("Sunday");
break;
default:
printf
("Invalid input");
}
return 0;
}

//cannot use string in switch case