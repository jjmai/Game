#include "header.h"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

void play::table() {
  char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << board[i][j] << ' ';
    }
    cout << "\n";
  }
}

int play::playing() {
  int turn = rand() % 2;
  int p1;
  int p2;

  if (turn == 0) {
    cout << "Enter a Valid Position on The graph. You are 'X'\n\n";

    cin >> p1;
    cout << "\n\n";

    if (p1 > 0 && p1 <= 9) {
      while (true) {
        p2 = rand() % 9 + 1;
        if (p2 != p1) {
          break;
        }
      }
      for (int i = 1; i < 10; i++) {
        if (p1 == i) {
          cout << "X ";
        } else if (p2 == i) {
          cout << "O ";
        } else {
          cout << "-" << " ";
        }
        if (i > 0 && i % 3 == 0) {
          cout << "\n";
        }
      }
    }
  }
  cout << "\n";
  return 1;
}
