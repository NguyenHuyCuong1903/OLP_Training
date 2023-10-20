#include <bits/stdc++.h>
using namespace std;
 
void towerOfHanoi(int n, int cot1, int cot3,
                  int cot2)
{
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, cot1, cot2, cot3);
    cout << cot1 << " " << cot3 << endl;
    towerOfHanoi(n-1, cot2, cot3, cot1);
}
 
// Driver code
int main()
{
    int n;
    cin >> n;
    cout << pow(2,n) - 1 << '\n';
    towerOfHanoi(n, 1, 3, 2);
    return 0;
}