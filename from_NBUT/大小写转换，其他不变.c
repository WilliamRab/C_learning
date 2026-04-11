#include<stdio.h>
int main(){
	char a;
	scanf("%c",&a);
	if (a>=65 && a<=89){
		a=a+32;
	}
	else if (a>=97 && a<=97+24){
		a=a-32;
	}
	printf("%c",a);
	return 0;
	
}
