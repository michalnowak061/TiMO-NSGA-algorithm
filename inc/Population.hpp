//
//  Population.hpp
//  TiMO_Projekt
//
//  Created by Michal on 13/03/2020.
//  Copyright © 2020 Michal_Nowak & Kacper_Stenka. All rights reserved.
//

#ifndef Population_hpp
#define Population_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Math_Parser.hpp"

#define VARIABLE_TYPE double

using namespace std;

// --------------------------------------------------------------------

typedef struct {
    
    vector<string>        Genotypes;
    vector<VARIABLE_TYPE> Fenotypes;
    vector<VARIABLE_TYPE> Goals;
    VARIABLE_TYPE         Fitness;
    
} Individual;

Individual Individual_Initialization(VARIABLE_TYPE fitness);

void Individual_Genotypes_Decoding(Individual *i1, vector<VARIABLE_TYPE> search_domain_min, vector<VARIABLE_TYPE> search_domain_max);
void Individual_Fenotypes_Coding(Individual *i1);

Individual *Individual_Crossing(Individual i1, Individual i2, int c_probability, vector<VARIABLE_TYPE> search_domain_min, vector<VARIABLE_TYPE> search_domain_max);
Individual  Individual_Mutation(Individual i1, int m_probability, vector<VARIABLE_TYPE> search_domain_min, vector<VARIABLE_TYPE> search_domain_max);

VARIABLE_TYPE Individual_Adaptation(Individual i1, string adaptation_function);

// --------------------------------------------------------------------

class Population {
    
private:
    
    // Private variables
    vector<Individual> Individuals;
    
    vector<VARIABLE_TYPE> Search_Domain_MIN;
    vector<VARIABLE_TYPE> Search_Domain_MAX;
    
protected:
    
public:
    
    // Public variables
    int Work_Size;
    int Population_Size;
    
    int Crossing_Probability;
    int Mutation_Probability;
    
    int Goal_Functions_Number;
    vector<string> Goal_Functions;
    
    // Public methods
    Population(int Work_Size,
                  int Population_Size,
                  int Crossing_Probability,
                  int Mutation_Probability);
    
    ~Population();
    
    void Population_Initialization(int min, int max);
    
    Population Population_Crossing();
    Population Population_Mutation();
    
    Population Population_Selection();
    
    Population Population_Get_Non_Dominated();
    
    void Population_Set_Search_Domain(VARIABLE_TYPE min, VARIABLE_TYPE max);
    
    void Population_Set_Goal_Function(string goal_function);
    string Population_Get_Goal_Function(int index);
    
    void Population_Set_Individual(Individual i1);
    Individual Population_Get_Individual(int index);
    
    void Population_Set_Adaptation(VARIABLE_TYPE adaptation, int index);
    
    void Population_Set_Fitness(VARIABLE_TYPE fitness, int index);
    
    void Population_Save_To_File();
    void Population_Print();
};

// --------------------------------------------------------------------

#endif /* Population_hpp */
