/**********************************************
*	기초프로젝트 게임제작
*   프로젝트명 : Racing Game
*	소스 파일명 : removeCursor.c
*	작성자 : 2013041010 김기훈 (2조 : 이승훈 강예지 김기훈 김능환 권오동)
*	작성일 : 2017.06.08
*	프로그램 설명 : 커서 깜빡임 제거 함수
**********************************************/

#include "racing_game.h"

void removeCursor(void) // 커서 깜빡임 제거
{
	CONSOLE_CURSOR_INFO cur;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
	cur.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}