#include<stdio.h>
int main()
{


	/*
	putchar() 字符输出  int putchar(int ch)
	getchar() 字符输入 
	*/
	char x=getchar();//先等待输入字符，enter后继续 
	putchar('x');//输出字符'x' 
	putchar('\n');//换行 
	putchar(x);//输出x变量的字符
	putchar('\n');
	putchar('\n');
	
	
	
	
	
	
	
	
	
	/*
	printf() 格式化输出  printf("格式控制字符串",输出表项);
			格式控制字符串 分为 
				非格式字符串 原样打印 
				格式字符串   % [输出最小宽度] [.精度] [长度] 类型
			常用格式字符：
			d,i  以十进制形式输出有符号整数(正数不输出符号)
			O    以八进制形式输出无符号整数(不输出前缀0)
			x    以十六进制形式输出无符号整数(不输出前缀0x)
			U    以十进制形式输出无符号整数
			f    以小数形式输出单、双精度类型实数
			e    以指数形式输出单、双精度实数
			g    以%f或%e中较短输出宽度的一种格式输出单、双精度实数
			C    输出单个字符 
			S    输出字符串
		
			常用转义符： 
			\n   换行 
			\t   制表 
			\\   打印 \ 
			\'   打印 '
			\"   打印 "
		
		
	*/
	int a=65;
	printf("a is %d\n",a);
	printf("a is %c\n",a);//65对应ASCII码的'A' ,97对应'a' ,48对应0 
	printf("a is 0%o\n",a);
    printf("a is 0x%x\n",a);//注意前缀是自己输入的！！ 
	
	float b=114.514;
	printf("It is%8.2f\n",b);//%m.nf  m宽度(8->2) n精度 
	//修饰符*  用参数自定义字段宽度
	double width = 8; 
	printf("The num a is %*d\n",width,a);
	printf("The num b is %*.*f\n",width,1,b);
	printf("%%");//输出一个% 
	putchar('\n');
	putchar('\n');
	
	
	
	
	
	
	
	
	
	
	/*
	scanf()  格式化输入  scanf("格式控制字符串",输入项地址列表);  地址 = 地址运算符“&”+ 变量名
		注：1）格式说明符中，可以指定数据的宽度，但不能指定数据的精度
			2）输入long类型数据时必须使用%ld，输入double数据必须使用%lf或%le
			3）附加格式说明符“*”使对应的输入数据不赋给相应的变量 
 
 
转换说明符
%c	      把输入解释成一个字符
%d	       把输入解释成一个有符号十进制整数
%e,%f,%g,%a	把输入解释成一个浮点数(%a是C99的标准)
%E,%F,%G,%A	把输入解释成一个浮点数(%A是C99的标准)
%i	把输入解释成一个有符号十进制整数
%o	把输入解释成一个有符号的八进制整数
%p	把输入解释成一个指针(一个地址)
%s	把输入解释成一个字符串：输入的内容以第一个非空白字符作为开始，并且包含直到下一个空白字符的全部字符
%u	把输入解释成一个无符号十进制整数
%x,%X	把输入解释称一个有符号十六进制整数


	*/
	int num;
    printf("Please enter three number:\n");
    scanf("%*d %*d %d",&num);// * 在scanf()中截然不同，放在%和说明符字母之间，使函数跳过相应的输入项目 
    printf("The last number is %d\n",num);
    putchar('\n');
	putchar('\n');
	//如果它没有读取任何项目，scanf()返回0 
    
    
	//当它检测到“文件末尾”(end of file)时，它返回EOF
	//(EOF在是文件stdio.h中的定义好的一个特殊值，一般，#define指令将EOF的值定义为-1)
	//当您学过循环之后，或在参加ACM这样的比赛及使用在线评测系统的时候会经常用到这种写法。 
	
	
	
	
	
	
	
	/*
	gets()  字符串接收函数  
	另处单独展示 
	*/
	
	
	//char str[100] = "\0";  
    //printf("Give me a str：");
    //gets(str);
    //putchar('\n');
    //printf("The str is：");
    //printf("%s\n", str);
	//putchar('\n');
	//putchar('\n');
	
	//需要注意的是gets不会检查输入的字符串长度，即可能超出字符串数组的长度造成内存溢出
	//这其实也是gets函数不安全的原因，其已经在不少OJ中不允许使用
	
	
	
	
	
	//puts  字符串输出函数  int puts(const char *s);
	char strr[100] = "www.dotcpp.com";
    printf("%s\n", strr);  
    puts(strr);  
	
	return 0;
}
