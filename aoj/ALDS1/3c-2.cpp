#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct Node {
  long long data;
  Node *prev;
  Node *next;
};

Node *nil;

void printList(Node *node) {
  Node *next = node->next;

  std::cout << next->data;
  if (next->next == nil) {
    std::cout << '\n';
    return;
  } else {
    std::cout << ' ';
    printList(next);
  }
}

void insertNode(long long key) {
  Node *x = new Node{key, nil, nil};
  x->next = nil->next;
  x->prev = nil;
  nil->next->prev = x;
  nil->next = x;
}

Node *searchNode(long long key, Node *node) {
  Node *next = node->next;

  if (next == nil) {
    return nil;
  } else {
    if (next->data == key)
      return next;
    else
      return searchNode(key, next);
  }
}

void deleteNode(long long key) {
  Node *x = searchNode(key, nil);
  if (x == nil)
    return;
  x->prev->next = x->next;
  x->next->prev = x->prev;
  delete x;
}

void deleteFirst() {
  nil->next->next->prev = nil;
  nil->next = nil->next->next;
}

void deleteLast() {
  Node *last = nil->prev;
  last->prev->next = nil;
  nil->prev = last->prev;
}

int main() {
  int n;
  std::cin >> n;
  std::string com;
  long long key;

  nil = new Node();
  nil->prev = nil;
  nil->next = nil;

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

  printList(nil);

  return 0;
}