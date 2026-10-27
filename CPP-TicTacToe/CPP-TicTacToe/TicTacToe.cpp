#include "TicTacToe.h"
#include <iostream>

using namespace std;

// Constructor!!
TicTacToe::TicTacToe()
{
    for (int i = 0; i < 9; i++) //Game can only have a max of 9 turns.
    {
        m_board[i] = ' ';
    }

    m_currentPlayer = 0;
}

// This is to form/display the game board.
void TicTacToe::Display() const
{
    cout << endl;

    for (int i = 0; i < 9; i++)
    {
        if (m_board[i] == ' ')
        {
            cout << i + 1;
        }
        else
        {
            cout << m_board[i];
        }

        if (i % 3 != 2)
        {
            cout << " | ";
        }
        else if (i != 8)
        {
            cout << "\n---------\n";
        }
    }

    cout << "\n\nCurrent Player: "
        << (m_currentPlayer == 0 ? 'X' : 'O')
        << endl;
}

void TicTacToe::TakeTurn()
{
    int position;
    char mark = (m_currentPlayer == 0) ? 'X' : 'O';

    while (true)
    {
        cout << "Enter a number 1-9: ";
        cin >> position;

        position--;

        if (position < 0 || position > 8)
        {
            cout << "Please try again.\n";
            continue;
        }

        if (m_board[position] != ' ')
        {
            cout << "That space is taken.\n";
            continue;
        }

        m_board[position] = mark;
        break;
    }

    // This is to switch between players!!!
    m_currentPlayer = 1 - m_currentPlayer;
}

// This checks whether or notthe game is over.
bool TicTacToe::IsGameOver() const
{
    int wins[8][3] =
    {
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {0,3,6},
        {1,4,7},
        {2,5,8},
        {0,4,8},
        {2,4,6}
    };

	// Winner
    for (int i = 0; i < 8; i++)
    {
        int a = wins[i][0];
        int b = wins[i][1];
        int c = wins[i][2];

        if (m_board[a] != ' ' &&
            m_board[a] == m_board[b] &&
            m_board[b] == m_board[c])
        {
			cout << "\nPlayer " << m_board[a] << " wins!\n"; // Shows which player won the game.
            return true;
        }
    }

    // Tie
    bool boardFull = true;

    for (int i = 0; i < 9; i++)
    {
        if (m_board[i] == ' ')
        {
            boardFull = false;
            break;
        }
    }

    if (boardFull)
    {
        cout << "\nWow! It's a tie!\n";
        return true;
    }

    return false;
}