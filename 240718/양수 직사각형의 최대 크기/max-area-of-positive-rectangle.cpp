#include <iostream>
using namespace std;

int n,m;
int arr[20][20];

int result;

bool check_minus(int r1, int c1, int r2, int c2) {
    for(int i=r1 ; i<=r2 ; i ++) {
        for(int j=c1 ; j<=c2 ; j++) {
            if(arr[i][j] <= 0) {
                return false;
            }
        }
    }
    return true;
}

int check_board(int r, int c) {
    int partial_max = -1;
    for(int i=r ; i<n ; i++) {
        for(int j=c ; j<m ; j++) {
            if(check_minus(r,c,i,j)) {
                int temp = (i-r+1)*(j-c+1);
                if(partial_max < temp) {
                    partial_max = temp;
                }
            }
        }
    }
    return partial_max;
}

int main() {
    // 여기에 코드를 작성해주세요.
    result = -1;
    cin >> n >> m;

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            int temp = check_board(i,j);
            if(result < temp) {
                result = temp;
            }
        }
    }

    cout << result << endl;


    return 0;
}