#include <stdio.h>

int main()
{
    FILE *f = fopen("fscanf.txt","w");
    char *nev[100];
    while(1)
    {
        scanf("%s",&nev);
        if(strcmp(nev,"Aladar")!=0)
        {
            fprintf(f,"%s ",nev);
        }else
        break;
    }
}
