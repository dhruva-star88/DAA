# include <stdio.h>
#include <stdlib.h>
#include<time.h>

void merge(int a[], int low, int mid, int high)
{
    int b[100], i=low, j=mid+1, k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        b[k++] = a[i++];
        else
        b[k++] = a[j++];
    }
    while (i<=mid)
        b[k++]=a[i++];
    while (j<=high)
    b[k++]=a[j++];
    for(i=low; i<=high; i++)
    a[i] = b[i];
}

void mergeSort(int a[], int low, int high){
    int mid;
    if (low<high)
    {
mid = (low+high)/2;
mergeSort(a, low, mid);
mergeSort(a, mid+1, high);
merge(a, low, mid, high);
    }
    
}

int main(){
    int n, a[100];
    float t1, t2;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(int i=0; i<n; i++)
    {
        a[i] = rand();
    }
    printf("Original Array:\n");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    t1=clock();
    mergeSort(a, 0, n-1);
    t2=clock();
    printf("\nSorted Array:\n");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
}
printf("\nTime Taken is %f", (t2-t1));
}
