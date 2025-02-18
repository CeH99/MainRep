import java.util.Scanner;
import java.util.Random;

public class Matrix {
    private int rows;
    private int cols;
    private int[][] data;

    public Matrix(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        this.data = new int[rows][cols];
    }

    public int getRows() {
        return rows;
    }

    public void setRows(int rows) {
        this.rows = rows;
    }

    public int getCols() {
        return cols;
    }

    public void setCols(int cols) {
        this.cols = cols;
    }

    public int[][] getData() {
        return data;
    }

    public void setData(int[][] data) {
        this.data = data;
    }

    public void fillMatrix() {
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < rows; i++) {
            System.out.printf("Enter elements of row number %d: \n", i + 1);
            for (int j = 0; j < cols; j++) {
                System.out.printf("Enter element number %d: \n", j + 1);
                data[i][j] = scanner.nextInt();
            }
            System.out.println();
        }
    }

    public void fillMatrixRandom() {
        Random random = new Random();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = random.nextInt(100);
            }
        }
    }


    public void printMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(data[i][j] + " ");
            }
            System.out.println();
        }
    }

    public Matrix sumMatrix(Matrix a, Matrix b) {
        if (a.rows != b.rows || a.cols != b.cols) {
            throw new IllegalArgumentException("Matrix must be the same size");
        }

        Matrix result = new Matrix(a.rows, a.cols);
        for (int i = 0; i < a.rows; i++) {
            for (int j = 0; j < a.cols; j++) {
                result.data[i][j] = a.data[i][j] + b.data[i][j];
            }
        }
        return result;
    }

    public Matrix subMatrix(Matrix a, Matrix b) {
        if (a.rows != b.rows || a.cols != b.cols) {
            throw new IllegalArgumentException("Matrix must be the same size");
        }

        Matrix result = new Matrix(a.rows, a.cols);
        for (int i = 0; i < a.rows; i++) {
            for (int j = 0; j < a.cols; j++) {
                result.data[i][j] = a.data[i][j] - b.data[i][j];
            }
        }
        return result;
    }

    public Matrix multiplyMatrix(Matrix a, Matrix b) {
        if (a.cols != b.rows)
            throw new IllegalArgumentException("The number of columns of the first matrix must be equal to the row value of the second matrix");

        Matrix result = new Matrix(a.rows, b.cols);

        for (int i = 0; i < a.rows; i++) {
            for (int j = 0; j < b.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < a.cols; k++) {
                    result.data[i][j] += a.data[i][k] * b.data[k][j];
                }
            }
        }
        return result;
    }

    public Matrix multiplyByScalar(int scalar) {
        Matrix result = new Matrix(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = this.data[i][j] * scalar;
            }
        }
        return result;
    }

    public Matrix transpose() {
        Matrix result = new Matrix(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[j][i] = this.data[i][j];
            }
        }
        return result;
    }

    public boolean areEquals(Matrix b) {
        if (this.rows != b.rows || this.cols != b.cols) {
            return false;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (this.data[i][j] != b.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    public boolean isSquare() {
        return rows == cols;
    }

    public boolean isSymmetricMainDiagonal() {
        if (!isSquare()) return false;

        for (int i = 0; i < rows; i++) {
            for (int j = i + 1; j < cols; j++) {
                if (data[i][j] != data[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }

    public boolean isSymmetricSecondaryDiagonal() {
        if (!isSquare()) return false;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (data[i][j] != data[rows - 1 - j][cols - 1 - i]) {
                    return false;
                }
            }
        }
        return true;
    }
}