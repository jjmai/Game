#include "header.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  string choice;

  play a;
  while (true) {
    cout << "\n";
    cout << "Enter 'P' to play , Enter 'E' to exit\n\n";
    // getline(cin, choice);
    choice = getchar();
    if (choice.compare("E") == 0) {
      cout << "Thank You For Playing Tic Tac Toe!\n";
      break;
    } else if (choice.compare("P") == 0) {
      cout << "\n";
      a.table();
      a.playing();
    } else {
      cout << "Wrong Input\n";
    }
    break;
  }
}
