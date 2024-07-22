#include <iostream>
#include <vector>

using namespace std;

int n,r,c;
int arr[100][100];
vector<int> result;

int dir_r[4] = {-1,1,0,0};
int dir_c[4] = {0,0,-1,1};

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> r >> c;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cin >> arr[i][j];
        }
    }

    r = r-1;
    c=c-1;

    while(true) {
        result.push_back(arr[r][c]);
        if(r+1 < n && arr[r-1][c] > arr[r][c]) {
                r = r+1;
            } else if(r-1 >=0 && arr[r+1][c] > arr[r][c]) {
                r = r-1;
            } else if(c-1 >= 0 && arr[r][c-1] > arr[r][c]) {
                c = c-1;
            } else if(c+1 < n && arr[r][c+1] > arr[r][c]) {
                c = c+1;
            } else {
                break;
            }
    }

    for(int i=0 ; i<result.size() ; i++) {
        cout << result.at(i) << " ";
    }


    return 0;
}