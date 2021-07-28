//
// Created by alisher on 7/28/21.
//
#include <QDebug>
#include <QPainter>
#include <QMimeData>
#include <QDropEvent>
#include <QMessageBox>
#include <utility>
#include "inventory_widget.hpp"

InventoryWidget::InventoryWidget(QWidget *parent, const QSize &size,
                                 qsizetype num, std::shared_ptr<Controller> controller)
    : QWidget(parent), inventory_num_{num}, controller_{std::move(controller)} {
  resize(size);
  setAcceptDrops(true);
}

void setText(QImage &image, const QString &text) {
  QPainter painter(&image);
  painter.setPen(QPen(Qt::black));
  painter.setFont(QFont("Times", 14, QFont::Bold));
  painter.drawText(image.size().width() - 20, image.size().height() - 10, text);
}

void InventoryWidget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  auto item_type = controller_->inventory().items()[inventory_num_].first;
  auto item_count = QString::number(controller_->inventory().items()[inventory_num_].second);
  setToolTip(item_type == Item::Type::UNKNOWN ? "empty" : item_count + " " + to_string(item_type));
  if (item_type == Item::Type::UNKNOWN) {
    painter.drawRect(rect());
    return;
  }

  auto impath = [&](Item::Type type) -> QString {
    for (const auto &item: controller_->items()) {
      if (item.type() == type) return "../resources/" + item.impath();
    }
    return QString{};
  };

  QImage image;
  image.load(impath(item_type));
  setText(image, item_count);
  painter.drawPixmap(rect(), QPixmap::fromImage(image).scaled(size()));
}

void InventoryWidget::dragEnterEvent(QDragEnterEvent *event) {
  auto formats = event->mimeData()->formats();
  if (formats.contains("application/x-qt-image") && formats.contains("text/plain")) {
    event->acceptProposedAction();
  }
}

void InventoryWidget::dropEvent(QDropEvent *event) {
  event->acceptProposedAction();
  appendItemByType(to_type(event->mimeData()->text()), event->mimeData()->imageData().toInt());
}

void InventoryWidget::appendItemByType(const Item::Type &item_type, qsizetype count) noexcept {
  auto current_item_type = controller_->inventory().items()[inventory_num_].first;
  if (item_type != current_item_type and current_item_type != Item::Type::UNKNOWN) {
    return;
  }

  auto item_count = controller_->inventory().items()[inventory_num_].second + count;
  controller_->setItem(inventory_num_, item_type, item_count);
  repaint();
}

void InventoryWidget::mousePressEvent(QMouseEvent *event) {
  if (event->buttons() & Qt::RightButton) {
    auto item_count = controller_->inventory().items()[inventory_num_].second;
    item_count = item_count == 0 ? item_count : item_count - 1;

    auto item_type = controller_->inventory().items()[inventory_num_].first;
    item_type = item_count == 0 ? Item::Type::UNKNOWN : item_type;
    controller_->setItem(inventory_num_, item_type, item_count);
    repaint();
  }
  QWidget::mousePressEvent(event);
}
