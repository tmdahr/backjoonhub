#include <cstdio>
#include <cstring>

void solve(void);

int main(void)
{
    int test_case;
    scanf("%d", &test_case);

    while (test_case--) solve();

    return 0;
}

void solve(void)
{
    char bits[1000005];
    scanf("%s", bits);

    int len = strlen(bits);
    int idx = 0;
    bool continue_flag = true;

    while(idx < len && continue_flag) {
        if(bits[idx] == '0') {
            idx++;
            if(idx >= len || bits[idx] == '0') continue_flag = false;
            idx++;
        }
        else {
            idx++;

            int next_1 = -1;
            for (int i = idx; i < len; i++) {
                if (bits[i] == '1') {
                    next_1 = i;
                    break;
                }
            }
            if(next_1 == -1 || next_1 - idx < 2) {
                continue_flag = false;
                break;
            }

            int next_0 = -1;
            for(int i=next_1; i<len; i++)
                if(bits[i] == '0') {
                    next_0 = i;
                    break;
                }
            if(next_0 == -1) {
                idx = len;
                break;
            }
            if(next_0 == len - 1) {
                continue_flag = false;
                break;
            }

            idx = next_0;
            if(bits[next_0+1] == '0' && next_0 - next_1 > 1) idx--;
        }
    }
    printf("%s\n", (idx == len && continue_flag ? "YES" : "NO"));
}