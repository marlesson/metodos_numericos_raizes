#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "metodos.h"

using namespace std;
#define PI 3.14159265358979323846
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

/**
 * Função que executa todas os métodos para um determinado intervalo
 */
void executa_todas();



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
    case 0: executa_todas();                          break;
    case 1: result = bissecao(xl,xr, funcao);       break;
    case 2: result = falsa_posicao(xl,xr, funcao);  break;
    case 3: result = ponto_fixo(xl, funcao);        break;
    case 4: result = newton_raphson(xl, funcao, funcao_derivada); break;
    case 5: result = secante(xl, xr, funcao);       break;
  }

  return 0;
}


double funcao_ponto_fixo(double x){
  return x - funcao(x)/funcao_derivada(x);
}

double funcao(double x){
  return (x/2) - tan(2*x); 
}

double funcao_derivada(double x){
  return (1/2 - pow(sec(2*x), 2)*2);
}

# define INTERVALOS 5

void executa_todas(){
  double intervalos[INTERVALOS][2] = {{-0.1, 0.1}, {1.86, 2.06}, {3.58, 3.78}, {5.22, 5.42}, {6.82, 7.02}};
  double xl, xr;
  struct s_result result;

  cout << "Executa todos os metodos" << endl;
  
  for(int i = 0; i < INTERVALOS; i++){
    xl = intervalos[i][0];
    xr = intervalos[i][1];
    cout << endl << "Bissecao (" << xl << ", " << xr << ")"<< endl << endl;
    
    result = bissecao(xl,xr, funcao);
    cout << "RESULTADO ("<< result.interacoes << ", " << result.raiz << ")" << endl;
  }

  for(int i = 0; i < INTERVALOS; i++){
    xl = intervalos[i][0];
    xr = intervalos[i][1];
    cout << endl << "Falsa Posicao (" << xl << ", " << xr << ")"<< endl << endl;

    result = falsa_posicao(xl,xr, funcao);
    cout << "RESULTADO ("<< result.interacoes << ", " << result.raiz << ")" << endl;
  }

  for(int i = 0; i < INTERVALOS; i++){
    xl = intervalos[i][0];
    xr = intervalos[i][1];
    cout << endl << "Ponto Fixo  (" << xl << ", " << xr << ")"<< endl << endl;
    
    result = ponto_fixo(xl, funcao_ponto_fixo);
    cout << "RESULTADO ("<< result.interacoes << ", " << result.raiz << ")" << endl;
  }

  for(int i = 0; i < INTERVALOS; i++){
    xl = intervalos[i][0];
    xr = intervalos[i][1];
    cout << endl << "Newton Raphson (" << xl << ", " << xr << ")"<< endl << endl;
    
    result = newton_raphson(xl, funcao, funcao_derivada);
    cout << "RESULTADO ("<< result.interacoes << ", " << result.raiz << ")" << endl;
  }

  for(int i = 0; i < INTERVALOS; i++){
    xl = intervalos[i][0];
    xr = intervalos[i][1];
    cout << endl << "Secante (" << xl << ", " << xr << ")"<< endl << endl;
    
    result = secante(xl, xr, funcao); 
    cout << "RESULTADO ("<< result.interacoes << ", " << result.raiz << ")" << endl;
  }      
}