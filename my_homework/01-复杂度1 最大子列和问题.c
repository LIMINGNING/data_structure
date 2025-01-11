#include <stdio.h>

int MaxSubseqSum4(int A[],int N)
{
    int ThisSum,MaxSum;
    ThisSum=MaxSum=0;
    int i;
    for(i=0;i<N;i++)
    {
        ThisSum+=A[i];
        if(ThisSum>MaxSum)
            MaxSum=ThisSum;
        else if(ThisSum<0)
            ThisSum=0;
    }
    return MaxSum;
}

int MaxSubseqSum2(int A[],int N)
{
    int ThisSum,MaxSum=0;
    int i,j,k;
    for(i=0;i<N;i++)
    {
        ThisSum=0;
        for(j=i;j<N;j++)
        {
            ThisSum+=A[j];
            if(ThisSum>MaxSum)
                MaxSum=ThisSum;
        }
    }
    return MaxSum;
}

int main()
{
    int N;
    scanf("%d",&N);
    int A[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("%d",MaxSubseqSum2(A,N));
}