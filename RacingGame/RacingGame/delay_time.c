/**********************************************
*	기초프로젝트 게임제작
*   프로젝트명 : Racing Game
*	소스 파일명 : delay_time.c
*	작성자 : 2015041002 권오동 ( 2조 : 이승훈, 김기훈, 김능환, 권오동, 강예지 )
*	작성일 : 2017.06.08
*	프로그램 설명 : 대기 시간을 출력하는 함수
**********************************************/
#include"racing_game.h"
void delay_time()	//대기 시간 출력 함수
{	/*3초 출력*/
	boundary();
	gotoxy(20, 9);	printf("■■■■■■■");
	gotoxy(20, 10); printf("□□□□□□■");
	gotoxy(20, 11); printf("□□□□□□■");
	gotoxy(20, 12); printf("■■■■■■■");
	gotoxy(20, 13); printf("□□□□□□■");
	gotoxy(20, 14); printf("□□□□□□■");
	gotoxy(20, 15); printf("■■■■■■■");
	Sleep(900);
	/*2초 출력*/
	boundary();
	gotoxy(20, 9);	printf("■■■■■■■");
	gotoxy(20, 10); printf("□□□□□□■");
	gotoxy(20, 11); printf("□□□□□□■");
	gotoxy(20, 12); printf("■■■■■■■");
	gotoxy(20, 13); printf("■□□□□□□");
	gotoxy(20, 14); printf("■□□□□□□");
	gotoxy(20, 15); printf("■■■■■■■");
	Sleep(1000);
	/*1초 출력*/
	boundary();
	gotoxy(20, 9);	printf("□□□■□□□");
	gotoxy(20, 10); printf("□□■■□□□");
	gotoxy(20, 11); printf("□■□■□□□");
	gotoxy(20, 12); printf("■□□■□□□");
	gotoxy(20, 13); printf("□□□■□□□");
	gotoxy(20, 14); printf("□□□■□□□");
	gotoxy(20, 15); printf("■■■■■■■");
	Sleep(1000);
	/*GO!*/
	gotoxy(20, 9);	printf("□□■■■□□□■■■□□■■");
	gotoxy(20, 10); printf("□■□□□■□■□□□■□■■");
	gotoxy(20, 11); printf("■□□□□□□■□□□■□■■");
	gotoxy(20, 12); printf("■□□■■■□■□□□■□■■");
	gotoxy(20, 13); printf("■□□□□■□■□□□■□■■");
	gotoxy(20, 14); printf("□■□□□■□■□□□■□□□");
	gotoxy(20, 15); printf("□□■■■□□□■■■□□■■");
	Sleep(1000);
}