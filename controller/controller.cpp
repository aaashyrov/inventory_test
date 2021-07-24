//
// Created by alisher on 7/25/21.
//

#include "controller.hpp"
Controller::Controller(std::shared_ptr<Database> db) : inventory_{9} {

}

const QVector<Item> &Controller::items() const noexcept {
  return items_;
}

const Inventory &Controller::inventory() const noexcept {
  return inventory_;
}
