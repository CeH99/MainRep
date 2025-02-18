using System;

namespace Functions
{
    public enum SortOrder { Ascending, Descending }
    public static class DemoFunction
    {
        // TASK 1
        public static bool IsSorted(int[] array, SortOrder order)
        {
            if (order == SortOrder.Ascending)
            {
                for (int i = 0; i < array.Length - 1; i++)
                {
                    if (array[i + 1] < array[i])
                        return false;
                }
                return true;
            }
            else
            {
                for (int i = 0; i < array.Length - 1; i++)
                {
                    if (array[i + 1] > array[i])
                        return false;
                }
                return true;
            }
        }

        // Task 2
        public static void Transform(int[] array, SortOrder order)
        {
            if (IsSorted(array, order))
            {
                for (int i = 0; i < array.Length; i++)
                {
                    array[i] += i;
                }
            }
        }

        // Task 3
        public static double MultArithmeticElements(double a, double t, int n)
        {
            if (n <= 0) return 0.0;
            double result = 1.0;

            for (int i = 0; i < n; i++)
            {
                result *= (a + (i * t));
            }

            return result;
        }

        // Task 4
        public static double SumGeometricElements(double a, double t, double alim)
        {
            if (t < 0 || t > 1) return 0.0;

            double result = a;

            while ((a * t) > alim)
            {
                result += a * t;
                a *= t;
            }

            return result;
        }

        public static void Main(string[] args)
        {
            System.Console.WriteLine(MultArithmeticElements(5, 3, 4));
        }
    }
}


