#include <iostream>
using namespace std;

int main() {
  // size of the pyramid
  int size; cin>>size;
  for (int i = 0; i < size; i++) {
    // print spaces
    for (int j = 0; j < i; j++) {
      cout << "  ";
    }
    // print stars
    for (int j = 0; j < 2 * size - 1 -2*i; j++) {
      cout << "* ";
    }
    cout << "\n";
  }
  return 0;
}