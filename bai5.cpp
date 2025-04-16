#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct CongViec {
    string maCV;
    string thoiGianBatDau;
    double thoiGianThucHien; 
};

void hienThiCongViec(const CongViec& cv) {
    cout << "Ma CV: " << cv.maCV << ", Bat dau: " << cv.thoiGianBatDau 
         << ", Thoi gian: " << cv.thoiGianThucHien << " phut" << endl;
}

void A1(const vector<CongViec>& danhSach, int index) {
    if (index < 0) return;
    
    hienThiCongViec(danhSach[index]);
    A1(danhSach, index - 1);
}

int A2(const vector<CongViec>& danhSach, int left, int right) {
    if (left == right) {
        return (danhSach[left].thoiGianThucHien <= 30) ? 1 : 0;
    }
    
    int mid = (left + right) / 2;
    int countLeft = A2(danhSach, left, mid);
    int countRight = A2(danhSach, mid + 1, right);
    
    return countLeft + countRight;
}

void A3(const vector<CongViec>& congViec, const vector<string>& nhanVien, 
        vector<bool>& daGiao, vector<string>& phanCong, int index) {
    if (index == congViec.size()) {
        for (int i = 0; i < congViec.size(); i++) {
            cout << congViec[i].maCV << " - " << phanCong[i] << endl;
        }
        cout << "------------------------" << endl;
        return;
    }
    
    for (int i = 0; i < nhanVien.size(); i++) {
        if (!daGiao[i]) {
            daGiao[i] = true;
            phanCong[index] = nhanVien[i];
            A3(congViec, nhanVien, daGiao, phanCong, index + 1);
            daGiao[i] = false;
        }
    }
}

int main() {
    vector<CongViec> danhSachCV = {
        {"CV001", "08:00", 45},
        {"CV002", "09:30", 20},
        {"CV003", "10:15", 60},
        {"CV004", "13:00", 15},
        {"CV005", "14:30", 30},
        {"CV006", "15:45", 25}
    };
    
    vector<string> danhSachNV = {
        "Nguyen Van A", "Tran Thi B", "Le Van C",
        "Pham Thi D", "Hoang Van E", "Vu Thi F"
    };
    
    cout << "Danh sach cong viec ban dau:" << endl;
    for (const auto& cv : danhSachCV) {
        hienThiCongViec(cv);
    }
    
    cout << "\nDanh sach cong viec theo thu tu nguoc:" << endl;
    A1(danhSachCV, danhSachCV.size() - 1);

    int count = A2(danhSachCV, 0, danhSachCV.size() - 1);
    cout << "\nSo cong viec co thoi gian thuc hien <= 30 phut: " << count << endl;
    
    cout << "\nCac phuong an phan cong cong viec cho nhan vien:" << endl;
    vector<bool> daGiao(danhSachNV.size(), false);
    vector<string> phanCong(danhSachCV.size());
    A3(danhSachCV, danhSachNV, daGiao, phanCong, 0);
    
    return 0;
}
