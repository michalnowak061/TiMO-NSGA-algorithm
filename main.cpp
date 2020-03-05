//
//  main.cpp
//  TiMO_Projekt
//
//  Created by Michal_Nowak & Kacper_Stenka on 02/03/2020.
//  Copyright © 2020 Michal_Nowak & Kacper_Stenka. All rights reserved.
//

#include <iostream>
#include "Math_Parser.hpp"

using namespace std;

int main( void ) {
    
    Math_Parser Parser_fx_1;
    Math_Parser Parser_fx_2;
    
    Parser_fx_1.Math_Parser_Add_Expression("x_1^2");
    
    Parser_fx_1.Math_Parser_Add_Variable("x_1", 2);
    Parser_fx_1.Math_Parser_Calculate();
    
    cout << "Wartosc f(x)_1: " << Parser_fx_1.Math_Parser_Get_Expression_Value() << endl;
    
    Parser_fx_1.Math_Parser_Add_Variable("x_1", 3);
    Parser_fx_1.Math_Parser_Calculate();
    
    cout << "Wartosc f(x)_1: " << Parser_fx_1.Math_Parser_Get_Expression_Value() << endl;
    
    Parser_fx_1.Math_Parser_Add_Expression("x_1^2");
    Parser_fx_1.Math_Parser_Add_Variable("x_1", 2);
    Parser_fx_1.Math_Parser_Calculate();
    
    Parser_fx_2.Math_Parser_Add_Expression("sqrt(x_1)");
    Parser_fx_2.Math_Parser_Add_Variable("x_1", 2);
    Parser_fx_2.Math_Parser_Add_Variable("x_2", 2);
    Parser_fx_2.Math_Parser_Add_Variable("x_3", 2);
    Parser_fx_2.Math_Parser_Calculate();
    
    cout << "Wartosc f(x)_2: " << Parser_fx_2.Math_Parser_Get_Expression_Value() << endl;
    
    return 0;
}
