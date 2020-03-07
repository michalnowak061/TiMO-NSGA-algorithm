//
//  Individual.hpp
//  TiMO_Projekt
//
//  Created by Michal_Nowak & Kacper_Stenka on 07/03/2020.
//  Copyright © 2020 Michal_Nowak & Kacper_Stenka. All rights reserved.
//

#ifndef Individual_hpp
#define Individual_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Math_Parser.hpp"

#define VARIABLE_TYPE double

using namespace std;

typedef struct {
    
    vector<string>        Genotype;             // <- decoded binary representation of Fenotype
    vector<VARIABLE_TYPE> Fenotype;             // <- encoded representation of Genotype
    vector<VARIABLE_TYPE> Adaptation;
    VARIABLE_TYPE         Adaptation_Factor;    // <- value of the adaptation function
    
} Individual;

void Individual_Genotype_Coding(Individual *i1);
void Individual_Fenotype_Decoding(Individual *i1);

Individual Individual_Crossing(Individual i1, Individual i2);
void Individual_Mutation(Individual *i1);

VARIABLE_TYPE Individual_Adaptation(Individual i1, string adaptation_function);

#endif /* Individual_hpp */
