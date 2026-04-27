#include<stdio.h>
int main(){
	int t=100,a,b,c;
	while(t<1000){
		a=t/100;
		b=t%100/10;
		c=t%10;
		if(a*a*a+b*b*b+c*c*c==t){
			printf("%d\n",t);
		}
		
		t++;
	}
	
	return 0; 
}
