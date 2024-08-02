
from collections import deque

#BFS (Breadth-First Search) 

def bfs(graph, start):
    queue = deque([start]) #Criação de uma fila para gerenciar nos
    visited = set([start]) #Nó inicial foi visitado

    while queue: #Enquanto houver elementos na fila
        vertex = queue.popleft() #Remover o primeiro elemento adicionado (FIFO)
        print(vertex, end = ' ') #Printar os vertices em uma unica linha

        for vizinho in graph[vertex]: #Para cada vizinho
            if vizinho not in visited:
                queue.append(vizinho) #Adiciona os vizinmhos na fila 
                visited.add(vizinho) #Adiciona os vizinhos na lista de visitados


graph = { #Vertices e seus vizinhos

    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

bfs(graph, 'A') #Chamada da função
