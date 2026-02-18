#include <iostream>

#define MAX_N 20
#define DIR_NUM 4

using namespace std;

int n;
int grid[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int GetSumOfSquare(int x, int y, int k, int l) {
    int sum = 0;
    int dx[DIR_NUM] = {-1, -1, 1, 1}, dy[DIR_NUM] = {1, -1, -1, 1};
    int move_num[DIR_NUM] = {k, l, k, l};

    for (int curr_dir = 0; curr_dir < DIR_NUM; curr_dir++) {
        for (int move = 0; move < move_num[curr_dir]; move++) {
            if (!InRange(x, y))
                return 0;
            
            sum += grid[x][y];
            x += dx[curr_dir];
            y += dy[curr_dir];
        }
    }

    return sum;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cin >> grid[row][col];
        }
    }

    int max_sum = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            for (int k = 1; k < n; k++) {
                for (int l = 1; l < n; l++) {
                    max_sum = max(max_sum, GetSumOfSquare(row, col, k, l));
                }
            }
        }
    }

    cout << max_sum;

    return 0;
}