//
// Created by alisher on 7/28/21.
//

#ifndef INVENTORY_TEST__INVENTORY_WIDGET_HPP_
#define INVENTORY_TEST__INVENTORY_WIDGET_HPP_
#include <QWidget>
#include <inventory/item.hpp>

class InventoryWidget : public QWidget {
 Q_OBJECT

 public:
  InventoryWidget(QWidget *parent, const QSize &size);

  ~InventoryWidget() override = default;
  InventoryWidget(const InventoryWidget &) = default;
  InventoryWidget(InventoryWidget &&) noexcept = default;
  InventoryWidget &operator=(const InventoryWidget &) = default;
  InventoryWidget &operator=(InventoryWidget &&) noexcept = default;

  void enterEvent(QEvent *event) override;
  void dropEvent(QDropEvent *event) override;
  void paintEvent(QPaintEvent *event) override;
  void dragEnterEvent(QDragEnterEvent *event) override;
 protected:
  Item::Type item_type_;
  qsizetype item_count_;
};
#endif //INVENTORY_TEST__INVENTORY_WIDGET_HPP_
