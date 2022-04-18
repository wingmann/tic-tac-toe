#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H

#include "globals.h"

#include <QMainWindow>

#include <memory>

namespace Ui { class TitleScreen; }

/// @brief Responsible for the graphics of the title screen.
/// @details It is main functionality is to gather game options set by the user,
/// then starting a game by creating a game controller with the user options.
class TitleScreen final : public QMainWindow
{
private:
    Q_OBJECT

public:
    /// @brief Reference to the UI object of the game.
    Ui::TitleScreen* ui_;

    /// @brief Values and flags that control a game.
    Options options_{};

    /// @brief Constructs the game of the title screen.
    /// @param parent QWidget type parent that owns this instance of the controller.
    explicit TitleScreen(QWidget* parent = nullptr);
    virtual ~TitleScreen();

private:
    /// @brief Sets connections to gather game options from the graphical elements.
    void setConnections();

    /// @brief Manually handles the closing event defined in the base class QWidget.
    /// @param event Closing event.
    void closeEvent(QCloseEvent* event) override;

public slots:
    /// @brief Updates the board size in the current options.
    /// @param size Number of rows or columns in the board.
    void updateBoardSize(int size);

    /// @brief Updates the AI existence flag to true as there is one player.
    /// @param checked Whether the radio button is checked or not.
    void updateSinglePlayer(bool checked);

    /// @brief Updates the AI existence flag to false as there are two player.
    /// @param checked Whether the radio button is checked or not.
    void updateTwoPlayers(bool checked);

    /// @brief Sets the AI starting the first play or not.
    /// @param checked Whether the checkbox is checked or not.
    void updateAIStartsGame(bool checked);

    /// @brief Sets the value of the depth cutoff for the minimax algorithm.
    /// @param depth Depth cutoff for the minimax algorithm.
    void updateMiniMaxDepth(int depth);

    /// @brief Hides the title screen and creates the game controller to start the game.
    void startGame();

signals:
    /// @brief Emitted to manually handle the close functionality.
    void exited();
};

#endif // TITLE_SCREEN_H
