#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
ESP8266WebServer server(80);
String s = "";
String pagina = "";
void string1(){
  s = "";
  s = "<DOCTYPE! html><html><head><style>body {background-image: url('https://wallup.net/wp-content/uploads/2019/10/197087-city-moscow-russia-war-night-apocalyptic-battle-dark.jpg');}</style>";//Read HTML contents
 s += "<font color='White' face='Arial' size=7>";
 s += "<h1> Bienvenido a Warland! </h1></font>";
 s +=  "<font color='White' face='Arial' size=6>";
 s += "<p> El objetivo del juego es conquistar el territorio enemigo y tienes varias acciones diferentes para atacar/defender la estrategia la creas tu!<br>";
 s += "-> Puedes crear 2 tropas<br>-> Puedes mover tropas (Debes tener creadas primero)<br>-> Puedes poner trampas para matar enemigos<br>-> Puedes usar una rueda de la suerte donde te puede tocar una accion al azar ya sea buena o mala<br>";
 s += "-> Recuerda si vas a matar una unidad y es uno o varios niveles superior a tu unidad, la tuya muere!<br>";
 s +="-> No olvides lo importante es divertirse, gana quien conquiste primero el territorio rival completo!";
 s += "</p></font></font><title>Título de la página </title></head><body><font color='White' face='Arial' size=5><p>Nombre jugador 1</p>";
 s += "<form action= '/inicio'><input type='text' name='jugadorA' value='Pablo'><p>Nombre jugador 2<br></p><input type='text' name='jugadorB' value'Lorena'><br><br><button>";
 s +="<img src='https://cdn.onlinewebfonts.com/svg/img_18659.png' alt='imagen' width='32' height='32' style='vertical-align: middle'>Jugar</button></form></body></font></html>";
 server.send(200, "text/html", s);
}
void imagenboton(){
  s = "";
   s += "<style>body {background-image: url('https://wallup.net/wp-content/uploads/2019/10/197087-city-moscow-russia-war-night-apocalyptic-battle-dark.jpg');}</style><font color='White' face='Arial' size=7><a href='/partida'> Comenzar </a></font>";
  server.send(200, "text/html", s);
}

void imagen(String jugador_n){
  s = "";
  s = "<style>body {background-image: url('https://wallup.net/wp-content/uploads/2019/10/197087-city-moscow-russia-war-night-apocalyptic-battle-dark.jpg');}</style><font color='White' face='Arial' size=5>";
s += "<h1> " + jugador_n + " </h1>";
s += "<h2> Elija una opcion </h2>";
s += "<p> 1. Crear 2 tropas <br/>";
s += "2. Moverme <br/>";
s += "3. Colocar trampa <br/>";
s += "4. Rueda de la suerte <br/></p>";
s += "<form action='/Opciones'>";
s += "<input type='text' name='Opcion' value='0'>";
s += "<button><img src='https://cdn.onlinewebfonts.com/svg/img_18659.png' alt='imagen' width='32' height='32' style='vertical-align: middle'>Comenzar</button></form></font>";
server.send(200, "text/html", s);
}
void opcion1_o(){
      pagina = "";
    pagina += "<style>body {background-image: url('https://wallup.net/wp-content/uploads/2019/10/197087-city-moscow-russia-war-night-apocalyptic-battle-dark.jpg');}</style><font color='White' face='Arial' size=5>";
    pagina += "<h1> Crear unidades </h1>";
    pagina += "<h2> Elija una posicion donde colocarla </h2>";
    pagina += "<p> ";
}
void opcion1_t(){
   pagina += "</p>";
    pagina += "<form action='/cambios'>";
    pagina += "<br>";
     pagina +=  "Posicion unidad 1:<br>";
 pagina += "<input type='text' name='Unidad1' value='0'>";
 pagina += "<br>";
 pagina += "Posicion unidad 2:<br>";
 pagina +="<input type='text' name='Unidad2' value='0'>";
 pagina += "<br>";
 pagina += "<button><img src='https://cdn.onlinewebfonts.com/svg/img_18659.png' alt='imagen' width='32' height='32' style='vertical-align: middle'>Continuar</button></font></form>";
 server.send(200, "text/html", pagina);
}
void opcion2_o(){
  s = "";
     s += "<style>body {background-image: url('https://wallup.net/wp-content/uploads/2019/10/197087-city-moscow-russia-war-night-apocalyptic-battle-dark.jpg');}</style><font color='White' face='Arial' size=5>";
    s += "<h1> Moverse </h1>";
    s += "<h2> Elija una unidad para moverse </h2>";
    s += "<p>";
}
void opcion2_t(){
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
  s += "<br>";
  s += "<button><img src='https://cdn.onlinewebfonts.com/svg/img_18659.png' alt='imagen' width='32' height='32' style='vertical-align: middle'>Continuar</button></font></form>";
  server.send(200, "text/html", s);
}
void opcion3_o(){
     pagina = "";
    pagina += "<style>body {background-image: url('https://wallup.net/wp-content/uploads/2019/10/197087-city-moscow-russia-war-night-apocalyptic-battle-dark.jpg');}</style><font color='White' face='Arial' size=5>";
    pagina += "<h1> Trampas </h1>";
    pagina += "<h2> Elija una posicion donde colocar trampa </h2>";
    pagina += "<p>";
    pagina += "Posicion: ";
}
void opcion3_t(){
       pagina += "</p>";
  pagina += "<form action='/cambios'>";
  pagina += "<br>";
  pagina += "Posicion a colocar<br>";
  pagina += "<input type='text' name='posicionbomba' value='0'>";
  pagina += "<br>";
  pagina += "<button><img src='https://cdn.onlinewebfonts.com/svg/img_18659.png' alt='imagen' width='32' height='32' style='vertical-align: middle'>Continuar</button></font></form>";
  server.send(200, "text/html", pagina);
}
void opcion4_o(){
  s = "";
      s = "<style>body {background-image: url('https://wallup.net/wp-content/uploads/2019/10/197087-city-moscow-russia-war-night-apocalyptic-battle-dark.jpg');}</style><font color='White' face='Arial' size=5>";
     s += "<h1> Opciones </h1>";
}
void opcion4_o1(){
  s += "<h2> Elimina una trampa y puedes ver posiciones de bombas </h2>";
    s += "<p>";
    s += "Posicion: ";
}
void opcion4_t1(){
    s += "</p>";
  s += "<form action='/cambios'>";
  s += "<br>";
  s += "Posicion a eliminar bomba (Mediante ID)<br>";
  s += "<input type='text' name='eliminarbomba' value='0'>";
  s += "<br>";
  s += "<button><img src='https://cdn.onlinewebfonts.com/svg/img_18659.png' alt='imagen' width='32' height='32' style='vertical-align: middle'>Continuar</button></font></form>";
  server.send(200, "text/html", s);
}
void opcion4_o2(){
      pagina = "";
    pagina += "<style>body {background-image: url('https://wallup.net/wp-content/uploads/2019/10/197087-city-moscow-russia-war-night-apocalyptic-battle-dark.jpg');}</style><font color='White' face='Arial' size=5>";
    pagina += "<h2> Crear una unidad voladora </h2>";
    pagina += "<h3> Elige donde colocarla </h3>";
    pagina += "<p> ";
}
void opcion4_t2(){
  pagina += "</p>";
   pagina += "<form action='/cambios'>";
   pagina += "<br>";
  pagina +=  "Posicion unidad:<br>";
   pagina += "<input type='text' name='volador1' value='0'>";
   pagina += "<br><br>";
   pagina += "<button><img src='https://cdn.onlinewebfonts.com/svg/img_18659.png' alt='imagen' width='32' height='32' style='vertical-align: middle'>Continuar</button></font></form>";
    server.send(200, "text/html", pagina);
}
void opcion4_o3(){
        pagina = "";
      pagina += "<style>body {background-image: url('https://wallup.net/wp-content/uploads/2019/10/197087-city-moscow-russia-war-night-apocalyptic-battle-dark.jpg');}</style><font color='White' face='Arial' size=5>";
      pagina += "<h2> Debes regalar 1 posicion al rival</h2>";
     pagina += "<h3>Elige la posicion, si insertas una invalida se regalara 1 igualmente</h3>";
    pagina += "<p> ";
}
void opcion4_t3(){
     pagina += "</p>";
   pagina += "<form action='/cambios'>";
   pagina += "<br>";
   pagina +=  "Posicion regalada:<br>";
   pagina += "<input type='text' name='posicionregalada' value='0'>";
   pagina += "<br><br>";
   pagina += "<button><img src='https://cdn.onlinewebfonts.com/svg/img_18659.png' alt='imagen' width='32' height='32' style='vertical-align: middle'>Continuar</button></font></form>";  
    server.send(200, "text/html", pagina);
}
void opcion4_o4(){
  s = "";
     s += "<style>body {background-image: url('https://wallup.net/wp-content/uploads/2019/10/197087-city-moscow-russia-war-night-apocalyptic-battle-dark.jpg');}</style><font color='White' face='Arial' size=5>";
    s += "<h2> Aumentar un nivel a dos unidades </h2>";
    s += "<h3> Elija dos unidades en base a su id </h3>";
    s += "<p> ";
}
void opcion4_t4(){
      s += "</p>";
    s += "<form action='/cambios'>";
    s += "<br>";
     s +=  "Unidad 1 (ID):<br>";
 s += "<input type='text' name='Unidad1id' value='0'>";
 s += "<br>";
 s += "Unidad 2 (ID):<br>";
 s +="<input type='text' name='Unidad2id' value='0'>";
 s += "<br><br>";
 s += "<button><img src='https://cdn.onlinewebfonts.com/svg/img_18659.png' alt='imagen' width='32' height='32' style='vertical-align: middle'>Continuar</button></font></form>";
 server.send(200, "text/html", s);
}
void opcion4_o5(){
  s = "";
      s += "<style>body {background-image: url('https://wallup.net/wp-content/uploads/2019/10/197087-city-moscow-russia-war-night-apocalyptic-battle-dark.jpg');}</style><font color='White' face='Arial' size=5>";
     s += "<h2> Mueves una unidad a una posicion cualquiera </h2>";
    s += "<h3> Elija una unidad para moverla </h3>";
    s += "<p> ";
}
void opcion4_t5(){
      s += "</p>";
    s += "<form action='/cambios'>";
    s += "<br>";
     s +=  "Unidad (ID):<br>";
 s += "<input type='text' name='Unidad1elegida' value='0'>";
 s += "<br>";
  s += "Posicion (Entre 0 a 63)<br>";
 s +="<input type='text' name='Unidadlibrepos' value='0'>";
 s += "<br><br>";
 s += "<button><img src='https://cdn.onlinewebfonts.com/svg/img_18659.png' alt='imagen' width='32' height='32' style='vertical-align: middle'>Continuar</button></font></form>";
  server.send(200, "text/html", s);
}
void opcion4_o6(){
  s = "";
     s += "<style>body {background-image: url('https://wallup.net/wp-content/uploads/2019/10/197087-city-moscow-russia-war-night-apocalyptic-battle-dark.jpg');}</style><font color='White' face='Arial' size=5>";   
    s += "<h2> Pierdes una unidad </h2>";
    s += "<h3> Elige una unidad (ID): </h3>";
    s += "<p> ";
}
void opcion4_t6(){
           s += "</p>";
    s += "<form action='/cambios'>";
    s += "<br>";
     s +=  "Unidad (ID):<br>";
 s += "<input type='text' name='Unidadperdida' value='0'>";
 s += "<br>"; 
 s += "<button><img src='https://cdn.onlinewebfonts.com/svg/img_18659.png' alt='imagen' width='32' height='32' style='vertical-align: middle'>Continuar</button></font></form>";
  server.send(200, "text/html", s);
}
void opcion1_of(){
  s = "";
   s += "<style>body {background-image: url('https://wallup.net/wp-content/uploads/2019/10/197087-city-moscow-russia-war-night-apocalyptic-battle-dark.jpg');}</style><font color='White' face='Arial' size=5>";
   s += "<a href='/partida'> Continuar </a></font>";
 server.send(200, "text/html", s);
}
void imagen2(){
  s = "";
   s += "<style>body {background-image: url('https://wallup.net/wp-content/uploads/2019/10/197087-city-moscow-russia-war-night-apocalyptic-battle-dark.jpg');}</style><font color='White' face='Arial' size=5>";
}
void correcto(){
  s += "<a href='/partida'> Tropa movida correctamente </a>";
}
void incorrecto(){
  s += "<a href='/partida'> Tropa invalida </a>";
}
void bomba(){
  s += "<br><p> Tu unidad murio debido a que toco una bomba</p>";
}
void font(){
  s += "</font>";
  server.send(200, "text/html", s);
}
void opcion3_of(){
  s = "";
 s += "<style>body {background-image: url('https://wallup.net/wp-content/uploads/2019/10/197087-city-moscow-russia-war-night-apocalyptic-battle-dark.jpg');}</style><font color='White' face='Arial' size=5>";
 s += "<a href='/partida'> Continuar </a></font>";
server.send(200, "text/html", s);
}
void opcion4_of1(){
  s = "";
  s += "<style>body {background-image: url('https://wallup.net/wp-content/uploads/2019/10/197087-city-moscow-russia-war-night-apocalyptic-battle-dark.jpg');}</style><font color='White' face='Arial' size=5>";
      s += "<a href='/partida'> Continuar </a></font>";
    server.send(200, "text/html", s);
}
void continuar(){
  s = "";
       s += "<style>body {background-image: url('https://wallup.net/wp-content/uploads/2019/10/197087-city-moscow-russia-war-night-apocalyptic-battle-dark.jpg');}</style><font color='White' face='Arial' size=5>";
     s += "<a href='/partida'> Continuar </a></font>";
    server.send(200, "text/html", s);
}
void continuar2(){
      s += "<a href='/partida'> Continuar </a></font>";
    server.send(200, "text/html", s);
}
