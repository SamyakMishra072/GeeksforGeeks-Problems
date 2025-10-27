#include <iostream>
#include <list>
using namespace std;

/*
 * Problem: Josephus Circle (Last Man Standing)
 * ---------------------------------------------
 * There are n people standing in a circle. Every k-th person is eliminated
 * until only one person remains. You need to find the position of the last person.
 *
 * Approach:
 * - Use a list to represent the people standing in a circle.
 * - Use an iterator to move (k - 1) steps forward each time.
 * - Remove the k-th person and continue until one remains.
 */

int josephus(int n, int k) {
    list<int> people;

    // Fill the circle with people numbered 1 to n
    for (int i = 1; i <= n; i++) {
        people.push_back(i);
    }

    // Iterator to traverse the list
    auto it = people.begin();

    // Continue until one person remains
    while (people.size() > 1) {
        // Move (k - 1) steps ahead in circular fashion
        for (int i = 1; i < k; i++) {
            ++it;
            if (it == people.end()) {
                it = people.begin();  // wrap around to the start
            }
        }

        // Erase the k-th person
        it = people.erase(it);

        // If iterator reaches the end, start from the beginning
        if (it == people.end()) {
            it = people.begin();
        }
    }

    // The last remaining person is the safe position
    return people.front();
}

int main() {
    int n = 5, k = 3;
    cout << "The safe position is: " << josephus(n, k) << endl;
    return 0;
}
