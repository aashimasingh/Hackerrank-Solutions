#include <iostream>
#include <string>
#define n 4

void display (int mat[n][n]) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      std::cout << mat[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int main() {
  int mat[n][n] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

  display(mat);
  std::cout << "\n";

  for (int i = 0; i < n/2; i++) {
    for (int j = i; j < n - i - 1; j++) {
      int temp = mat[i][j];
      mat[i][j] = mat[j][n-i-1];
      mat[j][n-i-1] = mat[n-i-1][n-j-1];
      mat[n-i-1][n-j-1] = mat[n-j-1][i];
      mat[n-j-1][i] = temp;
    }
  }
  display(mat);
}