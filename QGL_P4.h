#include "Integracao.h"

class QGL_P4 : 
   public Integracao {

  public:
    
    QGL_P4(Funcao* integrando);
    double integrar();

};