#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct ChuyenBay {
    string soHieu;
    int giaVe;
    int soGhe;
};

void hienThiChuyenBay(const ChuyenBay& cb) {
    cout << "So hieu: " << cb.soHieu << ", Gia ve: " << cb.giaVe << ", So ghe: " << cb.soGhe << endl;
}

void A1(const vector<ChuyenBay>& danhSach, int index) {
    if (index >= danhSach.size()) return;
    
    if (danhSach[index].giaVe > 700000) {
        hienThiChuyenBay(danhSach[index]);
    }
    
    A1(danhSach, index + 1);
}

ChuyenBay A2(const vector<ChuyenBay>& danhSach, int left, int right) {
    if (left == right) return danhSach[left];
    
    int mid = (left + right) / 2;
    ChuyenBay minLeft = A2(danhSach, left, mid);
    ChuyenBay minRight = A2(danhSach, mid + 1, right);
    
    return (minLeft.giaVe < minRight.giaVe) ? minLeft : minRight;
}

void A3(const vector<ChuyenBay>& danhSach, vector<ChuyenBay>& temp, int start, int count) {
    if (count == 4) {
        for (const auto& cb : temp) {
            cout << cb.soHieu << " (" << cb.soGhe << " ghe), ";
        }
        cout << endl;
        return;
    }
    
    for (int i = start; i < danhSach.size(); i++) {
        temp[count] = danhSach[i];
        A3(danhSach, temp, i + 1, count + 1);
    }
}

int main() {
    vector<ChuyenBay> danhSach = {
        {"VN001", 500000, 150},
        {"VN002", 750000, 120},
        {"VN003", 1200000, 180},
        {"VN004", 650000, 160},
        {"VN005", 800000, 200},
        {"VN006", 950000, 170},
        {"VN007", 550000, 140},
        {"VN008", 700000, 130}
    };
    
    cout << "Danh sach chuyen bay:" << endl;
    for (const auto& cb : danhSach) {
        hienThiChuyenBay(cb);
    }
    
    cout << "\nCac chuyen bay co gia ve tren 700000:" << endl;
    A1(danhSach, 0);
    
    ChuyenBay minCB = A2(danhSach, 0, danhSach.size() - 1);
    cout << "\nChuyen bay co gia ve thap nhat:" << endl;
    hienThiChuyenBay(minCB);
    
    cout << "\nCac phuong an chon 4 chuyen bay:" << endl;
    vector<ChuyenBay> temp(4);
    A3(danhSach, temp, 0, 0);
    
    return 0;
}
