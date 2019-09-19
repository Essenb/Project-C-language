/**********************************************
*	기초프로젝트 게임제작
*   프로젝트명 : Racing Game
*	소스 파일명 : main.c
*	작성자 : 이승훈, 권오동 ( 2조 : 이승훈, 김기훈, 김능환, 권오동, 강예지 )
*	작성일 : 2017.05.25
*	프로그램 설명 : 메인 프로그램
**********************************************/

#include"racing_game.h"

int main()
{
	PlaySound("game_sound.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	//사운드 파일 위치, 파일이름 | 재생하면서 다음 코드 실행 | 반복재생
	int select;
	Initialize();
	start();

	gotoxy(61, 11);
	printf("***************");
	gotoxy(61, 12);
	printf("*    메뉴     *");
	gotoxy(61, 13);
	printf("***************");
	gotoxy(61, 14);
	printf("*  1. ID입력  *");
	gotoxy(61, 15);
	printf("*  2. 도움말  *");
	gotoxy(61, 16);
	printf("*  3. 종료    *");
	gotoxy(61, 17);
	printf("***************");
	
	select = menu();
	if (select == 3)		// 3번입력 시 종료
		return 0;
	system("cls");

	map(car_select());		// 자동차 선택 후 게임 진행
	system("cls");
	ranking();

	Sleep(3000);
	system("pause");
	return 0;
}
