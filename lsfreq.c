#include <stdio.h>

int main() {
    int n, k, f, freq = 0;
    printf("Enter the array size: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter search key: ");
    scanf("%d", &k);
    
    // Calculate frequency
    for (int j = 0; j < n; j++) {
        if (a[j] == k) {
            freq++;
        }
    }
    
    if (freq > 0) {
        printf("Frequency of the element is %d", freq);
        }
    else {
        printf("%d is not found in the array.", k);
        }
            
    return 0;
}