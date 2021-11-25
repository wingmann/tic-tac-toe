/********************************************************************************
** Form generated from reading UI file 'title_screen.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLE_SCREEN_H
#define UI_TITLE_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TitleScreen
{
public:
    QWidget* centralwidget;
    QGridLayout* gridLayout;
    QPushButton* startGame_2;
    QPushButton* startGame;
    QGroupBox* groupBox;
    QCheckBox* AIStarts;
    QLabel* label_3;
    QLabel* label_2;
    QLabel* label_4;
    QLabel* label_5;
    QWidget* layoutWidget;
    QHBoxLayout* horizontalLayout;
    QSlider* BoardSize;
    QLabel* boardSizeValue;
    QWidget* layoutWidget1;
    QHBoxLayout* horizontalLayout_3;
    QSlider* MiniMaxDepth;
    QLabel* miniMaxDepthValue;
    QWidget* layoutWidget2;
    QHBoxLayout* horizontalLayout_2;
    QRadioButton* onePlayer;
    QRadioButton* twoPlayers;
    QLabel* label;

    void setupUi(QMainWindow* TitleScreen)
    {
        if (TitleScreen->objectName().isEmpty())
            TitleScreen->setObjectName(QString::fromUtf8("TitleScreen"));
        TitleScreen->resize(481, 391);
        TitleScreen->setMinimumSize(QSize(481, 391));
        TitleScreen->setMaximumSize(QSize(481, 391));
        centralwidget = new QWidget(TitleScreen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        startGame_2 = new QPushButton(centralwidget);
        startGame_2->setObjectName(QString::fromUtf8("startGame_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(startGame_2->sizePolicy().hasHeightForWidth());
        startGame_2->setSizePolicy(sizePolicy);
        startGame_2->setMinimumSize(QSize(200, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("MS Shell Dlg 2")});
        font.setPointSize(9);
        font.setBold(false);
        startGame_2->setFont(font);

        gridLayout->addWidget(startGame_2, 2, 1, 1, 1);

        startGame = new QPushButton(centralwidget);
        startGame->setObjectName(QString::fromUtf8("startGame"));
        sizePolicy.setHeightForWidth(startGame->sizePolicy().hasHeightForWidth());
        startGame->setSizePolicy(sizePolicy);
        startGame->setMinimumSize(QSize(200, 30));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        startGame->setFont(font1);

        gridLayout->addWidget(startGame, 2, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font2;
        font2.setPointSize(10);
        groupBox->setFont(font2);
        AIStarts = new QCheckBox(groupBox);
        AIStarts->setObjectName(QString::fromUtf8("AIStarts"));
        AIStarts->setEnabled(true);
        AIStarts->setGeometry(QRect(143, 118, 16, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(32, 118, 96, 18));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Verdana")});
        font3.setPointSize(9);
        label_3->setFont(font3);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(32, 84, 41, 18));
        label_2->setFont(font3);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(32, 148, 44, 18));
        label_4->setFont(font3);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(32, 48, 80, 18));
        label_5->setFont(font3);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(144, 49, 102, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        BoardSize = new QSlider(layoutWidget);
        BoardSize->setObjectName(QString::fromUtf8("BoardSize"));
        BoardSize->setMinimum(3);
        BoardSize->setMaximum(5);
        BoardSize->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(BoardSize);

        boardSizeValue = new QLabel(layoutWidget);
        boardSizeValue->setObjectName(QString::fromUtf8("boardSizeValue"));
        boardSizeValue->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(boardSizeValue);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(144, 149, 102, 24));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        MiniMaxDepth = new QSlider(layoutWidget1);
        MiniMaxDepth->setObjectName(QString::fromUtf8("MiniMaxDepth"));
        MiniMaxDepth->setEnabled(true);
        MiniMaxDepth->setMinimum(1);
        MiniMaxDepth->setMaximum(20);
        MiniMaxDepth->setValue(3);
        MiniMaxDepth->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(MiniMaxDepth);

        miniMaxDepthValue = new QLabel(layoutWidget1);
        miniMaxDepthValue->setObjectName(QString::fromUtf8("miniMaxDepthValue"));
        miniMaxDepthValue->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(miniMaxDepthValue);

        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(144, 85, 182, 27));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        onePlayer = new QRadioButton(layoutWidget2);
        onePlayer->setObjectName(QString::fromUtf8("onePlayer"));
        QFont font4;
        font4.setPointSize(9);
        onePlayer->setFont(font4);
        onePlayer->setChecked(true);

        horizontalLayout_2->addWidget(onePlayer);

        twoPlayers = new QRadioButton(layoutWidget2);
        twoPlayers->setObjectName(QString::fromUtf8("twoPlayers"));
        twoPlayers->setChecked(false);

        horizontalLayout_2->addWidget(twoPlayers);

        gridLayout->addWidget(groupBox, 1, 0, 1, 2);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Source Code Pro")});
        font5.setPointSize(30);
        font5.setBold(true);
        font5.setStyleStrategy(QFont::PreferDefault);
        label->setFont(font5);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        TitleScreen->setCentralWidget(centralwidget);

        retranslateUi(TitleScreen);

        QMetaObject::connectSlotsByName(TitleScreen);
    } // setupUi

    void retranslateUi(QMainWindow* TitleScreen)
    {
        TitleScreen->setWindowTitle(QCoreApplication::translate("TitleScreen", "Tic Tac Toe", nullptr));
        startGame_2->setText(QCoreApplication::translate("TitleScreen", "Quit", nullptr));
        startGame->setText(QCoreApplication::translate("TitleScreen", "Start", nullptr));
        groupBox->setTitle(QCoreApplication::translate("TitleScreen", "Options", nullptr));
        AIStarts->setText(QString());
        label_3->setText(QCoreApplication::translate("TitleScreen", "AI starts first", nullptr));
        label_2->setText(QCoreApplication::translate("TitleScreen", "Mode", nullptr));
        label_4->setText(QCoreApplication::translate("TitleScreen", "Depth", nullptr));
        label_5->setText(QCoreApplication::translate("TitleScreen", "Board Size", nullptr));
        boardSizeValue->setText(QCoreApplication::translate("TitleScreen", "3", nullptr));
        miniMaxDepthValue->setText(QCoreApplication::translate("TitleScreen", "3", nullptr));
        onePlayer->setText(QCoreApplication::translate("TitleScreen", "1 Player", nullptr));
        twoPlayers->setText(QCoreApplication::translate("TitleScreen", "2 Players", nullptr));
        label->setText(QCoreApplication::translate("TitleScreen", "TIC TAC TOE", nullptr));
    } // retranslateUi
};

namespace Ui
{
    class TitleScreen : public Ui_TitleScreen
    {
    };
}

QT_END_NAMESPACE

#endif // UI_TITLE_SCREEN_H
