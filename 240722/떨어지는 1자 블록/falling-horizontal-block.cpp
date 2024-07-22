#include <iostream>
using namespace std;

int n,m,k;
int arr[101][101];

void check() {
    int index = 0;
    for(int i=1 ; i<=n ; i++) {

        bool is_blocked = false;

        for(int j=k ; j<k+m ; j++) {
            if(arr[i][j] == 1) {
                index = i - 1;
                is_blocked = true;
                break;
            }
        }
        if(is_blocked) {
            break;
        } else if(!is_blocked && i==n) {
            index = n;
        }
    }

    for(int j=k ; j<k+m ; j++) {
        arr[index][j] = 1;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> k;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            cin >> arr[i][j];
        }
    }

    check();

    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}