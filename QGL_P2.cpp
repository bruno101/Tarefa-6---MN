#include "QGL_P2.h"

QGL_P2::QGL_P2(Funcao* integrando) {
  this->integrando = integrando;
}

double QGL_P2::integrar() {

  double x1 = 2.0-sqrt(2.0);
  double x2 = 2.0+sqrt(2.0);
  double w1 = (2.0+sqrt(2.0))/4.0;
  double w2 = (2.0-sqrt(2.0))/4.0;
  double fx1 = (integrando->f(x1))/exp(-x1);
  double fx2 = (integrando->f(x2))/exp(-x2);

  return (w1*fx1 + w2*fx2);
  
}