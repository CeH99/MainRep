public abstract class Employee {
    protected String name;
    protected int experience;

    public Employee(String name, int experience) {
        this.name = name;
        this.experience = experience;
    }

    public abstract double getSalary();

    public String getName() {
        return name;
    }

    public int getExperience() {
        return experience;
    }
}

