#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct Node {
  int id, parent, left, right;
};

Node t[25];

void preorder(Node node) {
  std::cout << ' ' << node.id;
  if (node.left != -1) preorder(t[node.left]);
  if (node.right != -1) preorder(t[node.right]);
}

void inorder(Node node) {
  if (node.left != -1) inorder(t[node.left]);
  std::cout << ' ' << node.id;
  if (node.right != -1) inorder(t[node.right]);
}

void postorder(Node node) {
  if (node.left != -1) postorder(t[node.left]);
  if (node.right != -1) postorder(t[node.right]);
  std::cout << ' ' << node.id;
}

int main() {
  int n;
  std::cin >> n;

  rep(i, n) t[i] = Node{-1, -1, -1, -1};

  rep(i, n) {
    int id, left, right;
    std::cin >> id >> left >> right;
    t[id].id = id;
    t[id].left = left;
    t[id].right = right;
    if (left != -1) t[left].parent = id;
    if (right != -1) t[right].parent = id;
  }

  int root = 0;
  rep(i, n) {
    if (t[i].parent == -1) {
      root = t[i].id;
      break;
    }
  }

  std::cout << "Preorder" << '\n';
  preorder(t[root]);
  std::cout << '\n';

  std::cout << "Inorder" << '\n';
  inorder(t[root]);
  std::cout << '\n';

  std::cout << "Postorder" << '\n';
  postorder(t[root]);
  std::cout << '\n';

  return 0;
}
