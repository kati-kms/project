#include <stdio.h>
#define N 60 // 소숫점포함 널문자 포함 61자리
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
    int cipher(int num[][N], int stack[N], int count); // count를 매개변수로 자릿수 함수만든다. num변수에 넣어줄때마다 호출?
//  int _clear ()
//  int _load()
//  int _save()
//  int _end()
//  int _var()
//  int _error()



int main () {
	char c;
	printf("최강플젝 강승호 \n");
	printf("민석, 한다, 커밋 \n");
	
	int i=0;
	int j;
	char num[10][N]={0}; // 연산가능한 숫자가 i(1000)개
	char op[10]={0}; // 연산가능한 연산자도 i(1000)개
	char stack[N];
	int count=0,stop_count=0; // 자릿수  count 하는거랑 , 그 카운트를 저장하는 용도

	printf("(Input) : ");

	while((c=getchar())!='\n')//엔터키 전까지 다 넣기
	{
		while(c!=' ')//숫자,연산자  경계   마다 끊기 (숫자 / 연산자 )
		{
			if(c=='+'||c=='-'||c=='*'||c=='/'||c=='%') // 연산자일 경우
			{
				op[i]=c;
				i++; // 두번째 숫자와 연산자를 위해서 i를 1증가
				break;
			}
			stack[count]=c; // 스택에  자릿수맞게 넣는다
			count++;
			if(c=='.')
			{
				stop_count=count;
				count=0; // 0으로 다시 초기화
				//break;
				while(stop_count>=0) // 자리수에맞게끔 stack 만큼만 넣는거임
				{
					j=49; // num배열에 49에  1의자리숫자 부터 들어감
					num[i][j]=stack[stop_count];
					for(int i=0 ; i<N ; i++)
						stack[i]=0; // stack초기화 
					j--;
					stop_count--;
				}
				while(
			}
		}
	}

//	for(int i=0 ; i<N ; i++)
//		printf("%c",num[0][i]);



	printf("Start...\n");
	
	return 0;
}


int add_function () {
	char num1[N]={0};
	char num2[N]={0};
	char num3[N+1]={0};
	int i;

	for (i=1 ; i<=N ; i++)
	{
		num3[i] = num1[i]+num2[i];
		if(num3[i]>10) // 더했을때 10보다큰경우
		{
			num3[i]-=10;
			num3[i+1]+=1;
		}
	}
}
/*
int cipher () {
*/	
