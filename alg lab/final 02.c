#include<stdio.h>
int main()
{
   int i, j,n,V,x,y;
   printf("Enter coin size: ");
   scanf("%d",&n);

   int a[n+1];
   printf("Coin array: \n");
   for(i=1; i<n+1; i++) {
            printf("Enter value for a[%d]]:", i);
            scanf("%d", &a[i]);
   }
   printf("Enter amount: ");
   scanf("%d",&V);

   int  b[n+1][V+1];
    for(i=0; i<n+1; i++)
    {
        b[i][0]=0;
    }
    for(i=1; i<V+1; i++)
    {
         b[0][i]=99;
    }
   for(i=1; i<n+1; i++) {
      for(j=1;j<V+1;j++)
      {
          x=b[i-1][j];
          if(j>=a[i])
            y=1+b[i][j-a[i]];

          if(j<a[i])
            b[i][j] = x;

          else if(x<y)
          {
              b[i][j]=x;

          }

          else
          {
              b[i][j]=y;

          }
      }
   }

   for(i=0; i<n+1; i++) {
      for(j=0;j<V+1;j++)
      {
          printf(" %d ",b[i][j]);
      }
      printf("\n");
   }
     printf("\nCoin Required : %d\n",b[n][V]);
 i=n;
 j=V;
    int mini=b[i][j];

    while(j!=0)
    {
      if(b[i-1][j]== mini)
      {
          i--;
      }
      else
      {
        printf(" %d ",a[i]);
        j=j-a[i];
        mini=b[i][j];

      }
    }


   return 0;
}
