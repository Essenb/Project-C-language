/**********************************************
*	기초프로젝트 게임제작
*   프로젝트명 : Racing Game
*	소스 파일명 : menu.c
*	작성자 : 이승훈( 2조 : 이승훈, 김기훈, 김능환, 권오동, 강예지 )
*	작성일 : 2017.06.08
*	프로그램 설명 : 메뉴 프로그램
**********************************************/

#include "racing_game.h"

int menu()
{
	int select;
	while (1)
	{
		gotoxy(61, 18);
		printf(" 입력 : ");
		scanf_s("%d", &select);

		switch (select)
		{
		case 1:
			gotoxy(36, 20);
			printf("유저 ID : ");		//아이디 입력
			scanf("%s", &User.ID);
			return 0;
		case 2:
			system("cls");
			help();
			return 0;
		case 3:
			return 0;					// 종료
		default:
			gotoxy(68, 18); printf("  ");
		}
	}
}