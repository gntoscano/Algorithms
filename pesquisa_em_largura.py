
from collections import deque

grafo = {}
grafo["me"] = ["brother", "sister", "mom"]

#nome = str(input("Say your name: "))
#grafo[nome] = str(input("Say one friend name: "))

#grafo[people] = ["scooby"]

def people_are_friend(nome):
    grafo["me"] = ["brother", "sister", "mom"]

def search(nome):
    fila_de_pesquisa = deque() #Creation of a queue
    fila_de_pesquisa += grafo[nome] #Adding people friends
    verified = [] #Test of people already checked

    while fila_de_pesquisa:
        people = fila_de_pesquisa.popleft()
        if not people in verified:
            if people_are_friend(nome):
                print (people + "is a friend")
                return True
            else:
                fila_de_pesquisa += grafo[people]
                verified.append(people)
    return False

people_are_friend("me")
search("me")

