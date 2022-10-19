#include<stdio.h>
int main()
{

    int i,j,n,High = 0,temp = 0;
    printf("Enter Array size: ");
    scanf("%d",&n);
    printf("\n");
    int Array[n],l[n],pre[n];
    for(i=0; i<n; i++)
    {
        printf("Enter Array value:", i);
        scanf("%d", &Array[i]);
    }
    for(i=0; i<n; i++)
    {
        l[i]=1;
    }
    for(i=0; i<n; i++)
    {
        pre[i]=-1;
    }
    for(i=1; i<n; i++)
    {
        for(j=0; j<i; j++)
        {
            if(Array[i]>Array[j] && l[i]<(l[j]+1))
            {
                l[i]=l[j]+1;
                pre[i]=j;
            }
        }
    }
    printf("\n");
    for(i=0; i<n; i++)
    {
        printf(" %d ",Array[i]);
    }
    printf("\n");
    for(i=0; i<n; i++)
    {
        printf(" %d ",l[i]);
    }
    printf("\n");
    for(i=0; i<n; i++)
    {
        printf(" %d ",pre[i]);
    }
    printf("\n");

    for(int i=0 ; i<n ; i++)
    {
        if(Array[i] > High)
        {
            High = l[i];
            temp = i;
        }
    }
    printf("\n");
    printf("Length of LIS: %d \n",High);

    i = temp;
    j = 0;
    int subsequence[High];

    while(i != -1)
    {

        subsequence[j] =Array[i];
        i = pre[i];
        j++;

    }
    printf("\n");
    printf("The longest increasing subsequence: ");
    for ( i = High-1; i>0; i--)
    {
        printf(" %d ",subsequence[i]);

    }
    return 0;
}
