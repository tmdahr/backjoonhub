#include <stdio.h>
#include <string.h>

int arr[100002];
int ans[100002];
char a[100002];

int main(void) {
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        arr[x]++;
    }

    getchar();
    fgets(a, sizeof(a), stdin);

    for(int i=0; i<n; i++) {
        if(a[i] >= 'A' && a[i] <= 'Z') ans[a[i]-'A'+1]++;
        else if(a[i] >= 'a' && a[i] <= 'z') ans[a[i]-'a'+27]++;
        else if (a[i] == ' ') ans[0]++;
    }

    int flag = 1;
    for(int i=0; i<53; i++)
        if(arr[i] != ans[i]) flag = 0;

    if(!flag) printf("n");
    else printf("y");

    return 0;
}