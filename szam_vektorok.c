#include <stdio.h>

int main()
{

    int i,j,sor,oszlop;
    scanf("%d",&sor);
    scanf("%d",&oszlop);
    int a[sor][oszlop];
    for(i=0;i<sor;i++)
    {
        for(j=0;j<oszlop;j++)
        {
           scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<sor;i++)
    {
        printf("\n");
        for(j=0;j<oszlop;j++)
             printf("%d ",a[i][j]);

    }

    printf("\n");

    for(i=0;i<oszlop;i++)
    {
        for(j=sor-1;j>=0;j--)
             printf("%d ",a[j][i]);
        printf("\n");
    }


/*    printf("\n");
    for(i=9;i>=0;i--)
         printf(" %d ",a[i]);
*/
}
