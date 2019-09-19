/**********************************************
*	����������Ʈ ��������
*   ������Ʈ�� : Racing Game
*	�ҽ� ���ϸ� : car.c
*	�ۼ��� : 2014041019 ���ȯ ( 2�� : �̽���, �����, ���ȯ, �ǿ���, ������ )
*	�ۼ��� : 2017.05.25
*	���α׷� ���� : �ڵ��� ���� �� ����ȭ��
**********************************************/
// ��ǰ c��� ������Ʈ p103���� gotoxy�Լ� ��� ����

#include"racing_game.h"
void car1();
void car2();
void car3();
void car4();
void algo();

// ������� �� ���, �̸�, ����ӵ�, �ִ�ӵ�, ���ӵ�, ������
r_car s_car01 = { { { "���⦡�⦤" },{ "��      ��" },{ "����  ����" },{ "�ݦ�  ����" },{ "�������থ" },{ "      ��" } },{ "Yellow" }, 100, 500, 50, 20 };  // ����ü�� ����� 1�� �ڵ��� ����
r_car s_car02 = { { { "�ݦ�������" },{ "����������" },{ "�ݦ�������" },{ "����������" },{ "�ݦ������" },{ "      ��" } },{ "Plum" }, 100, 600, 30, 15 }; // ����ü�� ����� 2�� �ڵ��� ����
r_car s_car03 = { { { "����������" },{ "�١�������" },{ "�١�������" },{ "�١�������" },{ "����������" },{ "      ��" } },{ "SkyBlue" }, 100, 800, 40, 10 }; // ����ü�� ����� 3�� �ڵ��� ����
r_car s_car04 = { { { "�⦡�ަ���" },{ "�⦡�ަ���" },{ "��      ��" },{ "��      ��" },{ "�٦�������" },{ "      ��" } },{ "Green" }, 100, 1000, 50, 5 };   // ����ü�� ����� 4�� �ڵ��� ����

r_car* car_select()
{
	while (1)
	{
		printf("\n                          <  �ڵ����� �����ϼ���  >\n\n\n\n");
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
		printf(" �÷��� �ϰ� ���� �ڵ����� �������ּ��� : ");
		scanf("%d", &select_car_num);    // ���ϴ� �ڵ����� �Է�

		switch (select_car_num)		// �ڵ��� ����
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
			printf("�ٽ� �Է����ּ���.\n");
			system("pause");
			system("cls");
			break;
		}
	}
}
void algo()      // �ڵ��� ��� �Լ� ����
{
	car1();      // 1�� �ڵ���
	car2();      // 2�� �ڵ���
	car3();      // 3�� �ڵ���
	car4();      // 4�� �ڵ���
}
void car1()     // ù��° �ڵ���
{
	int k = 6;           // Ŀ���� �� ����

	gotoxy(3, k++);      // Ŀ���� 3������ �̵� ���� ��¸��� 1���� ����
	Yellow printf("%s", s_car01.shape[0]);
	gotoxy(3, k++);
	printf("%s", s_car01.shape[1]);   gotoxy(3, k++);
	printf("%s", s_car01.shape[2]);   gotoxy(3, k++);
	printf("%s", s_car01.shape[3]);   gotoxy(3, k++);
	printf("%s", s_car01.shape[4]);   gotoxy(3, k++);
	printf("%s", s_car01.shape[5]);

	k++;								 // ���� ���

	gotoxy(3, k++);
	Gray printf("�̸�     : %s\n", s_car01.name);
	gotoxy(3, k++);
	printf("�ִ�ӵ� : %d\n", s_car01.max_speed);
	gotoxy(3, k++);
	printf("���ӵ�   : %d\n", s_car01.acc);
	gotoxy(3, k++);
	printf("������   : %d\n", s_car01.energy);
}
void car2()    // �ι�° �ڵ���
{
	int k = 6;

	gotoxy(22, k++);      // Ŀ���� 22������ �̵� ���� ��¸��� 1���� ����
	Plum printf("%s", s_car02.shape[0]);   gotoxy(22, k++);
	printf("%s", s_car02.shape[1]);   gotoxy(22, k++);
	printf("%s", s_car02.shape[2]);   gotoxy(22, k++);
	printf("%s", s_car02.shape[3]);   gotoxy(22, k++);
	printf("%s", s_car02.shape[4]);   gotoxy(22, k++);
	printf("%s", s_car02.shape[5]);

	k++;								 // ���� ���

	gotoxy(22, k++);
	Gray printf("�̸�     : %s\n", s_car02.name);
	gotoxy(22, k++);
	printf("�ִ�ӵ� : %d\n", s_car02.max_speed);
	gotoxy(22, k++);
	printf("���ӵ�   : %d\n", s_car02.acc);
	gotoxy(22, k++);
	printf("������   : %d\n", s_car02.energy);
}
void car3()     // ����° �ڵ���
{
	int k = 6;

	gotoxy(41, k++);      // Ŀ���� 41������ �̵� ���� ��¸��� 1���� ����
	Blue printf("%s", s_car03.shape[0]);   gotoxy(41, k++);
	printf("%s", s_car03.shape[1]);   gotoxy(41, k++);
	printf("%s", s_car03.shape[2]);   gotoxy(41, k++);
	printf("%s", s_car03.shape[3]);   gotoxy(41, k++);
	printf("%s", s_car03.shape[4]);   gotoxy(41, k++);
	printf("%s", s_car03.shape[5]);

	k++;								 // ���� ���

	gotoxy(41, k++);
	Gray printf("�̸�     : %s\n", s_car03.name);
	gotoxy(41, k++);
	printf("�ִ�ӵ� : %d\n", s_car03.max_speed);
	gotoxy(41, k++);
	printf("���ӵ�   : %d\n", s_car03.acc);
	gotoxy(41, k++);
	printf("������   : %d\n", s_car03.energy);
	gotoxy(41, k++);
}
void car4()     // �׹�° �ڵ���
{
	int k = 6;

	gotoxy(60, k++);      // Ŀ���� 60������ �̵� ���� ��¸��� 1���� ����
	Green printf("%s", s_car04.shape[0]);   gotoxy(60, k++);
	printf("%s", s_car04.shape[1]);   gotoxy(60, k++);
	printf("%s", s_car04.shape[2]);   gotoxy(60, k++);
	printf("%s", s_car04.shape[3]);   gotoxy(60, k++);
	printf("%s", s_car04.shape[4]);   gotoxy(60, k++);
	printf("%s", s_car04.shape[5]);

	k++;								 // ���� ���

	gotoxy(60, k++);
	Gray printf("�̸�     : %s\n", s_car04.name);
	gotoxy(60, k++);
	printf("�ִ�ӵ� : %d\n", s_car04.max_speed);
	gotoxy(60, k++);
	printf("���ӵ�   : %d\n", s_car04.acc);
	gotoxy(60, k++);
	printf("������   : %d\n", s_car04.energy);
	gotoxy(60, k++);
}