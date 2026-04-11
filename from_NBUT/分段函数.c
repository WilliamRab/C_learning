#include<stdio.h>
int main(){
	int x,y;
	scanf("%d",&x);
	if (x<=0){
		y=x*x;
	}
	else if(x<3){
		y=x-5;
	}
	else y=3*x+1;
	printf("%d",y);
	return 0;
	
	
}
