#include "Integracao.h"

class QGH_P3 : 
   public Integracao {

  public:
    
    QGH_P3(Funcao* integrando);
    double integrar();

};