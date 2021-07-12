#include <iostream>
#include "Funcao01.h"
#include "Funcao02.h"
#include "Funcao03.h"
#include "Funcao04.h"
#include "Funcao05.h"
#include "Funcao06.h"
#include "Funcao07.h"
#include "NC_A_P1.h"
#include "NC_F_P1.h"
#include "NC_A_P2.h"
#include "NC_F_P2.h"
#include "NC_A_P3.h"
#include "NC_F_P3.h"
#include "NC_A_P4.h"
#include "NC_F_P4.h"
#include "GL_P2.h"
#include "GL_P3.h"
#include "GL_P4.h"
#include "QGL_P2.h"
#include "QGL_P3.h"
#include "QGL_P4.h"
#include "QGH_P2.h"
#include "QGH_P3.h"
#include "QGH_P4.h"
#include "QGC_P2.h"
#include "QGC_P3.h"
#include "QGC_P4.h"
#include "Funcao.h"
#include "Integracao.h"

using namespace std;

int main() {

  int no_fechada_ou_aberta = 0;
  int grau_polinomio_substituicao = -1;
  int no_gauss_ou_newton_ou_quadratura;
  int particao_ou_precisao = 0;
  int numero_de_particoes = 0;
  int id_integrando = 0;
  int no_pontos;
  Funcao *integrando = 0;
  Integracao *pintegrObj;

  double a = -1.0;
  double b = 1.0;
  double precisao = 0.000001;
  double integral;

  cout << "Escolha a função a ser integrada: \n";
  cout << "\t1 - x^3 \n";
  cout << "\t2 - sin(x) \n";
  cout << "\t3 - cos(x) \n";
  cout << "\t4 - (sen(2x)+4x^2+3x)^2 \n";
  cout << "\t5 - (e^(-x^2)*(x+1)) \n";
  cout << "\t6 - (e^(-x)*(x+1)) \n";
  cout << "\t7 - ((1/sqrt(1-x^2))*(x+1))\n";
  cin >> id_integrando;
  switch (id_integrando) {
    case 1:
       integrando = new Funcao01;
       break;
    case 2:
       integrando = new Funcao02;
       break;
    case 3:
       integrando = new Funcao03;
       break;
    case 4:
       integrando = new Funcao04;
       break;
    case 5:
       integrando = new Funcao05;
       break;
    case 6:
       integrando = new Funcao06;
       break;
    case 7:
       integrando = new Funcao07;
       break;
  }

  cout << "Escolha entre Gauss-Legendre, Newton-Cotes ou quadraturas especiais\n";
  cout << "1 - Gauss-Legendre\n";
  cout << "2 - Newton-Cotes\n";
  cout << "3 - Quadraturas especiais\n";
  cin >> no_gauss_ou_newton_ou_quadratura;

  switch (no_gauss_ou_newton_ou_quadratura) {
    case 1:

      cout << "Escolha o valor de a: \n";
      cin >> a;

      cout << "Escolha o valor de b: \n";
      cin >> b;

      cout << "Escolha o número de pontos: \n";
      cout << "2 - 2 Pontos\n";
      cout << "3 - 3 Pontos\n";
      cout << "4 - 4 Pontos\n";
      cin >> no_pontos;

      cout << "Escolha entre partição e precisão: \n";
      cout << "1 - Partição \n";
      cout << "2 - Precisão \n";
      cin >> particao_ou_precisao;

      if (particao_ou_precisao == 1) {
        cout << "Escolha o número de partições: \n";
        cin >> numero_de_particoes;
      } else {
        cout << "Escolha a precisão: \n";
        cin >> precisao;
      }

      switch (no_pontos) {
        case 2:
          pintegrObj = new GL_P2(integrando, a, b, particao_ou_precisao, numero_de_particoes, precisao);
          integral = pintegrObj->integrar();
        break;  

        case 3:
          pintegrObj = new GL_P3(integrando, a, b, particao_ou_precisao, numero_de_particoes, precisao);
          integral = pintegrObj->integrar();
        break;

        case 4:
          pintegrObj = new GL_P4(integrando, a, b, particao_ou_precisao, numero_de_particoes, precisao);
          integral = pintegrObj->integrar();
        break;

      }

      break;

    case 2:

      cout << "Escolha o valor de a: \n";
      cin >> a;

      cout << "Escolha o valor de b: \n";
      cin >> b;

      cout << "Escolha entre a filosofia aberta a fechada: \n";
      cout << "1 - Aberta \n";
      cout << "2 - Fechada \n";
      cin >> no_fechada_ou_aberta;

      cout << "Escolha o grau do polinômio de substituição: \n";
      cout << "1 - Grau 1 \n";
      cout << "2 - Grau 2 \n";
      cout << "3 - Grau 3 \n";
      cout << "4 - Grau 4 \n";
      cin >> grau_polinomio_substituicao;

      cout << "Escolha entre partição e precisão: \n";
      cout << "1 - Partição \n";
      cout << "2 - Precisão \n";
      cin >> particao_ou_precisao;

      if (particao_ou_precisao == 1) {
        cout << "Escolha o número de partições: \n";
        cin >> numero_de_particoes;
      } else {
        cout << "Escolha a precisão: \n";
        cin >> precisao;
      }

      switch (no_fechada_ou_aberta) {
        case 1:
       
           switch (grau_polinomio_substituicao) {
             case 1:
                pintegrObj = new NC_A_P1(integrando, a, b, particao_ou_precisao, numero_de_particoes, precisao);
                integral = pintegrObj->integrar();
            break;

             case 2:
                pintegrObj = new NC_A_P2(integrando, a, b, particao_ou_precisao, numero_de_particoes, precisao);
                integral = pintegrObj->integrar();
                break;

             case 3:
                pintegrObj = new NC_A_P3(integrando, a, b, particao_ou_precisao, numero_de_particoes, precisao);
                integral = pintegrObj->integrar();
                break;

             case 4:
                pintegrObj = new NC_A_P4(integrando, a, b, particao_ou_precisao, numero_de_particoes, precisao);
                integral = pintegrObj->integrar();
                break;

           }
           break;

        case 2:

           switch (grau_polinomio_substituicao) {
             case 1:
                pintegrObj = new NC_F_P1(integrando, a, b, particao_ou_precisao, numero_de_particoes, precisao);
                integral = pintegrObj->integrar();
                break;

             case 2:
                pintegrObj = new NC_F_P2(integrando, a, b, particao_ou_precisao, numero_de_particoes, precisao);
                integral = pintegrObj->integrar();
                break;

             case 3:
                pintegrObj = new NC_F_P3(integrando, a, b, particao_ou_precisao, numero_de_particoes, precisao);
            integral = pintegrObj->integrar();
                break;

             case 4:
                pintegrObj = new NC_F_P4(integrando, a, b, particao_ou_precisao, numero_de_particoes, precisao);
                integral = pintegrObj->integrar();
                break;
           }
           break;
      }

      case 3:

        int tipo_quadratura;

        cout << "Escolha o tipo de quadatura: \n";
        cout << "1 - Gauss-Hermite\n";
        cout << "2 - Gauss-Laguerre\n";
        cout << "3 - Gauss-Chebyshev\n";
        cin >> tipo_quadratura;

        cout << "Escolha o grau do polinômio de substituição: \n";
        cout << "2 - Grau 2 \n";
        cout << "3 - Grau 3 \n";
        cout << "4 - Grau 4 \n";
        cin >> grau_polinomio_substituicao;

        switch (tipo_quadratura) {
          case 1:
            switch (grau_polinomio_substituicao) {
              case 2:
                pintegrObj = new QGH_P2(integrando);
                integral = pintegrObj->integrar();
                break;
              case 3:
                pintegrObj = new QGH_P3(integrando);
                integral = pintegrObj->integrar();
                break;
              case 4:
                pintegrObj = new QGH_P4(integrando);
                integral = pintegrObj->integrar();
                break;
            }
          break;

          case 2:
            switch (grau_polinomio_substituicao) {
              case 2:
                pintegrObj = new QGL_P2(integrando);
                integral = pintegrObj->integrar();
                break;
              case 3:
                pintegrObj = new QGL_P3(integrando);
                integral = pintegrObj->integrar();
                break;
              case 4:
                pintegrObj = new QGL_P4(integrando);
                integral = pintegrObj->integrar();
                break;
            }
          break;

          case 3:
            switch (grau_polinomio_substituicao) {
              case 2:
                pintegrObj = new QGC_P2(integrando);
                integral = pintegrObj->integrar();
                break;
              case 3:
                pintegrObj = new QGC_P3(integrando);
                integral = pintegrObj->integrar();
                break;
              case 4:
                pintegrObj = new QGC_P4(integrando);
                integral = pintegrObj->integrar();
                break;
            }
          break;

          break;
        }

  break;

  }

  cout << "O valor da integral é : " << integral;

}