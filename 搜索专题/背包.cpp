//使用递归方法来解决背包问题，深度优先搜索（DFS)
#include<cstdio>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 30;
int n, V, maxValue = 0;
int w[maxn] = { 1 }, c[maxn];
int half_sum = 0;
vector<int> ans;
//void DFS(int index, int sumW, int sumC)
//{
//	if (index == n)
//	{
//		if (sumW <= V&&sumC > maxValue){
//			maxValue = sumC;
//		}
//		return;
//	}
//	DFS(index + 1, sumW, sumC);
//	DFS(index + 1, sumW + w[index], sumC + c[index]);
//}
void DFS(int index, int sumW, int sumC)
{
	if (index == n)
	{
		return;
	}
	DFS(index + 1, sumW, sumC);
	if (sumW + w[index] <= V && sumC+c[index]<=half_sum)
	{
		if (sumC + c[index] > maxValue)
		{
			maxValue = sumC + c[index];			
		}
		DFS(index + 1, sumW + w[index], sumC + c[index]);
	}
}
int main()
{
	int sum = 0;
	int value1 = 0;
	scanf("%d", &n);
	V = n / 2;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
		sum += c[i];
	}
	half_sum = sum / 2;
	if (n % 2 == 0)
	{
		DFS(0, 0, 0);
	}
	else
	{
		DFS(0, 0, 0);
		value1 = maxValue;
		V = n / 2 + 1;
		DFS(0, 0, 0);
		if (value1 > maxValue)
		{
			maxValue = value1;
			V = n / 2;
		}		
	}
	printf("%d %d\n", maxValue,sum-maxValue);
	vector<int>::iterator it=ans.begin();
	for (int i = 0; i < V; i++)
	{
		printf("%d ", *(it + i));
	}
	return 0;
}