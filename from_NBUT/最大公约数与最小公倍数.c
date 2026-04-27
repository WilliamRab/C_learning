#include<stdio.h>
int dd(int x,int y){
	if(x%y==0){
		return y;
	}
	else return dd(y,x%y);
	
}


int main(){
	int a,b,gys,gbs;
	scanf("%d%d",&a,&b);
	if(a>b){
		gys=dd(a,b);
	}
	else gys=dd(b,a);
	printf("zdgys %d\n",gys);
	
	printf("zxgbs %d",gys*(a/gys)*(b/gys));
	
	return 0;
} 
