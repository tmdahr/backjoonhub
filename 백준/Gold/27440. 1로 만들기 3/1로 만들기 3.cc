#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define TABLE_SIZE 1000003  // 큰 소수, 해시 테이블 크기
#define QUEUE_SIZE 1000000  // 큐 크기 (충분히 크게)

// ===== 큐 구현 =====
typedef struct {
    uint64_t value;
    int depth;
} Node;

Node queue[QUEUE_SIZE];
int front = 0, rear = 0;

void enqueue(uint64_t value, int depth) {
    queue[rear].value = value;
    queue[rear].depth = depth;
    rear++;
}

Node dequeue() {
    return queue[front++];
}

// ===== 해시셋 구현 =====
uint64_t hash_table[TABLE_SIZE];
bool used[TABLE_SIZE];

bool is_visited(uint64_t x) {
    uint64_t h = x % TABLE_SIZE;
    while (used[h]) {
        if (hash_table[h] == x) return true;
        h = (h + 1) % TABLE_SIZE;
    }
    return false;
}

void mark_visited(uint64_t x) {
    uint64_t h = x % TABLE_SIZE;
    while (used[h]) {
        if (hash_table[h] == x) return;
        h = (h + 1) % TABLE_SIZE;
    }
    hash_table[h] = x;
    used[h] = true;
}

// ===== 메인 알고리즘 =====
int main() {
    uint64_t n;
    scanf("%llu", &n);

    enqueue(n, 0);
    mark_visited(n);

    while (front < rear) {
        Node current = dequeue();

        if (current.value == 1) {
            printf("%d\n", current.depth);
            return 0;
        }

        // 연산 1: 나누기 3
        if (current.value % 3 == 0) {
            uint64_t next = current.value / 3;
            if (!is_visited(next)) {
                mark_visited(next);
                enqueue(next, current.depth + 1);
            }
        }

        // 연산 2: 나누기 2
        if (current.value % 2 == 0) {
            uint64_t next = current.value / 2;
            if (!is_visited(next)) {
                mark_visited(next);
                enqueue(next, current.depth + 1);
            }
        }

        // 연산 3: -1
        uint64_t next = current.value - 1;
        if (!is_visited(next)) {
            mark_visited(next);
            enqueue(next, current.depth + 1);
        }
    }

    return 0;
}