/*변수의 선언과 사용*/


#include <stdio.h>

int main(void)
{
	int a;    //int형 변수 a 선언
	int b, c;    //2개의 int형 변수 b,c를 동시에 선언
	double da;    //double형 변수 da 선언
	char ch;    //char형 변수 ch 선언

	a = 10;    //int형 변수 a에 정수 10을 대입
	b = a;    //int형 변수 b에 변수 a의 값 대입
	c = a + 20;    //int형 변수 c에 변수 a의 값과 정수 20을 더한 값 대입
	da = 3.5;    //double형 변수 da에 실수 3.5 대입
	ch = 'A';    //char형 변수 ch에 문자 'A' 대입

	printf("변수 a의 값 : %d\n", a);
	printf("변수 b의 값 : %d\n", b);
	printf("변수 c의 값 : %d\n", c);
	printf("변수 da의 값 : %.1lf\n", da);
	printf("변수 ch의 값 : %c\n", ch);

	return 0;
}

/*char형 변수의 사용*/


#include <stdio.h>

int main(void)
{
	char ch1 = 'A';    //문자로 초기화, 저장된 값은 문자의 아스키 코드 값
	char ch2 = 65;    //문자 'A'의 아스키 코드 값에 해당하는 정수로 초기화

	printf("문자 %c의 아스키 코드 값 : %d\n", ch1, ch2);
	printf("아스키 코드 값이 %d인 문자 : %c\n", ch2, ch2);

	return 0;
}

/*여러 가지 정수형 변수*/


#include <stdio.h>

int main(void)
{
	short sh = 32767;    //short형의 최댓값 초기화
	int in = 2147483647;    //int형의 최댓값 초기화
	long ln = 2147483647;    //long형의 최댓값 초기화
	long long lln = 123451234512345;    //아주 큰 값 초기화

	printf("short형 변수 출력 : %d\n", sh);
	printf("int형 변수 출력 : %d\n", in);
	printf("long형 변수 출력 : %ld\n", ln);
	printf("long long형 변수 출력 : %lld\n", lln);    //long long형은 lld로 출력

	return 0;
}

/*unsigned를 잘못 사용한 경우*/


#include <stdio.h>

int main(void)
{
	unsigned int a;

	a = 4294967295;    //큰 양수 저장
	printf("%d\n", a);    //%d로 출력
	a = -1;    //음수 저장
	printf("%u\n", a);    //%u로 출력

	return 0;
}

/*유효 숫자 확인*/


#include <stdio.h>

int main(void)
{
	float ft = 1.234567890123456789;    //유효 숫자가 많은 값으로 초기화
	double db = 1.234567890123456789;

	printf("float형 변수의 값 : %.20f\n", ft);    //소수점 이하 20자리까지 출력
	printf("double형 변수의 값 : %.20lf\n", db);

	return 0;
}

/*char 배열에 문자열 저장*/


#include <stdio.h>

int main(void)
{
	char fruit[20] = "strawberry";    //char 배열 선언과 문자열 초기화

	printf("딸기 : %s\n", fruit);    //배열명으로 저장된 문자열 출력
	printf("딸기쨈 : %s %s\n", fruit, "jam");    //문자열 상수를 직접 %s로 출력

	return 0;
}

/*char 배열에 문자열 복사*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>    //문자열을 다룰 수 있는 string.h 헤더 파일 포함

int main(void)
{
	char fruit[20] = "strawberry";    //strawberry로 초기화

	printf("%s\n", fruit);    //strawberry 출력
	strcpy(fruit, "banana");    //fruit에 banana 복사
	printf("%s\n", fruit);    //banana 출력

	return 0;
}

/*const를 사용한 변수*/

#include <stdio.h>

int main(void)
{
	int income = 0;    //소득액 초기화
	double tax;    //세금
	const double tax_rate = 0.12;    //세율 초기화

	income = 456;    //소득액 저장
	tax = income * tax_rate;    //세금 계산
	printf("세금은 : %.1lf입니다.\n", tax);

	return 0;
}