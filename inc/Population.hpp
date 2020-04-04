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
    VARIABLE_TYPE         Drawn_Probability;
    
} Individual;

Individual Individual_Initialization();

void Individual_Genotypes_Decoding(Individual *i1, vector<VARIABLE_TYPE> search_domain_min, vector<VARIABLE_TYPE> search_domain_max);
void Individual_Fenotypes_Coding(Individual *i1);

Individual *Individual_Crossing(Individual i1, Individual i2, int c_probability, vector<VARIABLE_TYPE> search_domain_min, vector<VARIABLE_TYPE> search_domain_max);
Individual  Individual_Mutation(Individual i1, int m_probability, vector<VARIABLE_TYPE> search_domain_min, vector<VARIABLE_TYPE> search_domain_max);

VARIABLE_TYPE Individual_Adaptation(Individual i1, string adaptation_function);

bool operator >= (const Individual i1, const Individual i2);
bool operator < (Individual i1, Individual i2);

bool Individual_Dominates(Individual individualToCheck, Individual individual);

// --------------------------------------------------------------------

class Population {
    
private:
    
    // Private variables
    int Work_Size;
    int Population_Size;
    
    int Crossing_Probability;
    int Mutation_Probability;
    
    vector<Individual> Individuals;
    vector<Individual> NonDom_Individuals;
    vector<Individual> Dom_Individuals;
    
    vector<string> Goal_Functions;
    
    vector<VARIABLE_TYPE> Search_Domain_MIN;
    vector<VARIABLE_TYPE> Search_Domain_MAX;
    
protected:
    
public:
    
    // Public methods
    Population();
    ~Population();
    
    void Population_Set_Parameters(int work_size,
                                   int population_size,
                                   int crossing_probability,
                                   int mutation_probability) {
        
        Work_Size = work_size;
        Population_Size = population_size;
        
        Crossing_Probability = crossing_probability;
        Mutation_Probability = mutation_probability;
    }
    
    void Population_Initialization(int min, int max);
    
    Population Population_Roulette_Selection(bool maximum);
    Population Population_Tournament_Selection(bool maximum, int T_Size);
    
    Population Population_Get_Non_Dominated();
    Population Population_Get_Dominated();
    
    void Population_Set_Search_Domain(VARIABLE_TYPE min, VARIABLE_TYPE max);
    
    void Population_Adaptation_Update();
    
    void Population_Set_Goal_Function(string goal_function);
    string Population_Get_Goal_Function(int index);
    
    void Population_Set_Individual(Individual i1);
    Individual Population_Get_Individual(int index);
    
    void Population_Set_Adaptation(VARIABLE_TYPE adaptation, int index);
    
    void Population_Set_Fitness(VARIABLE_TYPE fitness, int index);
    
    void Population_Save_To_File(string file_name);
    void Population_Print();
    
    void Population_Clear() {
        
        Individuals.clear();
    }
    
    int Population_Get_Size() {
        
        return (int)( Individuals.size() );
    }
    
    int Population_Get_Goal_Functions_Number() {
        
        return (int)( Goal_Functions.size() );
    }
    
    VARIABLE_TYPE Population_Get_Min_Fitness() {
        
        VARIABLE_TYPE min = numeric_limits<VARIABLE_TYPE>::max();
        
        for(int i = 0; i < Individuals.size(); ++i) {
            
            if( Individuals[i].Fitness <= min ) {
                
                min = Individuals[i].Fitness;
            }
        }
        
        return min;
    }
    
    void Population_Remove_Individual(int index) {
        
        Individuals.erase(Individuals.begin() + index);
    }
    
    Population Population_Delete_Return_NonDom();
    
    Population Population_Recombination();
};

// --------------------------------------------------------------------

#endif /* Population_hpp */
