#include <stdio.h>

int main()
{
    int n
    ;
    printf("N: ");
    scanf("%d",&n);
    int M[5][5];
    int i,j,counterX=0,counterY=0;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&M[i][j]);
        }
    }

    for(i=0; i<n; i++)
    {

        for(j=0; j<n-2; j++)
        {
            if(M[i][j]==1 && M[i][j+1]==1 && M[i][j+2]==1)
            {
                printf("X nyert");
                break;
            }

            if(M[i][j]==2 && M[i][j+1]==2 && M[i][j+2]==2)
            {
                printf("Y nyert");
                break;
            }
        }
    }
    for(i=0; i<n-2; i++)
    {

        for(j=0; j<n; j++)
        {
            if(M[j][i]==1 && M[j+1][i]==1 && M[j+2][i]==1)
            {
                printf("X nyert");
                break;
            }

            if(M[j][i]==2 && M[j+1][i]==2 && M[j+2][i]==2)
            {
                printf("Y nyert");
                break;
            }
        }
    }

    //ez m�g valami�rt nem megy
    for(i=0; i<n-2; i++)
    {
        for(j=0; j<n-2; j++)
        {
            if(M[i][j]==1 && M[i+1][j+1]==1 && M[i+2][j+2]==1)
            {
                printf(" X nyert ");
                break;
            }

            if(M[i][j]==2 && M[i+1][j+1]==2 && M[i+2][j+2]==2)
            {
                printf(" Y nyert ");
                break;
            }
        }
    }

    for(i=0; i<n-2; i++)
    {
        for(j=2; j<n; j++)
        {
            if(M[i][j]==1 && M[i+1][j-1]==1 && M[i+2][j-2]==1)
            {
                printf(" X nyert ");
                break;
            }

            if(M[i][j]==2 && M[i+1][j-1]==2 && M[i+2][j-2]==2)
            {
                printf(" Y nyert ");
                break;
            }
        }
    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(n-1-i==j)
            {

            }
        }
    }*/

    /*for(i=3; i>=0; i--)
    {
        for(j=0; j<3; j++)
        {
            if(i==i-j && M[i][j]==1 || i==j && M[i][j]==1 || j==j-i && M[i][j]==1)
            {
                counterX++;
            }

            if(i==i-j && M[i][j]==2 || i==j && M[i][j]==2 || j==j-i && M[i][j]==2)
            {
                counterY++;
            }
        }
    }
    if(counterX == 3)
    {
        printf("X nyert");
    }
    if(counterY == 3)
    {
        printf("Y nyert");
    }*/
    /*f(M[0][0]==1 && M[1][1]==1 && M[2][2]==1)
        printf("X nyert");

    if(M[0][0]==2 && M[1][1]==2 && M[2][2]==2)
        printf("Y nyert");*/


}

