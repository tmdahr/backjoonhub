#include <stdio.h>
#include <string.h>

void sort(int arr[],int left, int right);
void merge(int arr[], int left, int mid, int right);
int arr[1000002];
int sort_arr[1000002];
int search(int key, int left, int right);

int main(void)
{
	int t, i, n, m, l, num, p;
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		num=0;
		scanf("%d", &n);
		for(l=0; l<n; l++) scanf("%d", &arr[l]);
		sort(arr, 0, n-1);
		scanf("%d", &m);
		for(l=0; l<m; l++)
		{
			scanf("%d", &num);
			p = search(num, 0, n-1);
			printf("%d\n", p);
		}
	}
	
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
		{
			sort_arr[s++] = arr[f++];
		}
		else
		{
			sort_arr[s++] = arr[r++];
		}
	}
	
	if(f > mid)
		for(i=r; i<=right; i++)
		{
			sort_arr[s++] = arr[i];
		}
	else
		for(i=f; i<=mid; i++)
		{
			sort_arr[s++] = arr[i];
		}
		
	for(i=left; i<=right; i++) arr[i] = sort_arr[i];
}

int search(int key, int left, int right)
{
	while(1)
	{
		if(left>right) return 0;
		int mid = (left+right)/2;
		if(key==arr[mid]) return 1;
		else if(key>arr[mid])
		{
			left=mid+1;
		}
		else
		{
			right=mid-1;
		}
	}
}