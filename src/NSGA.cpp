//
//  NSGA.cpp
//  TiMO_Projekt
//
//  Created by Michal_Nowak & Kacper_Stenka on 08/03/2020.
//  Copyright © 2020 Michal_Nowak & Kacper_Stenka. All rights reserved.
//

#include "NSGA.hpp"

double NSGA_Split_Function(double alpha, double q_share, Individual ii, Individual jj) {
    
    double d_ij = 0;
    double sd_ij = 0;
    
    // Step 1:
    for(int i = 0; i < ii.Fenotypes.size() && i < jj.Fenotypes.size(); ++i) {
        
        d_ij += pow( ( jj.Fenotypes[i] - ii.Fenotypes[i] ), 2);
    }
    
    d_ij = sqrt( d_ij );
    
    // Step 2:
    if( d_ij < q_share ) {
        
        sd_ij = 1 - pow( (d_ij / q_share), alpha);
    }
    else {
        
        sd_ij = 0;
    }
    
    cout << sd_ij << endl;
    
    return sd_ij;
}

Population NSGA_Fitness(Population p) {
    
    Population New_Population = p;
    
    
    
    return New_Population;
}

Population NSGA_Algorithm(Population P0, int T) {
    
    // Step 1: Inititalization
    Population Pt = P0;
    Population P1 = P0;
    Population P2 = P0;
    Population P3 = P0;
    
    int t = 0;
    
    while(1) {
        
        // Step 2: Adaptation
        Pt = NSGA_Fitness(Pt);
        
        // Step 3: Selection
        P1 = Pt.Population_Selection();
        
        if(t > T) break;
        
        // Step 4: Crossing
        P2 = P1.Population_Crossing();
        
        // Step 5: Mutation
        P3 = P2.Population_Mutation();
        
        Pt = P3;
        
        cout << (double(t++) / double(T)) * 100 << " %"<<endl;
    }
    
    // Step 6: End
    Population A_nondom = P1.Population_Get_Non_Dominated();
    Population A_dom    = P1.Population_Get_Dominated();
    
    for(int i = 0; i < A_nondom.Population_Get_Population_Size(); ++i) {
        
        for(int j = 0; j < A_nondom.Goal_Functions_Number; ++j) {
            
            Individual I_Temp = A_nondom.Population_Get_Individual(i);
            string Goal_Function_Temp = A_nondom.Population_Get_Goal_Function(j);
            
            VARIABLE_TYPE adaptation = Individual_Adaptation(I_Temp, Goal_Function_Temp);
            A_nondom.Population_Set_Adaptation(adaptation, i);
        }
    }
    
    for(int i = 0; i < A_dom.Population_Get_Population_Size(); ++i) {
        
        for(int j = 0; j < A_dom.Goal_Functions_Number; ++j) {
            
            Individual I_Temp = A_dom.Population_Get_Individual(i);
            string Goal_Function_Temp = A_dom.Population_Get_Goal_Function(j);
            
            VARIABLE_TYPE adaptation = Individual_Adaptation(I_Temp, Goal_Function_Temp);
            A_dom.Population_Set_Adaptation(adaptation, i);
        }
    }
    
    A_nondom.Population_Save_To_File("NSGA_Nondom");
    A_dom.Population_Save_To_File("NSGA_Dom");
    
    A_nondom.Population_Print();
    
    //P1.Population_Print();
    
    return A_nondom;
}
