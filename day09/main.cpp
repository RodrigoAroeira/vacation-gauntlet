// failed compiles:
// failed runs:
// time taken:

#include <cstdio>
#include <iostream>

template <typename T> class Stack {
private:
  T m_data;
  int m_size = 1;
  Stack *m_next = nullptr;
  Stack *m_top = this;

public:
  Stack(T value) : m_data(value) {}

  void push(T val) {
    Stack *NewNode = new Stack<T>(val);
    m_top->m_next = NewNode;
    m_top = NewNode;
    m_size++;
  }

  void pop() {
    Stack *current = this;
    Stack *prev = nullptr;
    while (current->m_next) {
      prev = current;
      current = current->m_next;
    }
    if (prev) {
      prev->m_next = nullptr;
    }
    m_top = prev;
    m_size--;
    delete current;
  }

  T peek() { return m_top->m_data; }

  T peek(int pos) {
    Stack *current = this;
    if (pos > m_size || pos == m_size) {
      return peek();
    }
    int i = 1;
    while (current->m_next && i < pos) {
      current = current->m_next;
      i++;
    }
    return current->m_data;
  }

  int getSize() { return m_size; }

  void print() {
    Stack *current = this;
    std::cout << "Stack: ";
    while (current) {
      std::cout << current->m_data << "->";
      current = current->m_next;
    }
    std::cout << std::endl;
  }

  void print(int until) {
    Stack *current = this;
    if (until >= m_size) {
      this->print();
      return;
    }
    printf("Stack until position %d: ", until);
    int i = 0;
    while (current && i < until) {
      std::cout << current->m_data << "->";
      current = current->m_next;
      i++;
    }
    std::cout << std::endl;
  }

  void print(int from, int to) {
    Stack *current = this;
    int i = 1;
    if (from <= 1 && to >= m_size) {
      this->print();
      return;
    }
    printf("Stack from positions %d to %d: ", from, to);
    if (from > 1 && from <= to) {
      std::cout << "....->";
    }

    while (current && i <= to) {
      if (i >= from) {
        std::cout << current->m_data << "->";
      }
      current = current->m_next;
      i++;
    }
    if (to < m_size) {
      std::cout << "....";
    }
    std::cout << std::endl;
  }
};

template <typename T> class Queue {
private:
  T data;
  Queue *next = nullptr;
  Queue *end = this;
  int size = 1;

public:
  Queue(T val) : data(val) {}

  void enqueue(T val) {
    Queue *NewNode = new Queue<T>(val);
    end->next = NewNode;
    end = NewNode;
    size++;
  }

  T dequeue() {
    if (next) {
      data = next->data;
      Queue *del = next;
      next = next->next;
      delete del;
    }
    size--;
  }
  T peek(int pos) {
    Queue *curr = this;

    int i = 0;
    while (curr->next && i < pos) {
      curr = curr->next;
      i++;
    }
    return curr->data;
  }

  T peek() { return data; }

  void print() {
    Queue *current = this;
    std::cout << "Queue: <-";
    while (current) {
      std::cout << current->data;
      if (current->next) {
        std::cout << "<-";
      }
      current = current->next;
    }
    std::cout << std::endl;
  }

  void print(int until) {
    Queue *current = this;
    if (until >= size) {
      this->print();
      return;
    }
    printf("Queue until position %d: <-", until);
    int i = 0;
    while (current && i < until) {
      std::cout << current->data;
      if (current->next) {
        std::cout << "<-";
      }
      current = current->next;
      i++;
    }
    std::cout << std::endl;
  }

  void print(int from, int to) {
    Queue *current = this;
    int i = 1;
    if (from <= 1 && to >= size) {
      this->print();
      return;
    }
    printf("Queue from positions %d to %d: <-", from, to);
    if (from > 1 && from <= to) {
      std::cout << "....<-";
    }

    while (current && i <= to) {
      if (i >= from) {
        std::cout << current->data;
        if (current->next) {
          std::cout << "<-";
        }
      }
      current = current->next;
      i++;
    }
    if (to < size) {
      std::cout << "....";
    }
    std::cout << std::endl;
  }
};

int main(int argc, char const *argv[]) {
  int const MAX = 10;

  Stack<int> s(1);
  for (int i = 2; i <= MAX; i++) {
    s.push(i);
  }

  int start = argc > 1 ? std::stoi(argv[1]) : 3;
  int end = argc > 2 ? std::stoi(argv[2]) : 27;

  s.print(start, end);

  Queue<int> q(1);
  for (int i = 2; i <= MAX; i++) {
    q.enqueue(i);
  }

  q.print(start, end);

  return 0;
}
