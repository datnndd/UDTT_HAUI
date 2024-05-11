#include <iostream>
#include <string>

#define MAX 6

using namespace std;

struct HOCSINH {
    string ten;
    string tenDem;
    int namSinh;
    string diaChi;
};

HOCSINH b[100];

void mergeSort(HOCSINH hs[], int l, int r) {
    if (r > l) {
        int m = (l + r) / 2;
        mergeSort(hs, l, m);
        mergeSort(hs, m + 1, r);
        for (int i = m; i >= l; i--)
            b[i] = hs[i];
        for (int j = m + 1; j <= r; j++)
            b[m + r + 1 - j] = hs[j];
        int i = l, j = r;
        for (int k = l; k <= r; k++) {
            if (b[i].ten < b[j].ten) {
                hs[k] = b[i];
                i++;
            }
            else {
                hs[k] = b[j];
                j--;
            }
        }
    }
}

void hienThi(HOCSINH hs[], int n) {
    for (int i = 0; i < n; i++)
        cout << hs[i].tenDem << " " << hs[i].ten << " " << hs[i].namSinh << " " << hs[i].diaChi << " \n";
}

int timKiem(HOCSINH hs[], int l, int r , string& ten) {
    if (l > r) return -1;
    int m = (l + r) / 2;
    if (hs[m].ten == ten) {
        return m;
    }
    if (hs[m].ten < ten)    return timKiem(hs, m + 1, r, ten);
    if (hs[m].ten > ten)    return timKiem(hs, l, m -1, ten);
    return -1;
}

int main() {
    HOCSINH hs[MAX] = {
        {"anh", "nguyen van", 2000, "c"},
        {"bang", "nguyen dinh", 2000, "c"},
        {"hieu", "le trung", 2000, "c"},
        {"binh", "tran nguyen", 2000, "c"},
        {"an", "le phuong", 2000, "c"},
        {"tam", "nguyen thi", 2000, "c"}
    };
    cout << "Danh sach khoi tao: \n";
    hienThi(hs, MAX);
    mergeSort(hs, 0, MAX - 1);
    cout << "Danh sach sau khi duoc sap xep: \n";
    hienThi(hs, MAX);
    string ten = "an";
    int viTri = timKiem(hs, 0, MAX - 1, ten);
    if (viTri != -1) {
        cout << "vi tri: " << viTri << endl;
        cout << hs[viTri].tenDem << " " << hs[viTri].ten << " " << hs[viTri].namSinh << " " << hs[viTri].diaChi << " \n";
    }
    else {
        cout << "Khong tim thay ten can tim" << endl;
    }
    return 0;
}
