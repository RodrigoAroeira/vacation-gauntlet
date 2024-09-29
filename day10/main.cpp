// failed compiles:
// failed runs:
// time taken:

#include <iostream>

template <typename T> class TreeNode {
private:
  T m_data;
  TreeNode *m_left = nullptr;
  TreeNode *m_right = nullptr;
  TreeNode *m_prev = nullptr;
  int m_depth = 0;

public:
  TreeNode() : TreeNode(T(), nullptr, nullptr){};

  TreeNode(T data) : TreeNode(data, nullptr, nullptr) {}

  TreeNode(T data, TreeNode<T> *left, TreeNode<T> *right)
      : m_data(data), m_left(left), m_right(right) {

    left->m_prev = this;
    right->m_prev = this;

    if (left)
      left->m_depth = m_depth + 1;
    if (right)
      right->m_depth = m_depth + 1;
  }

  void insert(T value) {
    if (value > m_data) {
      if (m_right == nullptr) {
        m_right = new TreeNode<T>(value);
        m_right->m_depth = m_depth + 1;
        m_right->m_prev = this;
      } else {
        m_right->insert(value);
      }

    } else {
      if (m_left == nullptr) {
        m_left = new TreeNode<T>(value);
        m_left->m_depth = m_depth + 1;
        m_left->m_prev = this;
      } else {
        m_left->insert(value);
      }
    }
  }

  void remove(T value) {
    if (value == m_data) {
      if (m_prev) {

      } else {
        std::cout << "Depth minimum reached. Use the change() method to alter "
                     "value." /*??*/
                  << std::endl;
      }
    } else if (value > m_data) {

      if (m_right != nullptr) {
        m_right->remove(value);
      }

    } else {

      if (m_left != nullptr) {
        m_left->remove(value);
      }
    }
  }

  bool contains(T value) {
    if (value == m_data)
      return true;
    else if (value > m_data) {
      if (m_right == nullptr)
        return false;
      else
        return m_right->contains(value);
    } else {
      if (m_left == nullptr)
        return false;
      else
        return m_left->contains(value);
    }
  }

  void print() {
    std::cout << "KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK nao"
              << std::endl;
  }
};

int main() {

  TreeNode<int> root(0);
  root.remove(0);
  return 0;
}
