/*학생 3명의 네 과목의 총점과 평균을 구하는 프로그램*/

#include <stdio.h>

int main(void)
{
	int score[3][4];    //3명의 네 과목 점수를 저장할 2차원 배열 선언
	int total;    //총점
	double avg;    //평균
	int i, j;    //반복 제어 변수

	for (i = 0; i < 3; i++)    //학생 수만큼 반복
	{
		printf("4과목의 점수 입력 :");    //입력 안내 메시지
		for (j = 0; j < 4; j++)    //과목 수만큼 반복
		{
			scanf("%d", &score[i][j]);    //점수 입력
		}
	}

	for (i = 0; i < 3; i++)    //학생 수 만틈 반복
	{
		total = 0;    //학새이 바뀔 떄마다 총점이 0으로 초기화
		for (j = 0; j < 4; j++)    //과목 수 만큼 반복
		{
			total += score[i][j];    //학생별로 총점 누적
		}
		avg = total / 4;    //평균 계산
		printf("총점 : %, 평균 : %.2lf\n", total, avg);    //총점, 평균 출력
	}

	return 0;
}

/*2차원 배열의 다양한 초기화 방법*/

#include <stdio.h>

int main(void)
{
	int num[3][4] = {    //2차원 배열의 선언과 초기화
		{1,2,3,4},    //num의 0행
		{5,6,7,8},    //num의 1행
		{9,10,11,12}    //num의 2행
	};
	//int num[3][4={{1,2,3,4},{5,6,7,8},{9,10,11,12};와 같은 문장임
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%5d", num[i][j]);    //배열 요소 출력
		}
		printf("\n");    //한 행을 출력한 후에 줄 바꿈
	}

	return 0;
}

/*여러 개의 동물 이름을 입출력하는 프로그램*/

#include <stdio.h>

int main(void)
{
	char animal[5][20];    //2차원 char 배열 선언
	int i;    //반복 제어 변수
	int count;    //행의 수를 저장할 변수

	count = sizeof(animal) / sizeof(animal[0]);    //행의 수 계산
	for (i = 0; i < count; i++)    //행의 수만큼 반복
	{
		scanf("%s", animal[i]);    //문자열 입력
	}

	for (i = 0; i < count; i++)
	{
		printf("%s", animal[i]);    //입력된 문자열 출력
	}

	return 0;
}

/*2차원 char 배열에 동물 이름을 초기화하는 방법*/

#include <stdio.h>

int main(void)
{
	char animal1[5][10] = {    //문자 상수로 하나씩 초기화
		{'d','o','g','\0'},
		{'t','i','g','e','r','\0'},
		{'r','a','b','b','i','t','\0'},
		{'h','o','r','s','e','\0'},
		{'c','a','t','\0'};
	};
	//문자열 상수로 한 행씩 초기화, 행의 수 생략 가능

	char animal2[][10] = { "dog","tiger","rabbit","horse","cat" };
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("%s", animal1[i]);
	}
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		printf("%s", animal2[i]);
	}

	return 0;
}

/*2개 반 3명의 학생의 4과목 점수를 저장하는 3차원 배열*/

#include <stdio.h>

int main(void)
{
	int score[2][3][4] = {    //2개 반에서 세 명의 4과목 점수 저장
		{{72,80,95,60},{68,98,83,91},{75,72,84,90}},
		{{66,85,90,88},{95,92,88,95},{43,72,56,75}}
	};

	int i, j, k;    //반복 제어 변수

	for (i = 0; i < 2; i++)    //반 수만큼 반복
	{
		printf("%d반 점수...\n", i + 1);    //반이 바뀔 때마다 출력
		for (j = 0; j < 3; j++)    //학생 수만큼 반복
		{
			for (k = 0; k < 4; k++)    //과목 수만큼 반복
			{
				printf("%5d", score[i][j][k]);    //점수 출력
			}
			printf("\n");    //힌 학생의 점수를 출력하고 줄 바꿈
		}
		printf("\n");    //한 반의 점수를 출력하고 줄 바꿈
	}

	return 0;
}

/*포인터 배열로 여러 개의 문자열 출력*/

#include <stdio.h>

int main(void)
{
	char* pary[5];    //포인터 배열 선언, pointer와 arry의 약어로 pary
	int i;    //반복 제어 변수

	pary[0] = "dog";    //배열 요소에 문자열 대입
	pary[1] = "elephant";
	pary[2] = "horse";
	pary[3] = "tiger";
	pary[4] = "lion";

	for (i = 0; i < 5; i++)    //i는 0부터 4까지 5번 반복
	{
		printf("%s\n", pary[i]);    //배열 요소를 사용하여 모든 문자열 출력
	}

	return 0;
}

/*여러 개의 1차원 배열을 2차원 배열처럼 사용*/

#include <stdio.h>

int main(void)
{
	int ary1[4] = { 1,2,3,4 };    //1차원 배열의 선언과 초기화
	int ary2[4] = { 11,12,13,14 };
	int ary3[4] = { 21,22,23,24 };
	int* pary[3] = { ary1, ary2, ary3 };    //포인터 배열에 각 배열명 초기화
	int i, j;

	for (i = 0; i < 3; i++)    //3행 반복
	{
		for (j = 0; j < 4; j++)    //4열 반복
		{
			printf("%5d", pary[i][j]);    //2차원 배열처럼 출력
		}
		printf("\n");
	}

	return 0;
}