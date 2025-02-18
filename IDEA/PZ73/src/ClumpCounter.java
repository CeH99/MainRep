public class ClumpCounter {
    public int countClumps(int[] nums) {
        int count = 0;
        boolean inClump = false;

        for (int i = 1; i < nums.length; i++) {
            // Перевіряємо, чи поточний і попередній елемент однакові
            if (nums[i] == nums[i - 1]) {
                if (!inClump) {
                    count++; // Знайшли нову групу
                    inClump = true; // Встановлюємо, що ми в групі
                }
            } else {
                inClump = false;
            }
        }

        return count;
    }
}
