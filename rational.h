#include <iostream>

using namespace std;

class Rational
{
public:
   //konstruktor
   Rational(int numerator = 0, int denominator = 1)
   {
       initialize(numerator, denominator);
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
   Rational& operator=(const Rational& other)                                                                   //
   {
       if (&other != this) {

         this->numer = other.numerator();
         this->denom = other.denominator();
       }
       return *this;
   };
   //tworzy rational z inta czyli robi przykladowo z 12 na 12/1, z 6 na 6/1
   Rational& operator=(int i)                                                                                   //
   {
       this->numer = i;
       this->denom = 1;
       return *this;
   };
   //getter numer
   int numerator() const { return numer; }
   //getter denom
   int denominator() const { return denom; }
   //getter gcdND - //////////////////////////////do usuniecia
   int getGCD() const { return gcdND; }

   static Rational normalize(const Rational& other)
   {
       Rational r(other.numer / other.gcdND, other.denom / other.gcdND);
       return r;
   };
   static Rational normalized(int numerator, int denominator)
   {
       return Rational::normalize(Rational(numerator, denominator));
   };
   //dodawanie rational
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
   //odejmowanie rational
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
   //mnozenie rational
   Rational operator*(const Rational& other) const
   {
       int tempNumer = this->numer * other.numer;
       int tempDenom = this->denom * other.denom;
       return normalize(Rational {tempNumer, tempDenom});
   };
   //dzielenie rational
   Rational operator/(const Rational& other) const
   {
       int tempNumer = this->numer * other.denom;
       int tempDenom = this->denom * other.numer;
       return normalize(Rational {tempNumer, tempDenom});
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

   static int findGCD(int a, int b)
   {
      if(a!=b)
        return findGCD(a>b?a-b:a,b>a?b-a:b);
      return a;
   };

private:
   int numer;
   int denom;
   //greatest common divisor - najwiekszy wspolny dzielnik
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

   //cout
   friend std::ostream& operator<<(std::ostream &os, const Rational &rr)
   {
//      Rational rr = normalize(r);

       if (rr.numer < 0) {
          os << "(" << rr.numer << "/" << rr.denom << ")";
      }
      else {
          os << rr.numer << "/" << rr.denom;
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



// liczby calkowite ustaw wyswietlanie poprzez cout -> if denom = 1 os = numer
