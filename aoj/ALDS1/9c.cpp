#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

void maxHeapify(std::vector<int> &a, int i) {
  int n = a.size() - 1;
  int left = 2 * i;
  int right = left + 1;
  int largest = i;
  if (left <= n && a[left] > a[i]) largest = left;
  if (right <= n && a[right] > a[largest]) largest = right;

  if (largest != i) {
    int temp = a[i];
    a[i] = a[largest];
    a[largest] = temp;
    maxHeapify(a, largest);
  }
}

void insert(std::vector<int> &a, int k) {
  a.push_back(k);
  int i = a.size() - 1;
  while (i > 1 && a[i] > a[i / 2]) {
    int temp = a[i];
    a[i] = a[i / 2];
    a[i / 2] = temp;
    i = i / 2;
  }
}

int extractMax(std::vector<int> &a) {
  int max = a[1];
  a[1] = a[a.size() - 1];
  a.erase(a.end() - 1);
  maxHeapify(a, 1);
  return max;
}

int main() {
  std::vector<int> a;
  a.push_back(-1);

  std::string com;
  int key;
  while (1) {
    std::cin >> com;
    if (com == "insert") {
      std::cin >> key;
      insert(a, key);
    } else if (com == "extract") {
      std::cout << extractMax(a) << '\n';
    } else {
      break;
    }
  }

  return 0;
}
