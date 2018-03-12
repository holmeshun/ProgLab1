#include <stdio.h>

int main()
{
    int i,j,l,n,m,k;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&k);
    int a[n][m];
    int b[m][k];
    int c[n][k];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
           c[i][j]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
           scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<k;j++)
        {
           scanf("%d",&b[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<k;j++)
        {
            for(l=0;l<m;l++)
            {
                c[i][j]+=a[i][l]*b[l][j];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<k;j++)
        {
           printf(" %d ",[i][j]);
        }
        printf("\n");
    }
}
