
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void readMatrix(double a[][20], int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
}

void printMatrix(double a[][20], int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("%10.4f ", a[i][j]);
        }
        printf("\n");
    }
}

void addMatrices() {
    int r, c;
    double a[20][20], b[20][20], sum[20][20];
    printf("Matrix addition (max 20x20).\n");
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    if (r <= 0 || r > 20 || c <= 0 || c > 20) {
        printf("Invalid size.\n");
        return;
    }
    printf("First matrix:\n");
    readMatrix(a, r, c);
    printf("Second matrix:\n");
    readMatrix(b, r, c);
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            sum[i][j] = a[i][j] + b[i][j];

    printf("Sum matrix:\n");
    printMatrix(sum, r, c);
}

void saddlePoint() {
    int r, c;
    double a[20][20];
    printf("Saddle point (max of row-min and min of col-max).\n");
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    if (r <= 0 || r > 20 || c <= 0 || c > 20) {
        printf("Invalid size.\n");
        return;
    }
    readMatrix(a, r, c);

    int found = 0;
    for (int i = 0; i < r; ++i) {
        double rowMin = a[i][0];
        int minCol = 0;
        for (int j = 1; j < c; ++j) {
            if (a[i][j] < rowMin) {
                rowMin = a[i][j];
                minCol = j;
            }
        }
        double colMax = a[0][minCol];
        for (int k = 1; k < r; ++k) {
            if (a[k][minCol] > colMax) {
                colMax = a[k][minCol];
            }
        }
        if (fabs(rowMin - colMax) < 1e-9) {
            printf("Saddle point found at [%d][%d] = %.4f\n", i, minCol, rowMin);
            found = 1;
        }
    }
    if (!found) {
        printf("No saddle point in the matrix.\n");
    }
}

int inverseMatrix() {
    int n;
    double aug[20][40];
    printf("Matrix inverse (Gauss-Jordan, max 20x20).\n");
    printf("Enter dimension n (n x n): ");
    scanf("%d", &n);
    if (n <= 0 || n > 20) {
        printf("Invalid size.\n");
        return 0;
    }

    printf("Enter matrix values:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%lf", &aug[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            aug[i][j+n] = (i == j) ? 1.0 : 0.0;
    }

    for (int i = 0; i < n; ++i) {
        double pivot = aug[i][i];
        int pivotRow = i;
        for (int r = i + 1; r < n; ++r) {
            if (fabs(aug[r][i]) > fabs(pivot)) {
                pivot = aug[r][i];
                pivotRow = r;
            }
        }
        if (fabs(pivot) < 1e-12) {
            printf("Matrix is singular and not invertible.\n");
            return 0;
        }
        if (pivotRow != i) {
            for (int k = 0; k < 2 * n; ++k) {
                double tmp = aug[i][k];
                aug[i][k] = aug[pivotRow][k];
                aug[pivotRow][k] = tmp;
            }
        }

        pivot = aug[i][i];
        for (int k = 0; k < 2 * n; ++k) {
            aug[i][k] /= pivot;
        }

        for (int r = 0; r < n; ++r) {
            if (r != i) {
                double factor = aug[r][i];
                for (int k = 0; k < 2 * n; ++k) {
                    aug[r][k] -= factor * aug[i][k];
                }
            }
        }
    }

    printf("Inverse matrix:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%12.6f ", aug[i][j+n]);
        }
        printf("\n");
    }
    return 1;
}

int isMagicSquare() {
    int n;
    double a[20][20];
    printf("Magic square check (n x n).\n");
    printf("Enter n: ");
    scanf("%d", &n);
    if (n <= 0 || n > 20) {
        printf("Invalid n.\n");
        return 0;
    }

    printf("Enter matrix values:\n");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%lf", &a[i][j]);

    long long target = 0;
    for (int j = 0; j < n; ++j)
        target += (long long)round(a[0][j]);

    for (int i = 1; i < n; ++i) {
        long long rowSum = 0;
        for (int j = 0; j < n; ++j)
            rowSum += (long long)round(a[i][j]);
        if (rowSum != target) {
            printf("Not a magic square (row %d sum mismatch).\n", i);
            return 0;
        }
    }

    for (int j = 0; j < n; ++j) {
        long long colSum = 0;
        for (int i = 0; i < n; ++i)
            colSum += (long long)round(a[i][j]);
        if (colSum != target) {
            printf("Not a magic square (column %d sum mismatch).\n", j);
            return 0;
        }
    }

    long long diag1 = 0, diag2 = 0;
    for (int i = 0; i < n; ++i) {
        diag1 += (long long)round(a[i][i]);
        diag2 += (long long)round(a[i][n - 1 - i]);
    }
    if (diag1 != target || diag2 != target) {
        printf("Not a magic square (diagonal sum mismatch).\n");
        return 0;
    }

    long long minv = (long long)round(a[0][0]);
    long long maxv = minv;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            long long v = (long long)round(a[i][j]);
            if (v < minv) minv = v;
            if (v > maxv) maxv = v;
        }

    if (maxv - minv + 1 != n * n) {
        printf("Not a normal magic square (not continuous values).\n");
        return 0;
    }

    int seen[400] = {0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int idx = (int)(round(a[i][j]) - minv);
            if (idx < 0 || idx >= n * n) {
                printf("Not a normal magic square (value out of range).\n");
                return 0;
            }
            if (seen[idx]) {
                printf("Not a normal magic square (duplicate value).\n");
                return 0;
            }
            seen[idx] = 1;
        }
    }

    printf("It is a magic square.\n");
    return 1;
}

int main() {
    int choice;
    while (1) {
        printf("\nMatrix operations menu:\n");
        printf("1. Add 2 matrices\n");
        printf("2. Find saddle point\n");
        printf("3. Find inverse of a matrix\n");
        printf("4. Magic square check\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMatrices();
                break;
            case 2:
                saddlePoint();
                break;
            case 3:
                inverseMatrix();
                break;
            case 4:
                isMagicSquare();
                break;
            case 5:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
