#include <iostream>
using namespace std;

int n;
int arr[201][201];

void bomb(int r, int c) {
    int power = arr[r][c];
    arr[r][c] = -1;
    for(int i=1 ; i<power ; i++) {
        if(r+i <= n) {
            arr[r+i][c] = -1;
        }
        if(r-i > 0) {
            arr[r-i][c] = -1;
        }

        if(c+i <= n) {
            arr[r][c+i] = -1;
        }
        
        if(c-i > 0) {
            arr[r][c-i] = -1;
        }
    }
}

void gravity() {
    for(int i=1 ; i<= n ; i++) {
        int start = -1;
        int end = -1;

        for(int j=1 ; j<=n ; j++) {
            if(arr[j][i] == -1) {
                start = j;
                break;
            }
        }

        if(start != -1) {
            for(int j=start ; j<=n ; j++) {
                if(arr[j][i] == -1) {
                    end = j;
                } else {
                    break;
                }
            }

            for(int j=end ; j>=start ; j--) {
                if(j-(end-start+1)>0 ) {
                    arr[j][i] = arr[j-(end-start+1)][i];
                } else {
                    arr[j][i] = 0;
                }
                
            }
            for(int j=start-1 ; j>0 ; j--) {
                arr[j][i] = 0;
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            cin >> arr[i][j];
        }
    }

    int r,c;
    cin >> r >> c;

    bomb(r,c);
    gravity();

    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}