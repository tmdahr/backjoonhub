#include <stdio.h>
#include <string.h>
void sort(char arr[], int left, int right);
void merge(char arr[], int left, int mid, int right);
char sort_arr[12];

int main(void)
{
	char arr[12];
	int i, l;
	scanf("%s", &arr);
	l = strlen(arr);
	sort(arr, 0, l-1);
	for(l=l-1; l>=0; l--) printf("%c", arr[l]);
	
	return 0;
}

void sort(char arr[], int left, int right)
{
	int mid;
	if(left<right)
	{
		mid=(left+right)/2;
		sort(arr, left, mid);
		sort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}

void merge(char arr[], int left, int mid, int right)
{
	int f = left, r = mid+1, s = left, i;
	
	while(f <= mid && r <= right)
	{
		if(arr[f]<arr[r]) sort_arr[s++] = arr[f++];
		else sort_arr[s++] = arr[r++];
	}
	
	if(f > mid)
		for(i=r; i<=right; i++) sort_arr[s++] = arr[i];
	else
		for(i=f; i<=mid; i++) sort_arr[s++] = arr[i];
	
	for(i=left; i<=right; i++) arr[i] = sort_arr[i];
}