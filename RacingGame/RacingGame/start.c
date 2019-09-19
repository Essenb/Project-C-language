/**********************************************
*	기초프로젝트 게임제작
*   프로젝트명 : Racing Game
*	소스 파일명 : start.c
*	작성자 : 2016039083 강예지 (2조 : 이승훈 강예지 김기훈 김능환 권오동)
*	작성일 : 2017.05.25
*	프로그램 설명 : 시작 화면 출력 함수
**********************************************/

#include "racing_game.h"

void start()
{
	int i;
	char str[100] = " ↗〓〓〓〓";
	char str2[200] = "[ ☆   #▤# ]⊃  =3 =3   ";
	char str3[100] = "[ ★   #▤# ]⊃  =3 =3   ";
	char str4[100] = " ↘〓〓〓〓";

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

		removeCursor();			// 커서 깜빡임 제거
	}
}
