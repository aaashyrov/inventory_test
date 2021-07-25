//
// Created by alisher on 7/24/21.
//
#include <QDebug>
#include "inventory.hpp"

qsizetype Inventory::size() const noexcept {
  return size_;
}

const QMap<qsizetype, QPair<Item::Type, size_t>> &Inventory::items() const noexcept {
  return items_;
}
bool Inventory::initialize(const std::shared_ptr<Database> &database, const QMap<size_t, Item> &items) noexcept {
  size_ = database->size_of("inventory");
  if (not size_) {
    qDebug() << "[Inventory::initialize]: " << database->message();
    return false;
  }

  auto type = [&](size_t i) -> Item::Type {
    auto type_id = database->value("inventory", "type", i);
    if (not type_id) {
      return Item::Type::UNKNOWN;
    }

    if (not items.contains(type_id.value().toInt())) {
      return Item::Type::UNKNOWN;
    }

    return items[type_id.value().toInt()].type();
  };

  auto num = [&](size_t i) -> size_t {
    auto value = database->value("inventory", "num", i);
    if (not value) return 0;
    return value.value().toInt();
  };

  for (size_t i = 1; i <= size_; ++i) {
    items_.insert(i, QPair(type(i), num(i)));
  }
  return true;
}