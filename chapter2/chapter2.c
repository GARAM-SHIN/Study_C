/* �ۼ��� : 
   ���� : 10�� 20�� ���ϴ� ���α׷�*/

int main(void)
{
	10 + 20;

	return 0;
}

/*���ڿ��� ȭ�鿡 ����ϴ� ���α׷�*/

#include <stdio.h>   // stdio : standard input output(ǥ�������)�� ���Ӹ�

int main(void)
{
	printf("Be happy");   //���ڿ� "Be happy" ���
	printf("My friend");  //���ڿ� "My friend" ���

	return 0;
}

/*���� ���ڸ� ����� ���*/

#include <stdio.h>

int main(void)
{
	printf("Be happy\n");   //"Be happy"�� ����ϰ� ���� �ٲ�
	printf("12345678901234567890\n");   //ȭ�鿡 �� ��ȣ�� ����ϰ� ���� �ٲ�
	printf("My\tfriend\n");   //"My"�� ����ϰ� �� ��ġ�� �̵� �Ŀ� "friend"�� ����ϰ� ���� �ٲ�
	printf("Goot\bd\tchance\n");   //t�� d�� �ٲٰ� �� ��ġ�� �̵� �Ŀ� "chance"�� ����ϰ� ���� �ٲ�
	printf("Cow\rW\a\n");    //�� ������ �̵��� C�� W�� �ٲٰ� ���Ҹ��� ���� ���� �ٲ�

	return 0;
}

/*������ �Ǽ��� ���*/

#include <stdio.h>

int main(void)
{
	printf("%d\n", 10);   //%d ��ġ�� 10 ���
	printf("%lf\n", 3.4);    //%lf ��ġ�� 3.4�� �Ҽ��� ���� 6�ڸ����� ���
	printf("%.1lf\n", 3.45);    //�Ҽ��� ���� ù° �ڸ����� ���(�Ѷ� �ڸ����� �ݿø�)
	printf("%.10lf\n", 3.4);   //�Ҽ��� ���� 10�ڸ����� ���

	printf("%d�� %d�� ���� %d�Դϴ�.\n", 10, 20, 10 + 20);
	printf("%.1lf-%.1lf = %.1lf\n", 3.4, 1.2, 3.4 - 1.2);

	return 0;
}

/*�� ���� ������ ���� ���*/

#include <stdio.h>

int main(void)
{
	printf("%d\n", 12);    //10���� ���� ��� ���
	printf("%d\n", 014);    //8���� ���� ��� ���
	printf("%d\n", 0xc);    //16���� ���� ��� ���

	return 0;
}

/*���� ������ �Ǽ� ���*/

#include <stdio.h>

int main(void)
{
	printf("%.1lf\n", 1e6);    //���� ������ �Ǽ��� �Ҽ��� ���·� ���
	printf("%.7lf\n", 3.14e-5);    //�Ҽ��� ���� 7�ڸ����� ���
	printf("%le\n", 0.0000314);    //�Ҽ��� ������ �Ǽ��� ���� ���·� ���
	printf("%.2le\n", 0.0000314);    //���� ���·� �Ҽ��� ���� ��° �ڸ����� ���

	return 0;
}

/*���ڿ� ���ڿ� �������� ���*/

#include <stdio.h>

int main(void)
{
	printf("%c\n", 'A');    //���� ��� ���
	printf("%s\n", "A");    //���ڿ� ��� ���
	printf("%c�� %s�Դϴ�.\n", '1', "first");    //���ڿ� ���ڿ��� �Բ� ���

	return 0;
}