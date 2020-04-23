#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct Node {
  int p, l, r;
};

Node t[25];
int sib[25];
int d[25];
int h[25];

void print(int n) {
  rep(i, n) {
    int deg = (t[i].l != -1) + (t[i].r != -1);

    std::string type;
    if (t[i].p == -1)
      type = "root";
    else if (deg == 0)
      type = "leaf";
    else
      type = "internal node";

    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, "
           "height = %d, %s\n",
           i, t[i].p, sib[i], deg, d[i], h[i], type.c_str());
  }
}

void setDepth(int i, int depth) {
  d[i] = depth;
  if (t[i].l != -1) setDepth(t[i].l, depth + 1);
  if (t[i].r != -1) setDepth(t[i].r, depth + 1);
}

void setHeight(int i) {
  if (t[i].l == -1 && t[i].r == -1) {
    h[i] = 0;
    return;
  }

  int h1, h2;
  h1 = h2 = 0;
  if (t[i].l != -1) {
    setHeight(t[i].l);
    h1 = h[t[i].l] + 1;
  }
  if (t[i].r != -1) {
    setHeight(t[i].r);
    h2 = h[t[i].r] + 1;
  }
  h[i] = std::max(h1, h2);
}

int main() {
  int n;
  std::cin >> n;
  int id, left, right;

  rep(i, n) {
    t[i] = Node{-1, -1, -1};
    sib[i] = -1;
  }

  rep(i, n) {
    std::cin >> id >> left >> right;
    t[id].l = left;
    t[id].r = right;
    if (left != -1) {
      sib[left] = right;
      t[left].p = id;
    }
    if (right != -1) {
      sib[right] = left;
      t[right].p = id;
    }
  }

  int root;
  rep(i, n) {
    if (t[i].p == -1) root = i;
  }
  setDepth(root, 0);
  setHeight(root);
  print(n);
  return 0;
}
