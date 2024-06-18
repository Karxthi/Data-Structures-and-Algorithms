#include <stdio.h>
int main()
{
    int a,b;
printf("The color: %s\n","blue");
printf("The First Number: %d\n",12345);
printf("The Second Number: %04d\n",25);//Left-pads the number with zeroes (0) instead of spaces, where padding is specified
printf("The Third Number: %i\n",1234);//integer
printf("Float Number: %3.2f\n",3.1459);
printf("Hexadecimal Number: %x\n",255);
printf("Octal Number: %o\n",255);
printf("Unsigned value: %u\n",150);
printf("Just print the percentage sign: %%\n",10);

printf("\n\n\n----------------------------------------------------------------");

printf(":%s:\n","Hello,World!");
printf(":%15s:\n","Hello,World!");//right padded generally
printf("\n\n\n");
printf(":%.10s:\n\n","Hello,World!");
printf(":%-10s:\n","Hello,World!");//only extra spaces if digit greater than actual length

printf(":%-15s:\n","Hello,World!");// " - " Denotes left append (right default)
printf(":%.15s:\n","Hello,World!");//full length, only 15 characters

printf(":%15.10s:\n","Hello,World!");// FIRST DIGIT - Total Size , SECOND DIGIT - Total number of characters
printf(":%-15.11s:\n","Hello,World!");
}