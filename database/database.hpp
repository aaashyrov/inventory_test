//
// Created by alisher on 7/24/21.
//

#ifndef INVENTORY_TEST_DATABASE_DATABASE_HPP_
#define INVENTORY_TEST_DATABASE_DATABASE_HPP_
#include <QString>

class Database {
 public:
  virtual bool connect() noexcept = 0;
  virtual bool disconnect() noexcept = 0;
};

#endif //INVENTORY_TEST_DATABASE_DATABASE_HPP_
