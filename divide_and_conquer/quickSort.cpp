#include <iostream>
using namespace std;

const int N = 1e5+10;
int a[N], n;

int Partition(int q[], int l, int r)
{
    int i = l, x = q[r];
    for (int j = l; j <= r - 1; j++)
        if (q[j] <= x) swap(q[i++], q[j]);
    swap(q[i], q[r]);
    return i;
}

void quickSort(int q[], int l, int r)
{
    if (l < r)
    {
        int k = Partition(q, l, r);
        quickSort(q, l, k - 1), quickSort(q, k + 1, r);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    return 0;
}
