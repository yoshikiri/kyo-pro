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

void insert(Node *n, int k) {
  Node *t = new Node(k, n, nullptr, nullptr);

  if (n == nullptr) {
    t->parent = nullptr;
    root = t;
    return;
  }
  if (k < n->value) {
    if (n->left == nullptr) {
      n->left = t;
    } else {
      delete t;
      insert(n->left, k);
    }
  } else {
    if (n->right == nullptr) {
      n->right = t;
    } else {
      delete t;
      insert(n->right, k);
    }
  }
}

void insert2(int k) {
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
      // insert(root, key);
      insert2(key);
    } else {
      inorder(root);
      std::cout << '\n';
      preorder(root);
      std::cout << '\n';
    }
  }
  return 0;
}
