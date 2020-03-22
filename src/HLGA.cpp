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
            
            F_sum += adaptation;
        }
        
        VARIABLE_TYPE Fitness_Temp = F_sum / p.Population_Size;
        New_Population.Population_Set_Fitness(Fitness_Temp, i);
    }
    
    return New_Population;
}

// --------------------------------------------------------------------

Population HLGA_Algorithm(Population P0, int T) {
    
    // Step 1: Inititalization
    Population Pt = P0;
    
    //cout << endl << "####################################################### INICJALIZACJA #######################################################" << endl;
    //Pt.Population_Print();
    
    int t = 0;
    
    while(1) {
        
        // Step 2: Adaptation
        Pt = HLGA_Fitness(Pt);
        
        //cout << endl << "####################################################### ADAPTACJA #######################################################" << endl;
        Pt.Population_Print();
        
        if(t > T) break;
        
        // Step 3: Selection
        Population P1 = Pt.Population_Selection();
        
        //cout << endl << "####################################################### SELEKCJA #######################################################" << endl;
        //P1.Population_Print();
        
        // Step 4: Crossing
        Population P2 = P1.Population_Crossing();
        
        //cout << endl << "####################################################### KRZYZOWANIE #######################################################" << endl;
        //P2.Population_Print();
        
        // Step 5: Mutation
        Population P3 = P2.Population_Mutation();
        
        //cout << endl << "####################################################### MUTACJA #######################################################" << endl;
        //P2.Population_Print();
        
        Pt = P3;
        
        cout << (double(t++) / double(T)) * 100 << " %"<<endl;
    }
    
    // Step 6: End
    Population A = Pt.Population_Get_Non_Dominated();
    
    cout << endl << "####################################################### POPULACJA A #######################################################" << endl;
    A.Population_Print();
    
    return A;
}

// --------------------------------------------------------------------
