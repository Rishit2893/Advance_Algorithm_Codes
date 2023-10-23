#include <bits/stdc++.h>

using namespace std;

int partition(int arr[], int p, int r, int &count)
{
    int i=p-1, j=p, pivot=arr[r];
    
    for(j=p; j<=r-1; j++)
    {
        count++;
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i+1], arr[r]);
    
    return i+1;
}

int randomized_partition(int arr[], int p, int r, int &count)
{
    srand(time(0));
    
    int random = p+rand()%(r-p+1);
    
    swap(arr[r], arr[random]);
    
    return partition(arr, p, r, count);
}

void quick_sort(int arr[], int p, int r, int &count)
{
    if(p<r)
    {
        int q=randomized_partition(arr, p, r, count);
        quick_sort(arr, p, q-1, count);
        quick_sort(arr, q+1, r, count);
    }
}

int main() {
    int count=0;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quick_sort(arr, 0, n-1, count);
    
    cout << "No. of comparisons : " << count << endl;
    
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}
