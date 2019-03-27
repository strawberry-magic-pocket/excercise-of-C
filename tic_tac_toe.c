#include <stdio.h>

int main(void)
{
    const int size=3;
    int board[size][size];
    int i,j;
    int numOfX;
    int numOfO;
    int result=-1;    // -1:没人赢，1:X赢，0:O赢
    printf("please input matrix:\n");
    //读入矩阵
    for (i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            scanf("%d",&board[i][j]);
        }
    }
    /*
    //检查行
    for(i=0;i<size && result == -1;i++)
    {
        numOfO=numOfX=0;
        for(j=0;j<size;j++)
        {
            if(board[i][j]==1)
            {
                numOfX++;
            }
            else{
                numOfO++;
            }
        }
        if(numOfO==size)
        {
            result=0;
        }
        else if(numOfX==size)
        {
            result=1;
        }
    }
    
    //检查列
    if(result==-1){
        for(j=0;j<size && result == -1;j++)
        {
            numOfO=numOfX=0;
            for(i=0;i<size;i++)
            {
                if(board[i][j]==1)
                {
                    numOfX++;
                }
                else{
                    numOfO++;
                }
            }
            if(numOfO==size)
            {
                result=0;
            }
            else if(numOfX==size)
            {
                result=1;
            }
        }
    }
    */
    //使用双重循环检查行与列
    for(i=0;i<size;i++)
    {
        numOfX=numOfO=0;
        for(j=0;j<size;j++)
        {
            for(i=0;i<size;i++)
            {
                if(board[i][j]==1)
                {
                    numOfX++;
                }
                else{
                    numOfO++;
                }
            }
        }
        if(numOfX==size){
            result=0;
            break;
        }
        else if(numOfO==size)
        {
            result=1;
            break;
        }
    }
    
    //检查主对角线
    numOfO=numOfX=0;
    for(i=0;i<size;i++)
    {
        if(board[i][i]==1)
        {
            numOfX++;
        }
        else{
            numOfO++;
        }
    }
    if(numOfO==size){
        result=0;
    }
    else if(numOfX==size)
    {
        result=1;
    }
    
    //检查次对角线
    numOfX=numOfO=0;
    for(i=0;i<size;i++)
    {
        if(board[i][size-i-1]==1)
        {
            numOfX++;
        }
        else{
            numOfO++;
        }
    }
    if(numOfO==size){
        result=0;
    }
    else if(numOfX==size)
    {
        result=1;
    }
    
    if(result==1)
    {
        printf("X win!\n");
    }
    else if(result==0)
    {
        printf("O win!\n");
    }
    else{
        printf("nobody wins!\n");
    }
    return 0;
}
