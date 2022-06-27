// https://www.acmicpc.net/problem/10989

#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int arr[10001] = { 0 };
	// ���� ������ 10000���� �۰ų� ���� �ڿ����� ��õǾ����Ƿ�

	cin >> n;

	// ��� ����
	for (int i = 0; i < n; i++) {
		int index;
		cin >> index;

		arr[index]++;
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << i << "\n";
		}
	}

	return 0;
}