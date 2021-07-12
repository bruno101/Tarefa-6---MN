#include "QGL_P3.h"

QGL_P3::QGL_P3(Funcao* integrando) {
  this->integrando = integrando;
}

double QGL_P3::integrar() {

  double w1 = 0.4157745568;
  double w2 = 2.2942803603;
  double w3 = 6.2899450829;
  double x1 = 0.7110930099;
  double x2 = 0.2785177336;
  double x3 = 0.0103892565;
  double fx1 = (integrando->f(x1))/exp(-x1);
  double fx2 = (integrando->f(x2))/exp(-x2);
  double fx3 = (integrando->f(x3))/exp(-x3);

  return (w1*fx1 + w2*fx2 + w3*fx3);
  
}