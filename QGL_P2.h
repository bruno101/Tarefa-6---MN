#include "Integracao.h"

class QGL_P2 : 
   public Integracao {

  public:
    
    QGL_P2(Funcao* integrando);
    double integrar();

};