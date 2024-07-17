#include <iostream>
using namespace std;

int arr[21][21];
int n;

int get_num(int r, int c) {
    int result = 0;
    for(int i=0 ; i<3 ; i++) {
        for(int j=0 ; j<3 ; j++) {
            result += arr[i+r][j+c];
        }
    }

    return result;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cin >> arr[i][j];
        }
    }

    int result = 0;

    for(int i=0 ; i<=n-3 ; i++) {
        for(int j=0 ; j<=n-3 ; j++) {
            int temp = get_num(i,j);
            if(temp > result) {
                result = temp;
            }
        }
    }

    cout << result << endl;


    return 0;
}