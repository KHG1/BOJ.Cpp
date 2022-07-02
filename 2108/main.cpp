// https://www.acmicpc.net/problem/2108
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, i, j;
	int sum = 0, median, mode_index = 0, mode_value = 0;	// �������� ���� �հ�, �߾Ӱ� �ε���, �ֺ� �ε���, �ֺ� �� ��
	bool is_second = false;									// �ֺ� ���ǿ��� �ι�° �ֺ������� �Ǻ��ϱ� ���� ����
	int arr[8001] = { 0, };

	cin >> n;

	for (i = 0; i < n; i++) {
		int input;

		cin >> input;

		sum += input;										// �Է°� ���ÿ� ������ ����
		arr[input + 4000]++;
	}

	// �߾Ӱ�
	for (median = 0, i = -1; i < n / 2; median++) {
		for (int j = 0; j < arr[median]; j++) {
			i++;

			if (i == n / 2)
				break;
		}
	}

	// �ֺ�
	for (i = 0; i < 8001; i++) {
		if (!arr[i])
			continue;

		else if (arr[i] > mode_value) {
			mode_index = i;
			mode_value = arr[i];
			is_second = true;
		}

		else if (arr[i] == mode_value) {
			if (is_second) {
				mode_index = i;
				mode_value = arr[i];
				is_second = false;
			}
		}
	}

	// ����
	for (i = 0; !arr[i]; i++);
	for (j = 8000; !arr[j]; j--);

	// ���
	cout << (int)round((double)sum / n) << endl;
	cout << median - 4001 << endl;
	cout << mode_index - 4000 << endl;
	cout << (j - 4000) - (i - 4000) << endl;

	return 0;
}