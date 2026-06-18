#include<stdio.h>
int main(){
	int n,p,i,k=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&p);
	for(i=0;i<n-1;i++){
		if(a[i]+a[i+1]==p){
			k++;
		}
	}
	printf("%d",k);
	return 0;
}
