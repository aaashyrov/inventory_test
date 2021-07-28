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
    throw std::runtime_error("image '../resources/" + item.impath().toStdString() + "' was not found");
  }
}

void ItemWidget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.drawPixmap(rect(), QPixmap::fromImage(*image_).scaled(size()));
  painter.save();
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

  auto *drag = new QDrag(this);
  auto *mime_data = new QMimeData;
  mime_data->setText(to_string(item_.type()));
  drag->setMimeData(mime_data);
  drag->setPixmap(QPixmap::fromImage(*image_).scaled(size()));
  auto result = drag->exec(Qt::MoveAction);
  qDebug() << "Drop action result: " << result;
}
