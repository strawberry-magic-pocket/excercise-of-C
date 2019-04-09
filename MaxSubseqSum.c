#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define M 10000

int Max3(int A,int B,int C);
int MaxSubseqSum1(int A[],int N);
int MaxSubseqSum2(int A[],int N);
//int DivideAndConquer(int List[],int left,int right);
int MaxSubseqSum3(int List[],int N);
int MaxSubseqSum4(int A[],int N);
clock_t start,stop;
double duration;

int main()
{
    int A[M];
    int length;
    int Max1,Max2,Max3,Max4;
    Max1=Max2=Max3=Max4=0;
    length=sizeof(A)/sizeof(int);
    int i;
    for(i=0;i<M;i++)
    {
        A[i]=rand()%100;
    }
    
    printf("子列的元素个数：%d\n",M);
    start=clock();
    Max1=MaxSubseqSum1(A, length);
    stop=clock();
    duration=((double)(stop-start))/CLOCKS_PER_SEC;
    printf("Max1=%d,算法一用时：%lf\n",Max1,duration);
    
    start=clock();
    Max2=MaxSubseqSum2(A, length);
    stop=clock();
    duration=((double)(stop-start))/CLOCKS_PER_SEC;
    printf("Max2=%d,算法二用时：%lf\n",Max2,duration);
    
    start=clock();
    Max3=MaxSubseqSum3(A, length);
    stop=clock();
    duration=((double)(stop-start))/CLOCKS_PER_SEC;
    printf("Max3=%d,算法三用时：%lf\n",Max3,duration);
    
    start=clock();
    Max4=MaxSubseqSum4(A, length);
    stop=clock();
    duration=((double)(stop-start))/CLOCKS_PER_SEC;
    printf("Max4=%d,算法一用时：%lf\n",Max4,duration);
    
    /*
    Max2=MaxSubseqSum2(A, length);
    Max3=MaxSubseqSum3(A, length);
    Max4=MaxSubseqSum4(A, length);
    
    printf("Max1=%d\n",Max1);
    printf("Max2=%d\n",Max2);
    printf("Max3=%d\n",Max3);
    printf("Max4=%d\n",Max4);
    */
    return 0;
}

int Max3(int A,int B,int C)
{
    return A>B?A>C?A:C:B>C?B:C;
}

int MaxSubseqSum1(int A[],int N)
{
    int ThisSum,MaxSum=0;
    int i,j,k;
    for(i=0;i<N;i++){      /*i是子列左端位置*/
        for(j=i;j<N;j++){  /*j是子列右端位置*/
            ThisSum=0;     /*ThisSum是从A[i]到A[j]的子列和*/
            for(k=i;k<=j;k++)
                ThisSum+=A[k];
            if(ThisSum>MaxSum)   /*如果刚得到的子列和更大*/
                MaxSum=ThisSum;  /*更新最大和*/
        } /*j循环结束*/
    } /*i循环结束*/
    return MaxSum;
}

int MaxSubseqSum2(int A[],int N)
{
    int ThisSum,MaxSum=0;
    int i,j;
    for(i=0;i<N;i++){
        ThisSum=0;
        for(j=i;j<N;j++){
            ThisSum+=A[j];
            /*对于相同的i，不同的j，只要在上一次循环（当前j-1）的基础上累加1项（当前A[j]）即可*/
            if(ThisSum>MaxSum)
                MaxSum=ThisSum;
        }
    }
    return MaxSum;
}

int DivideAndConquer(int List[],int left,int right)
{ /*分治法求List[left]到List[right]的最大子列和*/
    int MaxLeftSum,MaxRightSum;  /*存放左右子列的解*/
    int MaxLeftBorderSum,MaxRightBorderSum; /*存放跨分界线的结果*/
    
    int LeftBorderSum,RightBorderSum;
    int center,i;
    
    if(left==right){ /*递归的终止条件，子列只有1个数字*/
        if(List[left]>0) return List[left];
        else return 0;
    }
    
    /*下面是“分”的过程*/
    center=(left+right)/2; /*找到中分点*/
    /*递归求得两边子列的最大和*/
    MaxLeftSum=DivideAndConquer(List,left,center);
    MaxRightSum=DivideAndConquer(List, center+1, right);
    
    /*下面求跨分界线的最大子列和*/
    MaxLeftBorderSum=0;
    LeftBorderSum=0;
    for(i=center;i>=left;i--){ /*从中线向左扫描*/
        LeftBorderSum+=List[i];
        if(LeftBorderSum>MaxLeftBorderSum)
            MaxLeftBorderSum=LeftBorderSum;
    }/*左边扫描结束*/
    
    MaxRightBorderSum=0;
    RightBorderSum=0;
    for(i=center+1;i<=right;i++){/*从中线向右扫描*/
        RightBorderSum+=List[i];
        if(RightBorderSum>MaxRightBorderSum)
            MaxRightBorderSum=RightBorderSum;
    }/*右边扫描结束*/
    
    /*下面返回“治”的结果*/
    return Max3(MaxLeftSum,MaxRightSum,MaxLeftBorderSum+MaxRightBorderSum);
}

int MaxSubseqSum3(int List[],int N)
{/*保持与前两种算法相同的函数接口*/
    return DivideAndConquer(List, 0, N-1);
}

int MaxSubseqSum4(int A[],int N)
{
    int ThisSum,Maxsum;
    int i;
    ThisSum=Maxsum=0;
    for(i=0;i<N;i++){
        ThisSum+=A[i];   /*向右累加*/
        if(ThisSum>Maxsum) /*发现更大和则更新当前结果*/
            Maxsum=ThisSum;
        else if(ThisSum<0) /*若当前子列和为负，抛弃之*/
            ThisSum=0;
    }
    return Maxsum;
}
