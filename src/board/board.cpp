#include "board.h"

Board::Board(std::size_t size) : board{size, std::vector<Mark>(size, Mark::Empty)}, boardSize{size}
{
}

Board& Board::operator=(Board value)
{
    std::swap(board, value.board);
    std::swap(boardSize, value.boardSize);
    return *this;
}

bool Board::setPlayerInput(std::size_t row, std::size_t column, Mark player)
{
    // The game is over, so no input is allowed until game resets.
    if (evaluateBoard() != State::NoWinner) return false;

    // Cell is not empty.
    if (board[row][column] != Mark::Empty) return false;

    // Update cell with current player's mark.
    board[row][column] = player;
    return true;
}

void Board::resetCell(std::size_t row, std::size_t column)
{
    board[row][column] = Mark::Empty;
}

Mark Board::at(std::size_t row, std::size_t column) const
{
    return board.at(row).at(column);
}

State Board::evaluateBoard() const
{
    auto checkForEquals = [](const Mark& ref)
    {
        switch (ref)
        {
        case Mark::X:
            [[likely]] return State::XWins;
        case Mark::O:
            [[likely]] return State::OWins;
        default:
            // Unreachable branch. Required for correct execution.
            [[unlikely]] return State::NoWinner;
        }
    };

    // Check rows for a win for the current player.
    for (std::size_t row = 0; row < boardSize; ++row)
    {
        bool equalRow{true};
        Mark ref{board[row][0]};

        for (std::size_t column = 1; column < boardSize; ++column)
            if (ref != board[row][column])
                equalRow = false;

        if (equalRow)
            return checkForEquals(ref);
    }

    // Checks columns for a win for the current player.
    for (std::size_t column = 0; column < boardSize; ++column)
    {
        bool equalColumn{true};
        Mark ref{board[0][column]};

        for (std::size_t row = 1; row < boardSize; ++row)
            if (ref != board[row][column])
                equalColumn = false;

        if (equalColumn)
            return checkForEquals(ref);
    }

    // Checks diagonals for a win for the current player.
    bool equalDiagonal{true};
    Mark ref{board[0][0]};

    for (std::size_t i = 1; i < boardSize; ++i)
        if (ref != board[i][i])
            equalDiagonal = false;

    if (equalDiagonal)
        return checkForEquals(ref);

    equalDiagonal = true;
    ref = board[0][boardSize - 1];

    for (std::size_t row = 1; row < boardSize; ++row)
        if (ref != board[row][boardSize - row - 1])
            equalDiagonal = false;

    if (equalDiagonal)
        return checkForEquals(ref);

    // If there is an empty cell and no winner is determined, then the game is still ongoing.
    for (std::size_t row = 0; row < boardSize; ++row)
        for (std::size_t column = 0; column < boardSize; ++column)
            if (board[row][column] == Mark::Empty)
                return State::NoWinner;

    // If no winner is determined and there are no empty cells, then the game is a tie.
    return State::Tie;
}

void Board::reset()
{
    // Sets all the cells to empty.
    for (std::size_t row = 0; row < boardSize; ++row)
        for (std::size_t column = 0; column < boardSize; ++column)
            board[row][column] = Mark::Empty;
}

std::size_t Board::size() const
{
    return boardSize;
}
