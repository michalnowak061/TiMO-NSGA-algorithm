//
//  NSGA.hpp
//  TiMO_Projekt
//
//  Created by Michal on 08/03/2020.
//  Copyright © 2020 Michal_Nowak & Kacper_Stenka. All rights reserved.
//

#ifndef NSGA_hpp
#define NSGA_hpp

#include <stdio.h>
#include "Population.hpp"

using namespace std;

// --------------------------------------------------------------------

class NSGA {

private:

    vector<Population> NSGA_Populations_List;

    Population NSGA_P0;
    Population NSGA_Pt;

    double NSGA_Split_Function(double alpha, double q_share, Individual ii, Individual jj);
    void NSGA_Fitness_Scharing(Population *p, double Fd);
    Population NSGA_NonDominated_Sorting(Population P);

    double Niche_Radius;

protected:

public:

    NSGA();
    ~NSGA();

    void NSGA_Set_Population0(Population P0);
    void NSGA_Set_Niche_Radius(double radius);
    void NSGA_Algorithm();

    vector<Population> NSGA_Get_Population_List();
    Population NSGA_Get_Actual_Population();
    Population NSGA_Get_NonDom();
    Population NSGA_Get_Dom();
};

// --------------------------------------------------------------------


#endif /* NSGA_hpp */
