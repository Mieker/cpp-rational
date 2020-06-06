#include <iostream>

using namespace std;

class Rational
{
public:
   Rational(int numerator = 0, int denominator = 1)
   {
       initialize(numerator, denominator);
   };

   ~Rational() {}

   Rational(const Rational& copy)
   {
       this->numer = copy.numerator();
       this->denom = copy.denominator();
   };

   Rational& operator=(const Rational& other)
   {
       if (&other != this) {
         this->numer = other.numerator();
         this->denom = other.denominator();
       }
       return *this;
   };

   Rational& operator=(int i)
   {
       this->numer = i;
       this->denom = 1;
       return *this;
   };

   int numerator() const { return numer; }
   int denominator() const { return denom; }

   static Rational normalize(const Rational& other)
   {
       Rational r(other.numer / other.gcdND, other.denom / other.gcdND);
       return r;
   };
   static Rational normalized(int numerator, int denominator)
   {
       return Rational::normalize(Rational(numerator, denominator));
   };

   Rational operator+(const Rational& other) const
   {
       if (this->denom == other.denom) {
           return Rational {this->numer + other.numer, this->denom};
       }
       else {
           int tempNumer = this->numer * other.denom + other.numer * this->denom;
           int tempDenom = this->denom * other.denom;
           return normalize(Rational {tempNumer, tempDenom});
       }
   };

   Rational operator-(const Rational& other) const
   {
       if (this->denom == other.denom) {
           return normalize(Rational {this->numer - other.numer, this->denom});
       }
       else {
           int tempNumer = this->numer * other.denom - other.numer * this->denom;
           int tempDenom = this->denom * other.denom;
           return normalize(Rational {tempNumer, tempDenom});
       }
   };

   Rational operator*(const Rational& other) const
   {
       int tempNumer = this->numer * other.numer;
       int tempDenom = this->denom * other.denom;
       return normalize(Rational {tempNumer, tempDenom});
   };

   Rational operator/(const Rational& other) const
   {
       int tempNumer = this->numer * other.denom;
       int tempDenom = this->denom * other.numer;
       return normalize(Rational {tempNumer, tempDenom});
   };

   Rational operator+() const
   {
       return *this*(+1);
   };
   Rational operator-() const
   {
       return *this*(-1);
   };

   bool operator==(const Rational& other) const
   {
       Rational a(this->numer * other.denom, this->denom * other.denom);
       Rational b(other.numer * this->denom, other.denom * this->denom);
       if (a.numer == b.numer) {
            return true;
       }
       else {
               return false;
       }
   };
   bool operator>=(const Rational& other) const
   {
       Rational a(this->numer * other.denom, this->denom * other.denom);
       Rational b(other.numer * this->denom, other.denom * this->denom);
       if (a.numer >= b.numer) {
            return true;
       }
       else {
               return false;
       }
   };
   bool operator<=(const Rational& other) const
   {
       Rational a(this->numer * other.denom, this->denom * other.denom);
       Rational b(other.numer * this->denom, other.denom * this->denom);
       if (a.numer <= b.numer) {
            return true;
       }
       else {
               return false;
       }
   };
   bool operator>(const Rational& other) const
   {
       Rational a(this->numer * other.denom, this->denom * other.denom);
       Rational b(other.numer * this->denom, other.denom * this->denom);
       if (a.numer > b.numer) {
            return true;
       }
       else {
               return false;
       }
   };
   bool operator<(const Rational& other) const
   {
       Rational a(this->numer * other.denom, this->denom * other.denom);
       Rational b(other.numer * this->denom, other.denom * this->denom);
       if (a.numer < b.numer) {
            return true;
       }
       else {
               return false;
       }
   };

   static int findGCD(int a, int b)
   {
      if(a!=b)
        return findGCD(a>b?a-b:a,b>a?b-a:b);
      return a;
   };

private:
   int numer;
   int denom;
   int gcdND;

   void initialize(int numerator, int denominator)
   {
       if (denominator < 0) {
           this->numer = abs(numerator) * (-1);
           this->denom = abs(denominator);
       }
       else {
           this->numer = numerator;
           this->denom = denominator;
       }
       this->gcdND = findGCD(abs(numerator), abs(denominator));
   };

   friend std::ostream& operator<<(std::ostream &os, const Rational &rr)
   {
      if (rr.numer < 0) {
          os << "(" << rr.numer << "/" << rr.denom << ")";
      }
      else {
          os << rr.numer << "/" << rr.denom;
      }
      return os;
   };

   friend std::istream& operator>>(std::istream &is, Rational &r)
   {
       cout << "numerator: ";
       is >> r.numer;
       cout << "denominator: ";
       is >> r.denom;
       return is;
   };

};

Rational operator+(const Rational& r, int i)
{
    int tempNumer = r.numerator() + i * r.denominator();
    int tempDenom = r.denominator();
    return Rational {tempNumer, tempDenom};
};
Rational operator+(int i, const Rational& r)
{
    int tempNumer = r.numerator() + i * r.denominator();
    int tempDenom = r.denominator();
    return Rational {tempNumer, tempDenom};
};

Rational operator-(const Rational& r, int i)
{
    int tempNumer = r.numerator() - i * r.denominator();
    int tempDenom = r.denominator();
    return Rational {tempNumer, tempDenom};
};
Rational operator-(int i, const Rational& r)
{
    int tempNumer = i * r.denominator() - r.numerator();
    int tempDenom = r.denominator();
    return Rational {tempNumer, tempDenom};
};

Rational operator*(const Rational& r, int i)
{
    int tempNumer = r.numerator() * i;
    int tempDenom = r.denominator();
    return Rational {tempNumer, tempDenom};
};
Rational operator*(int i, const Rational& r)
{
    int tempNumer = r.numerator() * i;
    int tempDenom = r.denominator();
    return Rational {tempNumer, tempDenom};
};

Rational operator/(const Rational& r, int i)
{
    int tempNumer = r.numerator();
    int tempDenom = r.denominator() * i;
    return Rational {tempNumer, tempDenom};
};
Rational operator/(int i, const Rational& r)
{
    int tempNumer = i * r.denominator();
    int tempDenom = r.numerator();
    return Rational {tempNumer, tempDenom};
};
