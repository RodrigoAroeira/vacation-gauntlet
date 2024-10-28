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
  LinkedList(const Node<T> &head)
      : m_head(std::make_shared<Node<T>>(head)), m_size(1) {}

  LinkedList(const T headVal) : LinkedList(Node<T>(headVal)) {}

  LinkedList() : m_head(nullptr), m_size(0) {}

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

  bool search(const T value) const {

    for (auto current = m_head; current; current = current->getNext())
      if (current->getData() == value)
        return true;

    return false;
  }

  bool remove_val(const T value) {
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

  void insert_back(const T value) {
    auto newNode = std::make_shared<Node<T>>(value);
    if (!m_head) {
      m_head = newNode;
      m_size++;
      return;
    }

    auto current = m_head;
    while (current->getNext())
      current = current->getNext();

    current->setNext(newNode);
    m_size++;
  }

  void insert_front(const T value) {
    auto newNode = std::make_shared<Node<T>>(value);
    newNode->setNext(m_head);
    m_head = newNode;
    m_size++;
  }

  void replace(const size_t pos, const T value) {
    auto current = m_head;
    for (int i = 0; current && i < pos; i++) {
      current = current->getNext();
    }

    if (current)
      current->setData(value);
  }

  void print_list() const { std::cout << *this << std::endl; }

  int getSize() const { return m_size; }

private:
  int m_size;
  std::shared_ptr<Node<T>> m_head;
};

int main() {

  LinkedList<int> ll(43);
  for (int i = 1; i <= 4; i++) {
    ll.insert_back(i);
  }
  ll.print_list();
  ll.replace(2, 4);
  ll.print_list();
  ll.remove_val(2);
  ll.insert_front(30);
  ll.print_list();
}
