#include "controller.h"
#include "minimax_agent.h"
#include "no_agent.h"

#include <QPushButton>

Controller::Controller(const Options& options, QObject* parent)
    : QObject{parent}, board{options.boardSize}, options{options}
{
    // Build graphics.
    cells = view.buildCellButtons(options.boardSize);

    // Set Connections to the UI elements.
    setConnections();

    // Specifies the type of agent, and its behaviour throughout polymorphism.
    if (options.aiOpponent && options.aiStarts)
        agent = std::make_unique<MiniMaxAgent>(options.miniMaxDepth, Mark::X, Mark::O);
    else if (options.aiOpponent)
        agent = std::make_unique<MiniMaxAgent>(options.miniMaxDepth, Mark::O, Mark::X);
    else
        agent = std::make_unique<NoAgent>();

    // Set up a new game.
    reset();
}

void Controller::startGame()
{
    // Shows the gameplay graphics.
    view.exec();
}

void Controller::setConnections()
{
    // Cell connections.
    for (Cell& cell : cells)
        connect(cell.cellButton, &QPushButton::clicked, [&]() { updateGame(cell); });

    // New Game connection - resetting the game.
    connect(&view, &Game::newGame, this, [&]() { reset(); });

    // Connect AI to play after a cell is chosen by human input.
    connect(this, &Controller::turnFinished, [=]() { aiAgentPlay(); });
}

void Controller::updateGameState(Cell& cell)
{
    // Updates the cell game.
    Game::updateCell(cell, player);

    // Update board state and declare state if it's a final state.
    State boardState{board.evaluateBoard()};
    if (boardState != State::NoWinner)
        Game::declareGameState(boardState);

    // Switch the players.
    switchPlayer();
}

void Controller::reset()
{
    // Resets the current player back to X.
    player = Mark::X;

    // Resets the game GUI elements.
    Game::reset(cells);

    // Resets the internal Representation of the board.
    board.reset();

    // Resets the AI agent.
    // Uses the arrow operator to avoid calling std::unique_pointer::reset()
    agent->reset();

    // Start AI play.
    if (options.aiStarts)
        aiAgentPlay();
}

void Controller::aiAgentPlay()
{
    int cellIndex = agent->play(board);
    if (cellIndex != Defaults::invalidCell)
        updateGameState(cells.at(static_cast<std::size_t>(cellIndex)));
}

void Controller::switchPlayer()
{
    player = (player == Mark::X) ? Mark::O : Mark::X;
}

void Controller::updateGame(Cell& cell)
{
    bool success =
        board.setPlayerInput(static_cast<std::size_t>(cell.row), static_cast<std::size_t>(cell.column), player);

    if (success)
    {
        updateGameState(cell);
        emit turnFinished();
    }
}
