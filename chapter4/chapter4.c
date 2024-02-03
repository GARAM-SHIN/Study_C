/*대입, 덧셈, 뺄셈, 곱셈, 음수 연산*/

#include <stdio.h>

int main(void)
{
	int a, b;
	int sum, sub, mul, inv;

	a = 10;    //대입 연산(=)
	b = 20;    //대입 연산(=)
	sum = a + b;    //더하기 연산 후 대입 연산
	sub = a - b;    //빼기 연산 후 대입 연산
	mul = a * b;    //곱하기 연산 후 대입 연산
	inv = -a;    //음수 연산 후 대입 연산

	printf("a의 값 :%d, b의 값 :%d\n", a, b);
	printf("덧셈 : %d\n", sum);
	printf("뺄셈 : %d\n", sub);
	printf("곱셈 : %d\n", mul);
	printf("a의 음수 연산 : %d\n", inv);

	return 0;
}

/*몫과 나머지를 구하는 연산*/

#include <stdio.h>

int main(void)
{
	double apple;    //실수
	int banana;    //정수
	int orange;    //정수

	apple = 5.0 / 2.0;    //실수와 실수의 나누기 연산
	banana = 5 / 2;    //정수와 정수의 나누기 연산
	orange = 5 % 2;    //정수와 정수의 나머지 연산

	printf("apple : %.1lf\n", apple);
	printf("banana : %d\n", banana);
	printf("orange : %d\n", orange);

	return 0;
}

/*증감 연산자의 연산*/

#include <stdio.h>

int main(void)
{
	int a = 10, b = 10;

	++a;    //변수의 값을 1만큼 증가
	--b;     //변수의 값을 1만큼 감소

	printf("a : %d\n", a);
	printf("b : %d\n", b);

	return 0;
}

/*전위 표기와 후위 표기를 사용한 증감 연산*/

#include <stdio.h>

int main(void)
{
	int a = 5, b = 5;
	int pre, post;

	pre = (++a) * 3;    //전위형 증감 연산자
	post = (b++) * 3;    //후위형 증감 연산자

	printf("초깃값 a = %d, b = %d\n", a, b);
	printf("전위형: (++a) * 3 = %d, 후위형: (b++) * 3 = %d\n", pre, post);

	return 0;
}

/*관계 연산의 결괏값 확인*/

#include <stdio.h>

int main(void)
{
	int a = 10, b = 20, c = 10;
	int res;    //결괏갑을 저장할 변수
	    //각각 a와 b, c 값을 대입해보자.
	res = (a > b);    //10 > 20은 거짓이므로 결괏값은 0
	printf("a > b : %d\n", res);      
	res = (a >= b);    //10 > 20은 거짓이므로 결괏값은 0
	printf("a >= b : %d\n", res);
	res = (a < b);    //10 >= 20은 참이므로 결괏값은 1
	printf("a > b : %d\n", res);
	res = (a <= b);    //10 < 10은 참이므로 결괏값은 1
	printf("a <= b : %d\n", res);
	res = (a <= c);    //10 <= 10은 참이므로 결괏값은 1
	printf("a <= c : %d\n", res);
	res = (a == b);    //10 == 20은 거짓이므로 결괏값은 0
	printf("a == b : %d\n", res);
	res = (a != c);    //10 != 10은 거짓이므로 결괏값은 0
	printf("a != c : %d\n", res);

	return 0;
}

/*논리 연산의 결괏값 확인*/

#include <stdio.h>

int main(void)
{
	int a = 30;
	int res;

	res = (a > 10) && (a < 20);    //좌항과 우항이 모두 참이면 참
	printf("(a > 10) && (a < 20) : %d\n", res);
	res = (a < 10) :: (a > 20);    //좌항과 우항 중 하나라도 참이면 참
	printf("(a < 10) :: (a > 20) : %d\n", res);
	res = !(a >= 30);    //거짓이면 참으로, 참이면 거짓으로
	printf("!(a >= 30 : %d\n", res);

	return 0;
}

/*연산의 결괏값을 사용하는 방법*/

#include <stdio.h>

int main(void)
{
	int a = 10, b = 20, res;

	a + b;    //연산 결과는 버려짐
	printf("%d + %d = %d\n", a, b, a + b);    //연산 결과를 바로 출력에 사용

	res = a + b;    //연산 결과를 변수에 저장
	printf("%d + %d = %d\n", a, b, res);    //저장된 값을 계속 사용

	return 0;
}