/**********************************************
*	기초프로젝트 게임제작
*   프로젝트명 : Racing Game
*	소스 파일명 : ranking.c
*	작성자 : 2016039083 강예지 (2조 : 이승훈 강예지 김기훈 김능환 권오동)
*	작성일 : 2017.05.25
*	프로그램 설명 : 랭킹 출력 함수
**********************************************/

#include "racing_game.h"

void do_rank() //현재 유저의 점수와 비교해서 순위 이동
{
	for (int i = 0; i < 5; i++)
	{
		if (User_Rank[i].score < User.score) //랭킹되어 있는 유저들보다 현재 유저의 점수가 더 크면
		{
			for (int j = 3; j >= i; j--)
				User_Rank[j + 1] = User_Rank[j]; //하나씩 미룸(2위를 3위로, 3위를 4위로)
			User_Rank[i] = User; //비어있는 순위에 현재 유저의 순위 저장
			break;
		}
	}
}

void ranking()
{
	FILE *fp = NULL; //파일포인터 선언

	fp = fopen("ranking.txt", "rt"); //파일오픈
	if (fp == NULL)
	{
		printf("파일을 찾을 수 없습니다.\n");
		return;
	}
	for (int i = 0; i < 5; i++)
		fscanf(fp, "%s    %d", &User_Rank[i].ID, &User_Rank[i].score); //파일에 저장

	fclose(fp);

	do_rank(); //순위 정렬

	gotoxy(35, 5);
	printf("<<Ranking>>");
	gotoxy(22, 7);
	printf("나       %s", User.ID); //현재 유저의 아이디 출력
	gotoxy(47, 7);
	printf("%d", User.score); //현재 유저의 점수 출력
	gotoxy(30, 9);
	printf("유저ID          점수");
	gotoxy(28, 10);
	printf("========================");
	for (int i = 0; i < 5; i++) //1위~5위의 아이디와 점수 출력
	{
		gotoxy(22, 12 + i * 2);
		printf("%d위       %s", i + 1, User_Rank[i].ID);
		gotoxy(47, 12 + i * 2);
		printf("%d", User_Rank[i].score);
	}
	printf("\n\n\n");

	fp = fopen("ranking.txt", "wt"); //파일오픈
	if (fp == NULL)
	{
		printf("파일을 찾을 수 없습니다.\n");
		return;
	}
	for (int i = 0; i < 5; i++)
		fprintf(fp, "%s    %d\n", User_Rank[i].ID, User_Rank[i].score); //파일에 저장된 걸 출력

	fclose(fp);
}
