#include <iostream>
#include <algorithm>

#define MAX_N 20

using namespace std;

int n;
int grid[MAX_N][MAX_N];

int GetNumOfCoin(int row_s, int col_s, int row_e, int col_e) {
    int num_of_coin = 0;

    for (int i = row_s; i <= row_e; i++) {
        for (int j = col_s; j <= col_e; j++) {
            num_of_coin += grid[i][j];
        }
    }

    return num_of_coin;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cin >> grid[row][col];
        }
    }

    int max_coin = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row + 2 >= n || col + 2 >= n) continue;

            max_coin = max(max_coin, GetNumOfCoin(row, col, row + 2, col + 2));
        }
    }

    cout << max_coin;
    return 0;
}