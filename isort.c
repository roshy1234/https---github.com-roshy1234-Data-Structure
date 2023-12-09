#include <stdio.h>
void main() {
    int n, a[20], j, k;

    printf("Enter array size : ");
    scanf("%d", &n);
    printf("Enter the array : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i < n; i++) {
        k = a[i];
        j = i-1;
        while(j>=0 && a[j]>=k) {
            a[j+1] = a[j];
            j--;
        }
    a[j+1] = k;
        printf("Iteration %d : ", i);
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        } 
        printf("\n");
    }
    printf("The sorted array is : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    } 
}