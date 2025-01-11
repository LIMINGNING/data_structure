#include <stdio.h>

int MaxSubseqSum( int A[], int N, int *head, int *tail)
{
    int ThisSum;
    float MaxSum=-0.1;
    int i,j;
    for(i=0;i<N;i++)
    {
        ThisSum=0;
        for(j=i;j<N;j++)
        {
            ThisSum+=A[j];
            if(ThisSum>MaxSum)
            {
                *head=i;
                *tail=j;
                MaxSum=ThisSum;
            }
        }
    }
    if(MaxSum<0)
    {
        *head=0;
        *tail=N-1;
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

    int head=0;
    int tail=0;
    printf("%d ",MaxSubseqSum(A,N,&head,&tail));
    printf("%d ",A[head]);
    printf("%d\n",A[tail]);
}