#ifndef _VISSAGE_H_
#define _VISSAGE_H_

#include <stdio.h>


#include "basetypes.h"
#include "coord3d.h"

namespace PTools
{

// class Rigidbody;

typedef double Mat33[3][3];

struct Vissage
{
private:

    PTools::Coord3D axetranslation; //vecteur unitaire directeur de l'axe de translation
    PTools::Coord3D point; //un point de l'axe de rotation
    dbl normtranslation; // scalar. t = normtranslation.axetranslation
    dbl matrot[3][3];  // variable a conserver ? 
    dbl angle;


public:
    void Print() {
          std::cout << "------ <vissage> --------" << std::endl ;
            std::cout << "axe translation: " ; 
            std::cout << axetranslation.toString();
            std::cout << "angle: " << angle <<"  norme translation:" << normtranslation << std::endl ; 
            std::cout << "vecteur translation (recalc): " << (normtranslation*axetranslation).toString() << std::endl;
            std::cout << "point axe: " << point.toString();
            std::cout << "matrice: " << std::endl;
            for (int i=0; i<3; i++)
            {
               for (int j=0; j<3; j++)
               {
                  printf("%8.3f ",matrot[i][j]) ;
               }
              printf("\n");
            }

            std::cout << "####### </vissage> #######" << std::endl ; 
        } 

friend Vissage superpose_sippl(const Rigidbody& ref, const Rigidbody& mob, int verbosity);
friend Vissage MatTrans2screw(Mat33 rotmatrix, Coord3D trans);
};


}

#endif // _VISSAGE_H_
