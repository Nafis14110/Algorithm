#include<stdio.h>

#define SIZE 6

int main()

{

    int A[SIZE]={1,2,1,1,4,1,4};

    int OccurCount[SIZE]={0,0,0,0,0,0};

    for(int i=0; i<SIZE; i++)
        OccurCount[A[i]]++;
    for(int i=0; i<SIZE; i++)

printf("%d is occur %d times\n", i, OccurCount[i]);

    return 0;
}
