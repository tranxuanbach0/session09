#include <stdio.h>

int main() {
    int mang[100];
    int currentLength, xoaViTri;

    printf("Nhap so phan tu ban dau cua mang (toi da 100): ");
    scanf("%d", &currentLength);

    if (currentLength > 100 || currentLength < 0) {
        printf("So phan tu khong hop le.\n");
        return 1;
    }

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("Phan tu thu %d: ", i);
        scanf("%d", &mang[i]);
    }

    printf("Nhap vi tri can xoa (0 den %d): ", currentLength - 1);
    scanf("%d", &xoaViTri);

    if (xoaViTri < 0 || xoaViTri >= currentLength) {
        printf("Vi tri khong hop le.\n");
        return 1;
    }

    for (int i = xoaViTri; i < currentLength - 1; i++) {
        mang[i] = mang[i + 1];
    }

    currentLength--;

    printf("Mang sau khi xoa la:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", mang[i]);
    }
    printf("\n");

    return 0;
}
