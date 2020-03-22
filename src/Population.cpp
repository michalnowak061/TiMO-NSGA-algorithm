//
//  Population.cpp
//  TiMO_Projekt
//
//  Created by Michal on 13/03/2020.
//  Copyright © 2020 Michal_Nowak & Kacper_Stenka. All rights reserved.
//

#include "Population.hpp"

// --------------------------------------------------------------------

Math_Parser Parser;

// --------------------------------------------------------------------

Individual Individual_Initialization(VARIABLE_TYPE fitness) {
    
    Individual I;
    
    I.Fitness = fitness;
    
    return I;
}

// --------------------------------------------------------------------

void Individual_Genotypes_Decoding(Individual *i1, vector<VARIABLE_TYPE> search_domain_min, vector<VARIABLE_TYPE> search_domain_max) {
    
    string s = "";
    unsigned long long x = 0;
    VARIABLE_TYPE d = 0;
    
    i1->Fenotypes.clear();
    
    for(int i = 0; i < i1->Genotypes.size(); ++i) {
        
        s = i1->Genotypes[i];
        
        for (string::const_iterator i = s.begin(); i != s.end(); ++i) {
            
            x = (x << 1) + (*i - '0');
        }
        
        memcpy(&d, &x, 8);
        
        VARIABLE_TYPE min = search_domain_min[i];
        VARIABLE_TYPE max = search_domain_max[i];
        
        if(d > max) {
            
            d = max;
            i1->Fenotypes.push_back(d);
            Individual_Fenotypes_Coding(i1);
            return;
        }
        else if(d < min) {
            
            d = min;
            i1->Fenotypes.push_back(d);
            Individual_Fenotypes_Coding(i1);
            return;
        }
        
        if( isnan(d) ) {
            
            d = 0;
        }
        
        i1->Fenotypes.push_back(d);
    }
}

// --------------------------------------------------------------------

void Individual_Fenotypes_Coding(Individual *i1) {
    
    string s = "";
    double d = 0;
    
    i1->Genotypes.clear();
    
    for (int i = 0; i < i1->Fenotypes.size(); ++i) {
        
        d = i1->Fenotypes[i];
        
        s = bitset<sizeof d * 8>( *(long unsigned int*)(&d) ).to_string();
        i1->Genotypes.push_back(s);
    }
}

// --------------------------------------------------------------------

Individual *Individual_Crossing(Individual i1, Individual i2, int c_probability, vector<VARIABLE_TYPE> search_domain_min, vector<VARIABLE_TYPE> search_domain_max) {
    
    Individual *New_I = new Individual[2];
    New_I[0] = Individual_Initialization(0);
    New_I[1] = Individual_Initialization(0);
    
    string Genotype1_Temp;
    string Genotype2_Temp;
    string New_Genotype_Temp1;
    string New_Genotype_Temp2;
    
    int Rand_Temp = rand() % ( i1.Genotypes.size() * ( 8 * sizeof(VARIABLE_TYPE) ) );
    int Rand_Propability_Temp = rand() % 100;
    
    for(int i = 0; i < i1.Genotypes.size() && i < i2.Genotypes.size(); ++i) {
        
        Genotype1_Temp += i1.Genotypes[i];
        Genotype2_Temp += i2.Genotypes[i];
    }
    
    for(int i = 0; i < Genotype1_Temp.length() && i < Genotype2_Temp.length(); ++i) {
        
        if (i < Rand_Temp) {
            
            New_Genotype_Temp1 += Genotype1_Temp[i];
            New_Genotype_Temp2 += Genotype2_Temp[i];
        }
        else {
            
            New_Genotype_Temp1 += Genotype2_Temp[i];
            New_Genotype_Temp2 += Genotype1_Temp[i];
        }
    }
    
    for(int i = 0; i < New_Genotype_Temp1.size() / ( 8 * sizeof(VARIABLE_TYPE) ); ++i) {
        
        string genotype1;
        string genotype2;
        
        int start = i * ( 8 * sizeof(VARIABLE_TYPE) );
        int legth = ( 8 * sizeof(VARIABLE_TYPE) );
        
        if(Rand_Propability_Temp < c_probability) {
            
            genotype1 = New_Genotype_Temp1.substr(start, legth);
            genotype2 = New_Genotype_Temp2.substr(start, legth);
            
            New_I[0].Genotypes.push_back(genotype1);
            New_I[1].Genotypes.push_back(genotype2);
        }
        else {
            
            genotype1 = Genotype1_Temp.substr(start, legth);
            genotype2 = Genotype2_Temp.substr(start, legth);
            
            New_I[0].Genotypes.push_back(genotype1);
            New_I[1].Genotypes.push_back(genotype2);
        }
        
        Individual_Genotypes_Decoding(&New_I[0], search_domain_min, search_domain_max);
        Individual_Genotypes_Decoding(&New_I[1], search_domain_min, search_domain_max);
    }
    
    return New_I;
}

// --------------------------------------------------------------------

Individual Individual_Mutation(Individual i1, int m_probability, vector<VARIABLE_TYPE> search_domain_min, vector<VARIABLE_TYPE> search_domain_max) {
    
    Individual New_I = Individual_Initialization(0);
    string Genotype_Temp;
    string temp = Genotype_Temp;
    
    for(int i = 0; i < i1.Genotypes.size(); ++i) {
        
        Genotype_Temp += i1.Genotypes[i];
        temp += i1.Genotypes[i];
    }
    
    for (int i = 0; i < Genotype_Temp.length(); ++i) {
        
        int Rand_Temp = rand() % 100;
        
        if(Rand_Temp < m_probability) {
            
            if(Genotype_Temp[i] == '0') temp[i] = '1';
            else temp[i] = '0';
        }
    }
    
    for(int i = 0; i < temp.length() / ( 8 * sizeof(VARIABLE_TYPE) ); ++i) {
        
        string genotype;
        
        int start = i * ( 8 * sizeof(VARIABLE_TYPE) );
        int legth = ( 8 * sizeof(VARIABLE_TYPE) );
        
        genotype = temp.substr(start, legth);
        
        New_I.Genotypes.push_back(genotype);
        Individual_Genotypes_Decoding(&New_I, search_domain_min, search_domain_max);
    }
    
    return New_I;
}

// --------------------------------------------------------------------

VARIABLE_TYPE Individual_Adaptation(Individual i1, string adaptation_function) {
    
    VARIABLE_TYPE Adaptation;
    
    Parser.Math_Parser_Add_Expression(adaptation_function);
    
    for (int i = 0; i < i1.Fenotypes.size(); ++i) {
        
        Parser.Math_Parser_Add_Variable("x_" + to_string(i), i1.Fenotypes[i]);
    }

    Parser.Math_Parser_Calculate();
    
    Adaptation = Parser.Math_Parser_Get_Expression_Value();
    
    Parser.Math_Parser_Clear_Expression();
    
    return Adaptation;
}

// --------------------------------------------------------------------

bool operator >= (Individual i1, Individual i2) {

    for(int i = 0; i < i1.Goals.size() && i < i2.Goals.size(); ++i){
     
        if( i1.Goals[i] < i2.Goals[i] ) {
            
            return false;
        }
    }
    
    return true;
}

// --------------------------------------------------------------------

Population::Population(int work_size,
                       int population_size,
                       int crossing_probability,
                       int mutation_probability) {
    
    Work_Size = work_size;
    Population_Size = population_size;
    
    Crossing_Probability = crossing_probability;
    Mutation_Probability = mutation_probability;
    
    Goal_Functions_Number = 0;
}

// --------------------------------------------------------------------

Population::~Population() {
    
    Individuals.clear();
    Search_Domain_MIN.clear();
    Search_Domain_MAX.clear();
    Goal_Functions.clear();
}

// --------------------------------------------------------------------

void Population::Population_Initialization(int min, int max) {
    
    for(int i = 0; i < Population_Size; ++i) {
        
        Individual I_Temp = Individual_Initialization(0);
        
        string Genotype_Rand;
        
        
        for (int j = 0; j < Work_Size; j++) {
            
            VARIABLE_TYPE Fenotype_Rand = (rand() % max) + min;
            I_Temp.Fenotypes.push_back(Fenotype_Rand);
        }
        
        Individual_Fenotypes_Coding(&I_Temp);
        Individuals.push_back(I_Temp);
    }
}

// --------------------------------------------------------------------

void Population::Population_Set_Search_Domain(VARIABLE_TYPE min, VARIABLE_TYPE max) {
    
    Search_Domain_MIN.push_back(min);
    Search_Domain_MAX.push_back(max);
}

// --------------------------------------------------------------------

void Population::Population_Set_Goal_Function(string goal_function) {
    
    Goal_Functions.push_back(goal_function);
    Goal_Functions_Number++;
}

// --------------------------------------------------------------------

string Population::Population_Get_Goal_Function(int index) {
    
    if(index < Goal_Functions_Number) {
        
        return Goal_Functions[index];
    }
    else {
        
        return 0;
    }
}

// --------------------------------------------------------------------

void Population::Population_Set_Individual(Individual i1) {
    
    Individuals.push_back(i1);
}

// --------------------------------------------------------------------

Individual Population::Population_Get_Individual(int index) {
    
    return Individuals[index];
}

// --------------------------------------------------------------------

void Population::Population_Set_Adaptation(VARIABLE_TYPE adaptation, int index) {
    
    Individuals[index].Goals.push_back(adaptation);
}

// --------------------------------------------------------------------

void Population::Population_Set_Fitness(VARIABLE_TYPE fitness, int index) {
    
    Individuals[index].Fitness = fitness;
}

// --------------------------------------------------------------------

Population Population::Population_Crossing() {
    
    Population New_Population(Work_Size, Population_Size, Crossing_Probability, Mutation_Probability);
    
    New_Population.Goal_Functions        = Goal_Functions;
    New_Population.Goal_Functions_Number = Goal_Functions_Number;
    New_Population.Search_Domain_MIN     = Search_Domain_MIN;
    New_Population.Search_Domain_MAX     = Search_Domain_MAX;
    
    for(int i = 0; i < Population_Size / 2; ++i) {
        
        int Temp_Rand_1 = 0;
        int Temp_Rand_2 = 0;
        
        while( Temp_Rand_1 == Temp_Rand_2 ) {
            
            Temp_Rand_1 = rand() % Individuals.size();
            Temp_Rand_2 = rand() % Individuals.size();
        }
        
        Individual Temp_i = Individuals[Temp_Rand_1];
        Individual Temp_j = Individuals[Temp_Rand_2];
        
        if( Temp_Rand_1 > Temp_Rand_2 ) {
            
            Individuals.erase(Individuals.begin() + Temp_Rand_1);
            Individuals.erase(Individuals.begin() + Temp_Rand_2);
        }
        else {
         
            Individuals.erase(Individuals.begin() + Temp_Rand_2);
            Individuals.erase(Individuals.begin() + Temp_Rand_1);
        }
        
        Individual *Individual_Childs =  new Individual[2];
        Individual_Childs = Individual_Crossing(Temp_i, Temp_j, Crossing_Probability, Search_Domain_MIN, Search_Domain_MAX);
        Individual Temp_k = Individual_Childs[0];
        Individual Temp_l = Individual_Childs[1];
        
        New_Population.Individuals.push_back(Temp_k);
        New_Population.Individuals.push_back(Temp_l);
        
        delete [] Individual_Childs;
    }
    
    return New_Population;
}

// --------------------------------------------------------------------

Population Population::Population_Mutation() {
    
    Population New_Population(Work_Size, Population_Size, Crossing_Probability, Mutation_Probability);
    
    New_Population.Goal_Functions        = Goal_Functions;
    New_Population.Goal_Functions_Number = Goal_Functions_Number;
    New_Population.Search_Domain_MIN     = Search_Domain_MIN;
    New_Population.Search_Domain_MAX     = Search_Domain_MAX;
    
    for(int i = 0; i < Population_Size; ++i) {
        
        Individual I_Temp = Individuals[i];
        
        I_Temp = Individual_Mutation(I_Temp, Mutation_Probability, Search_Domain_MIN, Search_Domain_MAX);
        New_Population.Individuals.push_back(I_Temp);
    }
    
    return New_Population;
}

// --------------------------------------------------------------------

Population Population::Population_Selection() {
    
    Population New_Population(Work_Size, Population_Size, Crossing_Probability, Mutation_Probability);
    
    New_Population.Goal_Functions        = Goal_Functions;
    New_Population.Goal_Functions_Number = Goal_Functions_Number;
    New_Population.Search_Domain_MIN     = Search_Domain_MIN;
    New_Population.Search_Domain_MAX     = Search_Domain_MAX;
    
    New_Population.Population_Clear();
    
    double Population_Fitness = 0;
    
    for(int i = 0; i < Individuals.size(); ++i) {
        
        Population_Fitness += Individuals[i].Fitness;
    }
    
    Population_Fitness /= Individuals.size();
    
    for(int i = 0; i < Individuals.size(); ++i) {
        
        double Fitness = Individuals[i].Fitness;
        Individuals[i].Drawn_Probability = 1 - (Fitness / Population_Fitness);
    }
    
    while( New_Population.Individuals.size() < Individuals.size() ) {
        
        double Probability = rand() % 1000;
        Probability /= 1000;
        
        int i = rand() % Individuals.size();
        
        if( isnan(Individuals[i].Drawn_Probability) ) Individuals[i].Drawn_Probability = 0;
        
        if( Probability <= Individuals[i].Drawn_Probability ) {
            
            New_Population.Individuals.push_back( Individuals[i] );
        }
        else {
            
            //cout << Probability << " <= " << Individuals[i].Drawn_Probability << endl;
        }
    }
    
    return New_Population;
}

// --------------------------------------------------------------------

Population Population::Population_Get_Non_Dominated() {
    
    // Variables:
    Population Non_Dominated(Work_Size, Population_Size, Crossing_Probability, Mutation_Probability);
    
    Non_Dominated.Goal_Functions        = Goal_Functions;
    Non_Dominated.Goal_Functions_Number = Goal_Functions_Number;
    Non_Dominated.Search_Domain_MIN     = Search_Domain_MIN;
    Non_Dominated.Search_Domain_MAX     = Search_Domain_MAX;
    
    Non_Dominated.Individuals = Individuals;
    
    // Step 1:
    for(int i = 0; i < Non_Dominated.Individuals.size(); ++i) {
        
        Individual I_Temp1 = Non_Dominated.Individuals[i];
        
        for(int j = i - 1; j < Non_Dominated.Individuals.size(); ++j) {
            
            Individual I_Temp2 = Non_Dominated.Individuals[j];
            
            if( I_Temp2 >= I_Temp1 ) {
                
                Non_Dominated.Individuals.erase(Non_Dominated.Individuals.begin() + j);
            }
        }
    }
    
    return Non_Dominated;
}

// --------------------------------------------------------------------

Population Population::Population_Get_Dominated() {
    
    // Variables:
    Population Dominated(Work_Size, Population_Size, Crossing_Probability, Mutation_Probability);
    Dominated.Goal_Functions        = Goal_Functions;
    Dominated.Goal_Functions_Number = Goal_Functions_Number;
    Dominated.Search_Domain_MIN     = Search_Domain_MIN;
    Dominated.Search_Domain_MAX     = Search_Domain_MAX;
    
    Population Temp(Work_Size, Population_Size, Crossing_Probability, Mutation_Probability);
    Temp.Goal_Functions        = Goal_Functions;
    Temp.Goal_Functions_Number = Goal_Functions_Number;
    Temp.Search_Domain_MIN     = Search_Domain_MIN;
    Temp.Search_Domain_MAX     = Search_Domain_MAX;
    
    Temp.Individuals = Individuals;
    
    // Step 1:
    for(int i = 0; i < Temp.Individuals.size(); ++i) {
        
        Individual I_Temp1 = Temp.Individuals[i];
        
        for(int j = i - 1; j < Temp.Individuals.size(); ++j) {
            
            Individual I_Temp2 = Temp.Individuals[j];
            
            if( I_Temp2 >= I_Temp1 ) {
                
                Temp.Individuals.erase(Temp.Individuals.begin() + j);
                Dominated.Individuals.push_back(I_Temp2);
            }
        }
    }
    
    return Dominated;
}

// --------------------------------------------------------------------

void Population::Population_Save_To_File(string file_name) {
    
    fstream file(file_name, std::ios::out | std::ios::trunc);

    if( file.good() ) {
        
        file << "T \t";
        
        for(int i = 0; i < Goal_Functions_Number; ++i) {
            
            file << "f(x)_" + to_string(i) + "\t";
        }
        
        file << "\n";

        for(int i = 0; i < Individuals.size(); i++) {
            
            string data;
            
            data += to_string(i) + "\t";
            
            for(int j = 0; j < Individuals[i].Goals.size(); ++j) {
                
                data += to_string( Individuals[i].Goals[j] ) + "\t";
            }
            
            data += "\n";
            
            file << data;
            file.flush();
        }

        file.close();
    }
    else {

        cout << "Nie mozna utworzyc pliku !" << endl;
    }
}

// --------------------------------------------------------------------

void Population::Population_Print() {
    
    cout << "--------------------------------------- POPULACJA ---------------------------------------" << endl;
    cout << "Rozmiar zadania: " << Work_Size << endl;
    cout << "Rozmiar populacji: " << Individuals.size() << endl;
    cout << "Prawdopodobienstwo krzyzowania: " << Crossing_Probability << " %" << endl;
    cout << "Prawdopodobienstwo mutacji: " << Mutation_Probability << " %" << endl;
    cout << "--------------------------------------- OSOBNIKI ----------------------------------------" << endl;
    
    for(int i = 0; i < Individuals.size(); ++i) {
        
        Individual I_Temp = Individuals[i];
        
        cout << "Osobnik: " << i << endl;
        
        for (int j = 0; j < I_Temp.Genotypes.size() && j < I_Temp.Fenotypes.size(); ++j) {
            
            cout << "x_" << j << "<" << Search_Domain_MIN[j] << "," << Search_Domain_MAX[j] << ">"
                 << ": "<< I_Temp.Genotypes[j] << " / " << I_Temp.Fenotypes[j] <<endl;
        }
        
        for(int k = 0; k < Goal_Functions.size() && k < Individuals[i].Goals.size(); ++k) {
            
            cout << "f(x)_" + to_string(k) << "[" << Goal_Functions[k] << "]" << ": " << Individuals[i].Goals[k] << endl;
        }
        
        cout << "Wsk.Przystosowania: " << Individuals[i].Fitness << endl;
        
        cout << "-----------------------------------------------------------------------------------------" << endl;
    }
}

// --------------------------------------------------------------------
