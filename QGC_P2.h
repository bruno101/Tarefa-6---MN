#include "Integracao.h"

class QGC_P2 : 
   public Integracao {

  public:
    
    QGC_P2(Funcao* integrando);
    double integrar();

};