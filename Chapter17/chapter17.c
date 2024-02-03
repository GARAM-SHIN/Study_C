/*구조체를 선언하고 멤버를 사용하는 방법*/

#include <stdio.h>

struct student    //구조체 선언
{
	int num;    //int형 멤버
	double grade;    //double형 멤버
};    //세미콜론 사용

int main(void)
{
	struct student s1;    //struct student형의 변수 선언

	s1.num = 2;    //s1의 num 멤버에 2 저장
	s1.grade = 2.7;    //s1의 grade 멤버에 2.7 저장
	printf("학번 : %d\n", s1.num);    //num 멤버 출력
	printf("학점 : %.1lf\n", s1.grade);    //grade 멤버 출력

	return 0;
}

/*배열과 포인터를 멤버로 갖는 구조체 사용*/

#include <stdio.h>   
#include <stdlib.h>
#include <string.h>

struct profile    //신상명세 구조체 선언
{
	char name[20];    //이름을 저장할 배열 멤버
	int age;    //나이
	double height;    //키
	char* intro;    //자기소개를 위한 포인터
};

int main(void)
{
	struct profile yuni;    //profile 구조체 변수 선언

	strcpy(yuni.name, "서하윤");    //name 배열 멤버에 이름 복사
	yuni.age = 17;    //age 멤버에 나이 저장
	yuni.height = 164.5;    //height 멤버에 키 저장

	yuni.intro = (char*)malloc(80);    //자기소개를 저장할 공간 동적 할당
	printf("자기소개 : ");  
	gets(yuni.intro);    //할당한 공간에 자기소개 입력

	printf("이름 : %s\n", yuni.name);    //각 멤버의 데이터 출력
	printf("나이 : %d\n", yuni.age);
	printf("키 : %.1lf\n", yuni.height);
	printf("자기소개 : %s\n", yuni.intro);
	free(yuni.intro);    //동적 할당 영역 반환

	return 0;
}

/*다른 구조체를 멤버로 갖는 구조체 사용*/

#include <stdio.h>

struct profile    //신상명세 구조체 선언
{
	int age;    //나이
	double height;    //키
};

struct student
{
	struct profile pf;    //profile 구조체를 멤버로 사용
	int id;    //학번을 저장할 멤버
	double grade;    //학점을 저장할 멤버
};

int main(void)
{
	struct student yuni;    //student 구조체 변수 선언

	yuni.pf.age = 17;    //pf 멤버의 age 멤버에 나이 저장
	yuni.pf.height = 164.5;    // pf 멤버의 heigth 멤버에 키 저장
	yuni.id = 315;
	yuni.grade = 4.3;

	printf("나이 : %d\n", yuni.pf.age);    //pf 멤버의 age 멤버 출력
	printf("키 : %.1lf\n", yuni.pf.height);    //pf 멤버의 height 멤버 출력
	printf("학번 : %d\n", yuni.id);    //id 멤버 출력
	printf("학점 : %d\n", yuni.grade);    //grade 멤버 출력

	return 0;
}

/*최고 학점의 학생 데이터 출력*/

#include <stdio.h>

struct student    //학생 구조체 선언
{
	int id;    //학번
	char name[20];    //이름
	double grade;    //학점
};

int main(void)
{
	struct student s1 = { 315, "홍길동", 2.4 }, s2 = { 316, "이순신", 3.7 }, s3 = { 317, "세종대왕", 4.4 };    //구조체 변수 선언과 초기화

	struct student max;    //최고 학점을 저장할 구조체 변수

	max = s1;    //s1을 최고 학점으로 가정
	if (s2.grade > max.grade) max = s2;    //s2가 더 높으면 max에 대입
	if (s3.grade > max.grade) max = s3;    //s3가 더 높으면 max에 대입

	printf("학번 : %d\n", max.id);    //최고 학점 학생의 학번 출력
	printf("이름 : %s\n", max.name);    //최고 학점 학생의 이름 출력
	printf("학점 : %.1lf\n", max.grade);    //최고 학점 학생의 학점 출력

	return 0;
}

/*구조체를 반환하여 두 변수의 값 교환*/

#include <stdio.h>

struct vision    //로봇의 시력을 저장할 구조체
{
	double left;    //왼쪽 눈
	double right;    //오른쪽 눈
};

struct vision exchange(struct vision robot);    //두 시력을 바꾸는 함수

int main(void)
{
	struct vision robot;    //구조체 변수 선언

	print("시력 입력 : ");
	scanf("%lf%lf", &(robot.left), &(robot.right));    //시력 입력
	robot = exchange(robot);    //교환 함수 호출
	printf("바뀐 시력 : %.1lf %.1lf\n", robot.left, robot.right);

	return 0;
}

struct vision exchange(struct vision robot)    //구조체를 반환하는 함수
{
	double temp;    //교환을 위한 임시 변수

	temp = robot.left;    //좌우 시력 교환
	robot.left = robot.right;
	robot.right = temp;

	return robot;    //구조체 변수 반환
}

/*구조체 포인터의 사용*/

#include <stdio.h>

struct score    //구조체 선언
{
	int kor;    //국어 점수를 저장할 멤버
	int eng;    //영어 점수
	int math;    //수학 점수
};

int main(void)
{
	struct score yuni = { 90,80,70 };    //구조체 변수 선언과 초기화
	struct score* ps = &yuni;    //구조체 포인터에 주소 저장

	printf("국어 : %d\n", (*ps).kor);    //구조체 포인터로 멤버 접근
	printf("영어 : %d\n", ps->eng);    //-> 연산자 사용
	printf("수학 : %d\n", ps->math);

	return 0;
}

/*구조체 배열을 초기화하고 출력*/

#include <stdio.h>

struct address    //주소록을 만들 구조체 선언
{
	char name[20];    //이름을 저장할 멤버
	int age;    //나이를 저장할 멤버
	char tel[20];    //전화번호를 저장할 멤버
	char addr[80];    //주소를 저장할 멤버
};

int main(void)
{
	struct address list[5] = {    //요소가 5개인 구조체 배열 선언
		{"홍길동", 23, "111-1111", "울릉도 독도"},
		{"이순신", 35, "222-2222", "서울 건천동"},
		{"장보고",19,"333-3333","완도 청해진"},
		{"유관순", 15, "444-4444", "충남 천안"},
		{"안중근", 45, "555-5555","황해도 해주"}
	};
	int i;

	for (i = 0; i < 5; i++)    //배열 요소 수만큼 반복
	{
		printf("%10s%5d%15s%20s\n", list[i].name, list[i].tel, list[i].addr);    //각 배열 요소의 멤버 출력
	}

	return 0;
}

/*함수에서 -> 연산자를 사용하여 구조체 배열의 값 출력*/

#include <stdio.h>

struct address    //주소록을 만들 구조체 선언
{
	char name[20];    //이름을 저장할 멤버
	int age;    //나이를 저장할 멤버
	char tel[20];    //전화번호를 저장할 멤버
	char addr[80];    //주소를 저장할 멤버
};

void print_list(struct address* lp);

int main(void)
{
	struct address list[5] = {    //요소가 5개인 구조체 배열 선언
		{"홍길동", 23, "111-1111", "울릉도 독도"},
		{"이순신", 35, "222-2222", "서울 건천동"},
		{"장보고",19,"333-3333","완도 청해진"},
		{"유관순", 15, "444-4444", "충남 천안"},
		{"안중근", 45, "555-5555","황해도 해주"}
	};

	print_list(list);

	return 0;
}

void print_list(struct address* lp)    //매개변수는 구조체 포인터
{
	int i;    //반복 제어 변수

	for (i = 0; i < 5; i++)    //배열 요소의 개수 만큼 반복
	{
		printf("%10s%5d%15s%20s\n", (lp + i)->name, (lp + i)->age, (lp + i)->tel, (lp + i)->addr);    //각 배열 요소의 멤버 출력
	}
}

/*자기 참조 구조체로 list 만들기*/

#include <stdio.h>

struct list    //자기 참조 구조체
{
	int num;    //데이터를 저장하는 멤버
	struct list* next;    //구조체 자신을 가리키는 포인터 멤버
};

int main(void)
{
	struct list a = { 10,0 }, b = { 20,0 }, c = { 30,0 };    //구조체 변수 초기화
	struct list* head = &a, * current;    //헤드 포인터 초기화

	a.next = &b;    //a의 포인터 멤버가 b를 가리킴
	b.next = &c;    //b의 포인터 멤버가 c를 가리킴

	printf("head->num : %d\n", head->num);    //head가 가리키는 a의 num 멤버 사용
	printf("head->next->num : %d\n", head->next->num);    //head로 b의 num 멤버 사용

	printf("list all : ");
	current = head;    //최초 current 포인터가 a를 가리킴
	while (current != NULL)    //마지막 구조체 변수까지 출력하면 반복 종료
	{
		printf("%d  ", current->num);    //current가 가리키는 구조체 변수의 num 출력 
		current = current->next;    //current가 다음 구조체 변수를 가리키도록 함
	}
	printf("\n");

	return 0;
}

/*공용체를 사용한 학번과 학점 데이터 처리*/

#include <stdio.h>

union student    //공용체 선언
{
	int num;    //학번을 저장할 멤버
	double grade;    //학점을 저장할 멤버
};

int main(void)
{
	union student s1 = { 315 };    //공용체 변수의 선언과 초기화

	printf("학번 : %d\n", s1.num);    //학번 멤버 출력
	s1.grade = 4.4;    //학점 멤버에 값 대입
	printf("학점 : %.1lf\n", s1.grade);  
	printf("학번 : %d\n", s1.num);    //학번 다시 출력

	return 0;
}

/*열거형을 사용한 프로그램*/

#include <stdio.h>

enum season {SPRING, SUMMER, FALL, WINTER};    //열거형 선언

int main(void)
{
	enum season ss;    //열거형 변수 선언
	char* pc = NULL;    //문자열을 저장할 포인터

	ss = SPRING;    //열거 멤버의 값 대입
	switch (ss)    //열거 멤버 판단
	{
	case SPRING:    //봄이면
		pc = "inline";    //인라인 문자열 선택
		break;
	case SUMMER:    //여름이면
		pc = "swimming";    //수영 문자열 선택
		break;
	case FALL:    //가을이면
		pc = "trip";    //여행 문자열 선택
		break;
	case WINTER:    //겨울이면
		pc = "skiing";    //스키 문자열 선택
		break;
	}
	printf("나의 레저 활동 => %s\n", pc);    //선택된 문자열 출력 

	return 0;
}

/*typedef를 사용한 자료형 재정의*/

#include <stdio.h>

struct student
{
	int num;
	double grade;
};

typedef struct student Student;    //Student형으로 재정의
void print_data(Student* ps);    //매개변수는 Student형의 포인터

int main(void)
{
	Student s1 = { 315,4.2 };    //Student형의 변수 선언과 초기화

	print_data(&s1);    //Student형 변수의 주소 전달

	return 0;
}

void print_data(Student* ps)
{
	printf("학번 : %d\n", ps->num);    //Student 포인터로 멤버 접근
	printf("학점 : %.1lf\n", ps->grade);
}