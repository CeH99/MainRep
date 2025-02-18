public class Manager extends Employee {
    private int numberOfEngineers;
    private int numberOfMechanics;
    private int numberOfArchitects;

    public Manager(String name, int experience, int numberOfEngineers, int numberOfMechanics, int numberOfArchitects) {
        super(name, experience);
        this.numberOfEngineers = numberOfEngineers;
        this.numberOfMechanics = numberOfMechanics;
        this.numberOfArchitects = numberOfArchitects;
    }

    @Override
    public double getSalary() {
        return 5000 + experience * 200 + (numberOfEngineers + numberOfMechanics + numberOfArchitects) * 100;
    }

    public int getTotalSubordinates() {
        return numberOfEngineers + numberOfMechanics + numberOfArchitects;
    }
}

