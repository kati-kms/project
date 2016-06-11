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
	void priority(char num[][N], char op[], int i); // 우선순위 정할때 숫자랑 연산자랑 넘기고 현재 숫자가몇갠지(i)도 넘겨준다.
//  int 변수()
	int cipher_save_stack_integers(int c, char stack[N], int i, int var_flag); //stack에 저장해둔다. ( ' ' 전까지 space바 전까지)
    int cipher_save_num_integers(char num[][N], char stack[N], int count, int i); // count를 매개변수로 자릿수 함수만든다. num변수에 넣어줄때마다 호출?
	int cipher_save_num_decimal_places(int c, char num[][N], int i, int var_flag); // num i번쨰 [N]을 받아서 (숫자한줄)  소수부분을 넣는다.
	int cipher_save_op(int c, char op[]); // 연산자를 저장한다. // char op는 호출할때 원소 하나만 하니까 배열로안해도됌
//  int _clear ()
//  int _load() // 이런 명령들은 문자열비교 이용??
//  int _save()
//  int _end()
//  int _var()
//  int _error()
	int _order(char order[],int c);
	int order_check(char order[]);



int main () {
	int c;
	printf("최강플젝 강승호 \n");
	printf("민석, 한다, 커밋 \n");
	
	int i = 0;
	int v = 0;
//	int j;
	char num[10][N] = { 0 }; // 연산가능한 숫자가 i(1000)개
	char op[10] = { 0 }; // 연산가능한 연산자도 i(1000)개
	char order[6] = { 0 }; //변수 이름,명령어 저장배열
	char vnum[10][N] = { 0 }; //변수에 해당하는 숫자저장을 위한 배열
	char vname[10] = { 0 }; //변수의 이름을 저장하는배열

	char stack[N] = { 0 }; // 자리수를 맞추기위한 stack 배열
	int cipher_count[]={0}; // count가 최고일때 즉 자릿수 저장
	int count=0; // 자릿수  count 하는거 (return값 저장)
	int point_flag=0; //소수점확인
	int space_flag=0; // space바 확인
	int var_flag = 0; // 변수 확인
	int error = 0; //error 확인

	printf("Start...\n");

	//while (1)
	

		printf("(Input) : ");

		while ((c = getchar()) != '\n')//엔터키 전까지 다 넣기
		{
			if (order[1] == ' '&&order[2] == '='&&order[3] == ' ') //변수를 입력 받았으면
			{
				var_flag++;  //함수내에서 변수를위한 배열에 따로 저장하기 위한것
				vname[v++]=order[0];
				continue;
			}
			else if(c != ' ')//숫자,연산자  경계   마다 끊기 (숫자 / 연산자 )
			{
				if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') //문자나 공백문자일 경우
				{
					_order(order, c); //변수이름 저장
				}
				else if (c >= '0'&&c <= '9') // 숫자일경우
				{
					if (point_flag) //소수점이 존재했다면 이쪽으로 들어와서   소수첫째자리부터 시작
					{
						cipher_save_num_decimal_places(c, num, i, var_flag);   // 소수부분
					}
					else
						count = cipher_save_stack_integers(c, stack, i, var_flag);// 우선은stack에넣고 count를 리턴하여 stop_count에 넣음 // 검토사항 count변수 나눌까??
				}
				else if (c == '.') //소수점 받았을경우
				{
					point_flag++; //한배열에 2개 이상 받았을경우 오류표시
					//	continue;
				}
				else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') // 연산자일 경우
				{
					cipher_save_op(c, op);  // op의 i번째 원소만 전달하고 싶었지만 실패 다 전달
				}
				else
					error = 1;//if(error==1){ printf("= error"); }
			}
			else //c==' '
			{
				_order(order, c); //공백문자도 저장
				if (var_flag == 1 || order[0]==0) //공백전에 문자를 입력받지 않았으면
				{
					printf("%d\n", count);
					cipher_count[i] = count + 1; // 자릿수 저장
					if (space_flag == 0)
					{
						if (var_flag == 1)
							cipher_save_num_integers(vnum, stack, count, i);
						else
							cipher_save_num_integers(num, stack, count, i); //stack부분  정수부분  넣기 //숫자의 경우 소수점이 없는애들이 끝나는시점이니까 stack을 num에 넣어야하나요?
					}
					space_flag++;
					if (space_flag == 2) // 숫자도 입력됬고 연산자도 입력됬을테니까 num의 i를 1높여야함
					{
						++i;
						space_flag = 0;// 다시 0으로
					}
					point_flag = 0; // 소수점초기화
					count = 0; // 자릿수 초기화
				}
			}
		}
		if (order[0] != 0)  //첫번째 문자를 입력받았으면
		{
			order_check(order); //입력받은문자 확인
		}

		//}
	if(var_flag==1) //변수를 입력받았을때
		cipher_save_num_integers(vnum, stack, count, i);
	else
		cipher_save_num_integers(num,stack,count,i); //stack부분  정수부분  넣기 //숫자의 경우 소수점이 없는애들이 끝나는시점이니까 stack을 num에 넣어야하나요?

	printf("스택 출력\n");
	for(int j=0 ; j<N ; j++)
		printf("%d : %c\n",j,stack[j]);

	printf("1번째 배열 출력\n");
	for(int i=0 ; i<N ; i++)
		printf("%d : %c\n",i,num[0][i]);

	printf("2번째 배열 출력\n");
	for(int i=0 ; i<N ; i++)
		printf("%d : %c\n",i,num[1][i]);

	printf("연산자 출력\n");
	for(int i=0 ; i<10 ; i++)
		printf("%d : %c\n",i,op[i]);

	printf("명령어 출력\n");
	for (int i = 0; i < 5; i++)
		printf("%d : %c\n",i, order[i]);

	printf("변수 저장값 출력\n");
	for (int i = 0; i < N; i++)
		printf("%d : %c\n", i, vnum[i]);

	printf("변수 이름 출력\n");
	for (int i = 0; i < 10; i++)
		printf("%d : %d\n", i, vname[i]);

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cipher_save_stack_integers(int c, char stack[], int i, int var_flag) { //stack에 저장해둔다. ( ' ' 전까지 space바 전까지)
	static int k = 0, vk = 0;
	static int count = 0, vcount = 0;

	if (var_flag == 1)
	{
		if (i != vk)
		{
			vk++;
			vcount = 0;
		}
		
		stack[vcount] = c; //스택에 자릿수맞게 넣는다

		return vcount++;
	}
	else
	if(i!=k)
	{
		k++;
		count=0;
	}

	stack[count]=c; // 스택에  자릿수맞게 넣는다

	return count++; // count++값자체는 count값과 같고 다음 count를위해서 1증가;
}


int cipher_save_num_integers(char num[][N], char stack[], int count,int i) { //stack한테 자리수도 받았고,stack을 그냥 num에 넣기만하면됨   현)stack에깔끔하게 다들어가있음
//	static int i=0; // 함수에 들어올때마다 i는 계속 전역변수처럼 사용되어야 하니까

	int j=49; // num배열에 49에  1의자리숫자 부터 들어감
	while(count>=0) // 자리수에맞게끔 stack 만큼만 넣는거임
	{
		num[i][j]=stack[count];
		j--;
		count--;
	}
		for(int i=0 ; i<N ; i++)
			stack[i]=0; // stack초기화 
//	++i;
	return 0;
}


int cipher_save_num_decimal_places(int c, char num[][N],int i, int var_flag) { // num i번쨰 [N]을 받아서 (숫자한줄)  소수부분을 넣는다.
	static int k = 0, vk = 0;
	static int j = N - 10, vj = N - 10;
	if (var_flag == 1)
	{
		if (i != vk)
		{
			vk++;
			vj = N - 10;
		}
		num[i][vj++] = c;
		return 0;
	}
	else
		if(i!=k)
		{
			k++;
			j = N - 10;
		}

	num[i][j++] = c;
	return 0;
}
	

int cipher_save_op(int c,char op[]) { // 연산자를 저장한다.
	static int i=0; // 함수에 들어올때마다 i는 계속 전역변수처럼 사용되어야 하니까
	op[i]=c;
	++i; // 두번째 연산자를 위해서 i를 1증가
	return 0;
}

int _order(char order[],int c) //입력받은 문자,공백문자 저장
{
	static int i=0; //들어올때마다 전역변수처럼 사용
	order[i++]=c;
}

int order_check(char order[]) //입력받은 명령어를 확인한다.
{
	if (order[0] == 'e'&&order[1] == 'n'&&order[2] == 'd'&&order[3] == 0) //"end" 입력 받았을때
	{
		system("exit");  //프로그램 종료
	}
	else if (order[0] == 'c'&&order[1] == 'l'&&order[2] == 'e'&&order[3] == 'a'&&order[4] == 'r'&&order[5] == 0) //"clear" 입력 받았을때
	{
		system("clear");  //화면비우기
	}
	/*else if (order[1] == 0&&order[2] == 0&&order[3] == 0&&order[4] == 0&&order[5] == 0) //변수를 입력받았을때
	{
		if (변수존재)
		{
			변수 출력
		}
		else
			printf("= undefined.\n");
	}
	else if (order[0] == 'V'&&order[1] == 'A'&&order[2] == 'R'&&order[3] == 0) //"VAR" 입력 받았을때
	{
		if (변수존재)
		{
			모든변수 출력
		}
		else
			printf("정의된 변수 없음\n");
	}
	else if (order[0] == 'l'&&order[1] == 'o'&&order[2] == 'a'&&order[3] == 'd'&&order[4] == 0) //"load" 입력 받았을때
	{
		FILE *file = fopen("file.txt", "rt"); //file.txt를 텍스트형 읽기전용으로 열어 file이라는 포인터로 사용하겠다라는 듯
		fclose(file); //file포인터를 닫는다, file.txt 종료 
	}
	else if (order[0] == 's'&&order[1] == 'a'&&order[2] == 'v'&&order[3] == 'e'&&order[4] == 0) //"save" 입력 받았을때
	{
		FILE *file = fopen("file.txt", "wt"); //file.txt를 텍스트형 쓰기전용으로 열어 file이라는 포인터로 사용하겠다라는 듯

		fclose(file); //file포인터를 닫는다, file.txt 종료 
	}*/
	else
		printf("= error\n");
}

/*void priority(char num[][N], char op[], int i){ // 우선순위 정할때 숫자랑 연산자랑 넘기고 현재 숫자가몇갠지(i)도 넘겨준다.
	while
		for(
		if(op[j]
*/


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
