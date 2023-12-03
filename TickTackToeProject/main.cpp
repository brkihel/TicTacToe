#include <iostream>
#include <string>

using namespace std;

//Global Constants for the array size(could be only one, i know :s
const int ROWS = 3;
const int COLS = 3;

void runGame();
void initializeGameBoard(string gameBoard[ROWS][COLS]);
void printCurrentBoard(string[ROWS][COLS]);
void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]);
bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]);
string getWinner(string gameBoard[ROWS][COLS]);
bool isBoardFull(string gameBoard[ROWS][COLS]);


int main() {

	runGame();

	return 0;

}

void runGame(){

	string winner = "";
	bool xTurn = true;

	string gameBoard[ROWS][COLS];

	initializeGameBoard(gameBoard);

	printCurrentBoard(gameBoard);

	while (winner == "") {
		
		if (xTurn) {
			cout << "It is X's turn." << endl;
		}
		else {
			cout << "It is O's turn." << endl;
		}

		getUserInput(xTurn, gameBoard);
		cout << endl;
		printCurrentBoard(gameBoard);
		winner = getWinner(gameBoard);
		xTurn = !xTurn;//flip turn
		
		if (isBoardFull(gameBoard) == true && winner == "") {
			winner = "C"; //Cat's game no winner.
		}

	}

	if (winner == "O") {

		cout << "THE GRAND WINNER IS O!! CONGRATULATIONS!" << endl;
	}
	else if (winner == "X") {
		cout << "THE GRAND WINNER IS X!! CONGRATULATIONS!" << endl;
	}
	else {
		cout << "Thats the cat game! We have a tie! Try again!" << endl;
	}

}

//initializes the 2d array for the game board
void initializeGameBoard(string gameBoard[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {			
			gameBoard[i][j] = " ";
		}
	}
}

//organize the game board and separate each cell with lines and bars to better visualization
void printCurrentBoard(string gameBoard[ROWS][COLS]) {

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++)
		{
			cout << gameBoard[i][j];
			if (j < 2) {
				cout << " | ";
			}
		}
		cout << endl;
		if (i < 2) {
			cout << "- - - - -" << endl;
		}
	}

	cout << endl;

}

void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]) {

	int row = -1;
	int col = -1;
	bool keepAsking = true;

	while (keepAsking) {
		cout << "Please enter the row THEN the column, each from 0, 1 or 2, separated by a space." << endl;
		cin >> row;
		cin >> col;

		if (row >= 0 && row <= 2 && col >= 0 && col <= 2) {
			if (!cellAlreadyOccupied(row, col, gameBoard)) {
				keepAsking = false;
			}
			else {
				cout << "That cell is already occupied! Select another cell..." << endl;
			}
		}
	}

	if (xTurn) {
		gameBoard[row][col] = "X";
	}
	else {
		gameBoard[row][col] = "O";
	}

}

bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]) {
	return gameBoard[row][col] != " ";//checks the specific cell(user input)
}

string getWinner(string gameBoard[ROWS][COLS]) {
	
	for (int i = 0; i < ROWS; i++) {
		//Check rows and columns for matching user inputs, then return the winner
		if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != " ") {
			return gameBoard[i][0];
		}
		if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != " ") {
			return gameBoard[0][i];
		}
		if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[0][0] != " ") {
			return gameBoard[0][0];
		}
		if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[0][2] != " ") {
			return gameBoard[0][2];
		}
	}
	return "";
}

bool isBoardFull(string gameBoard[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++)
		{
			if (gameBoard[i][j] == " ") {
				//cout << "BOARD IS NOT FULL";//REMOVE AFTER DONE(ONLY TEST)
				return false;
			}
		}
	}
	//cout << "BOARD IS FULL!";//REMOVE AFTER DONE(ONLY TEST)
	return true;
}



/*
GAME BOARD LEGEND:

	 0-0 | 0-1 | 0-2
	 ---------------
	 1-0 | 1-1 | 1-2
	 ---------------
	 2-0 | 2-1 | 2-2

*/