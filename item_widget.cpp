//
// Created by alisher on 7/27/21.
//
#include <QDrag>
#include <QDebug>
#include <QLabel>
#include <QPainter>
#include <QMimeData>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QApplication>

#include "item_widget.hpp"

ItemWidget::ItemWidget(QWidget *parent, const QSize &size) : QWidget(parent) {
  resize(size);
}

void ItemWidget::setItem(const Item &item) {
  item_ = item;
  image_ = new QImage();
  if (not image_->load("../resources/" + item.impath())) {
    throw std::runtime_error("pixmap '../resources/" + item.impath().toStdString() + "' was not found");
  }
}

void ItemWidget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.drawPixmap(rect(), QPixmap::fromImage(*image_).scaled(size()));
}

void ItemWidget::enterEvent(QEvent *event) {
  setToolTip(to_string(item_.type()));
}

void ItemWidget::mousePressEvent(QMouseEvent *event) {
  mouse_press_pos_ = event->pos();
}

void ItemWidget::mouseMoveEvent(QMouseEvent *event) {
  if (not event->buttons() & Qt::LeftButton
      or QApplication::startDragDistance() > (event->pos() - mouse_press_pos_).manhattanLength()) {
    return;
  }

  auto drag = new QDrag(this);
  auto data = new QMimeData;
  data->setImageData(1);
  data->setText(to_string(item_.type()));

  drag->setMimeData(data);
  drag->setPixmap(QPixmap::fromImage(*image_).scaled(size()));
  drag->exec(Qt::MoveAction);
}