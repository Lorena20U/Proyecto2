#include "htmlproyectoED.h"
#include "BinarySearchTree.h"
#include "Circular_Linkedlist.h"
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
void registro() {string1();} //Send web page
void inicio() {
jugadorA = server.arg("jugadorA"); 
jugadorB = server.arg("jugadorB"); 
imagenboton();
}
void partida(){
  int cnt = 0;
if (turno == true){jugador_n = jugadorA;}
else{jugador_n = jugadorB;}
preorderTraversal(treeA, "A",false,true);
preorderTraversal(treeB, "B",false,true);
turno = !turno;
imagen(jugador_n);}
void decisiones(){
  int f = 0;
  int t = 0;
 opciones = server.arg("Opcion").toInt();
 opcion1_o();
  if (opciones == 1){
    if(jugador_n == jugadorA){preorderTraversal(treeA, "A",true,false);}
    else {preorderTraversal(treeB, "B",true,false);}
    for (int go=0;go<guerrero;go++){
    if((tropas[go].tipo != "muerto") && (tropas[go].jugador == jugador_n)){strip.setPixelColor(tropas[go].posicion,0,255,0);}}
    strip.show();
    opcion1_t();}
  else if(opciones == 2){
opcion2_o();
    for(t=0;t<guerrero;t++){
      if((tropas[t].jugador == jugador_n) && (tropas[t].tipo != "muerto")){
        s += "ID: " + String(tropas[t].id) + " Tropa: " + tropas[t].tipo + " Posicion -> " + String(tropas[t].posicion) + "  Nivel: " + String(tropas[t].nivel) +  "<br>";}}
        for (int gb=0;gb<guerrero;gb++){
      if((tropas[gb].tipo != "muerto") && (tropas[gb].jugador == jugador_n)){
      strip.setPixelColor(tropas[gb].posicion,0,255,0);}}
    strip.show();
    opcion2_t();}
  else if(opciones == 3){
    opcion3_o();
      if(jugador_n == jugadorA){preorderTraversal(treeA, "A",true,false);}
      else{preorderTraversal(treeB, "B",true,false);}
 opcion3_t();}
  else if(opciones == 4){
    empezar = neopixelring(empezar);
    opcion4_o();
  if(ctn == 1){
    opcion4_t1();
    for(f=0;f<cantbombas;f++){
      if((bombas[f].jugador != jugador_n) && (bombas[f].posicion != -1)){
        s += "ID: " + String(bombas[f].id) + " Posicion -> " + String(bombas[f].posicion) + "<br>";
        strip.setPixelColor(bombas[f].posicion,255,128,0);}}
    strip.show();
opcion4_t1();}
  else if(ctn == 2){
opcion4_o2();
            for (f=0;f<guerrero;f++){
      if((tropas[f].tipo != "muerto") && (tropas[f].jugador == jugador_n)){
      strip.setPixelColor(tropas[f].posicion,0,255,0);}}
    strip.show();
    if(jugador_n == jugadorA){preorderTraversal(treeA, "A",true,false);}
    else{preorderTraversal(treeB, "B",true,false);}
   opcion4_t2();}
    else if(ctn == 3){
      opcion4_o3();
            for (f=0;f<guerrero;f++){
      if((tropas[f].tipo != "muerto") && (tropas[f].jugador == jugador_n)){
      strip.setPixelColor(tropas[f].posicion,0,255,0);}}
      strip.show();
      if(jugador_n == jugadorA){preorderTraversal(treeA, "A",true,false);}
      else{preorderTraversal(treeB, "B",true,false);}
opcion4_t3();}
    else if(ctn == 4){
            for (f=0;f<guerrero;f++){
      if((tropas[f].tipo != "muerto") && (tropas[f].jugador == jugador_n)){
      strip.setPixelColor(tropas[f].posicion,0,255,0);}}
opcion4_o4();
    for(f=0;f<guerrero;f++){
      if((tropas[f].jugador == jugador_n) && (tropas[f].tipo != "muerto")){
        s += "ID: " + String(tropas[f].id) + " Tropa: " + tropas[f].tipo + " Posicion -> " + String(tropas[f].posicion) + "  Nivel: " + String(tropas[f].nivel) +  "<br>";}}
    strip.show();
opcion4_t4();}
    else if(ctn == 5){
    opcion4_o5();
            for (f=0;f<guerrero;f++){
      if((tropas[f].tipo != "muerto") && (tropas[f].jugador == jugador_n)){
      strip.setPixelColor(tropas[f].posicion,0,255,0);}}
       for(f=0;f<guerrero;f++){
      if((tropas[f].jugador == jugador_n) && (tropas[f].tipo != "muerto")){
        s += "ID: " + String(tropas[f].id) + " Tropa: " + tropas[f].tipo + " Posicion -> " + String(tropas[f].posicion) + "  Nivel: " + String(tropas[f].nivel) +  "<br>";}}
    strip.show();
opcion4_t5();}
    else if(ctn == 6){
opcion4_o6();
            for (f=0;f<guerrero;f++){
      if((tropas[f].tipo != "muerto") && (tropas[f].jugador == jugador_n)){
      strip.setPixelColor(tropas[f].posicion,0,255,0);}}
       for(f=0;f<guerrero;f++){
      if((tropas[f].jugador == jugador_n) && (tropas[f].tipo != "muerto")){
        s += "ID: " + String(tropas[f].id) + " Tropa: " + tropas[f].tipo + " Posicion -> " + String(tropas[f].posicion) + "  Nivel: " + String(tropas[f].nivel) +  "<br>";}}
            strip.show();
opcion4_t6();}}}
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
   opcion1_of();} //Send web page  
  else if(opciones == 2){
    int unidad = server.arg("tropamoverse").toInt();
    int pos = server.arg("donde").toInt();
    imagen2();
    bool iterar = false;
    bool borrar = true;
    if (guerrero == 0 || unidad >= guerrero){incorrecto();}
    else if ((tropas[unidad].jugador != jugador_n) || (tropas[unidad].tipo == "muerto")){incorrecto();;}
    else{
      strip.setPixelColor(tropas[unidad].posicion,0,0,0);
      if((tropas[unidad].tipo == "volador") && (pos >= 0) && (pos <= 63)){
      tropas[unidad].posicion = pos;
      correcto();
      iterar = true;}
    else if (pos==1){
      if(tropas[unidad].posicion > 55){incorrecto();}
      else{
      tropas[unidad].posicion += 8;
      correcto();
      iterar = true;}}
    else if(pos==2){
      if(tropas[unidad].posicion < 8){incorrecto();}
    else{
      tropas[unidad].posicion -= 8;
      correcto();
      iterar = true;}}
    else if(pos==3){
      if(tropas[unidad].posicion == 0){incorrecto();}
      else{
        tropas[unidad].posicion -= 1;
        correcto();
        iterar = true;}}
    else if(pos==4){
      if(tropas[unidad].posicion == 63){incorrecto();}
    else{
      tropas[unidad].posicion += 1;
      correcto();
      iterar = true;}}
    else{incorrecto();}
          if(cantbombas != 0){
        for(int iu=0;iu<cantbombas;iu++){
          if ((tropas[unidad].posicion == bombas[iu].posicion) && (bombas[iu].jugador != jugador_n) && (tropas[unidad].tipo == "terrestre")){
            bomba();
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
  font();} //Send web page 
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
        opcion3_of();} //Send web page 
else if(opciones == 4){
      int cm = 0;
  if(ctn == 1){
    int bombaeliminar = server.arg("eliminarbomba").toInt();
    if (cantbombas > 0 && bombaeliminar < cantbombas){
      if((bombas[bombaeliminar].jugador != jugador_n) && (bombas[bombaeliminar].posicion != -1)){
        bombas[bombaeliminar].posicion = -1;
        bombas[bombaeliminar].estado = "inactiva";}}
    opcion4_of1();} //Send web page
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
continuar();}
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
     continuar();}
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
     continuar();}
   else if(ctn == 5){
    imagen2();
   int unielegir = server.arg("Unidad1elegida").toInt();
   int poslibreunidad = server.arg("Unidadlibrepos").toInt();
   bool campo = true;
   if(unielegir < guerrero){
   if(tropas[unielegir].posicion != -1 && tropas[unielegir].jugador == jugador_n && poslibreunidad >= 0 && poslibreunidad <= 63){
    if(cantbombas > 0){
              for(cm=0;cm<cantbombas;cm++){
          if ((tropas[unielegir].posicion == bombas[cm].posicion) && (bombas[cm].jugador != jugador_n) && (tropas[unielegir].tipo == "terrestre")){
            bomba();
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
continuar2();} //Send web page
   else if(ctn == 6){
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
    continuar();}}}
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
