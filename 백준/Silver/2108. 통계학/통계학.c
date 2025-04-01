#include <stdio.h>

void mergesort(int arr[], int left, int right);
void mergetwoarea(int arr[], int left, int mid, int right);
int sortarr[500002];

int main(void)
{
	int arr[500002], count[8002]={0,};
	int n, m, t=0, i;
	double avg;
	scanf("%d", &n);
	for(m=0; m<n; m++)
	{
		scanf("%d", &arr[m]);
		count[arr[m]+4000]++;
		t += arr[m];
	}
	avg = (double)t/(double)n;
	//if((int)avg==-0) printf("0\n");
	if(-0.5<=avg && avg<0)
		printf("0\n");
	else printf("%.0lf\n", avg);
	mergesort(arr, 0, n-1);
	printf("%d\n", arr[(n-1)/2]);
	t=1;
	int max=0;
	int num;
	for(i=0;i<=8000;i++)
	{
		if(max<count[i])
		{
			max = count[i];
			num = i-4000;
		}
	}
	for(i=0;i<=8000;i++)
	{
		if(max==count[i]&&num!=i-4000)
		{
			num = i-4000;
			break;
		}
	}
	printf("%d\n", num);
	printf("%d", arr[n-1]-arr[0]);
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