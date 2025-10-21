#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Move {
    int squareNum;
    int value;
};

const int NUMROWS = 4;
const int NUMCOLS = 4;
const int BOARDSIZE = NUMROWS * NUMCOLS;
const int WINX = 1;
const int WINO = -1;

struct Board {
    char squares[BOARDSIZE];
    int numFilled;
};

Move bestMove(Board & bd);

bool xTurn(const Board & bd) {
    return bd.numFilled % 2 == 0;
}
bool oTurn(const Board & bd) {
    return bd.numFilled % 2 == 1;
}

bool isFull(const Board & bd) {
    return bd.numFilled == BOARDSIZE;
}

bool isFree(const Board & bd, int sq) {
    return bd.squares[sq] == '-';
}
bool isX(const Board & bd, int sq) {
    return bd.squares[sq] == 'X';
}
bool isO(const Board & bd, int sq) {
    return bd.squares[sq] == 'O';
}

// Return 1 for X win, -1 for O win and zero for nobody has won so far
int immediateValue(const Board& bd) {
    if (NUMROWS > 4 || NUMCOLS > 4) {
        cout << "Unsupported board size" << endl;
        return 0;
    }
    // Determine correct return value for 4 by 4 board

    int winningSquares[16][4] = {
        { 0, 1, 2, 3 },  { 4, 5, 6, 7  }, { 8, 9, 10, 11 }, { 12, 13, 14, 15 },
        { 0, 4, 8, 12 }, { 1, 5, 9, 13 }, { 2, 6, 10, 14 }, { 3, 7, 11, 15 },
        { 0, 5, 10, 15 }, { 3, 6, 9, 12 }, { 0, 3, 12, 15}, {5, 6, 9, 10}, {4, 7, 8, 11}, {1, 2, 13, 14}, { 1,7,14,8 }, {2, 11, 13, 4 } };
     // FILL IN

    return 0;  // didn't find a win for X or for O
}

// Does the current board have three X's
bool isWinX(const Board & bd) {
    return immediateValue(bd) == 1;
}

// Does the current board have three 0's 
bool isWinO(const Board & bd) {
    return immediateValue(bd) == -1;
}

// Determine the value of the current board,
// i.e. is it an ultimate win for 'X' (value 1)
// an ultimate win fo 'O'
int boardValue(Board & bd) {
    int val = immediateValue(bd);
    if (val != 0 || isFull(bd)) return val;
    return bestMove(bd).value;
}

// Determine the best move for the current board
Move bestMove(Board & bd) {
    bool xT = xTurn(bd);
    int bestValue = xT ? -10 : 10;
    int bestSquare = -1;
    char ch = xT ? 'X' : 'O';
    for (int squareNum = 0; squareNum < BOARDSIZE; squareNum++) {
        if (isFree(bd, squareNum)) {
            bd.squares[squareNum] = ch; // try moving to squareNum
            bd.numFilled++;
            int v = boardValue(bd);  // determ
            if (xT ? v > bestValue : v < bestValue) {
                bestValue = v;
                bestSquare = squareNum;
            }
            bd.squares[squareNum] = '-'; // undo move
            bd.numFilled--;
        }
        if (xT ? bestValue == WINX : bestValue == WINO)
            return Move{ bestSquare, bestValue };
    }
    return Move{ bestSquare,bestValue };
}





// Print the board
void printBoard(const Board & bd) {
    cout << endl;
    for (int i = 0; i < NUMROWS; i++) {
        for (int j = 0; j < NUMCOLS; j++) {
            cout << bd.squares[i * NUMCOLS + j] << "  ";
        }
        cout << "\t\t";
        for (int j = 0; j < NUMCOLS; j++) {
            int sq = i * NUMCOLS + j;
            cout << sq << " "; if (sq < 10) cout << " ";
        }
        cout << endl << endl;
    }
    cout << endl;
}

// Mark the given square with an X or O depending on whose move it is
void moveTo(Board & bd, int squareNum) {
    char ch = (bd.numFilled % 2 == 0 ? 'X' : 'O');
    if (isFree(bd, squareNum)) {
        bd.squares[squareNum] = ch;
        bd.numFilled++;
    }
    else cout << "ERROR, squareNum = " << squareNum << endl;
}

// initialize the board
void initBoard(Board & bd) {
    for (int i = 0; i < BOARDSIZE; i++)
        bd.squares[i] = '-';  // meaning a 'blank'
    bd.numFilled = 0;  // no square has 'X' or 'O' yet
}
int getRandomSquare(Board& bd) {
    bool found;
    int sq;
    do {
        sq = rand() % BOARDSIZE;
        found = bd.squares[sq] == '-';
       
    } while (!found);
    return sq;
}


int main()
{
    srand(time(0));
    Board bd;
  
    cout << "Computer starts? (y/n) ";
    char response;
    cin >> response;
    bool computerTurn = response == 'y';
    bool gameOver = false;
    int squareNum;
    initBoard(bd);
    int preMoves;
    cout << "Please enter the number of squares to randomly fill in ( > 3) :";
    cin >> preMoves;
    for (int i = 0; i < preMoves; i++) moveTo(bd, getRandomSquare(bd));
    if (preMoves < 4) preMoves = 4;

    printBoard(bd);
    while (!gameOver) {
        if (computerTurn) {
            int sqn = bestMove(bd).squareNum;
            moveTo(bd, sqn);
            cout << "Computer moves to square " << sqn << endl;
        }
        else {
            printBoard(bd);
            cout << "Enter square number: ";

            cin >> squareNum;
            moveTo(bd, squareNum);
            printBoard(bd);
        }
        if (isFull(bd) || isWinX(bd) || isWinO(bd))
            gameOver = true;
        else computerTurn = !computerTurn;
    }
    int v = immediateValue(bd);
    printBoard(bd);
    if (v == 0) cout << "Cat's game" << endl;
    else if (computerTurn) cout << "Computer wins!" << endl;
    else cout << "You win!" << endl;

    return 0;
}


