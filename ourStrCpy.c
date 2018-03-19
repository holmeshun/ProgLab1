#include <stdio.h>

void ourStrCpy(char mibe[], char mit[])
{
    int i;
    //printf("\n%d\n",strlen(mit));
    for(i=0;i<strlen(mit);i++)
    {
        mibe[i]=mit[i];
    }

}


int main()
{
    char a[5];
    char b[5]=" ";
    scanf("%s",a);
    ourStrCpy(b,a);
    printf("%s",b);
}
