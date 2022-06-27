#include <stdio.h>

int main()
{
	int n;
	int arr[10001] = { 0 };

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int index;
		scanf("%d", &index);

		arr[index]++;
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < arr[i]; j++) {
			printf("%d\n", i);
		}
	}

	return 0;
}