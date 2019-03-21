#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    const int AMOUNT=10;
    int number[AMOUNT];
    int i;
    int x;

    for(i=0;i<AMOUNT;i++)   //初始化数组
    {
        number[i]=0;
    }
    printf("please input your data:\n");
    scanf("%d",&x);
    while(x!=-1)
    {
        if(x>=0 && x<=AMOUNT-1)
        {
            number[x]++;
        }
        scanf("%d",&x);
    }
    for(i=0;i<AMOUNT;i++)
    {
        printf("%d有:%d个。\n",i,number[i]);
    }
    return 0;
}
