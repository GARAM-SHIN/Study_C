/*대문자를 소문자로 변경*/

#include <stdio.h>

int main(void)
{
	char small, cap = 'G';    //char형 변수 선언과 초기화

	if ((cap > 'A') && (cap <= 'Z'))    //대문자 범위라면
	{
		small = cap + ('a' - 'A');    //대/소문자의 차이를 더해 소문자로 변환
	}
	printf("대문자 : %c %c", cap, '\n');    //'\n'를 %c로 출력하면 줄이 바뀜
	printf("소문자 : %c", small);

	return 0;
}

/*공백이나 제어 문자의 입력*/

#include <stdio.h>

int main(void)
{
	char ch1, ch2;

	scanf("%c%c", &ch1, &ch2);    //2개의 문자를 연속 입력

	printf("[%c%c]", ch1, ch2);    //입력된 문자 출력

	return 0;
}

/*getchar 함수와 putchar 함수 사용*/

#include <stdio.h>

int main(void)
{
	int ch;    //입력 문자를 저장할 변수

	ch = getchar();    //함수가 반환하는 문자를 바로 저장
	printf("입력한 문자 : ");

	putchar(ch);    //입력한 문자 출력
	putchar('\n');    //개행 문자 출력

	return 0;
}

/*버퍼를 사용하는 문자 입력*/

#include <stdio.h>

int main(void)
{
	char ch;
	int i;

	for (i = 0; i < 3; i++)    //3번 반복
	{
		scanf("%c", &ch);    //문자 입력 
		printf("%c", ch);    //입력된 문자 출력
	}

	return 0;
}

/*입력 문자의 아스키 코드 값을 출력하는 프로그램*/

#include <stdio.h>

int main(void)
{
	int res;    //scanf 함수의 반환값을 저장할 변수
	char ch;    //문자를 입력할 변수

	while (1)
	{
		res = scanf("%c", &ch);    //문자 입력, <Crtl> + <Z>를 누르면 -1 반환
		if (res == -1)break;    //반환값이 -1이면 반복 종료
		printf("%d", ch);    //입력된 문자의 아스키 코드 값 출력
	}

	return 0;
}

/*getchar 함수를 사용한 문자열 입력*/

#include <stdio.h>

void my_gets(char* str, int size);

int main(void)
{
	char str[7];    //문자열을 저장할 배열

	my_gets(str, sizeof(str));    //한 줄의 문자열을 입력하는 함수
	printf("입력한 문자열 : %s\n", str);    //입력한 문자열 출력

	return 0;
}

void my_gets(char* str, int size)    //str은 char 배열, size는 배열의 크기
{
	int ch;    //getchar 함수의 반환값을 저장할 변수
	int i = 0;    //str 배열의 점자

	ch = getchar();    //첫 번째 문자 입력
	while ((ch != '\n') && (i < size - 1))   //배열의 크기만큼 입력
	{
		str[i] = ch;   //입력한 문자를 배열에 저장
		i++;    //첨자 증가
		ch = getchar();    //새로운 문자 입력
	}
	str[i] = '\0';    //입력된 문자열의 끝에 널 문자를 저장
}

/*버퍼의 내용을 지워야 하는 경우*/

#include <stdio.h>

int main(void)
{
	int num, grade;    //학번과 학점을 저장할 변수

	printf("학번 입력 : ");
	scanf("%d", num);    //학번 입력
	getchar();    //버퍼에 남아 있는 개행 문자 제거
	printf("학점 입력 : ");
	grade = getchar();    //학점 입력
	printf("학번 : %d, 학점 : %c", num, grade);

	return 0;
}