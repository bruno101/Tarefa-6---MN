#include "QGH_P3.h"

QGH_P3::QGH_P3(Funcao* integrando) {
  this->integrando = integrando;
}

double QGH_P3::integrar() {

  double x1 = -sqrt(3.0/2.0);
  double x2 = 0.0;
  double x3 = sqrt(3.0/2.0);
  double w1 = sqrt(M_PI)/6.0;
  double w2 = 2.0*sqrt(M_PI)/3.0;
  double w3 = sqrt(M_PI)/6.0;
  double fx1 = (integrando->f(x1))/exp(-x1*x1);
  double fx2 = (integrando->f(x2))/exp(-x2*x2);
  double fx3 = (integrando->f(x3))/exp(-x3*x3);

  return (w1*fx1 + w2*fx2 + w3*fx3);
  
}