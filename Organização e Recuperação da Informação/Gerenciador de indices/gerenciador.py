# Nomes: Mateus Lisboa, Gabriela Zerbone e João Paulo

import os
import numpy as np

# Função que trabalha com o txt dos arquivos
def setConjunto(conjuntoCAM):
    pular_linha = "\n"

    # Abrindo para leitura o arquivo conjunto.txt
    conjunto = open(conjuntoCAM, "rt")

    # Criando um vetor para os arquivos
    global arquivos
    arquivos = []

    # Tirando o "\n" do texto e adicionando os arquivos ao vetor
    for palavras in conjunto:
        arquivos.append(''.join(filter(lambda i: i not in pular_linha, palavras)))

    # Criando um vetor para um copia dos nomes dos arquivos
    global nome_arquivos
    nome_arquivos = arquivos.copy()

    # Variável que armazena a quantidade de arquivos
    global quantidade_arquivos
    quantidade_arquivos = 0

    # Abrindo os arquivos de texto para leitura
    for palavras in arquivos:
        arquivos[quantidade_arquivos] = open(palavras, "rt")
        quantidade_arquivos += 1
    
    # Criando um vetor para os textos
    global conteudo_arquivos
    conteudo_arquivos = []
    
    frase = ""

    # Preenchendo o vetor com os textos dos arquivos
    for x in range(quantidade_arquivos):
        for palavras in arquivos[x]:
            for char in palavras:
                if(char != "!" and char != "?" and char != "." and char != ","):
                    frase += char
                else:
                    frase += " "
            
            conteudo_arquivos.append(frase + " ")
            frase = ""

    # Fechando o arquivo
    conjunto.close()


# Função que trabalha com o txt das palavras desconsideradas
def setDesconsideradas(desconsideradasCAM):
    pular_linha = "\n"

    # Abrindo para leitura o arquivo que tem as palavras que serão desconsideradas
    desconsideradas = open(desconsideradasCAM, "rt")

    # Vetor com as palavras desconsideradas
    global palavras_desconsideradas
    palavras_desconsideradas = []
    
    # Tirando o "\n" do texto
    for palavras in desconsideradas:
        palavras_desconsideradas.append(''.join(filter(lambda i: i not in pular_linha, palavras)))

    desconsideradas.close()

# Função que trabalha com o txt das palavras que serão procuradas
def setConsulta(consultaCAM): # <-
    # Abrindo arquivo de consulta com permissão de leitura
    consulta = open(consultaCAM, "rt")

    # Vetor com as palavras da resposta
    global vetor_resposta
    vetor_resposta = []

    # Identificador da lógica de busca
    global logica_de_verificacao

    word = ""

    # Preenchimento do vetor com os textos tratados dos arquivos e verificação da lógica de busca
    for palavras in consulta:
        for char in palavras:
            # Verificação da lógica de busca
            if(char == ","):
                logica_de_verificacao = True
            elif(char == ";"):
                logica_de_verificacao = False

            # Tratamento dos textos
            if(char != " " and char != "\n" and char != "," and char != ";"):
                word += char
            else:
                vetor_resposta.append(word)
                word = ""
        
        vetor_resposta.append(word)

    consulta.close()


# Função que gera o arquivo de resposta 
def geraRespostas(): # <-
    # Criação do arquivo de resposta
    resposta = open("resposta.txt", "wt")

    # Cria vetores inicalizados com zeros e com strings vazias
    contador_resposta = np.zeros(len(vetor_resposta), dtype=int)
    arquivos_resposta = [""] * len(vetor_resposta)

    texto = ""
    aux = 0
    quantidade = 0
    texto_destino = ""

    # Método de busca pela lógica E
    if(logica_de_verificacao):
        for i in range(quantidade_arquivos):
            # Verifica se a primeira palavra da busca está no arquivo
            achou = conteudo_arquivos[i].find(vetor_resposta[0] + " ")
            
            # verifica se as demais palavras da busca estão no arquivo
            if(achou != -1):    
                aux = 0
                
                for y in range(len(vetor_resposta)):
                    achou = conteudo_arquivos[i].find(vetor_resposta[y] + " ")
                    if(achou != -1):
                        aux += 1
                
                if(aux == len(vetor_resposta)):
                    quantidade += 1
                    texto_destino += nome_arquivos[i] + "\n"

        # Escreve no arquivo de resposta
        texto = str(quantidade) + "\n" + texto_destino
        resposta.write(texto)
    else: # Método de busca pela lógica OU
        for i in range(quantidade_arquivos):
            for y in range(len(vetor_resposta)):
                achou = conteudo_arquivos[i].find(vetor_resposta[y] + " ")
                
                if(achou != -1):
                    contador_resposta[y] = contador_resposta[y] + 1
                    texto_destino = arquivos_resposta[y]
                    texto_destino += "\n" + nome_arquivos[i]
                    arquivos_resposta[y] = texto_destino

        # Escreve no arquivo resposta
        for indice in range(len(vetor_resposta)):
            texto += str(contador_resposta[indice]) + arquivos_resposta[indice] + "\n\n"
        
        resposta.write(texto)

    resposta.close()

# Função que gera o arquivo de indice
def geraIndice():
    # Criação do arquivo de indice
    Indice = open("indice.txt", "wt")

    global numero_arquivo
    numero_arquivo = 0

    global Dicionario
    global lista_indice
    Dicionario = {}
    lista_indice = []

    word = ""
    
    for tam in range(quantidade_arquivos):
        word = ""
        numero_arquivo += 1
        for palavras in conteudo_arquivos[tam]:
            for char in palavras:
                if(char != " " and char != "!" and char != "?" and char != "." and char != ","):
                    word += char
                else:
                    criarDicionario(word)
                    word = ""
        if(word != " " and tam <= quantidade_arquivos):
            criarDicionario(word)
            word = ""

    # Laço de repetição para escrever no arquivo de indice
    for chave in sorted(Dicionario):
        if(chave != ""):
            Indice.write(chave + ": " + str(Dicionario[chave]) + "\n")
    
    Indice.close()

# Função para criação do dicionário
def criarDicionario(word):
    repetida = False

    if(Ignoradas(word) == 1):
        word = ""
    else:
        for palavra_indice in Dicionario:
            if(word == palavra_indice):
                repetida = True
                if(numero_arquivo not in Dicionario[word]):
                    Dicionario[word][numero_arquivo] = 1
                else:
                    Dicionario[word][numero_arquivo] += 1
                word = ""
                break
        if(not(repetida)):
            lista_indice.append(word)
            auxDict = {}
            auxDict[numero_arquivo] = 1
            Dicionario[word] = auxDict 
            Dicionario[word][numero_arquivo] = 1
            word = ""

# Função para verificar se a palavra é igual a alguma palavra a ser desconsiderada
def Ignoradas(word):
    tam = len(palavras_desconsideradas)
    status = 0

    for i in range(tam):
        if(palavras_desconsideradas[i] == word):
            status = 1
    
    return status

# Função principal
def main(): 
    os.system('cls')

    print("Insira abaixo o nome do arquivo de consulta:")

    conjuntoCAM = "conjunto.txt"
    setConjunto(conjuntoCAM)

    consultaCAM = input("Arquivo consulta: ")
    setConsulta(consultaCAM)

    desconsideradasCAM = "desconsideradas.txt"
    setDesconsideradas(desconsideradasCAM)

    geraRespostas()
    geraIndice()

main()