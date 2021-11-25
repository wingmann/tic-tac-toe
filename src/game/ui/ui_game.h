/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QVBoxLayout* verticalLayout_2;
    QHBoxLayout* horizontalLayout;
    QVBoxLayout* verticalLayout;
    QGridLayout* gridBoard;
    QHBoxLayout* horizontalLayout_2;
    QPushButton* back;
    QPushButton* reset;

    void setupUi(QDialog* Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QString::fromUtf8("Game"));
        Game->setWindowModality(Qt::WindowModal);
        Game->resize(538, 368);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Game->sizePolicy().hasHeightForWidth());
        Game->setSizePolicy(sizePolicy);
        Game->setMinimumSize(QSize(0, 0));
        Game->setMaximumSize(QSize(16777215, 16777215));
        Game->setStyleSheet(QString::fromUtf8("QPushButton[cell=true]{\n"
                                              "font: 50px \"Verdana\";\n"
                                              "min-height: 100px;\n"
                                              "max-height: 100px;\n"
                                              "min-width: 100px;\n"
                                              "max-width: 100px;\n"
                                              "}\n"
                                              ""));
        verticalLayout_2 = new QVBoxLayout(Game);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridBoard = new QGridLayout();
        gridBoard->setSpacing(0);
        gridBoard->setObjectName(QString::fromUtf8("gridBoard"));

        verticalLayout->addLayout(gridBoard);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        back = new QPushButton(Game);
        back->setObjectName(QString::fromUtf8("back"));
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        back->setFont(font);

        horizontalLayout_2->addWidget(back);

        reset = new QPushButton(Game);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setEnabled(true);
        reset->setFont(font);

        horizontalLayout_2->addWidget(reset);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2->addLayout(horizontalLayout);

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QDialog* Game)
    {
        Game->setWindowTitle(QCoreApplication::translate("Game", "Tic Tac Toe", nullptr));
        back->setText(QCoreApplication::translate("Game", "Back", nullptr));
        reset->setText(QCoreApplication::translate("Game", "New Game", nullptr));
    } // retranslateUi
};

namespace Ui
{
    class Game : public Ui_Game
    {
    };
}

QT_END_NAMESPACE

#endif // UI_GAME_H
