//
// Created by alisher on 7/27/21.
//

#ifndef INVENTORY_TEST__ITEM_WIDGET_HPP_
#define INVENTORY_TEST__ITEM_WIDGET_HPP_
#include <memory>
#include <QWidget>
#include <inventory/item.hpp>

class QLabel;

class ItemWidget : public QWidget {
 Q_OBJECT

 public:
  ItemWidget(QWidget *parent, const QSize &size);

  ~ItemWidget() override = default;
  ItemWidget(const ItemWidget &) = default;
  ItemWidget(ItemWidget &&) noexcept = default;
  ItemWidget &operator=(const ItemWidget &) = default;
  ItemWidget &operator=(ItemWidget &&) noexcept = default;

  void setItem(const Item &item);
  void enterEvent(QEvent *event) override;
  void paintEvent(QPaintEvent *event) override;

 protected:
  Item item_;
  QImage *image_;
};

#endif //INVENTORY_TEST__ITEM_WIDGET_HPP_
