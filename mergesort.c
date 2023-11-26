#include <stdio.h>

void merge_sort(int a[], int n);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);

int main() {
    int n,a[100];
    printf("Enter the number of terms in the array:");
    scanf("%d",&n);
    printf("Enter the array:");
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    merge_sort(a,n);
    for(int i=0;i<n;i++) 
        printf("%d ",a[i]);
    printf("\n");
}

void merge_sort(int a[], int n){
    merge_sort_recursion(a, 0, n-1);
}

void merge_sort_recursion(int a[], int l, int r){
    if(l<r) {
        int m = (l+r)/2;

        merge_sort_recursion(a,l,m);
        merge_sort_recursion(a,m+1,r);

        merge_sorted_arrays(a,l,m,r);
    }
}


void merge_sorted_arrays(int a[], int l, int m, int r){
    int left = m - l + 1;
    int right = r - m;

    int temp_left[left];
    int temp_right[right];

    int i,j,k;

    for(i=0;i<left;i++)
        temp_left[i] = a[l+i];
    for(j=0;j<right;j++)
        temp_right[j] = a[m+1+j];

    i=0;
    j=0;
    k=l;
    while(i<left && j<right){
        if(temp_left[i]<=temp_right[j]) {
            a[k] = temp_left[i];
            i++;
        }    
        else {
            a[k] = temp_right[j];
            j++;
        }
        k++;
    }

    while(i<left){
        a[k] = temp_left[i];
        i++;
        k++;
    }

    while(j<right){
        a[k] = temp_right[j];
        j++;
        k++;
    }
}
