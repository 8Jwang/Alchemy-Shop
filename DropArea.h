//
// Created by 16136 on 2021-06-10.
//

#ifndef ALCHEMY_SHOP_DROPAREA_H
#define ALCHEMY_SHOP_DROPAREA_H
#include <QLabel>

class DropArea : public QLabel
{
Q_OBJECT

public:
    explicit DropArea(QWidget *parent = nullptr);

public slots:
    void clear();

signals:
    void changed(const QMimeData *mimeData = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dropEvent(QDropEvent *event) override;

private:
    QLabel *label;
};

#endif //ALCHEMY_SHOP_DROPAREA_H