#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "BinarySearchTree.h"
#include "Circular_Linkedlist.h"
ESP8266WebServer server(80);
const char* ssid = "TIGO-D55E";
const char* password = "2NB123207539";
struct tropa{
  int posicion;
  int nivel;
  String jugador;
  String tipo;
  int id;};
struct bomba{
  int id;
  int posicion;
  String jugador;
  String estado;};
struct bomba bombas[128];
int cantbombas = 0;
struct tropa tropas[64];
bool turno = true;
String jugadorA = "";
String jugadorB = "";
String jugador_n = "";
int guerrero = 0;
int opciones = 0;
void registro() {
 String s = "<!DOCTYPE html><html><body><h2>WARLAND</h2>";//Read HTML contents
 s += "<h3>Registro de jugadores</h3>";
 s += "<form action='/inicio'>";
 s +=  "Jugador A:<br>";
 s += "<input type='text' name='jugadorA' value='Pablo'>";
 s += "<br>";
 s += "Jugador B:<br>";
 s +="<input type='text' name='jugadorB' value='Lorena'>";
 s += "<br><br>";
 s += "<input type='submit' value='Submit'>";
 s +="</form> </body></html>";
 server.send(200, "text/html", s);} //Send web page
void inicio() {
jugadorA = server.arg("jugadorA"); 
jugadorB = server.arg("jugadorB"); 
String s = "<a href='/partida'> Comenzar </a>";
server.send(200, "text/html", s);}
void partida(){
  int cnt = 0;
  String s = "";
if (turno == true){jugador_n = jugadorA;}
else{jugador_n = jugadorB;}
preorderTraversal(treeA, "A",false,true);
preorderTraversal(treeB, "B",false,true);
s = "<h1> " + jugador_n + " </h1>";
s += "<h2> Elija una opcion </h2>";
s += "<p> 1. Crear 2 tropas <br/>";
s += "2. Moverme <br/>";
s += "3. Colocar trampa <br/>";
s += "4. Rueda de la suerte <br/></p>";
s += "<form action='/Opciones'>";
s += "<input type='text' name='Opcion' value='0'>";
s += "<input type='submit' value='Submit'></form>";
turno = !turno;
server.send(200, "text/html", s);}
void decisiones(){
  int f = 0;
  int t = 0;
 opciones = server.arg("Opcion").toInt();
  if (opciones == 1){
    pagina = "";
    pagina = "<h1> Crear unidades </h1>";
    pagina += "<h2> Elija una posicion donde colocarla </h2>";
    pagina += "<p> ";
    if(jugador_n == jugadorA){preorderTraversal(treeA, "A",true,false);}
    else {preorderTraversal(treeB, "B",true,false);}
    for (int go=0;go<guerrero;go++){
    if((tropas[go].tipo != "muerto") && (tropas[go].jugador == jugador_n)){strip.setPixelColor(tropas[go].posicion,0,255,0);}}
    strip.show();
    pagina += "</p>";
    pagina += "<form action='/cambios'>";
    pagina += "<br>";
     pagina +=  "Posicion unidad 1:<br>";
 pagina += "<input type='text' name='Unidad1' value='0'>";
 pagina += "<br>";
 pagina += "Posicion unidad 2:<br>";
 pagina +="<input type='text' name='Unidad2' value='0'>";
 pagina += "<br><br>";
 pagina += "<input type='submit' value='Submit'></form>";
 server.send(200, "text/html", pagina);}
  else if(opciones == 2){
    String s = "<h1> Moverse </h1>";
    s += "<h2> Elija una unidad para moverse </h2>";
    s += "<p>";
    for(t=0;t<guerrero;t++){
      if((tropas[t].jugador == jugador_n) && (tropas[t].tipo != "muerto")){
        s += "ID: " + String(tropas[t].id) + " Tropa: " + tropas[t].tipo + " Posicion -> " + String(tropas[t].posicion) + "  Nivel: " + String(tropas[t].nivel) +  "<br>";}}
        for (int gb=0;gb<guerrero;gb++){
      if((tropas[gb].tipo != "muerto") && (tropas[gb].jugador == jugador_n)){
      strip.setPixelColor(tropas[gb].posicion,0,255,0);}}
    strip.show();
  s += "</p>";
  s += "<form action='/cambios'>";
  s += "<br>";
  s += "Unidad a seleccionar (mediante #ID)<br>";
  s += "<input type='text' name='tropamoverse' value='0'>";
  s += "<br>";
  s += "Moverse hacia<br>";
  s += "1. Arriba<br>";
  s += "2. Abajo<br>";
  s += "3. Izquierda<br>";
  s += "4. Derecho<br>";
  s += "Si la unidad es voladora inserte una posicion<br>";
  s +="<input type='text' name='donde' value='0'>";
  s += "<br><br>";
  s += "<input type='submit' value='Submit'></form>";
  server.send(200, "text/html", s);}
  else if(opciones == 3){
    pagina = "";
    pagina = "<h1> Trampas </h1>";
    pagina += "<h2> Elija una posicion donde colocar trampa </h2>";
    pagina += "<p>";
    pagina += "Posicion: ";
      if(jugador_n == jugadorA){preorderTraversal(treeA, "A",true,false);}
      else{preorderTraversal(treeB, "B",true,false);}
      pagina += "</p>";
  pagina += "<form action='/cambios'>";
  pagina += "<br>";
  pagina += "Posicion a colocar<br>";
  pagina += "<input type='text' name='posicionbomba' value='0'>";
  pagina += "<br><br>";
  pagina += "<input type='submit' value='Submit'></form>";
  server.send(200, "text/html", pagina);}
  else if(opciones == 4){
    empezar = neopixelring(empezar);
    String s = "<h1> Opciones </h1>";
  if(ctn == 1){
    s += "<h2> Elimina una trampa y puedes ver posiciones de bombas </h2>";
    s += "<p>";
    s += "Posicion: ";
    for(f=0;f<cantbombas;f++){
      if((bombas[f].jugador != jugador_n) && (bombas[f].posicion != -1)){
        s += "ID: " + String(bombas[f].id) + " Posicion -> " + String(bombas[f].posicion) + "<br>";
        strip.setPixelColor(bombas[f].posicion,255,128,0);}}
    strip.show();
  s += "</p>";
  s += "<form action='/cambios'>";
  s += "<br>";
  s += "Posicion a eliminar bomba (Mediante ID)<br>";
  s += "<input type='text' name='eliminarbomba' value='0'>";
  s += "<br><br>";
  s += "<input type='submit' value='Submit'></form>";
  server.send(200, "text/html", s);}
  else if(ctn == 2){
    pagina = "";
    pagina = "<h2> Crear una unidad voladora </h2>";
            for (f=0;f<guerrero;f++){
      if((tropas[f].tipo != "muerto") && (tropas[f].jugador == jugador_n)){
      strip.setPixelColor(tropas[f].posicion,0,255,0);}}
    pagina += "<h3> Elige donde colocarla </h3>";
    pagina += "<p> ";
    strip.show();
    if(jugador_n == jugadorA){preorderTraversal(treeA, "A",true,false);}
    else{preorderTraversal(treeB, "B",true,false);}
   pagina += "</p>";
   pagina += "<form action='/cambios'>";
   pagina += "<br>";
  pagina +=  "Posicion unidad:<br>";
   pagina += "<input type='text' name='volador1' value='0'>";
   pagina += "<br><br>";
   pagina += "<input type='submit' value='Submit'></form>";
    server.send(200, "text/html", pagina);}
    else if(ctn == 3){
      pagina = "";
      pagina = "<h2> Debes regalar 1 posicion al rival</h2>";
            for (f=0;f<guerrero;f++){
      if((tropas[f].tipo != "muerto") && (tropas[f].jugador == jugador_n)){
      strip.setPixelColor(tropas[f].posicion,0,255,0);}}
      strip.show();
      pagina += "<h3>Elige la posicion, si insertas una invalida se regalara 1 igualmente</h3>";
    pagina += "<p> ";
      if(jugador_n == jugadorA){preorderTraversal(treeA, "A",true,false);}
      else{preorderTraversal(treeB, "B",true,false);}
   pagina += "</p>";
   pagina += "<form action='/cambios'>";
   pagina += "<br>";
   pagina +=  "Posicion regalada:<br>";
   pagina += "<input type='text' name='posicionregalada' value='0'>";
   pagina += "<br><br>";
   pagina += "<input type='submit' value='Submit'></form>";  
    server.send(200, "text/html", pagina);}
    else if(ctn == 4){
            for (f=0;f<guerrero;f++){
      if((tropas[f].tipo != "muerto") && (tropas[f].jugador == jugador_n)){
      strip.setPixelColor(tropas[f].posicion,0,255,0);}}
    String s = "<h2> Aumentar un nivel a dos unidades </h2>";
    s += "<h3> Elija dos unidades en base a su id </h3>";
    s += "<p> ";
    for(f=0;f<guerrero;f++){
      if((tropas[f].jugador == jugador_n) && (tropas[f].tipo != "muerto")){
        s += "ID: " + String(tropas[f].id) + " Tropa: " + tropas[f].tipo + " Posicion -> " + String(tropas[f].posicion) + "  Nivel: " + String(tropas[f].nivel) +  "<br>";}}
    strip.show();
    s += "</p>";
    s += "<form action='/cambios'>";
    s += "<br>";
     s +=  "Unidad 1 (ID):<br>";
 s += "<input type='text' name='Unidad1id' value='0'>";
 s += "<br>";
 s += "Unidad 2 (ID):<br>";
 s +="<input type='text' name='Unidad2id' value='0'>";
 s += "<br><br>";
 s += "<input type='submit' value='Submit'></form>";
 server.send(200, "text/html", s);}
    else if(ctn == 5){
          String s = "<h2> Mueves una unidad a una posicion cualquiera </h2>";
    s += "<h3> Elija una unidad para moverla </h3>";
    s += "<p> ";
            for (f=0;f<guerrero;f++){
      if((tropas[f].tipo != "muerto") && (tropas[f].jugador == jugador_n)){
      strip.setPixelColor(tropas[f].posicion,0,255,0);}}
       for(f=0;f<guerrero;f++){
      if((tropas[f].jugador == jugador_n) && (tropas[f].tipo != "muerto")){
        s += "ID: " + String(tropas[f].id) + " Tropa: " + tropas[f].tipo + " Posicion -> " + String(tropas[f].posicion) + "  Nivel: " + String(tropas[f].nivel) +  "<br>";}}
    strip.show();
    s += "</p>";
    s += "<form action='/cambios'>";
    s += "<br>";
     s +=  "Unidad (ID):<br>";
 s += "<input type='text' name='Unidad1elegida' value='0'>";
 s += "<br>";
  s += "Posicion (Entre 0 a 63)<br>";
 s +="<input type='text' name='Unidadlibrepos' value='0'>";
 s += "<br><br>";
 s += "<input type='submit' value='Submit'></form>";
  server.send(200, "text/html", s);}
    else if(ctn == 6){  
          String s = "<h2> Pierdes una unidad </h2>";
    s += "<h3> Elige una unidad (ID): </h3>";
    s += "<p> ";
            for (f=0;f<guerrero;f++){
      if((tropas[f].tipo != "muerto") && (tropas[f].jugador == jugador_n)){
      strip.setPixelColor(tropas[f].posicion,0,255,0);}}
       for(f=0;f<guerrero;f++){
      if((tropas[f].jugador == jugador_n) && (tropas[f].tipo != "muerto")){
        s += "ID: " + String(tropas[f].id) + " Tropa: " + tropas[f].tipo + " Posicion -> " + String(tropas[f].posicion) + "  Nivel: " + String(tropas[f].nivel) +  "<br>";}}
            strip.show();
         s += "</p>";
    s += "<form action='/cambios'>";
    s += "<br>";
     s +=  "Unidad (ID):<br>";
 s += "<input type='text' name='Unidadperdida' value='0'>";
 s += "<br>"; 
  s += "<br><br>";
 s += "<input type='submit' value='Submit'></form>";
  server.send(200, "text/html", s);}}}
void cambio() {
  if (opciones == 1){
    int u1 = server.arg("Unidad1").toInt();
    int u2 = server.arg("Unidad2").toInt();
      if(jugador_n == jugadorA){
      search(treeA,u1);
     if (y != -1){
      tropas[guerrero].posicion = u1;
      tropas[guerrero].nivel = 1;
      tropas[guerrero].jugador = jugador_n;
      tropas[guerrero].tipo = "terrestre";
      tropas[guerrero].id = guerrero;
      strip.setPixelColor(u1,0,255,0);
      guerrero++;}
     search(treeA,u2);
     if(y != -1){
      tropas[guerrero].posicion = u2;
      tropas[guerrero].nivel = 1;
      tropas[guerrero].jugador = jugador_n;
      tropas[guerrero].tipo = "terrestre";
      tropas[guerrero].id = guerrero;
      strip.setPixelColor(u2,0,255,0);
      guerrero++;}}
     else{
      search(treeB,u1);
         if (y != -1){
      tropas[guerrero].posicion = u1;
      tropas[guerrero].nivel = 1;
      tropas[guerrero].jugador = jugador_n;
      tropas[guerrero].tipo = "terrestre";
      tropas[guerrero].id = guerrero;
      strip.setPixelColor(u1,0,255,0);
      guerrero++;}
     search(treeB,u2);
      if(y != -1){
      tropas[guerrero].posicion = u2;
      tropas[guerrero].nivel = 1;
      tropas[guerrero].jugador = jugador_n;
      tropas[guerrero].tipo = "terrestre";
      tropas[guerrero].id = guerrero;
      strip.setPixelColor(tropas[guerrero].posicion,0,255,0);
      guerrero++;}}
    strip.show();
    String s = "<a href='/partida'> Continuar </a>";
 server.send(200, "text/html", s);} //Send web page  
  else if(opciones == 2){
    int unidad = server.arg("tropamoverse").toInt();
    int pos = server.arg("donde").toInt();
    String s = "";
    bool iterar = false;
    bool borrar = true;
    if (guerrero == 0 || unidad >= guerrero){s += "<a href='/partida'> Tropa invalida </a>";}
    else if ((tropas[unidad].jugador != jugador_n) || (tropas[unidad].tipo == "muerto")){s += "<a href='/partida'> Tropa invalida </a>";}
    else{
      strip.setPixelColor(tropas[unidad].posicion,0,0,0);
      if((tropas[unidad].tipo == "volador") && (pos >= 0) && (pos <= 63)){
      tropas[unidad].posicion = pos;
      s += "<a href='/partida'> Tropa movida correctamente </a>";
      iterar = true;}
    else if (pos==1){
      if(tropas[unidad].posicion > 55){s += "<a href='/partida'> Tropa invalida </a>";}
      else{
      tropas[unidad].posicion += 8;
      s += "<a href='/partida'> Tropa movida correctamente </a>";
      iterar = true;}}
    else if(pos==2){
      if(tropas[unidad].posicion < 8){s += "<a href='/partida'> Tropa invalida </a>";}
    else{
      tropas[unidad].posicion -= 8;
      s += "<a href='/partida'> Tropa movida correctamente </a>";
      iterar = true;}}
    else if(pos==3){
      if(tropas[unidad].posicion == 0){s += "<a href='/partida'> Tropa invalida </a>";}
      else{
        tropas[unidad].posicion -= 1;
        s += "<a href='/partida'> Tropa movida correctamente </a>";
        iterar = true;}}
    else if(pos==4){
      if(tropas[unidad].posicion == 63){s += "<a href='/partida'> Tropa invalida </a>";}
    else{
      tropas[unidad].posicion += 1;
      s += "<a href='/partida'> Tropa movida correctamente </a>";
      iterar = true;}}
    else{s += "<a href='/partida'> Posicion invalida </a>";}
          if(cantbombas != 0){
        for(int iu=0;iu<cantbombas;iu++){
          if ((tropas[unidad].posicion == bombas[iu].posicion) && (bombas[iu].jugador != jugador_n) && (tropas[unidad].tipo == "terrestre")){
            s += "<br><p> Tu unidad murio debido a que toco una bomba</p>";
            bombas[iu].posicion = -1;
            bombas[iu].estado = "inactiva";
            tropas[unidad].posicion = -1;
            tropas[unidad].tipo = "muerto";
            iterar = false;}}}
      for(int n=0;n<guerrero;n++){
        if((tropas[n].posicion == tropas[unidad].posicion) && (tropas[n].nivel <= tropas[unidad].nivel) && (tropas[n].jugador != jugador_n) && (iterar == true)){
          tropas[n].tipo = "muerto";
          tropas[n].posicion = -1;}
      else if((tropas[n].posicion == tropas[unidad].posicion) && (tropas[n].jugador != jugador_n)  && (iterar == true)){
        tropas[unidad].tipo = "muerto";
        tropas[unidad].posicion = -1;
        iterar = false;}}
      if(iterar == true){
        strip.setPixelColor(tropas[unidad].posicion,0,255,0);
        strip.show();
      if(jugador_n == jugadorA){
        search(treeA, tropas[unidad].posicion);
        if(y == -1){
            treeA = insertElement(treeA, tropas[unidad].posicion);
            treeB = deleteElement(treeB, tropas[unidad].posicion);}}
      else{
        search(treeB, tropas[unidad].posicion);
        if(y == -1){
          treeB = insertElement(treeB, tropas[unidad].posicion);
          treeA = deleteElement(treeA, tropas[unidad].posicion);}}}}
  strip.show();
  server.send(200, "text/html", s);} //Send web page 
else if(opciones == 3){
  int bombasp = server.arg("posicionbomba").toInt();
  if(jugador_n == jugadorA){
    search(treeA, bombasp);
     if (y != -1){
        bombas[cantbombas].id = cantbombas;
        bombas[cantbombas].posicion = bombasp;
        bombas[cantbombas].jugador = jugador_n;
        bombas[cantbombas].estado = "activa";
        cantbombas++;}}
else{
  search(treeB, bombasp);
  if (y != -1){
        bombas[cantbombas].id = cantbombas;
        bombas[cantbombas].posicion = bombasp;
        bombas[cantbombas].jugador = jugador_n;
        bombas[cantbombas].estado = "activa";
        cantbombas++;}}
String s = "<a href='/partida'> Continuar </a>";
server.send(200, "text/html", s);} //Send web page 
else if(opciones == 4){
      int cm = 0;
  if(ctn == 1){
    String s = "";
    int bombaeliminar = server.arg("eliminarbomba").toInt();
    if (cantbombas > 0 && bombaeliminar < cantbombas){
      if((bombas[bombaeliminar].jugador != jugador_n) && (bombas[bombaeliminar].posicion != -1)){
        bombas[bombaeliminar].posicion = -1;
        bombas[bombaeliminar].estado = "inactiva";
        s += "<p> Bomba eliminada</p><br> ";}}
    s += "<a href='/partida'> Continuar </a>";
    server.send(200, "text/html", s);} //Send web page
    else if(ctn == 2){
    int colocarvolador = server.arg("volador1").toInt();
    bool colocar = true;
    if(guerrero > 0){
    for(cm=0;cm<guerrero;cm++){
      if((tropas[cm].posicion == colocarvolador) && (tropas[cm].jugador != jugador_n) && (tropas[cm].nivel >= 2) && (tropas[cm].tipo != "muerto")){
        colocar = false;}}}
    if ((colocarvolador >= 0) && (colocarvolador <= 63) && (colocar == true)){
      search(treeA, colocarvolador);
        if(y != -1){
          if(jugadorA != jugador_n){
           treeA = deleteElement(treeA, colocarvolador);
            treeB = insertElement(treeB, colocarvolador);
      strip.setPixelColor(tropas[colocarvolador].posicion,0,255,0);
      tropas[guerrero].posicion = colocarvolador;
      tropas[guerrero].nivel = 2;
      tropas[guerrero].jugador = jugador_n;
      tropas[guerrero].tipo = "volador";
      tropas[guerrero].id = guerrero;
      guerrero++;}}
      search(treeB, colocarvolador);
        if(y != -1){
          if(jugadorB != jugador_n){
           treeB = deleteElement(treeB, colocarvolador);
            treeA = insertElement(treeA, colocarvolador);}
      strip.setPixelColor(tropas[colocarvolador].posicion,0,255,0);
      tropas[guerrero].posicion = colocarvolador;
      tropas[guerrero].nivel = 2;
      tropas[guerrero].jugador = jugador_n;
      tropas[guerrero].tipo = "volador";
      tropas[guerrero].id = guerrero;
      guerrero++;}}
    strip.show();
    String s = "<a href='/partida'> Continuar </a>";
    server.send(200, "text/html", s);}
  else if(ctn == 3){
    int regalito = server.arg("posicionregalada").toInt();
    bool regalaruno = true;
      if(jugadorA == jugador_n){
        search(treeA, regalito);
        if(y != -1){
          strip.setPixelColor(y,0,0,255);
          treeA = deleteElement(treeA, y);
            treeB = insertElement(treeB, y);
          regalaruno = false;}
        if(regalaruno == true){
          ptr = findSmallestElement(treeA);
          strip.setPixelColor((ptr->data),0,0,255);
            treeA = deleteElement(treeA, (ptr->data));
            treeB = insertElement(treeB, (ptr->data));}}
    else{
      search(treeB, regalito);
      if(y != -1){
      treeB = deleteElement(treeB, y);
      treeA = insertElement(treeA, y);
          strip.setPixelColor(y,255,0,0);
          regalaruno = false;}
          if((regalaruno == true)){
           ptr = findSmallestElement(treeB);
           strip.setPixelColor((ptr->data),255,0,0);
          treeB = deleteElement(treeB, (ptr->data));
          treeA = insertElement(treeA, (ptr->data));}}
    strip.show();
    String s = "<a href='/partida'> Continuar </a>";
    server.send(200, "text/html", s);}
   else if(ctn == 4){
    int asignarnivelprimero = server.arg("Unidad1id").toInt();
    int asignarnivelsegundo = server.arg("Unidad2id").toInt();
    if(asignarnivelprimero < guerrero){
    if(tropas[asignarnivelprimero].posicion != -1 && tropas[asignarnivelprimero].jugador == jugador_n){
      tropas[asignarnivelprimero].nivel += 1;
       strip.setPixelColor(tropas[asignarnivelprimero].posicion,0,255,0);}}
    if(asignarnivelsegundo < guerrero){
     if(tropas[asignarnivelsegundo].posicion != -1 && tropas[asignarnivelsegundo].jugador == jugador_n){
      tropas[asignarnivelsegundo].nivel += 1;
      strip.setPixelColor(tropas[asignarnivelsegundo].posicion,0,255,0);}}
    strip.show();
    String s = "<a href='/partida'> Continuar </a>";
    server.send(200, "text/html", s);}
   else if(ctn == 5){
    String s = "";
   int unielegir = server.arg("Unidad1elegida").toInt();
   int poslibreunidad = server.arg("Unidadlibrepos").toInt();
   bool campo = true;
   if(unielegir < guerrero){
   if(tropas[unielegir].posicion != -1 && tropas[unielegir].jugador == jugador_n && poslibreunidad >= 0 && poslibreunidad <= 63){
    if(cantbombas > 0){
              for(cm=0;cm<cantbombas;cm++){
          if ((tropas[unielegir].posicion == bombas[cm].posicion) && (bombas[cm].jugador != jugador_n) && (tropas[unielegir].tipo == "terrestre")){
            s += "<br><p> Tu unidad murio debido a que toco una bomba</p>";
            bombas[cm].posicion = -1;
            bombas[cm].estado = "inactiva";
            tropas[unielegir].posicion = -1;
            tropas[unielegir].tipo = "muerto";
            break;}}}
          search(treeA, poslibreunidad);
        if(y != -1){
          if(jugadorA != jugador_n){
          treeA = deleteElement(treeA, poslibreunidad);
          strip.setPixelColor(poslibreunidad,0,0,255);
          treeB = insertElement(treeB, poslibreunidad);}}
        search(treeB, poslibreunidad);
      if(y != -1){
      if(jugadorB != jugador_n){
          treeB = deleteElement(treeB, poslibreunidad);
          strip.setPixelColor(poslibreunidad,255,0,0);
          treeA = insertElement(treeA, poslibreunidad);}}
   strip.show();}}
    s += "<a href='/partida'> Continuar </a>";
    server.send(200, "text/html", s);} //Send web page
   else if(ctn == 6){
    String s = "";
    int regalaruni = server.arg("Unidadperdida").toInt();
    if((regalaruni > guerrero) && (guerrero != 0)){
      for(cm=0;cm<guerrero;cm++){
        if((tropas[cm].jugador == jugador_n) && (tropas[cm].posicion != -1)){
          tropas[cm].posicion = -1;
          tropas[cm].tipo = "muerto";
          break;}}}
   else if((guerrero == 0) || (regalaruni > guerrero)){s += "<p> No hay unidades </p>";}
   else{
    tropas[regalaruni].posicion = -1;
    tropas[regalaruni].tipo = "muerto";}
   strip.show();
    s += "<a href='/partida'> Continuar </a>";
    server.send(200, "text/html", s);}}}
void setup() {
strip.begin();
strip.show();
pixels.begin();
pixels.show();
pixels.setBrightness(11);
strip.setBrightness(11);
create_tree(treeA);
create_tree(treeB);
empezar = create_cll(empezar);
for(int i=0; i<32; i++){
  treeA = insertElement(treeA, i);
  treeB = insertElement(treeB, (i+32));
 strip.setPixelColor(i,255,0,0);
 strip.setPixelColor((i+32),0,0,255);}
strip.show();
Serial.begin(9600);
WiFi.mode(WIFI_AP_STA);
WiFi.begin(ssid, password);
Serial.println("");
while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");}
    Serial.println("");
  Serial.print("Connected to ");
  Serial.println("WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
server.on("/", registro);
server.on("/inicio", inicio);
server.on("/partida", partida);
server.on("/Opciones", decisiones);
server.on("/cambios", cambio);
server.begin();
Serial.println("HTTP server started");}
void loop() {server.handleClient();}
