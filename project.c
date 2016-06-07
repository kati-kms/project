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
	int cipher_save_stack_integers(int c, char stack[N], int i); //stack에 저장해둔다. ( ' ' 전까지 space바 전까지)
    int cipher_save_num_integers(char num[][N], char stack[N], int count,int i); // count를 매개변수로 자릿수 함수만든다. num변수에 넣어줄때마다 호출?
	int cipher_save_num_decimal_places(int c, char num[][N],int i); // num i번쨰 [N]을 받아서 (숫자한줄)  소수부분을 넣는다.
	int cipher_save_op(int c, char op[]); // 연산자를 저장한다. // char op는 호출할때 원소 하나만 하니까 배열로안해도됌
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
//	int j;
	char num[10][N]; // 연산가능한 숫자가 i(1000)개
	char op[10]; // 연산가능한 연산자도 i(1000)개
	char stack[N]; // 자리수를 맞추기위한 stack 배열
	int count=1; // 자릿수  count 하는거 (return값 저장)
	int point_flag=0; //소수점확인
	int space_flag=0; // space바 확인
	
	for(int i=0 ; i<10 ; i++)
		for(int j=0 ; j<N ; j++)
			num[i][j]=0;

	for(int i=0 ; i<10 ; i++)
		op[i]=0;

	for(int i=0; i<N ; i++)
		stack[i]=0;

	printf("Start...\n");

//while(end) {

	printf("(Input) : ");

	while((c=getchar())!='\n')//엔터키 전까지 다 넣기
	{
		if(c!=' ')//숫자,연산자  경계   마다 끊기 (숫자 / 연산자 )
		{
			if(c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0') // 숫자일경우
			{
				if(point_flag) //소수점이 존재했다면 이쪽으로 들어와서   소수첫째자리부터 시작
				{
					cipher_save_num_decimal_places(c,num,i);   // 소수부분
				}
				else
					count=cipher_save_stack_integers(c,stack,i);// 우선은stack에넣고 count를 리턴하여 stop_count에 넣음 // 검토사항 count변수 나눌까??
				printf("count = %d\n", count);
			}
			else  //나중에 변수 선언들어오면 그것도 처리해야됨 if else를  나머지는 error뜨는함수로할수있게
			{
				if(c=='.')
				{
					point_flag=1;
				//	continue;
				}
				else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='%') // 연산자일 경우
				{
					cipher_save_op(c,op);  // op의 i번째 원소만 전달하고 싶었지만 실패 다 전달
				}
				else
				{
					printf("error\n");
					return 0;
				}
			}//else에 그외   변수/여러명령어들/ 등  이랑  그것마저도 else이면 error처리;
		}
		else //c==' '
		{
			if(space_flag==0)
				cipher_save_num_integers(num,stack,count,i); //stack부분  정수부분  넣기 //숫자의 경우 소수점이 없는애들이 끝나는시점이니까 stack을 num에 넣어야하나요?
			space_flag++;
			if(space_flag==2) // 숫자도 입력됬고 연산자도 입력됬을테니까 num의 i를 1높여야함
			{
				++i;
				space_flag=0;// 다시 0으로
				printf("\n");
			}
			point_flag=0; // 소수점초기화
		}
	}
		cipher_save_num_integers(num,stack,count,i); //stack부분  정수부분  넣기 //숫자의 경우 소수점이 없는애들이 끝나는시점이니까 stack을 num에 넣어야하나요?
	for(int j=0 ; j<N ; j++)
		printf("%d : %c\n",j,stack[j]);

	for (int m = 0; m <= i; m++)
		for (int j = 0; j < N; j++)
			printf("num[%2d][%2d] : %c\n", m, j, num[m][j]);

	for(int i=0 ; i<10 ; i++)
		printf("%d : %c\n",i,op[i]);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cipher_save_stack_integers(int c, char stack[], int i) { //stack에 저장해둔다. ( ' ' 전까지 space바 전까지)
	static int k=0;
	static int count=1;
	if(i!=k)		//다음 숫자를 입력 받고자 할 때 count값을 1로 초기화 시키고 다시 다음 i까지 대기한다.
	{
		k++;
		count=1;
	}

	stack[count]=c; // 스택에  자릿수맞게 넣는다

	return count++; // count++값자체는 count값과 같고 다음 count를위해서 1증가;
}


int cipher_save_num_integers(char num[][N], char stack[], int count,int i) { //stack한테 자리수도 받았고,stack을 그냥 num에 넣기만하면됨   현)stack에깔끔하게 다들어가있음
//	static int i=0; // 함수에 들어올때마다 i는 계속 전역변수처럼 사용되어야 하니까

	int j=49; // num배열에 49에  1의자리숫자 부터 들어감
	while(count>=0) // 자리수에맞게끔 stack 만큼만 넣는거임
	{
		num[i][j]=stack[count]; // 이거가능? 첫번째 꺼 비우면 위에서입력받는 num[i][j]로 인식이되나?????????????????????????????????????????????
		j--;
		count--;
	}
		for(int i=0 ; i<N ; i++)
			stack[i]=0; // stack초기화 
//	++i;
	return 0;
}


int cipher_save_num_decimal_places(int c, char num[][N],int i) { // num i번쨰 [N]을 받아서 (숫자한줄)  소수부분을 넣는다.
	static int k=0;
	static int j=50;
		if(i!=k)
		{
			k++;
			j=50;
		}
		num[i][j]=c; // 이거가능? 첫번째 꺼 비우면 위에서입력받는 num[i][j]로 인식이 되나?????????????
		++j;
	return 0;
}
	

int cipher_save_op(int c,char op[]) { // 연산자를 저장한다.
	static int i=0; // 함수에 들어올때마다 i는 계속 전역변수처럼 사용되어야 하니까
	op[i]=c;
	++i; // 두번째 연산자를 위해서 i를 1증가
	return 0;
}

/*
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
	return 0;
}*/
