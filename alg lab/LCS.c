#include<stdio.h>
int main()
{

    int i,j,n,V,a,b,c,p;
    printf("Enter X array size: ");
    scanf("%d",&n);
    char X[n+1];
    printf("\nFor X of item: \n");
    for(i=1; i<n+1; i++)
    {
        printf("Enter X[%d]:", i);
        scanf("%s",&X[i]);
    }
    printf("Enter Y array size: ");
    scanf("%d",&V);
    char Y[V+1];
    printf("\nFor Y of item: \n");
    for(i=1; i<V+1; i++)
    {
        printf("Enter Y[%d]]:", i);
        scanf("%s", &Y[i]);
    }
    int  T1[n+1][V+1],T2[n+1][V+1];
    for(i=0; i<n+1; i++)
    {
        T1[i][0]=0;
        T2[i][0]=0;
    }
    for(j=1; j<V+1; j++)
    {
        T1[0][j]=0;
        T2[0][j]=0;
    }
    for(i=1; i<n+1; i++)
    {
        for(j=1; j<V+1; j++)
        {
            a=1+ T1[i-1][j-1];
            b=T1[i-1][j];
            c=T1[i][j-1];
            if(X[i]==Y[j])
            {
                T1[i][j]=a;
                T2[i][j]=1;
            }
            else if(b>=c)
            {
                T1[i][j]=b;
                T2[i][j]=2;
            }
            else
            {
                T1[i][j]=c;
                T2[i][j]=3;
            }
        }
    }

    printf("\n");
    printf("\n Print for Sign:\n");
    for(i=0; i<n+1; i++)
    {
        for(j=0; j<V+1; j++)
        {
            printf(" %d ",T2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n Print for value:\n");
    for(i=0; i<n+1; i++)
    {
        for(j=0; j<V+1; j++)
        {
            printf(" %d ",T1[i][j]);
        }
        printf("\n");
    }
    printf("\nlength %d and that's are ",T1[n][V]);
    i=n;
    j=V;
    int R=0;
    p=T1[i][j];
    char sub[p];
    while(i != 0 && j != 0)
    {
        if(T2[i][j] == 1)
        {
            sub[R]=X[i];
            i--;
            j--;
            R++;
        }
        else if(T2[i][j]==2)
        {
            i--;
        }
        else if(T2[i][j]==3)
        {
            j--;
        }
    }
    printf(",LCS: ");
    for(i=p-1; i>=0; i--)
    {
        printf(" %c ",sub[i]);
    }

    return 0;
}
