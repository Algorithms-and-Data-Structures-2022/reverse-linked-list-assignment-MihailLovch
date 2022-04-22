#include "assignment/linked_list.hpp"

#include <utility>  // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    Node* node = front_;
    Node* prev = nullptr;
    Node* next = nullptr;
    for (int i = 0; i < size(); i++) {
      next = node->next;
      node->next = prev;
      prev = node;
      node = next;
    }
    node = front_;
    front_ = back_;
    back_ = node;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (size() > 0) {
      reverse_recursive_helper(front_, nullptr);
      Node* node = back_;
      back_ = front_;
      front_ = node;
    }
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (curr->next != nullptr) {
      reverse_recursive_helper(curr->next, curr);
    }
    curr->next = prev;
  }

}  // namespace assignment
