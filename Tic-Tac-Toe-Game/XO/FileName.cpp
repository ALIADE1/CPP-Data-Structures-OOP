#include <iostream>
using namespace std;

void Draw(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|" << endl;

        if (i < 2) // Only print a line after each row except the last one
        {
            cout << " --- --- --- " << endl;
        }
    }
}

char Check(char board[3][3])
{
    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[1][1];

    if (board[1][1] != ' ' && board[1][1] == board[0][2] && board[0][2] == board[2][0])
        return board[1][1];

    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return board[i][0];
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return board[0][i];
    }

    return ' '; // No winner
}

void main()
{
    char board[3][3];

    // Initialize the board with spaces
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
            board[i][j] = ' ';
    }

    // Draw the initial empty board
    Draw(board);

    // Optionally, you can add code to handle player input and make moves here

}
