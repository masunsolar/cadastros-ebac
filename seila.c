#include <stdio.h> //Biblioteca de cominica��o com o user
#include <stdlib.h> //Biblioteca de aloca��o de espa�o de mem�ria 
#include <locale.h> //Aloca��o de texto por regi�o 
#include <string.h> //Cuida das string

int cadast(){ //Fun��o cadastro
	
	char arquivo[80]; //Vari�veis 
	char cpf[40];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	
	printf ("Digite seu cpf: "); //Infos do cadastro
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf); //copia os valores da string
	
	FILE *file; //cria arquivo
	file = fopen(arquivo,"w"); //pasta
	fprintf(file,cpf); //salva o valor
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,", "); //separar info
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //Infos do cadastro
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,", "); 
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: "); //Infos do cadastro
	scanf("%s",sobrenome);

	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,", "); 
	fclose(file);

	printf("Digite o cargo a ser cadastrado: "); //Infos do cadastro
	scanf("%s",cargo);

	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,", "); 
	fclose(file);
	
	printf ("Obrigado por se cadastrar!\n\n");
	
	system ("pause");
}

int consult(){
	
		setlocale(LC_ALL, "pt_BR_utf8"); //Definindo linguagem
			
	char cpf[40];
	char conteudo[250];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		
		printf("Arquivo n�o localizado\n");
		
	}	
	
	while(fgets(conteudo, 250, file) != NULL){
		
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int del(){
	
    char cpf[40];
    
    printf("Qual usu�rio deseja deletar?\nDigite o cpf: ");
    scanf("%s", cpf);
    
	int retorno = remove(cpf);
    
	if (retorno == 0) {
		
        printf("Deletado com sucesso!\n\n");
        system("pause");
    
	} 
	
	else {
		
        printf("N�o encontrado...\n\n");
        system("pause");
    
	}
	
    return 0;

}

int main(){
	
	int option=0; //Definindo a variavel 
	int laco=1;
	char password[10]="a";
	int comparacao;
	
	printf(".... Registro de nomes EBAC ....");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",password);
	
	comparacao = strcmp(password, "admin");
	
	if (comparacao == 0){
	
		for(laco=1;laco=1;){
		
			system("cls");
		
			setlocale(LC_ALL, "English_united States.1252"); //Definindo linguagem
		
			printf (".... Registro de nomes EBAC ....\n\n"); //Inicio do menu
			printf ("Escolha a op��o do menu:\n\n");
			printf ("\t1 - Cadastrar um usu�rio:\n");
			printf ("\t2 - Consultar um usu�rio:\n");
			printf ("\t3 - Excluir um usu�rio:\n");
			printf ("\t4 - Sair do sistema:\n\n");
			printf ("Op��o: "); //Fim do menu
			
			scanf("%d", &option); //Armazenar escolha
	
			system("cls");
		
			switch(option){ //Inicio da sele��o
		
				case 1:
					cadast();
					break;
						
				case 2:
					consult();
					break;
					
				case 3:
					del();
					break;
			
				case 4:
					printf("Obrigdo por utilizar o aplicativo!\n\n");
					return 0;
					break;
		
				default:
					printf("Op��o Invalida\n");
					system("pause");
					break;
				
				
			} //fim da sele��o
		}
	}
	else 
		printf("Senha incorreta...\n\n");
}

