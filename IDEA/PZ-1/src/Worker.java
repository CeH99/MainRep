public class Worker {
    private String givenName;
    private String familyName;
    private double ratePerDay;
    private int workedDays;

    public Worker(String givenName, String familyName, double ratePerDay, int workedDays) {
        this.givenName = givenName;
        this.familyName = familyName;
        this.ratePerDay = ratePerDay;
        this.workedDays = workedDays;
    }

    public Worker(String givenName, String familyName) {
        this.givenName = givenName;
        this.familyName = familyName;
        this.ratePerDay = 0.0;
        this.workedDays = 0;
    }

    public String getGivenName() {
        return givenName;
    }

    public void setGivenName(String givenName) {
        this.givenName = givenName;
    }

    public String getFamilyName() {
        return familyName;
    }

    public void setFamilyName(String familyName) {
        this.familyName = familyName;
    }

    public double getRatePerDay() {
        return ratePerDay;
    }

    public void setRatePerDay(double ratePerDay) {
        this.ratePerDay = ratePerDay;
    }

    public int getWorkedDays() {
        return workedDays;
    }

    public void setWorkedDays(int workedDays) {
        this.workedDays = workedDays;
    }

    public double computeSalary() {
        return ratePerDay * workedDays;
    }

    public void displayWorkedDays() {
        System.out.println("Кількість відпрацьованих днів: " + workedDays);
    }

    public void compareEarningsWith(Worker otherWorker) {
        double salary1 = this.computeSalary();
        double salary2 = otherWorker.computeSalary();

        if (salary1 > salary2) {
            System.out.println(this.givenName + " " + this.familyName + " має вищу зарплату (" + salary1 + ") ніж " +
                    otherWorker.givenName + " " + otherWorker.familyName + " (" + salary2 + ").");
        } else if (salary1 < salary2) {
            System.out.println(otherWorker.givenName + " " + otherWorker.familyName + " має вищу зарплату (" + salary2 + ") ніж " +
                    this.givenName + " " + this.familyName + " (" + salary1 + ").");
        } else {
            System.out.println(this.givenName + " " + this.familyName + " і " + otherWorker.givenName + " " +
                    otherWorker.familyName + " мають однакову зарплату (" + salary1 + ").");
        }
    }
}

