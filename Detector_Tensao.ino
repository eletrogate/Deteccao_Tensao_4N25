/***************************************************************************************
 ***************************************************************************************
 * Sketch EG001-00
 * Faz a leitura digital de um GPIO para verificação da energização de um circuito VAC
 * usando o 4N25
 * 
 * Blog Eletrogate, 03 JUL 2021 - Autor: Marden Cicarelli
 ***************************************************************************************
 ***************************************************************************************/
#define myPIN 5             // define o pino de entrada
#define ledPIN 2            // define o pino LED
#define myRate 115200       // determina a velocidade da saída serial
#define SerialMon Serial    // define o monitor serial para saída

int onOff = 2;              // armazena o estado anterior do sinal de entrada
int leitura;                // armazena cada leitura do sinal na porta myPIN

void setup() {
  pinMode(myPIN, INPUT);    // não preocupacom com pullup ou pulldown, já que isso foi feito no circuito
  pinMode(ledPIN, OUTPUT);  // definimos o pino do led como saída

  SerialMon.begin(myRate);  // inicializa Monitor Serial com a velocidade escolhida (verificar configuração do monitor!)
  SerialMon.println("===================================================");
  SerialMon.println("Iniciando o programa... ligue e desligue o circuito");
  SerialMon.println("para testar...");
  SerialMon.println("===================================================");
  SerialMon.println();
}

void loop() {
  leitura = digitalRead(myPIN);   // faz a leitura do sinal
  if (leitura != onOff) {         // mudou o estado?
    onOff = leitura;              // armazena o novo estado
    if (leitura == HIGH) {        // valor lido é alto?
      digitalWrite(ledPIN, HIGH); // acende o led
      SerialMon.println("Circuito ligado. PERIGO DE CHOQUE ELÉTRICO!");
    } else {
      digitalWrite(ledPIN, LOW);  // apaga o led
      SerialMon.println("Circuito desligado. :)");
    }
  }
  delay(100);                     // aguarda um tempo de 0.1 s para próxima leitura.
}