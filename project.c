#include <stdio.h>
#define N 60
#define M 10
void stack(char c[1000][N], int );
int count = 0, i = 0;
//	int add_function ()
//	int minus_function ()
//	int multi_function ()
//	int divide_function ()
//	int 소수점 ()
//		.을만나면 들어오고 
//	int 컴마 ()
//		stack을 해서 다시 역순으로 출력해서 stack의 k가 3의배수일때 ,찍기
//  int 우선순위 ()
//  int 변수()
//  int 자릿수()
//  int _clear ()
//  int _load()
//  int _save()
//  int _end()
//  int _var()
//  int _error()



int main () {
	char c[1000][N]={0};
	printf("최강플젝 최강호 \n");
	printf("민석, 한다, 커밋 \n");
	printf("Start...\n");

	for (i; c != "\n"; i++)
	{
		for (int j = 10; c != '.' || c != ' '; j++)
		{
			c[i][j] = getchar();
				count++;
		}
		stack(c, count);
		count = 0;
	
		for (int j = 9; c != ' '; j--)
		{
			c[i][j] = getchar();
		}
	}	
	
	for (int i = 0; ; i++)
	{
		for (int j = count + M; j > 0; j--)
			printf("%c\n", c[i][j]);
	}
	i=0;



	return 0;
}

void stack(char c[1000][N], int a) {
	char ch;
		for(int j =0; j < a; j++)
		{
		ch = c[i][a - j];
		c[i][a - j] = c[i][j];
		c[i][j] = ch;
		}
	
	return;
}



//int add_function (){
//	char num1[N]={0};
//	char num2[N]={0};
//	char num3[N+1]={0};


//	for (i=1 ; i<=N ; i++)
//	{
//		num3[i] = num1[i]+num2[i];
//		if(num3[i]>10) // 더했을때 10보다큰경우
//		{
//			num3[i]-=10;
//			num3[i+1]+=1;
//		}
//	}
//}

//int 자릿수 () {

	
