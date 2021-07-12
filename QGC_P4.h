#include "Integracao.h"

class QGC_P4 : 
   public Integracao {

  public:
    
    QGC_P4(Funcao* integrando);
    double integrar();

};