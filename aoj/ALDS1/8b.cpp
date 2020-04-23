#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct Node {
  int value;
  Node *parent, *left, *right;

  Node(int k, Node *p, Node *l, Node *r) {
    value = k;
    parent = p;
    left = l;
    right = r;
  }

  Node() {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
  }
};

Node *root = nullptr;

void insert(int k) {
  Node *y = nullptr;
  Node *x = root;
  Node *z = new Node();
  z->value = k;

  while (x != nullptr) {
    y = x;
    if (k < x->value) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  z->parent = y;
  if (y == nullptr) {
    root = z;
    return;
  }
  if (k < y->value)
    y->left = z;
  else
    y->right = z;
}

void find(int k) {
  Node *x = root;
  while (x != nullptr) {
    if (x->value == k) {
      std::cout << "yes" << '\n';
      return;
    }
    if (k < x->value)
      x = x->left;
    else
      x = x->right;
  }
  std::cout << "no" << '\n';
}

void inorder(Node *n) {
  if (n == nullptr) return;
  inorder(n->left);
  std::cout << ' ' << n->value;
  inorder(n->right);
}

void preorder(Node *n) {
  if (n == nullptr) return;
  std::cout << ' ' << n->value;
  preorder(n->left);
  preorder(n->right);
}

int main() {
  int n;
  std::cin >> n;
  std::string com;
  int key;

  rep(i, n) {
    std::cin >> com;
    if (com == "insert") {
      std::cin >> key;
      insert(key);
    } else if (com == "print") {
      inorder(root);
      std::cout << '\n';
      preorder(root);
      std::cout << '\n';
    } else {
      std::cin >> key;
      find(key);
    }
  }
  return 0;
}
