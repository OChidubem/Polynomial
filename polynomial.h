#ifndef polynomial_h
#define polynomial_h

/**
 * @file polynomial.h
 * @author Chidubem Okoye
 * @class CSCI 301
 * @date 10/12/2024
 * @brief Header file for the polynomial class and related structures.
 */

/**
 * @struct term
 * @brief Represents a single term in the polynomial with a coefficient and power.
 */
struct term
{
    int coeff; ///< Coefficient of the term
    int power; ///< Power of the term
    struct term* next; ///< Pointer to the next term in the linked list
};

/**
 * @class polynomial
 * @brief A class that represents a sparse polynomial using a linked list of terms.
 */
class polynomial
{
private:
    struct term* headPtr; ///< Pointer to the head (first term) of the polynomial linked list
    int degree; ///< Degree of the polynomial

public:
    /**
     * @brief Default constructor to initialize an empty polynomial.
     */
    polynomial();

    /**
     * @brief Adds a new term to the polynomial in decreasing order of power.
     *        If a term with the same power exists, the coefficients are added together.
     * @param coeff The coefficient of the term to add.
     * @param power The power of the term to add.
     */
    void addTerm(int coeff, int power); //stores terms in decreasing order of power

    /**
     * @brief Adds two polynomials and returns the result as a new polynomial.
     * @param other Another polynomial to add.
     * @return The sum of the two polynomials.
     */
    polynomial addPolynomial(const polynomial &other);

    /**
     * @brief Gets the degree of the polynomial.
     * @return The degree of the polynomial.
     */
    int getDegree() const;

    /**
     * @brief Gets the coefficient of the term with a specific power.
     * @param power The power of the term to get the coefficient for.
     * @return The coefficient of the term, or 0 if the term doesn't exist.
     */
    int getCoeff(int power) const;

    /**
     * @brief Displays the polynomial in a readable format.
     */
    void display();
};

#endif /* polynomial_h */
