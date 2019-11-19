/*para escrever o código estou usando essa fonte: 
https://blogmasterwalkershop.com.br/arduino/arduino-utilizando-o-ethernet-shield-w5100-via-web-server/
*/

//bibliotecas para uso
#include <SPI.h>
#include <Ethernet.h>


//nosso desenvolvimento

//Gabriel, coloca os dados para nós pf | os comentários em CAPS são da fonte que estou a usar

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //ATRIBUIÇÃO DE ENDEREÇO MAC AO ETHERNET SHIELD W5100
byte ip[] = { 127, 0, 0, 1 }; //COLOQUE UMA FAIXA DE IP DISPONÍVEL DO SEU ROTEADOR. EX: 192.168.1.110  **** ISSO VARIA, NO MEU CASO É: 192.168.0.175
byte gateway[] = {127, 0, 0, 1}; //GATEWAY DE CONEXÃO (ALTERE PARA O GATEWAY DO SEU ROTEADOR)
byte subnet[] = {255, 255, 255, 0}; //MASCARA DE REDE (ALTERE PARA A SUA MÁSCARA DE REDE)
EthernetServer server(80);

//Nossos nossos pinos que serão usados
const int ledPin = 9; 
String 

//_________________________________________
String readStriwng = String(30);//Recebe os dados da web

//iniciando o sistema com os dados de rede cadastrados

void setup (){

Enthernet.begin(mec, ip, gateway, subnet);
server.begin();// Da inicio ao nosso servidor e assim recebemos os dados da porta 80(porta de html)
//apos inicar aqui iremos trabalhar com o nossa porta de racao
//pinMode(XXX ,LOW);


}


void nossoServer(){
//abaixo sao codigos da fonte

if (client) { // SE EXISTE CLIENTE, FAZ
    while (client.connected()) {//ENQUANTO EXISTIR CLIENTE CONECTADO, FAZ
   if (client.available()) { //SE O CLIENTE ESTÁ HABILITADO, FAZ
    char c = client.read(); //LÊ CARACTERE A CARACTERE DA REQUISIÇÃO HTTP
    if (readString.length() < 100) //SE O ARRAY FOR MENOR QUE 100, FAZ
      {
        readString += c; // "readstring" VAI RECEBER OS CARACTERES LIDO
      }  
        if (c == '\n') { //SE ENCONTRAR "\n" É O FINAL DO CABEÇALHO DA REQUISIÇÃO HTTP
          if (readString.indexOf("?") <0){ //SE ENCONTRAR O CARACTER "?", FAZ
          }
          else //SENÃO,FAZ
        if(readString.indexOf("ledParam=1") >0) //SE ENCONTRAR O PARÂMETRO "ledParam=1", FAZ
           {
             digitalWrite(ledPin, HIGH); //LIGA O LED
             status = 1; //VARIÁVEL RECEBE VALOR 1(SIGNIFICA QUE O LED ESTÁ LIGADO)
           }else{ //SENÃO, FAZ
             digitalWrite(ledPin, LOW); //DESLIGA O LED
             status = 0; //VARIÁVEL RECEBE VALOR 0(SIGNIFICA QUE O LED ESTÁ DESLIGADO)             
           }

//Aqui seria a parte de html que serao exibidos no servidor
//tambem conhecido como HTMLzao

client.println("HTTP/1.1 200 OK");
client.println("text/type HTML");
client.println("");
client.println("<!DOCTYPE html>");

client.println("<head>");
client.println("<title> Alimentador Arduino | RC.2 IFSP 2019</title>");
client.println("</head>");

client.println("<body>");

client.println("<h1> Sistema para alimentcao</h1>");
client.println("<input type='button' id='button' onclick='botao();' value='Ativar'/>");

//script JS
client.println("
<script>
    
  //Esse Script foi montado em JavaScript, caso precise encrementar algo
  //Caso precise encrementar ou modificar algo me avisem
  //ass:kmb
  
  
  function botao(){
  if(document.getElementById('button').value == 'Ativar'){
  document.getElementById('button').value = 'Desativar';
  } 
  else
  {
  document.getElementById("button").value = 'Ativar';
  }
}
</script>");


client.println("</body>");
client.println("<html>");


}//fim_nossoServer 

}//fimAlg




