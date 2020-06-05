#include <iostream>

using namespace std;

class Rational
{
public:
   //konstruktor
   Rational(int numerator = 0, int denominator = 1)
   {
       if (denominator < 0) {
           this->numer = abs(numerator) * (-1);
           this->denom = abs(denominator);
       }
       else {
           this->numer = numerator;
           this->denom = denominator;
       }
   };
   //destruktor
   ~Rational() {}
   //tworzy rational kopiujac podany w argumencie inny rational
   Rational(const Rational& copy)
   {
       this->numer = copy.numerator();
       this->denom = copy.denominator();
   };
   //tworzy rationala a w zasadzie nowe odniesienie do niego bo beda mialy ten sam memo space
   Rational& operator=(const Rational& other)
   {
       if (&other != this) {
         this->numer = other.numerator();
         this->denom = other.denominator();
       }
       return *this;
   };
   //tworzy rational z inta czyli robi przykladowo z 12 na 12/1, z 6 na 6/1
   Rational& operator=(int i)
   {
       this->numer = i;
       this->denom = 1;
       return *this;
   };
   //getter numer
   int numerator() const { return numer; }
   //getter denom
   int denominator() const { return denom; }

   static Rational normalize(const Rational& other);                            //tworzy static rational z innego rationala
   static Rational normalized(int numerator, int denominator);                  //tworzy static rational z dwoch intow w postaci numeratora i denominatora
                                                                                //byc moze chodzi tutaj o to ze normalizujemy l.rzeczywista np z 20/10 na 2 alby z 3/12 na 1/4
   //dodawanie rational
   Rational operator+(const Rational& other) const
   {
       if (this->denom == other.denom) {
           return Rational {this->numer + other.numer, this->denom};
       }
       else {
           int tempNumer = this->numer * other.denom + other.numer * this->denom;
           int tempDenom = this->denom * other.denom;
           return Rational {tempNumer, tempDenom};
       }
   };
   //odejmowanie rational
   Rational operator-(const Rational& other) const
   {
       if (this->denom == other.denom) {
           return Rational {this->numer - other.numer, this->denom};
       }
       else {
           int tempNumer = this->numer * other.denom - other.numer * this->denom;
           int tempDenom = this->denom * other.denom;
           return Rational {tempNumer, tempDenom};
       }
   };
   //mnozenie rational
   Rational operator*(const Rational& other) const
   {
       int tempNumer = this->numer * other.numer;
       int tempDenom = this->denom * other.denom;
       return Rational {tempNumer, tempDenom};
   };
   //dzielenie rational
   Rational operator/(const Rational& other) const
   {
       int tempNumer = this->numer * other.denom;
       int tempDenom = this->denom * other.numer;
       return Rational {tempNumer, tempDenom};
   };

   //umozliwia zapis Rational r w postaci -r lub +r
   Rational operator+() const
   {
       return *this*(+1);
   };
   Rational operator-() const
   {
       return *this*(-1);
   };

   bool operator==(const Rational& other) const;                                //zwraca booleana uzywajac operatory logiczne porownujac dwa rationale
   bool operator>=(const Rational& other) const;
   bool operator<=(const Rational& other) const;
   bool operator>(const Rational& other) const;
   bool operator<(const Rational& other) const;

private:
   int numer;
   int denom;
   //greatest common divisor - najwiekszy wspolny dzielnik
   int gcdND;

   void initialize(int numerator, int denominator);                        //?? //void ktory inicjalizuje cos z liczba rzeczywista ale nie wiem dokladnie o co kaman

   //cout
   friend std::ostream& operator<<(std::ostream &os, const Rational &r)
   {
      if (r.numer < 0) {
          os << "(" << r.numer << "/" << r.denom << ")";
      }
      else {
          os << r.numer << "/" << r.denom;
      }
      return os;
   };
   //cin
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
