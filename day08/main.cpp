// failed compiles:
// failed runs:
// time taken: we forgor was pretty quick tho

#include <iostream>

class Node {

private:
  int m_data;
  int m_size = 1;
  Node *m_prev = nullptr;
  Node *m_next = nullptr;

public:
  Node(int val) : m_data(val) {}

  operator std::string() const {
    std::string str;

    // I thought it was funny doing it that way, so now it'll stay like that
    for (const Node *current = this; current; current = current->m_next)
      str += std::to_string(current->m_data) + "->";

    return str;
  }

  bool search(const int value) const {

    for (const Node *current = this; current; current = current->m_next)
      if (current->m_data == value)
        return true;

    return false;
  }

  int remove_val(const int value) {

    for (const Node *current = this; current; current = current->m_next) {
      if (current->m_data == value) {
        current->m_prev->m_next = current->m_next;
        m_size--;
        delete current;
        return 0;
      }
    }
    return -1;
  }

  void insert_back(const int value) {
    Node *current = this;
    while (current->m_next)
      current = current->m_next;

    current->m_next = new Node(value);
    current->m_next->m_prev = current;
  }

  void insert_front(const int value) {
    Node *newNode = new Node(m_data);
    newNode->m_next = this->m_next;

    if (this->m_next) {
      this->m_next->m_prev = newNode;
    }

    newNode->m_prev = this;
    this->m_next = newNode;
    this->m_data = value;
  }

  void replace(const int pos, const int value) {
    Node *current = this;
    for (int i = 1; current && i < pos; i++) {
      current = current->m_next;
    }
    current->m_data = value;
  }

  void print_list() const {
    std::string str = *this;
    std::cout << str << std::endl;
  }

  int getData() const { return m_data; }

  void setData(int value) { m_data = value; }

  int getSize() const { return m_size; }
};

int main() {
  Node head(0);

  for (int i = 1; i <= 10; i++) {
    head.insert_back(i);
  }

  std::cout << "Original list:" << std::endl;
  head.print_list();

  head.remove_val(3);
  std::cout << "List after remove_val(3):" << std::endl;
  head.print_list();

  std::cout << "Insert_front(94)" << std::endl;
  head.insert_front(94);
  head.print_list();

  for (int i = 23; i < 28; i++) {
    head.insert_front(i);
    head.print_list();
  }

  std::cout << "Replace 2, 15" << std::endl;
  head.replace(2, 15);
  head.print_list();
}
