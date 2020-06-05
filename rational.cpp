#include "rational.h"
#include <iostream>

using namespace std;

int main()
{
    Rational r2(2, 11), r3(1, -3), r5(18, 6);
    Rational res1 = 3 + r2 * r3;
    Rational res2 = (3 + r2) * r3;
    Rational res3 = 3 + r3 * (r2 + 2) / (r5 - r3);

    cout << 3 << " + " << r2 << " * " <<  r3 << " = " << res1 << endl;
    cout << "(" << 3 << " + " << r2 << ")" << " * " <<  r3 << " = " << res2 << endl;
    cout << 3 << " + " << r3 << " * " << "(" << r2 << " + " << 2 << ")" << "/"
    << "(" << r5 << " - " << r3 << ")" << " = " << res3 << endl;

    Rational res4 = res3;
    cout << res4;

//    Rational r1(5508, 1980);
//    Rational r2=r1;
//    cout << r1;

//    Rational r1(5508, 1980);
//    cout << r1.getGCD();

//    Rational r2 = Rational::normalize(r1);
//    cout << r2;


    ////////////////////////////////////////////////////
//    Rational r2(2,11);
//    cout << +r2 << endl;
//    cout << -r2 << endl;
//    Rational r41{3,4};
//    Rational r42 = 2 / r41;
//    cout << r42 << endl;

//    cout << "Hello World!" << endl;
//    Rational r1{2,3};
//   cout << r1 << endl;

//    Rational r2(r1);
//    cout << r2 << endl;

//    Rational r3 = r2;
//    cout << "r3: " << r3 << endl;

//    Rational r4(12);
//    cout << r4 << endl;

////    Rational r5;
////    cin >> r5;
////    cout << r5;

//    Rational rA{3,4};
//    Rational rB{5,4};
//    Rational rC = rA + rB;
//    cout << "3/4 + 5/4 = " << rC << endl;

//    Rational rX{2,3};
//    Rational rY{3,4};
//    Rational rZ = rX + rY;
//    cout << "2/3 + 3/4 = " << rZ << endl;

//    Rational r11{3,4};
//    Rational r12{1,4};
//    Rational r13 = r11 - r12;
//    cout << "3/4 - 1/4 = " << r13 << endl;

//    Rational r21{3,5};
//    Rational r22{1,2};
//    Rational r23 = r21 * r22;
//    cout << "3/5 * 1/2 = " << r23 << endl;

//    Rational r31{4,7};
//    Rational r32{2,1};
//    Rational r33 = r31 / r32;
//    cout << "6/6 / 2/1 = " << r33 << endl;
    ////////////////////////////////////////////////////////



    return 0;
}
