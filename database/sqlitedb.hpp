//
// Created by alisher on 7/25/21.
//

#ifndef INVENTORY_TEST_DATABASE_SQLITEDB_HPP_
#define INVENTORY_TEST_DATABASE_SQLITEDB_HPP_

#include <memory>
#include <QtSql/QSqlDatabase>
#include "database.hpp"

struct Param {
  QString host;
  QString db;
  QString user;
  QString pass;
};

class SqliteDb : public Database {
 public:
  explicit SqliteDb(Param param);
  ~SqliteDb() override;
  bool isOpen() noexcept override;
  QString message() noexcept override;

 private:
  Param param_;
  QSqlDatabase db_;
  std::atomic_bool is_open_{};
};

#endif //INVENTORY_TEST_DATABASE_SQLITEDB_HPP_
