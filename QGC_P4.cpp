#include "QGC_P4.h"

QGC_P4::QGC_P4(Funcao* integrando) {
  this->integrando = integrando;
}

double QGC_P4::integrar() {

  double x1 = -sqrt(2.0+sqrt(2.0))/2.0;
  double x2 = -sqrt(2.0-sqrt(2.0))/2.0;
  double x3 = sqrt(2.0-sqrt(2.0))/2.0;
  double x4 = sqrt(2.0+sqrt(2.0))/2.0;
  double w1 = M_PI/4.0;
  double w2 = M_PI/4.0;
  double w3 = M_PI/4.0;
  double w4 = M_PI/4.0;
  double fx1 = (integrando->f(x1))/(1.0/sqrt(1.0-x1*x1));
  double fx2 = (integrando->f(x2))/(1.0/sqrt(1.0-x2*x2));
  double fx3 = (integrando->f(x3))/(1.0/sqrt(1.0-x3*x3));
  double fx4 = (integrando->f(x4))/(1.0/sqrt(1.0-x4*x4));

  return (w1*fx1 + w2*fx2 + w3*fx3 + w4*fx4);
  
}