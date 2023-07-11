n = 1763
e = 17
ch = [1, 610, 413, 107, 759, 1584]


# Encontrar fatores primos de um número
def fatorar(n):
    i = 2
    fator = []

    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            fator.append(i)

    if n > 1:
        fator.append(n)

    if len(fator) == 2:
        p = fator[0]
        q = fator[1]

    return p, q

p, q = fatorar(n)


# Encontra o valor do totiente
def totiente(p, q):
    return (p - 1) * (q - 1)

phi = totiente(p, q)


# Calcula o inverso multiplicativo para encontrar o d
def encontra_d(phi, e):
    return pow(e, -1, phi)

d = encontra_d(phi, e)


# Decriptografa a chave cifrada com criptografia RSA
def decriptografar_chave(d, n, ch):
    ch_decriptografada = []
    
    for chave in ch:
        ch_decriptografada.append(pow(chave, d, n))

    return ch_decriptografada

ch_decriptografada = decriptografar_chave(d, n, ch)
arquivo = open("arquivo.txt", 'r')
arquivo_decriptografado = open("arquivo_decriptogradado.txt", "wt")


# Decriptografa o arquivo cifrado com a Cifra Polialfabética
def decriptografa_texto(arquivo, arquivo_descriptografado, ch):
    conteudo = arquivo.readline()
    conteudo_criptografado = ""
    indice = 0

    for caracter in conteudo:
        conteudo_criptografado += chr(ord(caracter) - ch[indice])
        indice = (indice + 1) % len(ch)

    arquivo_decriptografado.write(conteudo_criptografado)


decriptografa_texto(arquivo, arquivo_decriptografado, ch_decriptografada)