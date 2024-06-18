#include <stdio.h>

int main()
{
  int n;
  int vow,cons=0;
  char str1[100];
  char *ptr;
  fgets(str1,sizeof str1,stdin);
  ptr=str1;
  vow=0;
  printf("----------------------%c\n",str1[0]);
  while(*ptr!='\0')
  {
    printf("POINYTET \n%c\n",*ptr);
    if(*ptr=='A' ||*ptr=='E' ||*ptr=='I' ||*ptr=='O' ||*ptr=='U')
    {
      vow++;
      printf("VOW %d\n",vow);

    }
    else
    {
      cons++;
    }
    ptr++;
  }
  printf("\n%d\n\n%d\n", vow, cons-1);
}