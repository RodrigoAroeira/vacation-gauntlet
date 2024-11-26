// failed compiles:
// failed runs:
// time taken: we forgor was pretty quick tho

#include "Node.h"
#include <cstddef>
#include <iostream>
#include <memory>
#include <sstream>

using utils::Node;

template <typename T>
class LinkedList {
public:
  using ParamType =
      typename std::conditional<std::is_fundamental<T>::value, T, T &>::type;

  class Iterator {
  public:
    Iterator(std::shared_ptr<Node<T>> node) : m_node(node) {}

    T &operator*() { return m_node->getData(); }
    const T &operator*() const { return m_node->getData(); }

    Iterator &operator++() {
      m_node = m_node->getNext();
      return *this;
    }
    Iterator operator++(int) {
      auto tmp = *this;
      m_node = m_node->getNext();
      return tmp;
    }

    bool operator==(const Iterator &other) const {
      return m_node == other.m_node;
    }

    bool operator!=(const Iterator &other) const { return !(*this == other); }

  private:
    std::shared_ptr<Node<T>> m_node;
  };

  LinkedList(const Node<T> &head)
      : m_head(std::make_shared<Node<T>>(head)), m_size(1) {}

  LinkedList(const ParamType headVal) : LinkedList(headVal) {}

  LinkedList() : m_head(nullptr), m_size(0) {}

  Iterator begin() { return Iterator(m_head); }
  Iterator end() { return Iterator(nullptr); }

  operator std::string() const {
    std::stringstream ss;

    // I thought it was funny doing it that way, so now it'll stay like that
    for (auto current = m_head; current; current = current->getNext())
      ss << current->getData() << "->";

    return ss.str();
  }

  friend std::ostream &operator<<(std::ostream &os, const LinkedList &ll) {
    os << static_cast<std::string>(ll);
    return os;
  }

  bool search(const ParamType value) const {

    for (auto current = m_head; current; current = current->getNext())
      if (current->getData() == value)
        return true;

    return false;
  }

  bool remove_val(const ParamType value) {
    std::shared_ptr<Node<T>> prev = nullptr;
    for (auto current = m_head; current; current = current->getNext()) {
      if (current->getData() == value) {
        if (!prev) {
          m_head = current->getNext();
        } else {
          prev->setNext(current->getNext());
        }
        m_size--;
        return true;
      }
      prev = current;
    }
    return false;
  }

  void insert_back(const ParamType value) {

    auto newNode = std::make_shared<Node<T>>(value);
    if (!m_head)
      m_head = newNode;
    else
      m_tail->setNext(newNode);

    m_tail = newNode;
    m_size++;
  }

  void insert_front(const ParamType value) {
    auto newNode = std::make_shared<Node<T>>(value);
    newNode->setNext(m_head);
    m_head = newNode;
    m_size++;
  }

  void replace(const size_t pos, const ParamType newValue) {
    auto current = m_head;
    for (int i = 0; current && i < pos; i++) {
      current = current->getNext();
    }

    if (current)
      current->setData(newValue);
  }

  void print_list() const { std::cout << *this << std::endl; }

  size_t getSize() const { return m_size; }

  void operator+(ParamType val) { insert_back(val); }

  friend void operator+(ParamType val, LinkedList<T> &ll) {
    ll.insert_front(val);
  }

  size_t m_size;

private:
  std::shared_ptr<Node<T>> m_head;
  std::shared_ptr<Node<T>> m_tail;
};

int main() {

  LinkedList<int> ll;
  for (int i = 0; i <= 5; i++) {
    ll.insert_back(i);
  }
  ll + 6;
  ll.print_list();
  ll.replace(2, 4);
  ll.print_list();
  ll.remove_val(2);
  ll.insert_front(30);

  29 + ll;
  std::cout << ll << std::endl;

  for (const int val : ll)
    std::cout << val << "->";
  std::cout << std::endl;

  for (auto it = ll.begin(); it != ll.end(); it++)
    std::cout << *it << "->";
  std::cout << std::endl;
}
