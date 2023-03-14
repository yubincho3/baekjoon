#include <bits/stdc++.h>
using namespace std;

double mtrx[6][7];
int n;

deque<double> solve()
{
    // Elimination phase
    for (int p = 0; p < n - 1; p++)
    {
        if (mtrx[p][p] == 0)
        {
            for (int r = p + 1; r < n; r++)
            {
                if (mtrx[r][p] != 0)
                {
                    swap(mtrx[p], mtrx[r]);
                    break;
                }
            }
        }

        for (int r = p + 1; r < n; r++)
        {
            if (mtrx[r][p] != 0)
            {
                double lambda = mtrx[r][p] / mtrx[p][p];

                for (int c = p; c <= n; c++)
                    mtrx[r][c] -= lambda * mtrx[p][c];
            }
        }
    }

    deque<double> x;

    // Backward substitute
    for (int i = n - 1; i >= 0; i--)
    {
        mtrx[i][n] /= mtrx[i][i];
        x.push_front(mtrx[i][n]);

        for (int r = 0; r < i; r++)
            mtrx[r][n] -= mtrx[r][i] * mtrx[i][n];
    }

    return x;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            scanf("%lf", &mtrx[i][j]);

    for (double x: solve())
        printf("%.0f ", x);

    return 0;
}
