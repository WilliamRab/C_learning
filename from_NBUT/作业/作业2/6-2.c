#include<stdio.h>
int main(){
	float h,w,bmi;
	scanf("%f%f",&h,&w);
	bmi=w/(h*h);
	if (bmi<18.5){
		printf("Æ«ÊÝ");
		}
	else if(bmi<24) {
		printf("Õý³£");
	}
	else if(bmi<28) {
		printf("Æ«ÅÖ");
	}
	else if(bmi<40) {
		printf("·ÊÅÖ");
	}
	else printf("ÖØ¶È·ÊÅÖ");
	return 0; 
	
} 
