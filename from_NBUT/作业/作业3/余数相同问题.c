#include<stdio.h>
int main(){
	int a,b,c,i;
	scanf("%d%d%d",&a,&b,&c);
	i=2;
	while(i>1){
		if(a%i==b%i && b%i==c%i){
			
			printf("%d",i);
			break;
			
		}
		
		i++;
	}
	
	
	
	return 0;
	
	
}
