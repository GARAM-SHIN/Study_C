/*5명의 나이를 저장할 배열을 선언하고 사용하는 방법*/

#include <stdio.h>

int main(void)
{
	int ary[5];    //int형 요소 5개의 배열 선언
                   //ary는 array의 축약어
	ary[0] = 10;     //첫 번째 배열 요소에 10 대입
	ary[1] = 20;    //두 번째 배열 요소에 20 대입
	ary[2] = ary[0] + ary[1];    //첫 번째 요소와 두 번째 요소를 더해 세 번째요소에 저장
	scanf("%d", &ary[3]);    //키보드로 입력받아 네 번째 요소에 저장

	printf("%d\n", ary[2]);    //세 번째 배열 요소 출력
	pirntf("%d\n", ary[3]);
	printf("%d\n", ary[4]);    //마지막 배열 요소는 쓰레기 값

	return 0;
}

/*배열과 반복문을 사용한 성적 처리 프로그램*/

#include <stdio.h>

int main(void)
{
	int score[5];    //다섯 과목의 성적을 입력할 int형 배열 선언
	int i;    //반복 제어 변수
	int total = 0;    //총점을 누적할 변수
	double avg;    //평균을 저장할 변수

	for (i = 0; i < 5; i++)    //i가 0부터 4까지 5번 반복
	{
		scanf("%d", &score[i]);    //각 배열 요소에 성적 입력
	}

	for (i = 0; i < 5; i++)
	{
		total += score[i];    //성적을 누적하여 총점 계산
	}
	avg = total / 5.0;    //평균 계산

	for (i = 0; i < 5; i++)
	{
		printf("%5d", score[i]);    //성적 출력
	}
	printf("\n");

	printf("평균 : %.1lf\n", avg);    //평균 출력

	return 0;
}

/*sizeof 연산자를 사용한 배열*/

#include <stdio.h>

int main(void)
{
	int score[5];
	int i;
	int total = 0;
	double avg;
	int count;    //배열 요소의 개수를 저장할 변수

	count = sizeof(score) / sizeof(score[0]);    //배열 요소의 개수 계산

	for (i = 0; i < count; i++)    //위 행에서 계산한 count만큼 반복
	{
		scanf("%d", &score[i]);
	}

	for (i = 0; i < count; i++)    
	{
		total += score[i];
	}
	avg = total / (double)count;    //총합을 count로 나누어 평균 계산

	for (i = 0; i < count; i++)
	{
		printf("%5d", score[i]);
	}
	printf("\n");

	printf("평균 : %.1lf\n", avg);

	return 0;
}

/*문자열을 저장하는 char형 배열*/

#include <stdio.h>

int main(void)
{
	char str[80] = "applejam";    //문자열 초기화

	printf("최초 문자열 : %s\n", str);    //초기화 문자열 출력
	printf("문자열 입력 :");
	scanf("%s", str);    //새로운 문자열 입력
	printf("입력 후 문자열 : %s\n", str);    //입력된 문자열 출력

	return 0;
}

/*문자열 대입하는 strcpy함수*/

#include <stdio.h>
#include <string.h>    //문자열 관련 함수 원형을 모아놓은 헤더 파일

int main(void)
{
	char str1[80] = "cat";
	char str2[80];

	strcpy(str1, "tiger");    //str1 배열에 "tiger" 복사
	strcpy(str2, str1);    //str2 배열에 str1 배열의 문자열 복사
	printf("%s %s\n", str1, str2);

	return 0;
}

/*빈칸을 포함한 문자열 입력*/

#include <stdio.h>

int main(void)
{
	char str[80];

	printf("문자열 입력 : ");    //입력 안내 메시지 출력
	gets(str);    //빈칸을 포함한 문자열 입력
	puts("입력된 문자열 : ");    //문자열 상수 출력
	puts(str);    //배열에 저장된 문자열 출력

	return 0;
}

/*널 문자가 없는 문자열*/

#include <stdio.h>

int main(void)
{
	char str[5];

	str[0] = 'O';
	str[1] = 'K';
	printf("%s\n", str);

	return 0;
}