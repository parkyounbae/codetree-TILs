#include <iostream>
using namespace std;

int n,m;
int arr[20][20];

int dir_r[8] = {-1, -1, -1, 0, 0, 1 ,1 ,1};
int dir_c[8] = {-1, 0, 1,-1, 1,-1, 0,1};

void tick() {
    int num = n*n;

    for(int num_to_exchange=1 ; num_to_exchange<=num ; num_to_exchange++) {
        bool found = false;
        for(int i=0 ; i<n && !found ; i++) {
            for(int j=0 ; j<n && !found ; j++) {
                if(arr[i][j] == num_to_exchange) {
                    int temp_value = 0;
                    int temp_dir = 0;
                    for(int k=0 ; k<8 ; k++) {
                        if(i+dir_r[k] >=0 && j+dir_c[k] >=0 && i+dir_r[k] <n && j+dir_c[k] <n && arr[i+dir_r[k]][j+dir_c[k]] > temp_value) {
                            temp_value = arr[i+dir_r[k]][j+dir_c[k]];
                            temp_dir = k;
                        }
                    }

                    arr[i+dir_r[temp_dir]][j+dir_c[temp_dir]] = arr[i][j];
                    arr[i][j] = temp_value;
                    found = true;
                }
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0 ; i<m ; i++) {
        tick();
    }

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}