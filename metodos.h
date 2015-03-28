/**
 * Métodos numéricos para encontrar Raiz de função
 */
#ifndef METODOS_H_INCLUDED
#define METODOS_H_INCLUDED

  //Tolerância para os métodos, limite superior de execução
  #define I_MAX 50

  // Erro Estimado (%) 
  #define ERRO  0.0001

  /**
   * Struct de resultado dos métodos numéricos
   * raiz: Valor da raiz encontrada
   * erro: Valor do erro relativo
   * interacoes: Quantidade de interações
   */
  struct s_result {
      double raiz;
      double erro;
      int    interacoes;
  };

  /**
   * Método da Bissecao
   * 
   * @param  xl     [Início do Intervalo de análise]
   * @param  xr     [Final do Intervalo de análise]
   * @param  funcao [Ponteiro para função a ser analisada]
   * @return    
   */
  s_result bissecao(double xl, double xr, double (*funcao)(double));

  /**
   * Método da Falsa Posição
   * 
   * @param  xl     [Início do Intervalo de análise]
   * @param  xr     [Final do Intervalo de análise]
   * @param  funcao [Ponteiro para função a ser analisada]
   * @return    
   */
  s_result falsa_posicao(double xl, double xr, double (*funcao)(double));  

  /**
   * Método de Ponto Fixo
   * 
   * @param  x0     [Estimativa da Raiz]
   * @param  funcao [Ponteiro para função a ser analisada]
   * @return    
   */
  s_result ponto_fixo(double x0, double (*funcao)(double));  

  /**
   * Método de Newton Raphson
   * 
   * @param  x0     [Estimativa da Raiz]
   * @param  funcao [Ponteiro para função a ser analisada]
   * @param  funcao_derivada [A função derivada da função principal]
   * @return    
   */
  s_result newton_raphson(double x0, double (*funcao)(double), double (*funcao_derivada)(double));  

  /**
   * Método de Secante
   * 
   * @param  x0     [1º Estimativa da Raiz]
   * @param  x1     [2º Estimativa da Raiz]
   * @param  funcao [Ponteiro para função a ser analisada]
   * @return    
   */
  s_result secante(double x0,double x1, double (*funcao)(double));


  double sec(double);

#endif // METODOS_H_INCLUDED
