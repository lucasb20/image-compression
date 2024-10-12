# image-compression
Aplicativo de compressão de imagens em C.

## Visão Geral

Aplicação de compressão de imagens baseado em decomposição de blocos quadrados. Uma imagem em escala de cinza inserida na entrada do codificador é transformada em uma representação comprimida para um arquivo de bitstream, visando a redução do tamanho da imagem. Também há um algoritmo de decodificação, em que um bitstream é inserido na entrada e sua imagem é reconstruída a partir dele.

Obs: Foi utilizado desvio padrão como critério de homogeneidade em um bloco.

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

Em questão de tempo de execução, não há algo interessante a se medir. Apesar do algoritmo de compressão possuir uma complexidade de tempo exponencial de acordo com o tamanho da entrada, o critério de homogeneidade reduz o número de chamadas. Por conta disso, o tempo de execução, tanto do algoritmo de compressão quanto do decodificador, é de muito menos que um segundo.

Para avaliar a eficiência dos algoritmos, apliquei o codificador nas imagens da pasta 'outros', comparei cada uma com o tamanho do bitstream e calculei o erro médio quadrático da imagem reconstruída para a original, a fim de verificar a qualidade.

A média da redução de tamanho da imagem para o bitstream foi de 50.45%, e a média do erro médio quadrático entre uma imagem original e a imagem reconstruída foi de 6.95%.