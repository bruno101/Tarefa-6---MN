#include "Integracao.h"

class QGL_P3 : 
   public Integracao {

  public:
    
    QGL_P3(Funcao* integrando);
    double integrar();

};