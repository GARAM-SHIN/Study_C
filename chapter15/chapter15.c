/*포인터와 이중 포인터의 관계*/

#include <stdio.h>

int main(void)
{
	int a = 10;    //int형 변수의 선언과 초기화
	int* pi;    //포인터 선언
	int* ppi;    //이중 포인터 선언

	pi = &a;    //int형 변수의 주소를 저장한 포인터
	ppi = &pi;    //포인터의 주소를 저장한 이중 포인터

	printf("----------------------------------------\n");
	printf("변수    변숫값    &연산    *연산    **연산\n");
	printf("----------------------------------------\m");
	printf("a%10d%10u\n", a, &a);
	printf("pi%10u%10u%10d\n", pi, &pi, *pi);
	printf("ppi%10u%10u%10u%10u\n", ppi, &ppi, *ppi, **ppi);
	printf("----------------------------------------\n");

	return 0;
}

/*이중 포인터를 사용한 포인터 교환*/

#include <stdio.h>

void swap_ptr(char** ppa, char** ppb);

int main(void)
{
	char* pa = "success";
	char* pb = "failure";

	printf("ps -> %s, pb -> %s\n", pa, pb);    //바꾸기 전에 문자열 출력
	swap_ptr(&pa, &pb);    //함수 호출
	printf("pa -> %s, pb -> %s\n", pa, pb);    //바꾼 후에 문자열 출력

	return 0;
}

void swap_ptr(char** ppa, char** ppb)
{
	char* pt;

	pt = *ppa;
	*ppa = *ppb;
	*ppb = pt;
}

/*포인터 배열의 값을 출력하는 함수*/

#include <stdio.h>

void print_str(char** pps, int cnt);

int main(void)
{
	char* ptr_ary[] = { "eagle", "tiger", "lion", "squirrel" };    //초기화
	int count;    //배열 요소 수를 저장할 변수

	count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);    //배열 요소의 수 계산
	print_str(ptr_ary, count);    //배열명과 배열 요소 수를 주고 호출

	return 0;
}

void print_str(char** pps, int cnt)    //매개변수로 이중 포인터 사용
{
	int i;

	for (i = 0; i < cnt; i++)    //배열 요소 수만큼 반복
	{
		printf("%s\n", pps[i]);    //이중 포인터를 배열명처럼 사용
	}
}

/*주소로 쓰이는 배열명과 배열의 주소 비교*/

#include <stdio.h>

int main(void)
{
	int ary[5];

	printf("ary의 값 : %u\t", ary);    //주소로서의 배열명의 값
	printf("ary의 주소 : %u\n", &ary);    //베열의 주소
	printf("ary+1 : %u\t", ary + 1);
	printf("&ary+1 : %u\n", &ary + 1);

	return 0;
}

/*배열 포인터로 2차원 배열의 값 출력*/

#include <stdio.h>

int main(void)
{
	int ary[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	int(*pa)[4];    //int형 변수 4개의 배열을 가리키는 포인터 배열
	int i, j;

	pa = ary;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%5d", pa[i][j]);    //pa를 2차원 배열처럼 사용
		}
		printf("\n");
	}

	return 0;
}

/*2차원 배열의 값을 출력하는 함수*/

#include <stdio.h>

void print_ary(int(*)[4]);

int main(void)
{
	int ary[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };

	print_ary(ary);    //배열명을 인수로 주고 함수 호출
	
	return 0;
}

void print_ary(int(*pa)[4])    //매개변수는 배열 표인터
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%5d", pa[i][j]);    //pa를 2차원 배열처럼 사용
		}
		printf("\n");
	}
}

/*함수 포인터를 사용한 함수 호출*/

#include <stdio.h>

int sum(int, int);    //함수 선언

int main(void)    
{
	int (*fp)(int, int);    //함수 포인터 선언
	int res;    //반환값을 저장할 변수

	fp = sum;    //함수명을 함수 포인터에 저장
	res = fp(10, 20);    //함수 포인터로 함수 호출
	printf("result : %d\n", res);    //반환값 출력

	return 0;
}

int sum(int a, int b)    //함수 정의
{
	return (a + b);
}

/*함수 포인터로 원하는 함수를 호출하는 프로그램*/

#include <stdio.h>

void func(int (*fp)(int, int));    //함수 포인터를 매개변수로 갖는 함수
int sum(int a, int b);    //두 정수를 더하는 함수
int mul(int a, int b);    //두 정수를 곱하는 함수
int max(int a, int b);    //두 정수 중에 큰 값을 구하는 함수

int main(void)
{
	int sel;    //선택된 메뉴 번호를 저장할 변수

	printf("01 두 정수의 합\n");    //메뉴 출력
	printf("02 두 정수의 곱\n");
	printf("03 두 정수 중에서 큰 값 계산\n");
	printf("원하는 연산을 선택하세요 : ");
	scanf("%d", &sel);    //메뉴 번호 입력

	switch (sel)
	{
	case 1: func(sum); break;    //1이면 func에 덧셈 기능 추가
	case 2: func(mul); break;    //2이면 func에 곱셈 기능 추가
	case 3: func(max); break;    //3이면 func에 큰 값을 구하는 기능 추가
	}

	return 0;
}

void func(int (*fp)(int, int))
{
	int a, b;    //두 정수를 저장할 변수
	int res;    //함수의 반환값을 저장할 변수

	printf("두 정수의 값을 입력하세요 : ");    
	scanf("%d%d", &a, &b);    //두 정수 입력
	res = fp(a, b);    //함수 포인터로 가리키는 함수를 호출
	printf("결괏값은 : %d\n", res);    //반환값 출력
}

int sum(int a, int b)    //덧셈 함수
{
	return (a + b);
}

int mul(int a, int b)    //곱셈 함수
{
	return (a * b);
}

int max(int a, int b)    //큰 값을 구하는 함수
{
	if (a > b) return a;
	else return b;
}

/*void 포인터의 사용*/

#include <stdio.h>

int main(void)
{
	int a = 10;    //int형 변수
	double b = 3.5;    //double형 변수
	void* vp;    //void 포인터

	vp = &a;    //int형 변수의 주소 저장
	printf("a : %d\n", *(int*)vp);

	vp = &b;    //double형 변수의 주소 저장
	printf("b : %.1lf\n", *(double*)vp);

	return 0;
}