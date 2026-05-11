#include<stdio.h>
int main(){
	int score;
	scanf("%d",&score);
	//if, else if, else
	if(score>90){
		printf("Good");
	} 
	else if(score>=60){
		printf("Pass");
	}
	else printf("Fail");
	
	//switch case
	switch(score/10){
		case 10:
		case 9:
			printf("Good");break;//break用于跳出switch结构或循环结构
		case 8:
		case 7:
		case 6:
			printf("Pass");break;
		default:
			printf("Fail");break;
	}
	
	return 0;
}
