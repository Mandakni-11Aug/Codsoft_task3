#include<iostream>
using namespace std;

char board[3][3];
char gamePlayer;

void initializetheBoard() {
    char start = '1';
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = start++;
        }
    }
}

void displayinboard() {
    cout << "\n";
    for (int i = 0; i < 3; i++){
        cout << " ";
        for (int j = 0; j <3; j++){
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i <2 ) cout << "---|---|---\n";
    }
    cout << "\n";
}
bool placeMark(int choice) {
    int row = (choice - 1) / 3;
    int col = (choice -1) %3;

    if (board[row][col] != 'X' && board[row][col] != '0') {
        board[row][col] = gamePlayer;
        return true;

    } else {
        return false;
    }
}

 bool checkhowWin() {
   // Rows and Coloums
   for (int i = 0; i < 3; i++) {
    if ((board[i][0] == gamePlayer &&
        board[i][1] == gamePlayer &&
        board[i][2] == gamePlayer) ||
       (board[0][i] == gamePlayer &&
        board[1][i] == gamePlayer && 
        board[2][i] == gamePlayer)) {
    return true;
}
   }
   // Diagonals
   if ((board[0][0] == gamePlayer &&
        board[1][1] == gamePlayer &&
        board[2][2] == gamePlayer) ||
       (board[0][2] == gamePlayer &&
       board[1][1] == gamePlayer && 
       board[2][0] == gamePlayer)) {
    return true;
 }
 return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
    if (board[i][j] != 'X' && board[i][j] != '0')
    return false;
    return true;
}

void switchPlayer() {
    gamePlayer = (gamePlayer == 'X') ? '0' : 'X';
}

int main () {
    char playAgain;

    do {
        initializetheBoard();
        gamePlayer = 'X';
        bool gameWon = false, gameDraw = false;

        cout << "Welcome to the Tic-Tac-Toe!\n";

while (true) {
    displayinboard();
    int move; 
    cout << " Player " << gamePlayer << ", enter your move(1-9): ";
    cin >> move;

    if (move < 1 || move > 9 || !placeMark(move)){
        cout << "Invalid move! Try again. \n";
        continue;
    }

    gameWon = checkhowWin ();
    if (gameWon) {
        displayinboard();
        cout << " Player " << gamePlayer << " wins!\n ";
        break;
    }

    gameDraw = checkDraw();
    if(gameDraw) {
        displayinboard();
        cout << "It's a draw!\n";
        break;
    }
    switchPlayer();
}
cout << "Do you want to play again? (Yes/No): ";
cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing!\n";
    return 0;
}