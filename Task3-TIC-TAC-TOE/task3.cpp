#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

char currentPlayer = 'X';

// Function to display the board
void displayBoard()
{
    cout << "\n";
    cout << "     TIC TAC TOE\n";
    cout << "-----------------------\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "     ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];

            if (j < 2)
                cout << " | ";
        }

        cout << endl;

        if (i < 2)
            cout << "    -----------" << endl;
    }

    cout << endl;
}

// Function to place player's mark
bool makeMove(int choice)
{
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = currentPlayer;
        return true;
    }

    return false;
}

// Function to check winner
bool checkWinner()
{
    // Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return true;
    }

    // Diagonal
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return true;

    // Anti-diagonal
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return true;

    return false;
}

// Function to check draw
bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' &&
                board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

int main()
{
    int choice;

    cout << "==================================" << endl;
    cout << "       TIC TAC TOE GAME" << endl;
    cout << "==================================" << endl;

    while (true)
    {
        displayBoard();

        cout << "Player " << currentPlayer
             << ", enter your choice (1-9): ";

        cin >> choice;

        if (choice < 1 || choice > 9)
        {
            cout << "\nInvalid choice! Please enter a number between 1 and 9.\n";
            continue;
        }

        if (!makeMove(choice))
        {
            cout << "\nThat position is already occupied. Try again.\n";
            continue;
        }

        if (checkWinner())
        {
            displayBoard();

            cout << "==================================" << endl;
            cout << "Congratulations Player "
                 << currentPlayer
                 << "! You Win!" << endl;
            cout << "==================================" << endl;

            break;
        }

        if (checkDraw())
        {
            displayBoard();

            cout << "==================================" << endl;
            cout << "The Game is a Draw!" << endl;
            cout << "==================================" << endl;

            break;
        }

        // Switch player
        if (currentPlayer == 'X')
            currentPlayer = 'O';
        else
            currentPlayer = 'X';
    }

    return 0;
}