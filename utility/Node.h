#pragma once

#include <cstddef>
#include <memory>
#include <sstream>
#include <string>
#include <type_traits>

namespace utils {
template <typename T>
class Node {
public:
  using ParamType =
      typename std::conditional<std::is_fundamental<T>::value, T, T &>::type;

  Node(ParamType val) : m_data(val), m_next(nullptr) {}

  operator std::string() const { return std::to_string(m_data); }

  T &getData() { return m_data; }
  const T &getData() const { return m_data; }

  void setData(const ParamType val) { m_data = val; }

  std::shared_ptr<Node<T>> getNext() const { return m_next; }

  void setNext(std::shared_ptr<Node<T>> next) { m_next = std::move(next); }

  void setNext(T nextVal) { m_next = std::make_shared<Node<T>>(nextVal); }

private:
  T m_data;
  std::shared_ptr<Node> m_next;
};
} // namespace utils
