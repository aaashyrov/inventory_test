//
// Created by alisher on 7/27/21.
//

#ifndef INVENTORY_TEST__ITEM_WIDGET_HPP_
#define INVENTORY_TEST__ITEM_WIDGET_HPP_
#include <QWidget>
#include <inventory/item.hpp>

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
  void paintEvent(QPaintEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;

 private:
  Item item_;
  static qsizetype item_counter_;

 protected:
  QImage *image_;
  qsizetype item_num_;
  QPoint mouse_press_pos_;
};

#endif //INVENTORY_TEST__ITEM_WIDGET_HPP_
