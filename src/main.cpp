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
    
    srand( (unsigned int)( time(NULL) ) );
    
    
    Population P1(5,5,0,0,0);
    
    P1.Population_Init();
    
    P1.Population_Add_Adaptation_Function("x_0^2");
    P1.Population_Add_Adaptation_Function("x_1");
    P1.Population_Add_Adaptation_Function("x_2");
    P1.Population_Add_Adaptation_Function("x_3");
    P1.Population_Add_Adaptation_Function("x_4");
    
    P1.Population_Adaptation();
    
    P1.Population_Print();
    
    
    return 0;
}
