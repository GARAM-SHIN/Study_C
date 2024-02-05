/*사용자 정의 헤더 파일을 사용하는 프로그램*/

//student.h

typedef struct    //student 구조체 선언
{
	int num;    //학번
	char name[20];    //이름
}Student;

//main.c

#include <stdio.h>    //시스템 헤더 파일의 내용 복사
#include "student.h"    //사용자 정의 헤더 파일의 내용 복사

int main(void)
{
	Studuent a = { 315, "홍길동" };    //구조체 변수 선언과 초기화

	printf("학번 : %d, 이름 : %s\n", a.num, a.name);    //구조체 멤버 출력

	return 0;
}

/*다양한 매크로명의 사용*/

#include <stdio.h>
#define PI 3.14159    //상수를 매크로명으로 정의
#define LIMIT 100.0    //상수를 매크로명으로 정의
#define MSG "passed!"    //문자열을 매크로명으로 정의
#define ERR_PRN printf("허용 범위를 벗어났습니다!\n")    //출력문을 매크로명으로 정의

int main(void)
{
	double radius, area;    //반지름과 면적 변수

	printf("반지름을 입력하세요(10 이하) : ");
	scanf("%lf", &radius);    //반지름 입력
	area = PI * radius * radius;    //면적 계산
	if (area > LIMIT)ERR_PRN;    //면적이 100을 초과하면 오류 메시지 출력
	else printf("원의 면적 : %.2lf (%s)\n", area, MSG);    //면적과 메시지 출력

	return 0;
}

/*매크로 함수를 사용한 프로그램*/

#include <stdio.h>
#define SUM(a,b) ((a)+(b))    //두 값을 더하는 매크로 함수
#define MUL(a,b) ((a)*(b))    //두 값을 곱하는 매크로 함수

int main(void)
{
	int a = 10, b = 20;
	int x = 30, y = 40;
	int res;

	printf("a + b = %d\n", SUM(a,b));    //a와 b의 합
	printf("x + y = %d\n", SUM(x, y));    //x와 y의 합
	res = 30 / MUL(2, 5);    //30을 2와 5의 곱으로 나눔
	printf("res : %d\n", res);

	return 0;
}

/*이미 정의된 매크로의 기능*/

#include <stdio.h>

void func(void);

int main(void)
{
	printf("컴파일 날짜와 시간 : %s, %s\n\n", __DATE__, __TIME__);
	printf("파일명 : %s\n", __FILE__);
	printf("함수명 : %s\n", __FUNCTION__);
	printf("행번호 : %d\n", __LINE__);

#line 100 "macro.c"    //행 번호를 100부터 시작, 파일명은 macro.c로 표시
	func();    //여기부터 행 번호는 100으로 시작

	return 0;
}

void func(void)
{
	printf("\n");
	printf("파일명 : %s\n", __FILE__);
	printf("함수명 : %s\n", __FUNCTION__);
	printf("행번호 : %d\n", __LINE__);
}

/*#과 ##을 사용한 매크로 함수*/

#include <stdio.h>
#define PRINT_EXPR(x) printf("#x = %d\n", x)
#define NAME_CAT(x,y) (x##y)

int main(void)
{
	int a1, a2;

	NAME_CAT(a, 1) = 10;    //(a1) = 10;
	NAME_CAT(a, 2) = 20;    //(a2) = 20;
	PRINT_EXPR(a1 + a2);    //printf("a1 + a2" "=%d\n",a1 + a2);
	PRINT_EXPR(a2 - a1);    //printf("a1 - a2" "=%d\n",a1 - a2);

	return 0;
}

/*#if,#ifdef,#else,#endif를 사용한 조건부 컴파일*/

#include <stdio.h>
#define VER 7    //치환될 부분이 있는 매크로명 정의
#define BIT16    //치환될 부분이 없는 매크로명 정의

int main(void)
{
	int max;

#if VER >= 6    //매크로명 VER이 6 이상이면
	printf("버전 %d입니다.\n", VER);    //이 문장 컴파일
#endif    //#if의 끝

#ifdef BIT16    //매크로명 BIT16이 정의되어 있으면
	max = 32767;    //이 문장 컴파일
#else     //BIT16이 정의되어 있지 않으면
	max = 2147483647;    //이 문장 컴파일
#endif    //#ifedf의 끝

	printf("int형 변수의 최댓값 : %d\n", max);    //max 출력
	 
	return 0;
}

/*#pragma 지시자*/

#include <stdio.h>
#pragma pack(push,1)    //바이트 얼라이먼트를 1로 바꿈
typedef struct
{
	char ch;
	int in;
}Sample1;

#pragma pack(pop)    //바꾸기 전의 바이트 얼라이먼트 적용
typedef struct
{
	char ch;
	int in;
}Sample2;

int main(void)
{
	printf("Sample1 구조체의 크기 : %d바이트\n", sizeof(Sample1));
	printf("Sample2 구조체의 크기 : %d바이트\n", sizeof(Sample2));
	
	return 0;
}

/*두 정수의 평균을 구하는 프로그램*/

//main 함수 정의 

#include <stdio.h>

void input_data(int*, int*);    //두 정수를 입력하는 함수 선언
double average(int, int);    //퍙군을 구하는 함수 선언

int main(void)
{
	int a, b;
	double avg;

	input_data(&a, &b);    //두 정수 입력
	avg = average(a, b);    //평균 계산
	printf("%d와 %d의 평균 : %.1lf\n", a, b, avg);    //입력값과 평균 출력

	return 0;
}

//sub.c : input_data,average 함수 정의

#include <stdio.h>    //printf, scanf 함수 사용을 위해 필요

void input_data(int* pa, int* pb)    //두 정수 입력 함수
{
	printf("두 정수 입력 : ");
	scanf("%d%d", pa, pb);
}

double average(int a, int b)    //평균을 구하는 함수
{
	int tot;
	double avg;

	tot = a + b;
	avg = tot / 2.0;

	return avg;
}

/*전역 변수에 extern과 static을 사용한 프로그램*/

//main.c : main, print_data 함수 정의

#include <stdio.h>

int input_data(void);    //양수를 입력하고 그 합을 반환
double average(void);    //평균을 구하는 함수
void print_data(double);    //출력 함수

int count = 0;    //입력한 양수의 수 누적
static int total = 0;    //입력한 양수의 합

int main(void)
{
	double avg;    //입력한 양수의 평균

	total = input_data();    //양수를 입력하고 그 합을 반환
	avg = average();    //평균 계산
	print_data(avg);

	return 0;
}

void print_data(double avg)
{
	printf(" 입력한 양수의 개수 : %d\n", count);
	printf(" 전체 합과 평균 : %d, %.1lf\n", total, avg);
}

//input.c : input_data 함수 정의

#include <stdio.h>

extern int count;    //main.c파일의 전역 변수 count 공유
int total = 0;    //전역 변수 선언

int input_data(void)
{
	int pos;    //양수 저장

	while (1)
	{
		printf("양수 입력 : ");
		scanf("%d", &pos);    //양수 입력
		if (pos < 0) break;    //음수면 입력 종료
		count++;    //개수 증가
		total += pos;    //입력값을 전역 변수 total에 누적
	}

	return total;    //전역 변수 total의 값 반환
}

//average.c : average 함수 정의

extern int count;    //main.c의 전역 변수 count 공유
extern int total;    //input.c의 전역 변수 total 공유

double average(void)
{
	return total / (double)count;    //입력값의 평균 반환
}

/*헤더 파일의 중복 포함 문제 해결 방법*/

//point.h : Point 구조체 선언

#ifndef _POINT_H_    //_POINT_H_ 매크로명이 정의되어 있지 않으면
#define _POINT_H_    //_POINT_H_ 매크로명 정의

typedef struct
{
	int x;    //x좌표
	int y;    //y좌표
}Point;

#endif    //#ifdef _POINT_H_의 끝

//line.h : Line 구조체 선언

#include "point.h"    //Point 구조체를 위해 포함

typedef struct
{
	Point first;    //첫 번쨰 점
	Point second;    //두 번째 점
}Line;

//main.c : Point와 Line 구조체 모두 사용

#include <stdio.h>
#include <point.h>    //Point 구조체 선언
#include <line.h>    //Line 구조체 선언

int main(void)
{
	Line a = { {1,2},{5,6} };    //Line 구조체 변수 초기화
	Point B;    //가운데 점의 좌표 저장

	b.x = (a.first.x + a.second.x / )2;    //가운데 점의 x좌표 계산
	b.y = (a.first.y + a.second.y) / 2;    //가운데 점의 y좌표 계산
	printf("선의 가운데 점의 좌표 : (%d,%d)\n", b.x, b.y);

	return 0;
}