#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar os usuários
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//início da criação de strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de strings
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //coletando as informações do usuário
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, "CPF: "); //escreve dentro do arquivo
	fprintf(file, cpf); //salva o valor da variável
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

int consulta() //função responsável por consultar os usuários
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("CPF a ser consultado: ");
	scanf("%s", cpf);
	system("cls");
	printf("\nEssas são as informações do usuário:\n\n");
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //condição se o cpf não existe no banco
	{
		system("cls");
		printf("\n\n");
		printf("CPF não localizado.\n");
	}
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	printf("\n\n");
	
	system("pause");
}

int deletar() //função responsável por deletar os usuários
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	
	printf("Qual o CPF do usuário que deseja deletar?");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL) //condição se o cpf não existe no banco
	{
		system("cls");
		printf("\nUsuário não encontrado no sistema!\n\n");
		system("pause");
	}
	
	remove(cpf);
	
	if(file != NULL) //condição se o cpf existe no banco
	{
		system("cls");
		printf("\nUsuário deletado com sucesso!\n\n");
		system("pause");
	}
	
}

int main()
{	
	int opcao=0; //definido variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		printf("### Cartório da EBAC ###\n\n"); //início do menu 
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); //fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls"); //limpando a tela
		
		switch(opcao) //início da escolha
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
			printf("Essa opção não está disponível!\n");
			system("pause");
		} //fim da escolha
	}
}
