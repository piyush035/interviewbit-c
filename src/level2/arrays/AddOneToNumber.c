#include <stdio.h>
#include <stdlib.h>

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* plusOne(int *A, int n1, int *len1) {
	int i, carry = 1, len = 0;
	int *result = (int*) malloc(sizeof(int) * (n1 + 1));
	int oind = n1;
	for (i = n1 - 1; i >= 0; i--) {
		result[oind--] = (A[i] + carry) % 10;
		carry = (A[i] + carry) / 10;
	}
	result[oind] = carry;
	for (i = 0; i < n1 + 1 && result[i] == 0; i++)
		len++;
	result = result + len;
	*len1 = n1 + 1 - len;
	return result;
}

int* plusOne(int* A, int n1, int *length_of_array)
{
	unsigned int i, start = 0, carry = 1, temp;

	// switch arr order
	for (i=0; i<n1/2; i++)
	{
		temp = A[i];
		A[i] = A[n1 - 1 - i];
		A[n1 - 1 - i] = temp;
	}

	// ignore zeros
	for (i = n1-1; i>0; i--)
	{
		if (A[i] > 0)
			break;
	}
	n1 = (i+1);

	// calculate
	temp = 1;
	for (i = 0; i < n1; i++)
	{
		temp += A[i];
		A[i] = temp % 10;
		temp = temp / 10;
	}

	if (temp > 0)
	{
		A[i] = temp;
		n1++;
	}

	// switch arr order
	for (i = 0; i<n1 / 2; i++)
	{
		temp = A[i];
		A[i] = A[n1 - 1 - i];
		A[n1 - 1 - i] = temp;
	}

	*length_of_array = n1;
	return A;
}

int main() {
	/* printf function displays the content that is
	 * passed between the double quotes.
	 */
	int A[3] = { 0, 1, 2 };
	int i = 0, length;
	int *result = plusOne(A, 3, &length);
	for (i = 0; i < length; i++)
		printf("%u\n", result[i]);
	return 0;
}
