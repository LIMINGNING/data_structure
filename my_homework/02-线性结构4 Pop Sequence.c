#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 1000 /* 最大容量 */

typedef struct SNode *Stack;
struct SNode
{
    int Top; /* 栈顶 */
    int Data[MaxSize]; /* 元素 */
    int Capacity; /* 容量 */
};

int IsPopPossible(int array[],int M,int N); /* 判断是否可能为出栈序列 */

int main()
{
    int M,N,K;
    scanf("%d %d %d",&M,&N,&K); /* 条件读入 */
    int array[N];
    for(int i=0;i<K;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&array[j]); /* 读入每一行 */
        }
        if(IsPopPossible(array,M,N)) /* 非零表示存在可能 */
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}

int IsPopPossible(int array[],int M,int N)
{
    int count=0;

    Stack S=(Stack)malloc(sizeof(struct SNode)); /* 申请并初始化一个空栈 */
    S->Capacity=M;
    S->Top=-1;

    for(int i=1;i<=N;i++)
    {
        if(S->Capacity==S->Top+1) /* 栈满 */
        {
            return 0;
        }
        else
        {
            S->Data[++S->Top]=i; /* 入栈 */
        }
        while(S->Data[S->Top]==array[count]) /* 满足条件则出栈 */
        {
            S->Top--;
            count++;
        }
    }

    if(count == N) /* 全部找到且输出时 */
    {
        return 1;
    }
    else
    {
        return 0;
    }
}