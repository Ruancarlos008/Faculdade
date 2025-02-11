#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


int main()
{

	// 1º ENTRADA DE TOKENS LIMITADA A 10.

	char entrada[11];

	printf("insira os dados para análise: ");
	fflush(stdout);

	scanf("%10s", entrada);

	printf("\nVocê inseriu esses caracteres: %s\n", entrada);
	fflush(stdout);

	//2º  COMPARAÇÃO DOS TOKENS DIGITADOS COM AO CONJUNTO LEXICO.

	char comp[51] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
					'n', 'o', 'p', 'q', 'r', 's', 'u', 'v', '0', '1', '2', '3', '4', '5', '6', '7', '8',
					'9', 'x', 'y', 'z', 't', 'w', '+', '-', '*', '/', '@',
					'#', '!', '(',')', '{','}', '[',']', '\0'}; // Compilado de todos os tokens válidos do conjunto Lexico.

	char invalidos[11] = ""; // string para empilhar caracteres inválidos.
	int n = 0;
	while (entrada[n] != '\0')
	{
		int m = 0;
	    while (comp[m] != '\0')
	    	{
	        	if (entrada[n] == comp[m])
	        	{
	        		break;
	        	}
	            m++;
	        }
	        if (comp[m] == '\0') // caractere não encontrado em comp
	        {
	            char str[2] = {entrada[n], '\0'}; // transforma o caractere em uma string.
	            strcat(invalidos, str); // desenpilhar o(s) caractere(s) inválido(s) à string.
	        }
	        n++;
	}

	    if (strlen(invalidos) > 0)
	    {
	        printf("\nO(s) caractere(s) %s nao pertence(m) ao conjunto Lexico.\n", invalidos);
	        return 0;
	    }
	    else
	    {
	        printf("\nO(s) token(s) digitado(s) esta(ão) dentro do intervalo Lexico.\n");
	    }

	    // ANALIZA SE A STRING É UMA PALAVRA RESERVADA DO SISTEMA.

	    if (entrada[0] >= '0' && entrada[0] <= '9')
	    {
	    	printf("\nPalavras iniciadas com números são palavras "
	    			"reservadas do sistema.\n");
	    	return 0;
	    }

	    // 3º VERIFICA SE OS TOKENS ALFABETICOS E SE ESTÃO NA MESMA ENTRADA.

	    char alfa[23] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
	    					'n', 'o', 'p', 'q', 'r', 's', 'u', 'v', '\0'}; // tokens alfabeticos, sem as letras reservadas.
	    char cnaf[29] = {'x', 'y', 'z', 't', 'w', '+', '-', '*', '/', '@', '#', '!', '(', ')',
	    					'[', ']', '{', '}', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9','\0'}; // Compilado de todos os tokens com exceção dos alfabéticos.

	    int i, j, alfa_encontrado, cnaf_encontrado;
	    alfa_encontrado = 0; // supondo que inicialmente não há caracteres alfabéticos
	    cnaf_encontrado = 0; // supondo que inicialmente não há caracteres da variável cnaf

	    	for (i = 0; i < strlen(entrada); i++) // verifica se o caractere atual é alfabético
	    	{

	    		for (j = 0; j < 26; j++) // contador para rastrear caracteres alfabéticos.
	    	    {
	    			if (entrada[i] == alfa[j]) // Compara entrada com o os caracteres da variável alfa.
	    	        {
	    				alfa_encontrado = 1; // Caso localize algum caractere alfabético, conta 1 na variável "alfa_encontrado"
	    	            	break;
	    	        }
	    	    }

	    		for (j = 0; j < 29; j++) // verifica se o caractere atual é da "variável cnaf".
	    	    {
	    			if (entrada[i] == cnaf[j]) // contador para rastrear caracteres da "variável cnaf".
	    	        {
	    				cnaf_encontrado = 1; // Caso localize algum caractere alfabético, conta 1 na variável "num_encontrado".
	    				break;
	    	        }
	    	    }
	    	}

	    if (alfa_encontrado == 1 && cnaf_encontrado == 1) // Testa se encontrou algum token da variável "alfa"
	    {
	    	//if (cnaf_encontrado) // Caso algum token de "cnaf" seja encontrado.
	    	//{
	    		printf("\nEntrada inválida: tokens alfabéticos e tokens de expressões \n"
	    	    	   "matemáticas não podem vir juntos.\n"); // imprime essa mensagem.
	    	    	        return 0; // Encerra o programa.
	    }


	    else;




	    //5º ANALISA SE É UMA EXPRESSÃO MATEMÁTICA

	    char OpMatematicos[6] = {'x', 'y', 'z', 't', 'w', '\0'}; // tokens reservados pelo sistema.
	    char CarEspeciais[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', '*', '/', '@', '#', '!', '(', ')',
	        					   '[', ']', '{', '}'}; // operadores matemáticos

	        bool CarValidos = true; // atribui a variável "CarValidos" o valor "true" (verdadeiro), para o controle o loop for, que irá localizar a posição das variáveis das listas acima.

	        for (int i = 0; i < strlen(entrada) - 1; i++) // loop para percorrer os tokens da variável "entrada" e verificar se estão na posição correta.
	        {
	            if (strchr(OpMatematicos, entrada[i]) != NULL) // vai verificar se algum token da lista OpMatematica contem em alguma das 10 posições da variável "entrada".
	            {
	                if (strchr(CarEspeciais, entrada[i + 1]) == NULL) // caso localize algum token na vairável "entrada", irá verificar se o proximo token será um token da lista "CarEspeciais" (i+1).
	                {
	                    CarValidos = false; // caso o próximo token não seja da lista "CarEspeciais", atribuirá "false" a variável "CarValidos".
	                    break; // irá sair do loop.
	                }
	            }
	            else if (strchr(CarEspeciais, entrada[i]) != NULL) // vai verificar se algum token da lista CarEspeciais contem em alguma das 10 posições da variável "entrada".
	            {
	                if (strchr(OpMatematicos, entrada[i + 1]) == NULL) // caso localize algum token na vairável "entrada", irá verificar se o proximo token será um token da lista "OpMatematicos"(i + 1).
	                {
	                    CarValidos = false; // caso o próximo token não seja da lista "OpMatematico", atribuirá "false" a variável "CarValidos".
	                    break; // irá sair do loop.
	                }
	            }
	        }

	        if (!CarValidos) // se não encotrar tokens da lista "OpMatematicos" alternados de um elemento da lista "CarEspeciais" (ex: x+y-z(x*t)) o programa irá exibir a mensagem a baixo e irá encerrar.
	        {
	          printf("\nExpressão matemática inválida, verifique se digitou tokens atômicos reservados x y z w t "
	        		  "alternados de operadores matemáticos ( )[ ]{ } ! @ #\n ou numéricos de 0 a 9");
	            return 0;
	        }

	        // Verifica se todos os parênteses, colchetes e chaves estão fechados corretamente

	        char pilha[11];
	        int top = -1;

	        for (int i = 0; i < strlen(entrada); i++) // loop for, utilizado para percorrer cada elemento da variável "entrada"
	        {
	            if (entrada[i] == '(' || entrada[i] == '[' || entrada[i] == '{') // compara posição a posição se contem um dos três caractere especial presente na lista "CarEspecial".
	            {
	                pilha[++top] = entrada[i]; // Caso encontre um parenteses, colchetes e/ou chaves abertas, elas serão empilhadas para comparação.
	            }
	            else if (entrada[i] == ')' || entrada[i] == ']' || entrada[i] == '}') // Caso encontre um parenteses, colchetes e/ou chaves fechadas, elas serão empilhadas para comparação.
	            {
	                if (top == -1) // caso a variável "pilha" estiver vazia quer dizer que fechou algum dos 3 operadores antes de abrir.
	                {
	                    printf("\nExpressão matemática inválida: )  ]  } Não podem vir antes de (  [  {\n"); // imprime a mensagem na tela
	                    return 0; // encerra
	                }
	                char abertura = pilha[top--];
	                if ((entrada[i] == ')' && abertura != '(') || (entrada[i] == ']' && abertura != '[') || (entrada[i] == '}' && abertura != '{')) // compara se o operador que abriu é o mesmo que fechou.
	                {
	                    printf("\nExpressão matemática inválida: não foi encontrado um operador de fechamento ) ou ] ou } correspondente\n"); // imprime a mensagem
	                    return 0;
	                }
	            }
	        }

	        if (top != -1) // verifica se não deixou em aberto um dos operadores.
	        {
	            printf("\nExpressão matemática inválida: (  [  { devem ser fechados\n"); // imprime
	            return 0; // Encerra
	        }
	        else
	        {
	            printf("\nÉ uma operação matemática válida\n"); // caso a expressão estiver dentro dos paramentros, imprime esta mensagem na tela.
	            return 0;
	        }


return 0;

}



