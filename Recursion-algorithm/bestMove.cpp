#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Move {
    int num;
    char pile;
    bool canWin;
};

Move bestMove(int a, int b, int c) {
    // An obvious base case is when a = b = c = 0. In that case, 
    // just return e.g. Move{0,'a',true}
    if (a + b + c == 0) return Move{0,'a', true}; // possible base case
    // BELOW IS DUMMY CODE TO BE REMOVED
    // if (a > 0) return Move{1, 'a', false};
    // if (b > 0) return Move{1, 'b', false};
    // if (c > 0) return Move{1, 'c', false};
    // END OF DUMMY CODE

   
    // For the recursive calls, try removing all possible values from pile 'a', 
    // then all possible
    // values from pile 'b', then all possible values from pile 'c'. 
    // (OK to use for loops.) 
    // If any of those recursive calls give back 
    // a Move object with canWin equal to false,
    // then the computer has found a winning move (since the opponent is forced to lose.)
    // That means the return value should be a Move object 
    // with num equal to the number removed,
    // pile equal to the pile that was used and canWin equal to true.
    // Suggested code below for case where the computer doesn't think it can win,
    // just to randomize behavior.
    // Or you can make computer just remove one item from any nonempty pile.

    for (int i = a; i >= 1; i--) 
        if (!bestMove(a-i, b, c).canWin) 
            return Move{i,'a', true};
        
    for (int i = b; i >= 1; i--) 
        if (!bestMove(a, b-i, c).canWin) 
            return Move{i,'b', true};
        
    for (int i = c; i >= 1; i--) 
        if (!bestMove(a, b, c-i).canWin) 
            return Move{i,'c', true};

    if (a >= b && a >= c) 
        return Move{ rand()%(a) +1 ,'a', false};
    if (b >= c) return Move{ rand() % (b) + 1 ,'b', false };
    return Move{ rand() % (c) + 1,'c', false };
}

int main()
{
    srand(time(0));
    int a, b, c;
    char response = 'y';
    bool gameOver = false;
    do {
        cout << "Enter initial values for piles a, b and c: ";
        cin >> a >> b >> c;
        if (a + b + c <= 1) 
          cout << "Not a legal starting configuration." << endl;
    } while (a + b + c <= 1);
    cout << "Inital piles are a = " 
         << a << ", b = " << b << " and c = " << c << endl;
    while (!gameOver) {
        cout << "Enter number to remove and which pile: ";
        int num; char pile;
        cin >> num >> pile;
        
        if (pile == 'a') {a -= num; if (a < 0) a = 0;}
        else if (pile == 'b') {b -= num; if (b < 0) b = 0;}
        else {c -= num; if (c < 0) c = 0;}
        cout << "Computer's turn with piles a = " 
             << a << ", b = " << b << " and c = " << c << endl;
        Move p = bestMove(a, b, c);
        if (p.canWin) cout << "(computer happy)\t";
        else  cout << "(computer not happy)\t";
        cout << endl;
        if (p.num == 0) {
            cout << "Computer won." << endl;
            gameOver = true;
        }
        else {
            cout << "Computer removes " << p.num << " from pile "
                << p.pile << "," << endl;
            if (p.pile == 'a') a -= p.num;
            else if (p.pile == 'b') b -= p.num;
            else if (p.pile == 'c') c -= p.num;
            cout << "That gives (a,b,c) = (" <<  a << "," << b 
                 << "," << c << ")" << endl;
            if (a + b + c == 0) {
                cout << "Computer lost." << endl;
                gameOver = true;
            }
            else {
                cout << "Continue? [y/n] ";
                char ch;
                cin >> response;
                gameOver = response != 'y';
            }
        }
    }
    cout << "Bye" << endl;
    return 0;
}