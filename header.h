
#ifndef Header_H
#define Header_H

class play {
public:
  void table();
  void player1();
  void player2();
  int playing();
  void bot(char board[][3]);
  bool check(char board[][3]);
  void instructions(int steps);
  void initialize(char board[][3]);
  void print_board(char bpard[][3]);
};

#endif
