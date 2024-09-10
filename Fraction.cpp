#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Default constructor
    Fraction() : numerator(1), denominator(1) {}

    // Parameterized constructor
    Fraction(int num, int denom) : numerator(num), denominator(denom) {}

    // Function to set values
    void setValues(int num, int denom) {
        numerator = num;
        denominator = denom;
    }

    // Function to print fraction
    void print() const {
        cout << numerator << "/" << denominator << endl;
    }

    // Function to add two fractions
    Fraction add(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.denominator + other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        return result;
    }

    // Function to subtract two fractions
    Fraction subtract(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.denominator - other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        return result;
    }

    // Function to multiply two fractions
    Fraction multiply(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.numerator;
        result.denominator = denominator * other.denominator;
        return result;
    }

    // Function to divide two fractions
    Fraction divide(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.denominator;
        result.denominator = denominator * other.numerator;
        return result;
    }
};

int main() {
    // Create fractions using the default constructor
    Fraction f1;
    f1.print(); // Should print 1/1

    // Create fractions using the parameterized constructor
    Fraction f2(3, 4);
    f2.print(); // Should print 3/4

    // Create another fraction and set values
    Fraction f3;
    f3.setValues(1, 2);
    f3.print(); // Should print 1/2

    // Demonstrate arithmetic operations
    Fraction sum = f3.add(f2);
    Fraction difference = f3.subtract(f2);
    Fraction product = f3.multiply(f2);
    Fraction quotient = f3.divide(f2);

    cout << "Sum: ";
    sum.print(); // Should print result of 1/2 + 3/4

    cout << "Difference: ";
    difference.print(); // Should print result of 1/2 - 3/4

    cout << "Product: ";
    product.print(); // Should print result of 1/2 * 3/4

    cout << "Quotient: ";
    quotient.print(); // Should print result of 1/2 / 3/4

    return 0;
}
