#include <stdio.h>
void sort(double arr[], int left, int right);
void merge(double arr[], int left, int mid, int right);
double sort_arr[10000002]={0,};

int main(void)
{
	double arr[10000002];
	int n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%lf", &arr[i]);
	sort(arr, 0, n-1);
	for(i=0; i<7; i++) printf("%.3lf\n", arr[i]);
	
	return 0;
}

void sort(double arr[], int left, int right)
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

void merge(double arr[], int left, int mid, int right)
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