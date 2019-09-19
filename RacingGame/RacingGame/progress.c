/**********************************************
*	기초프로젝트 게임제작
*   프로젝트명 : Racing Game
*	소스 파일명 : progress.c
*	작성자 : 이승훈, 김기훈, 권오동 ( 2조 : 이승훈, 김기훈, 김능환, 권오동, 강예지 )
*	작성일 : 2017.05.25
*	프로그램 설명 : 게임 진행 구현
**********************************************/

#include"racing_game.h"
void boundary();
void gotoxy(int x, int y);
void map(r_car *s_car);

void map(r_car *s_car)
{
	int random = rand() % 3 - 1;;
	int i, j, position_car, key;
	int x[20];
	int timer = 30000;				// 게임 속도를 조절할 변수
	int energy = s_car->energy;		// 진행화면에 나타낼 에너지 수치
	srand((unsigned)time(NULL));

	/*초기화*/
	x[19] = 16 + random;
	for (i = 19; i > 0; i--)
	{
			x[i - 1] = x[i];
	}
	position_car = x[13] + 4;

	delay_time();		// 카운트 출력
	system("cls");
	boundary();			// 경계선 출력
	

	/* 에너지가 0보다 작아지면 종료 */
	while (energy > 0)
	{
		/* 방향키 입력 되면 자동차 위치 변경*/
		if (_kbhit())
		{
			key = _getch();
			if (key == 224 || key == 0)
			{
				key = _getch();
				switch (key)
				{
				case 75: //'←'가 입력되면
					position_car--; //왼쪽으로 한칸 이동
					if (position_car <= 3)	//왼쪽경계선을 넘어가려고 하면
						position_car = 3;
					/****************************자동차 위치 제거**********/
					gotoxy(position_car, 16); printf("%s", "           ");
					gotoxy(position_car, 17); printf("%s", "           ");
					gotoxy(position_car, 18); printf("%s", "           ");
					gotoxy(position_car, 19); printf("%s", "           ");
					gotoxy(position_car, 20); printf("%s", "           ");
					gotoxy(position_car, 21); printf("%s", "           ");
					break;
				case 77: //'→/가 입력되면
					position_car++;
					if (position_car + 9 >= 42)	//오른쪽경계선을 넘어가려고 하면
						position_car = 42 - 9;	//오른쪽경계선의 좌표와 자동차의 길이를 뺌
					/****************************자동차 위치 제거**********/
					gotoxy(position_car, 16); printf("%s", "           ");
					gotoxy(position_car, 17); printf("%s", "           ");
					gotoxy(position_car, 18); printf("%s", "           ");
					gotoxy(position_car, 19); printf("%s", "           ");
					gotoxy(position_car, 20); printf("%s", "           ");
					gotoxy(position_car, 21); printf("%s", "           ");
					break;
				default:
					break;
				}
			}
		}
		
		/************************자동차 출력************************/
		switch (select_car_num)
		{
		case 1:
			gotoxy(position_car, 16); Yellow printf("%s", s_car->shape[0]);
			gotoxy(position_car, 17); printf("%s", s_car->shape[1]);
			gotoxy(position_car, 18); printf("%s", s_car->shape[2]);
			gotoxy(position_car, 19); printf("%s", s_car->shape[3]);
			gotoxy(position_car, 20); printf("%s", s_car->shape[4]);
			gotoxy(position_car, 21); printf("%s", s_car->shape[5]);
			break;
		case 2:
			gotoxy(position_car, 16); Plum printf("%s", s_car->shape[0]);
			gotoxy(position_car, 17); printf("%s", s_car->shape[1]);
			gotoxy(position_car, 18); printf("%s", s_car->shape[2]);
			gotoxy(position_car, 19); printf("%s", s_car->shape[3]);
			gotoxy(position_car, 20); printf("%s", s_car->shape[4]);
			gotoxy(position_car, 21); printf("%s", s_car->shape[5]);
			break;
		case 3:
			gotoxy(position_car, 16); Blue printf("%s", s_car->shape[0]);
			gotoxy(position_car, 17); printf("%s", s_car->shape[1]);
			gotoxy(position_car, 18); printf("%s", s_car->shape[2]);
			gotoxy(position_car, 19); printf("%s", s_car->shape[3]);
			gotoxy(position_car, 20); printf("%s", s_car->shape[4]);
			gotoxy(position_car, 21); printf("%s", s_car->shape[5]);
			break;
		case 4:
			gotoxy(position_car, 16); Green printf("%s", s_car->shape[0]);
			gotoxy(position_car, 17); printf("%s", s_car->shape[1]);
			gotoxy(position_car, 18); printf("%s", s_car->shape[2]);
			gotoxy(position_car, 19); printf("%s", s_car->shape[3]);
			gotoxy(position_car, 20); printf("%s", s_car->shape[4]);
			gotoxy(position_car, 21); printf("%s", s_car->shape[5]);
			break;
		}
		/************************자동차 출력************************/

		/*맵 출력*/
		for (j = 0; j < 20; j++)
		{

			gotoxy(x[j], j + 2);
			Gray printf("[");
			gotoxy(x[j] + 17, j + 2);
			printf("]");
		}

		/*피격 판정 계산*/
		if (position_car <= x[19] || position_car <= x[18] || position_car <= x[17] || position_car <= x[16]
			|| position_car <= x[15] || position_car <= x[14])
		{
			energy--;		//왼쪽 장애물에 닿았을 경우의 피격계산
			s_car->speed -= s_car->acc * 3;	//속도 감소
			if (s_car->speed <= 1)	//속도가 음수가 되려하면
				s_car->speed = 100;	//초기속도로 재설정
		}
		if (position_car + 9 >= x[19] + 17 || position_car + 9 >= x[18] + 17 || position_car + 9 >= x[17] + 17 || position_car + 9 >= x[16] + 17
			|| position_car + 9 >= x[15] + 17 || position_car + 9 >= x[14] + 17)
		{
			energy--;		//오른쪽 장애물에 닿았을 경우의 피격계산
			s_car->speed -= s_car->acc * 3;	//속도 감소
			if (s_car->speed <= 1)	//속도가 음수가 되려하면
				s_car->speed = 100;	//초기속도로 재설정
		}

		/* 게임 진행 현황판 출력 */
		gotoxy(28, 24);
		printf("Copyright 2017. Continue(2조) all rights reserved.");
		gotoxy(55, 2);
		printf("    %c%c Racing Game %c%c", 0xa1, 0xbc, 0xa1, 0xbd);
		gotoxy(55, 3);
		printf("                 ver 3.0");
		gotoxy(55, 5);
		printf(" 에너지");
		gotoxy(55, 6);
		printf("                   %d  ", energy);
		gotoxy(55, 8);
		printf(" 속도");
		gotoxy(55, 9);
		printf("                   %d  ", s_car->speed);
		gotoxy(55, 11);
		printf(" 점수");
		gotoxy(55, 12);
		printf("                   %d", User.score);

		gotoxy(55, 15); printf("     %c%c Car info %c%c", 0xa1, 0xba, 0xa1, 0xbb);
		gotoxy(55, 17); printf("  이름      :  %s", s_car->name);
		gotoxy(55, 18); printf("  최대속도  :  %d", s_car->max_speed);
		gotoxy(55, 19); printf("  가속도    :  %d", s_car->acc);
		gotoxy(55, 20); printf("  에너지    :  %d", s_car->energy);

		/*화면 초기화*/
		Sleep(timer / s_car->speed);
		for (j = 0; j < 20; j++)
		{
			gotoxy(x[j], j + 2);
			printf(" ");
			gotoxy(x[j] + 17, j + 2);
			printf(" ");
		}
		removeCursor();

		/* 게임 진행 현황판 처리 */
		User.score++;							// 점수 증가
		if (s_car->speed <= s_car->max_speed)	// 속도 증가
			s_car->speed += s_car->acc;
		if (s_car->speed >= s_car->max_speed)	//최대 속도를 넘어서면
			s_car->speed = s_car->max_speed;	//최대 속도로 제한

		/*다음 맵 준비*/
		for (i = 19; i > 0; i--)
		{
			x[i] = x[i - 1];
		}
		while (1)//경계 조건
		{
			random = rand() % 3 - 1;
			x[0] = x[1] + random;
			if (x[0] >= 3 && x[0] <= 35)
				break;
		}
	}
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void boundary()							// 경계선
{
	unsigned char a = 0xa6, b[12], i;
	int j = 25;
	for (i = 1; i < 12; i++)
		b[i] = 0xa0 + i;

	gotoxy(1, 1);
	printf("%c%c", a, b[3]);
	while (j)
	{
		printf("%c%c", a, b[1]);
		j--;
	}
	printf("%c%c", a, b[8]);
	printf("\n");
	j = 2;
	while (j < 22)
	{
		printf("%c%c", a, b[2]);
		gotoxy(53, j);
		printf("%c%c", a, b[2]);
		printf("\n");
		j++;
	}
	j = 25;
	printf("%c%c", a, b[6]);
	while (j)
	{
		printf("%c%c", a, b[1]);
		j--;
	}
	printf("%c%c", a, b[10]);

	j = 12;
	while (j)
	{
		printf("%c%c", a, b[1]);
		j--;
	}
	printf("%c%c", a, b[5]);
	j = 21;
	while (j>1)
	{
		gotoxy(79, j);
		printf("%c%c", a, b[2]);
		j--;
	}
	gotoxy(55, 1);
	j = 12;
	while (j)
	{
		printf("%c%c", a, b[1]);
		j--;
	}
	printf("%c%c", a, b[4]);
	gotoxy(53, 4);
	printf("%c%c", a, b[7]);
	j = 12;
	while (j)
	{
		printf("%c%c", a, b[1]);
		j--;
	}
	printf("%c%c", a, b[9]);
	gotoxy(53, 7);
	printf("%c%c", a, b[7]);
	j = 12;
	while (j)
	{
		printf("%c%c", a, b[1]);
		j--;
	}
	printf("%c%c", a, b[9]);
	gotoxy(53, 10);
	printf("%c%c", a, b[7]);
	j = 12;
	while (j)
	{
		printf("%c%c", a, b[1]);
		j--;
	}
	printf("%c%c", a, b[9]);
	gotoxy(53, 13);
	printf("%c%c", a, b[7]);
	j = 12;
	while (j)
	{
		printf("%c%c", a, b[1]);
		j--;
	}
	printf("%c%c", a, b[9]);
}