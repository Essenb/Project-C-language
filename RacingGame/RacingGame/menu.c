/**********************************************
*	����������Ʈ ��������
*   ������Ʈ�� : Racing Game
*	�ҽ� ���ϸ� : menu.c
*	�ۼ��� : �̽���( 2�� : �̽���, �����, ���ȯ, �ǿ���, ������ )
*	�ۼ��� : 2017.06.08
*	���α׷� ���� : �޴� ���α׷�
**********************************************/

#include "racing_game.h"

int menu()
{
	int select;
	while (1)
	{
		gotoxy(61, 18);
		printf(" �Է� : ");
		scanf_s("%d", &select);

		switch (select)
		{
		case 1:
			gotoxy(36, 20);
			printf("���� ID : ");		//���̵� �Է�
			scanf("%s", &User.ID);
			return 0;
		case 2:
			system("cls");
			help();
			return 0;
		case 3:
			return 0;					// ����
		default:
			gotoxy(68, 18); printf("  ");
		}
	}
}