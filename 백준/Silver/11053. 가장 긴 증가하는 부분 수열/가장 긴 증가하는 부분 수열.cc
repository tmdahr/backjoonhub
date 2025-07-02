#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, num;
    scanf("%d", &n);
    vector<int> lis;
    
    for(int i=0; i<n; i++)
    {
        scanf("%d", &num);
        auto it = lower_bound(lis.begin(), lis.end(), num);
        if(it == lis.end()) lis.push_back(num);
        else *it = num;
    }
    
    printf("%d",lis.size());
}