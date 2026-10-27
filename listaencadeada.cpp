#include <iostream>
using namespace std;

// Representa cada cliente
struct No {
	int telefone; 	// numero de telefone do cliente
	No* prox;		// ponteiro para o proximo nó
};

// Fila
struct Fila{
	No* inicio = nullptr;		// ponteiro para o primeiro elemento da fila
	No* fim = nullptr; 		// ponteiro para o ultimo elemento da fila
	
};

// verifica se a fila está vazia
bool filaVazia (Fila &fila){
	return fila.inicio == nullptr;
}

// insere um novo cliente
void enfileirar (Fila &fila, int telefone){
	No* novoNo = new No; // cria um novo nó
	novoNo->telefone = telefone;
	novoNo->prox = nullptr;
	
	if (filaVazia(fila)){
		fila.inicio = novoNo;	// se a fila estiver vazia, será o primeiro
	} else {
		fila.fim->prox = novoNo; // adiciona o novo no ao final da fila
	}
	
	fila.fim = novoNo; // Atualiza o ponteiro para o ultimo nó
}

// remove o primeiro atendimento da fila
void desenfileirar(Fila &fila){
	
	if (filaVazia(fila)){ // se a fila estiver vazia
		cout << "FILA VAZIA!" << endl;
		return;
	}
	
	No* temp = fila.inicio; // guarda referencia ao nó que será removido
	fila.inicio = fila.inicio->prox; // atualiza o inicio da fila
	
	if (fila.inicio == nullptr){ // se a fila ficar vazia, atualiza o fim
		fila.fim = nullptr;
	}
	
	delete temp; // libera memoria do no removido
}

// mostra o proximo atendimento (o primeiro da fila)
void proximoAtendimento(Fila &fila){
	
	if (filaVazia(fila)){
		cout << "FILA VAZIA!" << endl;
		return;
	} else {
		cout << "Proximo atendimento: " << fila.inicio->telefone << endl;
	}
}

// exibe fila 
void exibirFila (Fila &fila){
	
	if (filaVazia(fila)){
		cout << "FILA VAZIA!" << endl;
		return;
	} 
	
	cout << "Atendimentos na fila: " << endl;
	No* atual = fila.inicio;
	
	while (atual!= nullptr){
		cout << atual->telefone << " -> ";
		atual = atual->prox;
	}
	
	cout << "null" << endl; // indica fim da fila
}


int main() {
	
	Fila fila;
	int opcao, telefone;
	
	do {
		cout << "------------------------------" << endl;
		cout << "Menu: " << endl;
		cout << "1. Enfileirar novo cliente" << endl;
		cout << "2. Desenfileirar cliente atendido" << endl;
		cout << "3. Exibir proximo atendimento" << endl;
		cout << "4. Exibir lista de clientes" << endl;
		cout << "5. Verificar se há clientes na fila" << endl;
		cout << "0. Sair" << endl;
		cout << "Escolha uma opcao: ";
		cin >> opcao;
		
		switch (opcao){
			
			case 0:
				cout << "Saindo..." << endl;
			break;
			
			case 1: 
				cout << "Digite o número do telefone: ";
				cin >> telefone;
				
				enfileirar(fila,telefone);
			break;
			
			case 2:
				desenfileirar(fila);
			break;
				
			case 3: 
				proximoAtendimento(fila);
			break;
			
			case 4: 
				exibirFila(fila);
			break;
			
			case 5:
				if (filaVazia(fila)) {
                    cout << "Nao ha clientes na fila." << endl;
                } else {
                    cout << "Ha clientes aguardando atendimento." << endl;
                }
			break;
			
			default: 
			cout << "INVALIDO" << endl;
		}
		
	} while(opcao != 0);

	return 0;

}