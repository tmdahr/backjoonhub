#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

struct decimal36 {
    unsigned int cipher[60];
    int maxDigit;

    decimal36() {
        memset(cipher, 0, sizeof(cipher));
        maxDigit = 0;
    }

    bool operator<(const decimal36& t) const {
        if(maxDigit != t.maxDigit)
            return maxDigit < t.maxDigit;
        for(int i=maxDigit; i>=0; i--)
            if(cipher[i] != t.cipher[i])
                return cipher[i] < t.cipher[i];
        return false;
    }
};

priority_queue<decimal36> decQueue;

decimal36 byCipher[36];
decimal36 total;

void arrangeCipher(decimal36 &de) {
    for(int i=0; i<60; i++)
        if(de.cipher[i] > 0) {
            de.maxDigit = i;
            if(de.cipher[i] > 35) {
                de.cipher[i+1] += de.cipher[i] / 36;
                de.cipher[i] %= 36;
            }
        }
}

int charTode36(char c) {
    if(c >= '0' && c <= '9')
        return c - '0';
    return c - 'A' + 10;
}

char cipherTochar(int i) {
    if (i < 10) return i + '0';
    return i - 10 + 'A';
}

int main(void) {
    int N, K;
    scanf("%d", &N);

    for(int i=0; i<N; i++) {
        char temp[55];
        scanf("%s", temp);
        int len = strlen(temp);
        if(len == 1 && temp[0] == '0') continue;

        for(int j=0; j<len; j++) {
            int target = charTode36(temp[j]);
            byCipher[target].cipher[len-j-1] += 35 - target;
            total.cipher[len-j-1] += target;
        }
    }

    for(int i=0; i<36; i++) {
        arrangeCipher(byCipher[i]);
        decQueue.push(byCipher[i]);
    }

    scanf("%d", &K);

    for(int i=0; i<K; i++) {
        decimal36 temp = decQueue.top();
        decQueue.pop();
        for(int j=0; j<60; j++) total.cipher[j] += temp.cipher[j];
    }

    arrangeCipher(total);

    for(int i=total.maxDigit; i>=0; i--) putchar(cipherTochar(total.cipher[i]));
    putchar('\n');

    return 0;
}