#include <iostream>
#include <algorithm>

#define MAX_NUM 200

using namespace std;

int n, m;
int grid[MAX_NUM][MAX_NUM];

int blocks[6][3][3] = {
    {{1, 0, 0},
    {1, 1, 0},
    {0, 0, 0}},
    {{0, 1, 0},
    {1, 1, 0},
    {0, 0, 0}},
    {{1, 1, 0},
    {1, 0, 0},
    {0, 0, 0}},
    {{1, 1, 0},
    {0, 1, 0},
    {0, 0, 0}},
    {{1, 1, 1},
    {0, 0, 0},
    {0, 0, 0}},
    {{1, 0, 0},
    {1, 0, 0},
    {1, 0, 0}}
};

int GetSumOfGrid(int x, int y) {
    int max_sum = 0;

    for (int block = 0; block < 6; block++) {
        int sum = 0;
        bool is_in_range = true;
        for (int dx = 0; dx < 3; dx++) {
            for (int dy = 0; dy < 3; dy++) {
                if (blocks[block][dx][dy] == 0) 
                    continue;
                if (x + dx >= n || y + dy >= m)
                    is_in_range = false;
                else
                    sum += grid[x + dx][y + dy];
            }
        }
        if (is_in_range)
            max_sum = max(max_sum, sum);
    }

    return max_sum;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cin >> grid[row][col];
        }
    }

    int max_sum = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            max_sum = max(max_sum, GetSumOfGrid(row, col));
        }
    }

    cout << max_sum;
    return 0;
}