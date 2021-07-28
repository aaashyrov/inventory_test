//
// Created by alisher on 7/24/21.
//

#ifndef INVENTORY_TEST_INVENTORY_INVENTORY_HPP_
#define INVENTORY_TEST_INVENTORY_INVENTORY_HPP_
#include <memory>
#include <QMap>
#include <QVector>
#include <QString>
#include "item.hpp"
#include "../database/database.hpp"

class Controller;

class Inventory {
 public:

  friend class Controller;

  Inventory() = default;
  ~Inventory() = default;

  qsizetype size() const noexcept;
  const QMap<qsizetype, QPair<Item::Type, size_t>> &items() const noexcept;
  bool initialize(const std::shared_ptr<Database> &database, const QMap<size_t, Item> &items) noexcept;
 private:
  qsizetype size_;
  QString message_;
  QMap<qsizetype, QPair<Item::Type, size_t>> items_;
};

#endif //INVENTORY_TEST_INVENTORY_INVENTORY_HPP_
