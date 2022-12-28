//? EXERCISE 4: ASSOCIATION

// Programming Technique II

// Member 1's Name: Sadman Yasar Sayem
// Member 2's Name: MD. Mostakim Reza

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  28/12/2022    11:00        12:01            61

// Video link:
//   _________

#include <iostream>
#include <cmath>
using namespace std;

#define MAX_TERM_COUNT 10
class Term
{
private:
    int coef;
    int exp;

public:
    Term(int c = 0, int e = 0);
    void set(int c, int e);
    int evaluate(int x) const;
    int exponent() const;
    int coefficient() const;
};

class Polynomial
{
private:
    Term terms[MAX_TERM_COUNT];
    int count;

public:
    Polynomial();
    void input();
    int evaluate(int x) const;
    Term largestTerm() const;
    int degree() const;
    int getCount() const;
    void setCount(int c);
};

//----------------------------------------------------------------------------
int main()
{
    int noOfInputs = 0;
    Polynomial p;

    cout << "Enter a Polynomial :" << endl;
    cout << "   \t\t How many terms => ";

    cin >> noOfInputs;
    cout << endl;

    p.setCount(noOfInputs);
    p.input();

    cout << endl;

    cout << " x  \t\tPolynomial value" << endl;
    cout << "----\t\t----------------" << endl;

    for (int x = 0; x <= 5; x++)
        cout << x << "  \t\t" << p.evaluate(x) << endl;

    cout << endl;

    system("pause");
    return 0;
}

//----------------------------------------------------------------------------
// class Term

// The constructor is given

Term::Term(int c, int e) : coef(c), exp(e) {}

// Implement the other methods
void Term::set(int c, int e)
{
    coef = c;
    exp = e;
}
int Term::exponent() const { return exp; }
int Term::coefficient() const { return coef; }
int Term::evaluate(int x) const { return coef * pow(x, exp); }
//----------------------------------------------------------------------------

// class Polynomial
Polynomial::Polynomial()
{
    count = 0;
}

// Implement the constructor and the other methods of the class Polynomial
int Polynomial::evaluate(int x) const
{
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += terms[i].evaluate(x);
    }
    return sum;
}

void Polynomial::input()
{
    for (int i = 0; i < count; i++)
    {
        int coefficient;
        int exponent;
        cout << "    \t\tEnter term #" << (i + 1) << " (coef and exp) => ";
        cin >> coefficient >> exponent;

        this->terms[i].set(coefficient, exponent);
        cout << endl;
    }
}

int Polynomial::getCount() const
{
    return count;
}

void Polynomial::setCount(int c)
{
    count = c;
}

// int Polynomial::degree() const { }

// Term Polynomial::largestTerm() const {}