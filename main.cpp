#include <iostream>
#include <string>

using namespace std;

class Game
{
protected:
    char board[3][3];
    int turn;
    char currentPlayer;

public:
    Game()
    {
    }

    virtual void start()
    {
        turn = 0;
        currentPlayer = 'X';
        printBoard();

        for (turn = 0; turn < 3; turn++)
        {
            cout << "Player " << currentPlayer << "'s turn" << endl;
            getMove();
            printBoard();
            if (turn == 2)
            {
                if (checkWin())
                {
                    break;
                }
                turn++;
            }
            togglePlayer();
            cout << "Player " << currentPlayer << "'s turn" << endl;
            getMove();
            printBoard();
            if (turn == 3 && checkWin())
            {
                break;
            }
            if (turn == 3 && checkTie())
            {
                break;
            }
            togglePlayer();
        };
        showResult();
    }

    virtual void printBoard() = 0;
    virtual void getMove() = 0;
    virtual bool checkWin() = 0;
    virtual bool checkTie() = 0;
    virtual void togglePlayer() = 0;
    virtual void showResult() = 0;
    virtual bool emptyCheck() = 0;
};

class TicTacToe : public Game
{
public:
    TicTacToe() : Game()
    {
        initializeBoard();
    }

private:
    void initializeBoard()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = ' ';
            }
        }
    }

    void printBoard() override
    {
        cout << "\t\t " << board[0][0] << "\t|" << board[0][1] << "\t|" << board[0][2] << "\n";
        cout << "\t\t__________________________\n";
        cout << "\t\t " << board[1][0] << "\t|" << board[1][1] << "\t|" << board[1][2] << "\n";
        cout << "\t\t__________________________\n";
        cout << "\t\t " << board[2][0] << "\t|" << board[2][1] << "\t|" << board[2][2] << "\n";
    }

    void getMove() override
    {
        int row, col;

        while (true)
        {
            try
            {
                cout << "Enter the row: ";
                cin >> row;

                if (row < 1 || row > 3)
                {
                    throw out_of_range("Row out of range. Please enter a number between 1 and 3.");
                }

                cout << "Enter the column: ";
                cin >> col;

                if (col < 1 || col > 3)
                {
                    throw out_of_range("Column out of range. Please enter a number between 1 and 3.");
                }

                if (board[row - 1][col - 1] == ' ')
                {
                    break;
                }
                else
                {
                    throw invalid_argument("Cell already occupied. Try again.");
                }
            }
            catch (const exception &e)
            {
                cerr << "Error: " << e.what() << endl;
                cin.clear();
            }
        }

        board[row - 1][col - 1] = currentPlayer;
    }

    bool checkWin() override
    {
        bool victory = false;
        for (int i = 0; i < 3 && (turn >= 2 || turn <= 4); i++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && (board[i][0] != ' '))
            {
                victory = true;
                return victory;
            }

            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && (board[i][0] != ' '))
            {
                victory = true;
                return victory;
            }
        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            victory = true;
            return victory;
        }

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            victory = true;
            return victory;
        }

        return victory;
    }

    bool checkTie() override
    {
        if (!checkWin() && emptyCheck())
        {
            return true;
        }
        return false;
    }

    void togglePlayer() override
    {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void showResult() override
    {
        if (checkWin())
        {
            cout << "Player " << currentPlayer << " wins!" << endl;
        }
        else
        {
            cout << "It's a tie!" << endl;
        }
    }
    bool emptyCheck() override
    {
        bool empty = false;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    empty = true;
                    return empty;
                    break;
                }
            }
            if (empty)
            {
                break;
            }
        }
        return empty;
    }
};

int main()
{
    TicTacToe game;
    game.start();

    return 0;
}