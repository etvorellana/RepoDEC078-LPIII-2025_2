#include <stdio.h>

/*
    Queremos er uma serie de datas, verificar se todas elas 
    são representam datas válidas e imprimir elas em ordem 
    cronológica.
*/

int dataValida(int dia, int mes, int ano){
    if (mes < 1 || mes > 12) return 0;
    if (dia < 1 || dia > 31) return 0;
    // Verificação simplificada para meses com 30 dias
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) return 0;
    // Verificação para fevereiro
    if (mes == 2) {
        // Verificação de ano bissexto
        int bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
        if (dia > 29 || (dia == 29 && !bissexto)) return 0;
    }
    return 1;
}

void entradaDatas(int *diaLsta, int *mesLsta, int *anoLsta, int nDatas){
    for(int i = 0; i < nDatas; i++){
        printf("Digite uma data (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &diaLsta[i], &mesLsta[i], &anoLsta[i]);
        if (!dataValida(diaLsta[i], mesLsta[i], anoLsta[i])){
            printf("Data inválida. Tente novamente\n");
            i--;
        }
    }
}

void imprimeDatas(int *diaLsta, int *mesLsta, int *anoLsta, int nDatas){
    for(int i = 0; i < nDatas; i++){
        printf("Data: %02d/%02d/%04d\n", diaLsta[i], mesLsta[i], anoLsta[i]);
    }
}

int* alocaListaInt(int n){
    int *lista;
    lista = (int *) malloc(n * sizeof(int));
    if (lista == NULL){
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    return lista;
}

int main(void){
    int dia, mes, ano; 
    // Questão 1. Podemos usar tipos diferentes de int para 
    // representar estas variáveis? Justifique.
    printf("Digite uma data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &dia, &mes, &ano);
    
    // Questão 2. Como podemos verificar se a data é válida?
    if (dataValida(dia, mes, ano))
        printf("Data: %02d/%02d/%04d\n", dia, mes, ano);

    //Questão 3. Como podemos armazenar múltiplas datas?
    int *diaLista, *mesLista, *anoLista;
    int nDatas = 0;

    printf("Digite o número de datas: ");
    scanf("%d", &nDatas);
    diaLista = (int *) malloc(nDatas * sizeof(int));
    //ou
    mesLista = alocaListaInt(nDatas);
    anoLista = alocaListaInt(nDatas);
    entradaDatas(diaLista, mesLista, anoLista, nDatas);
    imprimeDatas(diaLista, mesLista, anoLista, nDatas);
    //Questão 4. Como modularizar o código utilizando funções?
    //Questão 5. Como podemos trabalhar quantidades arbitrarias 
    // de datas?
    free(diaLista);
    free(mesLista);
    free(anoLista);
    return 0;
    // Questão 6. Como podemos colocar toda a informação de uma 
    // data em uma única variável?
} // Fim da função main