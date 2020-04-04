//
//  main.cpp
//  TiMO_Projekt
//
//  Created by Michal_Nowak & Kacper_Stenka on 02/03/2020.
//  Copyright © 2020 Michal_Nowak & Kacper_Stenka. All rights reserved.
//

#include <iostream>
#include "Test_Functions.h"
#include "VEGA.hpp"
#include "NSGA.hpp"

using namespace std;

int main( void ) {
    
    srand( (unsigned int)( time(NULL) ) );
    
    int n = 1;
    int N = 1000;
    int T = 50;
    int P_c = 90;
    int P_m = 1;
    
    Population P0;
    P0.Population_Set_Parameters(n, N, P_c, P_m);
    
    //Fonseca_Fleming_Function(&P0, n);
    //Kursawe_Function(&P0);
    Population_Set_Schaffers_N1_Function(&P0);
    //Population_Set_Polonis_Function(&P0);
    //Population_Set_Zitzler_Deb_Thieles_Function(&P0);
    
    //Population_Set_Muratas_Function(&P0);
    
    VEGA vega;
    vega.VEGA_Set_Population0(P0);
    
    NSGA nsga;
    nsga.NSGA_Set_Population0(P0);
    
    int t = 0;
    
    while( t <= T ) {
        
        //vega.VEGA_Algorithm();
        //vega.VEGA_Get_Actual_Population().Population_Print();
        
        nsga.NSGA_Algorithm();
        nsga.NSGA_Get_Actual_Population().Population_Print();
        
        cout << ( double(t++) / double(T) ) * 100 << " %" << endl;
    }
    
    Population Vega_A_nondom = vega.VEGA_Get_NonDom();
    Population Vega_A_dom    = vega.VEGA_Get_Dom();
    
    Vega_A_nondom.Population_Save_To_File("VEGA_Nondom.csv");
    Vega_A_dom.Population_Save_To_File("VEGA_dom.csv");
    
    Population Nsga_A_nondom = nsga.NSGA_Get_NonDom();
    Population Nsga_A_dom    = nsga.NSGA_Get_Dom();
    
    Nsga_A_nondom.Population_Save_To_File("NSGA_Nondom.csv");
    Nsga_A_dom.Population_Save_To_File("NSGA_dom.csv");

    return 0;
}
