//SEE BOTTOM OF CODE FOR FUNCTION LIST, KEY VARIABLES AND NOTES

//include libraries
#include <iostream> //for I/O
#include "Windows.h" //for Sleep()
#include "stdio.h" //for getline()
#include <string> //for strings
#include <cctype> //for capitalisation i think (might not be used, too scared to delete)
#include <fstream> //for file I/O
#include <sstream> //for string streaming with file I/O
#include <vector> //for Vectors

using namespace std; //only std namespace will be used

void menu() {
	cout << "\nWhat would you like to do?:" << endl;//Menu header
	cout << "\t1 - Play Game" << endl;//Print Option 1
	cout << "\t2 - How to Play" << endl;//Print Option 2
	cout << "\t3 - View Scores" << endl;//Print Option 3
	cout << "\t4 - Open last game" << endl;//Print option 4
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
	cout << "Overall score is saved after each game" << endl;
	cout << "If you want to save your game for later, type save when taking a turn" << endl;
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
	if (turn == "save") {
		return true;
	}
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

void updateBoard(string turn, char player, char gameBoard[3][3]) {
	int row, column; //setup row and column variables
	findSpaceOnBoard(turn, row, column); //find the row and column on the board
	gameBoard[row][column] = player; //update the position with the player's marker
}//END FUNCTION

void saveGame(char gameBoard[3][3]) {
	ofstream outFile;//create out file stream variable
	outFile.open("savedGame.txt", ios::out);//open the file
	for (int i = 0; i < 3; i++) {//for every row...
		for (int j = 0; j < 3; j++) {//and every column...
			if (gameBoard[i][j] == ' ') {//if the value is " "...
				outFile << "-";//write a '-'
			}
			else {//otherwise...
				outFile << gameBoard[i][j];//just write the value
			}//END IF
		}//END FOR
		outFile << endl;
	}//END FOR
	outFile.close();
}//END FUNCTION

void takeTurn(char player, char gameBoard[3][3], bool& saveFlag) {
	system("cls"); //clear the screen
	string turn; // create variable to store the turn

	printBoard(gameBoard);
	cout << player << "'s turn." << endl; // tell the users whose turn it is

	turn = getTurn(); // run getTurn() function
	if (turnIsValid(turn, gameBoard)) {//check the turn is valid
		if (turn != "save") {
			updateBoard(turn, player, gameBoard);//if it is, update the board
		}
		else {
			saveGame(gameBoard);//run saveGame function on gameBoard
			saveFlag = true;//set the save flag to true
		}
	}
	else {//otherwise
		do {
			system("cls"); //clear the screen
			printBoard(gameBoard); //reprint the gameBoard
			cout << "\nTurn is invalid" << endl;//tell user the turn is invalid
			turn = getTurn();//get new turn
			if (turnIsValid(turn, gameBoard)) {//check the turn is valid
				if (turn != "save") {
					updateBoard(turn, player, gameBoard);//if it is update the board
				}
				else {
					saveGame(gameBoard);//run saveGame function on gameBoard
					saveFlag = true;//set the save flag to true
				}
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
	if (gameBoard[1][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[1][2] && (gameBoard[1][0] == 'X' || gameBoard[1][0] == 'O')) {
		return true;
	}
	//check row 3
	if (gameBoard[2][0] == gameBoard[2][1] && gameBoard[2][1] == gameBoard[2][2] && (gameBoard[2][0] == 'X' || gameBoard[2][0] == 'O')) {
		return true;
	}
	//check column 1
	if (gameBoard[0][0] == gameBoard[1][0] && gameBoard[1][0] == gameBoard[2][0] && (gameBoard[0][0] == 'X' || gameBoard[0][0] == 'O')) {
		return true;
	}
	//check column 2
	if (gameBoard[0][1] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][1] && (gameBoard[0][1] == 'X' || gameBoard[0][1] == 'O')) {
		return true;
	}
	//check column 3
	if (gameBoard[0][2] == gameBoard[1][2] && gameBoard[1][2] == gameBoard[2][2] && (gameBoard[0][2] == 'X' || gameBoard[0][2] == 'O')) {
		return true;
	}
	//check diagonal 1
	if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && (gameBoard[0][0] == 'X' || gameBoard[0][0] == 'O')) {
		return true;
	}
	//check diagonal 2
	if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && (gameBoard[0][2] == 'X' || gameBoard[0][2] == 'O')) {
		return true;
	}
	//no win
	return false;
}//END FUNCTION

bool checkStalemate(char gameBoard[3][3]) {
	for (int i = 0; i < 3; i++) {//for each row...
		for (int j = 0; j < 3; j++) {//...and each column
			if (gameBoard[i][j] == ' ') {//if there is an empty space...
				return false; //there is no stalemate
			}//END IF
		}//END FOR
	}//END FOR
	return true;//if the program reaches this statement, it is a stalemate
}//END FUNCTION

void updateScore() {
	vector<string> listOfNames(1); //create vector for list of names
	vector<int> listOfScores(1); //create vecotr for as list of scores
	istringstream iss; // create a string streaming variable
	string currentLine; //create a variable for the current line
	string playerName = ""; // create a variable for the player name
	int playerScore = 0; // create a varaible for the player scores
	int index = 0; //create a variable to check if it is the first item put into the vector
	ifstream readFile; //create a variable to read in the file
	readFile.open("scores.txt", ios::in); //open scores.txt
	while (getline(readFile, currentLine)) { //while there is a non empty line
		iss.clear(); //clear the stringstream
		iss.str(currentLine); //put the current line into the stringstream
		iss >> playerName >> playerScore; //put the player name into playerName and the score into playerScore
		if (index != 0) { //if its not the first item,
			listOfNames.push_back(playerName);//just add the name to the back
			listOfScores.push_back(playerScore);//just add the name to the back
		}
		else { //else, it is the first item...
		listOfNames[0] = playerName;//add the item to the front
		listOfScores[0] = playerScore;//add the item to the front
		index++;//increase index
		}
	}

	readFile.close();//close scores.txt

	//popping from the front //SEE NOTES
	/*
	vector<string> listOfNamesReversed(listOfNames.size());
	vector<int> listOfScoresReversed(listOfScores.size());
	for (int i = 0; i < listOfNames.size(); i++) {
		listOfNamesReversed[i] = listOfNames.pop_back();
		listOfScoresReversed[i] = listOfScores.pop_back();
	}*/

	string winner;//create a string for the winners name
	cout << "Enter the winner's name: ";//prompt user input
	cin >> winner;//get user input and put it into winner

	int nameIndex = 0;//set name index to 0
	bool inList = false; //create a flag to see if winner is in the vector already
	for (int i = 0; i < listOfNames.size(); i++) {//search vector for name
		if (listOfNames[i] == winner) {//if its in there
			inList = true;//set inList to true
			nameIndex = i;//set nameIndex to i
		}
	}
	if (inList) {//if the name is in the list
		listOfScores[nameIndex] += 1;// add one to their score
	}
	else {//otherwise...
		listOfNames.push_back(winner);//add the winners name to the back
		listOfScores.push_back(1);//add 1 to the back of the vector
	}

	//overwrite the scores
	ofstream overwrite;//create an out file stream
	overwrite.open("scores.txt", ios::trunc); //open the file in truncate mode
	for (int i = 0; i < listOfNames.size(); i++) {//for each item in the vectors...
		overwrite << listOfNames[i] << " " << listOfScores[i] << endl;//write them to the file with a space and newline afterwards
	}
	overwrite.close();//close the file

}//END FUNCTION

void showScores() {
	ifstream inFile; //create an in file stream
	istringstream iss; //create a string stream
	string currentLine; //create a variable for each line in the txt file

	inFile.open("scores.txt", ios::in); //open the text file
	string playerName;//create a variable for the players name
	string playerScore;//create a varibale for the players scores
	system("cls"); //clear the screen
	cout << endl << "Name\tScore" << endl;//output the table field headers
	while (getline(inFile, currentLine)) { //WHILE there is a line in the file...
		iss.clear();//empty the string stream
		iss.str(currentLine);//put the current line into it
		iss >> playerName >> playerScore;//put the 1st half (the name) into playerName and the 2nd half(the score) into playerScore
		cout << playerName << "\t" << playerScore << endl; //output them to the screen
	}
	inFile.close();//close the file
	system("pause");//wait for use input
	system("cls");//clear the screen
}//END FUNCTION

void loadGame(char gameBoard[3][3]) {
	ifstream inFile;//create an in file stream
	istringstream row;//create a variable for the row
	int currentRow = 0;//create a variable to keep track of the table row
	char column1, column2, column3;//create a variable for each on the column items
	string currentLine;//create a variable for the current line of the txt file

	inFile.open("savedGame.txt", ios::in); //open the file
	if (inFile.is_open()) { //if the file is open...
		while (getline(inFile, currentLine)) {//WHILE there is a line...
			row.clear();//clear the string stream
			row.str(currentLine);//assign the current line to the string stream
			row >> column1 >> column2 >> column3; //put the values into the column variables
			column1 == '-' ? column1 = ' ' : column1 = column1;//change '-' into " " where necessary
			column2 == '-' ? column2 = ' ' : column2 = column2;//change '-' into " " where necessary
			column3 == '-' ? column3 = ' ' : column3 = column3;//change '-' into " " where necessary
			gameBoard[currentRow][0] = column1;//place values into the correct row and column
			gameBoard[currentRow][1] = column2;//place values into the correct row and column
			gameBoard[currentRow][2] = column3;//place values into the correct row and column
			currentRow++;//increament the current row counter

		}
	}
	else {//if the saved game fails to open / doesn't exist...
		cout << "No saved game exists. Creating new game." << endl; //tell the user
		for (int i = 0; i < 3; i++) {//For each row...
			for (int j = 0; j < 3; j++) {//and each column...
				gameBoard[i][j] = ' ';//assign an empty space to create a new board
			}
		}
	}
	inFile.close(); //close the file
	if (remove("savedGame.txt") == 0){//delete the previous saved game
		cout << "Loading Successful!" << endl;//give message to user to show loading success
		Sleep(300);//sleep so they have time to read the message, but its not really important
	}

}//END FUNCTION

void playGame(bool load) {
	char gameBoard[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} }; //Setup the game board
	if (load == true) {//if the load flag is true...
		loadGame(gameBoard);//run loadGame function on gameBoard
	}	
	bool gameNotWon = true;//set up the while loop variable
	char playersTurn; //setup the variable to mark whose turn it is
	bool saveFlag = false; //setup a flag to see if the users exit by saving
	//while game not won
	while (gameNotWon) {
		//see whose turn it is
		playersTurn = checkTurn(gameBoard); //check whose turn it is
		//let them input a turn
		takeTurn(playersTurn, gameBoard,saveFlag);//Check it is valid - now included in takeTurn function
		//check if anyone has won the game
		gameNotWon = !checkWin(gameBoard); //if so, break the while loop (see notes)
		if (gameNotWon) {//if no one has won (if you want to see why this is in a separate if statement, there's probably a section in NOTES)
			//check if the match is a stalemate
			gameNotWon = !checkStalemate(gameBoard);// if so break the while loop
		}
		if (gameNotWon) {
			gameNotWon = !saveFlag; //if the game is being saved, end the game loop
		}
	}//END WHILE
	cout << endl;
	system("cls"); //clear the screen
	printBoard(gameBoard);//print the final board
	if (checkWin(gameBoard)) {
		cout << "The game has been won!!" << endl; //win message
		cout << "The winner is " << playersTurn << endl; //display winner using the playersTurn Variable
		updateScore();
	}
	else if (checkStalemate(gameBoard)) {
		cout << "The game is a stalemate..." << endl; //stalemate message
		cout << "Better luck next time" << endl; //stalemate message part 2
	}
	else if (saveFlag) {
		cout << "Game has been saved." << endl; //saving message
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
			playGame(false);//run playGame() with load flag set to false
			break;
		case 2://See instructions
			showInstructions();//run showInstructions()
			break;
		case 3:
			showScores();
			break;//run showScores()
		case 4:
			playGame(true);//run playGame() with load flag set to true
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
FUNCTIONS:
	main() - the main function

	menu() - prints a menu
	getChoice() - allows program to receive user input on the menu
	checkExit() - returns true if the user wants to exit the program
	
	playGame(loadGame) - contains the while loop that governs a single game of tic tac toe
	
	showInstructions() - prints the instructions for tic tac toe
	
	printBoard(gameBoard) - shows the current game board as a 3x3 grid
	checkTurn(gameBoard) - checks the board to figure out whose turn it is and returns the char 'X' or 'O'
	
	takeTurn(playerTurn, gameBoard, (ref)saveFlag) - runs a series of functions and blocks of code to allow one turn to take place
	getTurn() - gets user input for a turn
	findSpaceOnBoard(turn, (ref)row, (ref)column) - finds the row and column an input refers to eg "BL" refers to [2][0]
	turnIsValid(turn,gameBoard) - returns true if the turn is a valid one
	
	updateBoard(turn, player, gameBoard) - makes changes to the gameBoard using the turn in findSpaceOnBoard and player to know the character to place
	
	loadGame() - uses values from a txt file to build the game board (saved as gameBoard) (makes and empty one if the file does not exist); will delete the file upon loading
	saveGame(gameBoard) - saves values from gameBoard into a txt file

	showScores() - use scores.txt to print a table of scores
	updateScores() - updates the score values in txt - user input included in the function
	
	checkWin(gameBoard) - returns true if someone has won
	checkStalemate(gameBoard) - returns true is the game is in a stalemate

KEY VARIABLES:
	notFinished - The flag for the while loop in main. While loop ends when FALSE

	gameNotWon - the falg for the while loop in playGame. While loop ends when false

	gameBoard - holds the current games 3x3 grid as an array of CHARs
	playerTurn - The character of the players whose turn it is
	
	File I/O:
		inFile - used for all ifstream variables
		outFile - used for ofstream variables where the txt file is opened in OUT mode
		ouverwrite - used for ofstream variables where the txt file is opened in TRUNC mode
		scores.txt - the txt file holding the player names and their scores
		savedGame.txt (may not exist) - is used to hold the last saved game. It is deleted when the game is loaded in

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

	popping from the from block of code
		The code was going to be used to pop the first value of the vector becuase it was always appearing as 0 in both vectors.
		I figured out why and changed the code so this wouldn't happen so I no longer need the code.
*/