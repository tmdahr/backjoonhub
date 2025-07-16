#include <cstdio>
#include <set>
using namespace std;

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int k;
        scanf("%d", &k);
        multiset<int> ms;
        while(k--)
        {
            char id;
            int n;
            scanf(" %c %d", &id, &n);
            if(id=='I') ms.insert(n);
            else
            {
                if(ms.empty()) continue;
                if(n<0)
                {
                    auto it = ms.begin();
                    ms.erase(it);
                }
                else 
                {
                    auto it = --ms.end();
                    ms.erase(it);
                }
            }
        }
        if(ms.empty()) printf("EMPTY\n");
        else printf("%d %d\n", *--ms.end(), *ms.begin());
    }
    
    return 0;
}