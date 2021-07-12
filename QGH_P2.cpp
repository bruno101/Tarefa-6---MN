#include "QGH_P2.h"

QGH_P2::QGH_P2(Funcao* integrando) {
  this->integrando = integrando;
}

double QGH_P2::integrar() {

  double x1 = -1.0/sqrt(2.0);
  double x2 = 1.0/sqrt(2.0);
  double w1 = sqrt(M_PI)/2.0;
  double w2 = sqrt(M_PI)/2.0;
  double fx1 = (integrando->f(x1))/exp(-x1*x1);
  double fx2 = (integrando->f(x2))/exp(-x2*x2);

  return (w1*fx1 + w2*fx2);
  
}