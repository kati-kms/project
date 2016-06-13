#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 60 // 소숫점포함 널문자 포함 61자리 (num배열에는 소수점이없으니까 60) 널문자는있지
int add_function (int i, char num[][N], char result[][1000]); // int i는 몇번째 숫자인지; 
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
    int cipher_save_num_integers(char num[][N], char stack[N], int count,int i); // count를 매개변수로 자릿수 함수만든다. num변수에 넣어줄때마다 호출?
	int cipher_save_num_decimal_places(int c, char num[][N],int i, int var_flag); // num i번쨰 [N]을 받아서 (숫자한줄)  소수부분을 넣는다.
	int cipher_save_op(int c, char op[]); // 연산자를 저장한다. // char op는 호출할때 원소 하나만 하니까 배열로안해도됌
//  int _clear ()
//  int _load() // 이런 명령들은 문자열비교 이용??
//  int _save()
//  int _end()
//  int _var()
//  int _error()
 	int _order(char order[],int c,int o);
	int order_check(char order[],char vname[],char vnum[][N],int var_flag);



int main () {
	int c;
	int i=0;
	int v=0; //변수 
	int o=0;
	int k=0;
//	int j;
	char num[10][N]; // 연산가능한 숫자가 i(1000)개
	char result[10][1000];
	char op[10]; // 연산가능한 연산자도 i(1000)개
	char order[6]={0};
	char vnum[10][N]={0}; // 변수에 해당하는 숫자저장을 위한 배열
	char vname[10]={0};

	char stack[N]; // 자리수를 맞추기위한 stack 배열
	int cipher_count[]={0}; // count가 최고일때 즉 자릿수 저장
	int count=0; // 자릿수  count 하는거 (return값 저장)
	int point_flag=0; //소수점확인
	int space_flag=0; // space바 확인
	int var_flag = 0; // 변수 확인
	int error = 0; //error확인
	
	for(int i=0 ; i<10 ; i++)
		for(int j=0 ; j<N ; j++)
			num[i][j]=0;

	for(int i=0 ; i<10 ; i++)
		op[i]=0;

	for(int i=0; i<N ; i++)
		stack[i]=0;

	printf("Start...\n");
	printf("최강플젝 강승호 \n");
	printf("민석, 한다, 커밋 \n");

	for (int z = 0; z < 10; z++) {

		printf("(Input) : ");

		while ((c = getchar()) != '\n')//엔터키 전까지 다 넣기
		{
			if (c != ' ')//숫자,연산자  경계   마다 끊기 (숫자 / 연산자 )
			{
				if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))  //문자일경우
					_order(order, c, o);
				else
				{
					if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') // 숫자일경우
					{
						if (point_flag) //소수점이 존재했다면 이쪽으로 들어와서   소수첫째자리부터 시작
						{
							if (var_flag == 1)
								cipher_save_num_decimal_places(c, vnum, v, var_flag);   // 변수의 소수부분
							else
								cipher_save_num_decimal_places(c, num, i, var_flag);   // 소수부분
						}
						else
							if (var_flag == 1)
								count = cipher_save_stack_integers(c, stack, v, var_flag);// 우선은stack에넣고 count를 리턴하여 stop_count에 넣음 // 검토사항 count변수 나눌까??
							else
								count = cipher_save_stack_integers(c, stack, i, var_flag);// 우선은stack에넣고 count를 리턴하여 stop_count에 넣음 // 검토사항 count변수 나눌까??
					}
					//			else  //나중에 변수 선언들어오면 그것도 처리해야됨 if else를  나머지는 error뜨는함수로할수있게
					if (c == '.')
					{
						point_flag++;
						//	continue;
					}
					if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') // 연산자일 경우
					{
						cipher_save_op(c, op);  // op의 i번째 원소만 전달하고 싶었지만 실패 다 전달
					}
					if (c == '=')
					{
						var_flag++;
					}
					else
						error = 1;
				}//else에 그외   변수/여러명령어들/ 등  이랑  그것마저도 else이면 error처리;
			}
			else //c==' '
			{
				printf("%d\n", count);
				cipher_count[i] = count + 1; // 자릿수 저장
				if (space_flag == 0)
				{
					if (var_flag == 1)
						cipher_save_num_integers(vnum, stack, count, v); //stack부분  정수부분  넣기 //숫자의 경우 소수점이 없는애들이 끝나는시점이니까 stack을 num에 넣어야하나요?
					else
						cipher_save_num_integers(num, stack, count, i); //stack부분  정수부분  넣기 //숫자의 경우 소수점이 없는애들이 끝나는시점이니까 stack을 num에 넣어야하나요?
				}
				space_flag++;
				if (space_flag == 2) // 숫자도 입력됬고 연산자도 입력됬을테니까 num의 i를 1높여야함
				{
					++i;
					if (var_flag == 1)
						--i;
					space_flag = 0;// 다시 0으로
				}
				point_flag = 0; // 소수점초기화
				count = 0; // 자릿수 초기화
			}
		} //while (\n) 끝

	//	printf("%d\n",var_flag);
		if (var_flag == 1)
		{
			cipher_save_num_integers(vnum, stack, count, v); //vnum에 숫자입력받음
			vname[v] = order[0]; // 변수이름 따로 저장

			var_flag = 0; // 다시 변수를 받기 위해 초기화
			if (v < 10) //입력받은 변수가 10개 미만
				v++;
			else
				printf("변수는 10개까지 받을 수 있습니다.\n");
		}
		else
			cipher_save_num_integers(num, stack, count, i); //stack부분  정수부분  넣기 //숫자의 경우 소수점이 없는애들이 끝나는시점이니까 stack을 num에 넣어야하나요?


		if (order[0] != 0) //문자를 입력받았으면
		{
			order_check(order, vname, vnum, var_flag);
		}

		//	for (int z = 0; z < 6; z++)
		//		printf("order[%d] = %c\n", z, order[z]);

			///////////////////////////////////////////////////////////////////////////////////////////////////
		for (int i = 0; i < 6; i++) //명령어 재입력 위해 초기화
			order[i] = 0;

		o = 1;               //명령어 재입력 위해 초기화
		_order(order, c, o);
		o = 0;
		///////////////////////////////////////////////////////////////////////////////////////////////////

		  //if(error==1)
		  //	printf("(error)\n");
	  //for end

	//	priority(num,op,i);

	/*	for (int j = 0; j < N; j++)
			printf("stack %d : %c\n", j, stack[j]);

		for (int i = 0; i < N; i++)
			printf("num1 %d : %c\n", i, num[0][i]);

		for (int i = 0; i < N; i++)
			printf("num2 %d : %c\n", i, num[1][i]);

		for (int i = 0; i < 10; i++)
			printf("op %d : %c\n", i, op[i]);

		printf("명령어 출력\n");
		for (int i = 0; i < 10; i++)
			printf("%d : %c\n", i, order[i]);

		printf("변수 저장값 출력\n");
		for (int i = 0; i < N; i++)
			printf("%d : %c\n", i, vnum[0][i]);

		printf("변수 저장값 출력\n");
		for (int i = 0; i < N; i++)
			printf("%d : %c\n", i, vnum[1][i]);

		printf("변수 저장값 출력\n");
		for (int i = 0; i < N; i++)
			printf("%d : %c\n", i, vnum[2][i]);

		printf("변수 이름 출력\n");
		for (int i = 0; i < 10; i++)
			printf("%d : %c\n", i, vname[i]);*/

		//printf("var_flag = %d", var_flag);
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cipher_save_stack_integers(int c, char stack[], int i, int var_flag) { //stack에 저장해둔다. ( ' ' 전까지 space바 전까지)
	static int k=0, vk=0;
	static int count=0, vcount=0;

	if(var_flag == 1)
	{
		if(i != vk)
		{
			vk++;
			vcount = 0;
		}

		stack[vcount]=c; // 스택에 자릿수맞게 넣는다

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
//	 tatic int i=0; // 함수에 들어올때마다 i는 계속 전역변수처럼 사용되어야 하니까
//	 rder[

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


int cipher_save_num_decimal_places(int c, char num[][N],int i, int var_flag) { // num i번쨰 [N]을 받아서 (숫자한줄)  소수부분을 넣는다.
	static int k=0 ,vk=0;
	static int j=N-10, vj=N-10;

	if(var_flag==1)
	{
		if(i!=vk)
		{
			vk++;
			vj=N-10;
		}
		num[i][vj++]=c; // 이거가능? 첫번째 꺼 비우면 위에서입력받는 num[i][j]로 인식이 되나?????????????
		return 0;
	}
	else
		if(i!=k)
		{
		    k++;
			j=N-10;
		}
	num[i][j++]=c;
	return 0;
}
	

int cipher_save_op(int c,char op[]) { // 연산자를 저장한다.
	static int i=0; // 함수에 들어올때마다 i는 계속 전역변수처럼 사용되어야 하니까
	op[i]=c;
	++i; // 두번째 연산자를 위해서 i를 1증가
	return 0;
}

int _order(char order[], int c, int o) {
	static int k=0;
	///////////////////////////////////////////////////////////////////////////////////////////////////
	if (o==1) //o가 1이면 다시 받기위해 k값을초기화
	{
		k = 0;
		return o;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////
	order[k++]=c;
}

int order_check(char order[],char vname[],char vnum[][N],int var_flag) {
	int ch;
	if(order[0] =='e' && order[1]=='n' && order[2]=='d' && order[3]==0)  //end 입력받으면
	{
		printf("프로그램을 종료합니다.\n");
		system("exit");
	}
	else if(order[0]=='c' && order[1]=='l' && order[2]=='e' && order[3]=='a' && order[4]=='r' && order[5]==0) //clear 입력받으면
	{
		system("clear");
	}
	else if(var_flag)  //변수를 입력받으면
	{
		int i=0;
		int a = 0;
		printf("= ");
		for(i;i<10;i++)
		{
			if(vname[i]!=order[0])
				continue;
			if(vname[i]==order[0])
			{
				for(int j=0;j<N;j++)
				{
					printf("%c",vnum[i][j]);
				}
				a = 1;
				break;
			}
		}
		if (a = 0) //저장된변수에 입력된변수의 이름이없으면
		{
			printf("undifined"); //오류메세지 출력
		}
		printf("\n");
	}
	else if(order[0]=='V'&&order[1]=='A'&&order[2]=='R'&&order[3]==0) //VAR입력 받으면
	{
		if(vname[0]==0&&vname[1]==0&&vname[2]==0&&vname[3]==0&&vname[4]==0&&vname[5]==0&&vname[6]==0&&vname[7]==0&&vname[8]==0&&vname[9]==0)
		{
			printf("정의된 변수 없음\n");

		}
		else
			for(int i=0;i<10;i++)
			{
				if (vname[i] != 0) //변수 존재하지 않으면 출력하지 않음
				{
					printf("%c = ", vname[i]);  //변수 = 숫자 출력
					for (int j = 0; j < N; j++)
					{
						if (j == 50)
						{
							printf(".");
						}
							printf("%c", vnum[i][j]);
					}
					printf("\n");
				}
			}
	}
	else if(order[0]=='l'&&order[1]=='o'&&order[2]=='a'&&order[3]=='d'&&order[4]==0)  //load입력 받으면
	{
		int i = 0, j = 0, k = 0;
		FILE *file=fopen("file.txt","rt"); //file.txt를 현재 디렉토리에서 텍스트전용 읽기 모드로 연다
		if (file == NULL)
			printf("저장된 변수가 없습니다.\n");
		else
		{
			while (ch = getc(file) != EOF)
			{
				if (ch == '\n') //파일입력이 계행일 경우 j를증가
				{
					j++;
					k = 0; //변수를 다시저장하기 위해 초기화
				}

				if (ch >= 'a'&&ch <= 'z' || ch >= 'A'&&ch <= 'Z') //파일입력이 문자일 경우 입력문자배열에 저장
					vname[i++] = ch;
				else
					vnum[j][k++] = ch; //숫자를 변수배열에 저장
			}
		}
		
		fclose(file);
	}
	else if (order[0] == 's'&&order[1] == 'a'&&order[2] == 'v'&&order[3] == 'e'&&order[4] == 0) //save 입력 받으면
	{
		FILE *file = fopen("file.txt", "wt"); //file.txt를 쓰기모드로 열기(없으면 새로생성)
		for (int i = 0; i < N; i++)
		{
			if (vname[i] != 0)  //현재 입력받은변수가 있다면
			{
				putc(vname[i], file); //변수이름 파일에저장
				for (int j = 0; j < N; j++)  //숫자를 파일에저장
				{
					putc(vnum[i][j], file);
				}
				putc('\n', file);  //변수를 모두 저장하면 줄바꿈(계행 저장)
			}
		}
		fclose(file); //file이 가리키는 포인터 파일 닫기
	}
	else
		//printf("= error : 잘못된문자\n");
	return 0;
}

//	연산자 우선순위

void priority (char num[][N], char op[], int i)
{
	int how_num=i;

	char result[10][1000];	//num 이랑 num 끼리 최초계산한 뒤부터 result 배열로 전부 이사간다.
	int higher_priority = 0;//높은 우선순위(*,/,%)가 하나라도 있으면 이 값은 1이 되어 그것부터 계산할 수 있도록 만든다.
	int is_first_cal = 0;	//처음 계산할 때 num과 num을 계산해야 하는데, 문제는 처음 계산 후부터는 모든 배열이 result로 옮겨지기 때문에 이 변수를 활용했다.

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 1000; j++)
			result[i][j] = 0;

	for (int i = 0; i < how_num ; i++)		//op에 저장된 연산자들을 먼저 훑어본다. 높은 우선순위 연산자가 보인다면 higher_priority 변수의 값을 1 증가시킨다.
	{
		switch (op[i])
		{
			case '*':
				higher_priority++;
				break;
			case '/':
				higher_priority++;
				break;
			case '%':
				higher_priority++;
				break;
			case '+':
				break;
			case '-':
				break;
			default:
				printf("\n############################ F A T A L  E R R O R #######################\n");
				break;
		}
		printf("op[%d] = %c\n", i, op[i]);
		printf("higher priority = %d\n", higher_priority);
	}
		printf("how_num = %d\n", how_num);

	for (int i = 0; i < how_num && is_first_cal == 0; i++)	//계산을 아직 한번도 수행하지 않았을 때
	{
		if(higher_priority >= 1)					//높은 우선순위가 존재하는가?
		{
			switch (op[i])
			{
				case '*':
					printf("asterisk\n");
					//multiply(num[i], num[i + 1]);	
					is_first_cal = 1;
					higher_priority--;
					how_num--;
					break;
				case '/':
					printf("slash\n");
					//divide(num[i], num[i + 1]);
					is_first_cal = 1;
					higher_priority--;
					how_num--;
					break;
				case '%':
					printf("percent\n");
					//mode(num[i], num[i + 1]);
					is_first_cal = 1;
					higher_priority--;
					how_num--;
					break;
				default:		//i번째 num 배열을 곧바로 result 배열로 넣고 싶어요
					for (int k = N; k > 0; k--)
						result[i][k + 940] = num[i][k];
					break;
			}
		}
		else//higher_priority == 0	//이때는 그냥 맨 처음 두놈만 계산시키고 빠져나간다. 
		{
			switch (op[i])
			{
				case '+':
					printf("plus\n");
					//addition(num[i], num[i + 1]);
					is_first_cal = 1;
					break;
				case '-':
					printf("minus\n");
					//substraction(num[i], num[i + 1]);
					is_first_cal = 1;
					break;
				default:
					printf("\n############################ F A T A L  E R R O R #######################\n");
			}
		}
		if (is_first_cal == 1) // 이미 한번 연산이 수행됌
		{
			for (int j = i + 1; j < how_num + 1; j++)		//첫번째 계산시킨 뒤에는 전부다 result로 옮겨주고 자리까지 땡겨주어야 합니다. 아! op도 땅겨버려요~!
			{
				for (int k = N; k > 0; k--)
					result[j][k + 940] = num[j + 1][k];
				op[j - 1] = op[j];
			}
			how_num -= 1;									//당근 how_num을 1 감소시켜주어야 하는것 아니겠나요
		}
		printf("is first cal 존재? : %d\n", is_first_cal);
	}

	//test
	//
	//
	for (int tst_i = 0; tst_i < 10; tst_i++)
		for (int tst_j = 0; tst_j < N; tst_j++)
			printf("result[%d][%d] = %c\n", tst_i, tst_j + 940, result[tst_i][tst_j + 940]);
	printf("how_num = %d", how_num);

	printf("\n");

	for (; how_num > 1; how_num--)						//두번째 계산 : is_first_cal == 1 이제부터는 남은 숫자 수가 1이 될때까지 반복.
	{
		while (higher_priority >= 1)
		{
			int j = 0;
			printf("higher_priority = %d", higher_priority);
			for (int i = 0; j == 0; i++)		//음... 상위 우선순위에 있는 연산자부터 모두 처리하도록 했습니다. j를 사용, 계속 값들을 초기화 시키고 정렬하도록 만들었습니다. 높은 순위의 연산자가 계산되면 이 for문을 빠져나가(j = 1) higher_priority값을 줄이고 다시 반복한다.
			{
				switch (op[i])
				{
					case '*':
						printf("Wow multiply function!!!!\n");
						//multiply(result[i], result[i + 1]);
						j = 1;
						higher_priority--;
						break;
					case '/':
						printf("Wow division function!!!!\n");
						//divide(result[i], result[i + 1]);
						j = 1;
						higher_priority--;
						break;
					case '%':
						printf("Wow modular function!!!!\n");
						//mode(result[i], result[i + 1]);
						j = 1;
						higher_priority--;
						break;
					case '+':
						printf("plus\n");
						break;
					case '-':
						printf("minus\n");
						break;
					default:
						printf("\n############################ F A T A L  E R R O R #######################\n");
						break;
				}
				if (j == 1)				//숫자들 당기기
				{
					how_num--;
					for (int k = i + 1; k < how_num + 1; k++)
					{
						for (int i = 0; i < 1000; i++)
							result[k][i] = result[k + 1][i];
						op[k - 1] = op[k];
					}
				}
			}
		}	

		//이제부터는 낮은순위연산자 계산 파트. 항상 op[0]랑 result[0], result[1]만 고려하면 되니깐(어차피 계속 초기화 할꺼잖아) for문 필요 없겠네.
		switch (op[0])
		{
			case '+':
				printf("Wow addition function~~!!!\n");
				//addition(result[0], result[1]);
				break;
			case '-':
				printf("Wow abstraction function~~~!!!\n");
				//substraction(result[0], result[1]);
				break;
			default:
				printf("\n############################ F A T A L  E R R O R #######################\n");
				break;
		}
		for (int k = 1; k < how_num; k++)
			for (int i = 0; i < 1000; i++)
				result[k][i] = result[k + 1][i]; 

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < N; j++)
			printf("result[%d][%d] = %c\n", i, j + 940, result[i][j + 940]);
	}
		return;
}


/*
		for (int i = 1; i < how_num - 1; i++)		//두번째 계산부터는 num이 아니라 result로 계산.
		{
			switch (op[i])
			{
				case '+':
					addition(result[i], result[i + 1]);
					break;
				case '-':
					substraction(result[i], result[i + 1]);
					break;
				default:
					printf("\n############################ F A T A L  E R R O R #######################\n");
					break;
			}
		}
	}
}	*/

int add_function (int i, char num[][N], char result[][1000]) { // int i는 몇번째 숫자인지; 

	char tmp[N];
	int larger_cipher;
	int smaller_cipher;
	int j,k;
	int count[2];
	int count_smaller;

	if(strlen(num[i])>strlen(num[i+1]))
	{
		strcpy(tmp,num[i]);    // 큰숫자를 앞으로 두고 작은 숫자를 뒤에다 둔다 // 더하기에선 의미가 크지않지만 다른계산에선 필요할듯
		strcpy(num[i],num[i+1]);
		strcpy(num[i+1],tmp);
	}

// 배열안에 개행숫자 세보기
		for(int j=i ; j<=i+1 ; j++)
		{
			for(int k=1000 ; ; k--)
			{
				if(num[j][k]!='\0')
					count[j]++;
				else
					break;
			}
		}
		count_smaller=(count[i] < count[i+1]) ? count[i] : count[i+1]; 
			
		larger_cipher=N-count_smaller-strlen(num[i])-1; // 전체길이 - 소수빈부분 - 숫자길이 - 널문자한개 =  배열에 있는 숫자들 시작점?
		smaller_cipher=N-count_smaller-strlen(num[i+1])-1;; // 자리수 작은걸 cipher에 넣음

//두 문자열들을 숫자로 변환   (자리수가 작은쪽 까지 만큼만)
for(int j=i ; j<=j+1 ; j++)
	for(k=N-count_smaller ; k>=larger_cipher ; k--)
		num[j][k]-='0';               
//계산
	for(j=smaller_cipher ; j>=larger_cipher ; j--)
	{
		result[i][j] = num[i][j]+num[i+1][j];
		if(result[i][j]>10) // 더했을때 10보다큰경우
		{
			result[i][j]-=10;
			result[i][j+1]+=1;
		}
	}
//숫자들을 다시 문자로
for(int j=i ; j<=j+1 ; j++)
	for(k=N-count_smaller ; k>=larger_cipher ; k--)
		num[j][k]+='0';               

	return 0;
}

