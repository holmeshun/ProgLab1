#include <stdio.h>

int main()
{
    FILE *f = fopen("fscanf.dat","wb");
    char *nev[100];
    int db=3;
    while(1)
    {
        scanf("%s",nev);
        //fwrite(&db, sizeof (int), 1, f);
        if(strcmp(nev,"Aladar")!=0)
        {
            fwrite(nev, sizeof (char *), 1, f);
        }else
        break;
    }
}
