#include <stdio.h>
struct complex
{
    int real;
    int imag;
};
struct number
{
    int digit;
    struct complex comp;
};
int main()
{
    struct number n;
    int no,r,c;
    scanf("%d",&no);
    scanf("%d",&r);
    scanf("%d",&c);
    n.digit=no;
    n.comp.real=r;
    n.comp.imag=c;
    printf("%d",n.digit);
    printf("%d",n.comp.real);
    printf("%d",n.comp.imag);
}