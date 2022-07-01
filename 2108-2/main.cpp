// https://www.acmicpc.net/problem/2108
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n;
	int sum = 0, mode = 0, mode_value = 0;	// ������ - ����, �ֺ�, �ֺ��� �� ��
	bool is_second = false;					// �ֺ� - ���ǿ���, �� ��° ������ �Ǻ��ϱ� ���� ����
	int count[8001] = { 0, };				// �ֺ��� �����ϱ� ���� �迭

	cin >> n;

	int* arr = new int[n];

	// �� �Է� �� ���� ���
	for (int i = 0; i < n; i++)
	{
		int input;

		cin >> input;

		sum += input;
		arr[i] = input;
		count[input + 4000]++;
	}

	// ����
	sort(arr, arr + n);

	// �ֺ� ���
	for (int i = 0; i < 8001; i++)
	{
		if (count[i] == 0)
			continue;

		else if (count[i] > mode_value)
		{
			mode = i - 4000;
			mode_value = count[i];
			is_second = true;
		}

		else if (count[i] == mode_value)
		{
			if (is_second) 
			{
				mode = i - 4000;
				mode_value = count[i];
				is_second = false;
			}
		}
	}

	// ���
	cout << (int)round((double)sum / (double)n) << endl;	// ������
	cout << arr[n / 2] << endl;								// �߾Ӱ�
	cout << mode << endl;									// �ֺ�
	cout << arr[n - 1] - arr[0] << endl;					// ����

	delete[] arr;

	return 0;
}