#include <iostream>
using namespace std;

void PrintBoard(char board[3][3]) { 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j != 0) {
                cout << " |";
            }
            cout << " " << board[i][j];
        }
        cout << endl;
        if (i < 2) {
            cout << "---|---|---" << endl;
        }
    }
}

void MarkBoard(char board[3][3], int number, char marker, int &move){
   
    //get row and col cordinates 
    int row = (number - 1) / 3; //(number -1) because this way I get the exact number I want
    int col = (number - 1) % 3; //example for '9' board[2][2]: (9 - 1) / 3 = 8/3 = 2 and 8%3 = 2 BUT 9/3 = 3 and board[3][3] doesn't exist

    //check if the spot is taken
    if (board[row][col] != 'X' && board[row][col] != 'O'){
        board[row][col] = marker;          
        move = 0;
    }
    else {
        cout << "\nThis spot is already taken. Pick another one: ";    
        move = -1;
    }
}

void Check_Win_Condition(bool &win_condition, char board[3][3], char marker) {
    
    //check rows for win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == marker && board[i][1] == marker && board[i][2] == marker) {
            win_condition = true;
            return; 
        }
    }
    
    //check columns for win
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == marker && board[1][i] == marker && board[2][i] == marker) {
            win_condition = true;
            return; 
        }
    }
    
    //check first diagonal
    if (board[0][0] == marker && board[1][1] == marker && board[2][2] == marker) {
        win_condition = true;
        return; 
    }
    
    //check second diagonal
    if (board[0][2] == marker && board[1][1] == marker && board[2][0] == marker) {
        win_condition = true;
        return; 
    }
}


int main() {
    //start Player_X vs Player_O code 
    bool play_again = true;

    


    while (play_again) {
        //variables to end the game
        int i = 0;
        bool win_condition = false;
        string answer = "yes"; 
        int move;

       


        //show board
        char board[3][3] = { {'1', '2', '3'},
                             {'4', '5', '6'},
                             {'7', '8', '9'} };
        PrintBoard(board);
        

        
        //start the game
        cout << endl << "Enter the number in which spot you want to place your marker\n";
        int number;
        char marker;
        while (i < 9 && !win_condition) {
            if (i % 2 == 0) {                
                cout << "X is playing \n";
                marker = 'X';
            } else {
                cout << "O is playing \n";    
                marker = 'O';
            }

            do {
                cout << "Give a number: ";    
                cin >> number;
                if (number < 1 || number > 9) {
                    cout << "Please choose a number between 1 and 9.\n";
                    move = -1;
                } else {
                    MarkBoard(board, number, marker, move);
                }
            } while (move == -1);

            PrintBoard(board);
            Check_Win_Condition(win_condition, board, marker);
            if (win_condition == true){
                cout << "\n" << marker << " is the winner";
            }
            ++i;
        }

        
        
        
        //play again?
        do {
            cout << "\nDo you want to play again?\nType 'yes' to play again or 'no' to stop: "; 
            cin >> answer;
        } while (answer != "yes" && answer != "no");

        if (answer == "no") {
            play_again = false;
        }
    }
    return 0;
}
