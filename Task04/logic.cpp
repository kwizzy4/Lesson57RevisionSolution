// Task 04 [The Sum of elements of columns with extreme elements]
// Сумма элементов столбцов с экстремальными элементами
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию (или программу), которая 
// высчитывает сумму элементов в тех столбцах заданной матрицы,
// которые содержат хотя бы один экстремальный элемент.

#include "logic.h"

int sum_elements_of_columns_with_extreme_value(int matrix[DEFAULT_SIZE][DEFAULT_SIZE], int n, int m) {
	if (n == 0 || m == 0) {
		return 0;
	}

	int min_val = matrix[0][0];
	int max_val = matrix[0][0];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] < min_val) {
				min_val = matrix[i][j];
			}
			if (matrix[i][j] > max_val) {
				max_val = matrix[i][j];
			}
		}
	}
	bool column_has_extreme[DEFAULT_SIZE] = { false };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == min_val || matrix[i][j] == max_val) {
				column_has_extreme[j] = true;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (column_has_extreme[j]) {
				sum += matrix[i][j];
			}
		}
	}
	return sum;
}