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

Move bestMove(Board &bd);

bool xTurn(const Board &bd) { return bd.numFilled % 2 == 0; }
bool oTurn(const Board &bd) { return bd.numFilled % 2 == 1; }
bool isFull(const Board &bd) { return bd.numFilled == BOARDSIZE; }
bool isFree(const Board &bd, int sq) { return bd.squares[sq] == '-'; }

int immediateValue(const Board &bd) {
    int winCombos[10][4] = {
        {0,1,2,3}, {4,5,6,7}, {8,9,10,11}, {12,13,14,15},
        {0,4,8,12}, {1,5,9,13}, {2,6,10,14}, {3,7,11,15},
        {0,5,10,15}, {3,6,9,12}
    };
    int xCount = 0, oCount = 0;

    for (int i = 0; i < 10; i++) {
        int a = winCombos[i][0], b = winCombos[i][1], c = winCombos[i][2], d = winCombos[i][3];
        if (bd.squares[a] == 'X' && bd.squares[b] == 'X' && bd.squares[c] == 'X' && bd.squares[d] == 'X')
            xCount++;
        if (bd.squares[a] == 'O' && bd.squares[b] == 'O' && bd.squares[c] == 'O' && bd.squares[d] == 'O')
            oCount++;
    }

    if (xCount > oCount) return WINX;
    else if (oCount > xCount) return WINO;
    else return 0; // tie
}

int boardValue(Board &bd) {
    int val = immediateValue(bd);
    if (isFull(bd)) return val;
    return bestMove(bd).value;
}

Move bestMove(Board &bd) {
    bool xT = xTurn(bd);
    int bestValue = xT ? -10 : 10;
    int bestSquare = -1;
    char mark = xT ? 'X' : 'O';

    for (int i = 0; i < BOARDSIZE; i++) {
        if (isFree(bd, i)) {
            bd.squares[i] = mark;
            bd.numFilled++;
            int v = boardValue(bd);  // recursive call
            if (xT && v > bestValue) {
                bestValue = v;
                bestSquare = i;
            }
            if (!xT && v < bestValue) {
                bestValue = v;
                bestSquare = i;
            }
            bd.squares[i] = '-';
            bd.numFilled--;
        }
    }
    return Move{bestSquare, bestValue};
}

void printBoard(const Board &bd) {
    cout << endl;
    for (int i = 0; i < NUMROWS; i++) {
        for (int j = 0; j < NUMCOLS; j++) {
            cout << bd.squares[i * NUMCOLS + j] << "  ";
        }
        cout << "\t\t";
        for (int j = 0; j < NUMCOLS; j++) {
            int sq = i * NUMCOLS + j;
            cout << sq << " ";
            if (sq < 10) cout << " ";
        }
        cout << endl << endl;
    }
    cout << endl;
}

void moveTo(Board &bd, int squareNum) {
    char mark = (bd.numFilled % 2 == 0 ? 'X' : 'O');
    if (isFree(bd, squareNum)) {
        bd.squares[squareNum] = mark;
        bd.numFilled++;
    } else {
        cout << "ERROR: square already filled\n";
    }
}

void initBoard(Board &bd) {
    for (int i = 0; i < BOARDSIZE; i++) bd.squares[i] = '-';
    bd.numFilled = 0;
}

int getRandomSquare(Board &bd) {
    int sq;
    do {
        sq = rand() % BOARDSIZE;
    } while (!isFree(bd, sq));
    return sq;
}

void countTallies(const Board &bd, int &xCount, int &oCount) {
    int winCombos[10][4] = {
        {0,1,2,3}, {4,5,6,7}, {8,9,10,11}, {12,13,14,15},
        {0,4,8,12}, {1,5,9,13}, {2,6,10,14}, {3,7,11,15},
        {0,5,10,15}, {3,6,9,12}
    };
    xCount = 0;
    oCount = 0;
    for (int i = 0; i < 10; i++) {
        int a = winCombos[i][0], b = winCombos[i][1], c = winCombos[i][2], d = winCombos[i][3];
        if (bd.squares[a] == 'X' && bd.squares[b] == 'X' && bd.squares[c] == 'X' && bd.squares[d] == 'X')
            xCount++;
        if (bd.squares[a] == 'O' && bd.squares[b] == 'O' && bd.squares[c] == 'O' && bd.squares[d] == 'O')
            oCount++;
    }
}
int main() {
    srand(time(0));
    Board bd;
    initBoard(bd);

    cout << "Computer starts? (y/n) ";
    char response;
    cin >> response;
    bool computerTurn = (response == 'y');

    int preMoves;
    cout << "Please enter the number of squares to randomly fill in ( > 3) :";
    cin >> preMoves;
    if (preMoves < 4) preMoves = 4;

    for (int i = 0; i < preMoves; i++)
        moveTo(bd, getRandomSquare(bd));

    printBoard(bd);

    while (!isFull(bd)) {
        if (computerTurn) {
            Move mv = bestMove(bd);
            moveTo(bd, mv.squareNum);
            cout << "Computer moves to square " << mv.squareNum << endl;
            printBoard(bd);
        } else {
            int sq;
            cout << "Enter square number: ";
            cin >> sq;
            moveTo(bd, sq);
            printBoard(bd);
        }
        computerTurn = !computerTurn; // alternate turns
    }

    int xCount, oCount;
    countTallies(bd, xCount, oCount);

    cout << endl;
    printBoard(bd);
    if (xCount > oCount) {
        cout << "X wins!" << endl;
    } else if (oCount > xCount) {
        cout << "O wins!" << endl;
    } else {
        cout << "Cat's game" << endl;
    }
    cout << "x tally is " << xCount << endl;
    cout << "o tally is " << oCount << endl;

    return 0;
}
