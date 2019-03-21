#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[10]={[1]=1,2,[5]=5};
    int b[10];
    int i;
    for (i=0;i<sizeof(a)/sizeof(a[0]);i++)
    {
        b[i]=a[i];
    }
    for (i=0;i<sizeof(a)/sizeof(a[0]);i++)
    {
        printf("a[%d]=%d\t",i,a[i]);
    }
    printf("\n");
    for (i=0;i<sizeof(b)/sizeof(b[0]);i++)
    {
        printf("b[%d]=%d\t",i,b[i]);
    }
    printf("\n");
    return 0;
}
