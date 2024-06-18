#include <stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    (a>=6 && a<10)? printf("Very Basic"):(a>4 && a<6)?printf("acidic"):(a==4)?printf("Neutral"):(a>=2 && a<4)?printf("Very Acidic"):printf("Acidic");
    //ternary opp
}