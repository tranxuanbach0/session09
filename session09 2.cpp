#include <stdio.h>

int main() {
    int mang[5] = {10, 20, 30, 40, 50};
    int viTri, giaTriMoi;
    int soPhanTu = 5;

    printf("Mang ban dau:\n");
    for (int i = 0; i < soPhanTu; i++) {
        printf("%d ", mang[i]);
    }
    printf("\n");

    printf("Nhap vi tri can sua (0 den %d): ", soPhanTu - 1);
    scanf("%d", &viTri);

    if (viTri < 0 || viTri >= soPhanTu) {
        printf("Vi tri khong hop le.\n");
        return 1;
    }

    printf("Nhap gia tri moi: ");
    scanf("%d", &giaTriMoi);

    mang[viTri] = giaTriMoi;

    printf("Mang sau khi sua:\n");
    for (int i = 0; i < soPhanTu; i++) {
        printf("%d ", mang[i]);
    }
    printf("\n");

    return 0;
}
