//
// Created by alisher on 7/24/21.
//

#ifndef INVENTORY_TEST_INVENTORY_INVENTORY_HPP_
#define INVENTORY_TEST_INVENTORY_INVENTORY_HPP_
#include <QMap>
#include <QVector>
#include <QString>
#include "../item/item.hpp"

class Inventory {
 public:
  explicit Inventory(qsizetype size);

  ~Inventory() = default;
  qsizetype size() const noexcept;
  const QVector<QPair<Item::Type, qsizetype>> &items() const noexcept;
 private:
  qsizetype size_;
  QVector<QPair<Item::Type, qsizetype>> items_;
};

#endif //INVENTORY_TEST_INVENTORY_INVENTORY_HPP_
