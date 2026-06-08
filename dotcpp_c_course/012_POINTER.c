#include<stdio.h>
struct INFO
{
    int a;
    char b;
    double c;
};
int main()
{
    int num=2014;
    int *pn=&num;//将&num的地址赋给*pn,一个int类型的指针变量 
    printf("num Address = 0x%x,num=%d\n",&num,num);
    printf("p = 0x%x,*p=%d\n",pn,*pn);
    printf("%d\n",*&num);
        
	printf("/n");
    int *p0;
    char *p1;
    float *p2;
    double *p3;
    struct INFO *p4;   //struct INFO类型为结构体类型
    void *p5;
    printf("int point size is :%d\n",sizeof(p0));
    printf("char point size is :%d\n",sizeof(p1));
    printf("float point size is :%d\n",sizeof(p2));
    printf("double point size is :%d\n",sizeof(p3));
    printf("struct point size is :%d\n",sizeof(p4));
    printf("void point size is :%d\n",sizeof(p5));
        
	printf("/n"); 
	printf("int size is :%d\n",sizeof(*p0));
    printf("char size is :%d\n",sizeof(*p1));
    printf("float size is :%d\n",sizeof(*p2));
    printf("double size is :%d\n",sizeof(*p3));
    printf("struct size is :%d\n",sizeof(*p4));
    printf("void size is :%d\n",sizeof(*p5));
	
	printf("\n");	
	//指针与数组
	int k[10]; /*定义a为包含10个整型数据的数组*/
	int *p; /*定义p为指向整型变量的指针*/
	p=&k[0]; /*把k[0]元素的地址赋给指针变量p*/ 
		/*
		等价写法 
		p=k;		a表示a[0]的地址 
		int *p=k; 	声明并赋值 
		*/
	
	//对于指向首地址的指针p，p+i(或a+i)就是数组元素a[i]的地址
	int i;
    int a[10]={1,2,3,4,5,6,7,8,9,0};
    int *pt=a;
    for(i=0;i<10;i++){
        printf("P Value:%d   a Value :%d\n",*(pt++),*(a+i));
    }
    printf("\n");

    //指针与字符串
	char *str="www.dotcpp.com"; 
        
        
    return 0;
}
