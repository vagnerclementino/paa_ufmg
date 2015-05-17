# Universidade Federal de Minas Gerais
## Departamento de Ciência da Computação
### Projeto e Análise de Algoritmos
####Trabalho Prático 01 - Paradigmas

#####1 - O Problema
Esta branch foi criado para armazenar os arquivos do Trabalho Prático 01 da disciplina Projeto e Análise de Algoritmos. Neste trabalho foi proposto o problema de encontrar o maior número de cérebros tais que P[c[1]] < P[c[2]] < . . . < P[c[n]] e QI[c[1]] > QI[c[2]] > . . . > QI[c[n]], onde P[c[i]] e QI[c[i]] são, respectivamente, o peso e o Quociente de Inteligência do i-ésimo cérebro dado.

#####2 - Solução Proposta

O problema foi resolvido utilizando-se os paradigmas (1) Força Bruta, (2) Guloso e (3) Programação Dinâmica. Para cada paradigma foi implementado um algoritmo que retorna a solução ótima. Para detalhes verifique a pasta no arquivo vagner_clementino_doc_tp_paradigmas.pdf da pasta docs.

#####3 - Estrutura do Projeto

O projeto está estruturado da seguinte forma:
* src/lib/ 			   	        -> Pasta com algumas bibliotecas próprias utilizadas no trabalho
* src/tp_paradigmas 		    -> Pasta com todo os código e documentação relacionado ao trabalho prático
* src/tp_paradigmas/bin 	  -> Pasta onde o script de compilação irá salvar o executável
* src/tp_paradigmas/inputs  -> Pasta com os arquivos de entrada		
* src/tp_paradigmas/outputs -> Pasta com a saída do programa
* src/tp_paradigmas/src	    -> Pasta com os arquivos fontes de trabalho
* docs/                  	  -> Pasta com a documentação do trabalho prático

#####3 - Executável

Após compilado será gerado um executável de nome tp_paradigmas na pasta src/tp_paradigmas/bin.A sintaxe de execução do programa é:

**********************************************************************************
																			     
tp_paradigmas -i [ARQUIVO DE ENTRADA] -o [ARQUIVO DE SAIDA] -p [PARADIGMA]	
																				 
**********************************************************************************

Os paradigmas possíves são:
* "fb" 	  -> Força Bruta
* "greedy"  -> Guloso
* "pd"	  -> Programação Dinâmica
* 

#####4 - Contatos
Para maiores informações envio e-mail para [Vagner Clementino](mailto:vagnercs@dcc.ufmg.br)



