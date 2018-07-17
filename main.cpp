//  main.cpp
//  Swanson_TicTacToe
//  Created by Jacob Swanson on 11/15/12.
//  Copyright (c) 2012 Jacob Swanson. All rights reserved.

#include <iostream>
#include <string>
using namespace std;

int row = -1;
int col = -1;
string rowInput;
string colInput;

string winner;
string tic[3][3];

class TicTacToe
{
public:
  void create();
  void draw();
  void setvalues(int, int);
};

int checkDigit(string input)
{
  if (isdigit(input[0]))
  {
    return stoi(input);
  }

  return -1;
}

bool inRange(int val)
{
  return val > -1 && val < 3;
}

int checkMove(string input, string type)
{
  bool isValid = false;
  int val = -1;

  while (!isValid)
  {
    val = checkDigit(input);
    if (val != -1 && inRange(val))
    {
      isValid = true;
    }
    else
    {
      cout << "Invalid value for " + type + ", pick again: ";
      cin >> input;
    }
  }

  return val;
}

bool spotTaken()
{
  if (row == -1 || col == -1)
  {
    return true;
  }

  if (tic[row][col] != " ")
  {
    return true;
  }

  return false;
}

void TicTacToe::create()
{
  for (int k = 0; k < 3; k++)
  {
    for (int z = 0; z < 3; z++)
    {
      tic[k][z] = " ";
    }
  }
}

void draw()
{
  string horizontalLine = "------------------------";
  string spacing = "      ";

  cout << " " + spacing + "0" + spacing + "1" + spacing + "2" << endl;

  // Dynamically draw tic tac toe board
  for (int row = 0; row < 3; row++)
  {
    cout << horizontalLine << endl;
    cout << std::to_string(row) + spacing;
    for (int column = 0; column < 3; column++)
    {
      cout << tic[row][column] << spacing;
    }
    cout << endl;
  }
}

void makeMove(int movesMade)
{
  if (movesMade % 2)
  {
    tic[row][col] = "O";
  }
  else
  {
    tic[row][col] = "X";
  }

  // Redraw board
  draw();

  // Reset values for next move
  row = -1;
  col = -1;
}

string checkWin(int movesMade)
{
  // Translate array to easy to read vars
  string topLeft = tic[0][0];
  string topCenter = tic[0][1];
  string topRight = tic[0][2];

  string midLeft = tic[1][0];
  string midCenter = tic[1][1];
  string midRight = tic[1][2];

  string bottomLeft = tic[2][0];
  string bottomCenter = tic[2][1];
  string bottomRight = tic[2][2];

  // Default comparator to X so only have to check for O
  string comparator = "X";

  // Can determine a win by first checking the 3 squares in any diagonal

  // Get value of topLeft, set comparator to that value
  if (topLeft.compare("X") != 0)
  {
    comparator = "O";
  }

  // Check straight line wins from topLeft. Diagonal wins will be checked from midCenter square

  // check if topCenter matches topLeft
  if (topCenter.compare(comparator) == 0)
  {
    // check if topRight matches topLeft
    if (topRight.compare(comparator) == 0)
    {
      return comparator;
    }
  }

  // check if midLeft matches topLeft
  if (midLeft.compare(comparator) == 0)
  {
    // check if bottomLeft matches topLeft
    if (bottomLeft.compare(comparator) == 0)
    {
      return comparator;
    }
  }

  // Check squares that that can win from center square, straight lines and diagonals

  comparator = "X";
  // Get value of midCenter, set comparator to that value
  if (midCenter.compare("X") != 0)
  {
    comparator = "O";
  }

  // check if topCenter matches midCenter
  if (topCenter.compare(comparator) == 0)
  {
    // check if bottomCenter matches midCenter
    if (bottomCenter.compare(comparator) == 0)
    {
      return comparator;
    }
  }

  // check if midLeft matches midCenter
  if (midLeft.compare(comparator) == 0)
  {
    // check if midRight matches midCenter
    if (midRight.compare(comparator) == 0)
    {
      return comparator;
    }
  }

  // check if topLeft matches midCenter
  if (topLeft.compare(comparator) == 0)
  {
    // check if bottomRight matches midCenter
    if (bottomRight.compare(comparator) == 0)
    {
      return comparator;
    }
  }

  // check if topRight matches midCenter
  if (topRight.compare(comparator) == 0)
  {
    // check if bottomLeft matches midCenter
    if (bottomLeft.compare(comparator) == 0)
    {
      return comparator;
    }
  }

  // Check straight line wins from bottomRight. Diagonal wins checked from midCenter square
  comparator = "X";
  if (bottomRight.compare("X") != 0)
  {
    comparator = "O";
  }

  // check if midRight matches bottomRight
  if (midRight.compare(comparator) == 0)
  {
    // check if topRight matches bottomRight
    if (topRight.compare(comparator) == 0)
    {
      return comparator;
    }
  }

  // check if bottomCenter matches bottomRight
  if (bottomCenter.compare(comparator) == 0)
  {
    // check if bottomLeft matches bottomRight
    if (bottomLeft.compare(comparator) == 0)
    {
      return comparator;
    }
  }

  if (movesMade == 9)
  {
    return "cat";
  }

  return "";
}

int main()
{
  string playAgain = "Y";
  while (playAgain == "Y" || playAgain == "y")
  {
    TicTacToe play;
    play.create();
    cout << "X goes first" << endl;

    // Draw board
    draw();

    // Only 9 moves can be made
    for (int moves = 0; moves < 9; moves++)
    {
      cout << endl
           << "Enter row #: ";
      cin >> rowInput;

      cout << endl
           << "Enter column #: ";
      cin >> colInput;

      while (spotTaken())
      {
        row = checkMove(rowInput, "row");
        col = checkMove(colInput, "column");

        // Reset variables
        rowInput = -1;
        colInput = -1;
      }
      makeMove(moves);

      // No one can win until at least 5 moves are made
      if (moves >= 4)
      {
        winner = checkWin(moves);
        if (!winner.empty())
        {
          cout << winner + " wins!" << endl;

          cout << endl
               << "Play again? (Y/N): ";
          cin >> playAgain;
          break;
        }
      }
    }
  }
}