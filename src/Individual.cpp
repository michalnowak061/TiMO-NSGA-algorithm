//
//  Individual.cpp
//  TiMO_Projekt
//
//  Created by Michal on 07/03/2020.
//  Copyright © 2020 Michal_Nowak & Kacper_Stenka. All rights reserved.
//

#include "Individual.hpp"

Math_Parser Parser_fx;

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
    
    return New_I;
}

// --------------------------------------------------------------------

void Individual_Mutation(Individual *i1) {
    
    Individual New_I;
    string Genotype1_Temp;
    
    int Rand_Temp = rand() % ( i1->Genotype.size()  * 64 );
    
    for(int i = 0; i < i1->Genotype.size(); ++i) {
        
        Genotype1_Temp += i1->Genotype[i];
    }
    
    for (int i = 0; i < Genotype1_Temp.length() / 64; i++) {
        
        string temp;
        
        for (int j = i * (int)(Genotype1_Temp.length()); j < Genotype1_Temp.length(); ++j) {
            
            if(j == Rand_Temp) {
                
                if(Genotype1_Temp[j] == '0') temp += "1";
                else temp += "0";
            }
            else {
             
                temp += Genotype1_Temp[j];
            }
        }
        
        New_I.Genotype.push_back(temp);
    }
    
    i1->Genotype = New_I.Genotype;
}

// --------------------------------------------------------------------

VARIABLE_TYPE Individual_Adaptation(Individual i1, string adaptation_function) {
    
    VARIABLE_TYPE Adaptation;
    
    Parser_fx.Math_Parser_Add_Expression(adaptation_function);
    
    for (int i = 0; i < i1.Fenotype.size(); ++i) {
        
        Parser_fx.Math_Parser_Add_Variable("x_" + to_string(i), i1.Fenotype[i]);
        //cout << "x_" + to_string(i) << " " << i1.Fenotype[i] << endl;
    }

    Parser_fx.Math_Parser_Calculate();
    
    Adaptation = Parser_fx.Math_Parser_Get_Expression_Value();
    
    Parser_fx.Math_Parser_Clear_Expression();
    
    return Adaptation;
}

// --------------------------------------------------------------------
