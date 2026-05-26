#include<stdio.h>
int max;//全局变量 
int maxx(int x,int y){//返回值类型 函数名(形参表说明) 
	return x>y?x:y;//返回值 
} 
int main(){
	int a,b;//局部变量 
	scanf("%d%d",&a,&b);
	max=maxx(a,b);//调用函数 
	printf("%d",max);
	return 0;
}
