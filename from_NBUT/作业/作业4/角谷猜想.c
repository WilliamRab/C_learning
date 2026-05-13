#include<stdio.h>
void jg(int x){
	if(x==1){
		printf("End");
		return;
	}
	if(x%2==0){
		printf("%d/2=%d\n",x,x/2);
		jg(x/2);
		return;
	}
	else{
		printf("%d*3+1=%d\n",x,x*3+1);
		jg(x*3+1);
		return;
	}
}
int main(){
	int i;
	scanf("%d",&i);
	jg(i);
	return 0;
}
