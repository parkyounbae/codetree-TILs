#include <iostream>
using namespace std;

int n,r,c;
char arr[101][101];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    cin >> r >> c;

    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            cin >> arr[i][j];
        }
    }

    int current_dir = 3;

    int time = 0;
    int current_r = r;
    int current_c = c;

    while(true) {
        if(time!=0 && current_c==c && current_r==r) {
            time = -1;
            break;
        }

        if(current_c>n || current_c<=0 || current_r>n || current_r<=0) {
            break;
        }

        if(current_dir == 0) {
            if(arr[current_r-1][current_c+1]=='#' && arr[current_r-1][current_c] != '#') {
                // go
                time++;
                current_r = current_r - 1;
            } else if(arr[current_r-1][current_c+1]!='#' && arr[current_r-1][current_c] != '#') {
                // go & turn right
                current_dir = 3;
                time++;
                current_r = current_r - 1;
            } else if(arr[current_r-1][current_c] == '#') {
                // turn left
                current_dir = 2;
            }
        } else if(current_dir == 1) {
            if(arr[current_r+1][current_c-1]=='#' && arr[current_r+1][current_c] != '#') {
                // go
                time++;
                current_r = current_r + 1;
            } else if(arr[current_r+1][current_c-1]!='#' && arr[current_r+1][current_c] != '#') {
                // go & turn right
                time++;
                current_r = current_r + 1;
                current_dir = 2;
            } else if(arr[current_r+1][current_c] == '#') {
                // turn left
                current_dir = 3;
            }
        } else if(current_dir == 2) {
            if(arr[current_r-1][current_c-1]=='#' && arr[current_r][current_c-1] != '#') {
                // go
                time++;
                current_c = current_c - 1;
            } else if(arr[current_r-1][current_c-1]!='#' && arr[current_r][current_c-1] != '#') {
                // go & turn right
                time++;
                current_c = current_c - 1;
                current_dir = 0;
            } else if(arr[current_r][current_c-1] == '#') {
                // turn left
                current_dir = 1;
            }
        } else if(current_dir == 3) {
            if(arr[current_r+1][current_c+1]=='#' && arr[current_r][current_c+1] != '#') {
                // go
                time++;
                current_c = current_c + 1;
            } else if(arr[current_r+1][current_c+1]!='#' && arr[current_r][current_c+1] != '#') {
                // go & turn right
                time++;
                current_c = current_c + 1;
                current_dir = 1;
            } else if(arr[current_r][current_c+1] == '#') {
                // turn left
                current_dir = 0;
            }
        }


    }

    cout << time << endl;

    return 0;
}