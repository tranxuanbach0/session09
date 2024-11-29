#include <stdio.h>

int main() {
    int mang[100];
    int currentLength, addValue, addIndex;

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

    printf("Nhap gia tri can them: ");
    scanf("%d", &addValue);

    printf("Nhap vi tri can them: ");
    scanf("%d", &addIndex);

    if (addIndex < 0 || addIndex > 100) {
        printf("Vi tri khong hop le.\n");
        return 1;
    }

    if (addIndex >= currentLength) {
        mang[addIndex] = addValue;
        currentLength = addIndex + 1;
    } else {
        for (int i = currentLength; i > addIndex; i--) {
            mang[i] = mang[i - 1];
        }
        mang[addIndex] = addValue;
        currentLength++;
    }

    printf("Mang sau khi them moi la:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", mang[i]);
    }
    printf("\n");

    return 0;
}
