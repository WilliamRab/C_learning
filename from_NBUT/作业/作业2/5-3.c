#include<stdio.h>
int main(){
	int a,b,c,maxx;
	scanf("%d%d%d",&a,&b,&c);
	if (a>b){
		maxx=a;
	}
	else maxx=b;
	if(c>maxx){
		maxx=c;
	}
	printf("%d",maxx);
	return 0;
	
	
}
