/**********************************************
*	����������Ʈ ��������
*   ������Ʈ�� : Racing Game
*	�ҽ� ���ϸ� : start.c
*	�ۼ��� : 2016039083 ������ (2�� : �̽��� ������ ����� ���ȯ �ǿ���)
*	�ۼ��� : 2017.05.25
*	���α׷� ���� : ���� ȭ�� ��� �Լ�
**********************************************/

#include "racing_game.h"

void start()
{
	int i;
	char str[100] = " �֡����";
	char str2[200] = "[ ��   #��# ]��  =3 =3   ";
	char str3[100] = "[ ��   #��# ]��  =3 =3   ";
	char str4[100] = " �١����";

	gotoxy(6, 2);
	for (i = 6; i<76; i++)
	{
		Yellow printf("*");
		Sleep(5);
	}
	for (i = 75; i >= 6; i--)
	{
		gotoxy(i, 10);
		Yellow printf("*");
		Sleep(5);
	}
	gotoxy(13, 4);
	Plum printf(" _____            _              _____                 ");
	gotoxy(13, 5);
	Plum printf("| __  | ___  ___ |_| ___  ___   |   __| ___  _____  ___ ");
	gotoxy(13, 6);
	Plum printf("|    -|| .'||  _|| ||   || . |  |  |  || .'||     || -_|");
	gotoxy(13, 7);
	Plum printf("|__|__||__,||___||_||_|_||_  |  |_____||__,||_|_|_||___|");
	gotoxy(13, 8);
	Plum printf("                         |___|                          ");

	for (int i = 0; i < 45; i++)
	{
		gotoxy(50 - i, 12);
		Gray printf("%s", str);
		Sleep(3);

		gotoxy(50 - i, 13);
		printf("%s", str2);
		Sleep(3);

		gotoxy(50 - i, 14);
		printf("%s", str3);
		Sleep(3);

		gotoxy(50 - i, 15);
		printf("%s", str4);
		Sleep(30);

		removeCursor();			// Ŀ�� ������ ����
	}
}
