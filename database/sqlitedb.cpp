//
// Created by alisher on 7/25/21.
//
#include <QDebug>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include "sqlitedb.hpp"

SqliteDb::SqliteDb(Param param) : param_{std::move(param)} {
  db_ = QSqlDatabase::addDatabase("QSQLITE", "sqlite1");
  db_.setHostName(param_.host);
  db_.setDatabaseName(param_.db);
  is_open_ = db_.open(param_.user, param_.pass);
}

SqliteDb::~SqliteDb() {
  db_.close();
  QSqlDatabase::removeDatabase("sqlite");
}

bool SqliteDb::isOpen() noexcept {
  return is_open_;
}

QString SqliteDb::message() noexcept {
  return db_.lastError().text();
}

qsizetype SqliteDb::size_of(const QString &table) noexcept {
  QSqlQuery query(db_);
  if (not query.exec("select * from " + table + ";")) {
    return 0;
  }
  qsizetype size = 1;
  query.first();
  while (query.next()) ++size;
  return size;
}

std::optional<QVariant> SqliteDb::value(const QString &table, const QString &name, qsizetype i) noexcept {
  QSqlQuery query(db_);
  if (not query.exec("select * from " + table + " where id = " + QString::number(i))) {
    qDebug() << "[SqliteDb::value] " << query.lastError().text();
    return std::nullopt;
  }
  query.first();
  return query.value(name);
}