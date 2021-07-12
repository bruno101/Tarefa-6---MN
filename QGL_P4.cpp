#include "QGL_P4.h"

QGL_P4::QGL_P4(Funcao* integrando) {
  this->integrando = integrando;
}

double QGL_P4::integrar() {

  double x1 = 0.32255;
  double x2 = 1.7458;
  double x3 = 4.5366;
  double x4 = 9.3951;
  double w1 = 0.603158;
  double w2 = 0.357427;
  double w3 = 0.0388877;
  double w4 = 0.000539296;
  double fx1 = (integrando->f(x1))/exp(-x1);
  double fx2 = (integrando->f(x2))/exp(-x2);
  double fx3 = (integrando->f(x3))/exp(-x3);
  double fx4 = (integrando->f(x4))/exp(-x4);

  return (w1*fx1 + w2*fx2 + w3*fx3 + w4*fx4);
  
}