import java.util.Objects;

class Clothing {
    protected String brand;
    protected String size;
    protected String color;

    protected Clothing(String brand, String size, String color) {
        this.brand = brand;
        this.size = size;
        this.color = color;
    }

    void chooseClothing() {
        System.out.println("You choosed : " + this);
    }

    void wear() {
        System.out.println("You put on: " + this);
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Clothing clothing = (Clothing) o;
        return Objects.equals(brand, clothing.brand) && Objects.equals(size, clothing.size) && Objects.equals(color, clothing.color);
    }

    public int hashCode() {
        return Objects.hash(brand, size, color);
    }

    public String toString() {
        return getClass().getSimpleName() + "{brand='" + brand + "', size='" + size + "', color='" + color + "'}";
    }
}

class Jacket extends Clothing {
    Jacket(String brand, String size, String color) {
        super(brand, size, color);
    }

    @Override
    public boolean equals(Object o) {
        return super.equals(o);
    }

    @Override
    public int hashCode() {
        return super.hashCode();
    }
}

class Shirt extends Clothing {
    Shirt(String brand, String size, String color) {
        super(brand, size, color);
    }

    @Override
    public boolean equals(Object o) {
        return super.equals(o);
    }

    @Override
    public int hashCode() {
        return super.hashCode();
    }
}

class Pants extends Clothing {
    Pants(String brand, String size, String color) {
        super(brand, size, color);
    }

    @Override
    public boolean equals(Object o) {
        return super.equals(o);
    }

    @Override
    public int hashCode() {
        return super.hashCode();
    }
}

class Shoes extends Clothing {
    Shoes(String brand, String size, String color) {
        super(brand, size, color);
    }

    @Override
    public boolean equals(Object o) {
        return super.equals(o);
    }

    @Override
    public int hashCode() {
        return super.hashCode();
    }
}
