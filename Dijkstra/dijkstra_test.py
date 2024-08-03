import heapq #Implementar fila de prioridade

def dijkstra(grafo, origem):
    #Inicializando
    distancias = {vertice: float('inf') for vertice in grafo} #Distancias de todos os vertices por enquanto é infinita
    distancias[origem] = 0
    fila_prioridade =  [(0, origem)]
    caminho_anterior = {vertice: None for vertice in grafo}

    while fila_prioridade:
        #Vertice com menor distancia
        distancia_atual, vertice_atual = heapq.heappop(fila_prioridade)

        #Verifica todos os vizinhos do vertice atual
        for vizinho, peso in grafo[vertice_atual].items():
            distancia = distancia_atual + peso

            if distancia < distancias[vizinho]:
                distancias[vizinho] = distancia
                caminho_anterior[vizinho] = vertice_atual
                heapq.heappush(fila_prioridade, (distancia, vizinho))

    return distancias, caminho_anterior


#Exemplo de grafos

grafo = {

        'A': {'B': 1, 'C': 4},
        'B': {'A': 1, 'C': 2, 'D': 5},
        'C': {'A': 4, 'B': 2, 'D': 1},
        'D': {'B': 5, 'C': 1}
}

distancias, caminho_anterior = dijkstra(grafo, 'A')

print("Distancias: ", distancias)
print("Caminho Anterior: ", caminho_anterior)

#Funcao para reconstruir caminho mais curto

def short_path(caminho_anterior, origem, destino):
    caminho = []
    passo = destino
    while passo is not None:
        caminho.append(passo)
        passo = caminho_anterior[passo]

    caminho.reverse()
    return caminho

caminho = short_path(caminho_anterior, 'A', 'D')
print("O caminho mais curto de A a D é: ", caminho)
