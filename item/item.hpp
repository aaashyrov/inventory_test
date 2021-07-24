//
// Created by alisher on 7/24/21.
//

#ifndef INVENTORY_TEST_ITEM_ITEM_HPP_
#define INVENTORY_TEST_ITEM_ITEM_HPP_
#include<string>

class Item {
 public:

  enum class Type {
    UNKNOWN, APPLE, BANANA
  };

  Item(Type type, std::string image_path);

  ~Item() = default;
  Item(const Item &) = default;
  Item(Item &&) noexcept = default;
  Item &operator=(const Item &) = default;
  Item &operator=(Item &&) noexcept = default;

 private:
  Type type_;
  std::string image_path_;
};

std::string to_string(Item::Type type) {
  switch (type) {
    case Item::Type::APPLE: return "apple";
    case Item::Type::BANANA: return "banana";
    case Item::Type::UNKNOWN: return "unknown";
  }
}

Item::Type to_type(const std::string &type) {
  if (type == "apple") return Item::Type::APPLE;
  if (type == "banana") return Item::Type::BANANA;
  return Item::Type::UNKNOWN;
}

#endif //INVENTORY_TEST_ITEM_ITEM_HPP_
