def buscaMenor(arr):
    menor = arr[0]
    menor_indice = 0
    for i in range(1, len(arr)):
        if arr[i] < menor:
            menor = arr[i]
            menor_indice = i

    return menor_indice

def ordenacao_por_selecao(arr):
    novoArr = []
    for i in range (len(arr)):
        menor = buscaMenor(arr)
        novoArr.append(arr.pop(menor))

    return novoArr

arr = []
arr_len = int(input("Digite quantos numeros tem no array: "))
for i in range(0, arr_len):
    num = int(input("Digite um numero: "))
    arr.append(num)    


print(ordenacao_por_selecao(arr))
