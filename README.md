# image-compression
Aplicativo de compressão de imagens em C.

## Visão Geral

Esta aplicação realiza compressão de imagens baseada em decomposição de blocos quadrados. Imagens em escala de cinza são transformadas em uma representação comprimida para um arquivo de bitstream, visando a redução do tamanho da imagem. Uma imagem pode ser reconstruída a partir de um arquivo de bitstream.

## Estrutura do Projeto

O projeto está organizado da seguinte forma:

- **Makefile:** Contém as instruções para compilar e construir o projeto.
- **lib:** Pasta contendo os cabeçalhos necessários para compilar o projeto.
- **main.c:** Utilizado para testar o projeto e executar as funcionalidades implementadas.
- **funcs.c:** Contém as principais funções responsáveis pela lógica do projeto.
- **pgm.c:** Contém funções para lidar com imagens em escala de cinza.

## Algoritmos Principais

1. **encoder:** Inicia um fluxo de dividir uma imagem em quadrantes, verificar a homogeneidade e transformar a imagem e cria o bitstream. Obs: Foi utilizado desvio padrão como critério de homogeneidade em um bloco.
2. **decoder:** Reconstrói uma imagem a partir de um bitstream.

## Como Utilizar

Para utilizar o projeto, siga estas etapas:

1. Compile o projeto utilizando o Makefile.
2. Execute o arquivo gerado para testar as funcionalidades implementadas.
3. Siga as instruções apresentadas no console para interagir com o projeto.

## Eficiência dos Algoritmos

O tempo de execução, tanto do algoritmo de compressão quanto do decodificador, é de muito menos que um segundo porque são algoritmos simples, então não há nada relevante a se avaliar por tempo. Foram avaliados apenas a redução de tamanho da imagem para o bitstream e a perda de qualidade entre a imagem original e a reconstruída.

Para obter os estes resultados, apliquei o codificador nas imagens da pasta 'outros', comparei cada uma com o tamanho do bitstream e calculei o erro médio quadrático da imagem reconstruída para a original, a fim de verificar a qualidade.

A média da redução de tamanho da imagem para o bitstream foi de 50.45%, e a média do erro médio quadrático entre uma imagem original e a imagem reconstruída foi de 6.95%.