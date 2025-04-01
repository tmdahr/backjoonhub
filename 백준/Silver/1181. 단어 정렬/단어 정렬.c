#include <stdio.h>
#include <string.h>

typedef struct _node{
	int l;
	char t[50];
}node;

void sort(node arr[],int left, int right);
void merge(node arr[], int left, int mid, int right);
node arr[20002];
node sort_arr[20002];

int main(void)
{
	int n, i, j;
	scanf("%d", &n);
	for(i=0; i<n; i++) 
	{
		scanf("%s", &arr[i].t);
		arr[i].l = strlen(arr[i].t);
		for(j=0; j<=i-1; j++)
		{
			if(strcmp(arr[j].t,arr[i].t)==0)
			{
				i--;
				n--;
			}
		}
	}
	sort(arr, 0, n-1);
	for(i=0; i<n; i++) printf("%s\n", arr[i].t);
	
	return 0;
}

void sort(node arr[], int left, int right)
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

void merge(node arr[], int left, int mid, int right)
{
	int f = left, r = mid+1, s = left, i;
	
	while(f <= mid && r <= right)
	{
		if(arr[f].l==arr[r].l)
		{
			if(strcmp(arr[f].t, arr[r].t)<0)
			{
				sort_arr[s++]=arr[f++];
			}
			else
			{
				sort_arr[s++]=arr[r++];
			}
		}
		else if(arr[f].l<arr[r].l)
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
	
	for(i=left; i<=right; i++) 
	{
		arr[i] = sort_arr[i];
	}
}