#include<stdio.h>

int main(){
    int arr[100][100], row, cols, number;
    do{
        printf("\n\nMENU\n");
        printf("1.Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2.In gia tri cac phan tu mang theo ma tran\n");
        printf("3.In ra cac phan tu nam tren duong bien va tinh tich\n");
        printf("4.In ra cac pha tu nam tren duong cheo chinh\n");
        printf("5.In ra cac phan tu nam tren duong cheo phu\n");
        printf("6.Sap xep duong cheo chinh theo thu tu tang dan\n");
        printf("7.Tim kiem mot phan tu va in ra vi tri phan tu do trong mang\n");
        printf("8.Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &number);
        int product = 1;
        int arr2[100];
        switch(number){
            case 1:
                printf("Nhap so hang va so cot cho mang: ");
                scanf("%d %d", &row, &cols);
                printf("Nhap gia tri cho cac phan tu:\n");
                for(int i = 0; i < row; i++){
                    for(int j = 0; j < cols; j++){
                        scanf("%d", &arr[i][j]);
                    }
                }
                break;
            case 2:
                printf("Mang ban vua nhap vao la:\n");
                for(int i = 0; i < row; i++){
                    for(int j = 0; j < cols; j++){
                        printf("%d ", arr[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                printf("Cac phan tu nam tren duong bien:\n");
                for(int i = 0; i < row; i++){
                    for(int j = 0; j < cols; j++){
                        if(i == 0 || i == row - 1 || j == 0 || j == cols - 1){
                            printf("%d ", arr[i][j]);
                            product *= arr[i][j];
                        }else{
                            printf("  ");
                        }
                    }
                    printf("\n");
                }
                printf("\nTich cac phan tu duong bien la: %d", product);
                break;
            case 4:
                if(row != cols){
                    printf("Mang khong co duong cheo chinh");
                }else{
                    printf("Duong cheo chinh trong mang la:\n");
                    for(int i = 0; i < row; i++){
                        for(int j = 0; j < cols; j++){
                            if(i == j){
                                printf("%d ", arr[i][j]);
                            }else{
                                printf("  ");
                            }
                        }
                        printf("\n");
                    }
                }
                break;
            case 5:
                if(row != cols){
                    printf("Mang khong co duong cheo");
                }else{
                    printf("Duong cheo phu trong mang la:\n");
                    for(int i = 0; i < row; i++){
                        for(int j = 0; j < cols; j++){
                            if(j + i == cols - 1){
                                printf("%d ", arr[i][j]);
                            }else{
                                printf("  ");
                            }
                        }
                        printf("\n");
                    }
                }
                break;
            case 6:
                for(int i = 0; i < row; i++){
                    arr2[i] = arr[i][i];
                }
                for(int i = 0; i < row; i++){
                    for(int j = 0; j < row - 1- i; j++){
                        if(arr2[j] > arr2[j+1]){
                            int temp = arr2[j+1];
                            arr2[j+1] = arr2[j];
                            arr2[j] = temp;
                        }
                    }
                }
                printf("Duong cheo chinh sau khi duoc sap xep la:\n");
                for(int i = 0; i < row; i++){
                    printf("%d ", arr2[i]);
                }
                break;
            case 7:
                int searchNumber;
                int flag1 = -1, flag2 = -1;
                printf("Nhap so ban muon tim kiem: ");
                scanf("%d", &searchNumber);
                for(int i = 0; i < row; i++){
                    for(int j = 0; j < cols; j++){
                        if(searchNumber == arr[i][j]){
                            flag1 = i + 1;
                            flag2 = j + 1;
                            break;
                        }
                    }
                }
                if(flag1 == -1){
                    printf("Phan tu khong ton tai trong mang");
                }else{
                    printf("Phan tu ton tai trong mang o vi tri: arr[%d][%d]", flag1, flag2);
                }
                break;
            case 8:
                break;
            default:
                printf("Phan tu khong ton tai trong mang");
        }
    }while(number != 8);
    return 0;
}
