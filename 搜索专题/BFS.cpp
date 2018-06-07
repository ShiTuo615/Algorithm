//
#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 100;
int m, n;
int maxt[maxn][maxn];
bool inq[maxn][maxn] = { false };
int VX[4] = { 0, 0, 1, -1 };
int VY[4] = { 1, -1, 0, 0 };
struct node
{
	int x, y;
}Node;
bool test(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m) return false;
	if (maxt[x][y] == 0 || inq[x][y] == true) return false;
	return true;
}
void BFS(int x,int y)
{
	queue<node> Q;
	Node.x = x,Node.y = y;
	Q.push(Node);
	inq[x][y] = true;
	while (!Q.empty())
	{
		node top = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int newx = top.x + VX[i];
			int newy = top.y + VY[i];
			if (test(newx, newy))
			{
				Node.x = newx, Node.y = newy;
				Q.push(Node);
				inq[newx][newy] = true;
			}
		}
	}
}
int main()
{
	int num = 0;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &maxt[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (maxt[i][j]==1&&inq[i][j]==false)
			{
				num++;
				BFS(i, j);
			}
		}
	}
	printf("%d\n", num);
	return 0;
}