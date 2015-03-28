#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "metodos.h"

using namespace std;

/**
 * Função a ser analisada nos métodos numéricos
 * @param  x [Valor do ponto x]
 * @return   [F(x)]
 */
double funcao(double x);

/**
 * Função derivada da função principal da análise
 * @param  x [Valor do ponto x]
 * @return   [F'(x)]
 */
double funcao_derivada(double x);


int main(int argc, char **argv) {
  struct  s_result result;
  double  xl, xr;

  int opt, m;
  while ((opt = getopt(argc,argv,"m:l:r:")) != EOF)
    switch(opt){
      case 'm': m  = atoi(optarg); break;
      case 'l': xl = atof(optarg); break;
      case 'r': xr = atof(optarg); break;
      case '?': 
        cout << "Uso"                                 << endl;
        cout << "-m Metodo"                           << endl;
        cout << "\t 1 Bissecao"                       << endl;
        cout << "\t 2 Falsa Posicao "                 << endl;
        cout << "\t 3 Ponto Fixo "                    << endl;
        cout << "\t 4 Newton Raphson "                << endl;
        cout << "\t 5 Secante "                       << endl;
        cout << "-l Valor inicial do intervalo | 1º Estimativa da Raiz" << endl;
        cout << "-r Valor final do intervalo | 2º Estimativa da Raiz"   << endl;
      default: cout<<endl; abort();
    }

  switch(m){
    case 1: result = bissecao(xl,xr, funcao);       break;
    case 2: result = falsa_posicao(xl,xr, funcao);  break;
    case 3: result = ponto_fixo(xl, funcao);        break;
    case 4: result = newton_raphson(xl, funcao, funcao_derivada); break;
    case 5: result = secante(xl, xr, funcao);       break;
  }

  return 0;
}


/**
 * FUnção utilizada no ponto Fixo, função deve ser levemente modificada
 * @param  x [description]
 * @return   [description]
 */
double funcao_ponto_fixo(double x){
  return x - ((x/2 - tan(2*x))/(1/2 - pow(sec(2*x), 2)*2));
}

/**
 * Função básica para utilização dos métodos
 * @param  x [description]
 * @return   [description]
 */
double funcao(double x){
  return (x/2) - tan(2*x); 
}

/**
 * Derivada da função básica
 * @param  x [description]
 * @return   [description]
 */
double funcao_derivada(double x){
  return (1/2 - pow(sec(2*x), 2)*2);
}

