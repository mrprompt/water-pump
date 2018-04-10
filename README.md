# Planta IoT

Projeto de Planta IoT

* análise de nível de umidade do solo
* regagem automática
* Status via ThingSpeak

## Configuração

Antes de compilar o projeto, crie o arquivo *_config.h* no mesmo diretório e defina as constantes necessárias.

Exemplo:

```console
#define SSID_REDE "minha-rede-wifi"      // nome da rede wifi
#define SENHA_REDE "minha-senha-de-rede-wifi"  // senha da rede wifi

String ChaveEscritaThingSpeak   = ""; //chave de escrita do canal
String talkBackAPIKey           = ""; // chave de leitura do talkback
String talkBackID               = ""; // id do talkback
``` 

Para adquirir os dados do **ThingSpeak**, primeiramente você precisa criar um canal e configurar os campos corretamente;
o projeto utiliza somente um campo por enquanto (Field1) que irá receber o nível de umidade do solo. 

Quanto maior o valor, mais árido está o solo, por isso, quando este valor chegar a 70%, a bomba dágua será ativada 
por 3 segundos, em um loop até que este valor baixe.

