#include <iostream>
#include <string>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct card {
  char suit;
  int num;
};

void swapCard(card *x, card *y) {
  card temp = *x;
  x->suit = y->suit;
  x->num = y->num;

  y->suit = temp.suit;
  y->num = temp.num;
}

void bubbleSort(card *c, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = n - 1; j > i; j--) {
      if (c[j].num < c[j - 1].num) {
        swapCard(&c[j], &c[j - 1]);
      }
    }
  }
}

void selectionSort(card *c, int n) {
  rep(i, n) {
    int minIndex = i;
    for (int j = i; j < n; ++j) {
      if (c[j].num < c[minIndex].num) {
        minIndex = j;
      }
    }

    swapCard(&c[i], &c[minIndex]);
  }
}

bool isStable(card *origin, card *sorted, int n) {
  rep(i, n) {
    for (int j = i + 1; j < n; ++j) {
      if (origin[i].num == origin[j].num) {
        int a, b;
        for (int k = 0; k < n; ++k) {
          if (sorted[k].suit == origin[i].suit &&
              sorted[k].num == origin[i].num) {
            a = k;
          } else if (sorted[k].suit == origin[j].suit &&
                     sorted[k].num == origin[j].num) {
            b = k;
          }
        }

        // std::cout << "i, j: " << i << ", " << j << '\n';
        // std::cout << "a, b: " << a << ", " << b << '\n';
        if (a > b)
          return false;
      }
    }
  }

  return true;
}

int main() {
  int n;
  std::cin >> n;
  std::string a[n];
  rep(i, n) std::cin >> a[i];

  card c[n];
  rep(i, n) {
    c[i].suit = a[i][0];
    c[i].num = a[i][1] - '0';
  }

  card d[n];
  rep(i, n) {
    d[i].suit = c[i].suit;
    d[i].num = c[i].num;
  }

  bubbleSort(d, n);

  rep(i, n) {
    std::cout << d[i].suit << d[i].num;
    if (i == n - 1)
      std::cout << '\n';
    else
      std::cout << ' ';
  }

  if (isStable(c, d, n))
    std::cout << "Stable" << '\n';
  else
    std::cout << "Not stable" << '\n';

  //
  rep(i, n) {
    d[i].suit = c[i].suit;
    d[i].num = c[i].num;
  }

  //
  selectionSort(d, n);

  rep(i, n) {
    std::cout << d[i].suit << d[i].num;
    if (i == n - 1)
      std::cout << '\n';
    else
      std::cout << ' ';
  }

  if (isStable(c, d, n))
    std::cout << "Stable" << '\n';
  else
    std::cout << "Not stable" << '\n';

  return 0;
}
