//
// Created by alisher on 7/24/21.
//

#include "inventory.hpp"

Inventory::Inventory(qsizetype size) : size_{size} {
  items_.reserve(size);
}

qsizetype Inventory::size() const noexcept {
  return size_;
}

const QVector<QPair<Item::Type, qsizetype>> &Inventory::items() const noexcept {
  return items_;
}
