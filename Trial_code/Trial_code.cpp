#include <iostream>
#include <string>
#include <cmath>
#include <complex>
using namespace std;

class TrigonometricForm
{
protected:
    void trigonometricForm(double arr[2])
    {
        complex < double > z(arr[0], arr[1]);
        double rho = abs(z);
        double phi = arg(z);
        cout << endl << "Тригонометрическая форма." << endl;
        cout << "Модуль комплексного числа или радиус: " << rho << endl;
        cout << "Аргумент: " << phi << endl;
        cout << "cos(phi): " << cos(phi) << endl;
        cout << "sin(phi): " << sin(phi) << endl;
        cout << "Тригонометрическая форма комплексного числа: " << rho << "*(cos(" << phi << ") + i*sin(" << phi << "))" << endl;
        cout << "Показательная форма комплексного числа: " << rho << "*exp(i*" << phi << ")" << endl;
        cout << "Исходное комплексное число по модулю и аргументу: " << polar(rho, phi) << endl;
    }
};

class ComplexNumber : protected TrigonometricForm
{
private:
    double arr[2];
    void arithmeticForm()
    {
        complex < double > z(arr[0], arr[1]);
        cout << "Арифметическая форма = " << z << endl;
        cout << "Действительная часть комплексного числа: " << z.real() << endl;
        cout << "Мнимая часть комплексного числа: " << z.imag() << endl;
    }

    void createNumber(string str)
    {
        string str_number;
        int counter = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if ((isdigit(str[i]) || str[i] == '-' && isdigit(str[i + 1]) ||
                str[i] == '+' && isdigit(str[i + 1]) && counter == 0))
            {
                str_number += str[i];
                if (isdigit(str[i]) && str[i + 1] == '-' || str[i + 1] == '+')
                {
                    arr[counter] = stoi(str_number);
                    str_number = "";
                    counter++;
                }
            }
            else
            {
                str_number += str[i];
                if (i == str.size() - 1)
                {
                    arr[counter] = stoi(str_number);
                }
            }
        }
    }

public:
    void Print()
    {
        string str;
        int number;
        getline(cin, str);
        createNumber(str);
        arithmeticForm();
        trigonometricForm(arr);
        //cout << arr[0] << endl << arr[1] << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Введите строку с числами: ";
    ComplexNumber complexNumber;
    complexNumber.Print();
    cin.get();
    return 0;
}

/* Объект класса */

/*class Human
{
public:
    int age;
    int weight;
    string name;

    void print()
    {
        cout << endl << "Имя: " << name << ";\nВес: " << weight << ";\nВозраст: " << age << "." << endl;
    }
};

class Schedule
{
public:
    void print(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
        cout << endl << "X: " << x << ";\nY: " << y << ";\nZ: " << z << "." << endl;
    }

private:
    int x;
    int y;
    int z;
};

int main()
{
    setlocale(LC_ALL, "ru");
    Schedule schedule;
    schedule.print(2, 3, 5);

    Human firstHuman;
    firstHuman.age = 31;
    firstHuman.weight = 90;
    firstHuman.name = "Sergey - Vorobey";

    Human secondHuman;
    secondHuman.age = 30;
    secondHuman.weight = 75;
    secondHuman.name = "Vovan - NumberOne";

    firstHuman.print();
    secondHuman.print();
    cin.get();
    return 0;
}*/



/* Указатель на функцию */

/*string GetDataFromBD()
{
    return "Data From BD";
}

string GetDataFromWebServer()
{
    return "Data From Web Server";
}

string GetDataFromAstral()
{
    return "Data From Astral";
}

void showInfo(string (*foo)())
{
    cout << foo() << endl;
}

int main()
{
    showInfo(GetDataFromBD);
    showInfo(GetDataFromWebServer);
    showInfo(GetDataFromAstral);
    cin.get();
    return 0;
}*/


/* Шаблоны функций */

/*template <typename T1, typename T2>
T1 sum(T1 a, T2 b)  // Тип функции будет определять по первому параметру, т.к. тип функции == T1.
{
    a++;
    return a + b;
}

template <typename T1, typename T2>
void sum2(T1 a, T2 b)  // Этот тип функций будет принимать любой тип параметров в том виде, в котором он передается в функцию
{
    a++;
    cout << a + b << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    cout << sum(1, 5.895) << endl;
    sum2(1, 5.895);
    return 0;
}*/



/* Перегрузка функций */

/*double sum(double a, double b, double c)
{
    return a + b + c;
}

int sum(int a, int b, int c)
{
    return a + b + c;
}

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    cout << sum(3, 5) << endl;
    cout << sum(3, 5, 1) << endl;
    cout << sum(3.1, 5.8, 1.4) << endl;
    return 0;
}*/