// failed compiles:
// failed runs:
// time taken:

#include "Node.h"
#include <cstdio>
#include <iostream>
#include <memory>

using utils::Node;

template <typename T>
class Stack {
public:
  Stack(T value) : m_top(std::make_shared<Node<T>>(value)), m_size(1) {}

  void push(T val) {
    auto newNode = std::make_shared<Node<T>>(val);
    m_top->setNext(newNode);
    m_top = newNode;
    m_size++;
  }

  void pop() {
    if (m_top) {
      m_top = m_top->getNext();
      m_size--;
    }
  }

  T peek() { return m_top->getData(); }

  T peek(int pos) {
    auto current = m_top;
    if (pos > m_size || pos == m_size) {
      return peek();
    }
    int i = 1;
    while (current->getNext() && i < pos) {
      current = current->getNext();
      i++;
    }
    return current->getData();
  }

  int getSize() { return m_size; }

private:
  int m_size;
  std::shared_ptr<Node<T>> m_top;
};

template <typename T>
class Queue {
public:
  Queue(T val) : m_end(std::make_shared<Node<T>>(val)), m_size(1) {}

  void enqueue(T val) {
    auto newNode = std::make_shared<Node<T>>(val);
    if (m_end)
      m_end->setNext(newNode);
    else
      m_front = newNode;
    m_size++;
  }

  T dequeue() {
    if (m_size == 0) {
      std::cout << "Queue empty, returning any value\n";
      return T{};
    }
    T value = m_front->getData();
    m_front = m_front->getNext();
    m_size--;
    if (m_size == 0) {
      m_end = nullptr;
      m_front = nullptr;
    }
    return value;
  }

private:
  std::shared_ptr<Node<T>> m_end;
  std::shared_ptr<Node<T>> m_front;
  int m_size;
};

int main(int argc, char const *argv[]) {
  int const MAX = 10;

  Stack<int> s(1);
  for (int i = 2; i <= MAX; i++) {
    s.push(i);
  }

  Queue<int> q(1);
  for (int i = 2; i <= MAX; i++) {
    q.enqueue(i);
  }

  return 0;
}
