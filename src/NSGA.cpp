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
    
    for(int i = 0; i < p.Population_Size; ++i) {
        
        VARIABLE_TYPE F_sum = 0;
        //Individual I_Temp = Individual_Initialization(0);
        
        for(int j = 0; j < p.Goal_Functions_Number; ++j) {
            
            Individual I_Temp = p.Population_Get_Individual(i);
            string Goal_Function_Temp = p.Population_Get_Goal_Function(j);
            
            VARIABLE_TYPE adaptation = Individual_Adaptation(I_Temp, Goal_Function_Temp);
            New_Population.Population_Set_Adaptation(adaptation, i);
            
            F_sum +=  (j+1) * adaptation;
        }
        
        VARIABLE_TYPE Fitness_Temp = F_sum / p.Goal_Functions_Number;
        New_Population.Population_Set_Fitness(Fitness_Temp, i);
    }
    
    return New_Population;
}

void NSGA_Algorithm(int n, int N, int T, int P_c, int P_m) {
    
    Population Pt(n,N,P_c,P_m);
    Population P0(n,N,P_c,P_m);
    Population P1(n,N,P_c,P_m);
    Population P2(n,N,P_c,P_m);
    Population P3(n,N,P_c,P_m);
    
    // Step 1: Inititalization
    Pt.Population_Initialization(0, 4);
    P0.Population_Initialization(0, 4);
    P1.Population_Initialization(0, 4);
    P2.Population_Initialization(0, 4);
    P3.Population_Initialization(0, 4);
    
    P0.Population_Set_Goal_Function("x_0^2");
    P0.Population_Set_Goal_Function("(x_0-2)^2");
    
    P0.Population_Set_Search_Domain(0, 4);
    
    Pt = P0;
    
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
    //Pt = Pt.Population_Get_Non_Dominated();
    //Pt.Population_Save_To_File();
    //Pt.Population_Print();
}
