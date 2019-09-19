/**********************************************
*	����������Ʈ ��������
*   ������Ʈ�� : Racing Game
*	�ҽ� ���ϸ� : removeCursor.c
*	�ۼ��� : 2013041010 ����� (2�� : �̽��� ������ ����� ���ȯ �ǿ���)
*	�ۼ��� : 2017.06.08
*	���α׷� ���� : Ŀ�� ������ ���� �Լ�
**********************************************/

#include "racing_game.h"

void removeCursor(void) // Ŀ�� ������ ����
{
	CONSOLE_CURSOR_INFO cur;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
	cur.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}