//
// Created by alisher on 7/28/21.
//

#ifndef INVENTORY_TEST__INVENTORY_WIDGET_HPP_
#define INVENTORY_TEST__INVENTORY_WIDGET_HPP_
#include <memory>

#include <QWidget>

#include <inventory/item.hpp>
#include <controller/controller.hpp>

class InventoryWidget : public QWidget {
 Q_OBJECT

 public:
  InventoryWidget(QWidget *parent, const QSize &size, qsizetype num, std::shared_ptr<Controller> controller);

  ~InventoryWidget() override = default;
  InventoryWidget(const InventoryWidget &) = default;
  InventoryWidget(InventoryWidget &&) noexcept = default;
  InventoryWidget &operator=(const InventoryWidget &) = default;
  InventoryWidget &operator=(InventoryWidget &&) noexcept = default;

  void dropEvent(QDropEvent *event) override;
  void paintEvent(QPaintEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void dragEnterEvent(QDragEnterEvent *event) override;
 protected:

  QPoint mouse_press_pos_;
  qsizetype inventory_num_;
  std::shared_ptr<Controller> controller_;
};
#endif //INVENTORY_TEST__INVENTORY_WIDGET_HPP_
