/**********************************************
*	기초프로젝트 게임제작
*   프로젝트명 : Racing Game
*	소스 파일명 : car.c
*	작성자 : 2014041019 김능환 ( 2조 : 이승훈, 김기훈, 김능환, 권오동, 강예지 )
*	작성일 : 2017.05.25
*	프로그램 설명 : 자동차 선언 및 선택화면
**********************************************/
// 명품 c언어 프로젝트 p103에서 gotoxy함수 사용 참조

#include"racing_game.h"
void car1();
void car2();
void car3();
void car4();
void algo();

// 순서대로 차 모양, 이름, 현재속도, 최대속도, 가속도, 에너지
r_car s_car01 = { { { "┌△─△┐" },{ "◎      ◎" },{ "││  ││" },{ "◎│  │◎" },{ "└──□┘" },{ "      ∬" } },{ "Yellow" }, 100, 500, 50, 20 };  // 구조체를 사용해 1번 자동차 구현
r_car s_car02 = { { { "◎─＊─◎" },{ "│＊─＊│" },{ "◎───◎" },{ "│＊─＊│" },{ "◎──□◎" },{ "      ∬" } },{ "Plum" }, 100, 600, 30, 15 }; // 구조체를 사용해 2번 자동차 구현
r_car s_car03 = { { { "┌＂─＂┐" },{ "☆÷＂×☆" },{ "☆×＂÷☆" },{ "☆÷＂×☆" },{ "└＂─＂┘" },{ "      ∬" } },{ "SkyBlue" }, 100, 800, 40, 10 }; // 구조체를 사용해 3번 자동차 구현
r_car s_car04 = { { { "△─◇─△" },{ "△─◇─△" },{ "│      │" },{ "○      ○" },{ "↘───↙" },{ "      ∬" } },{ "Green" }, 100, 1000, 50, 5 };   // 구조체를 사용해 4번 자동차 구현

r_car* car_select()
{
	while (1)
	{
		printf("\n                          <  자동차를 선택하세요  >\n\n\n\n");
		gotoxy(3, 4);
		printf("1.");
		gotoxy(22, 4);
		printf("2.");
		gotoxy(41, 4);
		printf("3.");
		gotoxy(60, 4);
		printf("4.");
		algo();
		printf("\n");
		printf("\n");
		printf("\n");
		printf(" 플레이 하고 싶은 자동차를 선택해주세요 : ");
		scanf("%d", &select_car_num);    // 원하는 자동차를 입력

		switch (select_car_num)		// 자동차 선택
		{
		case 1:
			system("cls");
			return &s_car01;
			break;
		case 2:
			system("cls");
			return &s_car02;
			break;
		case 3:
			system("cls");
			return &s_car03;
			break;
		case 4:
			system("cls");
			return &s_car04;
			break;
		default:
			printf("다시 입력해주세요.\n");
			system("pause");
			system("cls");
			break;
		}
	}
}
void algo()      // 자동차 출력 함수 모음
{
	car1();      // 1번 자동차
	car2();      // 2번 자동차
	car3();      // 3번 자동차
	car4();      // 4번 자동차
}
void car1()     // 첫번째 자동차
{
	int k = 6;           // 커서의 열 변수

	gotoxy(3, k++);      // 커서를 3행으로 이동 열은 출력마다 1열씩 증가
	Yellow printf("%s", s_car01.shape[0]);
	gotoxy(3, k++);
	printf("%s", s_car01.shape[1]);   gotoxy(3, k++);
	printf("%s", s_car01.shape[2]);   gotoxy(3, k++);
	printf("%s", s_car01.shape[3]);   gotoxy(3, k++);
	printf("%s", s_car01.shape[4]);   gotoxy(3, k++);
	printf("%s", s_car01.shape[5]);

	k++;								 // 한줄 띄움

	gotoxy(3, k++);
	Gray printf("이름     : %s\n", s_car01.name);
	gotoxy(3, k++);
	printf("최대속도 : %d\n", s_car01.max_speed);
	gotoxy(3, k++);
	printf("가속도   : %d\n", s_car01.acc);
	gotoxy(3, k++);
	printf("에너지   : %d\n", s_car01.energy);
}
void car2()    // 두번째 자동차
{
	int k = 6;

	gotoxy(22, k++);      // 커서를 22행으로 이동 열은 출력마다 1열씩 증가
	Plum printf("%s", s_car02.shape[0]);   gotoxy(22, k++);
	printf("%s", s_car02.shape[1]);   gotoxy(22, k++);
	printf("%s", s_car02.shape[2]);   gotoxy(22, k++);
	printf("%s", s_car02.shape[3]);   gotoxy(22, k++);
	printf("%s", s_car02.shape[4]);   gotoxy(22, k++);
	printf("%s", s_car02.shape[5]);

	k++;								 // 한줄 띄움

	gotoxy(22, k++);
	Gray printf("이름     : %s\n", s_car02.name);
	gotoxy(22, k++);
	printf("최대속도 : %d\n", s_car02.max_speed);
	gotoxy(22, k++);
	printf("가속도   : %d\n", s_car02.acc);
	gotoxy(22, k++);
	printf("에너지   : %d\n", s_car02.energy);
}
void car3()     // 세번째 자동차
{
	int k = 6;

	gotoxy(41, k++);      // 커서를 41행으로 이동 열은 출력마다 1열씩 증가
	Blue printf("%s", s_car03.shape[0]);   gotoxy(41, k++);
	printf("%s", s_car03.shape[1]);   gotoxy(41, k++);
	printf("%s", s_car03.shape[2]);   gotoxy(41, k++);
	printf("%s", s_car03.shape[3]);   gotoxy(41, k++);
	printf("%s", s_car03.shape[4]);   gotoxy(41, k++);
	printf("%s", s_car03.shape[5]);

	k++;								 // 한줄 띄움

	gotoxy(41, k++);
	Gray printf("이름     : %s\n", s_car03.name);
	gotoxy(41, k++);
	printf("최대속도 : %d\n", s_car03.max_speed);
	gotoxy(41, k++);
	printf("가속도   : %d\n", s_car03.acc);
	gotoxy(41, k++);
	printf("에너지   : %d\n", s_car03.energy);
	gotoxy(41, k++);
}
void car4()     // 네번째 자동차
{
	int k = 6;

	gotoxy(60, k++);      // 커서를 60행으로 이동 열은 출력마다 1열씩 증가
	Green printf("%s", s_car04.shape[0]);   gotoxy(60, k++);
	printf("%s", s_car04.shape[1]);   gotoxy(60, k++);
	printf("%s", s_car04.shape[2]);   gotoxy(60, k++);
	printf("%s", s_car04.shape[3]);   gotoxy(60, k++);
	printf("%s", s_car04.shape[4]);   gotoxy(60, k++);
	printf("%s", s_car04.shape[5]);

	k++;								 // 한줄 띄움

	gotoxy(60, k++);
	Gray printf("이름     : %s\n", s_car04.name);
	gotoxy(60, k++);
	printf("최대속도 : %d\n", s_car04.max_speed);
	gotoxy(60, k++);
	printf("가속도   : %d\n", s_car04.acc);
	gotoxy(60, k++);
	printf("에너지   : %d\n", s_car04.energy);
	gotoxy(60, k++);
}