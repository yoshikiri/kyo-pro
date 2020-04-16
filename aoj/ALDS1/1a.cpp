#include <iostream>

void printArray(int *A, int N) {
  for (int i = 0; i < N; i++) {
    if (i > 0)
      std::cout << " ";
    std::cout << A[i];
  }
  std::cout << '\n';
}

void swap(int *x, int *y) {
  int t = *x;
  *x = *y;
  *y = t;
}

// void insertionSort(int *A, int N) {
//   for (int i = 1; i < N; i++) {
//     int v = A[i];
//
//     int j = i - 1;
//
//     while (j >= 0 && v < A[j]) {
//       A[j + 1] = A[j];
//       j--;
//     }
//
//     A[j + 1] = v;
//
//     printArray(A, N);
//   }
// }

// void insertionSort(int *A, int N) {
//   for (int i = 1; i < N; i++) {
//     for (int j = i - 1; j >= 0; j--) {
//       if (A[i] < A[j]) {
//         swap(&A[i], &A[j]);
//       } else {
//         break;
//       }
//     }
//     printArray(A, N);
//   }
// }

void insertionSort(int *A, int N) {
  for (int i = 1; i < N; i++) {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && v < A[j]) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    printArray(A, N);
  }
}

int main() {
  int N;
  std::cin >> N;

  int A[N];
  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  printArray(A, N);
  insertionSort(A, N);

  return 0;
}
