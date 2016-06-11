#include <stdio.h>
#define N 60
#define M 10
void stack(char c[i], int );
int count = 0;
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

	for (int i; c != "\n"; i++)
	{
		for (int j = M; j<=N-M || c != ' '; j++)	//j가 50초과되거나 공백문자를 입력받았을때 반복문탈출 
		{
			c[i][j] = getchar();	//정수부 받아서 10번째부터 순서대로 입력
				count++;		//정수부 자릿수 카운팅
				if(c[i][j]=='.')	//만약 마침표를 입력받았으면 소수부 배열저장
				{
					for (int j = 9; i > 0 || c != ' '; j--)
					{
						c[i][j] = getchar();
					}

		}
		stack(c, count);  //카운트이용 정수부 정상
		count = 0;  //카운트 초기화
	
	}	
	
	for (int i = 0; ; i++)
	{
		for (int j = count + M; j > 0; j--)
			printf("%c\n", c[i][j]);
	}
	



	return 0;
}

void stack(char c[i], int a) {
	char ch;
		for(int j =0; j < a; j++)
		{
		ch = c[i][a - j];
		c[i][a - j] = c[][j];
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

	
