//
//  main.cpp
//  TiMO_Projekt
//
//  Created by Michal_Nowak & Kacper_Stenka on 02/03/2020.
//  Copyright © 2020 Michal_Nowak & Kacper_Stenka. All rights reserved.
//

#include <iostream>
#include "Test_Functions.h"
#include "HLGA.hpp"
#include "VEGA.hpp"

using namespace std;

int main( void ) {
    
    srand( (unsigned int)( time(NULL) ) );
    
    int n = 1;
    int N = 50;
    int T = 400;
    int P_c = 60;
    int P_m = 1;
    
    Population P0(n,N,P_c,P_m);
    Population_Set_Schaffers_N1_Function(&P0);
    //Population_Set_Muratas_Function(&P0);
    //Population_Set_Polonis_Function(&P0);
    //Constr_Ex_problem(&P0);
    //Fonseca_Fleming_Function(&P0, 2);
    //Kursawe_Function(&P0);
    
    Population A = VEGA_Algorithm(P0, T);
    
    return 0;
}
