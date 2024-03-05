#include <iostream>
#include <algorithm>
#include <vector>

#include "../../../include/reverseTranspose.hpp"

void reverseTranspose(std::vector<std::vector<int>>& matrix) {
    int baris = matrix.size();
    int kolom = matrix[0].size();

    int x;

    // Kita putar-balikkan urutan elementnya agar bisa ditranspose searah jarum jam
    std::reverse(matrix.begin(), matrix.end());

    // Function untuk mentranspose Matrix
    for (int i = 0; i < baris; ++i) {
        for (int j = i + 1; j < kolom; ++j) {
            x = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = x;
        }
    }
}

