#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int arr[101][101];
int arr_copy[101][101];
int r,c,m,n;

int result = 0;

void tick(int time) {
    int distance = pow(2,time-1);
    memcpy(arr_copy, arr, sizeof(arr));

    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            if(arr[i][j] == 0) {
                if(i+distance <= n) {
                    arr_copy[i+distance][j] = 0;
                }

                if(i-distance > 0) {
                    arr_copy[i-distance][j] = 0;
                }

                if(j+distance <= n) {
                    arr_copy[i][j+distance] = 0;
                }

                if(j-distance > 0) {
                    arr_copy[i][j-distance] = 0;
                }
            }
        }
    }
    memcpy(arr, arr_copy, sizeof(arr));
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> r >> c;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            arr[i][j] = -1;
        }
    }

    arr[r][c] = 0;

    for(int i=1 ; i<=m ; i++) {
        tick(i);
    }

    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            // cout << arr[i][j] << " ";
            if(arr[i][j] == 0) {
                result ++;
            }
        }
        // cout << "\n";
    }

    cout << result << endl;

    return 0;
}