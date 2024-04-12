
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>


//https://www.cnblogs.com/DSCL-ing/p/18132065
//https://www.acwing.com/problem/content/96/

//知道范围后可以开一个很大的全局数组,之后就可以不用传参,方便递归
const int N = 10;

int state[N];  //记录选过的数字
bool used[N];  //false表示未使用过,true表示已使用当前下标的数字
int n;       //题目传入参数 

void dfs(int u)
{
	if (u > n)
	{
		for (int i = 1; i <= n; i++)  //遍历state数组 输出结果
		{
			printf("%d ", state[i]);
		}
		puts("");
		return;
	}

	for (int i = 1; i <= n; i++) //遍历used数组(分支)  寻找未使用过的数字, 并使用该数字
	{
		if (used[i] == false)
		{
			used[i] = true;
			state[u] = i;
			dfs(u + 1);

			//递归回来后恢复现场 
			used[i] = false;
			state[u] = 0;
		}
	}

}

int main()
{
	scanf("%d", &n);
	dfs(1);         //从1开始,与层数对应:  1==第一层    

	return 0;
}
