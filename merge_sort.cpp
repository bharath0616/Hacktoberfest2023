#include <iostream>
using namespace std;

void merge(int a[], int low, int high, int mid);
void msort(int a[], int low, int high)
{
    int mid;
    if (low < high) // if an array has only 1 element, both low and high will be equal. At that
    {               // point the recursive function will return.
        mid = (low + high) / 2;
        msort(a, low, mid);       // left sub-array with elements from low index to mid index
        msort(a, mid + 1, high);  // right sub-array with elements from mid+1 index to high index
        merge(a, low, high, mid); // after sorting the 2 arrays, call merge() function to merge them
    }
    else
        return;
}
void merge(int a[], int low, int high, int mid)
{
    int i, j, k, temp[50];            // a temporary array is used for merging the values of 2 sub-arrays
    i = low;                          // ‘i’ is the index for left sub-array and so it starts with ‘low’ & goes up to ‘mid’
    j = mid + 1;                      // ‘j’ is the index for right sub-array and so it starts with ‘mid+1’ & goes up to ‘high’
    k = low;                          // k is the index for ‘temp’ array
    while ((i <= mid) && (j <= high)) // this loop will continue as long as both left & right sub-arrays
    {                                 // have at least 1 element that has not yet been copied to ‘temp’
        if (a[i] < a[j])              // this finds the min. element between the first elements of left & right
            temp[k++] = a[i++];       // if left array element is minimum it is copied to ‘temp’
        else
            temp[k++] = a[j++]; // else if right array element is minimum it is copied to ‘temp’
    }
    while (i <= mid)          // if right sub-array is fully copied but left array still has few elements
        temp[k++] = a[i++];   // copy them to temp
    while (j <= high)         // if left sub-array is fully copied but right array still has few elements
        temp[k++] = a[j++];   // copy them to temp
    for (i = low; i < k; i++) // this is to transfer the contents of ‘temp’ array back to original array, a
        a[i] = temp[i];
}
int main()
{
    int a[20], i, n;
    cout << "Enter total no.of elements:" << endl;
    cin >> n;
    cout << "Enter a[i]" << endl;
    for (i = 0; i < n; i++)
        cin >> a[i];
    msort(a, 0, n - 1);
    cout << "After sorting:" << endl;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
