//
//  Population.cpp
//  TiMO_Projekt
//
//  Created by Michal on 06/03/2020.
//  Copyright © 2020 Michal_Nowak & Kacper_Stenka. All rights reserved.
//

#include "Population.hpp"

// --------------------------------------------------------------------

Population::Population(int work_size, int p_size, int max_g_number, int c_probability, int m_probability) {
    
    Work_Size = work_size;
    
    Population_Size = p_size;
    Max_Generation_Number = max_g_number;
    
    Crossing_Probability = c_probability;
    Mutation_Probability = m_probability;
}

// --------------------------------------------------------------------

Population::~Population() {
    
    Individuals_List.clear();
}

// --------------------------------------------------------------------

void Population::Population_Init() {
    
    for (int i = 0; i < Population_Size; ++i) {
        
        Individual I_Temp;
        
        for (int j = 0; j < Work_Size; j++) {
            
            string Genotype_Temp;
            
            for (int k = 0; k < 8 * sizeof(VARIABLE_TYPE); ++k) {
                
                int Rand_Temp = rand() % 2;
                Genotype_Temp += to_string(Rand_Temp);
            }
            
            I_Temp.Genotype.push_back(Genotype_Temp);
        }
        
        Individual_Genotype_Coding(&I_Temp);
        Individuals_List.push_back(I_Temp);
    }
}

// --------------------------------------------------------------------

void Population::Population_Add_Adaptation_Function(string adaptation_function) {
    
    Adaptation_Functions_List.push_back(adaptation_function);
}

// --------------------------------------------------------------------

void Population::Population_Adaptation() {
    
    for(int i = 0; i < Individuals_List.size(); ++i) {
        
        VARIABLE_TYPE Temp_Adaptation = 0;
        
        for(int j = 0; j < Adaptation_Functions_List.size(); ++j) {
            
            Individuals_List[i].Adaptation.push_back( Individual_Adaptation(Individuals_List[i], Adaptation_Functions_List[j]) );
            Temp_Adaptation += Individuals_List[i].Adaptation[j];
            //cout << "Wartosc f(x)_" + to_string(j) << ": " << Individual_Adaptation(Individuals_List[i], Adaptation_Functions_List[j]) << endl;
        }
        
        Individuals_List[i].Adaptation_Factor = Temp_Adaptation / Work_Size;
    }
}

// --------------------------------------------------------------------

void Population::Population_Crossing() {
    
}

// --------------------------------------------------------------------

void Population::Population_Mutation() {
    
}

// --------------------------------------------------------------------

void Population::Population_Selection() {
    
}

// --------------------------------------------------------------------

void Population::Population_Print() {
    
    cout << "------------- POPULACJA -------------" << endl;
    cout << "Rozmiar populacji: " << Population_Size << endl;
    cout << "Ilosc pokoleń: " << Generation_Number << endl;
    cout << "------------- OSOBNIKI -------------" << endl;
    
    for(int i = 0; i < Individuals_List.size(); ++i) {
        
        Individual I_Temp = Individuals_List[i];
        
        cout << "Osobnik: " << i << endl;
        
        for (int j = 0; j < I_Temp.Genotype.size() && j < I_Temp.Fenotype.size(); ++j) {
            
            cout << "x_" << j << ": "<< I_Temp.Genotype[j] << " / " << I_Temp.Fenotype[j] <<endl;
        }
        
        for(int k = 0; k < Adaptation_Functions_List.size(); ++k) {
            
            cout << "f(x)_" + to_string(k) << "[" << Adaptation_Functions_List[k] << "]" << ": " << Individuals_List[i].Adaptation[k] << endl;
        }
    }
}

// --------------------------------------------------------------------
