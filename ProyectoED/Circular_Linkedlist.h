int colores[6][3] = {{255,255,0},{255,0,0},{0,0,255},{0,255,0},{255,0,255},{0,255,255}};
int ctn = 0;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(12, 15, NEO_GRB + NEO_KHZ800);
struct nodecirc
{
  int val;
  struct nodecirc *next;
};
struct nodecirc *empezar = NULL;
struct nodecirc *neopixelring(struct nodecirc *);
struct nodecirc *create_cll(struct nodecirc *);
struct nodecirc *create_cll(struct nodecirc *empezar)
{
 struct nodecirc *new_node, *ptr;
 int num = 0;
while(num<12)
{
 new_node = (struct nodecirc*)malloc(sizeof(struct nodecirc));
 new_node -> val = num;
 if(empezar == NULL)
 {
 new_node -> next = new_node;
 empezar = new_node;
 }
 else
 { ptr = empezar;
 while(ptr -> next != empezar){
 ptr = ptr -> next;}
 ptr -> next = new_node;
 new_node -> next = empezar;
 }
 num++;
}
return empezar;
}
struct nodecirc *neopixelring(struct nodecirc *empezar)
{
struct nodecirc *ptr;
int parar = 0;
int c = 0;
ptr=empezar;
long al_azar = random(11,38);
while(parar < al_azar)
{
  if((parar-c) == 6){
    c += 6;
  }
 pixels.setPixelColor((ptr->val),colores[parar-c][0],colores[parar-c][1],colores[parar-c][2]);
 pixels.show();
 delay(200);
 pixels.setPixelColor((ptr->val),0,0,0);
 pixels.show();
 ptr = ptr -> next;
 parar++;
}
ctn = parar-c;
return empezar;
}
