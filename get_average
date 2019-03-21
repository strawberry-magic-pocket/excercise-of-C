#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int count;
    int x;
    int cnt=0;
    double sum=0.0;
    double average=0.0;
    printf("请输入要计算的数字总数：\n");
    scanf("%d",&count);
    if(count>0)   //判断总数
    {
        int number[count];
        int i,j;
        for(i=0;i<count;i++)   //初始化数组
        {
            number[i]=0;
        }
        printf("请输入要计算的数字(以-1结束）：\n"); 
        scanf("%d",&x);   
        while(x!=-1)       //输入数组元素，以-1结束
        {
            number[cnt]=x;
            sum+=x;
            cnt++;
            scanf("%d",&x);
        }
        average=sum/cnt;
        printf("sum=%lf average=%lf",sum,average);
        printf("输出大于平均数的数字：\n");
        
        for(j=0;j<count;j++)      //找出大于平均值的元素
        {
            if(number[j]>average)
            {
                printf("number[%d]=%d\n",j,number[j]);
            }
        }
    }
    return 0;
    
}
