/*
 [+] Create 5 functions to:  
    ▪ i) convert temperature Celsius to Fahrenheit: Fahrenheit = (Celsius * 9.0 / 5.0) + 32 
    ▪ ii) convert temperature Fahrenheit to Celsius: Celsius = (Fahrenheit – 32) * 50 / 9.0 
    ▪ iii) find root of quadratic equation ax2+bx+c=0.   
    ▪ iv) compute BMI of a person’s weight and height and tell whether he/she is overweight, 
        underweight and other terms according to BMI list: 
            bmi = weight / (height * height) - - - - 
            bmi < 18.5, underweight 
            bmi < 25, normal weight 
            bmi < 30, overweight 
            else, obese 
    ▪ v) sum numbers from 1 to n except those numbers that are divisible by 3, n is a parameter of the function.  
  Design a menu program to demonstrate these 5 functions with different test cases during the run time of the program.
*/
#include <iostream>
#include <cmath>
using namespace std;

double celsiusToFahrenheit(double c)
{
    return (c * 9.0 / 5.0) + 32;
}

double fahrenheitToCelsius(double f)
{
    return (f - 32) * 5.0 / 9.0;
}

void findRoots(double a, double b, double c)
{
    double discriminant = b * b - 4 * a * c;
    if (a == 0)
    {
        cout << "Root is: " << (-c / b);
    }
    else if (discriminant > 0)
    {
        double r1 = (-b + sqrt(discriminant)) / (2 * a);
        double r2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Roots are real and different: " << r1 << " and " << r2 << endl;
    }
    else if (discriminant == 0)
    {
        double r = -b / (2 * a);
        cout << "Roots are real and same: " << r << endl;
    }
    else
    {
        cout << "Roots are complex and different.\n";
    }
}

void computeBMI(double weight, double height)
{
    double bmi = weight / (height * height);
    cout << "BMI = " << bmi << endl;
    if (bmi < 18.5)
        cout << "Underweight\n";
    else if (bmi < 25)
        cout << "Normal weight\n";
    else if (bmi < 30)
        cout << "Overweight\n";
    else
        cout << "Obese\n";
}

int sumExceptDivisibleBy3(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i % 3 != 0)
            sum += i;
    }
    return sum;
}

int main()
{
    int choice;
    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Convert Celsius to Fahrenheit\n";
        cout << "2. Convert Fahrenheit to Celsius\n";
        cout << "3. Find roots of quadratic equation\n";
        cout << "4. Compute BMI\n";
        cout << "5. Sum numbers from 1 to n except those divisible by 3\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "-- Celsius Calculator --\n";
            double c;
            cout << "Enter Celsius: ";
            cin >> c;
            cout << "Fahrenheit: " << celsiusToFahrenheit(c) << endl;
            break;
        }
        case 2:
        {
            cout << "-- Fahrenheit Calculator --\n";
            double f;
            cout << "Enter Fahrenheit: ";
            cin >> f;
            cout << "Celsius: " << fahrenheitToCelsius(f) << endl;
            break;
        }
        case 3:
        {
            cout << "-- Quadratic Equation --\n";

            double a, b, c;
            cout << "Enter coefficients a, b and c: ";
            cin >> a >> b >> c;
            findRoots(a, b, c);
            break;
        }
        case 4:
        {
            cout << "-- BMI Calculator --\n";
            double weight, height;
            cout << "Enter weight (kg) and height (m): ";
            cin >> weight >> height;
            computeBMI(weight, height);
            break;
        }
        case 5:
        {
            cout << "-- Sum of non 3 divisible --\n";
            int n;
            cout << "Enter n: ";
            cin >> n;
            cout << "Sum = " << sumExceptDivisibleBy3(n) << endl;
            break;
        }
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
