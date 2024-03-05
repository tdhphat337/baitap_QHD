#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    freopen("MUAHANG.INP","r",stdin);
    freopen("MUAHANG.OUT","w",stdout);
    // Nh?p s? lu?ng ph?n t?
    int n;
    cin >> n;

    // Nh?p d? li?u vào vector
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // S?p x?p vector
    sort(a.begin(), a.end());

    // Tính toán k?t qu?
    long long res = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] <= res) {
            res += a[i];
        }
    }

    // In k?t qu?
    cout << res;

    return 0;
}
// sau 6 ngay n truc lai
// sau 4 ngayt h truc lai
//ngay 1 lun ruc chnh
//=>ngay 1 la 1
