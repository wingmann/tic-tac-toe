#ifndef BOARD_H
#define BOARD_H

#include "globals.h"

#include <QtGlobal>

#include <vector>

/// @brief The game board.
/// @details Responsible for representing the underlying board of the game,
/// it is a two-dimensional matrix representation of the GUI that is machine readable,
/// and can be used when running any sort of algorithms on the board.
class Board
{
protected:
    /// @brief Two-dimensional vector.
    /// @details Represents a machine readable format to the graphical
    /// application.
    std::vector<std::vector<Mark>> board;

    /// @brief Number of rows or columns in the board.
    /// @details A 3x3 board has a boardSize of 3.
    std::size_t boardSize;

public:
    /// @brief Constructs a board given a board size.
    /// @param size Number of rows or columns in the board.
    explicit Board(std::size_t size);

    /// @brief Copy constructor.
    /// @param board The board to be copied.
    [[maybe_unused]] Board(Board& board) = default;

    /// @brief Assignment operator.
    /// @details Implements the copy and swap idiom, so it works as a move and a copy
    /// assignment operator.
    /// @param value Value to be copied or moved.
    /// @return Reference to this object, so this operator can be chained.
    Board& operator=(Board value);

    /// @brief Destructor.
    virtual ~Board() = default;

    /// @brief Evaluates whether the state of the current board.
    /// @details Can evaluate to X wins or O wins or a Tie or No Winner.
    /// @return State of the current board.
    [[nodiscard]] virtual State evaluateBoard() const;

    /// @brief Sets the board with the mark given in the specified location.
    /// @details After boundary checking the input row and column, and if the game has not reached
    /// a final state.
    /// @param row Row of the cell target.
    /// @param column Column of the cell target.
    /// @param player Is the mark of the current player.
    /// @return Whether the update was successful or not based on the boundary check and validity
    /// of input given the board state.
    virtual bool setPlayerInput(std::size_t row, std::size_t column, Mark player);

    /// @brief Getter function that returns a cell given a row and a column.
    /// @param row Row of the cell target.
    /// @param column Column of the cell target.
    /// @return Value mark at the cell.
    [[nodiscard]] virtual Mark at(std::size_t row, std::size_t column) const;

    /// @brief Reset allows resetting the whole board, marking all the cells as empty.
    virtual void reset();

    /// @brief Allows resetting a given cell to an empty type.
    /// @details Executes without the extra state checks done in the setPlayerInput function
    virtual void resetCell(std::size_t row, std::size_t column);

    /// @brief Getter function of the board size.
    /// @return Size of the board i.e. number of rows or columns.
    [[nodiscard]] std::size_t size() const;
};

#endif // BOARD_H
