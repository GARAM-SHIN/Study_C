/*scanf함수를 사용한 키보드 입력*/

#include <stdio.h>

int main(void)
{
	int a;

	scanf_s("%d", &a);    //여기서 변수 a에 값 입력
	printf("입력된 값 : %d\n", a);    //입력한 값 출력

	return 0;
}

/*scanf함수를 사용한 연속 입력*/

#include <stdio.h>

int main(void)
{
	int age;    //나이는 정수형
	double height;    //키는 실수형

	printf("나이와 키를 입력하세요 : ");    //입력 안내 메시지 출력
	scanf("%d&lf", &age, &height);    //나이와 키를 함께 입력
	printf("나이는 %d살, 키는 %.1lfcm입니다\n", age, height);    //입력값 출력

	return 0;
}

/*문자와 문자열 입력*/

#include <stdio.h>

int main(void)
{
	char grade;    //학점을 입력할 변수
	char name[20];    //이름을 입력할 배열

	printf("학점 입력 : ");
	scanf("%c", &grade);    //grade 변수에 학점 문자 입력
	printf("이름 입력 : ");
	scanf("%s", name);    //name 배열에 이름 문자열 입력, &를 사용하지 않는다.
	printf("%s의 학점은 %c입니다.\n", name, grade);

	return 0;
}