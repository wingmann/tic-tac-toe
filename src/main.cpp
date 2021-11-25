#include "title_screen.h"

#include <QApplication>

int main(int argc, char** argv)
{
    // Disable QuitOnLastWindowClosed to avoid the dialog closing after QMessageBox is closed.
    QApplication::setQuitOnLastWindowClosed(false);

#ifdef WIN32
    // Sets the graphical style of the application.
    QApplication::setStyle("fusion");
    QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Round);
#endif

    QApplication app{argc, argv};
    TitleScreen titleScreen;

    // The main window must handle the close event manually to avoid the program running after
    // closing it.
    QObject::connect(&titleScreen, &TitleScreen::exited, &app, &QApplication::quit);
    titleScreen.show();

    return QApplication::exec();
}
