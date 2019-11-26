//include libraries
#include <iostream>
#include "Windows.h"
#include <string>
#include <cctype>

using namespace std; //only std namespace will be used

void menu() {
	cout << "\nWhat would you like to do?:" << endl;//Menu header
	cout << "\t1 - Play Game" << endl;//Print Option 0
	cout << "\t2 - How to Play" << endl;//Print Option 1
	cout << "\t9 - End the program" << endl;//Print Option 9
}//END FUNCTION

int getChoice() {
	int choice;//setup input/return value
	cout << "Choice: ";//prompt the user for input
	cin >> choice;//get the user input and assign it to choice
	return choice;//return choice
}//END FUNCTION

bool checkExit() {
	bool exit;//setup return variable
	char cInput;//setup input variable
	cout << "Are you sure you want to exit? Y/N: "; //Prompt the user for input
	cin >> cInput;//get the input and assign it to cInput
	cInput == 'Y' || cInput == 'y' ? exit = true : exit = false; //If the input is Y or y then make the return value true, otherwise, make it false
	return exit;//return exit
}//END FUNCTION

void showInstructions() {
	system("cls");
	cout << "How to Play:" << endl;
	cout << "A board will be printed out at the start of each person's turn." << endl;
	cout << "It will look like this:" << endl;
	cout << "+---+---+---+" << endl;
	cout << "|   |   |   |" << endl;
	cout << "+---+---+---+" << endl;
	cout << "|   |   |   |" << endl;
	cout << "+---+---+---+" << endl;
	cout << "|   |   |   |" << endl;
	cout << "+---+---+---+" << endl;
	cout << "Players will take turns placing an X or a O on the board." << endl;
	cout << "The way you input you turn is using two letter pseudonyms." << endl;
	cout << "These are things like BL (bottom left) or TM (for top middle)" << endl;
	cout << "When inputting your turn, make sure the first letter represents the row i.e.:" << endl;
	cout << "T(top), M(middle), B(bottom)" << endl;
	cout << "And the second letter represents the column i.e.:" << endl;
	cout << "L (left), M (middle), R (right)" << endl;
	cout << "Letters are not case sensitive." << endl;
	cout << "Get three of your sign (X or O) in a line to win either diagonally, horizontally or vertically." << endl;
	system("pause");
	system("cls");
}//END FUNCTION

void printBoard(char gameBoard[3][3]) {
	for (int row = 0; row < 3; row++) {
		cout << "+---+---+---+" << endl;//print top border of the row
		cout << "| " << gameBoard[row][0] << " | " << gameBoard[row][1] << " | " << gameBoard[row][2] << " |" << endl; //print the contents of the squares with partitions
	}//END FOR
	cout << "+---+---+---+" << endl;//print the bottom border of the game board
}//END FUNCTION

char checkTurn(char gameBoard[3][3]) {
	int xCount = 0;//setup counter for Xs
	int oCount = 0;//setup counter for Os
	for (int row = 0; row < 3; row++) {//FOR each row...
		for (int column = 0; column < 3; column++) {//and each column
			gameBoard[row][column] == 'X' ? xCount++ : xCount = xCount; //increment xCount if there's an X
			gameBoard[row][column] == 'O' ? oCount++ : oCount = oCount; //increment oCount if there's an O
		}//END FOR
	}//END FOR
	char playersTurn; //set up the return variable
	xCount > oCount ? playersTurn = 'O' : playersTurn = 'X';//if there are more Xs on the board, it is O's turn, else it is X's turn
	return playersTurn; //return the value

}//END FUNCTION

string getTurn() {
	cout << "Where would you like to go?: "; //prompt input
	string turn; // create input variable
	cin >> turn; // allow user input and put the input into turn
	return turn;
}//END FUNCTION

void findSpaceOnBoard(string turn, int& row, int& column) {
	turn.at(0) == 'b' || turn.at(0) == 'B' ? row = 2 : row = row; //if the first character is b, the row in the array is 3, else do nothing
	turn.at(0) == 'm' || turn.at(0) == 'M' ? row = 1 : row = row; //if the first character is m, the row in the array is 2, else do nothing
	turn.at(0) == 't' || turn.at(0) == 'T' ? row = 0 : row = row; //if the fisrt character is t, the row in the array is 1, else do nothing

	turn.at(1) == 'l' || turn.at(1) == 'L' ? column = 0 : column = column; //if the second letter is l, the column in the array is 1, else do nothing
	turn.at(1) == 'm' || turn.at(1) == 'M' ? column = 1 : column = column; //if the second letter is m, the column in the array is 2, else do nothing
	turn.at(1) == 'r' || turn.at(1) == 'R' ? column = 2 : column = column; //if the second letter is r, the column in the array is 3, else do nothing

	
}//END FUNCTION

bool turnIsValid(string turn, char gameBoard[3][3]) {
	int row, column;//setup variables to mark the postion in the array
	row = 4; //place dummy value into row
	column = 4; //place dummy value into column
	findSpaceOnBoard(turn, row, column); //change row and column to find where on the board the input refers
	if (row != 4 && column != 4) { //if row and column are unchanged, the input was invalid

		if (gameBoard[row][column] == ' ') {//if the space hasn't been occupied
			return true;//return true (the move is valid)
		}
	}//END IF
	return false; //return false (the move is invalid)

}//END FUNCTION

void updateBoard(string turn,char player, char gameBoard[3][3]) {
	int row, column; //setup row and column variables
	findSpaceOnBoard(turn, row, column); //find the row and column on the board
	gameBoard[row][column] = player; //update the position with the player's marker
}//END FUNCTION

void takeTurn(char player, char gameBoard[3][3]) {
	system("cls"); //clear the screen
	string turn; // create variable to store the turn

	printBoard(gameBoard);
	cout << player << "'s turn." << endl; // tell the users whose turn it is

	turn = getTurn(); // run getTurn() function
	if (turnIsValid(turn, gameBoard)) {//check the turn is valid
		updateBoard(turn, player, gameBoard);//if it is, update the board
	}
	else {//otherwise
		do {
			system("cls"); //clear the screen
			printBoard(gameBoard); //reprint the gameBoard
			cout << "\nTurn is invalid" << endl;//tell user the turn is invalid
			turn = getTurn();//get new turn
			if (turnIsValid(turn, gameBoard)) {//check the turn is valid
				updateBoard(turn, player, gameBoard);//if it is update the board
				break;//break the DO WHILE loop. DONT GET RID OF THIS OR THE PROGRAM BREAKS (see NOTES)
			}//END IF
		} while (turnIsValid(turn, gameBoard) == false);//continue getting turns until one is valid
	}//END IF
}//END FUNCTION

bool checkWin(char gameBoard[3][3]) {//see notes to understand what each if statement is doing
	//check row 1
	if (gameBoard[0][0] == gameBoard[0][1] && gameBoard[0][1] == gameBoard[0][2] && (gameBoard[0][0] == 'X' || gameBoard[0][0] == 'O')) {
		return true;
	}
	//check row 2
	else if (gameBoard[1][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[1][2] && (gameBoard[1][0] == 'X' || gameBoard[1][0] == 'O')) {
		return true;
	}
	//check row 3
	else if (gameBoard[2][0] == gameBoard[0][1] && gameBoard[2][1] == gameBoard[2][2] && (gameBoard[2][0] == 'X' || gameBoard[2][0] == 'O')) {
		return true;
	}
	//check column 1
	if (gameBoard[0][0] == gameBoard[1][0] && gameBoard[1][0] == gameBoard[2][0] && (gameBoard[0][0] == 'X' || gameBoard[0][0] == 'O')) {
		return true;
	}
	//check column 2
	else if (gameBoard[0][1] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][1] && (gameBoard[0][1] == 'X' || gameBoard[0][1] == 'O')) {
		return true;
	}
	//check column 3
	else if (gameBoard[0][2] == gameBoard[1][2] && gameBoard[1][2] == gameBoard[2][2] && (gameBoard[0][2] == 'X' || gameBoard[0][2] == 'O')) {
		return true;
	}
	//check diagonal 1
	if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && (gameBoard[0][0] == 'X' || gameBoard[0][0] == 'O')) {
		return true;
	}
	else if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && (gameBoard[0][2] == 'X' || gameBoard[0][2] == 'O')) {
		return true;
	}
	//no win
	return false;
}

bool checkStalemate(char gameBoard[3][3]) {
	for (int i = 0; i < 3; i++) {//for each row...
		for (int j = 0; j < 3; j++) {//...and each column
			if (gameBoard[i][j] == ' ') {//if there is an empty space...
				return false; //there is no stalemate
			}//END IF
		}//END FOR
	}//END FOR
	return true;//if the program reaches this statement, it is a stalemate


}//ENDFUNCTION

void playGame() {
	char gameBoard[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} }; //Setup the game board
	bool gameNotWon = true;//set up the while loop variable
	char playersTurn; //setup the variable to mark whose turn it is
	//while game not won
	while (gameNotWon) {
		//see whose turn it is
		playersTurn = checkTurn(gameBoard); //check whose turn it is
		//let them input a turn
		takeTurn(playersTurn,gameBoard);//Check it is valid - now included in takeTurn function
		//check if anyone has won the game
		gameNotWon = !checkWin(gameBoard); //if so, break the while loop (see notes)
		if (gameNotWon) {//if no one has won (if you want to see why this is in a separate if statement, there's probably a section in NOTES)
			//check if the match is a stalemate
			gameNotWon = !checkStalemate(gameBoard);// if so break the while loop
		}
	}//END WHILE
	cout << endl;
	system("cls"); //clear the screen
	printBoard(gameBoard);//print the final board
	if (checkWin(gameBoard)) {
		cout << "The game has been won!!" << endl; //win message
		cout << "The winner is " << playersTurn << endl; //display winner using the playersTurn Variable
	}
	else if (checkStalemate(gameBoard)) {
		cout << "The game is a stalemate..." << endl; //stalemate message
		cout << "Better luck next time" << endl; //stalemate message part 2
	}//END IF
	system("pause");//pause until input
	system("cls");//clear the screen
}//END FUNCTION


int main() {
	cout << "Welcome to the tic-tac-toe program!" << endl << endl; //print the Welcome message
	bool notFinished = true; // set up while loop variable
	int choice;//Set up user input variable

	while (notFinished) {//While the player does not want to exit
		//Print Menu
		menu();
		//Get user choice
		choice = getChoice();
		//switch to see what we have to do
		switch (choice) {
		case 1:	//play game
			playGame();
			break;
		case 2://See instructions
			showInstructions();//run showInstructions()
			break;
		case 9://Exit
			//Run checkExit()
			notFinished = !checkExit(); //Make sure they want to exit and flip the result (see NOTES at the bottom of the program)
			break;
		//DEFAULT to an "invalid option" message
		default:
			cout << "Invalid Option" << endl;//tell the user the choice was invalid
		}//END SWITCH
	}//END WHILE
	cout << "Goodbye..." << endl; //Print goodbye message
	cout << "Exiting program..."; //Tell user the program is ending
	Sleep(600); // Sleep is not necessary but just here for a bit of flair
	return 0;//Return 0 to end main()
}//END MAIN

/*
NOTES:
	notFinished and the checkExit function:
		The result of the checkExit function must be flipped to work properly with notFinished. This is because the while loop using notFinished is checking that it is true.
		checkExit returns true when the user wants to exit, so when it returns truenotFinished should be false.
		Instead of using an if statement, which would take multiple lines, the answer is just flipped using the NOT syntax (!) as it is quicker.

	gameNotWon and checkWin function:
		The result of checkWin will be true if the game has been won, however the while loop is checking whether or not gameNotWon is true.
		Similarly to the function pair above, the result of checkWin is flipped using the NOT (!) syntax to make sure the while loop breaks when necessary.

	gameNotWon and checkStalemate function:
		Just like the function above, the output of the function is TRUE when there is a stalemate (which is cause to exit the while loop)
		However, gameNotWon uses TRUE to continue the loop, so the output must be flipped using the NOT syntax (!) to make sure the loop breaks and continues when necessary

	break, DO WHILE and the turnIsValid function:
		There is a break; statement on line 139. This statement breaks the DO WHILE loop when turnIsValid becomes true.
		This is an important note -- DO NOT DELETE THIS STATEMENT
		After the turnIsValid is true, and the gameBoard is updated, the turn then becomes invalid.
		This means on the next check (the one which stops or continues the DO WHILE loop) the turn is now invalid and the loop will continue forever.

	gameNotWon, checkStalemate and an if statement
		gameNotWon = !checkStalemate(gameBoard) is in its own section because is the game has been won, the gameNotWon variable changes to false.
		Then the afore mentioned statement changes it back to true as there is no stalemate.
	
	checkWin and the unholy amount of conditions in the IF statements
		Each line checks a column, row or diagonal line. The array indexes match the places in the array with the visual representation of the 3x3 matrix
		Each checks if the 3 spaces are the same and that at least one of the spaces is and X or O (so that an empty row does not equal a victory)
		Note - the statements such as (gameBoard[0][1] == 'X' || gameBoard[0][1] == 'O') need to be in brackets to ensure that the BIDMAS order is followed i.e.
			without brackets the 3 spaces have to be the same, and have one space equal to 'X' to WIN OR the first space can just be 'O' to Win
*/