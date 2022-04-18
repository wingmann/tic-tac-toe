#include "game.h"
#include "./ui_game.h"

#include <QMessageBox>
#include <QPushButton>

Game::Game(QWidget* parent) : QDialog{parent}, ui_{new Ui::Game}
{
    // Remove question mark from the title bar.
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui_->setupUi(this);

    // New Game connection - resetting the game.
    connect(ui_->reset, &QPushButton::clicked, this, [=]() { emit newGame(); });
    connect(ui_->back, &QPushButton::clicked, this, [=]() { close(); });
}

Game::~Game()
{
    delete ui_;
}

void Game::setConnections()
{
}

std::vector<Cell> Game::buildCellButtons(std::size_t boardSize)
{
    std::vector<Cell> cells;
    cells.reserve(boardSize * boardSize);

    for (std::size_t row = 0; row < boardSize; ++row) {
        for (std::size_t column = 0; column < boardSize; ++column) {
            // Add buttons to gridLayout
            auto button = new QPushButton{};
            button->setProperty("cell", true);

            ui_->gridBoard->addWidget(
                button,
                static_cast<int>(row),
                static_cast<int>(column),
                Defaults::guiCellRowSpan,
                Defaults::guiCellColumnSpan);

            // Reference to cells.
            cells.emplace_back(button, row, column);
        }
    }
    // Adjusts window size to fit children widgets added dynamically.
    adjustSize();

    // Return by value to allow for RVO (Copy Elision)
    return cells;
}

QString Game::getPlayerStyleSheet(Mark player)
{
    QString styleSheet{
        "font: 60px \"Corbel\";"
        "min-height: 100px;"
        "max-height: 100px;"
        "min-width: 100px;"
        "max-width: 100px;"
        "color: %1"};

    styleSheet = styleSheet.arg([&player](){
        switch (player) {
        case Mark::O:
            return Defaults::oColor;
        case Mark::X:
            return Defaults::xColor;
        default:
            return Defaults::defaultColor;
        }
    }());

    return std::move(styleSheet);
}

void Game::updateCell(Cell& cell, Mark player)
{
    // Update Cell button in graphical interface.
    cell.cellButton->setStyleSheet(getPlayerStyleSheet(player));
    cell.cellButton->setText([&player]() {
        // Converts a board mark to string.
        switch (player)
        {
        case Mark::O:
            return "O";
        case Mark::X:
            return "X";
        default:
            return "";
        }
    }());
}

void Game::declareGameState(State state)
{
    QMessageBox resultBox;
    resultBox.setWindowTitle("Result");
    resultBox.setText([&state]() {
        switch (state) {
        case State::XWins:
            return "You Won!";
        case State::OWins:
            return "Game Over";
        default:
            return "It's a Tie!";
        }
    }());

    resultBox.exec();
}

void Game::reset(std::vector<Cell>& cells)
{
    // Resets the graphical cells to an empty button with no text marks.
    for (auto& cell : cells) cell.cellButton->setText("");
}
