#include <stdio.h>

void mergesort(int arr[], int left, int right);
void mergetwoarea(int arr[], int left, int mid, int right);
int sortarr[52];

int main(void)
{
	int arr[52], arrb[52];
	int n, m, num=0;
	scanf("%d", &n);
	for(m=0; m<n; m++) scanf("%d", &arr[m]);
	for(m=0; m<n; m++) scanf("%d", &arrb[m]);
	mergesort(arr, 0, n-1);
	mergesort(arrb, 0, n-1);
	for(m=0; m<n; m++) num += arr[m] * arrb[n-1-m];
	printf("%d", num);
	
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