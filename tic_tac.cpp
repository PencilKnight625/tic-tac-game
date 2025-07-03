#include <bits/stdc++.h>
using namespace std;

char board[3][3];

// Start the game board with numbers 1-9
void initializeBoard() 
{
	char start = '1';
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			board[i][j] = start++;
}

// Display the current state of the board
void printBoard() 
{
	cout << "\n";
	for (int i = 0; i < 3; ++i) {
		cout << " ";
		for (int j = 0; j < 3; ++j) {
			cout << board[i][j];
			if (j < 2) cout << " | ";
		}
		cout << "\n";
		if (i < 2) cout << "---|---|---\n";
	}
	cout << "\n";
}

// Check if a player has won
char check_win() 
{
	for (int i = 0; i < 3; i++) {
		// Rows
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return board[i][0];
		// Columns
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return board[0][i];
	}
	// For Diagonals
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return board[0][2];

	return ' '; // No winner yet
}

// Check if the board is full
bool is_draw() 
{
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (board[i][j] != 'X' && board[i][j] != 'O')
				return false;
	return true;
}

// Main game
int main() 
{
	initializeBoard();
	char current_player = 'X';
	int move;

	cout << "Welcome to Tic-Tac-Toe!\n";
	printBoard();

	while (true) {
		cout << "Player " << current_player << ", enter your move (1-9): ";
		cin >> move;

		if (move < 1 || move > 9) {
			cout << "Invalid move. Try again.\n";
			continue;
		}

		int row = (move - 1) / 3;
		int col = (move - 1) % 3;

		if (board[row][col] == 'X' || board[row][col] == 'O') {
			cout << "That spot is already taken. Try again.\n";
			continue;
		}

		board[row][col] = current_player;
		printBoard();

		char winner = check_win();
		if (winner == 'X' || winner == 'O') {
			cout << "Player " << winner << " wins! :) \n";
			break;
		}

		if (is_draw()) {
			cout << "It's a draw! :(\n";
			break;
		}

		// Switch players
		current_player = (current_player == 'X') ? 'O' : 'X';
	}

	return 0;
}
