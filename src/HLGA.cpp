//
//  HLGA.cpp
//  TiMO_Projekt
//
//  Created by Michal_Nowak & Kacper_Stenka on 15/03/2020.
//  Copyright © 2020 Michal_Nowak & Kacper_Stenka. All rights reserved.
//

#include "HLGA.hpp"

Population HLGA_Fitness(Population p) {
    
    Population New_Population = p;
    
    for(int i = 0; i < p.Population_Size; ++i) {
        
        VARIABLE_TYPE F_sum = 0;
        
        for(int j = 0; j < p.Goal_Functions_Number; ++j) {
            
            Individual I_Temp = p.Population_Get_Individual(i);
            string Goal_Function_Temp = p.Population_Get_Goal_Function(j);
            
            VARIABLE_TYPE adaptation = Individual_Adaptation(I_Temp, Goal_Function_Temp);
            New_Population.Population_Set_Adaptation(adaptation, i);
            
            F_sum += (j+1) * adaptation;
        }
        
        VARIABLE_TYPE Fitness_Temp = F_sum / p.Goal_Functions_Number;
        New_Population.Population_Set_Fitness(Fitness_Temp, i);
    }
    
    return New_Population;
}

void HLGA_Algorithm(int n, int N, int T, int P_c, int P_m) {
    
    Population Pt(n,N,P_c,P_m);
    Population P0(n,N,P_c,P_m);
    Population P1(n,N,P_c,P_m);
    Population P2(n,N,P_c,P_m);
    Population P3(n,N,P_c,P_m);
    
    // Step 1: Inititalization
    Pt.Population_Initialization(-4, 4);
    P0.Population_Initialization(0, 1);
    P1.Population_Initialization(0, 1);
    P2.Population_Initialization(0, 1);
    P3.Population_Initialization(0, 1);
    
    P0.Population_Set_Goal_Function("2*x_0^4-6*x_0^2-8");
    
    P0.Population_Set_Search_Domain(-4, 4);
    
    Pt = P0;
    
    //Pt.Population_Print();
    
    int t = 0;
    
    while(1) {
        
        // Step 2: Adaptation
        Pt = HLGA_Fitness(Pt);
        
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
    Pt.Population_Save_To_File();
    Pt.Population_Print();
}
