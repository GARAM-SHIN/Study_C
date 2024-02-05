/* 작성자 : 
   제목 : 10과 20을 더하는 프로그램*/

int main(void)
{
	10 + 20;

	return 0;
}

/*문자열을 화면에 출력하는 프로그램*/

#include <stdio.h>   // stdio : standard input output(표준입출력)의 줄임말

int main(void)
{
	printf("Be happy");   //문자열 "Be happy" 출력
	printf("My friend");  //문자열 "My friend" 출력

	return 0;
}

/*제어 문자를 사용한 출력*/

#include <stdio.h>

int main(void)
{
	printf("Be happy\n");   //"Be happy"를 출력하고 줄을 바꿈
	printf("12345678901234567890\n");   //화면에 열 번호를 출력하고 줄을 바꿈
	printf("My\tfriend\n");   //"My"를 출력하고 탭 위치로 이동 후에 "friend"를 출력하고 줄을 바꿈
	printf("Goot\bd\tchance\n");   //t를 d로 바꾸고 탭 위치로 이동 후에 "chance"를 출력하고 줄을 바꿈
	printf("Cow\rW\a\n");    //맨 앞으로 이동해 C를 W로 바꾸고 벨소리를 내고 줄을 바꿈

	return 0;
}

/*정수와 실수의 출력*/

#include <stdio.h>

int main(void)
{
	printf("%d\n", 10);   //%d 위치에 10 출력
	printf("%lf\n", 3.4);    //%lf 위치에 3.4를 소수점 이하 6자리까지 출력
	printf("%.1lf\n", 3.45);    //소수점 이하 첫째 자리까지 출력(둘때 자리에서 반올림)
	printf("%.10lf\n", 3.4);   //소수점 이하 10자리까지 출력

	printf("%d과 %d의 합은 %d입니다.\n", 10, 20, 10 + 20);
	printf("%.1lf-%.1lf = %.1lf\n", 3.4, 1.2, 3.4 - 1.2);

	return 0;
}

/*세 가지 진법의 정수 상수*/

#include <stdio.h>

int main(void)
{
	printf("%d\n", 12);    //10진수 정수 상수 출력
	printf("%d\n", 014);    //8진수 정수 상수 출력
	printf("%d\n", 0xc);    //16진수 정수 상수 출력

	return 0;
}

/*지수 형태의 실수 상수*/

#include <stdio.h>

int main(void)
{
	printf("%.1lf\n", 1e6);    //지수 형태의 실수를 소수점 형태로 출력
	printf("%.7lf\n", 3.14e-5);    //소수점 이하 7자리까지 출력
	printf("%le\n", 0.0000314);    //소수점 형태의 실수를 지수 형태로 출력
	printf("%.2le\n", 0.0000314);    //지수 형태로 소수점 이하 둘째 자리까지 출력

	return 0;
}

/*문자와 문자열 데이터의 출력*/

#include <stdio.h>

int main(void)
{
	printf("%c\n", 'A');    //문자 상수 출력
	printf("%s\n", "A");    //문자열 상수 출력
	printf("%c은 %s입니다.\n", '1', "first");    //문자와 문자열을 함께 출력

	return 0;
}