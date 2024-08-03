from collections import deque #import queue function

def paths(grafo, inicio):
    queue = deque([inicio])
    visited = set([inicio])

    while queue:
        vertices = queue.popleft()
        print(vertices, end = ' ')

        for vizinho in grafo[vertices]:
            if vizinho not in visited:
                queue.append(vizinho)
                visited.add(vizinho)

grafo = {

        'Inicio': ['Rua das Flores', 'Bosque Encantado'],
        'Rua das Flores': ['Casa de Gabriel', 'Casa de Gustavo'],
        'Bosque Encantado': ['Casa de Gustavo'],
        'Casa de Gabriel': ['Casa de Gustavo', 'Praca do norte'],
        'Casa de Gustavo': ['Rua das Flores'],
        'Praca do Norte': []
}

paths(grafo, 'Inicio')
