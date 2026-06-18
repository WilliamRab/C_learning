#include<stdio.h>
int main(){
	int locate,i;
	int k=0;
	char a[1000],c;
	gets(a);
	scanf("%c",&c);
	for(i=0;i<1000;i++){
		if(a[i]=='/0'){
			break;
		}
		if(a[i]==c){
			locate=i;
			k=1;
			break;
		}
	} 
	printf("%d",k==1?locate:-1);
	return 0;
}
