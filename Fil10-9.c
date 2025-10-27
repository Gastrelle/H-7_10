#include <stdio.h>
#include <math.h>
#include <locale.h>

// Функции для вычисления площади
float area_round(float r);
float area_rectangle(float a, float b);
float area_triangle(float a, float b, float c);
float area_golden_rectangle(float a);


// Функции для рисования фигур
void draw_rectangle(int a, int b);

//функция для рисования круга
void draw_round(char symbol);

// Функция для рисовния золотого прямоугольника
void draw_golden_rectangle(int short_side, char symbol);

// Функция для вывода определения фигуры
void definition(int sides);

int main() {
    setlocale(LC_CTYPE, "RUS");

    int choice;
    char symbol;
    int side, side2, side3;
    float radius;

    printf("Выберите операцию:\n");
    printf("1 - Нарисовать фигуру\n");
    printf("2 - Вывести определение фигуры\n");
    printf("3 - Рассчитать площадь фигуры\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: // Рисование фигуры
        printf("Выберите фигуру для рисования:\n");
        printf("1 - Прямоугольник\n");
        printf("2 - Круг\n");
        printf("3 - Золотой прямоугольник\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Введите ширину и высоту прямоугольника: ");
            scanf("%d %d", &side, &side2);
            draw_rectangle(side, side2);
            break;
        case 2:
            printf("Введите символ для рисования: ");
            scanf(" %c", &symbol);
            draw_round(symbol);
            break;
        case 3:
            printf("Введите символ для рисования: ");
            scanf(" %c", &symbol);
            printf("Введите размер короткой стороны: ");
            scanf("%d", &side);
            draw_golden_rectangle(side, symbol);
            break;
        default:
            printf("Неверный выбор!\n");
        }
        break;

    case 2: // Определение фигуры
        printf("Введите количество сторон (0 для круга, 1 для золотого прямоугольника): ");
        scanf("%d", &side);
        definition(side);
        break;

    case 3: // Расчет площади
        printf("Выберите фигуру:\n");
        printf("1 - Круг\n");
        printf("2 - Прямоугольник\n");
        printf("3 - Треугольник\n");
        printf("4 - Золотой прямоугольник\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Введите радиус круга: ");
            scanf("%f", &radius);
            printf("Площадь круга: %.2f\n", area_round(radius));
            break;
        case 2:
            printf("Введите длину и ширину прямоугольника: ");
            scanf("%d %d", &side, &side2);
            printf("Площадь прямоугольника: %.2f\n", area_rectangle(side, side2));
            break;
        case 3:
            printf("Введите три стороны треугольника: ");
            scanf("%d %d %d", &side, &side2, &side3);
            printf("Площадь треугольника: %.2f\n", area_triangle(side, side2, side3));
            break;
        case 4:
            printf("Введите короткую сторону золотого прямоугольника: ");
            scanf("%d", &side);
            printf("Площадь золотого прямоугольника: %.2f\n", area_golden_rectangle(side));
            break;
        default:
            printf("Неверный выбор!\n");
        }
        break;

    default:
        printf("Неверный выбор!\n");
    }

    return 0;
}

float area_round(float r) {
    return 3.14159 * r * r;
}
float area_rectangle(float a, float b) {
    return a * b;
}
float area_triangle(float a, float b, float c) {
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
float area_golden_rectangle(float a) {
    float b = a * 1.618; // Вторая сторона по золотому сечению
    return area_rectangle(a, b);
}
void draw_rectangle(int a, int b) {
    printf("\n");
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            if (i == 0 || i == b - 1 || j == 0 || j == a - 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
void draw_round(char symbol) {
    int radius = 8;
    printf("\n");
    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x * x + y * y <= radius * radius + radius * 0.5 &&
                x * x + y * y >= radius * radius - radius * 0.5) {
                printf("%c", symbol);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
void draw_golden_rectangle(int short_side, char symbol) {
    int long_side = (int)(short_side * 1.618);
    printf("\nЗолотой прямоугольник %dx%d:\n", short_side, long_side);

    for (int i = 0; i < long_side; i++) {
        for (int j = 0; j < short_side; j++) {
            if (i == 0 || i == long_side - 1 || j == 0 || j == short_side - 1) {
                printf("%c", symbol);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
void definition(int sides) {
    printf("\nОпределение: ");
    switch (sides) {
    case 0:
        printf("Круг - множество точек на плоскости, равноудаленных от центра.\n");
        break;
    case 3:
        printf("Треугольник - геометрическая фигура с тремя сторонами и тремя углами.\n");
        break;
    case 4:
        printf("Прямоугольник - четырехугольник, у которого все углы прямые.\n");
        break;
    case 1:
        printf("Золотой прямоугольник - прямоугольник, отношение сторон которого равно золотому сечению (≈1.618).\n");
        printf("Если от него отрезать квадрат, останется снова золотой прямоугольник.\n");
        break;
    default:
        printf("Многоугольник с %d сторонами.\n", sides);
    }
}