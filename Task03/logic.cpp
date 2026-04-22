// Task 03 [The Number of rows with a large number of positive elements]
// Количество строк с большим количество положительных элементов
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию (или программу), которая находит
// количество строк, в которых положительных элементов больше 
// чем всех остальных (отрицательных и нулевых).

#include "logic.h"

int count_rows_with_more_positive_values(int matrix[DEFAULT_SIZE][DEFAULT_SIZE], int n, int m) {
	int count_rows = 0;

	for (int i = 0; i < n; i++) {
		int positive_count = 0;
		int non_positive_count = 0;

		for (int j = 0; j < m; j++) {
			if (matrix[i][j] > 0) {
				positive_count++;
			}
			else {
				non_positive_count++;
			}
		}
		if (positive_count > non_positive_count) {
			count_rows++;
		}
	}
	return count_rows;
}