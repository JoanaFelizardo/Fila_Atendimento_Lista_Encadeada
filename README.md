# Fila de Atendimento Telefônico (Estrutura de Dados)

Implementação de uma **Fila Dinâmica (FIFO - First-In, First-Out)** em C++ utilizando ponteiros e alocação dinâmica de memória (`struct` e `new`/`delete`).

A aplicação simula um sistema de atendimento ao cliente por telefone com menu interativo.

## ⚙️ Funcionalidades

- **Enfileirar (`enfileirar`):** Adiciona um novo cliente (número de telefone) ao final da fila.
- **Desenfileirar (`desenfileirar`):** Remove e libera a memória do primeiro cliente da fila após o atendimento.
- **Consultar Próximo (`proximoAtendimento`):** Exibe o telefone do próximo cliente a ser atendido sem removê-lo.
- **Exibir Fila (`exibirFila`):** Percorre e exibe todos os números aguardando na fila.
- **Verificar Status (`filaVazia`):** Checa se há clientes na fila de espera.
