// https://www.acmicpc.net/problem/11650
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	vector<pair<int, int>> points;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y;

		cin >> x >> y;

		points.push_back(pair<int, int>(x, y));
	}

	sort(points.begin(), points.end());

	for (int i = 0; i < n; i++)
	{
		cout << points[i].first << " " << points[i].second << "\n";
	}

	return 0;
}