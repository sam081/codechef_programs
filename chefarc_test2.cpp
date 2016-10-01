#include <stdio.h>
#include <algorithm>
using namespace std;
#define NMAX 111
#define INF 1000000000
int A[NMAX][NMAX];
int M, N, K1, K2;
void ReadInput()
{
    scanf("%d %d %d %d", &M, &N, &K1, &K2);
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
        scanf("%d", &A[i][j]);
}
int dist[2][NMAX][NMAX], q[NMAX * NMAX][2], qli, qls;
void BFS(int r, int c, int K, int d[NMAX][NMAX])
{
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
        d[i][j] = INF; 	qli = qls = 0;
    q[0][0] = r;
    q[0][1] = c;
    d[r][c] = 0;
    while (qli <= qls)
    {
        int i = q[qli][0], j = q[qli][1];
        qli++;
        for (int ii = i - K; ii <= i + K; ii++)
            for (int jj = j - K; jj <= j + K; jj++)
            {
                if (ii <= 0 || ii > M || jj <= 0 || jj > N)
                continue;
                int dx = i - ii;
                if (dx < 0)
                    dx = -dx;
                int dy = j - jj;
                if (dy < 0)
                    dy = -dy;
                if (dx + dy > K)
                    continue;
                if (A[ii][jj] == 0 && d[i][j] + 1 < d[ii][jj])
                {
                        d[ii][jj] = d[i][j] + 1;
                        qls++;
                        q[qls][0] = ii; q[qls][1] = jj;
                }
            }
    }
}
int FindMinDist()
{
    int dmin = INF;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
        if (max(dist[0][i][j], dist[1][i][j]) < dmin)
        dmin = max(dist[0][i][j], dist[1][i][j]);
    if (dmin == INF)
        dmin = -1;
    return dmin;
}
int main()
{ 	//freopen("x.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ReadInput();
        BFS(1, 1, K1, dist[0]);
        BFS(1, N, K2, dist[1]);
        printf("%d\n", FindMinDist());
    }
return 0;
}
