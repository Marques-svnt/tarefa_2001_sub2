Projeto Animações com Teclado e LEDs

Descrição : Este projeto utiliza o Raspberry Pi Pico para controlar uma matriz de LEDs com animações acionadas por um teclado matricial. A cada tecla pressionada, uma animação é exibida na matriz de LEDs, oferecendo uma experiência interativa.

Tabela de Conteúdos
Descrição
Funcionalidades
Animações
Estrutura do Código
Requisitos
Como usar
Como Contribuir
Licença
Funcionalidades
Tecla	Animação
0-9	Animações específicas para cada número
ANÚNCIO	Animações personalizadas para as letras
*	Animação especial do asterisco
#	(Animação configurável para essa tecla)
Animações
As animações são rompidas nas funções ani_00(), ani_02(), ani_03(), ani_04()e ani_asterisco(). Cada uma delas gera um efeito diferente nos LEDs, criando uma experiência visual interessante. Aqui está uma descrição básica de cada animação:

Função	Descrição da Animação
ani_00()	Animação 00 (descrever o efeito visual)
ani_02()	Animação 02 (descrever o efeito visual)
ani_03()	Animação 03 (descrever o efeito visual)
ani_04()	Animação 04 (descrever o efeito visual)
ani_asterisco()	Animação especial para o asterisco (*)
Estrutura do Código
O projeto é organizado de forma modular, com cada funcionalidade separada em diferentes arquivos. Aqui está a estrutura do código:

Arquivo	Descrição
principal.c	Código principal, controla a leitura das teclas e animações
ani_00.c	Implementação da animação para a tecla 0
ani_02.c	Implementação da animação para a tecla 2
ani_03.c	Implementação da animação para a tecla 3
ani_04.c	Implementação da animação para a tecla 4
ani_asterisco.c	Implementação da animação para a tecla *
teclado.c	Leitura e controle do teclado matricial
leds.c	Controle da matriz de LEDs WS2812
campainha.c	Controle do buzzer (se instalado)
Requisitos
Hardware
Raspberry Pi Pico
Teclado matricial para capturar as teclas pressionadas
Matriz de LEDs WS2812 (ou similar) para mostrar as animações
Buzzer (opcional) para efeitos sonoros
Programas
Ambiente de Desenvolvimento : Visual Studio Code com suporte para Raspberry Pi Pico
Biblioteca : pico-sdk
Como usar
Passo 1: Preparação do Ambiente
Instale o ambiente de desenvolvimento no seu computador. Você pode usar o Visual Studio Code com a extensão do Raspberry Pi Pico.
Baixar as bibliotecas possíveis :
Pico SDK
Bibliotecas para controle de LED WS2812 e teclado matricial
Passo 2: Conectar o Hardware
Conecte o Raspberry Pi Pico ao computador via USB.
Conecte o teclado matricial e a matriz de LEDs WS2812 ao Raspberry Pi Pico.
Passo 3: Compilar e Carregar o Código
Compile o código usando o ambiente de desenvolvimento.
Carregue o código compilado para o Raspberry Pi Pico.
Execute o código . As animações começarão a ser acionadas conforme as teclas pressionadas.
Como Contribuir
Faça um fork do repositório.
Crie uma nova branch para sua feature ( git checkout -b feature/nova-animação).
Implemente uma funcionalidade ou correção.
Comprometa suas mudanças ( git commit -m 'Adiciona animação X').
Envie sua filial para o repositório remoto ( git push origin feature/nova-animação).
Abra um Pull Request para revisão e integração.
