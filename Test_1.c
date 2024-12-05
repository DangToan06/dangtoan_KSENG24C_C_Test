#include<stdio.h>
#include<limits.h>
#include<math.h>

int main(){
    int number, arr[100], n = 0;

    do{
        printf("\n\nMENU\n");
        printf("1.Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2.In gia tri cac phan tu dang quan ly\n");
        printf("3.In ra gia tri lon nhat cua mang\n");
        printf("4.In ra cac phan tu la so nguyen to trong mang\n");
        printf("5.Them 1 phan tu vao trong mang\n");        
        printf("6.Xoa mot phan tu trong mang\n");
        printf("7.Sap xep mang theo thu tu tang dan\n");
        printf("8.Tim kiem phan tu(nguou dung nhap) va in ra index cua phan tu do\n");
        printf("9.Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &number);
        int max = INT_MIN;
        int check = 0, addNumber, position, searchNumber;
        switch(number){
            case 1: // Nhap so phan tu can nhap va in ra gia tri cac phan tu
                printf("Nhap do dai cho mang: ");
                scanf("%d", &n);
                while(n <= 0){
                    printf("Chieu dai mang khong ddc nho hon or bang 0\nNhap lai: ");
                    scanf("%d", &n);
                }
                printf("Nhap gia tri cho cac phan tu:\n");
                for(int i = 0; i < n; i++){
                    scanf("%d", &arr[i]);
                }
                break;
            case 2: // In gia tri cac phan tu dang quan ly
                if(n == 0){
                    printf("Ban chu nhap gia tr nao cho mang");
                }else{
                    printf("Mang ban vua nhap vao la:\n");
                    for(int i = 0; i < n; i++){
                        printf("%d ", arr[i]);
                    }
                }
                break;
            case 3: // In ra gia tri lon nhat cua mang
                if(n == 0){
                    printf("Ban chua nhap gia tri nao cho mang");
                }else{
                    for(int i = 0; i < n; i++){
                        if(arr[i] > max){
                            max = arr[i];
                        }
                    }
                    printf("Gia tri lon nhat trong mang la: %d", max);
                }
                break;
            case 4: // In ra cac phan tu la so nguyen to trong mang
                for(int i = 0; i < n; i++){
                    check = 1;
                    if(arr[i] <= 1){
                        check = 0;
                    }
                    for(int j = 2; j <= sqrt(arr[i]); j++){
                        if(arr[i] % j == 0){
                            check = 0;
                        }
                    }
                    if(check == 1){
                        printf("%d ", arr[i]);
                    }
                }
                break;
            case 5: //Them 1 phan tu vao trong mang
                if(n == 0){
                    printf("Ban chua nhap gia tri nao cho mang");
                }else{
                    printf("Nhap gia tri ban muon them: ");
                    scanf("%d", &addNumber);
                    printf("Nhap vi tri ban muon them: ");
                    scanf("%d", &position);
                    while(position <= 0 || position > n){
                        printf("Vi tri ban nhap phai nam trong mang\nVui long nhap lai: ");
                        scanf("%d", &position);
                    }
                    n = n + 1;
                    for(int i = n; i >= position; i--){
                        arr[i] = arr[i - 1];
                    }

                    printf("Mang sau khi duoc sap xep lai la:\n");
                    for(int i = 0; i < n; i++){
                        if(position - 1 == i){
                            arr[i] = addNumber;
                        }
                        printf("%d ", arr[i]);
                    }
                }
                break;
            case 6: // Xoa mot phan tu trong mang
                if(n == 0){
                    printf("Ban chua nhap gia tri nao cho mang");
                }else{
                    printf("Nhap vi tri ban muon xoa: ");
                    scanf("%d", &position);
                    while(position <= 0 || position > n){
                        printf("Vi tri ban nhap phai nam trong mang\nVui long nhap lai: ");
                        scanf("%d", &position);
                    }
                    n = n - 1;
                    for(int i = position - 1; i < n; i++){
                        arr[i] = arr[i + 1];
                    }

                    printf("Mang sau khi duoc xoa la:\n");
                    for(int i = 0; i < n; i++){
                        printf("%d ", arr[i]);
                    }
                }
                break;
            case 7: // Sap xep mang theo thu tu tang dan
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n - 1 - i; j++){
                        if(arr[j] > arr[j+1]){
                            int temp = arr[j+1];
                            arr[j+1] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }

                printf("Mang sau khi duoc xap xep la:\n");
                for(int i = 0; i < n; i++){
                    printf("%d ", arr[i]);
                }
                break;
            case 8: // Tim kiem phan tu(nguou dung nhap) va in ra index cua phan tu do
                if(n == 0){
                    printf("Ban chua nhap gia tri nao cho mang");
                }else{
                    printf("Nhap vao gia tri ban muon tim: ");
                    scanf("%d", &searchNumber);
                    int start = 0;
                    int end = n;
                    int mid;
                    while(start <= end){
                        mid = (start + end)/2;
                        if(searchNumber == arr[mid]){
                            printf("So ban can tim nam o vi tri: %d", mid + 1);
                            check = 1;
                            break;
                        }else if(searchNumber < arr[mid]){
                            end = mid - 1;
                        }else if(searchNumber > arr[mid]){
                            start = mid + 1;
                        }
                    }
                    if(check == 0){
                        printf("Phan tu ban can tim khong co trong mang");
                    }
                }
                break;
            case 9:
                break;
            default:
                printf("Gia tri nhap khong ton tai trong MENU");
        }
    }while(number != 9);
    
    return 0;
}

