#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void nhapMang(int mang[], int *currentLength) {
    printf("Nhap so phan tu cua mang (toi da %d): ", MAX);
    scanf("%d", currentLength);

    if (*currentLength > MAX || *currentLength < 0) {
        printf("So phan tu khong hop le.\n");
        *currentLength = 0;
        return;
    }

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < *currentLength; i++) {
        printf("Phan tu thu %d: ", i);
        scanf("%d", &mang[i]);
    }
}

void hienThiMang(int mang[], int currentLength) {
    if (currentLength == 0) {
        printf("Mang rong.\n");
        return;
    }
    printf("Cac phan tu cua mang: ");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", mang[i]);
    }
    printf("\n");
}

void inChanVaTong(int mang[], int currentLength) {
    int tong = 0;
    printf("Cac phan tu chan trong mang: ");
    for (int i = 0; i < currentLength; i++) {
        if (mang[i] % 2 == 0) {
            printf("%d ", mang[i]);
            tong += mang[i];
        }
    }
    printf("\nTong cac phan tu chan: %d\n", tong);
}

void timMaxMin(int mang[], int currentLength) {
    if (currentLength == 0) {
        printf("Mang rong.\n");
        return;
    }

    int max = mang[0], min = mang[0];
    for (int i = 1; i < currentLength; i++) {
        if (mang[i] > max) max = mang[i];
        if (mang[i] < min) min = mang[i];
    }

    printf("Gia tri lon nhat: %d\n", max);
    printf("Gia tri nho nhat: %d\n", min);
}

void inNguyenToVaTong(int mang[], int currentLength) {
    int tong = 0;
    printf("Cac so nguyen to trong mang: ");
    for (int i = 0; i < currentLength; i++) {
        if (laSoNguyenTo(mang[i])) {
            printf("%d ", mang[i]);
            tong += mang[i];
        }
    }
    printf("\nTong cac so nguyen to: %d\n", tong);
}

void thongKePhanTu(int mang[], int currentLength) {
    int soCanTim, dem = 0;
    printf("Nhap so can thong ke: ");
    scanf("%d", &soCanTim);

    for (int i = 0; i < currentLength; i++) {
        if (mang[i] == soCanTim) {
            dem++;
        }
    }

    printf("So %d xuat hien %d lan trong mang.\n", soCanTim, dem);
}

void themPhanTu(int mang[], int *currentLength) {
    if (*currentLength >= MAX) {
        printf("Mang da day, khong the them phan tu.\n");
        return;
    }

    int addValue, addIndex;
    printf("Nhap gia tri can them: ");
    scanf("%d", &addValue);
    printf("Nhap vi tri can them (0 den %d): ", *currentLength);
    scanf("%d", &addIndex);

    if (addIndex < 0 || addIndex > *currentLength) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    for (int i = *currentLength; i > addIndex; i--) {
        mang[i] = mang[i - 1];
    }
    mang[addIndex] = addValue;
    (*currentLength)++;
    printf("Them phan tu thanh cong.\n");
}

int main() {
    int mang[MAX];
    int currentLength = 0;
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. In ra gia tri cac phan tu chan va tinh tong\n");
        printf("4. In ra gia tri lon nhat va nho nhat trong mang\n");
        printf("5. In ra cac phan tu la so nguyen to trong mang va tinh tong\n");
        printf("6. Nhap vao mot so va thong ke trong mang co bao nhieu phan tu do\n");
        printf("7. Them mot phan tu vao vi tri chi dinh\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapMang(mang, &currentLength);
                break;
            case 2:
                hienThiMang(mang, currentLength);
                break;
            case 3:
                inChanVaTong(mang, currentLength);
                break;
            case 4:
                timMaxMin(mang, currentLength);
                break;
            case 5:
                inNguyenToVaTong(mang, currentLength);
                break;
            case 6:
                thongKePhanTu(mang, currentLength);
                break;
            case 7:
                themPhanTu(mang, &currentLength);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 8);

    return 0;
}
