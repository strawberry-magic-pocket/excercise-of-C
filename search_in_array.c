#include <stdio.h>

int search(int key,int a[],int length);//函数声明

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[]={2,4,5,6,7,8,9,10,11};
    int x;
    int loc;
    printf("请输入你要找的数字：");
    scanf("%d",&x);
    loc=search(x,a,sizeof(a)/sizeof(a[0]));
    if(loc!=-1)
    {
        printf("%d在第%d个位置上,即a[%d]=%d\n",x,loc,loc-1,x);
    }
    else
    {
        printf("%d不存在。\n",x);
    }
    
    return 0;
}

int search(int key,int a[],int length)
{
    int ret=-1;
    int i;
    for(i=0;i<length;i++)
    {
        if(a[i]==key)
        {
            ret=i+1;
            break;   //跳出循环
        }
    }
    return ret;
}
