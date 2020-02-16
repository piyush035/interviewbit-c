#include <stdio.h>

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 *
 * @Output Integer
 */
int coverPoints(int *A, int n1, int *B, int n2) {
	if (n1 != n2) {
		return 0;
	}
	int distance = 0, i = 0;
	for (i = 0; i < n1 - 1; i++) {
		int diffA = A[i + 1] - A[i];
		int diffB = B[i + 1] - B[i];
		if (diffA < 0) {
			diffA = diffA * (-1);
		}
		if (diffB < 0) {
			diffB = diffB * (-1);
		}
		if (diffA > diffB) {
			distance += diffA;
		} else {
			distance += diffB;
		}
	}
	return distance;
}

/*int main() {
	 printf function displays the content that is
	 * passed between the double quotes.

	int A[3] = { 0, 1, 1 };
	int B[3] = { 0, 1, 2 };
	int result = coverPoints(A, 3, B, 3);
	printf("%d ", result);
	return 0;
}*/
