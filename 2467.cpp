#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int n;

vector<int> solve()
{
    int mlIdx = 0, mrIdx = n - 1;
    int lIdx = 0, rIdx = n - 1;

    while (lIdx < rIdx)
    {
        if (abs(arr[mlIdx] + arr[mrIdx]) > abs(arr[lIdx] + arr[rIdx]))
            tie(mlIdx, mrIdx) = tie(lIdx, rIdx);

        if (arr[lIdx] + arr[rIdx] < 0)
            lIdx++;
        else
            rIdx--;
    }

    return {arr[mlIdx], arr[mrIdx]};
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int t: solve())
        printf("%d ", t);

    return 0;
}
