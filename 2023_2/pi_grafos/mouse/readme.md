Trabalho: Desvendando o Labirinto usando API
Objetivo
O objetivo deste trabalho é desenvolver uma ferramenta capaz de decifrar a estrutura de um labirinto representado como um grafo. Uma vez entendido o labirinto, você deve sugerir a sequência de movimentos otimizada para sair do labirinto a partir de um ponto inicial.

Descrição
O labirinto é representado por um grafo onde cada vértice é um ponto que pode ser visitado pelo usuário. Para ajudá-lo a entender e navegar pelo labirinto, você terá acesso a uma API com três endpoints:

1. /iniciar:
Permite ao usuário iniciar a exploração do labirinto.

Requisição:

{
    "id": "usuario",
    "labirinto": "nome_do_labirinto"
}
Resposta:

{
    "pos_atual": 5,
    "inicio": true,
    "final": false,
    "movimentos": [4, 6]
}
2. /movimentar:
Permite ao usuário se mover pelo labirinto.

Requisição:


{
    "id": "usuario",
    "labirinto": "nome_do_labirinto",
    "nova_posicao": 6
}
Resposta:


{
    "pos_atual": 6,
    "inicio": false,
    "final": false,
    "movimentos": [5, 7]
}
3. /valida_caminho:
Valida se a sequência de movimentos fornecida é um caminho válido no labirinto.

Requisição:


{
    "id": "usuario",
    "labirinto": "nome_do_labirinto",
    "todos_movimentos": [5, 6, 7]
}
Resposta:


{
    "caminho_valido": true,
    "quantidade_movimentos": 3
}
Instruções:
Entendimento do Labirinto: Utilize a API fornecida para entender o grafo que representa o labirinto. Seu código deve ser capaz de identificar todos os vértices e arestas.

Busca do Caminho: Após entender a estrutura do labirinto, desenvolva um algoritmo que encontre o caminho mais curto (se existir) do ponto inicial até o ponto final.

Validação do Caminho: Use o endpoint /valida_caminho para confirmar se o caminho encontrado é válido.

Apresentação: Desenvolva uma interface simples (ou utilize a saída padrão do console) para mostrar a sequência de movimentos que o usuário deve realizar para sair do labirinto.

Avaliação
O trabalho será avaliado com base na acurácia do algoritmo (se ele realmente encontra o melhor caminho), na clareza do código e na apresentação dos resultados.

Dicas
Você pode usar algoritmos de busca em grafos, como o Dijkstra ou o BFS (Busca em Largura), para encontrar o caminho mais curto no labirinto.
Organize bem seu código, separando responsabilidades e documentando as funções.
Não esqueça de tratar possíveis erros que podem surgir durante as chamadas da API.

