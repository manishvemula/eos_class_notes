#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define SIZE 10
#define SWAP(a, b) { int temp = a; a = b; b = temp; }

void *selectionsort(void *param) {
    int *arr = (int *)param;
    for (int i = 0; i < SIZE - 1; i++) {
        int min = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        SWAP(arr[i], arr[min]);
    }
    return NULL;
}

int main() {
    pthread_t t;
    int ret;
    int arr[SIZE] = {64, 25, 12, 22, 11, 90, 45, 33, 2, 8};
    
    ret = pthread_create(&t, NULL, selectionsort, arr);
    if (ret != 0) {
        perror("Thread creation failed");
        return 1;
    }
    
    pthread_join(t, NULL);
    
    printf("Sorted array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
