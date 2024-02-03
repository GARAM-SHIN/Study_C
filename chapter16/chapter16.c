/*동적 할당한 저장 공간을 사용하는 프로그램*/

#include <stdio.h>
#include <stdlib.h>    //malloc, free 함수 사용을 위한 헤더 파일

int main(void)
{
	int* pi;    //동적 할당 영역을 연결할 포인터 선언
	double* pd;

	pi = (int*)malloc(sizeof(int));    //메모리 동적 할당 후 포인터 연결
	if (pi == NULL)    //동적 할당에 실패하면 NULL 포인터 반환
	{

		printf("# 메모리가 부족합니다.\n");    //예외 상항 메시지 출력
		exit(1);    //프로그램 종료
	}
	pd = (double*)malloc(sizeof(double));

	*pi = 10;    //포인터로 동적 할당 영역 사용
	*pd = 3.4;

	printf("정수형으로 사용 : %d\n", *pi);    //동적 할당 영역에 저장된 값 출력
	printf("실수형으로 사용 : %.1lf\n", *pd);

	free(pi);    //동적 할당 영역 반환
	free(pd);

	return 0;
}

/*동적 할당 영역을 배열처럼 사용*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* pi;    //동적 할당 영역을 연결할 포인터
	int i, sum = 0;    //반복 제어 변수와 누적 변수

	pi = (int*)malloc(5 * sizeof(int));    //저장 공간 20바이트 할당
	if (pi == NULL)
	{
		printf("메모리가 부족합니다!\n");
		exit(1);
	}

	printf("다섯 명의 나이를 입력하세요 : ");
	for (i = 0; i < 5; i++)     //i는 0부터 4까지 5번 반복
	{
		scanf("%d", &pi[i]);    //배열 요소에 입력
		sum += pi[i];    //배열 요소의 값 누적
	}
	printf("다섯 명의 평균 나이 : %.1lf\n", (sum / 5.0));    //평균 나이 출력
	free(pi);    //할당한 메모리 영역 반환

	return 0;
}

/*calloc, realloc 함수를 사용한 양수 입력*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* pi;    //할당한 저장 공간을 연결할 포인터
	int size = 5;    //한 번에 할당할 저장 공간의 크기, int형 변수 5개씩 
	int count = 0;    //현재 입력된 양수 개수
	int num;    //양수를 입력할 변수
	int i;    //반복 제어 변수

	pi = (int*)calloc(size, sizeof(int));    //먼저 5개의 저장 공간 할당
	while (1)
	{
		printf("양수만 입력하세요 : ");
		scanf("%d", &num);    //데이터 입력
		if (num <= 0)break;    //0또는 음수이면 종료
		if (count == size)    //저장 공간을 모두 사용하면
		{
			size += 5;    //크기를 늘려서 재할당
			pi = (int*)realloc(pi, size * sizeof(int));
		}
		pi[count++] = num;
	}
	for (i = 0; i < count; i++)
	{
		printf("%5d", pi[i]);    //입력한 데이터 출력
	}
	free(pi);    //동적 할당 저장 공간 반납

	return 0;
}

/*3개의 문자열을 저장하기 위한 동적 할당*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char temp[80];    //임시 char 배열
	char* str[3];    //동적 할당 영역을 연결할 포인터 배열
	int i;    //반복 제어 변수

	for (i = 0; i < 3; i++)
	{
		printf("문자열을 입력하세요 : ");
		gets(temp);    //문자열 입력
		str[i] = (char*)malloc(strlen(temp) + 1);    //문자열 저장 공간 할당 
		strcpy(str[i], temp);    //동적 할당 영역에 문자열 복사
	}

	for (i = 0; i < 3; i++)
	{
		printf("%s\n", str[i]);    //입력된 문자열 출력
	}

	for (i = 0; i < 3; i++)
	{
		free(str[i]);    //동적 할당 영역 반환
	}

	return 0;
}

/*동적 할당 영역의 문자열을 함수로 출력*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_str(char** ps);    //동적 할당 영역의 문자열을 출력하는 함수

int main(void)
{
	char temp[80];    //임시 char 배열
	char* str[21] = { 0 };    //문자열을 연결할 포인터 배열, 널 포인터로 초기화
	int i = 0;    //반복 제어 변수

	while (i < 20)    //최대 20개까지 입력
	{
		printf("문자열을 입력하세요 : ");
		gets(temp);    //문자열 입력
		if (strcmp(temp, "end") == 0)break;    //end가 입력되면 반복 종료
		str[i] = (char*)malloc(strlen(temp) + 1);    //문자열 저장 공간 할당
		strcpy(str[i], temp);    //동적 할당 영역에 문자열 복사
		i++;
	}
	print_str(str);    //입력한 문자열 출력

	for (i = 0; str[i] != NULL; i++)    //str에 연결된 문자열이 없어질 때까지
	{
		free(str[i]);    //동적 할당 영역 반환
	}

	return 0;
}

void print_str(char** ps)    //이중 포인터 선언
{
	while (*ps != NULL)    //포인터 배열의 값이 널 포인터가 아닌 동안 반복
	{
		printf("%s\n", *ps);    //ps가 가리키는 것은 포인터 배열의 요소
		ps++;    //ps가 다음 배열 요소를 가리킴
	}
}

/*명령행 인수를 출력하는 프로그램*/

#include <stdio.h>

int main(int argc, char **argv)    //명령행 인수를 받을 매개변수
{
	int i;

	for (i = 0; i < argc; i++)    //인수 개수 만큼 반복
	{
		printf("%s\n", argv[i]);    //인수로 받은 문자열 출력
	}

	return 0;
}