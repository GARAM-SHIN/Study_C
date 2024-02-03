/*배열명에 정수 연산을 수행하여 배열 요소 사용*/

#include <stdio.h>

int main(void)
{
	int ary[3];
	int i;

	*(ary + 0) = 10;    //ary[0]=10
	*(ary + 1) = *(ary + 0) + 10;    //ary[1]=ary[0]+10

	printf("세 번쨰 배열 요소에 키보드 입력 : ");
	scanf_s("%d", ary + 2);    //&ary[2]

	for (i = 0; i < 3; i++)    //모든 배열 요소 출력
	{
		printf("%5d", *(ary + i));    //ary[i]
	}
	return 0;
}

/*배열명처럼 사용되는 포인터*/

#include <stdio.h>

int main(void)
{
	int ary[3];    //배열 선언
	int* pa = ary;    //포인터에 배열명 저장
	int i;    //반복 제어 변수

	*pa = 10;    //첫 번째 배열 요소에 10 대입
	*(pa + 1) = 20;    //두 번쨰 배열 요소에 20 대입
	pa[2] = pa[0] + pa[1];    //대괄호를 써서 pa를 배열명처럼 사용

	for (i = 0; i < 3; i++)
	{
		printf("%5d", pa[i]);    //포인터로 모든 배열 요소 출력
	}
	return 0;
}

/*포인터를 이용한 배열의 값 출력*/

#include <stdio.h>

int main(void)
{
	int ary[3] = { 10,20,30 };
	int* pa = ary;
	int i;

	printf("배열의 값 : ");
	for (i = 0; i < 3; i++)
	{
		printf("%d", *pa);    //pa가 가리키는 배열 요소 출력
		pa++;    //다음 배열 요소를 가리키도록 pa 값 증가
	}
	return 0;
}

/*포인터의 뺄셈과 곱셈의 연산*/

#include <stdio.h>

int main(void)
{
	int ary[5] = { 10,20,30,40,50 };
	int* pa = ary;    //첫 번째 배열 요소 주소
	int* pb = pa + 3;    //네 번쨰 배열 요소 주소

	printf("pa : %u\n", pa);
	printf("pb : %u\n", pb);
	 
	pa++;    //pa를 다음 배열 요소로 이동
	printf("pb-pa : %u\n", pb - pa);    //두 포인터의 뺼셈

	printf("앞에 있는 배열 요소의 값 출력 : ");
	if (pa < pb)printf("%d\n", *pa);    //pa가 배열의 앞에 있으면 *pa 출력 
	else printf("%d\n", *pb);    //pb가 배열의 앞에 있으면 *pb 출력

	return 0;
}

/*배열을 처리하는 함수*/

#include <stdio.h>

void print_ary(int* pa);    //함수 선언

int main(void)
{
	int ary[5] = { 10,20,30,40,50 };

	print_ary(ary);    //배열명을 주고 함수 호출

	return 0;
}

void print_ary(int* pa)    //매개변수로 포인터 선언
{
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("%d", pa[i]);    //pa로 배열 요소 표현식 사용
	}
}

/*크기가 다른 배열을 출력하는 함수*/

#include <stdio.h>

void print_ary(int* pa, int size);    //함수 선언, 매개변수 2개

int main(void)
{
	int ary1[5] = { 10,20,30,40,50 };    //배열 요소의 개수가 5개인 배열
	int ary2[7] = { 10,20,30,40,50,60,70 };    //요소의 개수가 7개인 배열

	print_ary(ary1, 5);    //ary1 배열 출력, 배열 요소의 개수 전달
	printf("\n");    
	print_ary(ary2, 7);    //ary2 배열 출력, 배열 요소의 개수 전달

	return 0;
}

void print_ary(int* pa, int size)    //배열명과 배열 요소의 개수를 받는 매개변수 선언
{
	int i;

	for (i = 0; i < size; i++)    //size 값에 따라 반복 횟수 결정
	{
		printf("%d", pa[i]);
	}
}

/*배열에 값을 입력하는 함수*/

#include <stdio.h>

void input_ary(double* lpa, int size);
double find_max(double* pa, int size);

int main(void)
{
	double ary[5];
	double max;    //최댓값을 저장할 변수
	int size = sizeof(ary) / sizeof(ary[0]);    //배열 요소의 개수 계산

	input_ary(ary, size);    //배열에 값 입력
	max = find_max(ary, size);    //배열의 최댓값 반환
	printf("배열의 최댓값 : %.1lf\n", max);

	return 0;
}

void input_ary(double* pa, int size)    //double 포인터를 매개변수로 선언
{
	int i;

	printf("%d개의 실수값 입력 : ", size);
	for (i = 0; i < size; i++)    //size 값에 따라 반복 횟수 결정
	{
		scanf("%lf", pa + i);    //&pa[i]도 가능, 입력할 배열 요소의 주소를 전달
	}
}

double find_max(double* pa, int size)
{
	double max;
	int i;

	max = pa[0];    //첫 번쨰 배열 요소의 값을 최댓값으로 설정
	for (i = 1; i < size; i++)    //두 번쨰 배열 요소부터 max와 비교
	{
		if (pa[i] > max)max = pa[i];    //새료운 배열 요소의 값이 max보다 크면 대입
	}

	return max;    //최댓값 반환
}