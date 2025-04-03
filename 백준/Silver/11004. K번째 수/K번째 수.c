#include <stdio.h>

void mergesort(int arr[], int left, int right);
void mergetwoarea(int arr[], int left, int mid, int right);
int sortarr[5000002];
int arr[5000002]={0,};

int main(void)
{
	int n, k, i;
	scanf("%d %d", &n, &k);
	for(i=0; i<n; i++) scanf("%d", &arr[i]);
	mergesort(arr, 0, n-1);
	printf("%d", arr[k-1]);
	
	return 0;
}

void mergesort(int arr[], int left, int right)
{
	int mid;
	if(left<right)
	{
		mid = (left+right)/2;
		mergesort(arr, left, mid);
		mergesort(arr, mid+1, right);
		mergetwoarea(arr, left, mid, right);
	}
}

void mergetwoarea(int arr[], int left, int mid, int right)
{
	int fidx = left, ridx = mid+1, sidx = left, i, l;
	while(fidx<=mid && ridx<=right)
	{
		if(arr[fidx]>arr[ridx]) sortarr[sidx++] = arr[ridx++];
		else sortarr[sidx++] = arr[fidx++];
	}
	
	if(fidx>mid) for(i=ridx; i<=right; i++) sortarr[sidx++] = arr[i];
	else for(i=fidx; i<=mid; i++) sortarr[sidx++] = arr[i];

	for(i=left; i<=right; i++) arr[i] = sortarr[i];	
}