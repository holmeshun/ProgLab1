#include <stdio.h>

int main()
{
    char* buffer[10][100];
    char* temp[100];
    int i,j,n=0;
    FILE* f = fopen("fscanf.txt","r");
    FILE* f1 = fopen("fscanf_rendezett.txt","w");
    while(fscanf(f,"%s", buffer[n])!=EOF)
    {
        printf("%s ",buffer[n]);
        n++;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(buffer[i],buffer[j])>0)
            {
                strcpy(temp,buffer[j]);
                strcpy(buffer[j],buffer[i]);
                strcpy(buffer[i],temp);
            }
        }

    }
    for(i=0;i<n;i++)
    {
        fprintf(f1,"%s ",buffer[i]);
    }
    fclose(f);
    fclose(f1);
}
