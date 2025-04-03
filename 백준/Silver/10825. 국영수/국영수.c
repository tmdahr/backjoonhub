#include <stdio.h>
#include <string.h>

typedef struct _node{
	char name[12];
	int k, e, m;
}node;

void sort(node arr[],int left, int right);
void merge(node arr[], int left, int mid, int right);
node arr[100002];
node sort_arr[100002];

int main(void)
{
	int n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%s %d %d %d", &arr[i].name, &arr[i].k, &arr[i].e, &arr[i].m);
	sort(arr, 0, n-1);
	for(i=0; i<n; i++) printf("%s\n", arr[i].name);
	
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
		if(arr[f].k==arr[r].k)
		{
			if(arr[f].e==arr[r].e)
			{
				if(arr[f].m==arr[r].m)
				{
					if(strcmp(arr[f].name,arr[r].name) < 0)
					{
						sort_arr[s++]=arr[f++];
					}
					else
					{
						sort_arr[s++]=arr[r++];
					}
				}
				else if(arr[f].m>arr[r].m)
				{
					sort_arr[s++]=arr[f++];
				}
				else
				{
					sort_arr[s++]=arr[r++];
				}
			}
			else if(arr[f].e<arr[r].e)
			{
				sort_arr[s++]=arr[f++];
			}
			else
			{
				sort_arr[s++]=arr[r++];
			}
		}
		else if(arr[f].k>arr[r].k)
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