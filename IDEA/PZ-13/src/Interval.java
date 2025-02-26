public class Interval {
    private double left;
    private double right;

    public Interval(double left, double right) {
        if (left > right) {
            throw new IllegalArgumentException("Ліва межа не може бути більшою за праву.");
        }
        this.left = left;
        this.right = right;
    }

    public double getLeft() {
        return left;
    }

    public double getRight() {
        return right;
    }

    public void setLeft(double left) {
        if (left > this.right) {
            throw new IllegalArgumentException("Ліва межа не може бути більшою за праву.");
        }
        this.left = left;
    }

    public void setRight(double right) {
        if (right < this.left) {
            throw new IllegalArgumentException("Права межа не може бути меншою за ліву.");
        }
        this.right = right;
    }

    public double length() {
        return right - left;
    }

    public void shift(double value) {
        this.left += value;
        this.right += value;
    }

    public void scale(double factor) {
        double center = (left + right) / 2;
        double halfLength = (right - left) / 2 * factor;
        this.left = center - halfLength;
        this.right = center + halfLength;
    }

    public boolean equals(Interval other) {
        return this.left == other.left && this.right == other.right;
    }

    public Interval add(Interval other) {
        return new Interval(Math.min(this.left, other.left), Math.max(this.right, other.right));
    }

    public Interval subtract(Interval other) {
        return new Interval(this.left - other.left, this.right - other.right);
    }

    @Override
    public String toString() {
        return "[" + left + ", " + right + "]";
    }
}
