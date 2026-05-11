#include<stdio.h>
void zhi(int x){
	int i;
	for(i=2;i<=(x/2);i++){
		if(x%i==0){
			printf("%d*",i);
			zhi(x/i);
			return;	
		}
		
	}
	printf("%d",x);
	return;
	
}

int main(){
	int a;
	scanf("%d",&a);
	zhi(a);
	return 0;
	
}
