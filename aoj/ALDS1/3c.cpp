#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct node {
  int data;
  node *left;
  node *right;
};

node root{0, 0, 0};

void insert(int x) {
  node newNode{x, 0, 0};

  newNode.right = root.right;
  root.right->left = &newNode;
  root.right = &newNode;
  newNode.left = &root;

  // if (root.right == 0) {
  //   newNode.right = 0;
  //   root.right = &newNode;
  // } else {
  //   newNode.right = root.right;
  //   (root.right)->left = &newNode;
  //   root.right = &newNode;
  // }
}

void deleteNode(int x, node *n) {
  if (n->data == x) {
    (n->left)->right = n->right;
    (n->right)->left = n->left;
    n->left = 0;
    n->right = 0;
    return;
  }

  if (n->right == 0)
    return;

  deleteNode(x, n->right);
}

void deleteFirst() {
  root.right = (root.right)->right;
  (root.right)->left = &root;
}

void deleteLast(node *n) {
  if (n->right == 0) {
    (n->left)->right = 0;
    n->left = 0;
    return;
  }
  deleteLast(n->right);
}

void printNode(node *n) {
  std::cout << (n->data);

  if (n->right == &root) {
    // std::cout << "n->right == 0" << '\n';
    std::cout << '\n';
  } else {
    // std::cout << "n->right != 0" << '\n';
    std::cout << ' ';
    printNode(n->right);
  }
}

int main() {
  int n;
  std::cin >> n;
  std::string com;
  int key;

  root.left = &root;
  root.right = &root;

  rep(i, n) {
    std::cin >> com;
    if (com == "insert") {
      std::cin >> key;
      // std::cout << com << '\n';
      insert(key);
    } else if (com == "delete") {
      std::cin >> key;
      deleteNode(key, root.right);
    } else if (com == "deleteFirst") {
      deleteFirst();
    } else if (com == "deleteLast") {
      deleteLast(root.right);
    }
  }

  printNode(root.right);

  return 0;
}