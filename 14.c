#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int listIndex;
    int elementIndex;
} HeapNode;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(HeapNode heap[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && heap[left].value < heap[smallest].value)
        smallest = left;
    if(right < n && heap[right].value < heap[smallest].value)
        smallest = right;

    if(smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void buildHeap(HeapNode heap[], int n) {
    for(int i=(n/2)-1; i>=0; i--) {
        heapify(heap, n, i);
    }
}

int main() {
    int K;
    printf("Enter number of sorted lists (K): ");
    scanf("%d", &K);

    int *lists[K], sizes[K];
    for(int i=0; i<K; i++) {
        printf("Enter size of list %d: ", i+1);
        scanf("%d", &sizes[i]);
        lists[i] = (int *)malloc(sizes[i]*sizeof(int));

        printf("Enter elements of list %d (sorted): ", i+1);
        for(int j=0; j<sizes[i]; j++) {
            scanf("%d", &lists[i][j]);
        }
    }

    HeapNode heap[K];
    int heapSize = 0, totalSize = 0;

    // Initialize heap with the first element of each list
    for(int i=0; i<K; i++) {
        if(sizes[i] > 0) {
            heap[heapSize].value = lists[i][0];
            heap[heapSize].listIndex = i;
            heap[heapSize].elementIndex = 0;
            heapSize++;
            totalSize += sizes[i];
        }
    }

    buildHeap(heap, heapSize);

    printf("Merged Sorted List: ");
    for(int count=0; count<totalSize; count++) {
        HeapNode root = heap[0];
        printf("%d ", root.value);

        if(root.elementIndex + 1 < sizes[root.listIndex]) {
            heap[0].value = lists[root.listIndex][root.elementIndex + 1];
            heap[0].elementIndex += 1;
        } else {
            // Replace with last heap element and shrink heap size
            heap[0] = heap[heapSize - 1];
            heapSize--;
        }

        heapify(heap, heapSize, 0);
    }
    printf("\n");

    for(int i=0; i<K; i++) free(lists[i]);

    return 0;
}