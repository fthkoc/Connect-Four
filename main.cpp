/******************************************************************************/
/* Folder name: 141044013								  	  			      */
/* File name: main.cpp								  	  			          */
/* Student: Fatih Koç          				                                  */
/* Date of created: 05/10/2017											  	  */
/* Last update: 08/10/2017											  	      */
/* Description: The Connect Four - HW02                                       */
/******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>

//#define DEBUG

using namespace std;

/******************************************************************************/
/* bool checkBoardSize(int boardSize)                                   	  */
/* _________																  */
/* Parameters:																  */
/* 		boardSize: Given board size for game board							  */
/* ______																	  */
/* Return:																	  */
/* 		'true' on success													  */
/* 	    'false' on error	  	  			 								  */
/* ______																	  */
/* Description: 															  */
/*		Checks for validness for user input board size.                       */
/******************************************************************************/
bool checkBoardSize(const int boardSize);

/******************************************************************************/
/* void initBoard(char (&board)[20][20],int boardSize)                    	  */
/* _________																  */
/* Parameters:																  */
/* 	    (&board)[20][20]: Game board                   		        		  */
/* 		boardSize: Given board size for game board							  */
/* ______																	  */
/* Description: 															  */
/*		Initializes game board by given board size.                            */
/******************************************************************************/
void initBoard(char (&board)[20][20],int boardSize);

/******************************************************************************/
/* void printBoard(const char (&board)[20][20], const int boardSize)          */
/* _________																  */
/* Parameters:																  */
/* 	    (&board)[20][20]: Game board                   		        		  */
/* 		boardSize: Given board size for game board							  */
/* ______																	  */
/* Description: 															  */
/*		Prints game board.                                                    */
/******************************************************************************/
void printBoard(const char (&board)[20][20], const int boardSize);

/******************************************************************************/
/* bool checkPlayer(const char versus)                                        */
/* _________																  */
/* Parameters:																  */
/* 		versus: Given character for who to play against.		              */
/* ______																	  */
/* Return:																	  */
/* 		'true' on success													  */
/* 	    'false' on error	  	  			 								  */
/* ______																	  */
/* Description: 															  */
/*		Checks for validness of user entered character for second player.     */
/******************************************************************************/
bool checkPlayer(const char versus);

/******************************************************************************/
/* char computerPlay(char (&board)[20][20], const int boardSize)              */
/* _________																  */
/* Parameters:																  */
/* 	    (&board)[20][20]: Game board                   		        		  */
/* 		boardSize: Given board size for game board							  */
/* ______																	  */
/* Return:																	  */
/* 		A character for a valid column in game board by using basic algorithm */
/* ______																	  */
/* Description: 															  */
/*		Analyses game board and finds a logical column for computer play      */
/******************************************************************************/
char computerPlay(const char (&board)[20][20], const int boardSize);

/******************************************************************************/
/* string getMove(const char (&board)[20][20], const int boardSize, const char player)*/
/* _________																  */
/* Parameters:																  */
/* 	    (&board)[20][20]: Game board                   		        		  */
/* 		boardSize: Given board size for game board							  */
/* 		player: A character for which player to get move					  */
/* ______																	  */
/* Return:																	  */
/* 		A character given by user or computer depending on 'player' character */
/* ______																	  */
/* Description: 															  */
/*		Gets character from user if player is human, else returns a character */
/*	for computer by using computerPlay(board, boardSize) function.            */
/******************************************************************************/
string getMove(const char (&board)[20][20], const int boardSize, const char player);

/******************************************************************************/
/* bool isValid(const char (&board)[20][20], const int boardSize, const string command)*/
/* _________																  */
/* Parameters:																  */
/* 	    (&board)[20][20]: Game board                   		        		  */
/* 		boardSize: Given board size for game board							  */
/* 		command: Given command for where to play on board 		              */
/* ______																	  */
/* Return:																	  */
/* 		'true' on success													  */
/* 	    'false' on error	  	  			 								  */
/* ______																	  */
/* Description: 															  */
/*		Checks for validness of given command.                                */
/******************************************************************************/
bool isValid(const char (&board)[20][20], const int boardSize, const string command);

/******************************************************************************/
/* void save(const char (&board)[20][20], const int boardSize, const string command, const char player, const char versus)*/
/* _________																  */
/* Parameters:																  */
/* 	    (&board)[20][20]: Game board                   		        		  */
/* 		boardSize: Given board size for game board							  */
/* 		command: Given command to save                                        */
/* 		player: Who's turn to play							                  */
/* 		versus: Which side to play against          						  */
/* ______																	  */
/* Description: 															  */
/*		Saves game into given file.                                           */
/******************************************************************************/

void save(const char (&board)[20][20], const int boardSize, const string command, const char player, const char versus);
/******************************************************************************/
/* void load(char (&board)[20][20], int& boardSize, const string command, char& player, char& versus)*/
/* _________																  */
/* Parameters:																  */
/* 	    (&board)[20][20]: Game board                   		        		  */
/* 		boardSize: Given board size for game board							  */
/* 		command: Given command to load                                        */
/* 		player: Who's turn to play							                  */
/* 		versus: Which side to play against          						  */
/* ______																	  */
/* Description: 															  */
/*		Loads game from given file.                                           */
/******************************************************************************/
void load(char (&board)[20][20], int& boardSize, const string command, char& player, char& versus);

/******************************************************************************/
/* void makeMove(char (&board)[20][20], int boardSize, const string& command, char& player, char& versus)*/
/* _________																  */
/* Parameters:																  */
/* 	    (&board)[20][20]: Game board                   		        		  */
/* 		boardSize: Given board size for game board							  */
/* 		command: Given command for where to play on board 		              */
/* 		player: A character for which player to make move					  */
/* 		versus: A character for which side to play against					  */
/* ______																	  */
/* Description: 															  */
/*		Puts checker on board for given player on given column.               */
/******************************************************************************/
void makeMove(char (&board)[20][20], int boardSize, const string& command, char& player, char& versus);

/******************************************************************************/
/* bool isFinished(const char (&board)[20][20], const int boardSize)          */
/* _________																  */
/* Parameters:																  */
/* 	    (&board)[20][20]: Game board                   		        		  */
/* 		boardSize: Given board size for game board							  */
/* ______																	  */
/* Return:																	  */
/* 		'true' on success													  */
/* 	    'false' on error	  	  			 								  */
/* ______																	  */
/* Description: 															  */
/*		Checks for end-game rules on given board                              */
/******************************************************************************/
bool isFinished(const char (&board)[20][20], const int boardSize);



int main() {
    char board[20][20]; // Game board
    int boardSize = 8;  // User decision for boards size
    auto versus = 'C';  // Who to play against

    std::cout << "Welcome to the Connect Four!" << std::endl;

    // Gets board size from user, checks it
    std::cout << "Board size can be 4x4, 6x6, 8x8, ..., 20x20." << std::endl;
    std::cout << "Please enter the boards size:" << std::endl;
    std::cin >> boardSize;
#ifdef DEBUG
    std::cout << "Board Size: " << boardSize << std::endl;
#endif
    if(!checkBoardSize(boardSize)){
        std::cerr << "Non valid board size! Game will close." << std::endl;
        exit(1);
    }
    std::cout << "Connect Four will start with";
    std::cout << boardSize << "x" << boardSize << " board." << std::endl;

    // Gets a character to play against, checks it
    std::cout << "Who you want to play against ?" << std::endl;
    std::cout << "'C' for against Computer." << std::endl;
    std::cout << "'P' for against 2nd Player." << std::endl;
    std::cout << "Please enter: ";
    std::cin >> versus;
#ifdef DEBUG
    std::cout << "Versus Char: " << versus << std::endl;
#endif
    if(!checkPlayer(versus)){
        std::cerr << "Wrong input to play against! Program will shut down." << std::endl;
        exit(1);
    }

    // Prepares board and prints it to the screen
    initBoard(board, boardSize);
    printBoard(board, boardSize);

    char turn = 'P'; // a variable to see who's turn to play.
    string move;     // a string to hold given command
    do{
        move = getMove(board, boardSize, turn);
#ifdef DEBUG
        std::cout << "col_vs_" << versus << "___" << turn << ": " << move << std::endl;
#endif
        if(isValid(board, boardSize, move))
            makeMove(board, boardSize, move, turn, versus);
        else{
            std::cerr << "Invalid input! Program will shut down." << std::endl;
            exit(1);
        }
        printBoard(board, boardSize);
        if(isFinished(board, boardSize))
            return 0;
#ifdef DEBUG
        std::cout << "versus_switch" << versus << std::endl;
#endif
        switch (versus) {
            case 'C':
            case 'c':
                if ((move.find("LOAD") == string::npos) && (move.find("SAVE") == string::npos)) {
                    if ((turn == 'P') || (turn == 'p'))
                        turn = 'C';
                    else if ((turn == 'C') || (turn == 'c'))
                        turn = 'P';
                }
                break;
            case 'P':
            case 'p':
                if ((move.find("LOAD") == string::npos) && (move.find("SAVE") == string::npos)) {
                    if ((turn == 'P') || (turn == 'p'))
                        turn = 'U';
                    else if (turn == 'U')
                        turn = 'P';
                }
                break;
            default:
                std::cerr << "Unexpected error at switch case, program will close." << std::endl;
                exit(1);
        }
    }while(!isFinished(board, boardSize));

    return 0;
}

/******************************************************************************/
// Checks given board size by using game rules.
bool checkBoardSize(const int boardSize){
    return (boardSize >= 4) && (boardSize <= 20) && (boardSize % 2 == 0);
}

// Prepares game board for given board size.
void initBoard(char (&board)[20][20],int boardSize){
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            board[i][j] = '.'; // Assigns default value for limited board.
        }
    }
}

// Prints game board.
void printBoard(const char (&board)[20][20], const int boardSize){
    char row = 'A';

    for (int k = 0; k < boardSize; ++k) { // Loop for print rows.
        std::cout << char (row+k); // Casting by using ASCII
    }
    std::cout << std::endl;
    for (int i = 0; i < boardSize; ++i) { // Loop for print board.
        for (int j = 0; j < boardSize; ++j) {
            std::cout << board[boardSize - 1 - i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Checks input for player to play against.
bool checkPlayer(const char versus){
    return (versus == 'C') || (versus == 'c') || (versus == 'P') || (versus == 'p');
}

// Basic algorithm for vsComputer.
char computerPlay(const char (&board)[20][20], const int boardSize){
    char col = '@';
    int random;

    for (int i = 0; i < boardSize-1; ++i) {
        for (int j = 0; j < boardSize - 1; ++j) {
            if (board[i][j] == 'O') {
                if (board[i][j + 1] == '.'){    // Look for horizontal rule
                    col = char('A' + (j + 1));
                    if(isValid(board, boardSize, &col))
                        return col;
                }
                if (board[i + 1][j] == '.'){    // Look for vertical rule
                    col = char('A' + j);
                    if(isValid(board, boardSize, &col))
                        return col;
                }
                if (board[i + 1][j + 1] == '.'){    // Look for cross rule
                    col = char('A' + (j + 1));
                    if(isValid(board, boardSize, &col))
                        return col;
                }
                if (board[i + 1][j - 1] == '.'){    // Look for cross rule
                    col = char('A' + (j - 1));
                    if(isValid(board, boardSize, &col))
                        return col;
                }
            }   // If all not available.
        }
        do {    // Find valid position by using random
            srand((unsigned) time(NULL));
            random = rand() % boardSize;
            col = char('A' + random);
        } while (!(isValid(board, boardSize, &col)));
    }
#ifdef DEBUG
    std::cout << "computerPlay(), col:" << col << std::endl;
#endif
    return col;
}

// Gets column to play.
string getMove(const char (&board)[20][20], const int boardSize, const char player){
    string result;
    string input, fileName;

    if((player == 'P') || (player == 'p')) {
        std::cout << "Enter column character to insert 'X': ";
        std::cin >> input;
        if(input.find("LOAD") != string::npos){
            std::cin >> fileName;
            result = "LOAD";
            result.append(fileName);
        }
        else if(input.find("SAVE") != string::npos){
            std::cin >> fileName;
            result = "SAVE";
            result.append(fileName);
        }
        else
            result = input[0];
#ifdef DEBUG
        std::cout << "input: " << input << std::endl;
        std::cout << "fileName: " << fileName << std::endl;
        std::cout << "result: " << result << std::endl;
#endif
    }
    else if(player == 'U') { // Special char for Player2
        std::cout << "Enter column character to insert 'O': ";
        std::cin >> input;
        if(input.find("LOAD") != string::npos){
            std::cin >> fileName;
            result = "LOAD";
            result.append(fileName);
        }
        else if(input.find("SAVE") != string::npos){
            std::cin >> fileName;
            result = "SAVE";
            result.append(fileName);
        }
        else
            result = input[0];
#ifdef DEBUG
        std::cout << "input: " << input << std::endl;
        std::cout << "fileName: " << fileName << std::endl;
        std::cout << "result: " << result << std::endl;
#endif
    }
    else if((player == 'C') || (player == 'c')){
        result = computerPlay(board, boardSize);
    }
    return result;
}

// Checks given columns availability to play.
bool isValid(const char (&board)[20][20], const int boardSize, const string command) {
    if ((command.find("LOAD") != string::npos) || (command.find("SAVE") != string::npos)) {
        return true;
    }
    else {
        decltype(toupper(command[0]) - 'A') difference = toupper(command[0]) - 'A';
#ifdef DEBUG
        std::cout << "isValid_command[0]" << command[0] << std::endl;
#endif
        if (difference < boardSize) {
            for (int i = 0; i < boardSize; ++i) {
                if (board[i][difference] == '.') {
                    return true;
                }
            }
        }
    }
    return false;
}

// File structure:
// boardSize, board size.
// versus, against who ?
// player, who's turn ?
// board
void save(const char (&board)[20][20], const int boardSize, const string command, const char player, const char versus){
    string fileName = command.substr(4,command.size());
#ifdef DEBUG
    std::cout << "save_fileName: " << fileName << std::endl;
#endif
    std::ofstream file(fileName);
    if(!file.is_open()){
        cerr << "File couldn't open in 'save'. Program will shut down!";
        exit(1);
    }
    file << versus << std::endl;
    file << player << std::endl;
    file << boardSize << std::endl;
    for (int i = 0; i < boardSize; ++i) { // Loop for print board.
        for (int j = 0; j < boardSize; ++j) {
            file << board[boardSize - 1 - i][j];
        }
        file << std::endl;
    }
    file << std::endl;
    file.close();
}

void load(char (&board)[20][20], int& boardSize, const string command, char& player, char& versus){
    string fileName = command.substr(4,command.size());
#ifdef DEBUG
    std::cout << "load_fileName: " << fileName << std::endl;
#endif
    std::ifstream file(fileName);
    if(!file.is_open()){
        cerr << "File couldn't open in 'load'. Program will shut down!";
        exit(1);
    }
    file >> versus;
    file >> player;
    file >> boardSize;
    for (int i = 0; i < boardSize; ++i) { // Loop for print board.
        for (int j = 0; j < boardSize; ++j) {
            file >> board[boardSize - 1 - i][j];
        }
    }
    file.close();
    printBoard(board, boardSize);
}


// Puts checker to given column for given player.
void makeMove(char (&board)[20][20], int boardSize, const string& command, char& player, char& versus) {

    if (command.find("LOAD") != string::npos){
        load(board, boardSize, command, player, versus);
    }
    else if(command.find("SAVE") != string::npos){
        save(board, boardSize, command, player, versus);
    }
    else {
        int difference = toupper(command[0]) - 'A';
        for (int i = 0; i < boardSize; ++i) {
            if (board[i][difference] == '.') {
                switch (player) {
                    case 'P':
                        board[i][difference] = 'X'; // condition for User
                        break;
                    case 'C':
                        board[i][difference] = 'O'; // condition for Computer
                        break;
                    default:
                        board[i][difference] = 'O'; // condition for Player2
                        break;
                }
                i = boardSize;  // to break the loop
            }
        }
    }
}

// Checks finishing conditions for the game.
bool isFinished(const char (&board)[20][20], const int boardSize){
    for (int i = 0; i < boardSize; ++i) { // Control for horizontal rule
        for (int j = 3; j < boardSize; ++j) {   // In order 3-2-1 (Keyboard order)
            if((board[i][j] == board[i][j-1]) && (board[i][j] != '.')){
                if(board[i][j] == board[i][j-2]){
                    if(board[i][j] == board[i][j-3]){
                        std::cout << std::endl;
                        std::cout << char('A' + j) << "[" << (i+1) << "], ";
                        std::cout << char('A' + j - 1) << "[" << (i+1) << "], ";
                        std::cout << char('A' + j - 2) << "[" << (i+1) << "], ";
                        std::cout << char('A' + j - 3) << "[" << (i+1) << "], ";
                        std::cout << std::endl;
                        std::cout << board[i][j] << " WINS!" << std::endl;
                        return true;
                    }
                }
            }
        }
    }

    for (int i = 3; i < boardSize; ++i) { // Control for vertical rule
        for (int j = 0; j < boardSize; ++j) {   // In order 7-4-1
            if(board[i][j] == board[i-1][j] && (board[i][j] != '.')){
                if(board[i][j] == board[i-2][j]){
                    if(board[i][j] == board[i-3][j]){
                        std::cout << std::endl;
                        std::cout << char('A' + j) << "[" << (i+1) << "], ";
                        std::cout << char('A' + j) << "[" << (i) << "], ";
                        std::cout << char('A' + j) << "[" << (i-1) << "], ";
                        std::cout << char('A' + j) << "[" << (i-2) << "], ";
                        std::cout << std::endl;
                        std::cout << board[i][j] << " WINS!" << std::endl;
                        return true;
                    }
                }
            }
        }
    }

    for (int i = 3; i < boardSize; ++i) { // Control right to left cross rule
        for (int j = 3; j < boardSize; ++j) {   // In order 9-5-1
            if(board[i][j] == board[i-1][j-1] && (board[i][j] != '.')){
                if(board[i][j] == board[i-2][j-2]){
                    if(board[i][j] == board[i-3][j-3]){
                        std::cout << std::endl;
                        std::cout << char('A' + j) << "[" << (i+1) << "], ";
                        std::cout << char('A' + j - 1) << "[" << (i) << "], ";
                        std::cout << char('A' + j - 2) << "[" << (i-1) << "], ";
                        std::cout << char('A' + j - 3) << "[" << (i-2) << "], ";
                        std::cout << std::endl;
                        std::cout << board[i][j] << " WINS!" << std::endl;
                        return true;
                    }
                }
            }
        }
    }

    for (int i = 3; i < boardSize; ++i) { // Control left to right cross rule
        for (int j = 0; j < boardSize-3; ++j) { // In order 7-5-3
            if(board[i][j] == board[i-1][j+1] && (board[i][j] != '.')){
                if(board[i][j] == board[i-2][j+2]){
                    if(board[i][j] == board[i-3][j+3]){
                        std::cout << char('A' + j) << "[" << (i+1) << "], ";
                        std::cout << char('A' + j + 1) << "[" << (i) << "], ";
                        std::cout << char('A' + j + 2) << "[" << (i-1) << "], ";
                        std::cout << char('A' + j + 3) << "[" << (i-2) << "], ";
                        std::cout << std::endl;
                        std::cout << board[i][j] << " WINS!" << std::endl;
                        return true;
                    }
                }
            }
        }
    }

    int temp = boardSize; // variable to check '.' characters in board.
    for (int i = 0; i < boardSize; ++i) { // Control for no place to add
        for (int j = 0; j < boardSize; ++j) {
            if(board[i][j] == '.')
                temp = 0;
        }
    }
    if(temp == boardSize) {
        std::cout << std::endl << "TIE!" << std::endl;
        return true;
    }

    return false;
}
/******************************************************************************/
