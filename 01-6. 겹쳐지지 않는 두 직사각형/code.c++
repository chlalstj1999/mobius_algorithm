#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_NUM 5

using namespace std;

int n, m;
int grid[MAX_NUM][MAX_NUM];
int rect[MAX_NUM][MAX_NUM];

void ClearRect() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rect[i][j] = 0;
        }
    }
}

void Draw(int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            rect[i][j]++;
        }
    }
}

bool CheckRect() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (rect[i][j] >= 2)
                return true;
        }
    }
    return false;
}

bool Overlapped(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    ClearRect();
    Draw(x1, y1, x2, y2);
    Draw(x3, y3, x4, y4);
    return CheckRect();
}

int GetSum(int x1, int y1, int x2, int y2) {
    int sum = 0;

    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            sum += grid[i][j];
        }
    }

    return sum;
}

int GetSumInTwoRect(int x1, int y1, int x2, int y2) {
    int max_sum = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < m; l++) {
                    if (!Overlapped(x1, y1, x2, y2, i, j, k, l))
                        max_sum = max(max_sum, GetSum(x1, y1, x2, y2) + GetSum(i, j, k, l));
                }
            }
        }
    }

    return max_sum;
}

int GetMaxInTwoRect() {
    int max_sum = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < m; l++) {
                    max_sum = max(max_sum, GetSumInTwoRect(i, j, k, l));
                }
            }
        }
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

    int max_sum = GetMaxInTwoRect();

    cout << max_sum;

    return 0;
}