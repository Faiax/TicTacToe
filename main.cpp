#include <iostream>
#include <string>
using namespace std;

char board[3][3] = { {'1','2','3'} , {'4','5', '6'} , {'7', '8', '9'} };



char currentMarker;
int currentPlayer;

void drawBoard() {
	cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "_________\n";
	cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "_________\n";
	cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;

}


void placeMarker(int slot) {

	int row = slot / 3;
	int col;

	if (slot % 3 == 0) {
		row = row - 1;
		col = 2;
	}
	else col = (slot % 3) - 1;
	
	board[row][col] = currentMarker;

}

int winner( ) {

	for (int i = 0; i < 3; i++) {
		// rows
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer;
		//columns
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer;}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer;
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])  return currentPlayer;

	return 0;
}

void swapPlayerAndMarker() {

	if (currentMarker == 'X') currentMarker = 'O';
	else currentMarker = 'X';

	if (currentPlayer == 1) currentPlayer == 2;
	else currentPlayer == 1;
}



void game() {

	cout << "Player One, Choose your maker : ";
	char marker_p1;
	cin >> marker_p1;

	currentPlayer = 1;
	currentMarker = marker_p1;

	int player_won;


	for (int i = 0; i < 9; i++) {
		cout << " Its player" << currentPlayer << "'s turn. Enter your slot: ";
		int slot;
		cin >> slot;

		placeMarker(slot);

		player_won = winner();

		if (player_won == 1) {cout << " Player1 Won! Congratulations!"; break;}
		if (player_won == 2) { cout << " Player2 Won! Congratulations!"; break; }
		swapPlayerAndMarker();
		drawBoard();

	}
	if (player_won == 0) cout << "Thats is a tie game!";
}


int main() {
	
	game();
	
}
