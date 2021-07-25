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

    items_.insert(i, Item(to_type(type.value().toString()), impath.value().toString()));
  }

  if (not inventory_.initialize(database, items_)) {
    qDebug() << "[Controller::initialize] " << "inventory was not initialized";
    return false;
  }
  return true;
}

Controller::Controller() : items_{}, inventory_{} {

}
