//
//  Population.hpp
//  TiMO_Projekt
//
//  Created by Michal on 06/03/2020.
//  Copyright © 2020 Michal_Nowak & Kacper_Stenka. All rights reserved.
//

#ifndef Population_hpp
#define Population_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Individual.hpp"

using namespace std;

class Population {

private:
    
    int Population_Size;
    int Generation_Number;
    int Max_Generation_Number;
    
    int Crossing_Probability;
    int Mutation_Probability;
    
    vector<Individual> Individuals_List;
    vector<string> Adaptation_Functions_List;
    
    int Work_Size;
    
protected:
    
public:
    Population(int work_size, int p_size, int max_g_number, int c_probability, int m_probability);
    ~Population();
    
    void Population_Init();
    void Population_Add_Adaptation_Function(string adaptation_function);
    void Population_Adaptation();
    void Population_Crossing();
    void Population_Mutation();
    void Population_Selection();
    void Population_Print();
};

#endif /* Population_hpp */
