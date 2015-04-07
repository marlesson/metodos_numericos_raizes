Métodos Numéricos para Aproximação de Raizes
===================

Algotitmo desenvolvido na matéria de Métodos Numéricos I - PPGMC UESC

* Métodos
  * Bisseção        [0]
  * Falsa Posição   [1]
  * Ponto Fixo      [2]
  * Nweton-Raphson  [3]
  * Secante         [4]

## Uso

A função e a derivada devem ser implementadas no código antes de ser executado em `` `double funcao(double x)` `` e a
`` `double funcao_derivada(double x)` ``. Para o caso do método de ponto fixo deve ser implementado a `` `double funcao_ponto_fixo(double x)` ``.

### Execução

./main -m 0 -l 1 -r 2

### Parâmetros

* -m: Método a ser executado, utilizar de 0 a 4
* -l: Valor inicial do intervalo para os métodos intervalares ou 1º Estimativa da Raiz para os métodos interativos
* -r: Valor final do intervalo para os métodos intervalares ou 2º Estimativa da Raiz para o método da secante
* -?: Ajuda

