// UnionsProject.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

enum class Color { Красный, Оранжевый, Желтый, Зеленый, Голубой, Синий, Фиолетовый};

struct Circle {
    double radius;
    Color color;
};

struct Rectangle {
    double length;
    double width;
    Color color;
};

struct Triangle {
    double S_circle;
    double b;
    double c;
    Color color;
};

union Shape {
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;
};

int main() {
    setlocale(LC_ALL, "rus");
    Shape shapes[3];
    shapes[0].triangle = { 3, 4, 5, Color::Красный };
    shapes[1].circle = { 2.5, Color::Синий };     
    shapes[2].rectangle = { 2, 4, Color::Зеленый };  
    double S_circle = 3.1415926535 * shapes[1].circle.radius * shapes[1].circle.radius;
    double S_rectangle = shapes[2].rectangle.length * shapes[2].rectangle.width;
    double polu_perimetr = (shapes[0].triangle.S_circle + shapes[0].triangle.b + shapes[0].triangle.c) / 2;
    double S_triangle = sqrt(polu_perimetr * (polu_perimetr - shapes[0].triangle.S_circle) * (polu_perimetr - shapes[0].triangle.b) * (polu_perimetr - shapes[0].triangle.c));
    std::cout << "Площадь круга: " << S_circle << "\nПлощадь прямоугольника: " << S_rectangle << "\nПлощадь треугольника: " << S_triangle;
    if (S_circle > S_rectangle) {
        double temp = S_circle;
        S_circle = S_rectangle;
        S_rectangle = temp;
    }
    if (S_rectangle > S_triangle) {
        double temp = S_rectangle;
        S_rectangle = S_triangle;
        S_triangle = temp;
    }
    if (S_circle > S_rectangle) {
        double temp = S_circle;
        S_circle = S_rectangle;
        S_rectangle = temp;
    }
    std::cout << "\nПлощади по возрастанию: " << S_circle << "; " << S_rectangle << "; " << S_triangle;
}






// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
