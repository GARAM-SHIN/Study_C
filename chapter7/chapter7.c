/*2개의 함수로 만든 프로그램*/

#include <stdio.h>

int sum(int x, int y);    //sum 함수 선언 

int main(void)    //main 함수 시작
{
	int a = 10, b = 20;
	int result;    //두 정수를 더한 결과(result)를 저장할 변수

	result = sum(a, b);    //sum 함수 선언
	printf("result : %d\n", result);

	return 0;
}    //main 함수의 끝

int sum(int x, int y)    //sum 함수 정의 시작
{
	int temp;    //두 정수의 합을 잠시 저장할 변수

	temp = x + y;    //x와 y의 합을 temp에 보관

	return temp;    //temp의 값을 변환
}    //sum 함수의 끝

/*매개변수가 없는 함수*/

#include <stdio.h>

int get_num(void);    //함수 선언

int main(void)
{
	int result;

	result = get_num();    //함수 호출, 반환값은 result에 저장
	printf("반환값 : %d\n", result);    //반환값 출력
	return 0;
}

int get_num(void)    //매개변수가 없고 반환형만 있음
{
	int num;    //키보드 입력값을 저장할 변수

	printf("양수 입력 : ");    //입력 안내 메시지
	scanf_s("%d", &num);    //키보드 입력

	return num;    //입력할 값 변환
}

/*반환값이 없는 함수*/

#include <stdio.h>

void print_char(char ch, int count);    //함수 선언

int main(void)
{
	print_char('@', 5);    //문자와 숫자를 주고 함수 호출
	
	return 0;
}

void print_char(char ch, int count)    //매개변수는 있으나 반환형은 없음
{
	int i;

	for (i = 0; i < count; i++)    //i는 0부터 count-1까지 증가, count번 반복
	{
		printf("%c", ch);    //매개변수 ch에 받은 문자 출력
	}

	return;
}

/*반환값과 매개변수가 모두 없는 함수*/

#include <stdio.h>

void print_line(void);    //함수 선언

int main(void)
{
	print_line();    //함수 호출
	printf("학번     이름     전공     학점\n");
	print_line();    //함수 호출

	return 0;
}

void print_line(void)
{
	int i;

	for (i = 0; i < 50; i++)    //50번 반복하여 '-' 출력
	{
		printf("-");
	}
	printf("\n");
}

/*재귀호출 함수*/

#include <stdio.h>

void fruit(void);    //함수 선언

int main(void)
{
	fruit();    //함수 호출

	return 0;
}

void fruit(void)    //재귀호출 함수 정의
{
	printf("apple\n");
	fruit();    //자신을 다시 호출
}

/*3번 실행되는 재귀호출 함수*/

#include <stdio.h>

void fruit(int count);

int main(void)
{
	fruit(1);    //처음 호출하므로 1을 인수로 줌

	return 0;
}

void fruit(int count)    //호출 횟수를 매개변수에 저장
{
	printf("apple\n");
	if (count == 3) return;    //호출 횟수가 3이면 반환하고 끝냄
	fruit(count + 1);    //재호출할 때 호출 횟수를 1 증가
}

/*3번 실행되는 재귀호출 함수2*/

#include <stdio.h>

void fruit(int count);

int main(void)
{
	fruit(1);    //처음 호출하므로 1을 인수로 줌

	return 0;
}

void fruit(int count)    //호출 횟술르 매개변수에 저장
{
	printf("apple\n");
	if (count == 3)return;    //호출 횟수가 3이면 반환하고 끝냄
	fruit(count + 1);    //재호출할 때 호출 횟수를 1 증가
	printf("jam\n");
}