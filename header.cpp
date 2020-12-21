#include "header.h"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

void play::table() {
  char board[3][3] = {{'0', '1', '2'}, {'3', '4', '5'}, {'6', '7', '8'}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << board[i][j] << ' ';
    }
    cout << "\n\n";
  }
}

int play::playing() {
  int turn = rand() % 2;
  int number = 0, x = 0, y = 0;
  char board[3][3];
  initialize(board);
  print_board(board);
  while (true) {
    
    cin >> number;
    x = number / 3;
    y = number % 3;
    board[x][y] = 'X';
    bot(board);
    print_board(board);
    if (check(board)) {
      break;
    }
  }
  cout <<"DONE";
}

void play::bot(char board[][3]) {
  int x = 0, y = 0;
  while (true) {
    x = rand() % 3;
    y = rand() % 9;
    if (board[x][y] == '-') {
      board[x][y] = 'O';
      break;
    }
  }
  //cout <<"DONE";
}

bool play::check(char board[][3]) {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
      return true;
    } else if (board[0][i] == board[1][i] && board[1][i]== board[2][i] &&
               board[0][i] != '-') {
      return true;
    } else if (board[0][0] == board[1][1]&& board[1][1] == board[2][2] &&
               board[0][0] != '-') {
      return true;
    }
  }
  
  return false;
}

void play::initialize(char board[][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = '-';
    }
  }
}

void play::print_board(char board[][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << board[i][j] << " ";
    }
    cout << "\n\n";
  }
}
