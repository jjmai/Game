#include "header.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  string choice;

  play a;

  while (true) {
    cout << "Enter 'P' to play , Enter 'E' to exit\n\n";
    getline(cin, choice);
    if (choice.compare("E") == 0) {
      cout << "Thank You For Playing Tic Tac Toe!\n";
      break;
    } else if (choice.compare("P") == 0) {
      a.playing();

      a.table();
    }else {
      cout << "Wrong Input\n";
}
  }
}
