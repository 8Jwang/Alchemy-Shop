//
// Created by 16136 on 2021-06-10.
//

#ifndef ALCHEMY_SHOP_LABEL_H
#define ALCHEMY_SHOP_LABEL_H
#include <iostream>
#include <QMouseEvent>
#include <QEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>

using namespace std;

class Label: public QGraphicsPixmapItem {

private:
    int og_x;
    int og_y;
    QPixmap image;
    string name;
    int id;
    int numIng;
    static int count;

public:
    Label(int og_x, int og_y, QPixmap image, string name);
    Label(int og_x, int og_y, QPixmap image, string name, int id);
    void setName(string n);
    int getId();
    string getName();
    string toString();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *e);

};

#endif //ALCHEMY_SHOP_LABEL_H
