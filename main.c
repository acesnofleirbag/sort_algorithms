#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 8

/* #define merge_sort(int arr[SIZE], ...) merge_sort(arr[SIZE], (0, NULL, ##__VA_ARGS__)) */

void show(int *arr, bool mark);
void selection_sort(int *arr);
void bubble_sort(int *arr);
void insertion_sort(int *arr);
void merge_sort(int *arr, int start, int end);
void merge(int *arr, int start, int mid, int end);
void quick_sort(int *arr, int start, int end);
int partition(int *arr, int start, int end);

int main() {
    int nbrs[SIZE] = { 99, 4, 29, 7, 0, 45, 1, 77 };

    show(nbrs, false);

    /* selection_sort(nbrs); */
    /* bubble_sort(nbrs); */
    /* insertion_sort(nbrs); */
    /* merge_sort(nbrs, 0, -1); */
    /* quick_sort(nbrs, 0, -1); */

    show(nbrs, false);

    return 0;
}

void show(int *arr, bool mark) {
    if (mark) printf("[+] ");

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void selection_sort(int *arr) {
    for (int pos = 0; pos < SIZE - 1; pos++) {
        int min = pos;

        for (int i = pos; i < SIZE; i++) {
            if (arr[i] < arr[min]) min = i;
            /* show(arr, true); */
        }

        if (arr[pos] > arr[min]) {
            int tmp = arr[pos];
            arr[pos] = arr[min];
            arr[min] = tmp;
        }
    }
}

void bubble_sort(int *arr) {
    for (int x = 0; x < SIZE - 1; x++) {
        for (int y = 0; y < SIZE - 1; y++) {
            if (arr[y] > arr[y + 1]) {
                int aux = arr[y + 1];
                arr[y + 1] = arr[y];
                arr[y] = aux;
            }

            /* show(arr, true); */
        }
    }
}

void insertion_sort(int *arr) {
    for (int i = 1; i < SIZE; i++) {
        int cur = arr[i], aux = i - 1;

        while (aux >= 0 && arr[aux] > cur) {
            arr[aux + 1] = arr[aux];
            aux--;
            /* show(arr, true); */
        };

        arr[aux + 1] = cur;
    }
}

void merge_sort(int *arr, int start, int end) {
    if (end == -1) end = SIZE;

    if (end - start > 1) {
        int mid = (end + start) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid, end);
        merge(arr, start, mid, end);
    }
}

void merge(int *arr, int start, int mid, int end) {
    int *left, *right;
    int tleft = 0, tright = 0;
    int items = (end - start) / 2;

    left = calloc(items, sizeof(int));
    right = calloc(items, sizeof(int));

    for (int i = 0; i < items; i++) {
       left[tleft++] = arr[start + i];
       right[tright++] = arr[mid + i];
    }

    tleft = 0, tright = 0;

    for (int i = start; i < end; i++) {
       if (tleft >= items) arr[i] = right[tright++];
       else if (tright >= items) arr[i] = left[tleft++];
       else if (left[tleft] < right[tright]) arr[i] = left[tleft++];
       else arr[i] = right[tright++];
    }

    /* show(arr, true); */

    free(left);
    free(right);
}

void quick_sort(int *arr, int start, int end) {
   if (end == -1) end = SIZE - 1;

   if (start < end) {
      int pivot = partition(arr, start, end);
      quick_sort(arr, start, pivot - 1);
      quick_sort(arr, pivot + 1, end);
   }
}

int partition(int *arr, int start, int end) {
   int pivot = arr[end];
   int x = start;

   for (int y = start; y < end; y++) {
      if (arr[y] < pivot) {
         int aux = arr[y];
         arr[y] = arr[x];
         arr[x] = aux;
         x++;
      }

      /* show(arr, true); */
   }

   int aux = arr[x];
   arr[x] = arr[end];
   arr[end] = aux;

   return x;
}
