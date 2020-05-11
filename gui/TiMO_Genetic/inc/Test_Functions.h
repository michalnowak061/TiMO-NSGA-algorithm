//
//  Test_Functions.h
//  TiMO_Projekt
//
//  Created by Michal on 15/03/2020.
//  Copyright © 2020 Michal_Nowak & Kacper_Stenka. All rights reserved.
//

#ifndef Test_Functions_h
#define Test_Functions_h

#include <math.h>
#include "Population.hpp"

// --------------------------------------------------------------------

void Set_Binh_Korn_Function(Population *p) {

    const string f1 = "4 * x1^2 + 4 * x2^2";
    const string f2 = "(x1 - 5)^2 + (x2 - 5)^2";

    p->Population_Set_Goal_Function(f1);
    p->Population_Set_Goal_Function(f2);

    p->Population_Initialization(0, 5);

    p->Population_Set_Search_Domain(0, 5);
    p->Population_Set_Search_Domain(0, 3);
}

// --------------------------------------------------------------------

void Set_Chankong_Haimes_Function(Population *p) {

    const string f1 = "2 + (x1 - 2)^2 + (x2 - 1)^2";
    const string f2 = "9 * x1 - (x2 - 1)^2";

    p->Population_Set_Goal_Function(f1);
    p->Population_Set_Goal_Function(f2);

    p->Population_Initialization(-20, 20);

    p->Population_Set_Search_Domain(-20, 20);
    p->Population_Set_Search_Domain(-20, 20);
}

// --------------------------------------------------------------------

void Fonseca_Fleming_Function(Population *p, int n) {
    
    const string n_str = to_string(n);
    
    const string sum_1 = " -( x1 - (1/sqrt(3)) )^2 - ( x2 - (1/sqrt(3)) )^2 - ( x3 - (1/sqrt(3)) )^2 ";
    const string sum_2 = " -( x1 + (1/sqrt(3)) )^2 - ( x2 + (1/sqrt(3)) )^2 - ( x3 + (1/sqrt(3)) )^2 ";
    
    const string f1 = "1 - exp(" + sum_1 + ")";
    const string f2 = "1 - exp(" + sum_2 + ")";
    
    p->Population_Set_Goal_Function(f1);
    p->Population_Set_Goal_Function(f2);
    
    p->Population_Initialization(-4, 4);
    
    for(int i = 0; i < n; ++i) {
        
        p->Population_Set_Search_Domain(-4, 4);
    }
}

// --------------------------------------------------------------------

void Set_Test_Function_4(Population *p) {

    const string f1 = "x1^2 - x1";
    const string f2 = "-0.5 * x1 - x2 - 1";

    p->Population_Set_Goal_Function(f1);
    p->Population_Set_Goal_Function(f2);

    p->Population_Initialization(-7, 4);

    p->Population_Set_Search_Domain(-7, 4);
    p->Population_Set_Search_Domain(-7, 4);
}

// --------------------------------------------------------------------

void Kursawe_Function(Population *p) {
    
    string sum_1;
    string sum_2;
    
    for(int i = 1; i < 3; ++i) {
        
        sum_1 += "- 10 * exp(-0.2 * sqrt(x" + to_string(i) + "^2 + x" + to_string(i+1) + "^2))";
    }
    
    for(int i = 1; i < 4; ++i) {
        
        sum_2 += "+ abs(x" + to_string(i) + ")^(0.8) + 5 * sin(x" + to_string(i) + "^3)";
    }
    
    const string f1 = sum_1;
    const string f2 = sum_2;
    
    p->Population_Set_Goal_Function(f1);
    p->Population_Set_Goal_Function(f2);
    
    p->Population_Initialization(-5, 5);
    
    for(int i = 0; i < 3; ++i) {
        
        p->Population_Set_Search_Domain(-5, 5);
    }
}

// --------------------------------------------------------------------

void Population_Set_Schaffers_N1_Function(Population *p) {
    
    const string f1 = "x1^2";
    const string f2 = "(x1 - 2)^2";
    
    p->Population_Set_Goal_Function(f1);
    p->Population_Set_Goal_Function(f2);
    
    p->Population_Initialization(-10, 10);
    p->Population_Set_Search_Domain(-10, 10);
}

// --------------------------------------------------------------------

void Population_Set_Polonis_Function(Population *p) {
    
    const string f1 = "1 + ( 0.5 * sin(1) - 2 * cos(1) + sin(2) - 1.5 * cos(2) - 0.5 * sin(x1) + 2 * cos(x1) - sin(x2) + 1.5 * cos(x2) )^2 + "
                          "( 1.5 * sin(1) - cos(1) + 2 * sin(2) - 0.5 * cos(2) - 1.5 * sin(x1) + cos(x1) - 2 * sin(x2) + 0.5 * cos(x2) )^2";

    const string f2 = "( x1 + 3 )^2 + ( x2 + 1 )^2";

    p->Population_Set_Goal_Function(f1);
    p->Population_Set_Goal_Function(f2);
    
    p->Population_Initialization(-M_PI, M_PI);
    
    p->Population_Set_Search_Domain(-M_PI, M_PI);
    p->Population_Set_Search_Domain(-M_PI, M_PI);
}

// --------------------------------------------------------------------

void Population_Set_Zitzler_Deb_Thieles_Function_N1(Population *P) {
    
    const string f1 = "x1";
    
    string g = "1";
    
    for(int i = 2; i <= 30; ++i) {
        
        g += " + (9 / 29) * x" + to_string(i);
        P->Population_Set_Search_Domain(0, 1);
    }
    
    P->Population_Set_Search_Domain(0, 1);
    
    string h = "1 - sqrt(" + f1 + " / (" + g + "))";
    
    const string f2 = "(" + g + ")" + " * " + "(" + h + ")";
    
    P->Population_Set_Goal_Function(f1);
    P->Population_Set_Goal_Function(f2);
    
    P->Population_Initialization(0, 1);
}

// --------------------------------------------------------------------

void Population_Set_Zitzler_Deb_Thieles_Function_N2(Population *P) {

    const string f1 = "x1";

    string g = "1";

    for(int i = 2; i <= 30; ++i) {

        g += " + (9 / 29) * x" + to_string(i);
        P->Population_Set_Search_Domain(0, 1);
    }

    P->Population_Set_Search_Domain(0, 1);

    string h = "1 - (" + f1 + " / (" + g + "))^2";

    const string f2 = "(" + g + ")" + " * " + "(" + h + ")";

    P->Population_Set_Goal_Function(f1);
    P->Population_Set_Goal_Function(f2);

    P->Population_Initialization(0, 1);
}

// --------------------------------------------------------------------

void Population_Set_Zitzler_Deb_Thieles_Function_N3(Population *P) {

    const string f1 = "x1";

    string g = "1";

    for(int i = 2; i <= 30; ++i) {

        g += " + (9 / 29) * x" + to_string(i);
        P->Population_Set_Search_Domain(0, 1);
    }

    P->Population_Set_Search_Domain(0, 1);

    string h = "1 - sqrt(" + f1 + " / (" + g + ")) - (" + f1 + " / (" + g + ")) * sin(10 * " + to_string(M_PI) + " * " + f1 + ")";

    const string f2 = "(" + g + ")" + " * " + "(" + h + ")";

    P->Population_Set_Goal_Function(f1);
    P->Population_Set_Goal_Function(f2);

    P->Population_Initialization(0, 1);
}

// --------------------------------------------------------------------

void Population_Set_Zitzler_Deb_Thieles_Function_N4(Population *P) {

    const string f1 = "x1";

    string g = "91";

    P->Population_Set_Search_Domain(0, 1);

    for(int i = 2; i <= 10; ++i) {

        g += " + (x" + to_string(i) + "^2 - 10 * cos( 4 *" + to_string(M_PI) + " * x" + to_string(i) + "))";
        P->Population_Set_Search_Domain(-5, 5);
    }

    string h = "1 - sqrt(" + f1 + " / (" + g + "))";

    const string f2 = "(" + g + ")" + " * " + "(" + h + ")";

    P->Population_Set_Goal_Function(f1);
    P->Population_Set_Goal_Function(f2);

    P->Population_Initialization(0, 1);
}

// --------------------------------------------------------------------

void Population_Set_Zitzler_Deb_Thieles_Function_N6(Population *P) {

    const string f1 = "1 - exp(-4 * x1) * ( sin(6 * " + to_string(M_PI) + " * x1) )^6";
    const string g = "1 + 9 * ( ( x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10 ) / 9 )^(0.25) ";
    const string h = "1 - (" + f1 + " / (" + g + "))^2";
    const string f2 = "(" + g + ")" + " * " + "(" + h + ")";

    for(int i = 0; i < 10; ++i) {

        P->Population_Set_Search_Domain(0, 1);
    }

    P->Population_Set_Goal_Function(f1);
    P->Population_Set_Goal_Function(f2);

    P->Population_Initialization(0, 1);
}

// --------------------------------------------------------------------

void Set_Osyczka_Kundu_Function(Population *p) {

    const string f1 = "-25 * (x1 - 2)^2 - (x2 - 2)^2 - (x3 - 1)^2 - (x4 - 4)^2 - (x5 - 1)^2";
    const string f2 = "x1^2 + x2^2 + x3^2 + x4^2 + x5^2 + x6^2";

    p->Population_Set_Goal_Function(f1);
    p->Population_Set_Goal_Function(f2);

    p->Population_Initialization(0, 10);

    p->Population_Set_Search_Domain(0, 10);
    p->Population_Set_Search_Domain(0, 10);
    p->Population_Set_Search_Domain(1, 5);
    p->Population_Set_Search_Domain(0, 6);
    p->Population_Set_Search_Domain(0, 10);
    p->Population_Set_Search_Domain(1, 5);
}

// --------------------------------------------------------------------

void Set_CTP1_Function(Population *p) {

    const string f1 = "x1";
    const string f2 = "(1 + x2) * exp(-x1 / (1 + x2))";

    p->Population_Set_Goal_Function(f1);
    p->Population_Set_Goal_Function(f2);

    p->Population_Initialization(0, 1);

    p->Population_Set_Search_Domain(0, 1);
    p->Population_Set_Search_Domain(0, 1);
}

// --------------------------------------------------------------------

void Set_Constr_EX_Function(Population *p) {

    const string f1 = "x1";
    const string f2 = "(1 + x2) / x1";

    p->Population_Set_Goal_Function(f1);
    p->Population_Set_Goal_Function(f2);

    p->Population_Initialization(0, 5);

    p->Population_Set_Search_Domain(0.1, 1);
    p->Population_Set_Search_Domain(0, 5);
}

// --------------------------------------------------------------------

void Population_Set_Muratas_Function(Population *p) {
    
    const string f1 = "2 * sqrt(x1)";
    const string f2 = "x1 * (1 - x2) + 5";
    
    p->Population_Set_Goal_Function(f1);
    p->Population_Set_Goal_Function(f2);

    p->Population_Set_Search_Domain(1, 4);
    p->Population_Set_Search_Domain(1, 2);

    p->Population_Initialization(1, 4);
}

// --------------------------------------------------------------------

void Population_Set_Viennet_Function(Population *p) {

    const string f1 = "0.5 * (x1^2 + x2^2) + sin(x1^2 + x2^2)";
    const string f2 = "( (3 * x1 - 2 * x2 + 4) / 8 ) + ( (x1 - x2 + 1)^2 / 27 ) + 15";
    const string f3 = "( 1 / (x1^2 + x2^2 + 1) ) - 1.1 * exp( -(x1^2 + x2^2) )";

    p->Population_Set_Goal_Function(f1);
    p->Population_Set_Goal_Function(f2);
    p->Population_Set_Goal_Function(f3);

    p->Population_Initialization(-3, 3);

    p->Population_Set_Search_Domain(-3, 3);
    p->Population_Set_Search_Domain(-3, 3);
}

// --------------------------------------------------------------------

#endif /* Test_Functions_h */
