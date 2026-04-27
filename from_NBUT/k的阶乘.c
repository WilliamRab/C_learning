#include<stdio.h>
int jiecheng(int x){
	int i,p;
	p=1;
	for(i=x;i>0;i--){
		p=p*i;
		
	}
	return p;
	
}


int main(){
	int k;
	scanf("%d",&k);
	printf("%d",jiecheng(k));
	return 0;
	
	
	
}
