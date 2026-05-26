#include<stdio.h>
int main(){
	int a[3][2]={1,3,5,2,4,6};
	int b[2][4]={9,8,7,3,2,1,5,6};
	int c[3][4],i,j;
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			c[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j];
		}
		
	}
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
