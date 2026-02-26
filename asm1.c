/******************************************************************************
 * Họ và tên: [ngô thanh nhân]
 * MSSV:      [ps49576]
 * Lớp:       [com108]
 *****************************************************************************/

// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c


// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
// ====== Khai báo hàm ======
void kiemTraSoNguyen();
void uocVaBoi();
void tinhTienQuanKaraoke();
void tinhTienDien();
void doiTien();
void tinhLaiSuat();
void vayTienMuaXe();
void sapXepSinhVien();
void gameFPolyLott();
void tinhToanTongHop();

// ====== MAIN ======
int main() {
    int choice;

    do {
        printf("\n=========== MENU ASM1 ===========\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim UCLN va BCNN\n");
        printf("3. Tinh tien karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Doi tien\n");
        printf("6. Tinh lai suat vay\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep sinh vien\n");
        printf("9. Game FPoly-Lott\n");
        printf("10. Chuong trinh tinh toan\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: kiemTraSoNguyen(); break;
            case 2: uocVaBoi(); break;
            case 3: tinhTienQuanKaraoke(); break;
            case 4: tinhTienDien(); break;
            case 5: doiTien(); break;
            case 6: tinhLaiSuat(); break;
            case 7: vayTienMuaXe(); break;
            case 8: sapXepSinhVien(); break;
            case 9: gameFPolyLott(); break;
            case 10: tinhToanTongHop(); break;
            case 0: printf("Thoat chuong trinh!\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);

    return 0;
}

// ====== CHỨC NĂNG ======

void kiemTraSoNguyen() {
    float x;
    printf("Nhap so: ");
    scanf("%f", &x);
    if (x == (int)x)
        printf("Day la so nguyen\n");
    else
        printf("Day khong phai so nguyen\n");
}

void uocVaBoi() {
    int a, b, ucln, bcnn;
    printf("Nhap a, b: ");
    scanf("%d%d", &a, &b);
    int x = a, y = b;
    while (x != y) {
        if (x > y) x -= y;
        else y -= x;
    }
    ucln = x;
    bcnn = (a * b) / ucln;
    printf("UCLN = %d\nBCNN = %d\n", ucln, bcnn);
}

void tinhTienQuanKaraoke() {
    int gio;
    printf("Nhap so gio hat: ");
    scanf("%d", &gio);
    int tien = (gio <= 3) ? gio * 150000 :
               3 * 150000 + (gio - 3) * 120000;
    printf("Tien karaoke: %d VND\n", tien);
}

void tinhTienDien() {
    int kWh;
    printf("Nhap so dien tieu thu: ");
    scanf("%d", &kWh);
    int tien = kWh * 3500;
    printf("Tien dien: %d VND\n", tien);
}

void doiTien() {
    int tien;
    printf("Nhap so tien can doi: ");
    scanf("%d", &tien);
    int menhGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    for (int i = 0; i < 9; i++) {
        printf("%d VND: %d to\n", menhGia[i], tien / menhGia[i]);
        tien %= menhGia[i];
    }
}

void tinhLaiSuat() {
    float tien, lai;
    printf("Nhap so tien vay: ");
    scanf("%f", &tien);
    lai = tien * 0.05 * 12;
    printf("Tien lai sau 12 thang: %.2f\n", lai);
}

void vayTienMuaXe() {
    float giaXe;
    printf("Nhap gia xe: ");
    scanf("%f", &giaXe);
    printf("Tra truoc 30%%: %.2f\n", giaXe * 0.3);
    printf("Vay 70%%: %.2f\n", giaXe * 0.7);
}

void sapXepSinhVien() {
    int n;
    printf("Nhap so sinh vien: ");
    scanf("%d", &n);
    float diem[n];
    for (int i = 0; i < n; i++) {
        printf("Diem SV %d: ", i + 1);
        scanf("%f", &diem[i]);
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (diem[i] > diem[j]) {
                float t = diem[i];
                diem[i] = diem[j];
                diem[j] = t;
            }
    printf("Danh sach diem tang dan:\n");
    for (int i = 0; i < n; i++)
        printf("%.2f ", diem[i]);
    printf("\n");
}

void gameFPolyLott() {
    int so;
    printf("Nhap so du doan (0-9): ");
    scanf("%d", &so);
    if (so == 5)
        printf("Chuc mung ban trung thuong!\n");
    else
        printf("Chuc ban may man lan sau!\n");
}

void tinhToanTongHop() {
    float a, b;
    printf("Nhap a, b: ");
    scanf("%f%f", &a, &b);
    printf("Tong: %.2f\n", a + b);
    printf("Hieu: %.2f\n", a - b);
    printf("Tich: %.2f\n", a * b);
    if (b != 0)
        printf("Thuong: %.2f\n", a / b);
    else
        printf("Khong chia duoc cho 0\n");
}

