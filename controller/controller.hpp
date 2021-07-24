//
// Created by alisher on 7/25/21.
//

#ifndef INVENTORY_TEST_CONTROLLER_CONTROLLER_HPP_
#define INVENTORY_TEST_CONTROLLER_CONTROLLER_HPP_
#include <memory>
#include <QVector>
#include "../item/item.hpp"
#include "../database/database.hpp"
#include "../inventory/inventory.hpp"

class Controller {
 public:
  explicit Controller(std::shared_ptr<Database> db);
  ~Controller() = default;
  [[nodiscard]] const Inventory &inventory() const noexcept;
  [[nodiscard]] const QVector<Item> &items() const noexcept;
 private:
  QVector<Item> items_;
  Inventory inventory_;
};

#endif //INVENTORY_TEST_CONTROLLER_CONTROLLER_HPP_
