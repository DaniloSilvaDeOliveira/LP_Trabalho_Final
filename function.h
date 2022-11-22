//definição do tipo para ponteiro (ponteiro de produto)
typedef struct Conta* ponteiro_Conta;

void inicializar(ponteiro_Conta vetorConta[], int tamanho);

void cadastrar(ponteiro_Conta vetorConta[], int posicao);

int verificaNumeroDaConta(ponteiro_Conta vetorConta[],int posicao,int numero);

void procurar(ponteiro_Conta vetorConta[],int posicao,int numero);

void alterar(ponteiro_Conta vetorConta[],int posicao,int numero);

void listarContas(ponteiro_Conta vetorConta[], int posicao);

void procurarNoVetor(ponteiro_Conta vetorConta[], int posicao,int numero);

void depositar(ponteiro_Conta vetorConta[], int posicao,int numero);

void sacar(ponteiro_Conta vetorConta[], int posicao,int numero);

void saldoGeral(ponteiro_Conta vetorConta[], int posicao);