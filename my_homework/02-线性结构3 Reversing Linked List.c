#include <stdio.h>

#define MaxSize 100005

int main()
{
    int Data[MaxSize];
    int Next[MaxSize];
    int List[MaxSize];

    int FirstAddr,N,K;
    scanf("%d %d %d",&FirstAddr,&N,&K);
    for(int i=0;i<N;i++)
    {
        int tempAddr,tempData,tempNext;

        scanf("%d %d %d",&tempAddr,&tempData,&tempNext);
        Data[tempAddr]=tempData;
        Next[tempAddr]=tempNext;        
    }
    int sum=0; /* 累计有效节点数 */
    while(FirstAddr!=-1)
    {
        List[sum++]=FirstAddr;
        FirstAddr=Next[FirstAddr];
    }

    for(int i=0;i<sum-sum%K;i+=K)
    {
        for(int j=0;j<K/2;j++)
        {
            int t=List[i+j];
            List[i+j]=List[i+K-j-1];
            List[i+K-j-1]=t;
        }
    }

    for(int i=0;i<sum-1;i++)
    {
        printf("%05d %d %05d\n",List[i],Data[List[i]],List[i+1]);
    }
    printf("%05d %d -1\n",List[sum-1],Data[List[sum-1]]);
    
    return 0;
}