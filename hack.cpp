
#include <stdio.h>
#include <stdlib.h>

typedef struct Fenwick
{
    int *bit;
    int n;

} Fenwick;

int find(Fenwick *fen, int r)
{
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += fen->bit[r];
    return ret;
}

void update(Fenwick *fen, int idx, int delta)
{
    for (; idx < fen->n; idx = idx | (idx + 1))
        fen->bit[idx] += delta;
}

int change(int n)
{
    int ans = 0;
    while (n)
    {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

void solve()
{
    int n, q;
    scanf("%d %d", &n, &q);
    int *arr = (int *)malloc(sizeof(int) * n);
    Fenwick *Tree = (Fenwick *)malloc(sizeof(Fenwick));
    Tree->n = n + 2;
    Tree->bit = (int *)calloc(Tree->n, sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < q; i++)
    {
        int a;
        scanf("%d", &a);
        if (a == 1)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            update(Tree, l, 1);
            update(Tree, r + 1, -1);
        }
        else
        {
            int x;
            scanf("%d", &x);
            int cnt = find(Tree, x);
            int ans = arr[x - 1];
            for (int i = 0; i < cnt; i++)
            {
                ans = change(ans);
                if (ans / 10 == 0)
                    break;
            }
            printf("%d\n", ans);
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();

    return 0;
}