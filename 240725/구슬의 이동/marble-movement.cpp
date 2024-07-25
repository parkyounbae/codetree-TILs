#include <iostream>
#include <queue>

using namespace std;

struct Ball {
    int priority;
    int speed;
    int dir;

    Ball() {

    }

    Ball(int priority, int speed, int dir) {
        this->priority = priority;
        this->speed = speed;
        this->dir = dir;
    }

    bool operator<(const Ball s) const {
        if(this->speed == s.speed) {
            return this->priority > s.priority;
        }
        return this->speed > s.speed;
    }
};

int n,m,t,k;
priority_queue<Ball> arr[50][50];

int dir_r[4] = {-1, 1, 0,0};
int dir_c[4] = {0,0,-1,1};

int get_result() {
    int result = 0;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            result += arr[i][j].size();
        }
    }

    return result;
}

void print_arr() {
    cout << "\n";
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cout << arr[i][j].size() << " ";
        }
        cout << "\n";
    }
}

void tick() {
    priority_queue<Ball> temp_arr[50][50];

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            while (!arr[i][j].empty()) {
                Ball temp = arr[i][j].top();
                arr[i][j].pop();

                int next_r = i;
                int next_c = j;
                int next_dir = temp.dir;

                for(int k=0 ; k<temp.speed ; k++) {
                    // cout << next_dir << endl;
                    if(next_r+dir_r[next_dir] < 0 || next_r+dir_r[next_dir] >=n || next_c+dir_c[next_dir] < 0 || next_c+dir_c[next_dir]>=n) {
                        if(next_dir == 0) {
                            next_dir = 1;
                        } else if (next_dir == 1) {
                            next_dir = 0;
                        } else if (next_dir == 2) {
                            next_dir = 3;
                        } else if (next_dir == 3) {
                            next_dir = 2;
                        }
                    }

                    next_r += dir_r[next_dir];
                    next_c += dir_c[next_dir];
                }

                temp.dir = next_dir;
                temp_arr[next_r][next_c].push(temp);
            }
        }
    }

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            while(!arr[i][j].empty()) {
                arr[i][j].pop();
            }

            if(temp_arr[i][j].size() > k) {
                while(temp_arr[i][j].size() > k) {
                    temp_arr[i][j].pop();
                }
            }

            while(!temp_arr[i][j].empty()) {
                Ball temp = temp_arr[i][j].top();
                temp_arr[i][j].pop();
                arr[i][j].push(temp);
            }
        }
    }




}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> t >> k;

    for(int i=0 ; i<m ; i++) {
        int r,c,v;
        char d;
        cin >> r >> c >> d >> v;
        if(d == 'U') {
            arr[r-1][c-1].push(Ball(i,v,0));
        } else if (d=='D') {
            arr[r-1][c-1].push(Ball(i,v,1));
        } else if (d=='L') {
            arr[r-1][c-1].push(Ball(i,v,2));
        } else {
            arr[r-1][c-1].push(Ball(i,v,3));
        }
    }

    // print_arr();
    for(int i=0 ; i<t ; i++) {
        tick();
        // print_arr();
    }

    cout << get_result() << endl;



    return 0;
}