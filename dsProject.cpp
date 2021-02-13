#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <unordered_map>

using namespace std;

#define UNASSIGNED 0
#define N 9

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

int checkwin();
void board();


/*******************************************************
 *          Function for Rock Paper and Scissor        *
 * ****************************************************/

void rockPapperScissor(string n1,string n2,int pos1,int pos2){
unordered_map<int,string> playerMap;
playerMap[0]="Rock";
playerMap[1]="Paper";
playerMap[2]="Scissor";
int p1=(n1[pos1]-'0')%3;
int p2=(n2[pos2]-'0')%3;
if(playerMap[p1]==playerMap[p2]){
    cout<<"Draw\n";
}
else if(playerMap[p1]=="Rock" && playerMap[p2]=="Scissor"){
    cout<<"Player one wins\n";
}
else if(playerMap[p1]=="Rock" && playerMap[p2]=="Paper"){
     cout<<"Player two wins\n";
}
else if(playerMap[p1]=="Paper" && playerMap[p2]=="Scissor"){
    cout<<"Player two wins\n";
}
else if(playerMap[p1]=="Paper" && playerMap[p2]=="Rock"){
     cout<<"Player one wins\n";
}

else if(playerMap[p1]=="Scissor" && playerMap[p2]=="Rock"){
     cout<<"Player two wins\n";
}

else if(playerMap[p1]=="Scissor" && playerMap[p2]=="Paper"){
     cout<<"Player one wins\n";
}

}


/**********************************************************
 *              Function for Tic Tac Toe                  *
 * ********************************************************/

int checkwin(){
    
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
       return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;

    else
        return -1;
        }


/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/

void board(){
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}

/*******************************************************************
          FUNCTIONs TO FIND SOLUTION FOR GIVEN SUDOKO
********************************************************************/

bool FindUnassignedLocation(int grid[N][N], int &row, int &col);
bool isSafe(int grid[N][N], int row, int col, int num);
 
/* assign values to all unassigned locations for Sudoku solution  */

bool SolveSudoku(int grid[N][N]){
    int row, col;
    if (!FindUnassignedLocation(grid, row, col))
       return true;

    for (int num = 1; num <= 9; num++){
        if (isSafe(grid, row, col, num)){
            grid[row][col] = num;
            if (SolveSudoku(grid))
                return true;
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}
 
/* Searches the grid to find an entry that is still unassigned. */
bool FindUnassignedLocation(int grid[N][N], int &row, int &col){
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}
 
/* Returns whether any assigned entry n the specified row matches 
   the given number. */

bool UsedInRow(int grid[N][N], int row, int num){
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;

    return false;
}
 
/* Returns whether any assigned entry in the specified column matches 
   the given number. */

bool UsedInCol(int grid[N][N], int col, int num){
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;

    return false;
}
 
/* Returns whether any assigned entry within the specified 3x3 box matches 
   the given number. */

bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num){
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;

    return false;
}
 
/* Returns whether it will be legal to assign num to the given row,col location. */

bool isSafe(int grid[N][N], int row, int col, int num){
    
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row % 3 , col - col % 3, num);
}
 
/* print grid  */

void printGrid(int grid[N][N]){
    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++)
            cout<<grid[row][col]<<"  ";
        cout<<endl;
    }

}

int main() {
    
    int game_choice;
    cout<<"Welcome to MINEGEM"<<endl;
    cout<<"We have 3 games for you (Choose from the following):\n";
    cout<<"1. Rock Paper and Scissor\n";
    cout<<"2. Tic Tac Toe\n";
    cout<<"3. Sudoko Solver\n";
    
    cin>>game_choice;
    cout<<endl;
    
    if(game_choice==1){
    string n1,n2;
    int pos1,pos2;
    cout<<"Player one, It's your turn please enter your choice and secret bit position\n";
    cin>>n1>>pos1;
    cout<<"Player two, It's your turn please enter your choice and secret bit position\n";
    cin>>n2>>pos2;
    rockPapperScissor(n1,n2,pos1,pos2);
    }
    
    cout<<endl;
    
    if(game_choice==2){
        int player = 1,i,choice;
        char mark;
        do{
        board();
        player=(player%2)?1:2;
        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;
        mark=(player == 1) ? 'X' : 'O';
        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else{
            cout<<"Invalid move "<<endl;
            player--;
            cin.ignore();
            cin.get();
        }

        i=checkwin();
        player++;
    }while(i==-1);
    board();
    if(i==1)
        cout<<"==>\aPlayer "<<--player<<" win ";
    
    else
        cout<<"==>\aGame draw";

    cin.ignore();
    cin.get();
    return 0;
    }

    cout<<endl;

    if(game_choice==3){
        int grid[N][N] ;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>grid[i][j];
            }
        }

    if (SolveSudoku(grid) == true)
          printGrid(grid);
    
    else
        cout<<"No solution exists"<<endl;
    
    }

    cout<<"\n ****************** THANK YOU :) ********************** \n";
}
