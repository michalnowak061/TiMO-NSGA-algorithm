//
//  VEGA.hpp
//  TiMO_Projekt
//
//  Created by Michal on 22/03/2020.
//  Copyright © 2020 Michal_Nowak & Kacper_Stenka. All rights reserved.
//

#ifndef VEGA_hpp
#define VEGA_hpp

#include <stdio.h>
#include "Population.hpp"

using namespace std;

// --------------------------------------------------------------------

class VEGA {
    
private:
    
    vector<Population> VEGA_Populations_List;

    Population VEGA_P0;
    Population VEGA_Pt;
    
    Population VEGA_Fitness_And_Selection(Population P);
    
protected:
    
public:
    
    VEGA();
    ~VEGA();
    
    void VEGA_Set_Population0(Population P0);
    
    void VEGA_Algorithm();
    
    vector<Population> VEGA_Get_Population_List();
    Population VEGA_Get_Actual_Population();
    Population VEGA_Get_NonDom();
    Population VEGA_Get_Dom();
};

// --------------------------------------------------------------------

#endif /* VEGA_hpp */
