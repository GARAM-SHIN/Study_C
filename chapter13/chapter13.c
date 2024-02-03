/*두 함수에서 같은 이름의 지역 변수를 사용한 경우*/

#include <stdio.h>

void assign(void);    //함수 선언

int main(void)
{
	auto i = 0;    //지역 변수 선언과 초기화, auto는 생략 가능

	assign();    //함수 호출
	printf("main 함수 a : %d\n", a);

	return 0;
}

void assign(void) 
{
	int a;    //main 함수에 있는 변수와 같은 이름의 지역 변수, auto 생략

	a = 10;    //assign 함수 안에 선언된 a에 대입
	printf("assign 함수 a : %d\n", a);    //assign 함수에 선언된 a 값 출력
}

/*블록 안에 지역 변수를 사용하여 두 변수를 교환하는 프로그램*/

#include <stdio.h>

int main(void)
{
	int a = 10, b = 20;

	printf("교환 전 a와 b의 값 : %d %d\n", a, b);
	{    //블록 시작
		int temp;    //temp 변수 선언

		temp = a;
		a = b;    //a와 b는 윗 행에 선언된 변수
		b = temp;
	}    //블록 끝
	printf("교환 후 a와 b의 값 : %d %d\n", a, b);

	return 0;
}

/*전역 변수의 사용*/

#include <stdio.h>

void assign10(void);
void assign20(void);

int a;    //전역 변수 사용

int main(void)
{
	printf("함수 호출 전 a 값 : %d\n", a);    //전역 변수 a 출력

	assign10();
	assign20();

	printf("함수 호출 후 a 값 : %d\n", a);    //전역 변수 a 출력

	return 0;
}

void assign10(void)
{
  	a = 10;    //전역 변수 a에 10 대입
}

void assign20(void)
{
	int a;    //전역 변수와 같은 이름의 지역 변수 선언

	a = 20;    //지역 변수 a에 20 대입
}

/*auto 지역 변수와 static 지역 변수의 비교*/

#include <stdio.h>

void auto_func(void);    //auto_func 함수 선언
void static_func(void);    //static_func 함수 선언

int main(void)
{
	int i;

	printf("일반 지역 변수(auto)를 사용한 함수...\n");
	for (i = 0; i < 3; i++)
	{
		auto_func();
	}

	printf("정적 지역 변수(static)를 사용한 함수...\n");
	for (i = 0; i < 3; i++)
	{
		static_func();
	}

	return 0;
}

void auto_func(void)
{
	auto int a = 0;    //지역 변수 선언과 초기화

	a++;    //a 값 1 증가
	printf("%d\n", a);    //a 출력
}

void static_func(void)
{
	static int a;    //정적 지역 변수 선언

	a++;    //a 값 1 증가
	printf("%d\n", a)    //a 출력
}

/*래지스터 변수를 반복문에 사용한 예*/

#include <stdio.h>

int main(void)
{
	register int i;    //래지스터 변수
	auto int sum = 0;    //auto 지역 변수

	for (i = 1; i <= 10000; i++)    //반복 과정에서 i를 계속 사용함
	{
		sum += i;    //i값을 반복하여 누적
	}

	printf("%d\n", sum);

	return 0;
}

/*10을 더하기 위해 값을 인수로 주는 경우*/

#include <stdio.h>

void add_ten(int a);    //함수 선언

int main(void)
{
	int a = 10;

	add_ten(a);    //a 값을 복사아여 전달
	printf("a :%d\n", a);

	return 0;
}

void add_ten(int a)    //위 행의 a와 다른 독립적인 저장 공간 할당
{
	a = a + 10;    //이 함수의 매개변수 a에 10을 더함
}

/*포인터를 써서 변수의 값에 10을 더하는 경우*/

#include <stdio.h>

void add_ten(int* pa);    //매개변수로 포인터 pa 선언

int main(void)
{
	int a = 10;

	add_ten(&a);    //a의 주소를 인수로 줌
	printf("a : %d\n", a);    //증가된 a 값 출력

	return 0;
}

void add_ten(int *pa)    //포인터 pa가 a의 주소를 받음
{
	*pa = *pa + 10;    //포인터 pa가 가리키는 변수의 값 10 증가
}

/*주소를 반환하여 두 정수의 합 계산*/

#include <stdio.h>

int* sum(int a, int b);    //int형 변수의 주소를 반환하는 함수 선언

int main(void)
{
	int* resp;    //반환값을 저장할 포인터 resp(result pointer)

	resp = sum(10, 20);    //반환될 주소는 resp에 저장
	printf("두 정수의 합 : %d\n", *resp);    //resp가 가리키는 변숫값 저장

	return 0;
}

int* sum(int a, int b)    //int형 변수의 주소를 반환하는 함수
{
	static int res;    //정적 지역 변수

	res = a + b;    //두 정수의 합을 res(result)에 저장

	return &res;    //정적 지역 변수의 주소 반환
}