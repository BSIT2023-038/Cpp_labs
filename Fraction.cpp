#include <iostream>

class Fraction {
public:
    // Constructors
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            std::cerr << "Error: Denominator cannot be zero." << std::endl;
            denominator = 1; // Set to 1 to avoid division by zero
        }
    }

    // Copy Constructor
    Fraction(const Fraction& f) : numerator(f.numerator), denominator(f.denominator) {}

    // Method to print the fraction
    void print() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }

    // Method to add two fractions
    Fraction add(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.denominator + other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        return result;
    }

    // Method to subtract two fractions
    Fraction subtract(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.denominator - other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        return result;
    }

    // Method to multiply two fractions
    Fraction multiply(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.numerator;
        result.denominator = denominator * other.denominator;
        return result;
    }

    // Method to divide two fractions
    Fraction divide(const Fraction& other) const {
        Fraction result;
        if (other.numerator == 0) {
            std::cerr << "Error: Division by zero." << std::endl;
            return Fraction(); // Return a default Fraction to avoid undefined behavior
        }
        result.numerator = numerator * other.denominator;
        result.denominator = denominator * other.numerator;
        return result;
    }

private:
    int numerator;
    int denominator;
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(2, 3);

    std::cout << "Fraction f1: ";
    f1.print(); // Output: 1/2

    std::cout << "Fraction f2: ";
    f2.print(); // Output: 2/3

    Fraction f3 = f1.add(f2);
    std::cout << "f1 + f2: ";
    f3.print(); // Output: 7/6

    Fraction f4 = f1.subtract(f2);
    std::cout << "f1 - f2: ";
    f4.print(); // Output: -1/6

    Fraction f5 = f1.multiply(f2);
    std::cout << "f1 * f2: ";
    f5.print(); // Output: 2/6

    Fraction f6 = f1.divide(f2);
    std::cout << "f1 / f2: ";
    f6.print(); // Output: 3/4

    return 0;
}
