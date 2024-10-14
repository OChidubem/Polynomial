#include "polynomial.h"
#include <iostream>
using namespace std;

/**
 * @file polynomial.cpp
 * @author Chidubem Okoye
 * @class CSCI 301
 * @date 10/12/2024
 * @brief Implementation of a sparse polynomial class using a linked list of terms.
 */

// Default constructor. Initializes the polynomial with no terms.
polynomial::polynomial()
{
    headPtr = 0;
    degree = 0;
}

/**
 * @brief Adds a term to the polynomial, maintaining the order of terms by decreasing power.
 * 
 * @param coeff The coefficient of the term to add.
 * @param power The power of the term to add.
 */
void polynomial::addTerm(int coeff, int power)
{
    struct term* prev = 0;
    struct term* curr = headPtr;

    while(curr != 0 )
    {
        if(power > curr->power)
            break;
        else if(curr->power == power) // Already a term with given power exists, add the coeff
        {
            curr->coeff += coeff;
            return;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    struct term* t = new term;
    t->coeff = coeff;
    t->power = power;
    t->next = 0;

    if(prev == 0) // Adding as 1st term
    {
        degree = power;
        t->next = headPtr;
        headPtr = t;
    }
    else
    {
        prev->next = t;
        t->next = curr;
    }
}

/**
 * @brief Adds two polynomials together and returns the result as a new polynomial.
 * 
 * @param other The polynomial to add.
 * @return A new polynomial that is the sum of the two polynomials.
 */
polynomial polynomial::addPolynomial(const polynomial &other)
{
    polynomial result;
    struct term* poly1 = headPtr;
    struct term* poly2 = other.headPtr;

    while(poly1 != 0 && poly2 != 0)
    {
        if(poly1->power > poly2->power)
        {
            result.addTerm(poly1->coeff, poly1->power);
            poly1 = poly1->next;
        }
        else if(poly2->power > poly1->power)
        {
            result.addTerm(poly2->coeff, poly2->power);
            poly2 = poly2->next;
        }
        else
        {
            int sum = poly1->coeff + poly2->coeff;
            if(sum != 0)
                result.addTerm(sum, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add any left out terms from poly1 and poly2
    while(poly1 != 0)
    {
        result.addTerm(poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }

    while(poly2 != 0)
    {
        result.addTerm(poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }

    return result;
}

/**
 * @brief Returns the degree of the polynomial.
 * 
 * @return The highest power of the polynomial.
 */
int polynomial::getDegree() const
{
    return degree;
}

/**
 * @brief Returns the coefficient of the term with the given power.
 * 
 * @param power The power of the term to get the coefficient for.
 * @return The coefficient of the term with the specified power, or 0 if not found.
 */
int polynomial::getCoeff(int power) const
{
    struct term* curr = headPtr;
    if(power > degree)
        return 0;
    while(curr != 0)
    {
        if(curr->power == power)
            return curr->coeff;
        else if(curr->power < power) // No need to search further since we have come to lower powers
            break;
        else
            curr = curr->next;
    }
    return 0;
}

/**
 * @brief Displays the polynomial in human-readable form, formatted as specified.
 */
void polynomial::display()
{
    struct term* curr = headPtr;
    if (headPtr == 0)
    {
        cout << "0";
    }
    else
    {
        cout << "P(x) = "; // Start with the polynomial representation

        // Display the first term with special formatting
        if (curr->power == 0)
            cout << "(" << curr->coeff << ")"; // Only the coefficient
        else if (curr->power == 1)
            cout << "(" << curr->coeff << ")X"; // Coefficient and X
        else
            cout << "(" << curr->coeff << ")X^" << curr->power; // Standard format

        curr = curr->next;

        while (curr != 0)
        {
            // Formatting for subsequent terms
            if (curr->coeff > 0)
                cout << " + "; // Add plus sign for positive coefficients
            else
                cout << " "; // No plus sign for negative coefficients, just a space

            // Handle special formatting for current term
            if (curr->power == 0)
                cout << "(" << curr->coeff << ")"; // Only the coefficient
            else if (curr->power == 1)
                cout << "(" << curr->coeff << ")X"; // Coefficient and X
            else
                cout << "(" << curr->coeff << ")X^" << curr->power; // Standard format

            curr = curr->next;
        }
    }

    cout << endl;
}
