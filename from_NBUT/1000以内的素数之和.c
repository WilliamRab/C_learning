#include<stdio.h>
int su(int k){
	int i;
	for(i=2;i<=(k/2);i++){
		if(k%i==0){
			return 0;	
		}	
	}
	return 1;
}

int main(){
	int j,s;
	s=0;
	for(j=2;j<=1000;j++){
		s=s+j*su(j);
	}
	printf("%d",s);
	return 0;
}
