#include<stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	switch(a/10){
		case 10:
		case 9:
			printf("优秀");
			break;
		case 8:
			printf("良好");
			break;
		case 7:
			printf("中等");
			break;
		case 6:
			printf("及格");
			break;
		default:
			printf("不及格");
		
	}
	return 0;
	
}
