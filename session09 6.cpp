#include <stdio.h>

#define MAX 100

void nhapMaTran(int mat[MAX][MAX], int *n, int *m) {
    printf("Nhap kich co ma tran (hang cot): ");
    scanf("%d %d", n, m);

    if (*n <= 0 || *m <= 0 || *n > MAX || *m > MAX) {
        printf("Kich co khong hop le.\n");
        *n = 0;
        *m = 0;
        return;
    }

    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            printf("Phan tu [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void hienThiMaTran(int mat[MAX][MAX], int n, int m) {
    if (n == 0 || m == 0) {
        printf("Ma tran rong.\n");
        return;
    }

    printf("Ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
}

void inLeVaTinhTong(int mat[MAX][MAX], int n, int m) {
    int tong = 0;
    printf("Cac phan tu le trong ma tran: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] % 2 != 0) {
                printf("%d ", mat[i][j]);
                tong += mat[i][j];
            }
        }
    }
    printf("\nTong cac phan tu le: %d\n", tong);
}

void inDuongBienVaTinhTich(int mat[MAX][MAX], int n, int m) {
    int tich = 1;
    printf("Cac phan tu tren duong bien: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                printf("%d ", mat[i][j]);
                tich *= mat[i][j];
            }
        }
    }
    printf("\nTich cac phan tu tren duong bien: %d\n", tich);
}

void inDuongCheoChinh(int mat[MAX][MAX], int n, int m) {
    if (n != m) {
        printf("Khong co duong cheo chinh vi ma tran khong vuong.\n");
        return;
    }

    printf("Cac phan tu tren duong cheo chinh: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", mat[i][i]);
    }
    printf("\n");
}

void inDuongCheoPhu(int mat[MAX][MAX], int n, int m) {
    if (n != m) {
        printf("Khong co duong cheo phu vi ma tran khong vuong.\n");
        return;
    }

    printf("Cac phan tu tren duong cheo phu: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", mat[i][n - i - 1]);
    }
    printf("\n");
}

void inDongTongLonNhat(int mat[MAX][MAX], int n, int m) {
    int maxTong = 0, dongMax = 0;

    for (int i = 0; i < n; i++) {
        int tongDong = 0;
        for (int j = 0; j < m; j++) {
            tongDong += mat[i][j];
        }
        if (i == 0 || tongDong > maxTong) {
            maxTong = tongDong;
            dongMax = i;
        }
    }

    printf("Dong co tong lon nhat (dong %d): ", dongMax);
    for (int j = 0; j < m; j++) {
        printf("%d ", mat[dongMax][j]);
    }
    printf("\nTong gia tri dong: %d\n", maxTong);
}

int main() {
    int mat[MAX][MAX];
    int n = 0, m = 0;
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In gia tri cac phan tu le va tinh tong\n");
        printf("4. In ra cac phan tu nam tren duong bien va tinh tich\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh\n");
        printf("6. In ra cac phan tu nam tren duong cheo phu\n");
        printf("7. In ra dong co tong gia tri cac phan tu lon nhat\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapMaTran(mat, &n, &m);
                break;
            case 2:
                hienThiMaTran(mat, n, m);
                break;
            case 3:
                inLeVaTinhTong(mat, n, m);
                break;
            case 4:
                inDuongBienVaTinhTich(mat, n, m);
                break;
            case 5:
                inDuongCheoChinh(mat, n, m);
                break;
            case 6:
                inDuongCheoPhu(mat, n, m);
                break;
            case 7:
                inDongTongLonNhat(mat, n, m);
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

