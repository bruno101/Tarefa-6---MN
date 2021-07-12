#include "QGC_P3.h"

QGC_P3::QGC_P3(Funcao* integrando) {
  this->integrando = integrando;
}

double QGC_P3::integrar() {

  double x1 = -sqrt(3.0)/2.0;
  double x2 = 0.0;
  double x3 = sqrt(3.0)/2.0;
  double w1 = M_PI/3.0;
  double w2 = M_PI/3.0;
  double w3 = M_PI/3.0;
  double fx1 = (integrando->f(x1))/(1.0/sqrt(1.0-x1*x1));
  double fx2 = (integrando->f(x2))/(1.0/sqrt(1.0-x2*x2));
  double fx3 = (integrando->f(x3))/(1.0/sqrt(1.0-x3*x3));

  return (w1*fx1 + w2*fx2 + w3*fx3);
  
}