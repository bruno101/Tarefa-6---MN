#include "Integracao.h"

class QGC_P3 : 
   public Integracao {

  public:
    
    QGC_P3(Funcao* integrando);
    double integrar();

};