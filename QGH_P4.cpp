#include "QGH_P4.h"
#include "iostream"

QGH_P4::QGH_P4(Funcao* integrando) {
  this->integrando = integrando;
}

double QGH_P4::integrar() {

  double x1 = -sqrt((3.0+sqrt(6.0))/2.0);
  double x2 = -sqrt((3.0-sqrt(6.0))/2.0);
  double x3 = sqrt((3.0-sqrt(6.0))/2.0);
  double x4 = sqrt((3.0+sqrt(6.0))/2.0);
  double w1 = sqrt(M_PI)/(12+4*sqrt(6.0));
  double w2 = sqrt(M_PI)/(12-4*sqrt(6.0));
  double w3 = sqrt(M_PI)/(12-4*sqrt(6.0));
  double w4 = sqrt(M_PI)/(12+4*sqrt(6.0));
  double fx1 = (integrando->f(x1))/exp(-x1*x1);
  double fx2 = (integrando->f(x2))/exp(-x2*x2);
  double fx3 = (integrando->f(x3))/exp(-x3*x3);
  double fx4 = (integrando->f(x4))/exp(-x4*x4);

  return (w1*fx1 + w2*fx2 + w3*fx3 + w4*fx4);
  
}