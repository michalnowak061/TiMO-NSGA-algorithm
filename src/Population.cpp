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
        //cout << i1->Fenotype[i] << endl;
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
        //cout << i1->Genotype[i] << endl;
    }
}

// --------------------------------------------------------------------

Individual Individual_Crossing(Individual i1, Individual i2) {
    
    Individual New_I;
    string Genotype1_Temp;
    string Genotype2_Temp;
    string New_Genotype_Temp;
    
    int Rand_Temp = rand() % ( i1.Genotype.size()  * 64 );
    
    for(int i = 0; i < i1.Genotype.size() && i < i2.Genotype.size(); ++i) {
        
        Genotype1_Temp += i1.Genotype[i];
        Genotype2_Temp += i2.Genotype[i];
    }
    
    for(int i = 0; i < Genotype1_Temp.length() && i < Genotype2_Temp.length(); ++i) {
        
        if (i < Rand_Temp) {
            
            New_Genotype_Temp += Genotype1_Temp[i];
        }
        else {
            
            New_Genotype_Temp += Genotype2_Temp[i];
        }
    }
    
    for (int i = 0; i < New_Genotype_Temp.length() / 64; i++) {
        
        string temp;
        
        for (int j = i * (int)(New_Genotype_Temp.length()); j < New_Genotype_Temp.length(); ++j) {
            
            temp += New_Genotype_Temp[j];
        }
        
        New_I.Genotype.push_back(temp);
    }
    
    //cout << Genotype1_Temp << endl;
    //cout << Genotype2_Temp << endl;
    //cout << New_Genotype_Temp << endl;
    //cout << Rand_Temp << endl;
    
    return New_I;
}

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
