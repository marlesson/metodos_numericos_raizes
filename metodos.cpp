#include <iostream>
#include <cmath>
#include <iomanip>

#include "metodos.h"

using namespace std;

void exibe_status(int i, double xl, double xr, double x, double ea);

double sec(double x){
  return 1/cos(x);
}

s_result bissecao(double xl, double xr, double (*funcao)(double)){
  struct s_result result;
  double x   = xl;
  double ea  = 100;
  double fl  = funcao(xl);
  double fx;
  double x_old;

  int   i   = 1;
  while(ea > ERRO && i <= I_MAX){
    x_old   = x;
    x       = (xl + xr)/2;
    fx      = funcao(x);

    if(x != 0){
      ea = abs((x - x_old)/x) * 100;
    }

    exibe_status(i, xl, xr, x, ea);

    if( (fl*fx) < 0){
      xr = x;
    }else{
      xl = x;
      fl = fx;
    }

    i++;
  }

  result.interacoes = i;
  result.raiz       = x;
  result.erro       = ea;

  return result;
}


s_result falsa_posicao(double xl, double xr, double (*funcao)(double)){
  struct s_result result;
  double ea  = 100;
  double fl  = funcao(xl);
  double fr  = funcao(xr);
  double x;
  double fx;
  double x_old;

  if(abs(fl) < abs(fr)){
    x = xl;
  }else{
    x = xr;
  }

  int   i   = 1;
  while(ea > ERRO && i <= I_MAX){
    x_old   = x;
    x       = xr + (fr * (xl-xr))/(fr-fl);
    fx      = funcao(x);

    if(x != 0){
      ea = abs((x - x_old)/x) * 100;
    }

    exibe_status(i, xl, xr, x, ea);

    xl = x;
    fl = fx;

    i++;
  }

  result.interacoes = i;
  result.raiz       = x;
  result.erro       = ea;

  return result;
}

s_result ponto_fixo(double x0, double (*funcao)(double)){
  struct s_result result;
  double ea = 100;
  double x  = x0;
  double x_old;

  int i = 1;
  while(ea > ERRO && i <= I_MAX){
    x_old   = x;
    x       = funcao(x_old);

    if( x != 0){
      ea = abs((x - x_old)/x)*100;
    }

    exibe_status(i, x_old, x, 0, ea);

    i++;
  }  

  result.interacoes = i;
  result.raiz       = x;
  result.erro       = ea;  

  return result;
}

s_result newton_raphson(double x0, double (*funcao)(double), double (*funcao_derivada)(double)){
  struct s_result result;
  double ea = 100;
  double x  = x0;
  double x_old, f0;

  int i = 1;
  while(ea > ERRO && i <= I_MAX){
    x_old   = x;
    f0      = funcao(x_old);
    x       = x_old - f0/funcao_derivada(x_old);

    if( x != 0){
      ea = abs((x - x_old)/x)*100;
    }

    exibe_status(i, x_old, f0, 0, ea);

    i++;
  }  

  result.interacoes = i;
  result.raiz       = x;
  result.erro       = ea;  

  return result;
}

s_result secante(double x0, double x1, double (*funcao)(double)){
  struct s_result result;
  double ea = 100;
  double x, x_old;
  double f0, f1;

  int i = 1;
  while(ea > ERRO && i <= I_MAX){
    f0    = funcao(x0);
    f1    = funcao(x1);

    x  = x1 - f1*(x0- x1)/(f0-f1);

    if( x != 0){
      ea = abs((x - x0)/x)*100;
    }

    exibe_status(i, x0, f0, 0, ea);

    x0 = x1;
    x1 = x;

    i++;
  }  

  result.interacoes = i;
  result.raiz       = x;
  result.erro       = ea;  

  return result;
}

void exibe_status(int i, double xl, double xr, double x, double ea){
  cout.precision(12);
  
  cout  << i  << "\t" 
        << setw(16) << xl << "\t" 
        << setw(16) << xr << "\t" 
        << setw(16) << x  << "\t" 
        << setw(16) << ea 
        << endl;
}
