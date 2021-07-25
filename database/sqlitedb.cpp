//
// Created by alisher on 7/25/21.
//
#include <QtSql/QSqlError>
#include <iostream>
#include "sqlitedb.hpp"

SqliteDb::SqliteDb(Param param) : param_{std::move(param)} {
  db_ = QSqlDatabase::addDatabase("QSQLITE", "sqlite");
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
