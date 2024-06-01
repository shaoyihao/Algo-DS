#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010, K = 100000;
int q[N], res[N], n;
int cnt[K + 1], S[K + 1];

void countingSort(int q[], int n, int k)
{
    for (int i = 0; i < n; i++) cnt[q[i]]++;

    S[0] = cnt[0];
    for (int i = 1; i <= k; i++) S[i] = S[i - 1] + cnt[i];

    for (int i = n - 1; i >= 0; i--) 
    {
        res[S[q[i]] - 1] = q[i];
        S[q[i]]--;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i];

    countingSort(q, n, *max_element(q, q + n));

    for (int i = 0; i < n; i++) cout << res[i] << ' ';
    return 0;
}
