#include <iostream>

#define MAX_NUM 100
#define SHIFT_RIGHT 0
#define SHIFT_LEFT 1

using namespace std;

int n, m;
int buildings[MAX_NUM][MAX_NUM];

void Shift(int row, int dir) {
    if (dir == SHIFT_RIGHT) {
        int temp = buildings[row][m - 1];
        for (int col = m - 1; col > 0; col--) {
            buildings[row][col] = buildings[row][col - 1];
        }
        buildings[row][0] = temp;
    }

    if (dir == SHIFT_LEFT) {
        int temp = buildings[row][0];
        for (int col = 0; col < m - 1; col++) {
            buildings[row][col] = buildings[row][col + 1];
        }
        buildings[row][m - 1] = temp;
    }
}

bool HasSameNumber(int row1, int row2) {
    for (int col = 0; col < m; col++) {
        if (buildings[row1][col] == buildings[row2][col])
            return true;
    }

    return false;
}

int Flip(int dir) {
    return dir == SHIFT_LEFT ? SHIFT_RIGHT : SHIFT_LEFT;
}

void Simulate(int start_row, int start_dir) {
    Shift(start_row, start_dir);
    start_dir = Flip(start_dir);

    for (int row = start_row, dir = start_dir; row > 0; row--) {
        if (HasSameNumber(row, row - 1)) {
            Shift(row - 1, dir);
            dir = Flip(dir);
        }
        else
            break;
    }

    for (int row = start_row, dir = start_dir; row < n - 1; row++) {
        if (HasSameNumber(row, row + 1)) {
            Shift(row + 1, dir);
            dir = Flip(dir);
        }
        else 
            break;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int q;
    cin >> n >> m >> q;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cin >> buildings[row][col];
        }
    }

    while(q--) {
        int r;
        char d;
        cin >> r >> d;
        r--;

        Simulate(r, d == 'L' ? SHIFT_RIGHT : SHIFT_LEFT);
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cout << buildings[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}