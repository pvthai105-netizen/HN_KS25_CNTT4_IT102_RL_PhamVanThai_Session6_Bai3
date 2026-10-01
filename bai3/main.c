
#include <stdio.h>
#include <string.h>

#define MAX 100

int main(void) {
    // B1: Khai bao cac mang va bien can thiet
    char maPhieu[MAX][20];
    char maSach[MAX][20];

    int soNgayMuon[MAX];
    int soLuong = 0;

    int choice;
    int i;
    int pos;
    int ngayMoi;
    int ngayQuaHan;
    int tienPhat;

    char maNhap[20];

    // B2: Xay dung menu
    do {
        printf("\n================ HE THONG QUAN LY MUON TRA SACH (LOGISTICS) ================\n");
        printf("1. Them moi phieu muon sach (Create)\n");
        printf("2. Hien thi danh sach phieu muon & Tien phat qua han (Read)\n");
        printf("3. Cap nhat so ngay muon sach (Update)\n");
        printf("4. Xac nhan tra sach / Xoa phieu muon (Delete)\n");
        printf("5. Thoat chuong trinh\n");
        printf("===========================================================================\n");
        printf("Lua chon cua ban (1-5): ");

        scanf("%d", &choice);

        // Lam sach bo dem ban phim
        while (getchar() != '\n');

        switch (choice) {

            // ==================================================
            // CASE 1: THEM MOI PHIEU MUON
            // ==================================================
            case 1:
                printf("\n--- THEM MOI PHIEU MUON ---\n");

                if (soLuong >= MAX) {
                    printf("Bo nho danh sach da day, khong the them moi!\n");
                    break;
                }

                printf("Nhap ma phieu: ");
                scanf("%19s", maNhap);

                while (getchar() != '\n');

                // Kiem tra ma phieu trung lap
                pos = -1;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos != -1) {
                    printf("Ma phieu da ton tai trong he thong!\n");
                    break;
                }

                // Luu ma phieu
                strcpy(maPhieu[soLuong], maNhap);

                // Nhap ma sach
                printf("Nhap ma sach: ");
                scanf("%19s", maSach[soLuong]);

                while (getchar() != '\n');

                // Nhap so ngay muon
                printf("Nhap so ngay muon: ");
                scanf("%d", &soNgayMuon[soLuong]);

                while (getchar() != '\n');

                while (soNgayMuon[soLuong] <= 0) {
                    printf("So ngay muon phai lon hon 0! Vui long nhap lai: ");
                    scanf("%d", &soNgayMuon[soLuong]);

                    while (getchar() != '\n');
                }

                soLuong++;

                printf("Them moi phieu muon thanh cong!\n");
                break;

            // ==================================================
            // CASE 2: HIEN THI DANH SACH VA TINH TIEN PHAT
            // ==================================================
            case 2:
                printf("\n================ DANH SACH PHIEU MUON =================\n");

                if (soLuong == 0) {
                    printf("Danh sach phieu muon hien dang rong!\n");
                    break;
                }

                printf("%-5s | %-12s | %-12s | %-12s | %-15s | %-15s\n",
                       "STT",
                       "Ma Phieu",
                       "Ma Sach",
                       "So Ngay Muon",
                       "Trang Thai",
                       "Tien Phat (VND)");

                printf("---------------------------------------------------------------------------------------------\n");

                for (i = 0; i < soLuong; i++) {

                    if (soNgayMuon[i] > 14) {
                        ngayQuaHan = soNgayMuon[i] - 14;
                        tienPhat = ngayQuaHan * 5000;

                        printf("%-5d | %-12s | %-12s | %-12d | %-15s | %-15d\n",
                               i + 1,
                               maPhieu[i],
                               maSach[i],
                               soNgayMuon[i],
                               "QUA HAN",
                               tienPhat);
                    } else {
                        tienPhat = 0;

                        printf("%-5d | %-12s | %-12s | %-12d | %-15s | %-15d\n",
                               i + 1,
                               maPhieu[i],
                               maSach[i],
                               soNgayMuon[i],
                               "DUNG HAN",
                               tienPhat);
                    }
                }

                printf("---------------------------------------------------------------------------------------------\n");
                printf("Tong so phieu muon: %d\n", soLuong);
                break;

            // ==================================================
            // CASE 3: CAP NHAT SO NGAY MUON
            // ==================================================
            case 3:
                printf("\n--- CAP NHAT SO NGAY MUON ---\n");

                printf("Nhap ma phieu can cap nhat: ");
                scanf("%19s", maNhap);

                while (getchar() != '\n');

                // Tim kiem ma phieu
                pos = -1;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1) {
                    printf("Khong tim thay ma phieu trong he thong!\n");
                    break;
                }

                printf("So ngay muon hien tai cua phieu %s la: %d\n",
                       maPhieu[pos], soNgayMuon[pos]);

                printf("Nhap so ngay muon moi: ");
                scanf("%d", &ngayMoi);

                while (getchar() != '\n');

                while (ngayMoi <= 0) {
                    printf("So ngay muon phai lon hon 0! Vui long nhap lai: ");
                    scanf("%d", &ngayMoi);

                    while (getchar() != '\n');
                }

                soNgayMuon[pos] = ngayMoi;

                printf("Cap nhat so ngay muon thanh cong!\n");
                break;

            // ==================================================
            // CASE 4: XAC NHAN TRA SACH / XOA PHIEU MUON
            // ==================================================
            case 4:
                printf("\n--- XAC NHAN TRA SACH / XOA PHIEU MUON ---\n");

                printf("Nhap ma phieu xac nhan tra/xoa: ");
                scanf("%19s", maNhap);

                while (getchar() != '\n');

                // Tim vi tri can xoa
                pos = -1;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1) {
                    printf("Khong tim thay ma phieu can xoa!\n");
                    break;
                }

                // Don cac phan tu phia sau len truoc
                for (i = pos; i < soLuong - 1; i++) {
                    strcpy(maPhieu[i], maPhieu[i + 1]);
                    strcpy(maSach[i], maSach[i + 1]);
                    soNgayMuon[i] = soNgayMuon[i + 1];
                }

                soLuong--;

                printf("Xac nhan tra sach va xoa phieu muon thanh cong!\n");
                break;

            // ==================================================
            // CASE 5: THOAT CHUONG TRINH
            // ==================================================
            case 5:
                printf("Cam on ban da su dung he thong LIBRARY_WMS!\n");
                break;

            // ==================================================
            // MAC DINH: LUA CHON KHONG HOP LE
            // ==================================================
            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
                break;
        }

    } while (choice != 5);

    return 0;
}