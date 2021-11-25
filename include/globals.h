#ifndef GLOBALS_H
#define GLOBALS_H

#include <cstddef>
#include <cstdint>

class QPushButton;

namespace Defaults
{
    const std::int16_t invalidCell{-1};

    const std::uint16_t miniMaxDepth{3};
    const std::uint16_t guiCellRowSpan{1};
    const std::uint16_t guiCellColumnSpan{1};

    const std::size_t boardSize{3};

    const char xColor[]{"#555555"};
    const char oColor[]{"#555555"};
    const char defaultColor[]{"#FFFFFF"};
}

/// @brief Represents a board cell and all the necessary information need about the cell.
struct Cell
{
    Cell() = default;

    explicit Cell(QPushButton* cellButton,
                  std::int16_t row = Defaults::invalidCell,
                  std::int16_t column = Defaults::invalidCell)
        : cellButton{cellButton}, row{row}, column{column}
    {
    }

    QPushButton* cellButton{};
    std::int16_t row{};
    std::int16_t column{};
};

/// @brief Defines game options.
struct Options
{
    bool aiOpponent{true};
    bool aiStarts{};

    Options() = default;

    std::size_t boardSize{Defaults::boardSize};
    std::uint16_t miniMaxDepth{Defaults::miniMaxDepth};
};

/// @brief Defines the type of mark on the board.
enum class Mark
{
    Empty,
    X,
    O
};

/// @brief Defines the possible states of the board.
enum class State
{
    NoWinner,
    XWins,
    OWins,
    Tie
};

#endif // GLOBALS_H
