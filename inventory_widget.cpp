//
// Created by alisher on 7/28/21.
//
#include <QDebug>
#include <QPainter>
#include <QMimeData>
#include <QDropEvent>
#include "inventory_widget.hpp"

InventoryWidget::InventoryWidget(QWidget *parent, const QSize &size)
    : QWidget(parent), item_type_{Item::Type::UNKNOWN}, item_count_{0} {
  resize(size);
  setAcceptDrops(true);
}

void InventoryWidget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  if (item_type_ == Item::Type::UNKNOWN) {
    painter.drawRect(rect());
    painter.save();
    return;
  }
}

void InventoryWidget::enterEvent(QEvent *event) {
  setToolTip(item_type_ == Item::Type::UNKNOWN ?
             "empty" : QString::number(item_count_) + " " + to_string(item_type_));
}

void InventoryWidget::dragEnterEvent(QDragEnterEvent *event) {
  auto formats = event->mimeData()->formats();
  if( formats.contains( "application/x-qt-image") && formats.contains( "text/plain" ) ) {
    event->acceptProposedAction();
  }
}

void InventoryWidget::dropEvent(QDropEvent *event) {
  qDebug() << "drop";
  event->acceptProposedAction();
}

