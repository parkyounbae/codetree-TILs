#include <iostream>
using namespace std;

int n,m;
int arr[201][201];

int check() {

    int max_num = 0;

    // 가로모양
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m-2 ; j++){
            int temp = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            if(max_num < temp) {
                max_num = temp;
            }
        }
    }

    // 세로모양
    for(int i=0 ; i<n-2 ; i++) {
        for(int j=0 ; j<m ; j++){
            int temp = arr[i][j] + arr[i+1][j] + arr[i+2][j];
            if(max_num < temp) {
                max_num = temp;
            }
        }
    }

    // ㄴ
    for(int i=0 ; i<n-1 ; i++) {
        for(int j=0 ; j<m-1 ; j++){
            int temp = arr[i][j] + arr[i+1][j+1] + arr[i+1][j];
            if(max_num < temp) {
                max_num = temp;
            }
        }
    }

    // ㅣ-
    for(int i=0 ; i<n-1 ; i++) {
        for(int j=0 ; j<m-1 ; j++){
            int temp = arr[i][j] + arr[i][j+1] + arr[i+1][j];
            if(max_num < temp) {
                max_num = temp;
            }
        }
    }

    // ㄱ
    for(int i=0 ; i<n-1 ; i++) {
        for(int j=0 ; j<m-1 ; j++){
            int temp = arr[i][j] + arr[i][j+1] + arr[i+1][j+1];
            if(max_num < temp) {
                max_num = temp;
            }
        }
    }

    // ㅢ
    for(int i=0 ; i<n-1 ; i++) {
        for(int j=0 ; j<m-1 ; j++){
            int temp = arr[i+1][j] + arr[i][j+1] + arr[i+1][j+1];
            if(max_num < temp) {
                max_num = temp;
            }
        }
    }

    return max_num;

}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            cin >> arr[i][j];
        }
    }

    cout << check() << endl;
    return 0;
}