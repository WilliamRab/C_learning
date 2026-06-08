#include<stdio.h>
int main(){
	int a,b,i,j,sum=0;
	scanf("%d%d",&a,&b);
	int table[a][b];
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			scanf("%d",&table[i][j]);
		}
	}
	
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			if(i==0||j==0||i==a-1||j==b-1){
				sum+=table[i][j];
			}
		}
	}
	printf("%d",sum);
	return 0;
	
}
