#include<stdio.h>

//使用switch...case语句完成月份的数字与英文之间的转换
int main()
{
    int month;
    printf("请输入月份：");
    scanf("%d",&month);
    switch( month ){
        case 1:printf("January\n");break;
        case 2:printf("February\n");break;
        case 3:printf("March\n");break;
        case 4:printf("April\n");break;
        case 5:printf("May\n");break;
        case 6:printf("June\n");break;
        case 7:printf("July\n");break;
        case 8:printf("August\n");break;
        case 9:printf("September\n");break;
        case 10:printf("October\n");break;
        case 11:printf("November\n");break;
        case 12:printf("December\n");break;
    }
    return 0;
}

//使用数组实现
int main(void)
{
    int number;
    char month[12][20]={"January","February","March","April",
                        "May","June","July","August","September",
                         "October","November","December"};
    printf("请输入月份：");
    scanf("%d",&number);
    if(number<=12 && number>=1)
    {
        printf("%s\n",month[number-1]);
    }
    else{
        printf("请输入正确的月份。\n");
    }
    return 0;
}
