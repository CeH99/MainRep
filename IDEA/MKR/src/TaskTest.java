import org.junit.Test;
import static org.junit.Assert.*;

public class TaskTest {

    @Test
    public void testFrontTimes() {
        Task task = new Task();

        // Тест для першого набору даних
        assertEquals("ChoCho", task.frontTimes("Chocolate", 2));

        // Тест для другого набору даних
        assertEquals("AppAppAppApp", task.frontTimes("Application", 4));

        // Тест для третього набору даних
        assertEquals("AbAbAb", task.frontTimes("Ab", 3));
    }

    @Test
    public void testCalcY() {
        Task task = new Task();

        // Тест для x = 0
        assertEquals(390.0, task.calcY(0), 0.001);

        // Тест для x = 1.2
        assertEquals(870.526, task.calcY(1.2), 0.001);

        // Тест для x = 2.8
        assertEquals(3112.54, task.calcY(2.8), 0.001);
    }
}
