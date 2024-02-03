/*if문의 기본 형식*/


#include <stdio.h>

int main(void)
{
	int a = 20;
	int b = 0;

	if (a > 10)    //조건식: a가 10보다 크므로 조건식은 참
	{
		b = a;    //실행문: b=a 대입문 실행
	}

	printf("a : %d, b : %d\n", a, b);    //대입이 수행되면 두 값은 같음

	return 0;
}

/*if~else문의 사용*/


#include <stdio.h>

int main(void)
{
	int a = 20;

	if (a >= 0)
	{
		a = 1;    //a가 0보다 크거나 같으면 a에 1 대입
	}
	else
	{
		a = -1;    //a가 0보다 작으면 a에 -1 대입
	}

	printf("a : %d\n", a);

	return 0;
}

/*if~else if~else문 사용*/


#include <stdio.h>

int main(void)
{
	int a = 0, b = 0;

	if (a > 0)    // 1)조건식1: a가 0보다 크면 b에 1 대입
	{
		b = 1;
	}
	else if (a == 0)    // 2)조건식2: a가 0보다 크지 않고 a가 0이면 b에 2 대입
	{
		b = 2;
	}
	else    // 3)a가 0보다 크지 않고 0도 아니면 b에 3대입
	{
		b = 3;
	}

	printf("b : %d\n", b);    //if문으로 결정된 b 값 출력

	return 0;
}

/*중첩된 if문*/


#include <stdio.h>

int main(void)
{
	int a = 20, b = 10;

	if (a > 10)    
	{
		if (b >= 0)
		{
			b = 1;
		}
		else
		{
			b = -1;
		}
	}

	printf("a : %d, b : %d\n", a, b);

	return 0;
}

/*중첩 if문에서 중괄호가 반드시 필요한 경우*/


#include <stdio.h>

int main(void)
{
	int a = 10, b = 20;

	if (a < 0)    //a가 0보다 작지만
	{
		if (b > 0)    //b가 0보다 크면 ok 출력
		{
			printf("ok");
		}
	}
	else    //a가 0 이상이면 ok 출력
	{
		printf("ok");
	}

	return 0;
}

/*switch~case문의 사용*/

#include <stdio.h>

int main(void)
{
	int rank = 2, m = 0;

	switch (rank)    //rank의 값이 얼마인지 확인
	{
	case 1:    //rank가 1이면
		m = 300;    // m = 300을 수행하고
		break;    //블록을 벗어남
	case 2:
		m = 200;
		break;
	case 3:
		m = 100;
		break;
	default:    //rank와 일치하는 case의 값이 없으면
		m = 10;    //m = 10을 수행하고
		break;    //블록을 벗어남
	}

	printf("m : %d\n", m);

	return 0;
}