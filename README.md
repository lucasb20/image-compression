# image-compression
Aplicativo de compressão de imagens em C.

## Visão Geral

Aplicação de compressão de imagens baseado em decomposição de blocos quadrados. Uma imagem em escala de cinza inserida na entrada do codificador é transformada em uma representação comprimida para um arquivo de bitstream, visando a redução do tamanho da imagem. Também há um algoritmo de decodificação, em que um bitstream é inserido na entrada e sua imagem é reconstruída a partir dele.

## Estrutura do Projeto

O projeto está organizado da seguinte forma:

- **Makefile:** Contém as instruções para compilar e construir o projeto.
- **lib:** Pasta contendo os cabeçalhos necessários para compilar o projeto.
- **main.c:** Utilizado para testar o projeto e executar as funcionalidades implementadas.
- **funcs.c:** Contém as principais funções responsáveis pela lógica do projeto.
- **pgm.c:** Contém funções para lidar com imagens em escala de cinza.

## Algoritmos Principais

1. **encoder:** Inicia um fluxo de dividir uma imagem em quadrantes, verificar a homogeneidade e transformar a imagem e cria o bitstream.
2. **decoder:** Reconstrói uma imagem a partir de um bitstream.

## Como Utilizar

Para utilizar o projeto, siga estas etapas:

1. Compile o projeto utilizando o Makefile.
2. Execute o arquivo gerado para testar as funcionalidades implementadas.
3. Siga as instruções apresentadas no console para interagir com o projeto.

## Eficiência dos Algoritmos

...