//
// Created by alisher on 7/27/21.
//
#include <QDebug>
#include <QLabel>
#include <QPainter>
#include <QVBoxLayout>

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
