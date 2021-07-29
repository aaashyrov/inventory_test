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

qsizetype ItemWidget::item_counter_ = 0;

ItemWidget::ItemWidget(QWidget *parent, const QSize &size) : QWidget(parent) {
  resize(size);
  item_num_ = item_counter_++;
}

void ItemWidget::setItem(const Item &item) {
  item_ = item;
  image_ = new QImage();
  if (not image_->load("../resources/" + item.impath())) {
    throw std::runtime_error("pixmap '../resources/" + item.impath().toStdString() + "' was not found");
  }
  setToolTip(to_string(item_.type()));
}

void ItemWidget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.drawPixmap(rect(), QPixmap::fromImage(*image_).scaled(size()));
}

void ItemWidget::mousePressEvent(QMouseEvent *event) {
  mouse_press_pos_ = event->pos();
}

void ItemWidget::mouseMoveEvent(QMouseEvent *event) {
  if (event->button() == Qt::RightButton
      or QApplication::startDragDistance() > (event->pos() - mouse_press_pos_).manhattanLength()) {
    return;
  }

  auto data = new QMimeData;
  data->setImageData(1);
  data->setColorData(item_num_);
  data->setText(to_string(item_.type()));

  auto drag = new QDrag(this);
  drag->setMimeData(data);
  drag->setPixmap(QPixmap::fromImage(*image_).scaled(size()));
  drag->exec(Qt::MoveAction);
}