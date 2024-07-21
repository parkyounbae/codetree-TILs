#include <iostream>
using namespace std;

int n,m;
int result;
int arr[101];

void re_sort(int delete_count) {
    int deleted_count = 0;
    int index = 1;
    while(deleted_count != delete_count) {
        int start = -1;
        int end = -1;

        for(int i=index ; i<=result ; i++) {
            if(arr[i] == -1) {
                start = i;
                break;
            }
        }

        for(int i=start+1 ; i<=result ; i++) {
            if(arr[i] != -1) {
                end = i-1;
                break;
            }
        }

        for(int i=start ; i<=result ; i++) {
            if(+(end-start+1) <= result) {
                arr[i] = arr[i+(end-start+1)];
            } else {
                arr[i] = 0;
            }
        }

        deleted_count += (end-start+1);
        result = result - (end-start+1);

        // cout << "deleted_count : " << deleted_count << endl;
        // cout << "result : " << result << endl;

        // for(int i=1 ; i<=result ; i++) {
        //     cout << arr[i] << " ";
        // }
    }
}

void bomb() {
    int delete_count = 0;
    while(result != 0) {
        int index = arr[1];
        int count = 1;
        for(int i=1 ; i<result ; i++) {
            if(index == arr[i+1]) {
                count ++;
            } else {
                if(count >= m) {
                    for(int j=0 ; j<count ; j++) {
                        arr[i-j] = -1;
                    }
                    delete_count += count;
                } 
                count = 1;
                index = arr[i+1];
            }
        }
        if(delete_count == 0) {
            break;
        } else {
            re_sort(delete_count);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    result = n;

    for(int i=1 ; i<=n ; i++) {
        cin >> arr[i];
    }

    bomb();

    cout << result << endl;
    for(int i=1 ; i<=result ; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}