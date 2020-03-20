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

// --------------------------------------------------------------------

Population HLGA_Algorithm(Population P0, int T) {
    
    // Step 1: Inititalization
    Population Pt = P0;
    Population P1 = P0;
    Population P2 = P0;
    Population P3 = P0;
    
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
    Population A1 = Pt.Population_Get_Non_Dominated();
    A1.Population_Save_To_File("nondom.csv");
    
    Population A2 = Pt.Population_Get_Dominated();
    A2.Population_Save_To_File("dom.csv");
    //Population A = P1;
    
    return A1;
}

// --------------------------------------------------------------------
