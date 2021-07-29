//
// Created by alisher on 7/24/21.
//

#ifndef INVENTORY_TEST_DATABASE_DATABASE_HPP_
#define INVENTORY_TEST_DATABASE_DATABASE_HPP_
#include <QMap>
#include <QString>
#include <QVariant>

class Database {
 public:
  virtual bool isOpen() noexcept = 0;
  virtual QString message() noexcept = 0;

  virtual qsizetype size_of(const QString &table) noexcept = 0;
  virtual std::optional<QVariant> value(const QString &table, const QString &name, qsizetype i) noexcept = 0;
  virtual void set(const QString &table, const QString &name, qsizetype i, const QString &value) noexcept = 0;

  Database() = default;
  virtual ~Database() = default;
  Database(const Database &) = default;
  Database(Database &&) noexcept = default;
  Database &operator=(const Database &) = default;
  Database &operator=(Database &&) noexcept = default;
};

#endif //INVENTORY_TEST_DATABASE_DATABASE_HPP_
