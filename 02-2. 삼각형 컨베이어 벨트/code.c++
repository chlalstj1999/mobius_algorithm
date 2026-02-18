#include <iostream>

#define MAX_N 200

using namespace std;

int n, t;
int a[MAX_N];
int b[MAX_N];
int c[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    while(t--) {
        int temp = c[n - 1];

        for (int i = n - 1; i >= 1; i--) 
            c[i] = c[i - 1];
        c[0] = b[n - 1];

        for (int i = n - 1; i >= 1; i--)
            b[i] = b[i - 1];
        b[0] = a[n - 1];

        for (int i = n - 1; i >= 1; i--)
            a[i] = a[i - 1];
        a[0] = temp;
    }

    for (int i = 0; i < n; i++) 
        cout << a[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++) 
        cout << b[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++) 
        cout << c[i] << " ";
        
    return 0;
}