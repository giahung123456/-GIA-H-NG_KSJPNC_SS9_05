#include <stdio.h>

int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int arr[100], n, choice, value, pos, sum, min, max, primeSum, count, primeCount;

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
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so phan tu can nhap: ");
                scanf("%d", &n);
                if (n > 100) {
                    printf("So phan tu vuot qua gioi han 100!\n");
                    break;
                }
                for (int i = 0; i < n; i++) {
                    printf("Nhap gia tri phan tu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                printf("Gia tri cac phan tu dang quan ly: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 3:
                sum = 0;
                printf("Cac phan tu chan trong mang: ");
                for (int i = 0; i < n; i++) {
                    if (arr[i] % 2 == 0) {
                        printf("%d ", arr[i]);
                        sum += arr[i];
                    }
                }
                printf("\nTong cac phan tu chan: %d\n", sum);
                break;

            case 4:
                if (n == 0) {
                    printf("Mang rong!\n");
                    break;
                }
                min = max = arr[0];
                for (int i = 1; i < n; i++) {
                    if (arr[i] > max) max = arr[i];
                    if (arr[i] < min) min = arr[i];
                }
                printf("Gia tri lon nhat trong mang: %d\n", max);
                printf("Gia tri nho nhat trong mang: %d\n", min);
                break;

            case 5:
                primeSum = 0;
                primeCount = 0;
                printf("Cac phan tu la so nguyen to trong mang: ");
                for (int i = 0; i < n; i++) {
                    if (isPrime(arr[i])) {
                        printf("%d ", arr[i]);
                        primeSum += arr[i];
                        primeCount++;
                    }
                }
                printf("\nTong cac so nguyen to: %d\n", primeSum);
                printf("So luong so nguyen to: %d\n", primeCount);
                break;

            case 6:
                printf("Nhap vao mot so can thong ke: ");
                scanf("%d", &value);
                count = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        count++;
                    }
                }
                printf("So phan tu co gia tri %d trong mang: %d\n", value, count);
                break;

            case 7:
                if (n >= 100) {
                    printf("Mang da day, khong the them phan tu!\n");
                    break;
                }
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                printf("Nhap vi tri can them (0 den %d): ", n);
                scanf("%d", &pos);
                if (pos < 0 || pos > n) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }
                for (int i = n; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = value;
                n++;
                break;

            case 8:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long chon lai.\n");
        }
    } while (choice != 8);

    return 0;
}