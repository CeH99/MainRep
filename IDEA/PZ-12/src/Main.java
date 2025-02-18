public class Main {
    public static void main(String[] args) {
        Engineer engineer = new Engineer("Dave", 5);
        Mechanic mechanic = new Mechanic("Oleg", 3);
        Architect architect = new Architect("Paul", 7);
        Manager manager = new Manager("Piter", 10, 1, 1, 1);

        System.out.println("Зарплата менеджера " + manager.getName() + ":" + manager.getSalary());
        System.out.println("Кількість підлеглих у менеджера: " + manager.getTotalSubordinates() + "\n");

        System.out.println("Зарплата інженера " + engineer.getName() + ":" + engineer.getSalary());
        System.out.println("Кількість днів щорічної відпустки інженера: " + engineer.getVacationDays() + "\n");

        System.out.println("Зарплата механіка " + mechanic.getName() + ":" + mechanic.getSalary());
        System.out.println("Зарплата архітектора " + architect.getName() + ":" + architect.getSalary());
    }
}
