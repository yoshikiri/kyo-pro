#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct Node {
  int parent;
  int left;
  int right;
};

Node t[100000];
int d[1000000];

void setDepth(int i, int depth) {
  d[i] = depth;
  if (t[i].left != -1)
    setDepth(t[i].left, depth + 1);
  if (t[i].right != -1)
    setDepth(t[i].right, depth);
}

void printChildren(int i) {
  std::cout << "[";

  int c = t[i].left;
  while (c != -1) {
    std::cout << c;
    c = t[c].right;
    if (c == -1) {
      break;
    } else {
      std::cout << ", ";
    }
  }
  std::cout << "]\n";
}

int main() {
  int n;
  std::cin >> n;

  rep(i, n) t[i] = Node{-1, -1, -1};

  int id, k, c, l;
  rep(i, n) {
    std::cin >> id >> k;
    rep(j, k) {
      std::cin >> c;
      if (j == 0)
        t[id].left = c;
      else
        t[l].right = c;
      l = c;
      t[c].parent = id;
    }
  }

  int root;
  rep(i, n) {
    if (t[i].parent == -1)
      root = i;
  }

  setDepth(root, 0);

  rep(i, n) {
    std::string type;
    if (t[i].parent == -1)
      type = "root";
    else if (t[i].left == -1)
      type = "leaf";
    else
      type = "internal node";

    printf("node %d: parent = %d, depth = %d, %s, ", i, t[i].parent, d[i],
           type.c_str());
    // std::cout << '\n';
    printChildren(i);
  }

  return 0;
}
