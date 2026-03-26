#include<stdio.h>
int main()
{
	char str[100] = "\0";  
    printf("Give me a str£º");
    gets(str);
    putchar('\n');
    printf("The str is£º");
    printf("%s\n", str);
	putchar('\n');
	putchar('\n');
	
	return 0;




}
