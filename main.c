#include <stdio.h>
#include <stdlib.h>

void show_data(int *src, int count)
{
    for(int i = 0; i < count; i++)
    {
        if(i != 0) printf(" ");
        printf("%d", src[i]);
    }
    printf("\n");
}

void quick_sort(int *src, int count, int left, int right)
{
    if(right <= left) return;
    
    int pivot = src[left];
    int idx_l = left + 1;
    int idx_r = right;
    
    while(1){
        while(src[idx_l] <= pivot&& idx_l < right){idx_l++;}
        while(pivot <= src[idx_r] && left < idx_r){idx_r--;}
        if(idx_l < idx_r){
            int tmp = src[idx_l];
            src[idx_l] = src[idx_r];
            src[idx_r] = tmp;
            show_data(src, count);
            
            idx_l++;
            idx_r--;
        }else{
            break;
        }
    }
    if(left != idx_r){
        src[left] = src[idx_r];
        src[idx_r] = pivot;
        show_data(src, count);
    }
    quick_sort(src, count, left, idx_r-1);
    quick_sort(src, count, idx_r+1, right);
}

int main(int argc, char *argv[]) 
{
    char str[7];
    int src[100];
    int count = 0;
    
    // データの読み込み
    while(fgets(str, sizeof(str), stdin)){
        src[count++] = atoi(str);
    }
    
    // 入力データの表示
    show_data(src, count);

    // 整列
    quick_sort(src, count, 0, count-1);
    
    return 0;
}
