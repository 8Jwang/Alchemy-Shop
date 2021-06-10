#include "Label.h"
#include <QGuiApplication>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <sstream>

int Label::count = 0;

Label::Label(int og_x, int og_y, QPixmap image, string name, int id) {
    this -> id = id;
    this -> og_x = og_x;
    this -> og_y = og_y;
    this -> image = image;
    this -> name = name;

    setOffset(og_x, og_y);
    setPixmap(image);
}

Label::Label(int og_x, int og_y, QPixmap image, string name) {
    this -> og_x = og_x;
    this -> og_y = og_y;
    this -> image = image;
    this -> name = name;

    setOffset(og_x, og_y);
    setPixmap(image);

    id = count++;

}

void Label::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event -> button() == Qt::LeftButton) {
        Label *img = new Label(og_x, og_y, image, name, id);
        img -> setPixmap(image);
        img -> setOffset(og_x,og_y);
        scene() -> addItem(img);
        qDebug() << id;

        //Label *temp = new Label(og_x, og_y, image, name, id);
    }
}

void Label::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    int posx = event -> scenePos().x();
    int posy = event -> scenePos().y();

    setOffset(posx-32, posy-32);
}

void Label::setName(string n) {
    name = n;
}

int Label::getId()
{
    return id;
}

string Label::getName()
{
    return name;
}

string Label::toString() {
    stringstream ss;

    ss << "name: ";
    ss << name;
    ss << "; id: ";
    ss << id;

    return ss.str();
}