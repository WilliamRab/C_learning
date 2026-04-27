#include<stdio.h>
int main(){
	int a,b;
	char c;
	scanf("%d %d %c",&a,&b,&c);
	if (c=='/'){
		if(b==0){
			printf("Divided by zero");
		}
		else printf("%d",a/b);
	}
	
	else if(c=='*'){
		printf("%d",a*b);
	}
	else if(c=='+'){
		printf("%d",a+b);
	}
	else if(c=='-'){
		printf("%d",a-b);
	}
	else printf("Invalid operator"); 
	
	return 0;
}
