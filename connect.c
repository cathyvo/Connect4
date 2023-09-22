#include <stdio.h>
#include <stdbool.h>

#define ROWS 6
#define COLUMNS 7 

char board[ROWS][COLUMNS];
char currentPlayer;
int toWin;

//creating the gameboard
void gameBoard(){
	for(int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			board[i][j] = ' ';
}}}

//prints the gameboard
void printBoard(){
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			printf("|%c", board[i][j]);
}
				printf("|\n");
}					printf("-----------------\n");
}

//checks if the move can be made/ is legal
bool isValidMove(int column){
	return column >= 0 && column < COLUMNS && board[0][column] == ' ';
}

void dropToken(int column, char token){
	for (int row = ROWS - 1; row >= 0; row--){
		if(board[row][column] == ' '){
			board[row][column] = token;
			break;
}}}

//checks to see if there is a win
bool checkWin(char token) {
for (int row = 0; row < ROWS; row++){
	for(int col = 0; col <= COLUMNS - toWin; col++){
		bool win = true;
		for(int k = 0; k < toWin; k++){
				if(board[row][col + k] != token){
					win = false;
					break;
}}
	if (win) return true;
}}

//vertical wins
for(int col = 0; col < COLUMNS; col++){
	for (int row = 0; row <= ROWS - toWin; row++){
		bool win = true;
		for(int k = 0; k < toWin; k++){
			if(board[row+k][col] != token){
			win = false;
			break;
}}
if (win) return true;
}}

//diagonal wins
for (int row = 0; row <= ROWS - toWin; row++){
	for(int col = 0; col <= COLUMNS - toWin; col++){
		bool win = true;
		for(int k = 0; k < toWin; k++){
			if(board[row+k][col+k] != token){
				win = false;
				break;
}}
if (win) return true;
}}

//diagonal wins pt 2
for (int row = 0; row <= ROWS - toWin; row++){
	for(int col = toWin - 1; col < COLUMNS; col++){
		bool win = true;
		for (int k = 0; k < toWin; k++){
			if(board[row+k][col-k] != token){
				win = false;
				break;
}}
if (win) return true;
}}
	return false;//returns false if there is no win
}

//checks if there is a tie
bool checkDraw(){
	for (int col = 0; col < COLUMNS; col++){
		if(board[0][col] == ' '){
			return false;
}}
return true;
}

int main() {
	printf("Welcome to Connect Four!\n"); 

	gameBoard();
	currentPlayer = 'R';
	toWin = 4; //sets default token to win to 4
	printBoard();//prints the board

	bool gameWon = false;
	bool isDraw = false;

	while (!gameWon && !isDraw){
//printBoard();
		int column;
		do {
			printf("%c to play. Pick a column (1-7): ", currentPlayer);
			scanf("%d", &column);
			column--;
		} while (!isValidMove(column));
		dropToken(column, currentPlayer);

		if (checkWin(currentPlayer)){
		printBoard();
		printf("%c wins!\n", currentPlayer);
		gameWon = true;

		} else if (checkDraw()) {
			printBoard();
			printf("Draw!\n");
			isDraw = true;
		} else {
			currentPlayer = (currentPlayer == 'R') ? 'Y' : 'R';
}
		printBoard();//prints board after each move
}
		printf("Thanks for playing!\n");		
		return 0;
}
