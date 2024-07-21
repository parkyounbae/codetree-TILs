#include <iostream>
using namespace std;

int n;
int arr[101];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=1; i<=n ; i++) {
        cin >> arr[i];
    }

    int s1, e1;
    cin >> s1 >> e1;

    for(int i=s1 ; i<=e1 ; i++) {
        arr[i] = arr[i+(e1-s1+1)];
    }
    n = n-(e1-s1+1);

    cin >> s1 >> e1;

    for(int i=s1 ; i<=e1 ; i++) {
        arr[i] = arr[i+(e1-s1+1)];
    }
    n = n-(e1-s1+1);

    cout << n << endl;
    for(int i=1 ; i<=n ; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}