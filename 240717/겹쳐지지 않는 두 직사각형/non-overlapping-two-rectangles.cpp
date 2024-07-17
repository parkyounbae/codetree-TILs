#include <iostream>
using namespace std;

int n,m;
int **arr;

int result;

int get_sum_rect(int r1, int c1, int r2, int c2) {
    int sum = 0;
    for(int i=r1 ; i<=r2 ; i++) {
        for(int j=c1; j<=c2 ; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

void set_second_rect(int r, int c, int f_r1, int f_c1, int f_r2, int f_c2, int amount) {
    if(r >= f_r1 && r <=f_r2 && c >= f_c1 && c <=f_c2) {
        return;
    }

    for(int i=r ; i<n ; i++) {
        for(int j=c ; j<m ; j++) {
            if(!(f_r1 < r && f_r2 > r)&&!(f_r1 < i && f_r2 > i)&&!(f_c1 < c && f_c2 > c)&&!(f_c1 < j && f_c2 > j)) {
                int temp = get_sum_rect(r,c,i,j);
                if(result < amount + temp) {
                    result = amount + temp;
                    cout << result << endl;
                    cout << f_r1 << " " << f_c1 << " " << f_r2 << " " << f_c2 << endl;
                    cout << r << " " << c << " " << i << " " << j << endl;
                }
                
            } 
        }
    }
}

void set_first_rect(int r, int c) {
    for(int i=r ; i<n ; i++) {
        for(int j=c ; j<m ; j++) {
            for(int k=0 ; k<n ; k++) {
                for(int l=0 ; l<m ; l++) {
                    set_second_rect(k,l,r,c,i,j,get_sum_rect(r,c,i,j));
                }
            }
        }
    }
}



int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    arr = new int*[n];
    for(int i=0 ; i<n ; i++) {
        arr[i] = new int[m]; 
    }

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            cin >> arr[i][j];
        }
    }

    result = arr[0][0] + arr[0][1];

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            set_first_rect(i,j);
        }
    }


    cout << result << endl;


    return 0;
}