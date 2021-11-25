#include "title_screen.h"
#include "controller.h"

TitleScreen::TitleScreen(QWidget* parent) : QMainWindow{parent}, ui_{new Ui::TitleScreen}
{
    ui_->setupUi(this);
    setConnections();
}

void TitleScreen::setConnections()
{
    connect(ui_->BoardSize,    SIGNAL(valueChanged(int)), SLOT(updateBoardSize(int)));
    connect(ui_->onePlayer,    SIGNAL(toggled(bool)),     SLOT(updateSinglePlayer(bool)));
    connect(ui_->twoPlayers,   SIGNAL(toggled(bool)),     SLOT(updateTwoPlayers(bool)));
    connect(ui_->AIStarts,     SIGNAL(toggled(bool)),     SLOT(updateAIStartsGame(bool)));
    connect(ui_->MiniMaxDepth, SIGNAL(valueChanged(int)), SLOT(updateMiniMaxDepth(int)));
    connect(ui_->startGame,    SIGNAL(clicked()),         SLOT(startGame()));
}

void TitleScreen::updateBoardSize(int size)
{
    ui_->boardSizeValue->setText(QString::number(size));
    options_.boardSize = static_cast<std::size_t>(size);
}

void TitleScreen::updateSinglePlayer(bool checked)
{
    if (checked)
    {
        ui_->AIStarts->setEnabled(true);
        ui_->MiniMaxDepth->setEnabled(true);
        options_.aiOpponent = true;
    }
}

void TitleScreen::updateTwoPlayers(bool checked)
{
    if (checked)
    {
        ui_->AIStarts->setEnabled(false);
        ui_->MiniMaxDepth->setEnabled(false);
        options_.aiOpponent = false;
    }
}

void TitleScreen::updateAIStartsGame(bool checked)
{
    options_.aiStarts = checked;
}

void TitleScreen::updateMiniMaxDepth(int depth)
{
    ui_->miniMaxDepthValue->setText(QString::number(depth));
    options_.miniMaxDepth = static_cast<std::uint16_t>(depth);
}

void TitleScreen::startGame()
{
    this->hide();
    Controller controller{options_};
    controller.startGame();
    this->show();
}

void TitleScreen::closeEvent(QCloseEvent* event)
{
    QMainWindow::closeEvent(event);
    emit exited();
}
