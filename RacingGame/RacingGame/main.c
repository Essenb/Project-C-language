/**********************************************
*	����������Ʈ ��������
*   ������Ʈ�� : Racing Game
*	�ҽ� ���ϸ� : main.c
*	�ۼ��� : �̽���, �ǿ��� ( 2�� : �̽���, �����, ���ȯ, �ǿ���, ������ )
*	�ۼ��� : 2017.05.25
*	���α׷� ���� : ���� ���α׷�
**********************************************/

#include"racing_game.h"

int main()
{
	PlaySound("game_sound.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	//���� ���� ��ġ, �����̸� | ����ϸ鼭 ���� �ڵ� ���� | �ݺ����
	int select;
	Initialize();
	start();

	gotoxy(61, 11);
	printf("***************");
	gotoxy(61, 12);
	printf("*    �޴�     *");
	gotoxy(61, 13);
	printf("***************");
	gotoxy(61, 14);
	printf("*  1. ID�Է�  *");
	gotoxy(61, 15);
	printf("*  2. ����  *");
	gotoxy(61, 16);
	printf("*  3. ����    *");
	gotoxy(61, 17);
	printf("***************");
	
	select = menu();
	if (select == 3)		// 3���Է� �� ����
		return 0;
	system("cls");

	map(car_select());		// �ڵ��� ���� �� ���� ����
	system("cls");
	ranking();

	Sleep(3000);
	system("pause");
	return 0;
}
