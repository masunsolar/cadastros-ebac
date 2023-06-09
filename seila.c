#include <stdio.h> //Biblioteca de cominicação com o user
#include <stdlib.h> //Biblioteca de alocação de espaço de memória 
#include <locale.h> //Alocação de texto por região 
#include <string.h> //Cuida das string

int cadast(){ //Função cadastro
	
	char arquivo[80]; //Variáveis 
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
		
		printf("Arquivo não localizado\n");
		
	}	
	
	while(fgets(conteudo, 250, file) != NULL){
		
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int del(){
	
    char cpf[40];
    
    printf("Qual usuário deseja deletar?\nDigite o cpf: ");
    scanf("%s", cpf);
    
	int retorno = remove(cpf);
    
	if (retorno == 0) {
		
        printf("Deletado com sucesso!\n\n");
        system("pause");
    
	} 
	
	else {
		
        printf("Não encontrado...\n\n");
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
			printf ("Escolha a opção do menu:\n\n");
			printf ("\t1 - Cadastrar um usuário:\n");
			printf ("\t2 - Consultar um usuário:\n");
			printf ("\t3 - Excluir um usuário:\n");
			printf ("\t4 - Sair do sistema:\n\n");
			printf ("Opção: "); //Fim do menu
			
			scanf("%d", &option); //Armazenar escolha
	
			system("cls");
		
			switch(option){ //Inicio da seleção
		
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
					printf("Opção Invalida\n");
					system("pause");
					break;
				
				
			} //fim da seleção
		}
	}
	else 
		printf("Senha incorreta...\n\n");
}

