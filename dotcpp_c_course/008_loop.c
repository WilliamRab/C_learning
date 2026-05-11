#include<stdio.h>
int main(){
	//while
	int i=0;
    while(i++<20)
    {
        printf("count %d\n",i);
    }
	
	printf("\n");
	printf("\n");
	
	
	
	//do while
	i=0;
    do
    {
        printf("count %d\n",i);
    }while(i++<20);
    printf("\n");
    printf("\n");
    
    
    
    //for
    for(i=0;i<20;i++)
    {
        printf("count is %d\n",i);
    }
    printf("\n");
    printf("\n");
    
    
    
    
	//可以嵌套循环结构 
	
	
	//continue 仅用于循环中，用于提前结束本次循环进行下次循环 
	int n=0;
    int sum=0;
    for(n=0;n<100;n++)
    {
        if(n%2!=0) //如果对2取余不等于0，说明没有整除，当然不是偶数啦
        {
            continue;
        }
        sum=sum+n;//将偶数相加 
    }
    printf("%d\n",sum);
	
	
	return 0;
}
