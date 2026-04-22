// Task 05 [The local maxima].
// Локальнык максимумы
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию (или программу), которая 
// находит локальные максимумы.

#include "util.h"

string get_all_local_maximums(int matrix[DEFAULT_SIZE][DEFAULT_SIZE], int n, int m) {
	string result = " ";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool is_local_max = true;

			if (i - 1 >= 0 && matrix[i][j] <= matrix[i - 1][j]) {
				is_local_max = false;
			}
			else if (i + 1 < n && matrix[i][j] <= matrix[i + 1][j]) {
				is_local_max = false;
			}
			else if (j - 1 >= 0 && matrix[i][j] <= matrix[i][j - 1]) {
				is_local_max = false;
			}
			else if (j + 1 < m && matrix[i][j] <= matrix[i][j - 1]) {
				is_local_max = false;
			}
			if (is_local_max) {
				if (!result.empty()) {
					result += " ";
				}
				result += "(" + to_string(i) + "," + to_string(j) + ")";
			}
		}
	}
	if (result.empty()) {
		result = "no elements";
	}
	return result;
}