#include "header.h"
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

#define PLAYER_TURN 0
#define BOT_TURN 1
// int steps =0;
using namespace std;

void play::table() {
  char board[3][3] = {{'0', '1', '2'}, {'3', '4', '5'}, {'6', '7', '8'}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << board[i][j] << ' ';
    }
    cout << "\n\n";
  }
  cout << "---------------------------------------------------------------\n"
       << "\n";
}

int play::playing() {
  srand(time(NULL));
  int turn = rand() % 2;
  int number = 0, x = 0, y = 0;
  char board[3][3];
  // instructions(steps);
  initialize(board);
  if (turn == 0) {
    cout << "Pick a Number\n";
    print_board(board);
  }
  while (true) {
    if (turn == PLAYER_TURN) {
      while (true) {
        cout << "You Picked Position: ";
        cin >> number;
        cout << "\n";
        x = number / 3;
        y = number % 3;
        if (board[x][y] != '-') {
          cout << "Spot Taken. Please Choose an available Position!\n\n";
          print_board(board);
        } else {
          break;
        }
      }
      board[x][y] = 'X';
      turn = BOT_TURN;
    } else {
      bot(board);
      turn = PLAYER_TURN;
    }
    print_board(board);

    if (check(board)) {
      if (turn == BOT_TURN) {
        cout << "You Win!\n";
      } else {
        cout << "You Lose!\n";
      }
      break;
    }
  }
  return 1;
}

void play::bot(char board[][3]) {
  int x = 0, y = 0;
  while (true) {
    srand(time(NULL));
    x = rand() % 3;
    y = rand() % 9;
    if (board[x][y] == '-') {
      board[x][y] = 'O';
      cout << "Bot Chose Position " << (x * 3) + y % 9
           << ". Your Turn to Pick a Number!\n\n";
      break;
    }
  }
  // cout <<"DONE";
}

bool play::check(char board[][3]) {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&
        board[i][0] != '-') {
      return true;
    } else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] &&
               board[0][i] != '-') {
      return true;
    } else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
               board[0][0] != '-') {
      return true;
    } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&
               board[0][2] != '-') {
      return true;
    }
  }

  return false;
}

void play::instructions(int steps) {
  cout << "This is the Tic-Tac-Toe Board. The Numbers Indicate the position "
          "\n"
       << "-------------------------------------------------------------\n"
       << "\n";
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
