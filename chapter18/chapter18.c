/*파일을 열고 닫는 프로그램*/

#include <stdio.h>

int main(void)
{
	FILE* fp;    //파일 포인터

	fp = fopen("a.txt", "r");    //a.txt 파일을 읽기 전용으로 개방
	if (fp == NULL)    //fp가 널 포인터면 파일 개방 실패
	{
		printf("파일이 열리지 않았습니다.\n");    //안내 메시지 출력
		return 1;    //프로그램 종료
	}
	printf("파일이 열렸습니다.\n");   
	fclose(fp);    //파일 종료

	return 0;
}

/*파일의 내용을 화면에 출력하기*/

#include <stdio.h>

int main(void)
{
	FILE* fp;    //파일 포인터 선언
	int ch;    //입력한 문자를 저장할 변수

	fp = fopen("a.txt", "r");    //읽기 전용으로 파일 개방
	if (fp == NULL)    //파일이 개방되었는지 확인
	{
		printf("파일이 열리지 않았습니다.\n");
		return 1;
	}

	while (1)
	{
		ch = fgetc(fp);    //개방한 파일에서 문자 입력
		if (ch == EOF)    //함수의 반환값이 EOF면 입력 종료
		{
			break;
		}
		putchar(ch);    //입력한 문자를 화면에 출력
	}
	fclose(fp);    //파일 닫음

	return 0;
}

/*문자열을 한 문자씩 파일로 출력하기*/

#include <stdio.h>

int main(void)
{
	FILE* fp;    //파일 포인터 선언
	char str[] = "banana";    //출력할 문자열
	int i;    //반복 제어 변수

	fp = fopen("b.txt", "w");    //쓰기 전용으로 개방
	if (fp == NULL)    //파일 개방 확인
	{
		printf("파일을 만들지 못했습니다.\n");
		return 1;
	}

	i = 0;    //문자 배열의 첫 번째 문자부터 출력
	while (str[i] != '\0')    //널 문자가 아니면
	{
		fputc(str[i], fp);    //문자를 파일에 출력
		i++;    //다음 문자로 이동
	}
	fputc('\n', fp);
	fclose(fp);    //파일 닫음

	return 0;
}

/*표준 입출력 스트림을 사용한 문자열 입력*/

#include <stdio.h>

int main(void)
{
	int ch;    //입력한 문자를 저장할 변수

	while (1)
	{
		ch = getchar();    //키보드에서 문자 입력
		if (ch == EOF)    //<Ctrl> + <Z>로 입력 종료
		{
			break;
		}
		putchar(ch);    //화면에 문자 출력
	}

	return 0;
}

/*stdin과 stdout을 사용한 문자 입출력*/

#include <stdio.h>

int main(void)
{
	int ch;    //입력한 문자를 저장할 변수

	while (1)
	{
		ch = fgetc(stdin);    //키보드에서 문자 입력
		if (ch == EOF)    //<Ctrl> + <Z>로 입력 종료
		{
			break;
		}
		fputc(ch, stdout);    //화면에 문자 출력
	}

	return 0;
}

/*파일의 형태와 개방 모드가 다른 경우*/

#include <stdio.h>

int main(void)
{
	FILE* fp;
	int ary[10] = { 13,10,13,13,10,26,13,10,13,10 };
	int i, res;

	fp = fopen("a.txt", "wb");    //바이너리 파일로 개방
	for (i = 0; i < 10; i++)
	{
		fputc(ary[i], fp);    //배열 요소의 각 값에 해당하는 아스키 문자 출력
	}
	fclose(fp);    //파일 닫음

	fp = fopen("a.txt", "rt");    //같은 파일을 텍스트 파일로 개방
	while (1)
	{
		res = fgetc(fp);    //파일에서 한 문자 입력
		if (res == EOF) 
			break;
		printf("%4d", res);    //입력한 문자의 아스키 코드 값 출력
	}
	fclose(fp);    //파일 닫음

	return 0;
}

/*a+ 모드로 파일의 내용을 확인하여 출력*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* fp;
	char str[20];

	fp = fopen("a.txt", "a+");    //읽기 가능한 추가 모드로 개방
	if (fp == NULL)    //파일 개방 확인
	{
		printf("파일을 만들지 못했습니다.\n");
		return 1;
	}

	while (1)
	{
		printf("과일 이름 : ");  
		scanf("%s", str);    //키보드로 과일 이름 입력
		if (strcmp(str, "end") == 0)    //end 입력 시 종료
		{
			break;
		}
		else if (strcmp(str, "list") == 0)    //list를 입력하면 파일의 내용 확인
		{
			fseek(fp, 0, SEEK_SET);    //버퍼의 위치 지시자를 맨 처음으로 이동
			while (1)
			{
				fgets(str, sizeof(str), fp);    //과일의 이름을 읽는다.
				if (feof(fp))    //파일의 내용을 모두 읽으면 종료
				{
					break;
				}
				printf("%s", str);    //읽은 과일 이름을 화면 출력
			}
		}
		else {
			fprintf(fp, "%s\n", str);    //입력한 과일 이름을 파일에 출력
		}
	}
	fclose(fp);

	return 0;
}

/*여러 줄의 문장을 입력하여 한 줄로 출력*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* ifp, * ofp;    //파일 포인터 선언
	char str[80];    //입력한 문자열을 저장할 배열
	char* res;    //fgets 함수의 반환값을 저장할 변수

	ifp = fopen("a.txt", "r");    //입력 파일을 읽기 전용으로 개방
	if (ifp == NULL)    //개방 여부 확인
	{
		printf("입력 파일을 열지 못했습니다.\n");
		return 1;
	}

	ofp = fopen("b.txt", "w");    //출력 파일을 쓰기 전용으로 개방
	if (ofp == NULL)    //개방 여부 확인
	{
		printf("출력 파일을 열지 못했습니다.\n");
		return 1;
	}

	while (1)    //문자열을 입력하고 출력하는 과정 반복
	{
		res = fgets(str, sizeof(str), ifp);
		if (res == NULL)    //반환값이 널 포인터면 반복 종료
		{
			break;
		}
		str[strlen(str) - 1] = '\0';    //개형 문자 제거
		fputs(str, ofp);
		fputs(" ", ofp);
	}

	fclose(ifp);    //입력 파일 닫기
	fclose(ofp);    //출력 파일 닫기

	return 0;
}

/*다양한 자료형을 형식에 맞게 입출력*/

#include <stdio.h>

int main(void)
{
	FILE* ifp, * ofp;    //파일 포인터 선언
	char name[20];    //이름
	int kor, eng, math;    //세 과목 점수
	int total;    //총점
	double avg;    //평균
	int res;    //fscanf 함수의 반환값 저장

	ifp = fopen("a.txt", "r");    //입력 파일을 읽기 전용으로 개방
	if (ifp == NULL)    //개방 여부 확인
	{
		printf("입력 파일을 열지 못했습니다.\n");
		return 1;
	}

	ofp = fopen("b.txt", "w");    //출력 파일을 쓰기 전용으로 개방
	if (ofp == NULL)    //개방 여부 확인
	{
		printf("출력 파일을 열지 못했습니다.\n");
		return 1;
	}

	while (1)
	{
		res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math);    //데이터 입력
		if (res == EOF)    //파일의 데이터를 모두 읽으면 EOF 반환
		{
			break;
		}
		total = kor + eng + math;    //총점 계산
		avg = total / 3.0;    //평균 계산
		fprintf(ofp, "%s%5d%7.1f\n", name, total, avg);    //이름, 총점, 평균 출력
	}
	
	fclose(ifp);    //입력 파일 닫기
	fclose(ofp);    //출력 파일 닫기

	return 0;
}

/*버퍼를 공유함으로 인해 발생하는 문제*/

#include <stdio.h>

int main(void)
{
	FILE* fp;    //파일 포인터 
	int age;    //나이 저장 변수
	char name[20];    //이름 저장 배열

	fp = fopen("a.txt", "r");    //파일 개방

	fscanf(fp, "%d", &age);    //나이 입력
	fgets(name, sizeof(name), fp);    //이름 입력

	printf("나이 : %d, 이름 : %s", age, name);    //입력 데이터 출력
	fclose(fp);    //파일 닫음

	return 0;
}

/*fprintf와 fwrite 함수의 차이*/

#include <stdio.h>

int main(void)
{
	FILE* afp, * bfp;
	int num = 10;
	int res;

	afp = fopen("a.txt", "wt");    //텍스트 모드로 출력 파일 개방
	fprintf(afp, "%d", num);    //num의 값을 문자로 반환하여 출력

	bfp = fopen("b.txt", "wb");    //바이너리 모드로 출력 파일 개방
	fwrite(&num, sizeof(num), 1, bfp);    //num의 값을 그대로 파일에 출력

	fcloes(afp);
	fclose(bfp);

	bfp = fopen("b.txt", "rb");    //바이너리 모드로 입력 파일 개방
	fread(&res, sizeof(res), 1, bfp);    //파일의 데이터를 그대로 변수에 입력
	printf("%d", res);    //입력한 데이터 확인

	fclose(bfp);

	return 0;
}