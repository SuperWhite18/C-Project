#include"game.h"

void InitBoard(char board[][COL], int row, int col)//行可以省略，列不可以
{
	int i = 0;
	for (; i < row; i++) {
		int j = 0;
		for (; j < col; j++) {
			board[i][j] = INIT;
		}
	}
}
void ShowBoard(char board[][COL], int row, int col)
{
	printf("   1  | 2 | 3 \n");
	printf("---------------\n");
	int i = 0;
	for (; i < row; i++){
	printf("%d |",i+1);
	int j = 0;
	for (; j < col; j++) {
		printf("%c  |", board[i][j]);
	}
	printf("\n");
	printf("---------------\n");
    }
	/*printf("3 |");
	for (int j = 0; j < col; j++) {
		printf("%c  |", board[2][j]);
	}
		printf("\n");
		printf("---------------\n");*/
}
void ComputerMove(char board[][COL], int row, int col)
{
	while (1) {
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ') {
			board[x][y] = Computer_C;
			break;
		}
	}
}

char Judge(char board[][COL], int row, int col)
{
	int i = 0;
	for (; i < row; i++) {
		if(board[i][0]==board[i][1]&&\
			board[i][1]==board[i][2]&&\
			board[i][0] != ' '){
			return board[i][0];
		}
	}
	for (i = 0; i < col; i++) {
		if (board[0][i] == board[1][i] && \
			board[1][i] == board[2][i] && \
			board[0][i] != ' ') {
			return board[i][0];
		}
	}
	if (board[0][0] == board[1][1] && \
		board[1][1] != ' ' && \
		board[1][1] == board[2][2]) {
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && \
		board[1][1] != ' ' && \
		board[1][1] ==board[2][0]) {
		return board[1][1];
	}
	for (i = 0; i < row; i++) {
		int j = 0;
		for (; j < col; j++) {
			if (board[i][j] == INIT) {
				return 'N';
			}
		}
	}
	return 'F';
}

void Game() {
	srand((unsigned long)time(NULL));//种下一个随机数种子
	char board[ROW][COL];
	InitBoard(board, ROW, COL);
	char result = 0;
	do {
		ShowBoard(board, ROW, COL);
		printf("请落子:> ");
		int x = 0;
		int y = 0;
		scanf_s("%d %d", &x, &y);
		if (x <= 0 || x > 3 || y <= 0 || y > 3) {
			printf("你输入的位置有误，请重新输入！\n");
			continue;
		}
		if (board[x - 1][y - 1] != ' ') {
			printf("该位置已经被占用，请重新输入！\n");
		}
		board[x - 1][y - 1] = Player_C;
	    result = Judge(board, ROW, COL);
		if (result != 'N') {//'N'->next,'F'->FULL,'X','O'
			break;

		}
		
		ComputerMove(board, ROW, COL);
		result = Judge(board, ROW, COL);
		if (result != 'N') {//'N'->next,'F'->FULL,'X','O'
			break;

		}
	} while(1);
	if (result == Player_C) {
		printf("恭喜你，你赢了！\n");
	}
	else if (result == Computer_C) {
		printf("不好意思，你输了!\n");
	}
	else {
		printf("还不错，平手!\n");
	}
	printf("你玩的还不错，要不要再来一把!\n");
}
