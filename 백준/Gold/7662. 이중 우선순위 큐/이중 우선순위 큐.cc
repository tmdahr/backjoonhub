#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000

typedef struct {
    int value;
    int id;
} Node;

Node minHeap[MAX], maxHeap[MAX];
int valid[MAX];  // 유효한 노드 여부
int minSize, maxSize;

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

// ------------ 삽입 ------------

void minHeapInsert(int value, int id) {
    int i = minSize++;
    minHeap[i].value = value;
    minHeap[i].id = id;
    while (i > 0 && minHeap[(i - 1) / 2].value > minHeap[i].value) {
        swap(&minHeap[i], &minHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void maxHeapInsert(int value, int id) {
    int i = maxSize++;
    maxHeap[i].value = value;
    maxHeap[i].id = id;
    while (i > 0 && maxHeap[(i - 1) / 2].value < maxHeap[i].value) {
        swap(&maxHeap[i], &maxHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// ------------ Pop ------------

void minHeapify(int i) {
    while (1) {
        int smallest = i;
        int l = 2 * i + 1, r = 2 * i + 2;
        if (l < minSize && minHeap[l].value < minHeap[smallest].value) smallest = l;
        if (r < minSize && minHeap[r].value < minHeap[smallest].value) smallest = r;
        if (smallest == i) break;
        swap(&minHeap[i], &minHeap[smallest]);
        i = smallest;
    }
}

void maxHeapify(int i) {
    while (1) {
        int largest = i;
        int l = 2 * i + 1, r = 2 * i + 2;
        if (l < maxSize && maxHeap[l].value > maxHeap[largest].value) largest = l;
        if (r < maxSize && maxHeap[r].value > maxHeap[largest].value) largest = r;
        if (largest == i) break;
        swap(&maxHeap[i], &maxHeap[largest]);
        i = largest;
    }
}

void cleanMin() {
    while (minSize > 0 && !valid[minHeap[0].id]) {
        swap(&minHeap[0], &minHeap[--minSize]);
        minHeapify(0);
    }
}

void cleanMax() {
    while (maxSize > 0 && !valid[maxHeap[0].id]) {
        swap(&maxHeap[0], &maxHeap[--maxSize]);
        maxHeapify(0);
    }
}

void deleteMin() {
    cleanMin();
    if (minSize > 0) {
        valid[minHeap[0].id] = 0;
        swap(&minHeap[0], &minHeap[--minSize]);
        minHeapify(0);
    }
}

void deleteMax() {
    cleanMax();
    if (maxSize > 0) {
        valid[maxHeap[0].id] = 0;
        swap(&maxHeap[0], &maxHeap[--maxSize]);
        maxHeapify(0);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int k;
        scanf("%d", &k);
        minSize = maxSize = 0;
        memset(valid, 0, sizeof(valid));
        int id = 0;

        for (int i = 0; i < k; i++) {
            char op;
            int n;
            scanf(" %c %d", &op, &n);

            if (op == 'I') {
                valid[id] = 1;
                minHeapInsert(n, id);
                maxHeapInsert(n, id);
                id++;
            } else if (op == 'D') {
                if (n == 1) deleteMax();
                else if (n == -1) deleteMin();
            }
        }

        cleanMin();
        cleanMax();

        if (minSize == 0 || maxSize == 0) {
            printf("EMPTY\n");
        } else {
            printf("%d %d\n", maxHeap[0].value, minHeap[0].value);
        }
    }
    return 0;
}
