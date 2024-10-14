#include "polynomial.h"
#include <iostream>
using namespace std;

/**
 * @file main.cpp
 * @author Chidubem Okoye
 * @class CSCI 301
 * @date 10/12/2024
 * @brief Main program to test the functionality of the polynomial class.
 */

/**
 * @brief Main function that tests the polynomial class functionality.
 * 
 * @return int Returns 0 on successful execution.
 */
int main()
{
    polynomial p1; ///< First polynomial object.
    polynomial p2; ///< Second polynomial object.

    int numTerms1, coeff, power; ///< Variables for number of terms and term details.

    // Input for the first polynomial
    cout << "Enter the number of terms for polynomial p1: ";
    cin >> numTerms1;

    for (int i = 0; i < numTerms1; ++i)
    {
        cout << "Enter coefficient and power for term " << (i + 1) << " (format: coeff power): ";
        cin >> coeff >> power;
        p1.addTerm(coeff, power);
    }

    // Input for the second polynomial
    int numTerms2; ///< Variable for the number of terms in the second polynomial.
    cout << "Enter the number of terms for polynomial p2: ";
    cin >> numTerms2;

    for (int i = 0; i < numTerms2; ++i)
    {
        cout << "Enter coefficient and power for term " << (i + 1) << " (format: coeff power): ";
        cin >> coeff >> power;
        p2.addTerm(coeff, power);
    }

    // Display polynomials
    cout << "Polynomial p1: ";
    p1.display();

    cout << "Polynomial p2: ";
    p2.display();

    // Add polynomials
    polynomial p3 = p1.addPolynomial(p2);
    cout << "Polynomial p1 + p2: ";
    p3.display();

    return 0; // Successful execution
}
