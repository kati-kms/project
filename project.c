#include <stdio.h>
#define N 60 // 소숫점포함 널문자 포함 61자리 (num배열에는 소수점이없으니까 60) 널문자는있지
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
	int cipher_save_stack_integers(int c, int stack[N],count); //stack에 저장해둔다. ( ' ' 전까지 space바 전까지)
    int cipher_save_num_integers(int c, int num[][N], int stack[N], int count); // count를 매개변수로 자릿수 함수만든다. num변수에 넣어줄때마다 호출?
	int cipher_save_op(int c, char op); // 연산자를 저장한다. // char op는 호출할때 원소 하나만 하니까 배열로안해도됌
//  int _clear ()
//  int _load() // 이런 명령들은 문자열비교 이용??
//  int _save()
//  int _end()
//  int _var()
//  int _error()



int main () {
	int c;
	printf("최강플젝 강승호 \n");
	printf("민석, 한다, 커밋 \n");
	
	int i=0;
	int j;
	char num[10][N]={0}; // 연산가능한 숫자가 i(1000)개
	char op[10]={0}; // 연산가능한 연산자도 i(1000)개
	char stack[N]={0}; // 자리수를 맞추기위한 stack 배열
	int count=0,stop_count=0; // 자릿수  count 하는거랑 , 그 카운트를 저장하는 용도
	int point_flag=0; //소수점확인

	printf("Start...\n");

//while(end) {

	printf("(Input) : ");

	while((c=getchar())!='\n')//엔터키 전까지 다 넣기
	{
		if(c!=' ')//숫자,연산자  경계   마다 끊기 (숫자 / 연산자 )
		{
			if(c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0') // 숫자일경우
			{
				if(point_flag) //소수점이 존재했다면 이쪽으로 들어와서  소수첫째자리부터 시작
				{
					j=50;
					num[i][j]=c;
					j++;
				}

				cipher_save_stack_integers(c,stack,/*count*/);// 우선은stack에넣고 나중에 소수점이나 ' ' 나왔을때 끊고 num배열에 집어넣는다.

			}
			else  //나중에 변수 선언들어오면 그것도 처리해야됨 if else를  나머지는 error뜨는함수로할수있게
			{
				if(c=='.')
				{
					point_flag=1;
					continue;
				}
				if(c=='+'||c=='-'||c=='*'||c=='/'||c=='%') // 연산자일 경우
				{
					cipher_save_op(c,op);  // op의 i번째 원소만 전달하고 싶다. //일차원배열은 크기 생략가능
				}
	

/*	count=0;
 *	static int i=0;
 *
 *				stack[count]=c; // 스택에  자릿수맞게 넣는다
				count++;
					if(c=='.')
					{
					stop_count=count;
					count=0; // 0으로 다시 초기화
						while(stop_count>=0) // 자리수에맞게끔 stack 만큼만 넣는거임
						{
							j=49; // num배열에 49에  1의자리숫자 부터 들어감
							num[i][j]=stack[stop_count];
							for(int i=0 ; i<N ; i++)
								stack[i]=0; // stack초기화 
							j--;
							stop_count--;
						}
					}*/
			}

		}
		else //c==' '
		{
		//	숫자의 경우 소수점이 없는애들이 끝나는시점이니까 stack을 num에 넣어야하나요?
		point_flag=0; // 소수점초기화
		j=0; // j도 초기화 (소수점넣을때 제어변수)
			continue;
		}
	}

	for(int i=0 ; i<N ; i++)
		printf("%c",num[0][i]);



	
	return 0;
}

int cipher_save_stack_integers(int c, int stack[N],count) { //stack에 저장해둔다. ( ' ' 전까지 space바 전까지)
	static int i=0;
	static int count=0; //함수 들어올때마다 count는 유지되어야만한다.

	stack[count]=c;
	count++;



int cipher_save_num_integers(int c, int num[][N], int stack[N], int count) { // count를 매개변수로 자릿수 함수만든다. num변수에 넣어줄때마다 호출?
	static int i=0; // 함수에 들어올때마다 i는 계속 전역변수처럼 사용되어야 하니까
	int count=0;
	int stop_count=0;
	
			stack[count]=c; // 스택에  자릿수맞게 넣는다
			count++;
				if(c=='.')
				{
					stop_count=count;
					count=0; // 0으로 다시 초기화
					while(stop_count>=0) // 자리수에맞게끔 stack 만큼만 넣는거임
					{
						j=49; // num배열에 49에  1의자리숫자 부터 들어감
						num[i][j]=stack[stop_count];
						for(int i=0 ; i<N ; i++)
							stack[i]=0; // stack초기화 
						j--;
						stop_count--;
					}
				}
				소숫점이없어도 실행되야되니까 함수로만들어서 다시호출시켜라


				return 0;
			}
/*
int cipher_save_num_decimal_places(int c, int num[][N], int stack[N], int count) { // count를 매개변수로 자릿수 함수만든다. num변수에 넣어줄때마다 호출?
	int i;
	int j;
	for(j=50 ; j<60 ; j++)
		num[i][j]=c;
	return 0;
}
*/	

int cipher_save_op(int c,char op) { // 연산자를 저장한다.
	static int i=0; // 함수에 들어올때마다 i는 계속 전역변수처럼 사용되어야 하니까
	char op[i]=c;
	++i; // 두번째 연산자를 위해서 i를 1증가
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
