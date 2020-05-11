//
//  VEGA.cpp
//  TiMO_Projekt
//
//  Created by Michal on 22/03/2020.
//  Copyright © 2020 Michal_Nowak & Kacper_Stenka. All rights reserved.
//

#include "VEGA.hpp"

// --------------------------------------------------------------------

VEGA::VEGA() {
    
}

// --------------------------------------------------------------------

VEGA::~VEGA() {
    
}

// --------------------------------------------------------------------

void VEGA::VEGA_Set_Population0(Population P0) {
    
    P0.Population_Adaptation_Update();

    VEGA_P0.Population_Clear();
    VEGA_Pt.Population_Clear();

    VEGA_P0 = P0;
    VEGA_Pt = P0;

    VEGA_Populations_List.clear();
    VEGA_Populations_List.push_back( P0 );
}

// --------------------------------------------------------------------

Population VEGA::VEGA_Fitness_And_Selection(Population P) {
    
    P.Population_Adaptation_Update();
    
    Population New_Population = P;
    New_Population.Population_Clear();
    
    Population Population_Temp1 = P;
    int k = P.Population_Get_Goal_Functions_Number();
    
    for(int i = 0; i < k; ++i) {
        
        string Adaptation_Function = P.Population_Get_Goal_Function(i);
        
        for(int j = 0; j < P.Population_Get_Size(); ++j) {
            
            Individual I_Temp = P.Population_Get_Individual(j);
            double Fitness = Individual_Adaptation(I_Temp, Adaptation_Function);
            
            Population_Temp1.Population_Set_Fitness(Fitness, j);
        }
        
        //Population Population_Temp2 = Population_Temp1.Population_Roulette_Selection(false);
        Population Population_Temp2 = Population_Temp1.Population_Tournament_Selection(false, 10);
        
        for(int j = 0; j < P.Population_Get_Size() / k; ++j) {
            
            Individual I_Temp = Population_Temp2.Population_Get_Individual(j);
            New_Population.Population_Set_Individual(I_Temp);
        }
    }
    
    return New_Population;
}

// --------------------------------------------------------------------

void VEGA::VEGA_Algorithm() {
        
    // Step 1: Crossing and Mutation
    VEGA_Pt = VEGA_Pt.Population_Recombination();
    
    // Step 2: Adaptation and Selection
    VEGA_Pt = VEGA_Fitness_And_Selection(VEGA_Pt);

    VEGA_Populations_List.push_back( VEGA_Pt );
}

// --------------------------------------------------------------------

vector<Population> VEGA::VEGA_Get_Population_List() {

    return VEGA_Populations_List;
}

// --------------------------------------------------------------------

Population VEGA::VEGA_Get_Actual_Population() {
    
    return VEGA_Pt;
}

// --------------------------------------------------------------------

Population VEGA::VEGA_Get_NonDom() {
    
    Population P_Temp1 = VEGA_Pt;
    
    P_Temp1.Population_Adaptation_Update();
    
    Population P_Temp2 = P_Temp1.Population_Delete_Return_NonDom();
    
    return P_Temp2;
}

// --------------------------------------------------------------------

Population VEGA::VEGA_Get_Dom() {
    
    Population P_Temp = VEGA_Pt;
    
    P_Temp.Population_Adaptation_Update();
    
    P_Temp.Population_Delete_Return_NonDom();
    
    return P_Temp;
}

// --------------------------------------------------------------------
