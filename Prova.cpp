#include <iostream>

using namespace std;

struct Lista{
	int num;
	Lista *prox, *ant;
};

int main(){
	
	setlocale(LC_ALL, "portuguese");
	
	Lista *inicio = NULL, *fim=NULL, *aux = NULL;
	
	int opcao=0, i=0, menu=0, op;
	
	int idade, sexo; 
	
	string cpf;
		
	cout << "\n\t***********************************************";
	cout << "\n\t*                                             *";
	cout << "\n\t*        Seja bem-vindo ao banco AV1.         *";
	cout << "\n\t*                                             *";
	cout << "\n\t***********************************************";
	
	cout << "\n\t**********************************************";
	cout << "\n\t*   Digite os seus dados para ser atendido.  *";
	cout << "\n\t**********************************************";
	
	while(op!=4){
	cout<<"\n\t 1 - Cadastro de cliente";
	cout<<"\n\t 2 - Próximo atendimento.";
	cout<<"\n\t 3 - Lista de pessoas na fila.";
	cout<<"\n\t 4 - Sair.";
	cout<<"\n\t Escolha uma opção:"<<endl;
	cin>>op;
	
	if(op==1){
	cout << "\nCPF: ";
	cin>> cpf;
	cout << "\nIdade: ";
	cin >> idade;
	if(idade>=65){
		Lista *idoso = new Lista;
		idoso-> num = idade;
		if (inicio == NULL) {
			inicio = idoso; 
			fim = idoso; 
			cout << "\nCliente " << i++ << " - " <<  idoso;
			idoso->prox = NULL; 
			idoso->ant = NULL;
		}else {
			Lista *novo = new Lista();
			novo->prox = inicio;
			cout << "Próximo da fila: "<<inicio;
			inicio->ant=novo;
			cout << "Anterior da fila: "<<inicio;
			novo->ant=NULL;
			inicio=novo;
		}
	}
	cout << "\nQual o seu sexo?\n";
	cout << "[1] - Feminino [2] - Masculino\n";
	cin >> sexo;
	switch(sexo){
		case 1:
			cout << "\nEstá grávida? Se sim, digite 1. Se não, digite 2.\n";
			cin >> opcao;
			if(opcao==1){
				Lista *gravida = new Lista; 
				gravida-> num = sexo;
				if (inicio == NULL) {
					inicio = gravida;
					fim = gravida;
					cout<< "Cliente "<< i++ << " - " <<gravida;
					gravida->prox = NULL;
					gravida->ant = NULL;
				}else {
					Lista *novo = new Lista();
					novo->prox = inicio;
					inicio->ant=novo;
					cout<< "Cliente "<< i++ << " - " <<inicio;
					novo->ant=NULL;
					inicio=novo;
				}
			}
			if(opcao=2){
				Lista *novo = new Lista; 
				novo-> num = sexo;
				if (inicio == NULL){
					inicio = novo;
					fim = novo;
					cout<< "Cliente "<< i++ << " - " <<fim;
					novo->prox = NULL;
					novo->ant = NULL;
			}else{					
				novo->prox = inicio;
				inicio->ant=novo;
				cout<< "Cliente "<< i++ << " - " <<inicio;
				novo->ant=NULL;
				inicio=novo;
			}
			break;
	}
			
		case 2:
			if(idade>=65){
				break; 
			}else{
				Lista *novo = new Lista; 
				novo-> num = sexo;
				if (inicio == NULL){
					inicio = novo;
					fim = novo;
					cout<< "Cliente "<< i++ << " - " <<fim;
					novo->prox = NULL;
					novo->ant = NULL;
				}	
				else{					
					novo->prox = inicio;
					inicio->ant=novo;
					cout<< "Cliente "<< i++ << " - " <<inicio;
					novo->ant=NULL;
					inicio=novo;
				}
			}
			break;
			
			default:
				cout << "\nOpção inválida.";
	}
	}
		if(op==2){
			if (inicio==NULL) {
				cout<<"\nLista Vazia."<<endl;
			}
			else{
				aux = inicio; 
				cout<<"\n\tCliente "<< i << " - " << aux->num << endl;
				delete(aux);
				aux = aux->ant;
			}
		}
		if(op==3){
			
		}
}
	
	system("pause");
	return 0;
}


