/**********************************************
*	����������Ʈ ��������
*   ������Ʈ�� : Racing Game
*	�ҽ� ���ϸ� : delay_time.c
*	�ۼ��� : 2015041002 �ǿ��� ( 2�� : �̽���, �����, ���ȯ, �ǿ���, ������ )
*	�ۼ��� : 2017.06.08
*	���α׷� ���� : ��� �ð��� ����ϴ� �Լ�
**********************************************/
#include"racing_game.h"
void delay_time()	//��� �ð� ��� �Լ�
{	/*3�� ���*/
	boundary();
	gotoxy(20, 9);	printf("��������");
	gotoxy(20, 10); printf("��������");
	gotoxy(20, 11); printf("��������");
	gotoxy(20, 12); printf("��������");
	gotoxy(20, 13); printf("��������");
	gotoxy(20, 14); printf("��������");
	gotoxy(20, 15); printf("��������");
	Sleep(900);
	/*2�� ���*/
	boundary();
	gotoxy(20, 9);	printf("��������");
	gotoxy(20, 10); printf("��������");
	gotoxy(20, 11); printf("��������");
	gotoxy(20, 12); printf("��������");
	gotoxy(20, 13); printf("��������");
	gotoxy(20, 14); printf("��������");
	gotoxy(20, 15); printf("��������");
	Sleep(1000);
	/*1�� ���*/
	boundary();
	gotoxy(20, 9);	printf("��������");
	gotoxy(20, 10); printf("��������");
	gotoxy(20, 11); printf("��������");
	gotoxy(20, 12); printf("��������");
	gotoxy(20, 13); printf("��������");
	gotoxy(20, 14); printf("��������");
	gotoxy(20, 15); printf("��������");
	Sleep(1000);
	/*GO!*/
	gotoxy(20, 9);	printf("����������������");
	gotoxy(20, 10); printf("����������������");
	gotoxy(20, 11); printf("����������������");
	gotoxy(20, 12); printf("����������������");
	gotoxy(20, 13); printf("����������������");
	gotoxy(20, 14); printf("����������������");
	gotoxy(20, 15); printf("����������������");
	Sleep(1000);
}