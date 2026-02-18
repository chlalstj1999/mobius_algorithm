#include <iostream>
#include <algorithm>

#define MAX_N 20
#define DIR_NUM 4

using namespace std;

int n, m;
int grid[MAX_N][MAX_N];

int GetCharge(int k) {
    return k * k + (k + 1) * (k + 1);
}

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int GetNumOfGoldInBorder(int x, int y, int k) {
    int num_of_gold = 0;

    if (k == 0)
        return grid[x][y];
    
    int dx[DIR_NUM] = {-1, 1, 1, -1}, dy[DIR_NUM] = {1, 1, -1, -1};
    int curr_x = x, curr_y = y - k;
    
    for (int dir = 0; dir < DIR_NUM; dir++) {
        for (int step = 0; step < k; step++) {
            if (InRange(curr_x, curr_y)) {
                num_of_gold += grid[curr_x][curr_y];
            }
            
            curr_x += dx[dir];
            curr_y += dy[dir];
        }
    }

    return num_of_gold;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cin >> grid[row][col];
        }
    }

    int max_gold = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            int num_of_gold = 0;
            for (int k = 0; k <= 2 * (n - 1); k++) {
                num_of_gold += GetNumOfGoldInBorder(row, col, k);

                if (num_of_gold * m >= GetCharge(k))
                    max_gold = max(max_gold, num_of_gold);
            }
        }
    }

    cout << max_gold;

    return 0;
}