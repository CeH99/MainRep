public class Main {
    public static void main(String[] args) {
        Worker worker1 = new Worker("Питер", "Паркер", 6000, 20);
        Worker worker2 = new Worker("Петро", "Петрович", 6000, 20);
        Worker worker3 = new Worker("Тони", "Старк", 75000.33, 30);


        System.out.println(worker1.getGivenName() + " " + worker1.getFamilyName());
        worker1.displayWorkedDays();

        System.out.println(worker2.getGivenName() + " " + worker2.getFamilyName());
        worker2.displayWorkedDays();

        System.out.println(worker3.getGivenName() + " " + worker3.getFamilyName());
        worker3.displayWorkedDays();

        System.out.println("Зарплата " + worker1.getGivenName() + ": " + worker1.computeSalary());
        System.out.println("Зарплата " + worker2.getGivenName() + ": " + worker2.computeSalary());
        System.out.println("Зарплата " + worker3.getGivenName() + ": " + worker2.computeSalary());

        System.out.println("--------------------------------------");

        worker1.compareEarningsWith(worker2);
        worker1.compareEarningsWith(worker3);
    }
}
