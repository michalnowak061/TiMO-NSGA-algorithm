//
//  main.cpp
//  TiMO_Projekt
//
//  Created by Michal_Nowak & Kacper_Stenka on 02/03/2020.
//  Copyright © 2020 Michal_Nowak & Kacper_Stenka. All rights reserved.
//

#include <iostream>
#include "HLGA.hpp"

using namespace std;

int main( void ) {
    
    srand( (unsigned int)( time(NULL) ) );
    
    int n = 1;
    int N = 10000;
    int T = 2;
    int P_c = 70;
    int P_m = 1;
    
    HLGA_Algorithm(n, N, T, P_c, P_m);
    
    return 0;
}
