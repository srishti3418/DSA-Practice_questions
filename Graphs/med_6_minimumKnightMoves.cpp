
//TC: O(N^2)
//SC :O(N^2)
class Solution
{
public:
	//Function to find out minimum steps Knight needs to reach target position.
	bool isValid(int n, int x, int y)
	{
		return (x >= 0 && x < n && y >= 0 && y < n);
	}

	int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n)
	{
		// Code here
		int x1 = KnightPos[0];
		int y1 = KnightPos[1];
		int x2 = TargetPos[0];
		int y2 = TargetPos[1];

		if (x1 == y1 && x2 == y2)
			return 0;

		vector<vector<int>> a(n, vector<int>(n, 0));

		int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
		int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

		queue<pair<int, int>> q;
		q.push(make_pair(x1 - 1, y1 - 1));
		while (!q.empty())
		{
			auto curr = q.front();
			int x = curr.first;
			int y = curr.second;
			if (x == x2 - 1 && y == y2 - 1)
				break;
			for (int k = 0; k < 8; k++)
			{
				if (isValid(n, x + dx[k], y + dy[k]) && a[x + dx[k]][y + dy[k]] == 0)
				{
					a[x + dx[k]][y + dy[k]] = a[x][y] + 1;
					q.push(make_pair(x + dx[k], y + dy[k]));
				}
			}
			q.pop();
		}
		return a[x2 - 1][y2 - 1];
	}
};