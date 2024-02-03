/*while문을 사용한 반복문*/


include <stdio.h>

int main(void)
{
	int a = 1;    //변수를 선언하고 곱셈을 하기 위해 1로 초기화

	while (a < 10)    //1) a가 10보다 작으므로 조건식은 참
	{
		a = a * 2;    //2) a에 2를 곱해 a에 다시 저장
	}
	printf("a : %d\n", a);    //a 값 출력

	return 0;
}

/*for문을 사용한 반복문*/


#include <stdio.h>

int main(void)
{
	int a = 1;    //변수를 선언하고 1로 초기화
	int i;    //반복 횟수를 세기 위한 변수

	for (i = 0; i < 3; i++)    //1) i는 0으로 초기화된 후에 2) 3보다 작은 동안(i < 3)
	{                          //3)하나씩 증가하면서(i++)
		a = a * 2;    //실행문을 실행
	}
	printf("a : %d\n", a);    //for문을 빠져나오면 a 값 출력

	return 0;
}

/*do~while문을 사용한 반복문*/


#include <stdio.h>

int main(void)
{
	int a = 1;    //변수를 선언하고 1로 초기화

	do    //반복문 시작 위치
	{
		a = a * 2;    //a의 값을 2배로 늘린다.
	} while (a < 10);    //a가 10보다 작으면 반복
	printf("a : %d\n", a);    //반복이 끝난 후 a 값 출력

	return 0;
}

/*중첩 반복문을 사용한 별 출력*/


#include <stdio.h>

int main(void)
{
	int i, j;    //반복 횟수를 세기 위한 제어 변수

	for (i = 0; i < 5; i++)    //i가 9부커 2까지 증가하면서 3변 반복
	{
		for (j = 0; j < 5; j++)    //j가 0부터 4까지 증가하면서 5번 반복
		{
			printf("*");    //별 출력문
		}
		printf("\n");    //별을 5번 출력한 후에 줄을 바꾼다.
	}
	return 0;
}

/*break를 사용한 반복문 종료*/

#include <stdio.h>

int main(void)
{
	int i;    //반복 횟수를 세기 위한 제어 변수
	int sum = 0;    //1부터 10까지의 합을 누적할 변수

	for (i = 1; i <= 10; i++)    //i는 1부터 10까지 증가하면서 10반 반복
	{
		sum += i;    //i 값을 sum에 누적
		if (sum > 30)break;    //누적한 값이 30보다 크면 반복문을 끝낸다.
	}
	printf("누적한 값 : %d\n", sum);

	printf("마지막으로 더한 값 : %d\n", i);

	return 0;
}