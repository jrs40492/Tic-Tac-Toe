//  main.cpp
//  Swanson_TicTacToe
//  Created by Jacob Swanson on 11/15/12.
//  Copyright (c) 2012 Jacob Swanson. All rights reserved.

#include <iostream>
#include <string>
using namespace std;

bool winner = false;
int **tic = new int *[3];

class moves //create class
{
public:
  int num;
  int row;
  int col;
  void create();
  void draw();
  void setvalues(int, int);
  void win(); //create constructors
  void taken()
  {
    while (tic[row][col] != 3)
    {
      cout << "Space taken, try again! "; //check if space is taken
      cin >> row >> col;                  //get in new move
    }
  }
  void move()
  {
    if (num == 0 || num == 2 || num == 4 || num == 6 || num == 8) //check num
    {
      tic[row][col] = 1; //set as 1 if player 1
      num++;
    }
    else
    {
      tic[row][col] = 0; //set as 0 if player 2
      num++;
    }
  }
  ~moves()
  {
    delete[] tic; //destructor deletes tic
  }
};

void moves::create()
{
  for (int q = 0; q < 3; q++)
  {
    tic[q] = new int[q]; //creates dynamic array
  }
  for (int k = 0; k < 3; k++)
  {
    for (int z = 0; z < 3; z++)
    {
      tic[k][z] = 3; //sets each value in tic array to 3
    }
  }
}

void moves::draw()
{
  cout << "      0      1      2" << endl;
  cout << "------------------------" << endl;
  cout << "0     " << tic[0][0] << "      " << tic[0][1] << "      " << tic[0][2] << endl;
  cout << "------------------------" << endl;
  cout << "1     " << tic[1][0] << "      " << tic[1][1] << "      " << tic[1][2] << endl;
  cout << "------------------------" << endl;
  cout << "2     " << tic[2][0] << "      " << tic[2][1] << "      " << tic[2][2]; //draw the array each time a move is made
}

void moves::win()
{
  if (tic[0][0] == 0 && tic[0][1] == 0 && tic[0][2] == 0) //checks each combination for a winner and breaks if found
  {
    draw();
    cout << endl
         << "Player 2 wins";
    winner = 1;
  }
  else if (tic[0][0] == 1 && tic[0][1] == 1 && tic[0][2] == 1)
  {
    draw();
    cout << endl
         << "Player 1 wins";
    winner = 1;
  }
  else if (tic[0][0] == 1 && tic[1][0] == 1 && tic[2][0] == 1)
  {
    draw();
    cout << endl
         << "Player 1 wins";
    winner = 1;
  }
  else if (tic[0][0] == 0 && tic[1][0] == 0 && tic[2][0] == 0)
  {
    draw();
    cout << endl
         << "Player 2 wins";
    winner = 1;
  }
  else if (tic[1][0] == 1 && tic[1][1] == 1 && tic[1][2] == 1)
  {
    draw();
    cout << endl
         << "Player 1 wins";
    winner = 1;
  }
  else if (tic[1][0] == 0 && tic[1][1] == 0 && tic[1][2] == 0)
  {
    draw();
    cout << endl
         << "Player 2 wins";
    winner = 1;
  }
  else if (tic[2][0] == 1 && tic[2][1] == 1 && tic[2][2] == 1)
  {
    draw();
    cout << endl
         << "Player 1 wins";
    winner = 1;
  }
  else if (tic[2][0] == 0 && tic[2][1] == 0 && tic[2][2] == 0)
  {
    draw();
    cout << endl
         << "Player 2 wins";
    winner = 1;
  }
  else if (tic[0][1] == 1 && tic[1][1] == 1 && tic[2][1] == 1)
  {
    draw();
    cout << endl
         << "Player 1 wins";
    winner = 1;
  }
  else if (tic[0][1] == 0 && tic[1][1] == 0 && tic[2][1] == 0)
  {
    draw();
    cout << endl
         << "Player 2 wins";
    winner = 1;
  }
  else if (tic[0][2] == 1 && tic[1][2] == 1 && tic[2][2] == 1)
  {
    draw();
    cout << endl
         << "Player 1 wins";
    winner = 1;
  }
  else if (tic[0][2] == 0 && tic[1][2] == 0 && tic[2][2] == 0)
  {
    draw();
    cout << endl
         << "Player 2 wins";
    winner = 1;
  }
  else if (tic[0][0] == 1 && tic[1][1] == 1 && tic[2][2] == 1)
  {
    draw();
    cout << endl
         << "Player 1 wins";
    winner = 1;
  }
  else if (tic[0][0] == 0 && tic[1][1] == 0 && tic[2][2] == 0)
  {
    draw();
    cout << endl
         << "Player 2 wins";
    winner = 1;
  }
  else if (tic[0][2] == 1 && tic[1][1] == 1 && tic[2][0] == 1)
  {
    draw();
    cout << endl
         << "Player 1 wins";
    winner = 1;
  }
  else if (tic[0][2] == 0 && tic[1][1] == 0 && tic[2][0] == 0)
  {
    draw();
    cout << endl
         << "Player 2 wins";
    winner = 1;
  }
  else if (num == 9)
  {
    cout << "Cats Game";
  }
}

void moves::setvalues(int a, int b)
{
  row = a;
  col = b; //sets user input to values row and col
}

int main()
{
  char again = 'Y';
  while (again == 'Y' || again == 'y')
  {
    int ch1;
    int ch2;
    int num = 0;

    moves play;
    play.create();
    cout << "X (1) goes first" << endl;
    for (int i = 0; i < 9; i++)
    {
      play.draw();
      cout << endl
           << "Please enter a row and column: "; //ask for user input
      cin >> ch1 >> ch2;
      play.setvalues(ch1, ch2);
      play.taken();
      play.move(); //call needed constructors
      num++;
      if (num >= 5)
      {
        play.win();
        if (winner)
        {
          break; //if winner found, end game
        }
      }
    }
    cout << endl
         << "Play again? (Y/N): "; //ask user to play again
    cin >> again;
  }
} //end program