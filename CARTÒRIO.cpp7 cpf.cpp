#include <stdio.h> //biblioteca de comunica�ao com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string 

int registro()//Fun�ao responsalvel por cadastrar os usuarios no sistema 
{
	//inicio cria�ao de variaveis/string
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//final cria�ao de variaveis/string
	
	printf("Digite o CPF a ser cadastrado : ");//coletando informa�ao do usuario
	scanf("%s", cpf );//%s refere-se a string
	
	strcpy(arquivo, cpf );//Responsavel por copiar os valores das string
	
	FILE *file;
	file = fopen(arquivo,"w");// cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf);// salvo o valor da variavel
	fclose(file); // fecha o arquivo
	 
	file = fopen(arquivo, "a");
	fprintf(file,","); //separar info
	fclose(file);
	
	printf("Digite o nome a ser cadastrado : ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf ("Digite o sobrenome a ser cadastrado : ");
	scanf("%s",sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, "," );
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado :  ");
	scanf("%s",cargo);
	
	file = fopen (arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}
  
  int consulta()
  {
  	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
  	
   char cpf[40];
   char conteudo [200];
   
   printf ("Digite o CPF a ser consultado : ");
   scanf("%s",cpf);
   
   FILE *file;
   file = fopen(cpf,"r");
   
   
   if(file == NULL)
   {
   	printf("Aquivo nao localizado! \n");
   	
   }
   	       
   while(fgets(conteudo, 200, file )!= NULL) 	       
   {
   	printf("\n Essas sao as informa�oes do usuario :");
   	printf("%s", conteudo);
   	printf("\n\n");
   }
   	  
	system("pause");
	fclose(file);	 
		 
		      
  }

int deletar ()
{
	char cpf[40];
	
	printf("Digite seu cpf a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	 
	if(file == NULL)
	{
	    printf(" O usuario nao encontrado no sistema!\n");
        system("pause");
	}
	
}







int main()
 {
   int opcao=0;  //Definindo vari�veis
   int x=1;
   char senhadigitada[10]="a";
   int comparacao;

    printf("### Cartorio da EBAC ###\n\n");
    printf("Login de administrador!\n\nDigite a sua senha:");
    scanf("%s",senhadigitada);
    
    comparacao = strcmp (senhadigitada, "admin");

	if(comparacao == 0)
	{
	   	
	     for(x=1;x=1;)
 	    {
	      
	      system("cls");
	
         setlocale(LC_ALL, "Portuguese");//Definindo a limguagem
     
         printf("###Cart�rio da EBAC ###\n\n");//inicio do menu
         printf("Escolher op��es desejada do menu:\n\n");
         printf("\t1 - registrer nomes\n");
         printf("\t2 - Consultar nomes\n");
         printf("\t3 - Deletar nomes \n\n");
         printf("\t4 - Sair do sistema\n\n");
         printf("Opcao:"); //fim do menu
  
          scanf("%d", &opcao); //armazenando a escolha do usuario
 
          system("cls");//responsavel por limpar a tela 
      
      
           switch(opcao) //inicio da sele�ao do menu 
         {
           case 1:// chamada de fun�oes 
          registro();
	       break;
	      
	       case 2:
	       consulta();
   	       break;
		  
		   case 3:	
		   deletar();
		   break;
		  
		   case 4:
		    printf("Obrigado por ultilizar o sistema!\n");
		   	return 0;
		   	break;
		   	
		   default:
		    printf("Essa opcao nao esta disponivel\n");
		    system("pause");
		    break;
		     
	        } // fim da sele�ao 
          } 
    }
    else
     printf("Senha incorreta!");
 }
   
  

