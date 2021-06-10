//
// Created by 16136 on 2021-06-10.
//

#ifndef ALCHEMY_SHOP_GAME_H
#define ALCHEMY_SHOP_GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Potion.h"
#include "Label.h"
#include "Customer.h"
#include "BaseIngredient.h"
#include "Popup.h"
class Game: public QGraphicsView {
public:
    Game(QWidget *parent = 0);

    QGraphicsScene *scene;
    Label *label;
    Popup *popup;
    Customer *customer;
    BaseIngredient *baseIngredient;
    Potion *potion;

};
#endif //ALCHEMY_SHOP_GAME_H
