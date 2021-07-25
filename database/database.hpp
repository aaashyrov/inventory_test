//
// Created by alisher on 7/24/21.
//

#ifndef INVENTORY_TEST_DATABASE_DATABASE_HPP_
#define INVENTORY_TEST_DATABASE_DATABASE_HPP_
#include <QString>

class Database {
 public:
  virtual bool isOpen() noexcept = 0;
  virtual QString message() noexcept = 0;
  virtual ~Database() = default;
};

#endif //INVENTORY_TEST_DATABASE_DATABASE_HPP_
