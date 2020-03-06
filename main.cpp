//
//  main.cpp
//  TiMO_Projekt
//
//  Created by Michal_Nowak & Kacper_Stenka on 02/03/2020.
//  Copyright © 2020 Michal_Nowak & Kacper_Stenka. All rights reserved.
//

#include <iostream>
#include "Math_Parser.hpp"
#include "Population.hpp"

using namespace std;

int main( void ) {
    
    srand( time(NULL) );
    
    /*
    Math_Parser Parser_fx_1;
    Math_Parser Parser_fx_2;
    
    Parser_fx_1.Math_Parser_Add_Expression("x_1^2");
    Parser_fx_1.Math_Parser_Add_Variable("x_1", 2);
    Parser_fx_1.Math_Parser_Calculate();
    
    Parser_fx_2.Math_Parser_Add_Expression("sqrt(x_1)");
    Parser_fx_2.Math_Parser_Add_Variable("x_1", 2);
    Parser_fx_2.Math_Parser_Add_Variable("x_2", 2);
    Parser_fx_2.Math_Parser_Add_Variable("x_3", 2);
    Parser_fx_2.Math_Parser_Calculate();
    
    cout << "Wartosc f(x)_1: " << Parser_fx_1.Math_Parser_Get_Expression_Value() << endl;
    cout << "Wartosc f(x)_2: " << Parser_fx_2.Math_Parser_Get_Expression_Value() << endl;
     */
    
    Individual I1;
    Individual I2;
    
    I1.Genotype.push_back("0011111111101111111101111100111011011001000101101000011100101011");
    I1.Genotype.push_back("0100000001011111110010000100000000111101110111011011000100100001");
    I2.Genotype.push_back("0100000001011111110010000100000000111101110111011011000100100001");
    I2.Genotype.push_back("0011111111101111111101111100111011011001000101101000011100101011");
    
    Individual_Genotype_Coding(&I1);
    //Individual_Fenotype_Decoding(&I1);
    
    //Individual_Crossing(I1, I2);
    Individual_Mutation(&I1);
    
    return 0;
}
