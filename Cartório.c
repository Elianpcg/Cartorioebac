#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rios
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//in�cio da cria��o de strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o de strings
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //coletando as informa��es do usu�rio
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, "CPF: "); //escreve dentro do arquivo
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nNome: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	getchar();
	fgets(nome, 40, stdin);
	nome[strlen(nome) - 1] = '\0';
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	fgets(sobrenome, 40, stdin);
	sobrenome[strlen(sobrenome) - 1] = '\0';
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nCargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	fgets(cargo, 40, stdin);
	cargo[strlen(cargo) - 1] = '\0';
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause"); //pausa a tela
}

int consulta() //fun��o respons�vel por consultar os usu�rios
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("CPF a ser consultado: ");
	scanf("%s", cpf);
	system("cls");
	printf("\nEssas s�o as informa��es do usu�rio:\n\n");
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //condi��o se o cpf n�o existe no banco
	{
		system("cls");
		printf("\n\n");
		printf("CPF n�o localizado.\n");
	}
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	printf("\n\n");
	
	system("pause");
}

int deletar() //fun��o respons�vel por deletar os usu�rios
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	
	printf("Qual o CPF do usu�rio que deseja deletar?");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL) //condi��o se o cpf n�o existe no banco
	{
		system("cls");
		printf("\nUsu�rio n�o encontrado no sistema!\n\n");
		system("pause");
	}
	
	remove(cpf);
	
	if(file != NULL) //condi��o se o cpf existe no banco
	{
		system("cls");
		printf("\nUsu�rio deletado com sucesso!\n\n");
		system("pause");
	}
	
}

int main()
{	
	int opcao=0; //definido vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu 
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); //fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
		system("cls"); //limpando a tela
		
		switch(opcao) //in�cio da escolha
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
		} //fim da escolha
	}
}
