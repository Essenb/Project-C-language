/**********************************************
*	기초프로젝트 게임제작
*   프로젝트명 : Racing Game
*	소스 파일명 : racing_game.h
*	작성자 : 이승훈, 김기훈, 김능환, 권오동, 강예지
*	작성일 : 2017.05.25
*	프로그램 설명 : 헤더 프로그램
**********************************************/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <mmsystem.h>
#include <conio.h>
#pragma comment(lib,"winmm")

int select_car_num;             // 자동차 선택을 위한 변수

/* 콘솔창 색깔 변환 */
#define COL GetStdHandle(STD_OUTPUT_HANDLE)
#define Plum SetConsoleTextAttribute(COL, 0x000d);
#define Gray SetConsoleTextAttribute(COL, 0x0007);
#define Yellow SetConsoleTextAttribute(COL, 0x000e);
#define Blue SetConsoleTextAttribute(COL, 0x000b);
#define Green SetConsoleTextAttribute(COL, 0x000a);

/* 자동차 구조체 선언 */
typedef struct car
{
	char shape[20][20];
	char name[8];
	int speed;
	int max_speed;
	int acc;
	int energy;
}r_car;

/* 자동차 선언*/
extern r_car s_car01;
extern r_car s_car02;
extern r_car s_car03;
extern r_car s_car04;

/* 유저 이름 저장*/
typedef struct {
	char ID[20];
	int score;
}USER; //유저정보를 저장할 구조체

USER User; //현재 유저
USER User_Rank[5]; //1위~5위(랭킹되어 있는 유저들)

/*자동차 코드 함수*/
void car1();
void car2();
void car3();
void car4();
void algo();
r_car* car_select();

/* 맵이동 게임진행 함수 */
void boundary();
void gotoxy(int x, int y);
void map(r_car *);
void delay_time();

/* 시작화면 함수 */
void start();		
void help();		

/* 랭킹 관련 함수 */
void Initialize();
void ranking();

/* 커서 깜빡임 제거 함수 */
void removeCursor();