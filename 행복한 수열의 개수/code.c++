#include <iostream>
#include <algorithm>

#define MAX_N 100

using namespace std;

int n, m;
int grid[MAX_N][MAX_N];
int arr[MAX_N];

int IsHappy() {
    int max_of_cons = 1;
    int num_of_cons = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i - 1] == arr[i]) {
            num_of_cons++;
        } else {
            num_of_cons = 1;
        }

        max_of_cons = max(max_of_cons, num_of_cons);
    }

    return (max_of_cons >= m);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cin >> grid[row][col];
        }
    }

    int num_of_happy = 0;

    for (int row = 0; row < n; row++) {
        int idx = 0;
        for (int col = 0; col < n; col++) {
            arr[idx++] = grid[row][col];
        }

        if (IsHappy())
            num_of_happy++;
    }

    for (int col = 0; col < n; col++) {
        int idx = 0;
        for (int row = 0; row < n; row++) {
            arr[idx++] = grid[row][col];
        }

        if (IsHappy())
            num_of_happy++;
    }

    cout << num_of_happy;

    return 0;
}