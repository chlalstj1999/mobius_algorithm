#include <iostream>

#define MAX_N 100

using namespace std;

int n;
int blocks[MAX_N];

int end_of_blocks;

void CutArray(int start_idx, int end_idx) {
    int temp_blocks[MAX_N];
    int idx = 0;
    for (int i = 0; i < end_of_blocks; i++) {
        if (i >= start_idx && i <= end_idx)
            continue;
        
        temp_blocks[idx++] = blocks[i];
    }

    for (int i = 0; i < idx; i++) {
        blocks[i] = temp_blocks[i];
    }

    end_of_blocks = idx;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }
    
    end_of_blocks = n;

    for (int k = 0; k < 2; k++) {
        int s, e;
        cin >> s >> e;
        s--; e--;

        CutArray(s, e);
    }

    cout << end_of_blocks << endl;
    for (int i = 0; i < end_of_blocks; i++) {
        cout << blocks[i] << endl;
    }

    return 0;
}