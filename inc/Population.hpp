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

#define VARIABLE_TYPE double

using namespace std;

typedef struct {
    
    vector<string> Genotype;    // <- decoded binary representation of Fenotype
    vector<double> Fenotype;    // <- encoded representation of Genotype
    VARIABLE_TYPE Adaptation;   // <- value of the adaptation function
    
} Individual;

void Individual_Genotype_Coding(Individual *i1);
void Individual_Fenotype_Decoding(Individual *i1);

Individual Individual_Crossing(Individual i1, Individual i2);
void Individual_Mutation(Individual *i1);

void Individual_Adaptation(Individual *i1);

class Population {

private:
    
    int Population_Size;
    int Max_Population_Size;
    
    int Crossing_Probability;
    int Mutation_Probability;
    
protected:
    
public:
    Population();
    ~Population();
};

#endif /* Population_hpp */
