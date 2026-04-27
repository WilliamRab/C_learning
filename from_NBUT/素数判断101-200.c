#include<stdio.h>

int main(){
	int a,b,i,p;
	for(i=101;i<=200;i++){
		for(b=2;b<=i/2;b++){
		
		if(i%b==0){
				p=0;
				break;
			}
			p=1;
			
		}
		
		
		if(p==1){
			printf("%d\n",i);
		}
		
	}
	
	
	return 0;
}
