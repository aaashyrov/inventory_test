//
// Created by alisher on 7/25/21.
//

#include <QDebug>
#include "controller.hpp"

const QMap<size_t, Item> &Controller::items() const noexcept {
  return items_;
}

const Inventory &Controller::inventory() const noexcept {
  return inventory_;
}

bool Controller::initialize(const std::shared_ptr<Database> &database) noexcept {
  database_ = database;
  auto size = database->size_of("item");
  if (not size) return false;

  for (size_t i = 1; i <= size; ++i) {
    auto type = database->value("item", "type", i);
    if (not type) {
      qDebug() << "[Controller::initialize] " << "was not found type in item table  at " << i;
      return false;
    }
    auto impath = database->value("item", "impath", i);
    if (not impath) {
      qDebug() << "[Controller::initialize] " << "was not found impath in item table  at " << i;
      return false;
    }

    items_.insert(i, Item{to_type(type.value().toString()), impath.value().toString()});
  }

  if (not inventory_.initialize(database, items_)) {
    qDebug() << "[Controller::initialize] " << "inventory was not initialized";
    return false;
  }
  return true;
}

Controller::Controller() : items_{}, inventory_{} {}

void Controller::setItem(qsizetype i, Item::Type type, qsizetype count) noexcept {
  if (not inventory_.items_.contains(i)) return;
  QPair<Item::Type, qsizetype> pair;
  pair.first = type;
  pair.second = count;
  inventory_.items_[i] = pair;
}

Controller::~Controller() {
  for (auto it = inventory_.items_.begin(); it != inventory_.items_.end(); ++it) {
    database_->set("inventory", "num", it.key(), QString::number(it.value().second));
    database_->set("inventory", "type", it.key(), QString::number(to_uint(it.value().first)));
  }
}
