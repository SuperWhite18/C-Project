#include"game.h"
#define _CRT_SECURE_NO_WARNINGS 1

void Menu()
{
	printf("############################\n");
	printf("##     欢迎来到三子棋     ##\n");
	printf("############################\n");
	printf("## 1.Play        2.Exit   ##\n");
	printf("############################\n");
	printf("请选择:> ");
}
int main()
{
	int quit = 0;
	while (!quit) {//如果不退出
		Menu();
		int select = 0;
		scanf("%d", &select);
	    switch (select) {
		case 1:
			Game();
			break;
		case 2:
			quit = 1;
			break;
		default:
			printf("你输错了，请重新输入！\n");
			break;

		}
	}
	printf("byebye!\n");
	system("pause");
}
