#include <stdio.h>

#define MAX 100

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

    printf("Cac phan tu cua mang la:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", mang[i]);
    }
    printf("\n");
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

void suaPhanTu(int mang[], int currentLength) {
    if (currentLength == 0) {
        printf("Mang rong, khong co gi de sua.\n");
        return;
    }

    int viTri, giaTriMoi;
    printf("Nhap vi tri can sua (0 den %d): ", currentLength - 1);
    scanf("%d", &viTri);

    if (viTri < 0 || viTri >= currentLength) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    printf("Nhap gia tri moi: ");
    scanf("%d", &giaTriMoi);

    mang[viTri] = giaTriMoi;
    printf("Sua phan tu thanh cong.\n");
}

void xoaPhanTu(int mang[], int *currentLength) {
    if (*currentLength == 0) {
        printf("Mang rong, khong co gi de xoa.\n");
        return;
    }

    int xoaViTri;
    printf("Nhap vi tri can xoa (0 den %d): ", *currentLength - 1);
    scanf("%d", &xoaViTri);

    if (xoaViTri < 0 || xoaViTri >= *currentLength) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    for (int i = xoaViTri; i < *currentLength - 1; i++) {
        mang[i] = mang[i + 1];
    }
    (*currentLength)--;
    printf("Xoa phan tu thanh cong.\n");
}

int main() {
    int mang[MAX];
    int currentLength = 0;
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao mang\n");
        printf("2. Hien thi mang\n");
        printf("3. Them phan tu\n");
        printf("4. Sua phan tu\n");
        printf("5. Xoa phan tu\n");
        printf("6. Thoat\n");
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
                themPhanTu(mang, &currentLength);
                break;
            case 4:
                suaPhanTu(mang, currentLength);
                break;
            case 5:
                xoaPhanTu(mang, &currentLength);
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 6);

    return 0;
}
