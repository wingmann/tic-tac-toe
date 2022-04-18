#ifndef GAME_H
#define GAME_H

#include "globals.h"

#include <QDialog>

#include <memory>
#include <vector>

namespace Ui { class Game; }

/// @brief Responsible for the graphics of the game.
/// @details It is responsible for building the cells of a board, which can be of variable size,
/// and a navigation button to take the user back to the title screen, and a button for
/// resetting the game and playing a new one.
class Game final : public QDialog
{
private:
    Q_OBJECT

    /// @brief Reference to the graphical object of the game.
    Ui::Game* ui_;

public:
    /// @brief Constructs a game of a game.
    /// @param parent QWidget type parent that owns this instance of the controller.
    explicit Game(QWidget* parent = nullptr);

    virtual ~Game();

    /// @brief Sets the text of the cell to the current player's mark.
    /// @param cell Reference to the clicked cell.
    /// @param player Current player's mark (X or O).
    static void updateCell(Cell& cell, Mark player);

    /// @brief Outputs the board's state to a QMessageBox.
    /// @param state Current board state.
    static void declareGameState(State state);

    /// @brief Builds the graphical cells as push buttons.
    /// @param boardSize Number of rows or columns of a board.
    /// @return Collection of cells containing push button references and their corresponding row
    /// and column.
    std::vector<Cell> buildCellButtons(std::size_t boardSize);

    /// @brief Clears out the text of all push button cells.
    /// @param cells Collection of cells containing push button references and their corresponding
    /// row and column.
    static void reset(std::vector<Cell>& cells);

private:
    /// @brief Handles setting.
    /// @details Set connection to emit if cells have clicked, and the navigational back button.
    void setConnections();

    /// @brief Gets a stylesheet associated with each player.
    /// @param player Current player's mark (X or O).
    /// @return QString stylesheet of the player given in the input.
    static QString getPlayerStyleSheet(Mark player);

signals:
    /// @brief Emitted when the new game button is clicked and some reset logic must be executed.
    void newGame();
};

#endif // GAME_H
