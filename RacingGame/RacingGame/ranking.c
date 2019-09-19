/**********************************************
*	����������Ʈ ��������
*   ������Ʈ�� : Racing Game
*	�ҽ� ���ϸ� : ranking.c
*	�ۼ��� : 2016039083 ������ (2�� : �̽��� ������ ����� ���ȯ �ǿ���)
*	�ۼ��� : 2017.05.25
*	���α׷� ���� : ��ŷ ��� �Լ�
**********************************************/

#include "racing_game.h"

void do_rank() //���� ������ ������ ���ؼ� ���� �̵�
{
	for (int i = 0; i < 5; i++)
	{
		if (User_Rank[i].score < User.score) //��ŷ�Ǿ� �ִ� �����麸�� ���� ������ ������ �� ũ��
		{
			for (int j = 3; j >= i; j--)
				User_Rank[j + 1] = User_Rank[j]; //�ϳ��� �̷�(2���� 3����, 3���� 4����)
			User_Rank[i] = User; //����ִ� ������ ���� ������ ���� ����
			break;
		}
	}
}

void ranking()
{
	FILE *fp = NULL; //���������� ����

	fp = fopen("ranking.txt", "rt"); //���Ͽ���
	if (fp == NULL)
	{
		printf("������ ã�� �� �����ϴ�.\n");
		return;
	}
	for (int i = 0; i < 5; i++)
		fscanf(fp, "%s    %d", &User_Rank[i].ID, &User_Rank[i].score); //���Ͽ� ����

	fclose(fp);

	do_rank(); //���� ����

	gotoxy(35, 5);
	printf("<<Ranking>>");
	gotoxy(22, 7);
	printf("��       %s", User.ID); //���� ������ ���̵� ���
	gotoxy(47, 7);
	printf("%d", User.score); //���� ������ ���� ���
	gotoxy(30, 9);
	printf("����ID          ����");
	gotoxy(28, 10);
	printf("========================");
	for (int i = 0; i < 5; i++) //1��~5���� ���̵�� ���� ���
	{
		gotoxy(22, 12 + i * 2);
		printf("%d��       %s", i + 1, User_Rank[i].ID);
		gotoxy(47, 12 + i * 2);
		printf("%d", User_Rank[i].score);
	}
	printf("\n\n\n");

	fp = fopen("ranking.txt", "wt"); //���Ͽ���
	if (fp == NULL)
	{
		printf("������ ã�� �� �����ϴ�.\n");
		return;
	}
	for (int i = 0; i < 5; i++)
		fprintf(fp, "%s    %d\n", User_Rank[i].ID, User_Rank[i].score); //���Ͽ� ����� �� ���

	fclose(fp);
}
