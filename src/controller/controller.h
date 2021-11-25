#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ai_agent.h"
#include "board.h"
#include "game.h"
#include "globals.h"

#include <QObject>

#include <memory>
#include <vector>

/// @brief Controller for the game.
/// @details It takes in game options as input, and controls the game and the board according to the
/// game logic specified in this class, it is also responsible for calling the AI agent to
/// play its turn if specified by the game options.
class Controller : public QObject
{
private:
    Q_OBJECT

public:
    /// @brief View class of a tic tac toe game.
    Game view{};

    /// @brief Represents the underlying layer of a game.
    Board board;

    /// @brief Collection of cell buttons built by the game class.
    std::vector<Cell> cells;

    /// @brief Collection of values and flags that controls the game.
    const Options& options;

    /// @brief Player that will play the current turn.
    Mark player{Mark::X};

    /// @brief AI agent chosen to play against the human player.
    std::unique_ptr<AIAgent> agent;

    /// @brief Controller constructs a game controller.
    /// @param options Collection of values and flags that controls the game.
    /// @param parent QObject type parent that owns this instance of the controller.
    explicit Controller(const Options& options, QObject* parent = nullptr);

    /// @brief Executes this QDialog to show the GUI and start the gameplay.
    virtual void startGame();

protected:
    /// @brief Updates the game and the board and switches the current player.
    /// @param cell Clicked cell that the player chooses.
    virtual void updateGameState(Cell& cell);

    /// @brief Calls the AI agent to play given the current board inputs.
    virtual void aiAgentPlay();

    /// @brief Switches the current player mark (X to O and O to X).
    virtual void switchPlayer();

private:
    /// @brief Set a connection to all GUI elements to slots defined to handle these events.
    void setConnections();

    /// @brief Resets all internal components, the game, the board and the AI agent.
    /// @details Then if AI is supposed to start a game it will play first.
    void reset();

public slots:
    /// @brief Sets the cell clicked in the board (Board).
    /// @param cell: Clicked cell that the player chooses.
    virtual void updateGame(Cell& cell);

signals:
    /// @brief Emitted when the human player is finished with the cell input,\n and the internal
    /// game state is supposed to be updated.
    void turnFinished();
};

#endif // CONTROLLER_H
