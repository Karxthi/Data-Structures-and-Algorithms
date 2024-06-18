#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void pali(char *a,int c);
int main()
{
    int i,j,n;
    int len=0;
  
    char s[100];
    fgets(s,100,stdin);
    printf("%s",s);
    for(i=0;i<100;i++)
    {
        printf("%c",s[i]);
        if(s[i]!='\0')
        {
            len++;
        }
    }
    printf("%d\n",len);
    char *ptr;
    ptr=s;
    
    
    pali(ptr,len);

}
void pali(char *a,int c)
{
    char s2[c];
    for(int i=c;i>0;i++)
    {
        s2[i]=*(a+i);
    }
    for(int i=0;i<c;i++)
    {
        if(s2[i]==*(a+i))
        {
            printf("[palii]");
        }
    }
}