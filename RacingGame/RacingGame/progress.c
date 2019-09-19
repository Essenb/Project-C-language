/**********************************************
*	����������Ʈ ��������
*   ������Ʈ�� : Racing Game
*	�ҽ� ���ϸ� : progress.c
*	�ۼ��� : �̽���, �����, �ǿ��� ( 2�� : �̽���, �����, ���ȯ, �ǿ���, ������ )
*	�ۼ��� : 2017.05.25
*	���α׷� ���� : ���� ���� ����
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
	int timer = 30000;				// ���� �ӵ��� ������ ����
	int energy = s_car->energy;		// ����ȭ�鿡 ��Ÿ�� ������ ��ġ
	srand((unsigned)time(NULL));

	/*�ʱ�ȭ*/
	x[19] = 16 + random;
	for (i = 19; i > 0; i--)
	{
			x[i - 1] = x[i];
	}
	position_car = x[13] + 4;

	delay_time();		// ī��Ʈ ���
	system("cls");
	boundary();			// ��輱 ���
	

	/* �������� 0���� �۾����� ���� */
	while (energy > 0)
	{
		/* ����Ű �Է� �Ǹ� �ڵ��� ��ġ ����*/
		if (_kbhit())
		{
			key = _getch();
			if (key == 224 || key == 0)
			{
				key = _getch();
				switch (key)
				{
				case 75: //'��'�� �ԷµǸ�
					position_car--; //�������� ��ĭ �̵�
					if (position_car <= 3)	//���ʰ�輱�� �Ѿ���� �ϸ�
						position_car = 3;
					/****************************�ڵ��� ��ġ ����**********/
					gotoxy(position_car, 16); printf("%s", "           ");
					gotoxy(position_car, 17); printf("%s", "           ");
					gotoxy(position_car, 18); printf("%s", "           ");
					gotoxy(position_car, 19); printf("%s", "           ");
					gotoxy(position_car, 20); printf("%s", "           ");
					gotoxy(position_car, 21); printf("%s", "           ");
					break;
				case 77: //'��/�� �ԷµǸ�
					position_car++;
					if (position_car + 9 >= 42)	//�����ʰ�輱�� �Ѿ���� �ϸ�
						position_car = 42 - 9;	//�����ʰ�輱�� ��ǥ�� �ڵ����� ���̸� ��
					/****************************�ڵ��� ��ġ ����**********/
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
		
		/************************�ڵ��� ���************************/
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
		/************************�ڵ��� ���************************/

		/*�� ���*/
		for (j = 0; j < 20; j++)
		{

			gotoxy(x[j], j + 2);
			Gray printf("[");
			gotoxy(x[j] + 17, j + 2);
			printf("]");
		}

		/*�ǰ� ���� ���*/
		if (position_car <= x[19] || position_car <= x[18] || position_car <= x[17] || position_car <= x[16]
			|| position_car <= x[15] || position_car <= x[14])
		{
			energy--;		//���� ��ֹ��� ����� ����� �ǰݰ��
			s_car->speed -= s_car->acc * 3;	//�ӵ� ����
			if (s_car->speed <= 1)	//�ӵ��� ������ �Ƿ��ϸ�
				s_car->speed = 100;	//�ʱ�ӵ��� �缳��
		}
		if (position_car + 9 >= x[19] + 17 || position_car + 9 >= x[18] + 17 || position_car + 9 >= x[17] + 17 || position_car + 9 >= x[16] + 17
			|| position_car + 9 >= x[15] + 17 || position_car + 9 >= x[14] + 17)
		{
			energy--;		//������ ��ֹ��� ����� ����� �ǰݰ��
			s_car->speed -= s_car->acc * 3;	//�ӵ� ����
			if (s_car->speed <= 1)	//�ӵ��� ������ �Ƿ��ϸ�
				s_car->speed = 100;	//�ʱ�ӵ��� �缳��
		}

		/* ���� ���� ��Ȳ�� ��� */
		gotoxy(28, 24);
		printf("Copyright 2017. Continue(2��) all rights reserved.");
		gotoxy(55, 2);
		printf("    %c%c Racing Game %c%c", 0xa1, 0xbc, 0xa1, 0xbd);
		gotoxy(55, 3);
		printf("                 ver 3.0");
		gotoxy(55, 5);
		printf(" ������");
		gotoxy(55, 6);
		printf("                   %d  ", energy);
		gotoxy(55, 8);
		printf(" �ӵ�");
		gotoxy(55, 9);
		printf("                   %d  ", s_car->speed);
		gotoxy(55, 11);
		printf(" ����");
		gotoxy(55, 12);
		printf("                   %d", User.score);

		gotoxy(55, 15); printf("     %c%c Car info %c%c", 0xa1, 0xba, 0xa1, 0xbb);
		gotoxy(55, 17); printf("  �̸�      :  %s", s_car->name);
		gotoxy(55, 18); printf("  �ִ�ӵ�  :  %d", s_car->max_speed);
		gotoxy(55, 19); printf("  ���ӵ�    :  %d", s_car->acc);
		gotoxy(55, 20); printf("  ������    :  %d", s_car->energy);

		/*ȭ�� �ʱ�ȭ*/
		Sleep(timer / s_car->speed);
		for (j = 0; j < 20; j++)
		{
			gotoxy(x[j], j + 2);
			printf(" ");
			gotoxy(x[j] + 17, j + 2);
			printf(" ");
		}
		removeCursor();

		/* ���� ���� ��Ȳ�� ó�� */
		User.score++;							// ���� ����
		if (s_car->speed <= s_car->max_speed)	// �ӵ� ����
			s_car->speed += s_car->acc;
		if (s_car->speed >= s_car->max_speed)	//�ִ� �ӵ��� �Ѿ��
			s_car->speed = s_car->max_speed;	//�ִ� �ӵ��� ����

		/*���� �� �غ�*/
		for (i = 19; i > 0; i--)
		{
			x[i] = x[i - 1];
		}
		while (1)//��� ����
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
void boundary()							// ��輱
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