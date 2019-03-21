1.判断是否为素数
int isPrime(int x);
int main(void)
{
	int x;
	scanf("%d",&x);
	if(isPrime(x))
	{
		printf("%d是素数\n",x);
	}
	else
	{
		printf("%d不是素数\n",x);
	}
	return 0;
}

方法一：
2.从2到x-1 测试是否可以整除   (该方法对n要循环n-1遍，当n较大时，需循环n遍）
int isPrime(int x)
{
  int ret=1;
  int i;
  if(x==1) ret=0;
  for(i=2;i<x;i++)
  {
    if(x%i==0)
    {
      ret=0;
      break;
    }
  }
  return ret;
}

方法二：
3.去掉偶数，从3到x-1，每次加2      (如果x是偶数，立即判断其不是素数；否则要循环（n-3）/2+1遍，当n很大时是n/2遍）
int isPrime(int x)
{
  int ret=1;
  int i;
  if(x==1 ||(x%2==0&&x!2))  ret=0;
  for(i=3;i<x;i+=2)
  {
    if(x%i ==0)
    {
      ret=0;
      break;
    }
  }
  return ret;
}

方法三：
4.不需要循环至x-1,到sqrt(x)就够了
int isPrime(int x)
{
  int ret=1;
  int i;
  if(x==1||(x%2==0 && x!=2))  ret=0;
  for(i=3;i<sqrt(x);i+=2)
  {
    if(x%i==0)
    {
      ret=0;
      break;
    }
  }
  return ret;
}      

方法四：
5.判断是否能被已知的且<x的素数整除
int isPrime(int x,int knownPrimes[],int numberOfKnowPrimes)
{
  int ret=1;
  int i;
  for( i=0;i<numberOfKnowPrimes;i++)
  {
    if(x%knownPrimes[i]==0)
    {
      ret=0;
      break;
    }
  }
  return ret;
}

int main(void)
{
  const int number=100;
  int prime[number]={2};
  int count=1;
  int i=3;
  while(i<number)
  {
    if(isPrime(i,prime,count))
    {
      prime[count++]=i;
    }
    i++;
  }
  for(i=0;i<number;i++)
  {
    printf("%d",prime[i]);
    if((i+1)%5) printf("\t");
    else printf("\n");
  }
  return 0;
}


!!!!6.构造素数表
·欲构造n以内的素数表
 1.令x为2
 2.将2x、3x、4x...ax<n的数标记为非素数
 3.令x为下一个没有被标记为非素数的数，重复2；直到所有的数都已尝试完毕
 
 程序步骤：
 1.开辟prime[n]，初始化其所有元素为1，prime[x]为1 表示x为素数；
 2.令x=2
 3.如果x是素数，则对于（i=2;x*i<n;i++),令prime[i*x]=0
 4.令x++，如果x<n，重复3，否则结束
 
 int main(void)
{
    const int maxNumber=100;
    int isPrime[maxNumber];
    int i;
    int x;
    for (i=0;i<maxNumber;i++)   //初始化isPrime[]
    {
        isPrime[i]=1;
    }
    
    for (x=2;x<maxNumber;x++)   //判断x++，直到x<maxNumber
    {
        if(isPrime[x])    //判断x是否为素数，将2*x、3*x、...<maxNumber 标记为非素数
        {
            for (i=2;i*x<maxNumber;i++)
            {
                isPrime[i*x]=0;
            }
        }
    }

    for(i=2;i<maxNumber;i++)
    {
        if(isPrime[i])
        {
            printf("%d\t",i)；
        }
    }
    return 0;
}
