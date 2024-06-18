#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    char str2[100];
    //char str2[100];
    int i,n;
    char temp;
    scanf("%s",str);
    strcpy(str2,str);
    n=strlen(str);
    
    printf("%s\n",str);
    printf("%d\n",n);
    int right=n-1;
    for(i=0;i<right;i++)
    {
        temp=str[i];
        str[i]=str[n];
        str[n]=temp;
        (n)--;
        printf("%c",temp);
    }
    printf("\t%s\n",str2);
    printf("\t%s\n",str);
    if(str2==str)
    {
        printf("yesss\n",str);
    }
    else{
        printf("no");
    }
}
