//
// Created by alisher on 7/25/21.
//

#ifndef INVENTORY_TEST_CONTROLLER_CONTROLLER_HPP_
#define INVENTORY_TEST_CONTROLLER_CONTROLLER_HPP_
#include <memory>
#include <QVector>
#include "../inventory/item.hpp"
#include "../database/database.hpp"
#include "../inventory/inventory.hpp"

class Controller {
 public:
  Controller();
  ~Controller();

  [[nodiscard]] const Inventory &inventory() const noexcept;
  [[nodiscard]] const QMap<size_t, Item> &items() const noexcept;
  void setItem(qsizetype i, Item::Type type, qsizetype count) noexcept;
  bool initialize(const std::shared_ptr<Database> &database) noexcept;

 private:
  Inventory inventory_;
  QMap<size_t, Item> items_;
  std::shared_ptr<Database> database_;
};

#endif //INVENTORY_TEST_CONTROLLER_CONTROLLER_HPP_
