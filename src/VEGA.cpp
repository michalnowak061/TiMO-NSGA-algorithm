//
//  VEGA.cpp
//  TiMO_Projekt
//
//  Created by Michal on 22/03/2020.
//  Copyright © 2020 Michal_Nowak & Kacper_Stenka. All rights reserved.
//

#include "VEGA.hpp"

Population VEGA_Fitness_And_Selection(Population p) {
    
    Population New_Population = p;
    New_Population.Population_Clear();
    
    Population Population_Temp1 = p;
    int k = p.Goal_Functions_Number;
    
    for(int i = 0; i < k; ++i) {
        
        string Adaptation_Function = p.Population_Get_Goal_Function(i);
        
        for(int j = 0; j < p.Population_Get_Population_Size(); ++j) {
            
            Individual I_Temp = p.Population_Get_Individual(j);
            double Fitness = Individual_Adaptation(I_Temp, Adaptation_Function);
            
            Population_Temp1.Population_Set_Fitness(Fitness, j);
        }
        
        Population Population_Temp2 = Population_Temp1.Population_Selection();
        
        for(int j = 0; j < p.Population_Get_Population_Size() / k; ++j) {
            
            Individual I_Temp = Population_Temp2.Population_Get_Individual(j);
            New_Population.Population_Set_Individual(I_Temp);
        }
    }
    
    return New_Population;
}

// --------------------------------------------------------------------

Population VEGA_Algorithm(Population P0, int T) {
    
    // Step 1: Inititalization
    Population Pt = P0;
    Population P1 = P0;
    Population P2 = P0;
    Population P3 = P0;
    
    int t = 0;
    
    while(1) {
        
        // Step 2: Adaptation and Selection
        P1 = VEGA_Fitness_And_Selection(Pt);
        
        P1.Population_Print();
        
        if(t > T) break;
        
        // Step 3: Crossing
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
    
    A_nondom.Population_Save_To_File("VEGA_Nondom");
    A_dom.Population_Save_To_File("VEGA_Dom");
    
    A_nondom.Population_Print();
    
    //P1.Population_Print();
    
    return A_nondom;
}

// --------------------------------------------------------------------
