#include <stdio.h>
void sort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
int sortarr[1000005];

int main(void)
{
	int arr[1000005];
	int n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &arr[i]);
	sort(arr, 0, n-1);
	for(i=0; i<n; i++) printf("%d\n", arr[i]);
	
	return 0;
}

void sort(int arr[], int left, int right)
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

void merge(int arr[], int left, int mid, int right)
{
	int f = left, r = mid+1, s = left, i;
	
	while(f <= mid && r <= right)
	{
		if(arr[f]<arr[r])
			sortarr[s++] = arr[f++];
		else
			sortarr[s++] = arr[r++];
	}
	
	if(f > mid)
		for(i=r; i<=right; i++)
			sortarr[s++] = arr[i];
	else
		for(i=f; i<=mid; i++)
			sortarr[s++] = arr[i];
	
	for(i=left; i<=right; i++) arr[i] = sortarr[i];
}