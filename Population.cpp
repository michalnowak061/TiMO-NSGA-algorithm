//
//  Population.cpp
//  TiMO_Projekt
//
//  Created by Michal on 06/03/2020.
//  Copyright © 2020 Michal_Nowak & Kacper_Stenka. All rights reserved.
//

#include "Population.hpp"

// --------------------------------------------------------------------

void Individual_Genotype_Coding(Individual *i1) {
    
    string s = "";
    unsigned long long x = 0;
    double d = 0;
    
    for(int i = 0; i < i1->Genotype.size(); ++i) {
        
        s = i1->Genotype[i];
        
        for (string::const_iterator i = s.begin(); i != s.end(); ++i) {
            
            x = (x << 1) + (*i - '0');
        }
        
        memcpy(&d, &x, 8);
        
        i1->Fenotype.push_back(d);
        cout << i1->Fenotype[i] << endl;
    }
}

// --------------------------------------------------------------------

void Individual_Fenotype_Decoding(Individual *i1) {
    
    string s = "";
    double d = 0;
    
    for (int i =0; i < i1->Fenotype.size(); ++i) {
        
        d = i1->Fenotype[i];
        s = bitset<sizeof d * 8>( *(long unsigned int*)(&d) ).to_string();
        
        i1->Genotype.push_back(s);
        cout << i1->Genotype[i] << endl;
    }
}

// --------------------------------------------------------------------

Individual Individual_Crossing(Individual i1, Individual i2);

// --------------------------------------------------------------------

void Individual_Mutation(Individual *i1);

// --------------------------------------------------------------------

void Individual_Adaptation(Individual *i1);

// --------------------------------------------------------------------

Population::Population() {
    
}

// --------------------------------------------------------------------

Population::~Population() {
    
}

// --------------------------------------------------------------------
