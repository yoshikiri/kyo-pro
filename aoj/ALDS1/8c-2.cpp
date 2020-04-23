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

Node *find(int k) {
  Node *x = root;
  while (x != nullptr) {
    if (x->value == k) { return x; }
    if (k < x->value)
      x = x->left;
    else
      x = x->right;
  }
  return nullptr;
}

Node *getMinimum(Node *x) {
  Node *t = x;
  while (t->left != nullptr) { t = t->left; }
  return t;
}

Node *getSuccessor(Node *x) {
  if (x->right != nullptr) return getMinimum(x->right);

  Node *z = x;
  Node *y = x->parent;
  while (y != nullptr && z == y->right) {
    z = y;
    y = y->parent;
  }
  return y;
}

void deleteNode(Node *x) {
  // 0 child
  if (x->left == nullptr && x->right == nullptr) {
    if (x == x->parent->left)
      x->parent->left = nullptr;
    else
      x->parent->right = nullptr;
    delete x;
    return;
  }

  // 2 children
  if (x->left != nullptr && x->right != nullptr) {
    Node *y = getSuccessor(x);
    x->value = y->value;
    deleteNode(y);
    return;
  }

  // 1 child
  Node *y;
  if (x->left != nullptr)
    y = x->left;
  else
    y = x->right;

  y->parent = x->parent;

  if (x == x->parent->left)
    x->parent->left = y;
  else
    x->parent->right = y;
  delete x;
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
    } else if (com == "find") {
      std::cin >> key;
      Node *x = find(key);
      if (x != nullptr)
        std::cout << "yes" << '\n';
      else
        std::cout << "no" << '\n';
    } else {
      std::cin >> key;
      Node *x = find(key);
      deleteNode(x);
    }
  }
  return 0;
}
