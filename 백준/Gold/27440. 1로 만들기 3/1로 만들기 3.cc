#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 1000003
#define QUEUE_SIZE 1000000

typedef struct {
    unsigned long long value;
    int depth;
} Node;

Node queue[QUEUE_SIZE];
int front = 0, rear = 0;

void enqueue(unsigned long long value, int depth)
{
    queue[rear].value = value;
    queue[rear].depth = depth;
    rear++;
}

Node dequeue(void) {return queue[front++];}

unsigned long long hash_table[TABLE_SIZE];
bool visit[TABLE_SIZE];

bool visited(unsigned long long x)
{
    unsigned long long h = x % TABLE_SIZE;
    while(visit[h]) {
        if(hash_table[h] == x) return true;
        h = (h+1) % TABLE_SIZE;
    }
    return false;
}

void mark(unsigned long long x)
{
    unsigned long long h = x % TABLE_SIZE;
    while(visit[h])
    {
        if(hash_table[h] == x) return;
        h = (h+1) % TABLE_SIZE;
    }
    hash_table[h] = x;
    visit[h] = true;
}

int main(void)
{
    unsigned long long n;
    scanf("%llu", &n);

    enqueue(n, 0);
    mark(n);

    while(front < rear)
    {
        Node cur = dequeue();
        if(cur.value == 1)
        {
            printf("%d\n", cur.depth);
            return 0;
        }

        unsigned long long next = cur.value - 1;
        if(!visited(next))
        {
            mark(next);
            enqueue(next, cur.depth + 1);
        }
        if(cur.value%2 == 0)
        {
            next = cur.value / 2;
            if(!visited(next))
            {
                mark(next);
                enqueue(next, cur.depth+1);
            }
        }
        if (cur.value%3 == 0)
        {
            next = cur.value / 3;
            if(!visited(next))
            {
                mark(next);
                enqueue(next, cur.depth+1);
            }
        }
    }
    return 0;
}