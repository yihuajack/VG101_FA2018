#include<stdio.h>
#include<math.h>
int main() {
	int i, j, k = 0, d1, d2, d3, n, s, t, p, q, min = 1000000, max = 0,arr[10000][2], sign = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d %d", &arr[i][0], &arr[i][1]);
	while (k < n) {
		j = k;
		for (i = k + 1; i < n; i++)
			if (arr[i][0] < arr[j][0]) j = i;
		s = arr[k][0]; t = arr[k][1];
		arr[k][0] = arr[j][0]; arr[k][1] = arr[j][1];
		arr[j][0] = s; arr[j][1] = t;
		k++;
	}
	for (i = 0; i < n; i++) {
		if (arr[i][0] > max) max = arr[i][0];
		if (arr[i][0] < min) min = arr[i][0];
	}
	i = 0; k = 0;
	for (j = min; j <= max; j++) {
		while (arr[i + k][0] == j) k++;
		for (p = 0; p < k - 1; p++) {
			for (q = i; q < i + k - p - 1; q++) {
				if (arr[q][1] > arr[q + 1][1]) {
					s = arr[q + 1][0]; t = arr[q + 1][1];
					arr[q + 1][0] = arr[q][0]; arr[q + 1][1] = arr[q][1];
					arr[q][0] = s; arr[q][1] = t;
				}
			}
		}
		i += k; k = 0;
	}
	t = 0;
	for (i = 0; i < n - 1; i++) {
		if (arr[i][0] == arr[i + 1][0]) {
			for (j = i + 2; j < n - 1; j++) {
				if (arr[j][1] == arr[i][1] && arr[j + 1][1] == arr[i+1][1] && arr[j][0] == arr[j + 1][0]) {
					for (k = i + 2; k < j; k++) {
						if (arr[k][1] == arr[i][1] || arr[k][1] == arr[i+1][1]) sign = 1;
					}
					if (sign == 1) sign = 0;
					else { t++; sign = 0; }
				}
			}
		}
	}
	printf("%d\n", t);
	return 0;
}