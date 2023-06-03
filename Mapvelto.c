/*----------------------------------------------------------------------------------------------------------------------
Objectivo: Fazer um Mini Sistema de Navegacao entre Cidades usando matrizes em Linguagem C.
Autor: Erivelto Clenio da Costa e Silva, 1000026877.
Para: Universidae Católica de Angola.
Disciplina: Matematica Discreta.
Ano: 2º, primeiro semestre.
Professor: Manuel Soares de Menezes.
*-----------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMO_VERTICES 20
#define MAXIMO_CARACTERES 20
#define TRUE 1
#define FALSE 0
/**************************************************************************************************
			Prototipo das Funcoes
***************************************************************************************************/
void limparTela();
void pausarTela();
int mausculaParaMinuscula(char c);
void copiarString(char str1[], char str2[]);
void copiarString(char str1[], char str2[]);
int compararStrings(char str1[], char str2[]);
int procurarCidade(char nomeCidade[], char matrizNomes[][MAXIMO_CARACTERES]);


void imprimirMenuPrincipal();
void imprimirMenuPerguntas();
void imprimirMatrizDeNomes(int numeroDeVertices, char matrizDeNomes[][MAXIMO_CARACTERES]);
void imprimirMatriz(int numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES]);

int lerNumeroDeVertices();
int lerNumeroDeArestas();
int lerCidade(char *txt, char matrizDeNomes[][MAXIMO_CARACTERES]);

int isMatrizVazio(int numeroDeVertices);
void carregarArestasDoGrafo(int numeroDeArestas, int numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES]);
void digitalizarSeuGrafo(int *numeroDeArestas, int *numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES]);
void carregarGrafoPredefinido(int *numeroDeArestas, int *numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES]);



//-----------Funcoes Auxiliares-------------

/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Limpar a tela da linha de comando
Recebe: Nada
Retorna: Nada
--------------------------------------------------------------------------------------------------------------------------------*/
void limparTela()
{
	system("clear");
	system("cls");
}
/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Pausar a tela e esperar um feed back do usuario para continuar a execução
Recebe: Nada
Retorna:Nada
--------------------------------------------------------------------------------------------------------------------------------*/
void pausarTela()
{
	char tecla;
	printf("Digite qualquer teclar seguida de <Enter> para continuar...");
	scanf(" %c", &tecla);
}
/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Converter um caracter maiusculo em minisculo.
Recebe: Um caracter maiusculo ou minusculo.
Retorna: um caracter minusculo.
--------------------------------------------------------------------------------------------------------------------------------*/
int maiusculaParaMinuscula(char c)
{
	if(c<='Z')
		if(c>='A')
			return (c+ 'a'-'A');
	return c;
}
/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Copiar uma string origem em uma string destino
Recebe: Dois vectores de strings, uma destino e outra origem.
Retorna:Nada.
--------------------------------------------------------------------------------------------------------------------------------*/
void copiarString(char destino[], char origem[])
{
	int i;
	for(i=0; origem[i]!='\0'; i++)
		destino[i]=origem[i];
	destino[i]='\0';
}
/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Comparar duas strings
Recebe: Dois vectores de Caracteres.
Retorna: Um numero negativo caso string2 maior que string1, um numero positivo caso string1 maior que string2, e 0 caso as strings sejam iguais,
--------------------------------------------------------------------------------------------------------------------------------*/
int compararStrings(char str1[], char str2[])
{
	int i=0;
	
	while(str2[i]!='\0')
	{
		if(str1[i]!=str2[i])
			return (str1[i]-str2[i]);
		i++;
	}
	return (str1[i]-str2[i]);
}
/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Procurar o nome de uma determinada cidade na matriz de nomes de cidades e devolver o indice deste nome na matriz caso encontre. 
Recebe: Um vector de caracteres(nome da cidade a procurar) e uma matriz de nomes
Retorna: O indice em que se encontra o nome procurado na matriz ou -1 caso não encontre o nome.
--------------------------------------------------------------------------------------------------------------------------------*/
int procurarCidade(char nomeCidade[], char matrizNomes[][MAXIMO_CARACTERES])
{
	int i;
	for(i=0; i<MAXIMO_CARACTERES; i++)
		if(compararStrings(nomeCidade, matrizNomes[i])==0)
			return i;
	return -1;
}

//----------------------Funcoes para Imprimir----------------------------------------


/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Mostrar o menu principal na tela.
Recebe: Nada
Retorna: Nada
--------------------------------------------------------------------------------------------------------------------------------*/
void imprimirMenuPrincipal()
{
	printf("\n|--------------------SEJA BEM VINDO AO MAPIVELTO--------------------|\n"); 
	printf("|       O MELHOR PROGRAMA DE MAPEAMENTO DE CAMINHOS PARA SI         |\n");
	printf("|			***** MENU PRINCIPAL *****		    |\n");
	printf("|1. Digitalizar Grafo 			              		    |\n");
	printf("|2. Explorar Mapa!						    |\n");
	printf("|3. Sair do Programa						    |\n");
	printf("|-------------------------------------------------------------------|\n");
	printf("Digite o numero da opcao que desejar:");
}
/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Mostrar o Menu com as opcoes de Perguntaas na Tela
Recebe: Nada
Retorna: Nada
--------------------------------------------------------------------------------------------------------------------------------*/
void imprimirMenuPerguntas()
{
	printf("|--------------------------------AREA INTERRATIVA COM MAPA-------------------------------|\n");
	printf("|	 	             ***** MENU DE OPCOES *****	       	                         |\n");
	printf("| a). MOSTRAR TODAS ESTRADAS QUE SAIEM DE [A] E VAO PARA [B]  	                         |\n");
	printf("| b). MOSTRAR SE EXISTE ANEL RODOVIARIO!			                         |\n");
	printf("| c). MOSTRAR TODAS AS ENTRADAS QUE CHEGAM ATE [X]        		                 |\n");
	printf("| d). O NUMERO DE CIDADES ISOLADAS		              	       		         |\n");
	printf("| e). QUAIS AS CIDADES SAO ADJACENTES UMA A OUTRA E DISTACIA DE ESTRADAS DIFERENTES      |\n");
	printf("| f). QUAIS AS CIDADES COM O MAIOR NUMERO DE ESTRADA(S) QUE CHEGA(M) A ESSA(AS) CIDADE(S)|\n");
	printf("| g). QUAIS AS CIDADES COM O MAIOR NUMERO DE ESTRADA(S) QUE SAI(EM) DESSA(AS) CIDADE(S)  |\n");
	printf("| h). QUAIS CIDADES TEM MAIS ESTRADAS NO GERAL(ENTRADAS + SAIDAS)               |\n");
	printf("| i). QUAIS CIDADES TEM ESTRADAS PARA SAIR E NAO TEM PARA CHEGAR	                 |\n");
	printf("| j). QUAIS AS CIDADES COM ESTRADAS PARA CHEGAR SEM ESTRADAS SAIR 	                 |\n");
	printf("| k). MOSTRAR SE EXISTE LIGACAO ENTRE DUAS CIDADES	    		                 |\n");
	printf("|----------------------------------------------------------------------------------------|\n");
	printf("Digite a letra da opcao que desejar:");
}


/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Mostrar na tela o numero e o nome correspondente a cada cidade na Matriz de Nomes de Cidades 
Recebe: Nada
Retorna: Nada
--------------------------------------------------------------------------------------------------------------------------------*/
void imprimirMatrizDeNomes(int numeroDeVertices, char matrizDeNomes[][MAXIMO_CARACTERES])
{
	int i;
	printf("|------------------------------Lista de Cidades no Grafo-----------------------------|\n");
	for(i=0; i< numeroDeVertices; i++)
		printf("%d.%s\n", i, matrizDeNomes[i]);
}
/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Mostrar na tela a Matriz de Adjacencia Digitalizada no Sistema.
Recebe: Nada
Retorna: Nada
--------------------------------------------------------------------------------------------------------------------------------*/
void imprimirMatriz(int numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES])
{
	int i, j;
	printf("\n|---------------------------------------Matriz-------------------------------------|\n");
	printf("      %.4s", matrizDeNomes[0]);
	for(i=1; i< numeroDeVertices;i++)
		printf(" %.4s", matrizDeNomes[i]);
	for(i=0; i< numeroDeVertices;i++)
	{
		printf("\n%.4s: ", matrizDeNomes[i]);
		for(j=0; j < numeroDeVertices;j++)
		{
			printf(" %4.0lf", matrizDeAdjacencia[i][j]);
		}
		printf("\n");
	}
}


//-------------------Func�es de Leitura de Valores---------------------------------/

/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Ler o numero de Vertices que o Grafo deve possuir
Recebe: Nada
Retorna: Um numero positivo representando o numero de vertices(cidades) que o grafo deve possuir.
--------------------------------------------------------------------------------------------------------------------------------*/
int lerNumeroDeVertices()
{
	int numeroDeVertices;
	do
	{
		printf("Digite o numero de Cidades(vertices) que o grafo possui:");
		scanf(" %d", &numeroDeVertices);
		
		if(numeroDeVertices<=0)
			printf("ERRO NUMERO INVALIDO: O grafo deve ter pelo menos 1 cidade(vertice)!\n");
	}while(numeroDeVertices<=0);
	return numeroDeVertices;
}
/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Ler o numero de arestas que o Grafo deve possuir
Recebe: Nada
Retorna: Um numero nao negativo representando o namero de arestas (estradas) que o grafo deve possuir.
--------------------------------------------------------------------------------------------------------------------------------*/
int lerNumeroDeArestas()
{
	int numeroDeArestas;
	do
	{
		printf("Digite o numero de estradas(arestas) que o grafo possui:");
		scanf(" %d", &numeroDeArestas);
		
		if(numeroDeArestas<0)
			printf("ERRO NUMERO INVALIDO: Nao existe numero de estradas(arestas) negativo\n");
	}while(numeroDeArestas<0);
	return numeroDeArestas;
}
/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Ler o nome de uma cidade e procurar por ele na matriz de nomes.
Recebe: Um vector de caracter(mensagem na tela) e uma matriz de nomes 
Retorna: Um valor inteiro, representando o indice da cidade na matriz de nomes.
--------------------------------------------------------------------------------------------------------------------------------*/
int lerCidade(char txt[], char matrizDeNomes[][MAXIMO_CARACTERES])
{
	char cidade[MAXIMO_CARACTERES];
	int indice;
	do{
		printf("%s", txt);
		scanf("%s", cidade);
		indice = procurarCidade(cidade, matrizDeNomes);
		if(indice ==-1)
			printf("ERRO: Cidade nao encontrada. Digite novamente.\n");
	}while(indice<0);
	return indice;
}
//------------------------------Funcoes para Carregar Grafo na Matriz---------------------------------------
/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Verificar se a matriz já possui algum vertice (cidade) digitalizada.
Recebe: Numero de vertices.
Retorna: 0-caso nao tenha vertice, 1- caso tenha vertice pelo menos um vertice.
--------------------------------------------------------------------------------------------------------------------------------*/
int isMatrizVazio(int numeroDeVertices)
{
	return (numeroDeVertices==0);
}
/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Digitalizar cada aresta que o grafo deve possuir na matriz de adjacencia.
Recebe: Numero de arestas do grafo, numero de vertices, matriz de adjacencia, matriz de nomes
Retorna: Nada
--------------------------------------------------------------------------------------------------------------------------------*/
void carregarArestasDoGrafo(int numeroDeArestas, int numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES])
{
	int i;
	int origem, destino;
	double distancia;
	
	printf("|----------------------------------Dados conhecidos----------------------------------|\n");
	printf("O mapa possui %d cidades e deve possuir %d estradas(arestas) entre elas\n", numeroDeVertices, numeroDeArestas);
	
	imprimirMatrizDeNomes(numeroDeVertices, matrizDeNomes);
	
	printf("-----Digitalizando as estradas(arestas) entre as Cidades----\n\n");
	for(i=0; i < numeroDeArestas; i++)
	{
		do{
			printf("%d* Estrada(Aresta)\nDigite o numero correspondente a cidade Origem:", i+1);
			scanf("%d", &origem);
			
			printf("Digite o numero correspondente a cidade Destino:");
			scanf("%d", &destino);
			
			printf("Digite o numero de Kilomentros entre as cidades:");
			scanf("%lf", &distancia);
			
			if((origem>=0 && origem < numeroDeVertices) && (destino>=0 && destino < numeroDeVertices) && (distancia>0))
				break;
			printf("Erro: Verifique os valores introduzidos de origem, destino e a distancia entre elas!\n");
		}while(1);
		
		matrizDeAdjacencia[origem][destino] = distancia;
		printf("\n");
	}
	
	printf("Dados carregados na matriz!\n");
	
}

/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Digitalizar o grafo que o usuario quiser.
Recebe: Numero de arestas, número de vertices, matriz de adjacencia e a matriz de nomes do grafo.
Retorna: Nada.
--------------------------------------------------------------------------------------------------------------------------------*/
void digitalizarSeuGrafo(int *numeroDeArestas, int *numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES])
{
	int i, j;
	int opcao;
	
	limparTela();
	printf("|--------------------------------Digitalizacao do Grafo------------------------------|\n");
	*numeroDeVertices = lerNumeroDeVertices();
	*numeroDeArestas = lerNumeroDeArestas();
	
	for(i=0; i < *numeroDeVertices; i++)
	{
		//Zerando todos as estradas(arestas) desta cidade(de um vertice)
		for(j=0; j < *numeroDeVertices;j++)
			matrizDeAdjacencia[i][j]=0;
		printf("Digite o nome da cidade %d:", i);
		scanf(" %s", matrizDeNomes[i]);	
	}
	carregarArestasDoGrafo(*numeroDeArestas, *numeroDeVertices, matrizDeAdjacencia, matrizDeNomes);
}
/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Carregar Grafo Predefinido na matriz de adjacencia e na matriz de nomes.
Recebe: Numero de arestas, número de vertices, matriz de adjacancia e a matriz de nomes do grafo.
Retorna: Nada.
--------------------------------------------------------------------------------------------------------------------------------*/
void carregarGrafoPredefinido(int *numeroDeArestas, int *numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES])
{
	int i, j;
	*numeroDeVertices = 18;
	*numeroDeArestas = 45;
	for(i=0; i < *numeroDeVertices; i++)
		for(j=0; j < *numeroDeVertices; j++)
			matrizDeAdjacencia[i][j]=0;
			
	
	//matrizDeAdjacencia[0][0]=120;
	
	matrizDeAdjacencia[1][5]=640;
	matrizDeAdjacencia[1][9]=418;
	matrizDeAdjacencia[1][10]=419;
	matrizDeAdjacencia[1][13]=251;
	matrizDeAdjacencia[1][17]=284;
	
	matrizDeAdjacencia[2][1]=750;
	matrizDeAdjacencia[2][5]=154;
	matrizDeAdjacencia[2][6]=715;
	matrizDeAdjacencia[2][8]=413;
	matrizDeAdjacencia[2][9]=427;
	
	matrizDeAdjacencia[3][2]=456;
	matrizDeAdjacencia[3][5]=344;
	matrizDeAdjacencia[3][7]=359;
	matrizDeAdjacencia[3][11]=721;
	matrizDeAdjacencia[3][12]=403;
	matrizDeAdjacencia[3][16]=213;
	
	matrizDeAdjacencia[4][9]=742;
	matrizDeAdjacencia[4][15]=278;
	
	matrizDeAdjacencia[5][7]=408;
	matrizDeAdjacencia[5][9]=531;
	
	matrizDeAdjacencia[6][1]=61;
	matrizDeAdjacencia[6][5]=604;
	matrizDeAdjacencia[6][13]=215;
	matrizDeAdjacencia[6][16]=329;
	
	matrizDeAdjacencia[7][12]=189;
	
	matrizDeAdjacencia[9][10]=942;
	matrizDeAdjacencia[9][17]=304;
	
	matrizDeAdjacencia[11][2]=322;
	matrizDeAdjacencia[11][5]=436;
	matrizDeAdjacencia[11][7]=508;
	matrizDeAdjacencia[11][13]=820;
	matrizDeAdjacencia[11][14]=391;
	
	matrizDeAdjacencia[13][2]=593;
	matrizDeAdjacencia[13][5]=487;
	matrizDeAdjacencia[13][9]=167;
	matrizDeAdjacencia[13][16]=383;
	matrizDeAdjacencia[13][17]=274;
	
	matrizDeAdjacencia[14][2]=707;
	matrizDeAdjacencia[14][5]=574;
	matrizDeAdjacencia[14][7]=381;
	matrizDeAdjacencia[14][12]=556;
	
	matrizDeAdjacencia[15][8]=265;
	
	matrizDeAdjacencia[16][2]=540;	
	matrizDeAdjacencia[16][9]=431;
	
	matrizDeAdjacencia[17][10]=516;
	
	for(i=0; i<*numeroDeVertices;i++)
		for(j=0; j<*numeroDeVertices;j++)
			if(matrizDeAdjacencia[i][j] !=0)
				matrizDeAdjacencia[j][i] = matrizDeAdjacencia[i][j];
	
	matrizDeAdjacencia[0][0]=120;
	matrizDeAdjacencia[3][3]=130;
	matrizDeAdjacencia[6][6]=200;
	
	copiarString(matrizDeNomes[0], "CABINDA");
	copiarString(matrizDeNomes[1], "CAXITO");
	copiarString(matrizDeNomes[2], "CUITO");
	copiarString(matrizDeNomes[3], "BENGUELA");
	copiarString(matrizDeNomes[4], "DUNDO");
	copiarString(matrizDeNomes[5], "HUAMBO");
	copiarString(matrizDeNomes[6], "LUANDA");
	copiarString(matrizDeNomes[7], "LUBANGO");
	copiarString(matrizDeNomes[8], "LUENA");
	copiarString(matrizDeNomes[9], "MALANGE");
	copiarString(matrizDeNomes[10], "MBANZA-CONGO");
	copiarString(matrizDeNomes[11], "MENONGUE");
	copiarString(matrizDeNomes[12], "MOCAMEDES");
	copiarString(matrizDeNomes[13], "N_DALATANDO");
	copiarString(matrizDeNomes[14], "ONDJIVA");
	copiarString(matrizDeNomes[15], "SAURIMO");
	copiarString(matrizDeNomes[16], "SUMBE");
	copiarString(matrizDeNomes[17], "UIGE");

}

/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Mostrar quais cidades  podemos chegar saindo de uma dada cidade no grafo. 
Recebe: Numero de vertices, matriz de adjacencia e a matriz de nomes do grafo.
Retorna: Nada.
--------------------------------------------------------------------------------------------------------------------------------*/
void alineaA(int numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES])
{
	
	int i;
	int origem, flag=FALSE;
	printf("| OK. VOCE QUER SABER QUAIS AS CIDADES QUE PODES CHEGAR SAINDO DE [A]!  |\n");
	imprimirMatrizDeNomes(numeroDeVertices, matrizDeNomes);
	origem = lerCidade("Digite o nome da cidade de ORIGEM[A]:", matrizDeNomes);
	printf("Pesquisando..\nR:");
	for(i=0; i < numeroDeVertices; i++)
		if(matrizDeAdjacencia[origem][i]!=0)
			if(origem!=i)
			{
				flag=TRUE;
				printf("[%s com %.1lfKM], ", matrizDeNomes[i], matrizDeAdjacencia[origem][i]);
			}
	if(flag==FALSE)
		printf("Nao existem cidades que partem de [%s]e vao ate elas\n", matrizDeNomes[origem]);
}

/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Mostra se uma determinada cidade do grafo possui anel Rodoviario.
Recebe: Numero de vertices, matriz de adjacancia e a matriz de nomes do grafo.
Retorna: Nada.
--------------------------------------------------------------------------------------------------------------------------------*/
void alineaB(int numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES])
{
	int cidade;
	printf("| OK. VOCE QUER SABER SE EXISTE ANEL RODOVIARIO NUMA DETERMINADA CIDADE!  |\n");
	imprimirMatrizDeNomes(numeroDeVertices, matrizDeNomes);
	cidade = lerCidade("Digite o nome da cidade que deseja verificar a informacao:", matrizDeNomes);
	if(matrizDeAdjacencia[cidade][cidade]==0)
		printf("Pesquisando...\nR:Nao Existe um anel rodoviario em ***%s***, com %lfKM!\n", matrizDeNomes[cidade], matrizDeAdjacencia[cidade][cidade]);
	else
		printf("Pesquisando...\nR:Existe um anel rodoviario em ***%s***! de %.1lfKM\n", matrizDeNomes[cidade], matrizDeAdjacencia[cidade][cidade]);
}
/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Mostrar todas as cidades que tem estradas directas para uma dada cidade destino no grafo.
Recebe: Numero de vertices, matriz de adjacancia e a matriz de nomes do grafo.
Retorna: Nada.
--------------------------------------------------------------------------------------------------------------------------------*/
void alineaC(int numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES])
{
	int i;
	int destino, flag=FALSE;
	printf("| OK. VOCE QUER CONHECER TODAS AS CIDADES QUE DAO A UMA DADA CIDADE[A] DE DESTINO |\n");
	imprimirMatrizDeNomes(numeroDeVertices, matrizDeNomes);
	destino = lerCidade("Digite o nome da cidade de DESTINO[A]:", matrizDeNomes);
	printf("Pesquisando...\nR:");
	
	for(i=0; i < numeroDeVertices; i++)
		if(matrizDeAdjacencia[i][destino]!=0)
		{
			flag=TRUE;
			printf("[%s com %.1lfKM], ", matrizDeNomes[i], matrizDeAdjacencia[i][destino]);
		}
	if(flag==FALSE)	printf("Nao existem cidades que vao para [%s]\n", matrizDeNomes[destino]);	
}

/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Mostrar quais as cidades isoladoas do grafo e seu total.
Recebe: Numero de vertices, matriz de adjacancia e a matriz de nomes do grafo.
Retorna: Nada.
--------------------------------------------------------------------------------------------------------------------------------*/
void alineaD(int numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES])
{	
	int i, j;
	int contIsoladas=0, flagIsolada;
	
	printf("| OK. VOCE QUER CONHECER O NUMERO DE CIDADES ISOLADAS |\n");	
	printf("Pesquisando...\nR:");
	for(i=0; i <numeroDeVertices; i++)
	{
		flagIsolada=TRUE;
		for(j=0; j < numeroDeVertices; j++)
			if(matrizDeAdjacencia[i][j]!=0 || matrizDeAdjacencia[j][i]!=0 ) flagIsolada=FALSE;
		if(flagIsolada==TRUE){
			contIsoladas++;
			printf("[%s], ", matrizDeNomes[i]);
		}
	}
	
	printf("[%d] cidade(s) isolada(s) ao todo\n", contIsoladas);
}
/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Mostrar quais estradas são adjacentes uma a outra mais com comprimento diferente no grafo.
Recebe: Numero de vertices, matriz de adjacencia e a matriz de nomes do grafo.
Retorna: Nada.
--------------------------------------------------------------------------------------------------------------------------------*/
void alineaE(int numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES])
{
	int i, j;
	int flgaCidadeAdjacente = FALSE;
	printf("| OK. VOCE QUER SABER QUAIS ESTRADAS SAO ADJACENTES UMAS AS OUTRAS |\n\t |E COM COMPRIMENTO de ESTRADAS DIFERENTES!\t\t|\n");
	printf("R:");
	for(i =0; i < numeroDeVertices; i++)
		for(j = 0; j < numeroDeVertices; j++)
			if(matrizDeAdjacencia[i][j]!=0) 
				if(matrizDeAdjacencia[j][i]!=0 )
					if(matrizDeAdjacencia[i][j]!=matrizDeAdjacencia[j][i]) //ESTRADAS COM MESMOS TAMANHOS
						if(i>j)
						{
							flgaCidadeAdjacente=TRUE;
							printf("\n[%s-->%s:%.1fKM]",matrizDeNomes[i], matrizDeNomes[j], matrizDeAdjacencia[i][j]);
							printf(" & [%s-->%s:%.1fKM]", matrizDeNomes[j], matrizDeNomes[i], matrizDeAdjacencia[j][i]);	
						}
	if(flgaCidadeAdjacente==FALSE)
		printf("Nao existem cidades Adjacentes entre si e com comprimento diferente no grafo!\n");
}

/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Mostrar quais cidades possuem maior numero de estradas que chegam a essas cidades.
Recebe: Numero de vertices, matriz de adjacencia e a matriz de nomes do grafo.
Retorna: Nada.
--------------------------------------------------------------------------------------------------------------------------------*/
void alineaF(int numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES])
{
	int i, j, k;
	int contEntradas, maiorEntradas=0;

	printf("| OK. VOCE QUER SABER QUAl(IS) A(S) CIDADE(S) COM MAIOR NUMERO DE ESTRADA(S) QUE CHEGA(M) ATE ESSA(S) CIDADE(S)! |\n");
	printf("R:");
	//Percorrendo a matriz na vertical para encontrar o maior valor de saidas
	for(i =0; i < numeroDeVertices; i++)
	{
		contEntradas=0;
		for(j=0; j < numeroDeVertices; j++)
			if(matrizDeAdjacencia[j][i]!=0)
				contEntradas++;
		if(contEntradas>maiorEntradas)
			maiorEntradas = contEntradas;
	}
			
	for(j =0; j < numeroDeVertices; j++)
	{
		contEntradas=0;
		for(i=0; i < numeroDeVertices; i++)
			if(matrizDeAdjacencia[i][j]!=0)
				++contEntradas;		
		if(contEntradas==maiorEntradas)
		{
			printf("\n**%s** com [%d] Estradas que chegam ate ela\n", matrizDeNomes[j], maiorEntradas);
			for(k=0; k<numeroDeVertices; k++)
				if(matrizDeAdjacencia[k][j]!=0)
					printf("De [%s] para [%s]:%.1lfKM\n",matrizDeNomes[k],matrizDeNomes[j],matrizDeAdjacencia[k][j]);
		}
	}
}


/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Mostrar quais as cidades com maior numero de estradas de saida no grafo.
Recebe: Numero de vertices, matriz de adjacencia e a matriz de nomes do grafo.
Retorna: Nada.
--------------------------------------------------------------------------------------------------------------------------------*/
void alineaG(int numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES])
{
	int i, j, k;
	int contSaidas; 	//Conta quantas saidas tem uma determinada cidade 
	int maiorSaidas=0;  	//Guarda o valor do numero de saidas da cidade com mais saidas
	
	printf("| OK. VOCE QUER SABER QUAIS AS CIDADES COM MAIOR NUMERO DE ESTRADAS QUE SAIEM DESSA CIDADE! |\n");
	printf("R:");
	//Percorrendo a matriz na vertical para encontrar o maior valor de saidas
	for(i =0; i < numeroDeVertices; i++)
	{
		contSaidas=0;
		for(j=0; j < numeroDeVertices; j++)
			if(matrizDeAdjacencia[i][j]!=0)
				contSaidas++;
		if(contSaidas>=maiorSaidas)
			maiorSaidas = contSaidas;	
	}

			
	//Percorrendo a matriz na vertical para encontrar 
	// as cidades que com valor igual a maior saidas e imprimi-las
	for(i =0; i < numeroDeVertices; i++)
	{
		contSaidas=0;
		for(j=0; j < numeroDeVertices; j++)
			if(matrizDeAdjacencia[i][j]!=0)
				contSaidas++;
		if(contSaidas==maiorSaidas)
		{
			printf("\n**%s** com [%d] Estradas que saiem dela\n", matrizDeNomes[i], maiorSaidas);
			for(k=0; k<numeroDeVertices; k++)
				if(matrizDeAdjacencia[i][k]!=0)
					printf("De [%s] para [%s]:%.1lfKM\n",matrizDeNomes[i],matrizDeNomes[k],matrizDeAdjacencia[i][k]);
		}
	}
}
/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Mostrar qual ou quais cidades do grafo possuem maior numero de estradas(numero de entradas + numero de saídas).
Recebe: Namero de vertices, matriz de adjacencia e a matriz de nomes do grafo.
Retorna: Nada.
--------------------------------------------------------------------------------------------------------------------------------*/
void alineaH(int numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES])
{
	int i, j;
	int totalEstradas=0;
	int somaCoxecao[MAXIMO_VERTICES]={0};
	int maiorConexao=0;
	
	printf("| OK. VOCE QUER SABER QUAL(IS) A(S) CIDADE(S) COM MAIOR NUMERO DE ENTRADA(S) E SAIDA(S)! |\n");
	printf("R:");
	//Calculando o numero de conexoes de cada cidade e descobrindo o maior numero de conexoes
	for(i=0; i<numeroDeVertices; i++)
	{
		totalEstradas=0;
		for(j=0; j< numeroDeVertices; j++)
		{
			if(matrizDeAdjacencia[i][j]!=0)totalEstradas++;//Soma o numero de saidas da linha
			if(matrizDeAdjacencia[j][i]!=0)totalEstradas++;//soma o numero de entradas da coluna
		}
		somaCoxecao[i]= totalEstradas;
		if(somaCoxecao[i]>maiorConexao) maiorConexao = somaCoxecao[i];
	}
	
	//Percorrendo a matriz na vertical para encontrar 
	// as cidades que com valor igual a maior saidas e imprimi-las
	for(i =0; i< numeroDeVertices; i++)
	{
		if(somaCoxecao[i]== maiorConexao)//Verifica se aquela cidade possui um numero alto de conexoes
		{
			printf("\n**%s** com [%d] Estradas\n", matrizDeNomes[i], maiorConexao);
			for(j=0; j < numeroDeVertices; j++)
			{
				if(matrizDeAdjacencia[i][j]!=0)//Verificando aresta na linha -- saida
					printf("De [%s] para [%s]:%.1lfM\n", matrizDeNomes[i], matrizDeNomes[j], matrizDeAdjacencia[i][j]);
				if(matrizDeAdjacencia[j][i]!=0)//Verificando aresta na coluna -- entrada
					printf("De [%s] para [%s]:%.1lfKM\n", matrizDeNomes[j], matrizDeNomes[i], matrizDeAdjacencia[j][i]);
			}
		}
	}	
}

/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Mostrar quais cidades do grafo tem estradas de saida sem estradas para entradas.
Recebe: Numero de vertices, matriz de adjacência e a matriz de nomes do grafo.
Retorna: Nada
--------------------------------------------------------------------------------------------------------------------------------*/
void alineaI(int numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES])
{
	int i, j;
	int quantidadeEntradasCidade[MAXIMO_VERTICES]={0};
	int quantidadeSaidasCidade[MAXIMO_VERTICES]={0};
	int somaConexoesCidade[MAXIMO_VERTICES]={0};
	int maiorConexao=0;
	int flag = FALSE;
	
	printf("| OK. VOCE QUER SABER QUAL(IS) CIDADE(S) TEM ESTRADA(S) PARA SAIR(EM) SEM ESTRADA(S) PARA ENTRAR NELA(S)! |\n");
	printf("R:");
	//Calculando o numero de conexoes de cada cidade
	for(i=0; i<numeroDeVertices; i++)
		for(j=0; j< numeroDeVertices; j++)
		{
			if(matrizDeAdjacencia[i][j]!=0)quantidadeSaidasCidade[i]++;//Soma o numero de saidas da linha
			if(matrizDeAdjacencia[j][i]!=0)quantidadeEntradasCidade[i]++;//soma o numero de entradas da coluna
		}
	
	for(i=0; i<numeroDeVertices; i++)
		if(quantidadeSaidasCidade[i]>0)
			if(quantidadeEntradasCidade[i]==0)
			{
				flag = TRUE;
				printf("\n**%s** com [%d] Estrada(s) saindo\n", matrizDeNomes[i], quantidadeSaidasCidade[i]);
				for(j=0; j < numeroDeVertices; j++)
					if(matrizDeAdjacencia[i][j]!=0)
						printf("De [%s] para [%s]:%.1lfKM\n", matrizDeNomes[i],matrizDeNomes[j], matrizDeAdjacencia[i][j]);
			}
	if(flag==FALSE)
		printf("Nao existem cidades com estradas para sair sem estradas para entrar no mapa!");	
}
/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Mostrar quais cidades do grafo tem estradas de entradas sem estradas para saidas.
Recebe: Numero de vertices, matriz de adjacencia e a matriz de nomes do grafo.
Retorna: Nada
--------------------------------------------------------------------------------------------------------------------------------*/
void alineaJ(int numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES])
{
	int i, j;
	int quantidadeEntradasCidade[MAXIMO_VERTICES]={0};
	int quantidadeSaidasCidade[MAXIMO_VERTICES]={0};
	int somaConexoesCidade[MAXIMO_VERTICES]={0};
	int maiorConexao=0;
	int flag=FALSE;
	
	printf("| OK. VOCE QUER SABER QUAL(IS) CIDADE(S) TEM ESTRADA(S) PARA CHEGAR(EM) SEM ESTRADA(S) PARA SAIR DELA(S)! |\n");
	printf("R:");
	//Calculando o numero de conexoes de cada cidade
	for(i=0; i<numeroDeVertices; i++)
		for(j=0; j< numeroDeVertices; j++)
		{
			if(matrizDeAdjacencia[i][j]!=0)quantidadeSaidasCidade[i]++;//Soma o numero de saidas da linha
			if(matrizDeAdjacencia[j][i]!=0)quantidadeEntradasCidade[i]++;//soma o numero de entradas da coluna
		}
	
	for(i=0; i<numeroDeVertices; i++)
		if(quantidadeEntradasCidade[i]>0)
			if(quantidadeSaidasCidade[i]==0)
			{
				flag=TRUE;
				printf("\n**%s** com [%d] Estrada(s) entrando\n", matrizDeNomes[i], quantidadeEntradasCidade[i]);
				for(j=0; j < numeroDeVertices; j++)
					if(matrizDeAdjacencia[j][i]!=0)
						printf("De [%s] para [%s]:%.1lfKM\n", matrizDeNomes[j],matrizDeNomes[i], matrizDeAdjacencia[j][i]);
			}
	if(flag==FALSE)
		printf("Nao existem cidades com estradas para chegar sem estradas para sair no mapa!");	
			
}
/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Determinar o menor caminho de um vertice ate todos os outros vertices do grafo.
Recebe: Numero de vertices, indice cidade origem, vector de indices dos vertices anteriores, vetor de distancias, vectore de vertices visitados, matriz de adjacencia.
Retorna: Nada
--------------------------------------------------------------------------------------------------------------------------------*/
void menorCaminho(int numeroDeVertices, int origem, int anterior[], double distancia[], int visitado[],double matrizDeAdjacencia[][MAXIMO_VERTICES])
{

	int i;
	int flag= TRUE;
	//Inicializa distancias e anteriores com -1
	for(i=0; i< numeroDeVertices; i++)
	{
		distancia[i]=1E9; //1milhao, valor infinito
		visitado[i] = 0; // nenhum vertice visitado ainda
		anterior[i]=-1;	// todos os vertices sem anteriores
	}
	
	distancia[origem]=0;
	
	//Procura vertice com menor distancia e marca como visitado
	while(flag)
	{
		 int vcm = -1;
		 for(i=0; i< numeroDeVertices;i++)
		 	if(visitado[i]==0 && ((vcm==-1) || (distancia[i] < distancia[vcm])))
		 		vcm = i;
		 if(vcm<0) 
		 	flag=FALSE;
		 else
		 {
		 	visitado[vcm] = 1;
		 	for(i=0; i< numeroDeVertices;i++)
		 	if(matrizDeAdjacencia[vcm][i]!=0 && (distancia[i]>distancia[vcm]+matrizDeAdjacencia[vcm][i]))
		 	{
		 		distancia[i]= distancia[vcm]+matrizDeAdjacencia[vcm][i];
		 		anterior[i] = vcm;
		 	}
		 }
	}
		 	
}

/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Mostrar o percurso do menor caminho entre duas cidades. 
Recebe: Indice da cidade destino, vetore de anteriores, vector de distancias, matriz de adjacencia.
Retorna: 0- Caso nao tenha nenhum  percurso a mostrar, 1- caso mostrou um percurso.
--------------------------------------------------------------------------------------------------------------------------------*/
int imprimirCaminhoCurto(int destino, int aux ,int anterior[], double distancia[], char matrizDeNomes[][MAXIMO_CARACTERES])
{

	if(aux !=-1)
	{
		imprimirCaminhoCurto(destino, anterior[aux], anterior, distancia, matrizDeNomes);
		printf("%s-->", matrizDeNomes[aux]);
		return 1;
	}
	return 0;
}
/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Mostrar o menor caminho entre duas cidade do grafo.
Recebe: Número de vértices, matriz de adjacência e a matriz de nomes do grafo.
Retorna: Nada.
--------------------------------------------------------------------------------------------------------------------------------*/
void alineaK(int numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES])
{
 	int origem, destino;
 	int anterior[MAXIMO_VERTICES];
	double distancia[MAXIMO_VERTICES];
	int visitado[MAXIMO_VERTICES];
	
	printf("| OK. VOCE QUER SABER QUAL O MENOR CAMINHO ENTRE DUAS CIDADES CASO EXISTA! |\n");
	imprimirMatrizDeNomes(numeroDeVertices, matrizDeNomes);
	origem = lerCidade("Digite o nome correspondente a cidade origem:", matrizDeNomes);
 	destino = lerCidade("Digite o nome correspondente a cidade destino:", matrizDeNomes);
 
	menorCaminho(numeroDeVertices, origem, anterior, distancia, visitado,matrizDeAdjacencia);
	printf("\n");
	
	if(anterior[destino]!=-1)
	{
		if(imprimirCaminhoCurto(destino, destino ,anterior, distancia, matrizDeNomes))
			printf(": %.1lfKM",distancia[destino]);
	}
	else 
		printf("\nNao ha nenhuma estrada que chega a essa cidade.");

}

/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Fazer a interacao com o usuario permitindo-o explorar o mapa por meio do menu de opcoes.
Recebe: Numero de vertices, matriz de adjacencia e a matriz de nomes do grafo.
Retorna: Nada.
--------------------------------------------------------------------------------------------------------------------------------*/
void explorandoMapa(int numeroDeVertices, double matrizDeAdjacencia[][MAXIMO_VERTICES], char matrizDeNomes[][MAXIMO_CARACTERES])
{
	char opcaoMenuInterativo;
	do{
		limparTela();
		printf("|------------------------------------EXPLORANDO MAPA-------------------------------------|\n");
		imprimirMatriz(numeroDeVertices, matrizDeAdjacencia, matrizDeNomes);
		imprimirMenuPerguntas();
		scanf(" %c", &opcaoMenuInterativo);
		opcaoMenuInterativo = maiusculaParaMinuscula(opcaoMenuInterativo);
		switch(opcaoMenuInterativo)
		{
			case 'a':
				alineaA(numeroDeVertices, matrizDeAdjacencia, matrizDeNomes);
				break;
			case 'b':
				alineaB(numeroDeVertices, matrizDeAdjacencia, matrizDeNomes);
				break;
			case 'c':
				alineaC(numeroDeVertices, matrizDeAdjacencia, matrizDeNomes);
				break;
			case 'd':
				alineaD(numeroDeVertices, matrizDeAdjacencia, matrizDeNomes);
				break;
			case 'e':
				alineaE(numeroDeVertices, matrizDeAdjacencia, matrizDeNomes);
				break;
			case 'f':
				alineaF(numeroDeVertices, matrizDeAdjacencia, matrizDeNomes);
				break;
			case 'g':
				alineaG(numeroDeVertices, matrizDeAdjacencia, matrizDeNomes);
				break;
			case 'h':
				alineaH(numeroDeVertices, matrizDeAdjacencia, matrizDeNomes);
				break;
			case 'i':
				alineaI(numeroDeVertices, matrizDeAdjacencia, matrizDeNomes);
				break;
			case 'j':
				alineaJ(numeroDeVertices, matrizDeAdjacencia, matrizDeNomes);
				break;
			case 'k':
				alineaK(numeroDeVertices, matrizDeAdjacencia, matrizDeNomes);
				break;
			default:
				printf("ERRO: OPCAO INVALIDA!\n");
		}				
		printf("\n\nDeseja interragir novamente com o mapa(s/n):");
		scanf(" %c", &opcaoMenuInterativo);
		opcaoMenuInterativo = maiusculaParaMinuscula(opcaoMenuInterativo);
			
	}while(opcaoMenuInterativo!='n');
}

/*------------------------------------------------------------------------------------------------------------------------------
Objectivo: Funcoes principal do programa
Recebe: Nada.
Retorna: 0.
--------------------------------------------------------------------------------------------------------------------------------*/
int main()
{
	int numeroDeVertices=0;
	int numeroDeArestas;
	char matrizDeNomes[MAXIMO_VERTICES][MAXIMO_VERTICES];
	double matrizDeAdjacencia[MAXIMO_VERTICES][MAXIMO_VERTICES];

	int opcao;
	do{
		limparTela();
		imprimirMenuPrincipal();
		scanf(" %d", &opcao);
		switch(opcao)
		{
			case 1:
				
				printf("|-------------------------Digitalizar Grafo-------------------------|\n");
				printf("Qual grafo deseja carregar?\n1-Predefinido.\n2-Carregar Voce Mesmo.\nR:");
				scanf(" %d", &opcao);
				if(opcao == 1)
					carregarGrafoPredefinido(&numeroDeArestas, &numeroDeVertices, matrizDeAdjacencia, matrizDeNomes);
										
				else
					digitalizarSeuGrafo(&numeroDeArestas, &numeroDeVertices, matrizDeAdjacencia, matrizDeNomes);	
					
				imprimirMatriz(numeroDeVertices, matrizDeAdjacencia, matrizDeNomes);
				pausarTela();
			case 2:
				if(isMatrizVazio(numeroDeVertices))
					printf("Voce deve digitalizar primeiro o mapa na matriz!\n");
				else
					explorandoMapa(numeroDeVertices, matrizDeAdjacencia, matrizDeNomes);
				break;
				
				
			case 3:
				printf("Voce escolheu a opcao Sair!\n Obrigado por usar o meu Programa, ate breve!\n");
				break;
			default:
				printf("ERRO: Voce digitou uma opcao invalida! Repita por favor\n");
		}
		
		pausarTela();
	}while(opcao!=3);
	
		
	return 0;
}
