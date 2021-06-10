#include "Popup.h"

void Popup::popup_win() {
    QMessageBox::information(
            this,
            tr("Winner"),
            tr("Great job! Your alchemy shop has a stellar reputation. You win!"));

}

void Popup::popup_lose() {
    QMessageBox::information(
            this,
            tr("Defeat"),
            tr("Sorry, you ran out of points. Better luck next time!"));

}

bool Popup::popup_reload() {
    switch( QMessageBox::question(
            this,
            tr("Reload?"),
            tr("Your last game's progress was saved! Would you like to reload your saved game? If not, a new game will be started."),

            QMessageBox::Yes |
            QMessageBox::No,

            QMessageBox::No ) )
    {
        case QMessageBox::Yes:
            qDebug( "yes" );
            return true;
        case QMessageBox::No:
            qDebug( "no" );
            return false;
        default:
            qDebug( "close" );
            return false;
    }
}