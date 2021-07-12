#include "Integracao.h"

class QGH_P4 : 
   public Integracao {

  public:
    
    QGH_P4(Funcao* integrando);
    double integrar();

};