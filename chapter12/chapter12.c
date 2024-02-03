/*문자열 상수가 주소란 증거*/

#include <stdio.h>

int main(void)
{
	printf("apple이 저장된 시작 주소 값 : %p\n", "apple");    //주소 값 출력
	printf("두 번째 문자의 주소 값 : %p\n", "apple" + 1);    //주소 값 출력
	printf("첫 번째 문자 : %c\n", *"apple");    //간접 참조 연산
	printf("두 번째 문자 : %c\n", *("apple" + 1));    //포인터 연산식
	printf("배열로 표현한 세 번째 문자 : %c\n", "apple"[2]);    //배열 표현식

	return 0;
}

/*포인터로 문자열을 사용하는 방법*/

#include <stdio.h>

int main(void)
{
	char* dessert = "apple";    //포인터에 문자열 초기화

	print("오늘 후식은 %s입니다.\n", dessert);    //문자열 출력
	dessert = "banana";    //새로운 문자열 출력
	printf("내일 후식은 %s입니다.\n", dessert);    //바뀐 문자열 출력

	return 0;
}

/*scanf함수를 사용한 문자열 입력*/

#include <stdio.h>

int main(void)
{
	char str[80];

	printf("문자열 입력 : ");
	scanf("%s", str);    //%s를 사용하고 배열명을 줌
	printf("첫 번째 단어 : %s\n", str);    //배열에 입력된 문자열 출력
	scanf("%s", str);
	printf("버퍼에 남아 있는 두 번째 단어 : %s\n", str);

	return 0;
}

/*gets 함수로 한 줄의 문자열 입력*/

#include <stdio.h>

int main(void)
{
	char str[80];

	printf("공백이 포함된 문자열 입력 : ");
	gets(str);    //배열명을 주고 함수 호출
	printf("입력한 문자열은 %s입니다.", str);

	return 0;
}

/*fgets 함수의 문자열 입력 방법*/

#include <stdio.h>
//나중에 입력할 공간입니다.

int main(void)
{
	char str[80];

	printf("공백이 포함된 문자열 입력 : ");    //문자열 입력
	fgets(str, sizeof(str), stdin);
	//나중에 입력할 공간입니다.
	printf("입력된 문자열은 %s입니다\n", str);

	return 0;
}

/*개행 문자로 인해 gets 함수가 입력을 못하는 경우*/

#include <stdio.h>

int main(void)
{
	int age;    //나이를 저장할 변수
	char name[20];    //이름을 저장할 변수

	printf("나이 입력 : ");
	scanf("%d", age);    //scanf 함수로 나이 입력

	printf("이름 입력 : ");
	gets(name);    //gets 함수로 이름 입력
	printf("나이 : %d, 이름 : %s\n", age, name);

	return 0;
}

/*문자열을 출력하는 put와 fputs함수*/

#include <stdio.h>

int main(void)
{
	char str[80] = "apple juice";    //배열에 문자열 초기화
	char* ps = "banana";    //포인터에 문자열 연결

	puts(str);    //apple juice 출력하고 줄 바꿈
	fputs(ps, stdout);    //banana만 출력
	puts("milk");    //banana에 이어 milk 출력

	return 0;
}

/*strcpy 함수의 사용법*/

#include <stdio.h>
#include <string.h>   //strcpy 함수를 사용하기 위해 인클루드함

int main(void)
{
	char str1[80] = "strawberry";    //char 배열에 문자열 초기화
	char str2[80] = "apple";    //char 배열에 문자열 초기화
	char* ps1 = "banana";    //포인터로 문자열 상수 연결
	char* ps2 = str2;    //포인터로 배열 연결

	printf("최초 문자열 : %s\n", str1);
	strcpy(str1, str2);    //다른 char 배열의 문자열 복사
	printf("바뀐 문자열 : %s\n", str1);

	strcpy(str1, ps1);    //문자열 상수를 연결한 포인터 사용
	printf("바뀐 문자열 : %s\n", str1);

	strcpy(str1, ps2);    //배열을 연결한 포인터 사용
	printf("바뀐 문자열 : %s\n", str1);

	strcpy(str1, "banana");    //문자열 상수 사용
	printf("바뀐 문자열 : %s\n", str1);
	 
	return 0;
}

/*strncpy 함수를 사용한 문자열 복사*/

#include <stdio.h>
#include <string.h>    //strncpy 함수 사용을 위한 헤더 파일 포함

int main(void)
{
	char str[20] = "mango tree";    //배열 초기화

	strncpy(str, "apple-pie", 5);    //"apple-pie"에서 다섯 문자만 복사

	printf("%s\n", str);    //복사 받은 문자열 출력

	return 0;
}

/*strcat, strncat 함수를 사용한 문자열 붙이기*/

#include <stdio.h>
#include <string.h>    //strcat, strncat 함수 사용을 위한 헤더 파일 포함

int main(void)
{
	char str[80] = "straw";    //문자열 초기화

	strcat(str, "berry");    //str 배열에 문자열 붙이기
	printf("%s\n", str);
	strncat(str, "piece", 3);    //str배열에 3개의 문자 붙이기
	printf("%s\n", str);

	return 0;
}

/*두 문자열 중 길이가 긴 단어 출력*/

#include <stdio.h>
#include <string.h>    //strlen 함수 사용을 위한 헤더 파일 포함

int main(void)
{
	char str1[80], str2[80];    //두 문자열을 입력할 배열
	char* resp;    //문자열이 긴 배열을 선택할 포인터

	printf("2개의 과일 이름 입력 : ");   
	scanf("%s%s", str1, str2);    //2개의 문자열 입력
	if (strlen(str1) > strlen(str2))    //배열에 입력된 문자열 길이의 비교
		resp = str1;    //첫 번째 배열이 긴 경우 선택
	else
		resp = str2;    //두 번째 배열이 긴 경우 선택
	printf("이름이 긴 과일은 : %s\n", resp);    //선택된 배열의 문자열 출력

	return 0;
}

/*strcmp, strncmp 함수를 사용한 문자 비교*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[80] = "pear";
	char str2[80] = "peach";

	printf("사전에 나중에 나오는 과일 이름 : ");
	if (strcmp(str1, str2) > 0)    //str1이 str2보다 크면(사전에 나중에 나오면)
		printf("%s\n", str1);    //str1 출력
	else    //str1이 str2보다 크지 않으면
		printf("%s\n", str2);    //str2 출력

	return 0;
}

/*strcpy와 기능이 같은 함수의 구현*/

#include <stdio.h>

char* my_strcpy(char* pd, char* ps);    //함수 선언

int main(void)
{
	char str[80] = "strawberry";

	printf("바꾸기 전 문자열 : %s\n", str);
	my_strcpy(str, "apple");    //문자열 "apple" 복사
	printf("바꾼 후 문자열 : %s\n", str);
	printf("다른 문자열 대입 : %s\n", my_strcpy(str, "kiwi"));    //반환값으로 출력

	return 0;
}

char* my_strcpy(char* pd, char* ps)    //복사 받을 곳(pd)과 복사할 곳(ps)의 포인터
{
	char* po = pd;    //pd 값을 나중에 반환하기 위해 보관

	while (*ps != '\0')    //ps가 가리키는 문자가 널 문자가 아닌 동안
	{
		*pd = *ps;    //ps가 가리키는 문자를 pd가 가리키는 위치에 대입
		pd++;    //복사 받을 다음 위치로 포인터 증가
		ps++;    //복사할 다음 문자의 위치로 포인터 증가
	}
	*pd = '\0';    //복사가 모두 끝난 후 복사 받을 곳에 널 문자로 마무리

	return po;    //복사가 끝난 저장 공간의 시작 주소 반환
}