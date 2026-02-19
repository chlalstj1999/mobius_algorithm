#include <iostream>
#include <vector>

#define MAX_N 100
#define DIR_NUM 4
#define CCW 0
#define CW 1

using namespace std;

int n;
int grid[MAX_N][MAX_N];
int temp_grid[MAX_N][MAX_N];

void Shift(int x, int y, int k, int l, int dir) {
    vector<int> dx, dy, move_nums;

    if (dir == CCW) {
        dx = {-1, -1, 1, 1};
        dy = {1, -1, -1, 1};
        move_nums = {k, l, k, l};
    } else {
        dx = {-1, -1, 1, 1};
        dy = {-1, 1, 1, -1};
        move_nums = {l, k, l, k};
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp_grid[i][j] = grid[i][j];
        }
    }

    for (int d = 0; d < DIR_NUM; d++) {
        for (int move = 0; move < move_nums[d]; move++) {
            int nx = x + dx[d], ny = y + dy[d];
            temp_grid[nx][ny] = grid[x][y];
            x = nx; y = ny;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = temp_grid[i][j];
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cin >> grid[row][col];
        }
    }

    int row, col, m1, m2, m3, m4, dir;
    cin >> row >> col >> m1 >> m2 >> m3 >> m4 >> dir;

    Shift(--row, --col, m1, m2, dir == 0 ? CCW : CW);

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
    return 0;
}