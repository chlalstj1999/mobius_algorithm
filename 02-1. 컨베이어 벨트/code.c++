#include <iostream>

#define MAX_N 200

using namespace std;

int n, t;
int arr1[MAX_N];
int arr2[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    while(t--) {
        int temp = arr2[n - 1];
        for (int i = n - 1; i >= 1; i--) {
            arr2[i] = arr2[i - 1];
        }
        arr2[0] = arr1[n - 1];

        for (int i = n - 1; i >= 1; i--) {
            arr1[i] = arr1[i - 1];
        }
        arr1[0] = temp;
    }

    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";
    
    cout << endl;

    for (int i = 0; i < n; i++) 
        cout << arr2[i] << " ";
    
    return 0;
}