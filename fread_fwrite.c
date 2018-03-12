#include <stdio.h>

int main()
{
    FILE *f = fopen("fscanf.dat","rb");
    char *nev[10][100];
    int *n;
    int i;
    //fread(&n,sizeof (int), 1, f);
    for(i=0;i<n;i++)
    {
        fread(nev[i],sizeof (char *) ,1, f);
    }
    fclose(f);
}

