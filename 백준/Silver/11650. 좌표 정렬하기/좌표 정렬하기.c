#include <stdio.h>
void sort(int arrx[], int arry[], int left, int right);
void merge(int arrx[], int arry[], int left, int mid, int right);
int sort_arrx[100002]={0,}, sort_arry[100002]={0,};

int main(void)
{
	int arrx[100002]={0,}, arry[100002]={0,};
	int n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d %d", &arrx[i], &arry[i]);
	sort(arrx, arry, 0, n-1);
	for(i=0; i<n; i++) printf("%d %d\n", arrx[i], arry[i]);
	
	return 0;
}

void sort(int arrx[], int arry[], int left, int right)
{
	int mid;
	if(left<right)
	{
		mid=(left+right)/2;
		sort(arrx, arry, left, mid);
		sort(arrx, arry, mid+1, right);
		merge(arrx, arry, left, mid, right);
	}
}

void merge(int arrx[], int arry[], int left, int mid, int right)
{
	int f = left, r = mid+1, s = left, i;
	
	while(f <= mid && r <= right)
	{
		if(arrx[f]==arrx[r])
		{
			if(arry[f]<arry[r])
			{
				sort_arrx[s] = arrx[f];
				sort_arry[s++] = arry[f++];
			}
			else
			{
				sort_arrx[s] = arrx[r];
				sort_arry[s++] = arry[r++];
			}
		}
		else if(arrx[f]<arrx[r])
		{
			sort_arrx[s] = arrx[f];
			sort_arry[s++] = arry[f++];
		}
		else
		{
			sort_arrx[s] = arrx[r];
			sort_arry[s++] = arry[r++];
		}
	}
	
	if(f > mid)
		for(i=r; i<=right; i++)
		{
			sort_arrx[s] = arrx[i];
			sort_arry[s++] = arry[i];
		}
	else
		for(i=f; i<=mid; i++)
		{
			sort_arrx[s] = arrx[i];
			sort_arry[s++] = arry[i];
		}
	
	for(i=left; i<=right; i++) 
	{
		arrx[i] = sort_arrx[i];
		arry[i] = sort_arry[i];
	}
}