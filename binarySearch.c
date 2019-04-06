#include <stdio.h>
int  binarySearch(int list[],int length,int s);
int main()
{
    int x;
    int length;
    int cnt=0;
    int s;
    printf("请输出要查找的序列的长度：");
    scanf("%d",&length);
    if(length>0)
    {
        int a[length];
        int i;
        for(i=0;i<length;i++)  //初始化数组
        {
            a[i]=0;
        }
        printf("请输入要查找的序列：\n");
        scanf("%d",&x);
        while(x!=-1)
        {
            a[cnt]=x;
            cnt++;
            scanf("%d",&x);
        }
        printf("请输入要查找的数字：\n");
        scanf("%d",&s);
        
        int j=binarySearch(a,length, s);
        if(j!=-1)
        {
            printf("a[%d]=%d\n",j,s);
        }
        else
        {
            printf("%Not find.\n",s);
        }
    }
    return 0;
}

int binarySearch(int list[],int length,int s)
{
    int mid,midvalue;
    int left=0,right=length-1;
    while(left<=right)
    {
        mid=(left+right)/2;
        midvalue=list[mid];
        if(s>midvalue)
        {
            left=mid+1;
        }
        else if(s<midvalue)
        {
            right=mid-1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
