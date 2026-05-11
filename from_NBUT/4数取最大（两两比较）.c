#include<stdio.h>
int max(int x,int y){
	if(x>y){
		return x; 
	}
	else return y;
}
int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d",max(max(a,b),max(c,d)));
	return 0;
}
