#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 1000  

// Structure to represent a point in 2D space
typedef struct {
    int x;
    int y;
} Point;

// Simple hash function for 2D coordinates
unsigned int hash(Point p) {
    return (abs(p.x) * 31 + abs(p.y) * 17) % TABLE_SIZE; // Bcs its simple numbers(less number of colisions)
}

// Hash function for floating-point coordinates
unsigned int hash_float(float x, float y) {
    return (abs((int)(x * 1000)) * 31 + abs((int)(y * 1000)) * 17) % TABLE_SIZE;
}

// Hash function for polar coordinates
unsigned int hash_polar(float r, float theta) {
    return (abs((int)(r * 100)) * 31 + abs((int)(theta * 100)) * 17) % TABLE_SIZE;
}

// Hash function for 3D coordinates
unsigned int hash_3D(int x, int y, int z) {
    return (abs(x) * 31 + abs(y) * 17 + abs(z) * 13) % TABLE_SIZE;
}

int main() {
    Point p1 = {3, 4};
    Point p2 = {10, 20};
    Point p3 = {-7, 8};
    
    // Printing hash values for 2D points
    printf("Hash for Point(%d, %d): %u\n", p1.x, p1.y, hash(p1));
    printf("Hash for Point(%d, %d): %u\n", p2.x, p2.y, hash(p2));
    printf("Hash for Point(%d, %d): %u\n", p3.x, p3.y, hash(p3));
    
    float x = 3.1415, y = 2.718;
    // Printing hash value for floating-point coordinates
    printf("Hash for Float Coordinates(%.4f, %.4f): %u\n", x, y, hash_float(x, y));
    
    float r = 5.0, theta = 1.57;
    // Printing hash value for polar coordinates
    printf("Hash for Polar Coordinates(%.2f, %.2f): %u\n", r, theta, hash_polar(r, theta));
    
    int z = 7;
    // Printing hash value for 3D coordinates
    printf("Hash for 3D Coordinates(%d, %d, %d): %u\n", p1.x, p1.y, z, hash_3D(p1.x, p1.y, z));
    
    return 0;
}

/*
1. **Зміна типу координат (від int до float)**:
   - Якщо змінити тип координат на float, потрібно враховувати можливі помилки округлення.
   - Для унікального хешування можна помножити координати на масштабний коефіцієнт (наприклад, 1000) та привести їх до int.

2. **Зміна системи координат (Декартова -> Полярна)**:
   - Полярні координати (r, θ) можуть бути використані в хеш-функції, де r - модуль вектора, а θ - кут.
   - В цьому випадку хеш можна будувати на основі (int)(r * 100) та (int)(θ * 100).

3. **Зміна розмірності (2D -> 3D або більше)**:
   - Додаючи третю координату z, хеш можна змінити так: `hash = (x * 31 + y * 17 + z * 13) % TABLE_SIZE;`.
   - Для ще більшої розмірності можна комбінувати коефіцієнти для різних осей.

*/
