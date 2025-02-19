import java.util.Scanner;
public class Lr11Koni {
    public static void main(String[] args) {
        Matrix a = new Matrix(3, 3);
        Matrix b = new Matrix(3, 3);
        Matrix c = new Matrix(3, 3);
        Matrix d = new Matrix(3, 3);
        a.fillMatrixRandom();
        b.fillMatrixRandom();
        c.fillMatrixRandom();
        d.fillMatrixRandom();

        System.out.println("Matrices: ");
        System.out.println('a');
        a.printMatrix();
        System.out.println('b');
        b.printMatrix();
        System.out.println('c');
        c.printMatrix();
        System.out.println('d');
        d.printMatrix();

        System.out.println("-------------METHOD-SUM-------------------");

        System.out.println("\nSum of a and b is: ");
        (a.sumMatrix(a, b)).printMatrix();
        System.out.println("\nSum of a and d is: ");
        (a.sumMatrix(a, d)).printMatrix();
        System.out.println("\nSum of c and b is: ");
        (c.sumMatrix(c, b)).printMatrix();



        System.out.println("-------------METHOD-SUB-------------------");

        System.out.println("\nSubtraction of a and b is: ");
        (a.subMatrix(a, b)).printMatrix();
        System.out.println("\nSubtraction of a and d is: ");
        (a.subMatrix(a, d)).printMatrix();
        System.out.println("\nSubtraction of c and b is: ");
        (c.subMatrix(c, b)).printMatrix();



        System.out.println("-------------METHOD-MULTIPLY-------------------");

        System.out.println("\nMultiplication of these a and b is: ");
        (a.multiplyMatrix(a, b)).printMatrix();
        System.out.println("\nMultiplication of these a and d is: ");
        (a.multiplyMatrix(a, d)).printMatrix();
        System.out.println("\nMultiplication of these c and b is: ");
        (c.multiplyMatrix(c, b)).printMatrix();



        System.out.println("-------------METHOD-MULTIPLY-BY-SCALAR-----------------");
        int scalar;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the scalar for multiplication:");
        scalar = scanner.nextInt();

        System.out.println("Multiplication of a, b and c by scalar is: ");
        System.out.println('a');
        (a.multiplyByScalar(scalar)).printMatrix();
        System.out.println('b');
        (b.multiplyByScalar(scalar)).printMatrix();
        System.out.println('c');
        (c.multiplyByScalar(scalar)).printMatrix();



        System.out.println("-------------METHOD-TRANSPOSE-------------------");

        System.out.println("\nTransposed matrix a: ");
        (a.transpose()).printMatrix();
        System.out.println("\nTransposed matrix b: ");
        (b.transpose()).printMatrix();
        System.out.println("\nTransposed matrix c: ");
        (c.transpose()).printMatrix();



        System.out.println("-------------METHOD-areEQUALS-------------------");
        if (!(a.areEquals(b)))
            System.out.println("a and b aren't equal!");
        else
            System.out.println("a and b are equal!");
        if (!(c.areEquals(d)))
            System.out.println("c and d aren't equal!");
        else
            System.out.println("c and d are equal!");
        if (!(a.areEquals(d)))
            System.out.println("a and d aren't equal!");
        else
            System.out.println("a and d are equal!");



        System.out.println("-------------METHOD-isSQUARE-------------------");
        if (!(a.isSquare()))
            System.out.println("a isn't square");
        else
            System.out.println("a is square");

        if (!(b.isSquare()))
            System.out.println("b isn't square");
        else
            System.out.println("b is square");
        if (!(c.isSquare()))
            System.out.println("c isn't square");
        else
            System.out.println("c is square");



        System.out.println("-------------METHOD-isSymmetricMainDiagonal-------------------");
        if (!(a.isSymmetricMainDiagonal()))
            System.out.println("a isn't symmetric along the main diagonal");
        else
            System.out.println("a is symmetric along the main diagonal");

        if (!(b.isSymmetricMainDiagonal()))
            System.out.println("b isn't symmetric along the main diagonal");
        else
            System.out.println("b is symmetric along the main diagonal");

        if (!(c.isSymmetricMainDiagonal()))
            System.out.println("c isn't symmetric along the main diagonal");
        else
            System.out.println("c is symmetric along the main diagonal");



        System.out.println("-------------METHOD-isSymmetricSecondaryDiagonal-------------------");
        if (!(a.isSymmetricSecondaryDiagonal()))
            System.out.println("a isn't symmetric along the secondary diagonal");
        else
            System.out.println("a is symmetric along the secondary diagonal");

        if (!(b.isSymmetricSecondaryDiagonal()))
            System.out.println("b isn't symmetric along the secondary diagonal");
        else
            System.out.println("b is symmetric along the secondary diagonal");
        if (!(c.isSymmetricSecondaryDiagonal()))
            System.out.println("c isn't symmetric along the secondary diagonal");
        else
            System.out.println("c is symmetric along the secondary diagonal");
    }
}
