//
// Created by 16136 on 2021-06-10.
//

#ifndef ALCHEMY_SHOP_POPUP_H
#define ALCHEMY_SHOP_POPUP_H
#include <QMessageBox>
#include <QInputDialog>
#include <QIcon>

class Popup : public QWidget {
public:
    void popup_win();
    void popup_lose();
    bool popup_reload();
};

#endif //ALCHEMY_SHOP_POPUP_H
