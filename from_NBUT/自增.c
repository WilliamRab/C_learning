#include<stdio.h>
int main()
{
	int a,b = 1;
	printf("%d\n",a++);//先算后增 
	printf("%d\n",++b);//先增后算 
	
	return 0;
}
