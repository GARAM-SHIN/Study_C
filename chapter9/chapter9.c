/*변수의 메모리 주소 확인*/

#include <stdio.h>

int main(void)
{
	int a;    //int형 변수 선언
	double b;    //double형 변수 선언
	char c;    //chat형 변수 선언

	printf("int형 변수의 주소 : %u\n", &a);    //주소 연산자로 주소 계산
	printf("double형 변수의 주소 : %u\n", &b);
	printf("char형 변수의 주소 : %u\n", &c);

	return 0;
}

/*포인터 선언과 사용*/

#include <stdio.h>

int main(void)
{
	int a;    //일반 변수 선언
	int* *pa;    //포인터 선언

	pa = &a;    //포인터에 a의 주소 대입
	*pa = 10;    //포인터로 변수 a에 10 대입

	printf("포인터로 a 값 출력 : %d\n", *pa);
	printf("변수명으로 a 값 출력 : %d\n", a);    //변수 a 값 출력

	return 0;
}

/*포인터를 사용한 두 정수의 합과 평균 계산*/

#include <stdio.h>

int main(void)
{
	int a = 10, b = 15, total;    //변수 선언과 초기화
	double avg;    //평균을 저장할 변수
	int* pa, * pb;    //포인터 동시 선언 
	int* pt = &total;    //포인터 선언과 초기화
	double* pg = &avg;    //double형 포인터 선언과 초기화

	pa = &a;    //포인터 pa에 변수 a의 주소 대입
	pb = &b;    //포인터 pb에 변수 b의 주소 대입

	*pt = *pa + *pb;    //a 값과 b 값을 더해 total에 저장
	*pg = *pt / 2.0;    //total 값을 2로 나눈 값을 avg에 저장

	printf("두 정수의 값 : %d, %d\n", *pa, *pb);    //a 값과 b값 출력
	printf("두 정수의 합 : %d\n", *pt);    //total 값 출력
	printf("두 정수의 평균 : %.1lf\n", *pg);    //avg 값 출력

	return 0;
}

/*포인터에 const 사용*/

#include <stdio.h>

int main(void)
{
	int a = 10, b = 20;
	const int* pa = &a;    //포인터 pa는 변수 a를 가리킨다.

	printf("변수 a 값 : %d\n", *pa);    //포인터 간접 참조하여 a 출력
	pa = &b;    //포인터가 변수 b를 가리키게 함
	printf("변수 b 값 : %d\n", *pa);    //포인터를 간접 참조하여 b 값 출력
	pa = &a;    //포인터가 다시 변수 a를 가리킨다.
	a = 20;    //a를 직접 참조하여 값을 바꿈
	printf("변수 a 값 : %d\n", *pa);    //포인터로 간접 참조하여 바뀐 값 참조

	return 0;
}

/*주소와 포인터 크기*/

#include <stdio.h>

int main(void)
{
	char ch;
	int in;
	double db;

	char* pc = &ch;
	int* pi = &in;
	double* pd = &db;

	printf("char형 변수의 주소 크기 : %d\n", sizeof(&ch));
	printf("int형 변수의 주소 크기 : %d\n", sizeof(&in));
	printf("double형 변수의 주소 크기 : %d\n", sizeof(&db));

	printf("char * 포인터의 크기 : %d\n", sizeof(pc));
	printf("int * 포인터의 크기 : %d\n", sizeof(pi));
	printf("double * 포인터의 크기 : %d\n", sizeof(pd));

	printf("char * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pc));
	printf("int * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pi));
	printf("double * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pd));

	return 0;
}

/*허용되지 않는 포인터의 대입*/

#include <stdio.h>

int main(void)
{
	int a = 10;    //변수 선언과 초기화
	int* p = &a;    //포인터 선언과 동시에 a를 가리키도록 초기화
	double* pd;    //double형 변수를 가리키는 포인터

	pd = p;    //포인터 p 값을 포인터 pd에 대입
	printf("%lf\n", *pd);    //pd가 가리키는 변수의 값 출력

	return 0;
}

/*포인터를 사용한 두 변수의 값 교환*/

#include <stdio.h>

void swap(int* pa, int* pb);    //두 변수의 값을 바꾸는 함수의 선언

int main(void)
{
	int a = 10, b = 20;    //변수 선언과 초기화

	swap(&a, &b);    //a.b의 주소를 인수로 두고 함수 호출
	printf("a:%d, b:%d\n", a, b);    //변수 a, b 출력

	return 0;
}

void swap(int* pa, int* pb)    //매개변수로 포인터 선언
{
	int temp;    //교환을 위한 임시 변수

	temp = *pa;    //temp에 pa가 가리키는 변수의 값 저장
	*pa = *pb;    //pa가 가리키는 변수에 pb가 가리키는 변수의 값 저장
	*pb = temp;    //pb가 가리키는 변수에 temp 값 저장
}

/*다른 함수의 변수 사용하기*/

#include <stdio.h>

void swap(void);    //두 변수의 값을 바꾸는 함수의 선언

int main(void)
{
	int a = 10, b = 20;    //변수 선언과 초기화

	swap();    //인수 없이 함수 호출
	printf("a:%d, b:%d\n", a, b);    //변수 a,b 출력

	return 0;
}

void swap(void)    //인수가 없으므로 매개변수도 없음
{
	int temp;    //교환을 위한 변수 선언

	temp = a;    //temp에 main 함수의 a 값 저장
	a = b;    //main 함수의 a에 main 함수의 b 값 저장
	b = temp;    //main 함수의 b에 temp 값 저장
}

/*변수의 값을 인수로 주는 경우*/

#include <stdio.h>

void swap(int x, int y);    //두 변수의 값을 바꾸는 함수 선언

int main(void)
{ 
	int a = 10, b = 20;    //변수 선언과 초기화

	swap(a, b);    //a, b의 값을 복사해서 전달
	printf("a:%d, b:%d\n", a, b);    //변수 a, b 출력

	return 0;
}

void swap(int x, int y)    //인수 a,b의 값을 x,y에 복사해서 저장
{
	int temp;    //교환을 위한 변수

	temp = x;    //temp에 x 값 저장
	x = y;    //x에 y 값 저장
	y = temp;    //y에 temp 값 저장
}