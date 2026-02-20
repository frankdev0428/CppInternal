#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Hoang_Le_IntBinaryTree-1.h"
using namespace std;

int main()
{
    srand(time(0));

    cout << "WELCOME TO THE BST LABYRINTH!\n";
    cout << "The tree has 5 hidden nodes (1-5).\n";
    cout << "Clear the tree by guessing all the nodes to win!\n";
    cout << "Stumble into the void (nullptr) and you lose!\n\n";

    vector<int> nums;

    // Generate 5 unique random numbers
    while (nums.size() < 5)
    {
        int r = rand() % 5 + 1;

        bool duplicate = false;
        for (int n : nums)
        {
            if (n == r)
            {
                duplicate = true;
                break;
            }
        }

        if (!duplicate)
            nums.push_back(r);
    }

    IntBinaryTree tree;

    for (int n : nums)
        tree.insertNode(n);

    while (!tree.isEmpty())
    {
        int currentValue = tree.getRootValue();

        while (true)
        {
            int guess;
            cout << "Enter your guess (1-5): ";
            cin >> guess;

            if (guess == currentValue)
            {
                cout << "CORRECT! Removing node "
                     << guess
                     << " and resetting to the root.\n";

                tree.remove(guess);

                if (!tree.isEmpty())
                    cout << "Nodes remaining...\n\n";

                break;
            }

            else if (guess < currentValue)
            {
                cout << "TOO LOW! You are one branch closer to the void!\n\n";

                if (!tree.searchNode(guess))
                {
                    cout << "INCORRECT! You stumbled into the void (nullptr)!\n";
                    cout << "GAME OVER. The BST labyrinth claimed you...\n";
                    return 0;
                }
            }

            else
            {
                cout << "TOO HIGH! You are one branch closer to the void!\n\n";

                if (!tree.searchNode(guess))
                {
                    cout << "INCORRECT! You stumbled into the void (nullptr)!\n";
                    cout << "GAME OVER. The BST labyrinth claimed you...\n";
                    return 0;
                }
            }
        }
    }

    cout << "CONGRATULATIONS! You escaped the BST Labyrinth!\n";

    return 0;
}