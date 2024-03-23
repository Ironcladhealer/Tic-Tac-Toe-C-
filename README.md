
# Tic Tac Toe Game

The Tic Tac Toe Game Project is an object-oriented programming (OOP) adaptation of the popular Tic Tac Toe game in C++. The project's goal is to deliver a simple and intuitive console-based gaming experience. The architecture stresses code modularity, reusability, and maintainability by leveraging inheritance and polymorphism principles. This paper delves into the development process, significant features, and insights obtained while making this C++ Tic Tac Toe game.




## Authors

- Saim Raza 
- Muhammad Ahmad Kashif


## Acknowledgements

 - [How to create a Tic Tac Toe game in C++: https://www.youtube.com/watch?v=KrH1qNVYKO0&t=492s]

## Roadmap

- Roadmap has been created from:
  www.code2flow.com

- To understand this code better, click on this link to understand the code:
  https://app.code2flow.com/5uBetkzkFVWx.png

## Key Concepts

Game Class:

- Attributes:

  1) board: Represents the Tic Tac Toe board.
  2) turn: Tracks the current turn.
  3) currentPlayer: Stores the symbol ('X' or 'O') of the current player.

- Methods:

   1) start(): Initiates the game loop, taking turns between players until a win or tie occurs.
   2) printBoard(): Pure virtual function to be  implemented by derived classes. Displays the current state of the board.
   3) getMove(): Pure virtual function to be implemented by derived classes. Collects player input for row and column and updates the board accordingly.
   4) checkWin(): Pure virtual function to be implemented by derived classes. Checks if the current player has won.
   5) checkTie(): Pure virtual function to be implemented by derived classes. Checks if the game is a tie.
   6) togglePlayer(): Pure virtual function to be implemented by derived classes. Switches the current player between 'X' and 'O'.
   7) showResult(): Pure virtual function to be implemented by derived classes. Displays the result of the game.


TicTacToe Class (Derived from Game):

- Constructor:

  Initializes the Tic Tac Toe board using the initializeBoard() function.

- Private Methods:

  initializeBoard(): Initializes the board with empty spaces.


- Overridden Methods:

  1) printBoard(): Displays the Tic Tac Toe board with the current state.
  2) getMove(): Collects player input for row and column, handling exceptions for invalid input.
  3) checkWin(): Checks for a win by examining rows, columns, and diagonals.
  4) checkTie(): Checks for a tie by verifying if there are no empty cells left.
  5) togglePlayer(): Switches the current player between 'X' and 'O'.
  6) showResult(): Displays the result of the game.

- Additional Method:

  emptyCheck(): Checks if the board has any empty cells.

Main Function:

  Creates an instance of the TicTacToe class and initiates the game by calling start().