#include <iostream>
using namespace std;

int n,m;
int arr[201][201];

void gravity() {
    for(int c=1 ; c<=n ; c++) {
        int zero_start = -1;
        int zero_end = -1;
        for(int r=n ; r>0 ; r--) {
            if(arr[r][c] == 0) {
                zero_start = r;
                zero_end = r;
                break;
            }
        }

        if(zero_start != -1) {
            for(int i=zero_end ; i>0 ; i--) {
                if(zero_end - (zero_start-zero_end+1) > 0) {
                    arr[i][c] = arr[i - (zero_start-zero_end+1)][c];
                } else {
                    arr[i][c] = 0;
                }

            }
        }
    }

    

}

void bomb(int c) {
    int power = -1;
    int r = -1;
    for(int i=1 ; i<=n ; i++) {
        if(arr[i][c] != 0) {
            power = arr[i][c];
            r = i;
            break;
        }
    }

    if(power == -1) {
        return;
    }

    arr[r][c] = 0;

    for(int i=1 ; i<power ; i++) {
        if(r+i <= n) {
            arr[r+i][c] = 0;
        }

        if(r-i > 0) {
            arr[r-i][c] = 0;
        }

        if(c+i <= n) {
            arr[r][c+i] = 0;
        }

        if(c-i > 0) {
            arr[r][c-i] = 0;
        }
    }

    

    gravity();
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            cin >> arr[i][j];
        }
    }

    int command;
    for(int i=0 ; i<m ; i++) {
        cin >> command;
        bomb(command);
    }

    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}