
#pragma once

#include "Game.h"

class TicTacToe : public Game
{
private:
    char m_board[9];
    int m_currentPlayer;

public:
    TicTacToe();

    bool IsGameOver() const override;
    void TakeTurn() override;
    void Display() const override;
};

