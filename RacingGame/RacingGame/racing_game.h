/**********************************************
*	����������Ʈ ��������
*   ������Ʈ�� : Racing Game
*	�ҽ� ���ϸ� : racing_game.h
*	�ۼ��� : �̽���, �����, ���ȯ, �ǿ���, ������
*	�ۼ��� : 2017.05.25
*	���α׷� ���� : ��� ���α׷�
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

int select_car_num;             // �ڵ��� ������ ���� ����

/* �ܼ�â ���� ��ȯ */
#define COL GetStdHandle(STD_OUTPUT_HANDLE)
#define Plum SetConsoleTextAttribute(COL, 0x000d);
#define Gray SetConsoleTextAttribute(COL, 0x0007);
#define Yellow SetConsoleTextAttribute(COL, 0x000e);
#define Blue SetConsoleTextAttribute(COL, 0x000b);
#define Green SetConsoleTextAttribute(COL, 0x000a);

/* �ڵ��� ����ü ���� */
typedef struct car
{
	char shape[20][20];
	char name[8];
	int speed;
	int max_speed;
	int acc;
	int energy;
}r_car;

/* �ڵ��� ����*/
extern r_car s_car01;
extern r_car s_car02;
extern r_car s_car03;
extern r_car s_car04;

/* ���� �̸� ����*/
typedef struct {
	char ID[20];
	int score;
}USER; //���������� ������ ����ü

USER User; //���� ����
USER User_Rank[5]; //1��~5��(��ŷ�Ǿ� �ִ� ������)

/*�ڵ��� �ڵ� �Լ�*/
void car1();
void car2();
void car3();
void car4();
void algo();
r_car* car_select();

/* ���̵� �������� �Լ� */
void boundary();
void gotoxy(int x, int y);
void map(r_car *);
void delay_time();

/* ����ȭ�� �Լ� */
void start();		
void help();		

/* ��ŷ ���� �Լ� */
void Initialize();
void ranking();

/* Ŀ�� ������ ���� �Լ� */
void removeCursor();