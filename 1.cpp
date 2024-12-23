#include <iostream>
#include <cmath>
using namespace std;
//функция для вывода матрицы
void Matrix(double** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void Gauss(double** matrix, int n) {

    for (int i = 0; i < n; ++i) {
 
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (fabs(matrix[k][i]) > fabs(matrix[maxRow][i])) {
                maxRow = k;
            }
        }
        //перестановка строк
        if (maxRow != i) {
            for (int j = 0; j < n + 1; ++j) {
                double temp = matrix[i][j];
                matrix[i][j] = matrix[maxRow][j];
                matrix[maxRow][j] = temp;
            }
        }
        double norm = matrix[i][i];
        for (int j = 0; j < n + 1; ++j) {
            matrix[i][j] /= norm;
        }
        for (int k = i + 1; k < n; ++k) {
            double factor = matrix[k][i];
            for (int j = 0; j < n + 1; ++j) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
    double* x = new double[n];
    for (int i = n - 1; i >= 0; --i) {
        x[i] = matrix[i][n];
        for (int k = i - 1; k >= 0; --k) {
            matrix[k][n] -= matrix[k][i] * x[i];
        }
    }
    //вывод решения
    cout << "Решение системы уравнений:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
    delete[] x;
}
int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите количество уравнений: ";
    cin >> n;
    double** matrix = new double* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new double[n + 1];
    }
    cout << "Введите коэффициенты системы уравнений:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            cout << "a" << i + 1 << j + 1 << " = ";
            cin >> matrix[i][j];
        }
    }
    cout << "Матрица коэффициентов:" << endl;
    Matrix(matrix, n);
    Gauss(matrix, n);

    return 0;
}