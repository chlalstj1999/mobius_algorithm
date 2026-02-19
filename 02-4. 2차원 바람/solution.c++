#include <iostream>

#define MAX_NUM 100
#define DIR_NUM 5

using namespace std;

int n, m;
int grid[MAX_NUM][MAX_NUM];
int temp_grid[MAX_NUM][MAX_NUM];

void Rotate(int row_s, int col_s, int row_e, int col_e) {
    int temp = grid[row_s][col_s];

    for (int row = row_s; row < row_e; row++) {
        grid[row][col_s] = grid[row + 1][col_s];
    }

    for (int col = col_s; col < col_e; col++) {
        grid[row_e][col] = grid[row_e][col + 1];
    }

    for (int row = row_e; row > row_s; row--) {
        grid[row][col_e] = grid[row - 1][col_e];
    }

    for (int col = col_e; col > col_s; col--) {
        grid[row_s][col] = grid[row_s][col - 1];
    }

    grid[row_s][col_s + 1] = temp;
}

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int Average(int x, int y) {
    int dx[DIR_NUM] = {0, 1, -1, 0, 0};
    int dy[DIR_NUM] = {0, 0, 0, -1, 1};

    int sum = 0, cnt = 0;

    for (int dir = 0; dir < DIR_NUM; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];

        if (InRange(nx, ny)) {
            sum += grid[nx][ny];
            cnt++;
        }
    }

    return sum / cnt;
}

void SetAverage(int row_s, int col_s, int row_e, int col_e) {
    for (int row = row_s; row <= row_e; row++) {
        for (int col = col_s; col <= col_e; col++) {
            temp_grid[row][col] = Average(row, col);
        }
    }

    for (int row = row_s; row <= row_e; row++) {
        for (int col = col_s; col <= col_e; col++) {
            grid[row][col] = temp_grid[row][col];
        }
    }
}

void Simulate(int row_s, int col_s, int row_e, int col_e) {
    Rotate(row_s, col_s, row_e, col_e);

    SetAverage(row_s, col_s, row_e, col_e);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int q;
    cin >> n >> m >> q;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cin >> grid[row][col];
        }
    }

    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--;
        r2--; c2--;

        Simulate(r1, c1, r2, c2);
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
    return 0;
}