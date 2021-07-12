#include "Integracao.h"

class QGH_P2 : 
   public Integracao {

  public:
    
    QGH_P2(Funcao* integrando);
    double integrar();

};