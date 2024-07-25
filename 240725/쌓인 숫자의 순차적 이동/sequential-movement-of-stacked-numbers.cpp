#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> arr[20][20];
int r_arr[401];
int c_arr[401];

int dir_r[8] = {1,1,1,0,0,-1,-1,-1};
int dir_c[8] = {-1, 0 ,1, -1, 1 ,-1, 0, 1};

int get_high(int r, int c) {
    int max_value = 0;
    for(int i=0 ; i<arr[r][c].size() ; i++) {
        if(max_value < arr[r][c].at(i)) {
            max_value = arr[r][c].at(i);
        }
    }

    return max_value;
}

void tick(int r, int c, int num) {
    int next_dir = -1;
    int value = 0;
    for(int i=0 ; i<8 ; i++) {
        int next_r = r + dir_r[i];
        int next_c = c + dir_c[i];

        if(next_r>=0 && next_r<n && next_c>=0 && next_c<n){
            int temp_value = get_high(next_r, next_c);
            if(temp_value > value) {
                value = temp_value;
                next_dir = i;
            }
        }
    }

    if(next_dir == -1) {
        return;
    }

    int next_r = r + dir_r[next_dir];
    int next_c = c + dir_c[next_dir];

    bool is_found = false;
    int index = 0;
    int memory_size = arr[r][c].size();
    for(int i=0 ; i<memory_size ; i++) {
        if(!is_found && arr[r][c].at(i) == num) {
            is_found = true;
            index = i;
        }

        if(is_found) {
            // cout << "found : " << arr[r][c].at(index) << ", move" << endl;
            arr[next_r][next_c].push_back(arr[r][c].at(index));
            r_arr[arr[r][c].at(index)] = next_r;
            c_arr[arr[r][c].at(index)] = next_c;
            arr[r][c].erase(arr[r][c].begin() + index);
        }
    }


}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            int temp;
            cin >> temp;
            arr[i][j].push_back(temp);
            r_arr[temp] = i;
            c_arr[temp] = j;
        }
    }

    for(int i=0 ; i<m ; i++) {
        int num;
        cin >> num;

        tick(r_arr[num], c_arr[num], num);
    }

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            for(int k=arr[i][j].size()-1 ; k>=0 ; k--) {
                cout << arr[i][j].at(k) << " ";
            }
            if(arr[i][j].size() == 0) {
                cout << "None";
            }
            cout << "\n";
        }
    }


    return 0;
}