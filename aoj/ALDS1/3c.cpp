// 23:40 - 24:01

#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct Node {
  int value;
  Node *prev;
  Node *next;
};

Node *root;

void insertNode(int key) {
  Node *node = new Node{key, root, root->next};
  root->next->prev = node;
  root->next = node;
}

Node *searchNode(int key, Node *node) {
  Node *t = node->next;
  if (t == root)
    return nullptr;

  if (t->value == key)
    return t;

  return searchNode(key, t);
}

void deleteNode(int key) {
  Node *node = searchNode(key, root);
  if (node == nullptr)
    return;

  node->prev->next = node->next;
  node->next->prev = node->prev;

  delete node;
}

void deleteFirst() {
  Node *t = root->next;
  t->next->prev = root;
  root->next = t->next;

  delete t;
}

void deleteLast() {
  Node *t = root->prev;
  t->prev->next = root;
  t->next->prev = t->prev;

  delete t;
}

void printList(Node *node) {
  Node *t = node->next;

  if (t == root) {
    return;
  }

  std::cout << t->value;
  if (t->next == root) {
    std::cout << '\n';
  } else {
    std::cout << ' ';
    printList(t);
  }
}

int main() {
  int n;
  std::cin >> n;

  root = new Node();
  root->value = 0;
  root->prev = root;
  root->next = root;

  std::string com;
  int key;

  rep(i, n) {
    std::cin >> com;
    if (com == "insert") {
      std::cin >> key;
      insertNode(key);
    } else if (com == "delete") {
      std::cin >> key;
      deleteNode(key);
    } else if (com == "deleteFirst") {
      deleteFirst();
    } else if (com == "deleteLast") {
      deleteLast();
    }
  }

  printList(root);

  return 0;
}