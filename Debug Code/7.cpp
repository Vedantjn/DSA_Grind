#include<iostream>
using namespace std;

int main() {
  int n;
  std::cin>>n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i; j++) {
      printf("  ");
    }
    for (int j = i; j < 2 * i; j++) {
      printf("%d ", j);
    }
    int ele = 2 * (i - 1);
    for (int j = 1; j <= i - 1; j++) {
      printf("%d ", ele--);
    }
    printf("\n");
  }
  return 0;
}