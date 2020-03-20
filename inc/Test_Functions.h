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

void Population_Set_Schaffers_N1_Function(Population *p) {
    
    const string f1 = "x_0^2";
    const string f2 = "(x_0 - 2)^2";
    
    p->Population_Set_Goal_Function(f1);
    p->Population_Set_Goal_Function(f2);
    
    p->Population_Initialization(0, 4);
    p->Population_Set_Search_Domain(0, 4);
}

// --------------------------------------------------------------------

void Population_Set_Muratas_Function(Population *p) {
    
    const string f1 = "2 * sqrt(x_0)";
    const string f2 = "x_0 * (1 - x_1) + 5";
    
    p->Population_Set_Goal_Function(f1);
    p->Population_Set_Goal_Function(f2);
    
    p->Population_Initialization(1, 4);
    
    p->Population_Set_Search_Domain(1, 4);
    p->Population_Set_Search_Domain(1, 2);
}

// --------------------------------------------------------------------

void Population_Set_Polonis_Function(Population *p) {
    
    const string A1 = "0.5 * sin(1) - 2 * cos(1) + sin(2) - 1.5 * cos(2)";
    const string A2 = "1.5 * sin(1) - cos(1) + 2 * sin(2) - 0.5 * cos(2)";
    const string B1 = "0.5 * sin(x_0) - 2 * cos(x_0) + sin(x_1) - 1.5 * cos(x_1)";
    const string B2 = "1.5 * sin(x_0) - cos(x_0) + 2 * sin(x_1) - 0.5 * cos(x_1)";
    
    const string f1 = "1 + (" + A1 + " - " + B1 + ")^2" + " + " + "(" + A2 + " - " + B2 + ")^2";
    const string f2 = "(x_0 + 3)^2 + (x_1 + 1)^2";
    
    p->Population_Set_Goal_Function(f1);
    p->Population_Set_Goal_Function(f2);
    
    p->Population_Initialization(-3.14, 3.14);
    
    p->Population_Set_Search_Domain(-3.14, 3.14);
    p->Population_Set_Search_Domain(-3.14, 3.14);
}

// --------------------------------------------------------------------

void Constr_Ex_problem(Population *p) {
    
    const string f1 = "x_0";
    const string f2 = "(1 + x_1) / x_0";
    
    p->Population_Set_Goal_Function(f1);
    p->Population_Set_Goal_Function(f2);
    
    p->Population_Initialization(0, 5);
    
    p->Population_Set_Search_Domain(0.1, 1);
    p->Population_Set_Search_Domain(0, 5);
}

// --------------------------------------------------------------------

void Fonseca_Fleming_Function(Population *p, int n) {
    
    const string n_str = to_string(n);
    
    string sum_1;
    string sum_2;
    
    for(int i = 0; i < n; ++i) {
        
        sum_1 += " - (x_" + to_string(i) + " - (1 / sqrt(" + n_str + ")))^2";
    }
    
    for(int i = 0; i < n; ++i) {
        
        sum_2 += " - (x_" + to_string(i) + " + (1 / sqrt(" + n_str + ")))^2";
    }
    
    const string f1 = "1 - exp(" + sum_1 + ")";
    const string f2 = "1 - exp(" + sum_2 + ")";
    
    cout << f1 << endl;
    cout << f2 << endl;
    
    p->Population_Set_Goal_Function(f1);
    p->Population_Set_Goal_Function(f2);
    
    p->Population_Initialization(0, 4);
    
    for(int i = 0; i < n; ++i) {
        
        p->Population_Set_Search_Domain(-4, 4);
    }
}

// --------------------------------------------------------------------

#endif /* Test_Functions_h */
