#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 100;
int m, n;
char map[maxn][maxn];
bool inq[maxn][maxn] = { false };
int X[4] = { 0, 0, 1, -1 };
int Y[4] = { 1, -1, 0, 0 };
struct node
{
	int x, y;
	int step;
}S,T,Node;
bool test(int x, int y)
{
	if (inq[x][y] == false && (map[x][y] == '.' || map[x][y] == 'T'))
		return true;
	else
		return false;
}
int BFS()
{
	queue<node> Q;
	Q.push(S);
	while (!Q.empty())
	{
		node top = Q.front();
		Q.pop();
		if (top.x == T.x&&top.y == T.y)
		{
			return top.step;
		}
		for (int i = 0; i < 4; i++)
		{
			int newx = top.x + X[i];
			int newy = top.y + Y[i];
			if (test(newx, newy))
			{
				Node.x = newx, Node.y = newy;
				Node.step = top.step + 1;
				Q.push(Node);
				inq[newx][newy] = true;
			}
		}
	}
	return -1;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int x = 0; x < n; x++)
	{
		getchar(); //过滤掉每一行后面的换行符
		for (int y = 0; y < n; y++)
		{
			//map[x][y]=getchar();
			scanf("%c", &map[x][y]);//上面那种写法也可以都一样
		}
	}
	scanf("%d%d%d%d", &S.x, &S.y, &T.x, &T.y);
	S.step = 0;
	printf("%d\n", BFS());
	return 0;
}