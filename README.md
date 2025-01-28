
# Projeto: Animações em matriz de LED usando teclado matricial no Wokwi

## Descrição

Este projeto utiliza um teclado matricial 4x4 conectado a um Raspberry Pi Pico para controlar uma matriz 5x5 de LEDs e exibir uma animação colorida em RGB

---

## Funcionalidades

Animações das teclas 1 até 7
Funções de acender e apagar Leds com intensidades programadas
Buzzer como recurso sonoro em duas animações
Modo bootsel através do teclado

---

## Requisitos

- Raspberry Pi Pico
- Teclado matricial 4x4 (WokWi)
- Matriz 5x5 de LEDs
- Buzzer

---

## Configuração

### Mapeamento de teclas

| Tecla | Função                              |
|-------|-------------------------------------|
| **1** | animação 01 - Gabriel Marques  - Bomba explodindo com buzzer               |
| **2** | animação 02 Ariel dos Santos de Cristo Góes (animação em ondas e intensidade)                 |
| **3** | animação 03 - Marcelo Rick Almeida Santos|
| **4** | animação 04- Paulo César de Jesus Di Lauro Robô atirando  |
| **5** | animação 05 - Bruna Alves Cabral  - Frames das letras do nome BRUNA |
| **6** | animação 06 - Lucas Borges Ribeiro - Animação do nome Lucas e um emoji   |
| **7** | animação 07 - Iago Virgílio - Vórtice Luminoso  |
| **A** | Desligar todos os LEDs  |
| **B** | Ligar todos os LEDs na cor azul com intensidade de 100 %  |
| **C** | Ligar todos os LEDs na cor vermelha com intensidade de 80 %  |
| **D** | Ligar todos os LEDs na cor verde com intensidade de 50 %  |
| **#** |Ligar todos os LEDs na cor branca com intensidade de 20 %  |
| **\*** | Habilita o modo de gravação USB.  |

---

## Compilação e Execução

1. Certifique-se de que o SDK do Raspberry Pi Pico está configurado no seu ambiente.
2. Compile o programa utilizando a extensão **Raspberry Pi Pico Project** no VS Code:
   - Abra o projeto no VS Code.
   - Vá até a extensão do **Raspberry pi pico project** e clique em **Compile Project**.
3. Coloque a placa em modo boot cell e copie o arquivo `main.uf2`, que está na pasta build, para o microcontrolador conectado via USB.

---

## Emulação com Wokwi

Para testar o programa sem hardware físico, você pode utilizar o **Wokwi** para emulação no VS Code:

1. Instale a extensão **Wokwi for VS Code**.
2. Inicie a emulação:
   - Clique no arquivo `diagram.json` e inicie a emulação.
4. Teste o funcionamento do programa diretamente no ambiente emulado.

---

## Demonstração no YouTube

Confira a demonstração completa deste projeto no YouTube: [Demonstração do Projeto]( a preencher )

---

## Colaboradores

- [brunaalvescabral - Bruna Alves Cabral ](https://github.com/brunaalvescabral)
- [iagovirgilio - Iago Virgílio Lopes Macedo de Oliveira](https://github.com/iagovirgilio)
- [ribeiro51 - Lucas Borges Ribeiro](https://github.com/ribeiro51)
- [PauloCesar53 - Paulo César de Jesus Di Lauro ](https://github.com/PauloCesar53)
- [marques-svnt - Gabriel Marques de Andrade ](https://github.com/Marques-svnt)
- [ArieldosSantosdeCristo - Ariel dos Santos de Cristo Góes ](https://github.com/ArieldosSantosdeCristo)
- [Ma756-max - Marcelo Rick Almeida Santos](https://github.com/Ma756-max)

---

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).


