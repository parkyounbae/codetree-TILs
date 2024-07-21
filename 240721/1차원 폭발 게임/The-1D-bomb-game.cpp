#include <iostream>
using namespace std;

int n,m;
int result;
int arr[101];

void re_sort(int delete_count) {
    int deleted_count = 0;
    int index = 1;
//    int loop_count = 0;
    while(deleted_count < delete_count) {
//        loop_count++;
//        if(loop_count>10) {
//            break;
//        }
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
            } else if(i==result && arr[i]==-1) {
                end = result;
            }
        }

        for(int i=start ; i<=result ; i++) {
            if(i+(end-start+1) <= result) {
                arr[i] = arr[i+(end-start+1)];
            } else {
                arr[i] = 0;
            }
        }

        deleted_count += (end-start+1);
        result = result - (end-start+1);
    }
}

void bomb() {
    while(true) {
        int delete_count = 0;
        int index_value = arr[1];
        int index_key = 1;
        for(int i=1 ; i<= result ; i++) {
            if(index_value == arr[i] && (i-index_key+1)>=m) {
                for(int j=i ; j>=index_key&&arr[j]!=-1; j--) {
                    arr[j] = -1;
                    delete_count++;
                }
            } else if(index_value != arr[i]) {
                index_key = i;
                index_value = arr[i];
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

    if(m==1) {
        cout << "0" << endl;
        return 0;
    }

    bomb();

    cout << result << endl;
    for(int i=1 ; i<=result ; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}