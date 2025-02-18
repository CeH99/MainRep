// Клас Engineer
public class Engineer extends Employee {
    private int days_of_weekend = 28;
    public Engineer(String name, int experience) {
        super(name, experience);
    }

    @Override
    public double getSalary() {
        return 3000 + experience * 150;
    }

    public int getVacationDays() {
        return days_of_weekend;
    }
}


