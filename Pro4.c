#include "biblioteca.h"
/*************************************************************
 *                     BUSCAMINAS/PROYECTO FINAL
 *  @archivo- Pro4.c
 *  @resumen- Este programa esta disñado para juegar cona interfaz
 *  del juego Buscamina que consiste en evitar las bombas y poderlas 
 *  localizar con todas las baneras del juego. Se utilizo todo tipo de
 *  funciones y prodecimientos aprendidos en clase para llegar al
 *  funcionamiento del programa.
 *
 *  @autores- David Parra y Daniela Requejo
 *  @fecha- 21-mayo-2015
 ***************************************************************/

gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer info);
void nuevo_juego(GtkWidget *widget, gpointer info);
void nuevo_juego1(GtkWidget *widget, gpointer info);
void recupera_juego(GtkWidget *widget, gpointer info);
void recupera_juego_4(GtkWidget *widget, gpointer info);
void Salir(GtkWidget *widget, gpointer info);
void comparacion(GtkWidget *widget, gpointer info);
void bomba(ELEMENTOS *elementos);
float rand9(void);
void check(GtkWidget *widget, gpointer info);
void no_hay_bombas(GtkWidget *widget, gpointer info);
void no_hay_bombas_1(GtkWidget *widget, gpointer info);
void no_hay_bombas_2(GtkWidget *widget, gpointer info);
void no_hay_bombas_3(GtkWidget *widget, gpointer info);
gint incrementa(gpointer info);
void estado(GtkWidget *widget, gpointer info);
void estado_1(GtkWidget *widget, gpointer info);
void estado_2(GtkWidget *widget, gpointer info);
gboolean bandera(GtkWidget *widget,GdkEvent *event, gpointer user_data);
void principal(ELEMENTOS *elementos);
void juego(ELEMENTOS *elementos);
void perdida(ELEMENTOS *elementos);
void guardada(ELEMENTOS *elementos);
void guardar_juego(GtkWidget *widget, gpointer info);
void seguir_juego(GtkWidget *widget, gpointer info);
void comparacion_r(GtkWidget *widget, gpointer info);
void check_r(GtkWidget *widget, gpointer info);
void no_hay_bombas_r(GtkWidget *widget, gpointer info);
gint incrementa_r(gpointer info);
gboolean bandera_r(GtkWidget *widget,GdkEvent *event, gpointer user_data);
void juego_r(ELEMENTOS *elementos);
void guardada_r(ELEMENTOS *elementos);
void guardar_juego_r(GtkWidget *widget, gpointer info);
void seguir_juego_r(GtkWidget *widget, gpointer info);
void guardar_juego_1(GtkWidget *widget, gpointer info);
void ventana_ayuda(ELEMENTOS *elementos);
void ayuda(GtkWidget *widget, gpointer info);
void terminar_guardar(ELEMENTOS *elementos);
void atras_1(GtkWidget *widget, gpointer info);
void adelante_1(GtkWidget *widget, gpointer info);
void terminar_1(GtkWidget *widget, gpointer info);
void ganador(GtkWidget *widget, gpointer info);
void vetana_ganador(ELEMENTOS *elementos);
void gano(ELEMENTOS *elementos);
void comparacion_a(GtkWidget *widget, gpointer info);
void ordenar(ELEMENTOS *elementos);
void quicksort(char *nombre[],int izquierda,int derecha);
void ventana_top_5(ELEMENTOS *elementos);
void mostrar_top(GtkWidget *widget, gpointer info);
void ventana_recuperar(ELEMENTOS *elementos);
void ventana_copia(ELEMENTOS *elementos);
void mostrar_nuevo(GtkWidget *widget, gpointer info);
void mostrar_recupera(GtkWidget *widget, gpointer info);
void com_guardar(GtkWidget *widget, gpointer info);
void deme_nombre(ELEMENTOS *elementos);
void guardar_juego_2(GtkWidget *widget, gpointer info);
void maximo_sig(ELEMENTOS *elementos);
void mov_sig(ELEMENTOS *elementos);
void sig(GtkWidget *widget, gpointer info);
void mostrar_max(GtkWidget *widget, gpointer info);
void muestra_sig(GtkWidget *widget, gpointer info);
void lista_v(GtkWidget *widget, gpointer info);
void no_hay_bombas_4(GtkWidget *widget, gpointer info);

int main(int argc, char *argv[]){  
  ELEMENTOS *elementos;  
  gint x;
  gtk_init(&argc,&argv);
  elementos=malloc(sizeof(ELEMENTOS));
  elementos->lista=NULL;
  elementos->jugador=malloc(sizeof(CRONOS));
  elementos->flag=0;
  elementos->x=0;  //iniciar variables en cero
  elementos->z=0;
  strcpy(elementos->o,"0");
  strcpy(elementos->h,"0");
  strcpy(elementos->b,"0");
  //crecion de las ventanas

  elementos->jugador->num_tiros=0;  //creacion cronometro para ventana juego
  elementos->jugador->segundos=0;
  elementos->jugador->minutos=0;
  elementos->jugador->horas=0;
  elementos->contador=10;
  elementos->flag=0;
  principal(elementos);
  juego_r(elementos);
  juego(elementos);
  perdida(elementos);
  guardada(elementos);
  vetana_ganador(elementos);
  ventana_ayuda(elementos);
  terminar_guardar(elementos);
  ventana_top_5(elementos);
  deme_nombre(elementos);
  ventana_copia(elementos);
  ventana_recuperar(elementos);
  maximo_sig(elementos);
  mov_sig(elementos);
  gtk_widget_show_all(elementos->ventana);
  bomba(elementos);

  //creacion de imagenes para las bombas
  for(x=0;x<10;x++){
    elementos->bomba[x]=gtk_image_new_from_file("bomba.jpg");
  }
  for(x=0;x<81;x++){
    strcpy(elementos->boton1[x],"0");
  }
  gtk_main();
  return 0;
}
/**************************************************************************
 *  @resumen- Este procedimiento nos checa localizara las bombas
 *  en sus respectivas coordenada y de esa forma obtener la coordenada
 *  y guardaralas en un arreglo.
 *
 *  @autores- David Parra
 *  @fecha- 21-mayo-2015
 *
 *  @param- un puntero de tipo ELEMENTOS que contiene toda nuestra estucturas 
 ****************************************************************************/
void bomba(ELEMENTOS *elementos){
  int x,cuantas=0;
  float w,z,w1,z1,w2,z2,w3,z3;
  w2=0;
  z2=1;
  w3=8;
  z3=9;
  for(x=0;x<10;x++){
    w=rand9();
    if(w==9){
      while(w!=9){
	w=rand9();
      }
    }
    z=w+1;
    w1=rand9(); //llama la funcion raddom que da las coordenada aleatoriamente
    if(w1==9){
      while(w1!=9){
	w1=rand9();
      }
    }
    z1=w1+1;

    sprintf(elementos->bombas[x],"%.0f-%.0f-%.0f-%.0f",w,z,w1,z1);
    sprintf(elementos->bombas[9],"%0.f-%0.f-%0.f-%0.f",w2,z2,w3,z3);
  }
  //asignacion de coordenadas al arreglo de bombas
  for(x=1;x<10;x++){
    if(strcmp(elementos->bombas[0],elementos->bombas[x])==0){
      cuantas++;
    } 
  }
  for(x=2;x<10;x++){
    if(strcmp(elementos->bombas[1],elementos->bombas[x])==0){
      cuantas++;
    } 
  }
  for(x=3;x<10;x++){
    if(strcmp(elementos->bombas[2],elementos->bombas[x])==0){
      cuantas++;
    } 
  }
  for(x=4;x<10;x++){
    if(strcmp(elementos->bombas[3],elementos->bombas[x])==0){
      cuantas++;
    } 
  }
for(x=5;x<10;x++){
    if(strcmp(elementos->bombas[4],elementos->bombas[x])==0){
      cuantas++;
    } 
  }
for(x=6;x<10;x++){
    if(strcmp(elementos->bombas[5],elementos->bombas[x])==0){
      cuantas++;
    } 
  }
for(x=7;x<10;x++){
    if(strcmp(elementos->bombas[6],elementos->bombas[x])==0){
      cuantas++;
    } 
  }
for(x=8;x<10;x++){
    if(strcmp(elementos->bombas[7],elementos->bombas[x])==0){
      cuantas++;
    } 
  }
for(x=9;x<10;x++){
    if(strcmp(elementos->bombas[8],elementos->bombas[x])==0){
      cuantas++;
    } 
  }
  if(cuantas>0){
    bomba(elementos);
  }
  for(x=0;x<10;x++){
    printf("%s\n",elementos->bombas[x]);
  }

}
/**************************************************************************
 *  @resumen- Esta funcion nos crea las cordenadas aleatoriamente de las bombas
 *  regresando un valor entero.
 *
 *  @autores- Daniela Requejo
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
float rand9(void)
{
  static float firstcall = 1;
   if (firstcall)
     {
       srand((unsigned int)time(NULL));
       firstcall = 0;
     }
   return (rand()%9); //un numero aleatorio hasta el limite del tablero = 9
}
/**************************************************************************
 *  @resumen- En esta funcion regrese un False para de esa forma cerrar una ventana
 *
 *  @autores- David Parra y Daniela Requejo
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer info){
  return FALSE;
}

/**************************************************************************
 *  @resumen- Este procedimiento nos cierra una ventana
 *
 *  @autores- David Parra y Daniela Requejo
 *  @fecha- 21-mayo-2015
 *
 *  @param- un widget que es el boton seleccionado para cerrar la ventana seleccionada
 ****************************************************************************/
void Salir(GtkWidget *widget, gpointer info){
  gtk_main_quit();
}
/**************************************************************************
 *  @resumen- Este procedimiento nos guarda el juego manejando listas 
 *  dinamicas se guarda lo que se encuentre en el tablero y de esa forma
 *  se pueda recuperar el juego ya empezado. Se guardara todo en un archivo con el
 *  el nombre del jugador en archivo de texto.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 *  @param- un widget que indico que se realizara la guardada de la partida
 ****************************************************************************/
void guardar_juego(GtkWidget *widget, gpointer info){
  const gchar *buffer1;
  gchar *buffer2,*buffer3,*buffer4;
  gint x1,x2;
  const gchar *tiempo;
  ELEMENTOS *elementos = (ELEMENTOS *)info;
  DATOS *persona;
  FILE *f1,*f2,*f3;
  gint i;
  gpointer info1;
  gtk_widget_set_sensitive(elementos->ventana1,FALSE);
  buffer2=malloc(sizeof(gchar));
  buffer3=malloc(sizeof(gchar));
  buffer4=malloc(sizeof(gchar));
  buffer1=gtk_entry_get_text(GTK_ENTRY(elementos->textbox));
  tiempo=gtk_label_get_text(GTK_LABEL(elementos->label_time));
  sscanf(tiempo,"Minutos: %d Segundos: %d",&x1,&x2);
  sprintf(buffer2,"%s.bcm",buffer1);
  sprintf(buffer3,"%s1.bcm",buffer1);
  sprintf(buffer4,"%s2.bcm",buffer1);
  f1=fopen(buffer2,"w");
  f2=fopen(buffer3,"w");
  f3=fopen(buffer4,"w");
  for(i=0;i<g_slist_length(elementos->lista);i++){
    info1=g_slist_nth_data(elementos->lista,i);
    persona=(DATOS*)info1;
    //    fwrite(persona,sizeof(DATOS),1,f1);
    fprintf(f1,"%s\n",persona->coor);
  }
  for(i=0;i<10;i++){
    fprintf(f2,"%s\n",elementos->bombas[i]);
  }
  fprintf(f3,"%d\n",x1);
  fprintf(f3,"%d\n",x2);
  fclose(f1);
  fclose(f2);
  fclose(f3);
  gtk_widget_show_all(elementos->ventana3);
  gtk_widget_hide(elementos->ventana13);
  gtk_widget_hide(elementos->ventana14);
}
/**************************************************************************
 *  @resumen- Este procedimiento nos guarda el juego manejando listas 
 *  dinamicas se guarda lo que se encuentre en el tablero y de esa forma
 *  se pueda recuperar el juego ya empezado.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 *  @param- un widget que indico que se realizara la guardada de la partida
 ****************************************************************************/
void guardar_juego_2(GtkWidget *widget, gpointer info){
  const gchar *buffer1;
  gchar *buffer2,*buffer3;
  ELEMENTOS *elementos = (ELEMENTOS *)info;
  DATOS *persona;
  FILE *f1,*f2;
  gint i;
  gpointer info1;
  gtk_widget_set_sensitive(elementos->ventana1,FALSE);
  buffer2=malloc(sizeof(gchar));
  buffer3=malloc(sizeof(gchar));
  buffer1=gtk_entry_get_text(GTK_ENTRY(elementos->textbox2));
  sprintf(buffer2,"%s.bcm",buffer1);
  sprintf(buffer3,"%s1.bcm",buffer1);
  f1=fopen(buffer2,"w");
  f2=fopen(buffer3,"w");
  for(i=0;i<g_slist_length(elementos->lista);i++){ // creacion de listas para ir guardando la jugada
    info1=g_slist_nth_data(elementos->lista,i);
    persona=(DATOS*)info1;
    //    fwrite(persona,sizeof(DATOS),1,f1);
    fprintf(f1,"%s\n",persona->coor);
  }
  for(i=0;i<10;i++){
    fprintf(f2,"%s\n",elementos->bombas[i]);
  }
  fclose(f1);
  fclose(f2);
  gtk_widget_show_all(elementos->ventana3);
  gtk_widget_hide(elementos->ventana13);
  gtk_widget_hide(elementos->ventana14);
}
/**************************************************************************
 *  @resumen- Este procedimiento nos mandara una ventana que se preguntara si
 *  se quiere seguir jugando.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 *  @param- un widget que indico que realizo para mostrar este mensaje de advertencia
 ****************************************************************************/
void seguir_juego(GtkWidget *widget, gpointer info){
    ELEMENTOS *elementos = (ELEMENTOS *)info;
    gtk_widget_hide(elementos->ventana3);
    gtk_widget_set_sensitive(elementos->ventana1,TRUE);
}
/**************************************************************************
 *  @resumen- Este procedimiento nos creara una ventana nueva como si fuera una 
 *  juegada nueva empezara todo desde cero.
 *
 *  @autores- David Parra y Daniela Requejo
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
void nuevo_juego(GtkWidget *widget, gpointer info){
  const gchar *buffer1;
  gchar *buffer2,*mina1;
  ELEMENTOS *elementos = (ELEMENTOS *)info;
  buffer2=malloc(sizeof(gchar));
  mina1=malloc(sizeof(gchar));
  buffer1=gtk_entry_get_text(GTK_ENTRY(elementos->textbox));
  sprintf(buffer2,"El jugador es : %s",buffer1);
  gtk_widget_hide(elementos->ventana); //escondemos la ventana anterior para mostrar la nueva
  gtk_label_set_text(GTK_LABEL(elementos->label),buffer2);
  sprintf(mina1,"%d",elementos->contador);
  gtk_label_set_text(GTK_LABEL(elementos->label_mina),mina1);
  gtk_widget_show_all(elementos->ventana1);
}
/**************************************************************************
 *  @resumen- Este procedimiento nos creara una ventana nueva como si fuera una 
 *  juegada nueva empezara todo desde cero.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
void nuevo_juego1(GtkWidget *widget, gpointer info){
  const gchar *buffer1;
  gchar *buffer2;
  ELEMENTOS *elementos = (ELEMENTOS *)info;
  gchar *mina1;
  buffer2=malloc(sizeof(gchar));
  mina1=malloc(sizeof(gchar));
  gtk_widget_hide(elementos->ventana1);
  gtk_widget_hide(elementos->ventana2);
  g_slist_free(elementos->lista);
  elementos->lista=NULL;
  elementos->flag=0;
  elementos->jugador->num_tiros=0;  //cronometro
  elementos->jugador->segundos=0;
  elementos->jugador->minutos=0;
  elementos->jugador->horas=0;
  elementos->contador=10;
  juego(elementos);
  bomba(elementos);
  buffer1=gtk_entry_get_text(GTK_ENTRY(elementos->textbox));
  sprintf(buffer2,"El jugador es : %s",buffer1); //se imprimira el nombre sel jugador
  gtk_label_set_text(GTK_LABEL(elementos->label),buffer2);
  sprintf(mina1,"%d",elementos->contador);
  gtk_label_set_text(GTK_LABEL(elementos->label_mina),mina1);
  gtk_widget_show_all(elementos->ventana1); 
  
}
/**************************************************************************
 *  @resumen- Este procedimiento nos recuperara el juego ya una vez creado
 *  se ingreasara el nombre y validara si existe y abrira el archivo de texto
 *  y lo ira leyendo y se ira imprimiendo poco a poco el tablero hasta que ya 
 *  ya no haya mas moviemientos
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
void recupera_juego(GtkWidget *widget, gpointer info){
  gint x,x1,x2,x3;
  ELEMENTOS *elem=(ELEMENTOS *)info;
  FILE *f1,*f2,*f3;
  DATOS *persona;
  gpointer info1;
  gchar *buffer3,*mina1,*buffer4,*buffer5,*buffer7;
  const gchar *buffer1,*buffer2;
  gint i=0;
  g_slist_free(elem->lista);
  elem->lista=NULL;
  elem->explo=malloc(sizeof(DATOS));
  buffer3=malloc(sizeof(gchar));
  buffer5=malloc(sizeof(gchar));
  buffer7=malloc(sizeof(gchar));
  buffer1=gtk_entry_get_text(GTK_ENTRY(elem->textbox1));
  sprintf(buffer3,"%s.bcm",buffer1);
  sprintf(buffer5,"%s1.bcm",buffer1);
  sprintf(buffer7,"%s2.bcm",buffer1);
  g_print("%s\n",buffer5);
  g_print("%s\n",buffer3);
  f1=fopen(buffer3,"r");
  f2=fopen(buffer5,"r");
  f3=fopen(buffer7,"r");
  fscanf(f3,"%d",&x2);
  fscanf(f3,"%d",&x3);
  elem->jugador->segundos=x3;
  elem->jugador->minutos=x2;
  elem->jugador->num_tiros=1;
  while(fscanf(f1,"%s",elem->explo->coor)==1){
    elem->lista=g_slist_append(elem->lista,elem->explo->coor);
    elem->explo=malloc(sizeof(DATOS));
  }
  while(fscanf(f2,"%s",elem->bombas[i])==1){
    i++;
  }
  for(x=0;x<g_slist_length(elem->lista);x++){
    info1=g_slist_nth_data(elem->lista,x);
    persona=(DATOS*)info1;
    for(x1=0;x1<81;x1++){
      buffer2=gtk_widget_get_name(elem->boton[x1]);
      if(strcmp(persona->coor,buffer2)==0){
	comparacion_a(elem->boton[x1],elem);
      }
    }
  }
  strcpy(elem->o,"1");
  fclose(f1);
  fclose(f2);
  buffer4=malloc(sizeof(gchar));
  mina1=malloc(sizeof(gchar));
  sprintf(buffer4,"El jugador es : %s",buffer1);
  gtk_widget_hide(elem->ventana);
  gtk_label_set_text(GTK_LABEL(elem->label),buffer4);
  sprintf(mina1,"%d",elem->contador);
  gtk_label_set_text(GTK_LABEL(elem->label_mina),mina1);
  gtk_widget_hide(elem->ventana1);
  gtk_widget_hide(elem->ventana12);
  gtk_widget_hide(elem->ventana13);
  gtk_widget_hide(elem->ventana14);
  gtk_widget_hide(elem->ventana16);
  gtk_widget_show_all(elem->ventana1);
  
}
/**************************************************************************
 *  @resumen- Este procedimiento nos recuperara el juego ya una vez creado
 *  se ingreasara el nombre y validara si existe y abrira el archivo de texto
 *  y lo ira leyendo y se ira imprimiendo poco a poco el tablero hasta que ya 
 *  ya no haya mas moviemientos
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
void recupera_juego_4(GtkWidget *widget, gpointer info){
  gint x,x1;
  ELEMENTOS *elem=(ELEMENTOS *)info;
  FILE *f1,*f2;
  DATOS *persona;
  gpointer info1;
  gchar *buffer3,*mina1,*buffer4,*buffer5;
  const gchar *buffer1,*buffer2;
  gint i=0;
  elem->explo=malloc(sizeof(DATOS));
  buffer3=malloc(sizeof(gchar)); 
  buffer5=malloc(sizeof(gchar));
  buffer1=gtk_entry_get_text(GTK_ENTRY(elem->textbox4));
  sprintf(buffer3,"%s.bcm",buffer1);
  sprintf(buffer5,"%s1.bcm",buffer1);
  g_print("%s\n",buffer5);
  g_print("%s\n",buffer3);
  f1=fopen(buffer3,"r");
  f2=fopen(buffer5,"r");
  while(fscanf(f1,"%s",elem->explo->coor)==1){ //lee el archivo de la persona para poder recuperar su juego, lo hcae por medio de comparaciones
    elem->lista=g_slist_append(elem->lista,elem->explo->coor);
    elem->explo=malloc(sizeof(DATOS));
  }
  while(fscanf(f2,"%s",elem->bombas[i])==1){
    i++;
  }
  for(x=0;x<g_slist_length(elem->lista);x++){
    info1=g_slist_nth_data(elem->lista,x);
    persona=(DATOS*)info1;
    for(x1=0;x1<81;x1++){
      buffer2=gtk_widget_get_name(elem->boton[x1]);
      if(strcmp(persona->coor,buffer2)==0){
	comparacion_a(elem->boton[x1],elem);
      }
    }
  }
  strcpy(elem->o,"1");
  fclose(f1);
  fclose(f2);
  buffer4=malloc(sizeof(gchar));
  mina1=malloc(sizeof(gchar));
  sprintf(buffer4,"El jugador es : %s",buffer1);
  gtk_widget_hide(elem->ventana);
  gtk_label_set_text(GTK_LABEL(elem->label),buffer4);
  sprintf(mina1,"%d",elem->contador);
  gtk_label_set_text(GTK_LABEL(elem->label_mina),mina1);
  gtk_widget_hide(elem->ventana1);  //se esconden las ventanas para que al recuperar pueda ver la ventana con su juego final
  gtk_widget_hide(elem->ventana12);
  gtk_widget_hide(elem->ventana13);
  gtk_widget_hide(elem->ventana14);
  gtk_widget_show_all(elem->ventana1);
  
}
/**************************************************************************
 *  @resumen- Este procedimiento se checa si hay bombas alrededor para que de esa 
 *  forma se impriman los numeros correspondientes y de otra forma ponerlo 
 *  insensible. Funciona con recursiva para checar que no falte cuardro por abrir
 *
 *  @autores- David Parra y Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
void no_hay_bombas(GtkWidget *widget, gpointer info){
  
  //gtk_widget_set_sensitive(widget,FALSE);
  gint y,w,z,u,x,y1,w1,z1,u1;
  const gchar *buffer,*buffer1,*buffer2;
  ELEMENTOS *elem=(ELEMENTOS *)info;
  gchar y2[9],y3[9];
  
  buffer=gtk_widget_get_name(widget);
  gtk_widget_set_sensitive(widget,FALSE);
  sscanf(buffer,"%d-%d-%d-%d",&y,&w,&z,&u);
  y=y+1;
  w=w+1;
  sprintf(y2,"%d-%d-%d-%d",y,w,z,u);
  for(x=0;x<81;x++){
    buffer1=gtk_widget_get_name(elem->boton[x]);
    if(strcmp(buffer1,y2)==0){
      check(elem->boton[x],elem);
    }
  }
  buffer2=gtk_widget_get_name(widget); //lee el boton clickeado y hace comparacion para que de esa forma pueda pueda comparar sies bomba o no
  sscanf(buffer2,"%d-%d-%d-%d",&y1,&w1,&z1,&u1);
  z1=z1+1;
  u1=u1+1;
  sprintf(y3,"%d-%d-%d-%d",y1,w1,z1,u1);
  
  for(x=0;x<81;x++){
    buffer1=gtk_widget_get_name(elem->boton[x]);
    if(strcmp(buffer1,y3)==0){
      check(elem->boton[x],elem);
    }
  }
}
/**************************************************************************
 *  @resumen- Este procedimiento se checa si hay bombas alrededor para que de esa 
 *  forma se impriman los numeros correspondientes y de otra forma ponerlo 
 *  insensible. Funciona con recursiva para checar que no falte cuardro por abrir
 *
 *  @autores- David Parra y Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
void no_hay_bombas_3(GtkWidget *widget, gpointer info){
 gint x,y1,w1,z1,u1,y6,w6,z6,u6;
 const gchar *buffer1,*buffer2,*buffer3;
  ELEMENTOS *elem=(ELEMENTOS *)info;
  gchar y3[9],y4[9];
  gtk_widget_set_sensitive(widget,FALSE);
  buffer3=gtk_widget_get_name(widget);
  sscanf(buffer3,"%d-%d-%d-%d",&y6,&w6,&z6,&u6);
  y6=y6-1;
  w6=w6-1;
  sprintf(y4,"%d-%d-%d-%d",y6,w6,z6,u6);  
  if(y6!=-1){
    for(x=0;x<81;x++){
      buffer1=gtk_widget_get_name(elem->boton[x]);
      if(strcmp(buffer1,y4)==0){
	check(elem->boton[x],elem);
      }
    }
  }

  buffer2=gtk_widget_get_name(widget);  
  sscanf(buffer2,"%d-%d-%d-%d",&y1,&w1,&z1,&u1);
  z1=z1+1;
  u1=u1+1;
  sprintf(y3,"%d-%d-%d-%d",y1,w1,z1,u1);
  
  for(x=0;x<81;x++){
    buffer1=gtk_widget_get_name(elem->boton[x]);
    if(strcmp(buffer1,y3)==0){
      check(elem->boton[x],elem);
    }
  }

}
/**************************************************************************
 *  @resumen- Este procedimiento se checa si hay bombas alrededor para que de esa 
 *  forma se impriman los numeros correspondientes y de otra forma ponerlo 
 *  insensible.Funciona con recursiva para checar que no falte cuardro por abrir
 *
 *  @autores- David Parra y Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
void no_hay_bombas_1(GtkWidget *widget, gpointer info){
  ELEMENTOS *elem=(ELEMENTOS *)info;
  gint x,y7,w7,z7,u7,y6,w6,z6,u6;
  const gchar *buffer1,*buffer4,*buffer3;
  gchar y5[9],y4[9];
  
  buffer3=gtk_widget_get_name(widget);
  gtk_widget_set_sensitive(widget,FALSE);
  
  sscanf(buffer3,"%d-%d-%d-%d",&y6,&w6,&z6,&u6);
  y6=y6-1;
  w6=w6-1;
  sprintf(y4,"%d-%d-%d-%d",y6,w6,z6,u6);
  
  if(y6!=-1){
    for(x=0;x<81;x++){
      buffer1=gtk_widget_get_name(elem->boton[x]);
      if(strcmp(buffer1,y4)==0){
	check(elem->boton[x],elem);
      }
    }
  }
  buffer4=gtk_widget_get_name(widget);  
  sscanf(buffer4,"%d-%d-%d-%d",&y7,&w7,&z7,&u7);
  z7=z7-1;
  u7=u7-1;
  sprintf(y5,"%d-%d-%d-%d",y7,w7,z7,u7);
 
  if(z7!=-1){
    for(x=0;x<81;x++){
      buffer1=gtk_widget_get_name(elem->boton[x]);
      if(strcmp(buffer1,y5)==0){
	check(elem->boton[x],elem);
      }
    }
  }

}
/**************************************************************************
 *  @resumen- Este procedimiento se checa si hay bombas alrededor para que de esa 
 *  forma se impriman los numeros correspondientes y de otra forma ponerlo 
 *  insensible. Funciona con recursiva para checar que no falte cuardro por abrir
 *
 *  @autores- David Parra y Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
void no_hay_bombas_2(GtkWidget *widget, gpointer info){
  ELEMENTOS *elem=(ELEMENTOS *)info;
  gint x,y,w,z,u,y6,w6,z6,u6;
  const gchar *buffer1,*buffer,*buffer3;
  gchar y2[9],y4[9];

  buffer=gtk_widget_get_name(widget);
  gtk_widget_set_sensitive(widget,FALSE);
  buffer3=gtk_widget_get_name(widget);
  sscanf(buffer3,"%d-%d-%d-%d",&y6,&w6,&z6,&u6); //convierte a entero
  y6=y6-1;
  w6=w6-1;
  sprintf(y4,"%d-%d-%d-%d",y6,w6,z6,u6); // convierte a caracter
   
   if(y6!=-1){
     for(x=0;x<81;x++){
       buffer1=gtk_widget_get_name(elem->boton[x]);
       if(strcmp(buffer1,y4)==0){
	 check(elem->boton[x],elem);
       }
    }
   }
   
   sscanf(buffer,"%d-%d-%d-%d",&y,&w,&z,&u);
   y=y+1;
   w=w+1; //le suma para moverse de coordenada
   sprintf(y2,"%d-%d-%d-%d",y,w,z,u);
   for(x=0;x<81;x++){
    buffer1=gtk_widget_get_name(elem->boton[x]);
    if(strcmp(buffer1,y2)==0){
      check(elem->boton[x],elem);
    }
   }
  
}

void no_hay_bombas_4(GtkWidget *widget, gpointer info){
  ELEMENTOS *elem=(ELEMENTOS *)info;
  gint x,y,w,z,u,y7,w7,z7,u7;
  const gchar *buffer1,*buffer,*buffer4;
  gchar y2[9],y5[9];

  buffer=gtk_widget_get_name(widget);
  gtk_widget_set_sensitive(widget,FALSE);
  buffer4=gtk_widget_get_name(widget);  
  sscanf(buffer4,"%d-%d-%d-%d",&y7,&w7,&z7,&u7);
  z7=z7-1;
  u7=u7-1;
  sprintf(y5,"%d-%d-%d-%d",y7,w7,z7,u7);
 
  if(z7!=-1){
    for(x=0;x<81;x++){
      buffer1=gtk_widget_get_name(elem->boton[x]);
      if(strcmp(buffer1,y5)==0){
	check(elem->boton[x],elem);
      }
    }
  }
   
   sscanf(buffer,"%d-%d-%d-%d",&y,&w,&z,&u);
   y=y+1;
   w=w+1; //le suma para moverse de coordenada
   sprintf(y2,"%d-%d-%d-%d",y,w,z,u);
   for(x=0;x<81;x++){
    buffer1=gtk_widget_get_name(elem->boton[x]);
    if(strcmp(buffer1,y2)==0){
      check(elem->boton[x],elem);
    }
   }
  
}


/**************************************************************************
 *  @resumen- Este procedimiento se checa si hay bombas alrededor para que de
 *  esa forma vaya contando y vaya imprimiendo en el tablero la canridad de
 *  bombas hay si no hay se ira a las funciones no_hay_bomba para comparar lo 
 *  demas
 *
 *  @autores- Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 *  @param- recibe un widget del boton accionado para que de esa forma pueda
 *  realizar la comparacion 
 ****************************************************************************/
void check(GtkWidget *widget, gpointer info){
  gint x=0,x1,y,w,z,u;
  const gchar *buffer;
  ELEMENTOS *elem=(ELEMENTOS *)info;
  gchar boton1[9],y1[9],z1[9],w1[9],b1[9],a1[9],c1[9],e1[9],f1[9],y4[9];
  GtkWidget *uno,*dos,*tres,*cuatro,*cinco;
  
  buffer=gtk_widget_get_name(widget);
  strcpy(boton1,buffer);
  sscanf(boton1,"%d-%d-%d-%d",&y,&w,&z,&u);
  y=y-1;
  w=w-1;
  if(w!=-1){
    sprintf(y1,"%d-%d-%d-%d",y,w,z,u);
    for(x1=0;x1<10;x1++){
      if(strcmp(elem->bombas[x1],y1)==0){
	x++;
      }
    }
  }
  sscanf(y1,"%d-%d-%d-%d",&y,&w,&z,&u);
  z=z-1;
  u=u-1;
  if(u!=-1){
    sprintf(z1,"%d-%d-%d-%d",y,w,z,u);
    for(x1=0;x1<10;x1++){
      if(strcmp(elem->bombas[x1],z1)==0){
	x++;
      }
    }
  }
  sscanf(y1,"%d-%d-%d-%d",&y,&w,&z,&u);
  z=z+1;
  u=u+1;
  if(u!=10){
    sprintf(w1,"%d-%d-%d-%d",y,w,z,u);
    for(x1=0;x1<10;x1++){
      if(strcmp(elem->bombas[x1],w1)==0){
	x++;
      }
    }
  }
  sscanf(boton1,"%d-%d-%d-%d",&y,&w,&z,&u);
  z=z-1;	
  u=u-1;
  if(u!=-1){
    sprintf(a1,"%d-%d-%d-%d",y,w,z,u);
    for(x1=0;x1<10;x1++){
      if(strcmp(elem->bombas[x1],a1)==0){
	x++;
      }
    }
  }
  sscanf(boton1,"%d-%d-%d-%d",&y,&w,&z,&u);
  z=z+1;
  u=u+1;
  if(u!=10){
    sprintf(b1,"%d-%d-%d-%d",y,w,z,u);
    for(x1=0;x1<10;x1++){
      if(strcmp(elem->bombas[x1],b1)==0){
	x++;
      }
    }
  }
  sscanf(boton1,"%d-%d-%d-%d",&y,&w,&z,&u);
  y=y+1;
  w=w+1;
  if(w!=10){
    sprintf(c1,"%d-%d-%d-%d",y,w,z,u);
    for(x1=0;x1<10;x1++){
      if(strcmp(elem->bombas[x1],c1)==0){
	x++;
      }
    }      
  }
  sscanf(c1,"%d-%d-%d-%d",&y,&w,&z,&u);
  z=z-1;
  u=u-1;
  if(u!=-1){
    sprintf(e1,"%d-%d-%d-%d",y,w,z,u);
    for(x1=0;x1<10;x1++){
      if(strcmp(elem->bombas[x1],e1)==0){
	x++;
      }
    } 
  }
  sscanf(c1,"%d-%d-%d-%d",&y,&w,&z,&u);
  z=z+1;
  u=u+1;
  if(u!=10){
    sprintf(f1,"%d-%d-%d-%d",y,w,z,u);
    for(x1=0;x1<10;x1++){
      if(strcmp(elem->bombas[x1],f1)==0){
	x++;
      }
    }
  }
  if(x==1){ //una bomba
    uno=gtk_image_new_from_file("1.jpg");
    gtk_button_set_image(GTK_BUTTON(widget),uno);
    //gtk_widget_set_sensitive(widget,FALSE);
    
 }
  if(x==2){ //dos bombas
    dos=gtk_image_new_from_file("2.jpg");
    gtk_button_set_image(GTK_BUTTON(widget),dos);
    //gtk_widget_set_sensitive(widget,FALSE);
    
  }
  if(x==3){ //tres bombas
    tres=gtk_image_new_from_file("3.jpg");
    gtk_button_set_image(GTK_BUTTON(widget),tres);
    //gtk_widget_set_sensitive(widget,FALSE);
    
  }
  if(x==4){ //cuatro bombas
    cuatro=gtk_image_new_from_file("4.jpg");
    gtk_button_set_image(GTK_BUTTON(widget),cuatro);
    //gtk_widget_set_sensitive(widget,FALSE);
    
  }
  if(x==5){ //cinco bombas
    cinco=gtk_image_new_from_file("5.jpg");
    gtk_button_set_image(GTK_BUTTON(widget),cinco);
    //gtk_widget_set_sensitive(widget,FALSE);
    
  }
  if(x==0){ //seis bombas
    sscanf(elem->buffer3,"%d-%d-%d-%d",&y,&w,&z,&u);
    sprintf(y4,"%d-%d-%d-%d",y,w,z,u);
    if(y<=4){
      no_hay_bombas(widget,elem);
    }else if(y<4&&z<9){
      no_hay_bombas_4(widget,elem);
    }else if(y>4&&z==8){
      no_hay_bombas_1(widget,elem);
    }else if(y>3&&z>4){
      no_hay_bombas_2(widget,elem);
    }else if(y<4&&z<2){
      no_hay_bombas(widget,elem);}
    else if(y>4&&z<3){
      no_hay_bombas_3(widget,elem);}
    else if(y>4&&z>=4){
      no_hay_bombas_1(widget,elem);}
    else{
      no_hay_bombas_1(widget,elem);
    }
  }
} 

/**************************************************************************
 *  @resumen- Este procedimiento se checa si el bontan selecciondo fue bomba 
 *  en caso de que se seleccione se mostraran todas las bombas en el tablero.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 *  @param- un widget del boton accionada para hacer la comparacion
 ****************************************************************************/
void comparacion(GtkWidget *widget, gpointer info){
  //gint x,y,w,y1,w1,a=0;
  gint x3=0,x2,x1=0,x,y,w,y1,w1,a=0;
  const gchar *buffer,*buffer1;
  ELEMENTOS *elem=(ELEMENTOS *)info;
  gchar bomba[9], y2[9];
  buffer=gtk_widget_get_name(widget);
  elem->buffer3=gtk_widget_get_name(widget);
  elem->explo=malloc(sizeof(DATOS));
  strcpy(elem->explo->coor,buffer);
  elem->lista=g_slist_append(elem->lista,elem->explo->coor);
  for(x=0;x<10;x++){
      if(strcmp(buffer,elem->bombas[x])==0){
	a=1;
	  for(x2=0;x2<81;x2++){
	    if(x1<10){
	      strcpy(bomba,elem->bombas[x1]);
	      sscanf(bomba,"%d-%d-%d-%d",&y,&w,&y1,&w1);
	      sprintf(y2,"%d-%d-%d-%d",y,w,y1,w1);
	      buffer1=gtk_widget_get_name(elem->boton[x2]);
	      if(strcmp(y2,buffer1)==0){ //comparacion del arreglo de bomvbas con el boton seleccionado
		gtk_button_set_image(GTK_BUTTON(elem->boton[x2]),elem->bomba[x3]);
		x3++;
		x1++;
		gtk_widget_set_sensitive(elem->boton[x2],FALSE);
		x2=-1;
	      }
	    }
	  }
	  g_source_remove(elem->id);
	  gtk_widget_set_sensitive(elem->ventana1,FALSE);
	  gtk_widget_show_all(elem->ventana2);
      }
  }
  if(a==0){
    check(widget,elem); //llamada de la funcion para checar que se tiene alrededor en caso de que no sea bomba
  }
  
}
/**************************************************************************
 *  @resumen- Esta funcion nos creara unos contadores que al final sera
 *  nuestro timer que se mostrara desde del inicio del juego. Se aumentara cada 
 *  determinado momento.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/

gint incrementa(gpointer info){
  ELEMENTOS* crono = (ELEMENTOS*)info;
  gchar tiempo[60];
  if(crono->jugador->num_tiros > 0){
    crono->jugador->segundos++;
    if(crono->jugador->segundos==60){
      crono->jugador->minutos++;
      crono->jugador->segundos=0;
      if(crono->jugador->minutos==60){
	crono->jugador->horas++;
	crono->jugador->minutos=0;
      }
    }
    sprintf(tiempo,"Minutos: %d Segundos: %d",crono->jugador->minutos,crono->jugador->segundos);
    gtk_label_set_text(GTK_LABEL(crono->label_time),tiempo);
  }
  return TRUE;
}
/**************************************************************************
 *  @resumen- Este procedimiento se mostrara cuando se accione los botones 
 *  del tablero para de esa forma saber si se esta picando correctamente
 *  o no.
 *
 *  @autores- David Parra y Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
void estado(GtkWidget *widget, gpointer info){
  gtk_statusbar_push(GTK_STATUSBAR(info),gtk_statusbar_get_context_id(GTK_STATUSBAR(info),"boton accionado"),"boton accionado");
}

void estado_1(GtkWidget *widget, gpointer info){
  gtk_statusbar_push(GTK_STATUSBAR(info),gtk_statusbar_get_context_id(GTK_STATUSBAR(info),"Has exedido el numero de elementos de la lista"),"Has exedido el numero de elementos de la lista");
}

void estado_2(GtkWidget *widget, gpointer info){
  gtk_statusbar_push(GTK_STATUSBAR(info),gtk_statusbar_get_context_id(GTK_STATUSBAR(info),"Ya no hay jugadas posteriores"),"Ya no hay jugadas posteriores");
}

/*********************************************************************************
 *  @resumen- Esta funcion nos crea la bandera picandole el click derecho del mouse
 *  esto se hace creando bandera y verificar que numero entra para de esa forma 
 *  asignarle la imagen correspondiente.
 *
 *  @autores- David Parra  
 *  @fecha- 21-mayo-2015
 * 
 *  @param- se le manda el widget para de esa forma ver donde se va a poner la bandera
 ************************************************************************************/
gboolean bandera(GtkWidget *widget,GdkEvent *event, gpointer user_data){
 gchar *mina1;
  gint x,x1;
  GtkWidget *cuadro;
  const gchar *buffer,*buffer1;
  ELEMENTOS *elem = (ELEMENTOS *)user_data;
  mina1=malloc(sizeof(gchar));
  elem->bandera=gtk_image_new_from_file("banderita.png");
  cuadro=gtk_image_new_from_file("cuadro.jpg");
  buffer=gtk_widget_get_name(widget);
  for(x=0;x<81;x++){
    buffer1=gtk_widget_get_name(elem->boton[x]);
    if(strcmp(buffer,buffer1)==0){
      x1=x;
    }
  }
  if(event->button.button==1&&(strcmp(elem->boton1[x1],"0")==0)){
    comparacion(widget,elem);
    estado(widget,elem->barra_estado);
    elem->jugador->num_tiros++;
  }
  else if(event->button.button==3&&(strcmp(elem->boton1[x1],"0")==0)&&elem->contador>0){ //se compara si se pico con el click derecho 
    for(x=0;x<81;x++){
      buffer1=gtk_widget_get_name(elem->boton[x]);
      if(strcmp(buffer,buffer1)==0){
	strcpy(elem->boton1[x],"1");
      }
    }
    elem->contador--; //en caso de que se coloque una bandera se va a restando una
    elem->jugador->num_tiros++;
    sprintf(mina1,"%d",elem->contador);
    gtk_label_set_text(GTK_LABEL(elem->label_mina),mina1);
    gtk_button_set_image(GTK_BUTTON(widget),elem->bandera);
    ganador(widget,elem);
  }
  else if(event->button.button==3&&(strcmp(elem->boton1[x1],"1")==0)){ // si la bandera se pone debe de ser igual a 1
    for(x=0;x<81;x++){
      buffer1=gtk_widget_get_name(elem->boton[x]);
      if(strcmp(buffer,buffer1)==0){
	strcpy(elem->boton1[x],"0");
      }
    }
    elem->contador++;
    elem->jugador->num_tiros++;
    elem->flag=0;
    sprintf(mina1,"%d",elem->contador);
    gtk_label_set_text(GTK_LABEL(elem->label_mina),mina1);
    gtk_button_set_image(GTK_BUTTON(widget),cuadro);
  }
  /*else{
    g_print("No valido\n");
    }*/
  return TRUE;
  }
/**************************************************************************
 *  @resumen- Este procedimiento se checa si hay bombas alrededor para que de esa 
 *  forma se impriman los numeros correspondientes y de otra forma ponerlo 
 *  insensible.Funciona con recursiva para checar que no falte cuardro por abrir
 *
 *  @autores- David Parra y Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
void no_hay_bombas_r(GtkWidget *widget, gpointer info){
  
  //gtk_widget_set_sensitive(widget,FALSE);
  gint y,w,z,u,x,y1,w1,z1,u1;
  const gchar *buffer,*buffer1,*buffer2;
  ELEMENTOS *elem=(ELEMENTOS *)info;
  gchar y2[9],y3[9];
  
  buffer=gtk_widget_get_name(widget);
  buffer2=gtk_widget_get_name(widget);
  gtk_widget_set_sensitive(widget,FALSE);
  sscanf(buffer,"%d-%d-%d-%d",&y,&w,&z,&u);
  y=y+1;
  w=w+1;
  sprintf(y2,"%d-%d-%d-%d",y,w,z,u);
  sscanf(buffer2,"%d-%d-%d-%d",&y1,&w1,&z1,&u1);
  z1=z1+1;
  u1=u1+1;
  sprintf(y3,"%d-%d-%d-%d",y1,w1,z1,u1);

  for(x=0;x<81;x++){
    buffer1=gtk_widget_get_name(elem->boton[x]);
    if(strcmp(buffer1,y2)==0){
      check_r(elem->boton[x],elem);
    }
  }
  for(x=0;x<81;x++){
    buffer1=gtk_widget_get_name(elem->boton[x]);
    if(strcmp(buffer1,y3)==0){
      check_r(elem->boton[x],elem);
    }
  }
}
/**************************************************************************
 *  @resumen- Este procedimiento nos guarda el juego manejando listas 
 *  dinamicas se guarda lo que se encuentre en el tablero y de esa forma
 *  se pueda recuperar el juego ya empezado.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 *  @param- un widget que indico que se realizara la guardada de la partida
 ****************************************************************************/
void guardar_juego_r(GtkWidget *widget, gpointer info){
  const gchar *buffer1;
  gchar *buffer2,*buffer3;
  ELEMENTOS *elementos = (ELEMENTOS *)info;
  DATOS *persona;
  FILE *f1,*f2;
  gint i;
  gpointer info1;
  gtk_widget_set_sensitive(elementos->ventana4,FALSE);
  buffer2=malloc(sizeof(gchar));
  buffer3=malloc(sizeof(gchar));
  buffer1=gtk_entry_get_text(GTK_ENTRY(elementos->textbox1));
  sprintf(buffer2,"%s.bcm",buffer1);
  sprintf(buffer3,"%s1.bcm",buffer1);
  f1=fopen(buffer2,"w");
  f2=fopen(buffer3,"w");
  for(i=0;i<g_slist_length(elementos->lista);i++){
    info1=g_slist_nth_data(elementos->lista,i);
    persona=(DATOS*)info1;
    //fwrite(persona,sizeof(DATOS),1,f1);
    fprintf(f1,"%s\n",persona->coor);
  }
  for(i=0;i<10;i++){
    fprintf(f2,"%s\n",elementos->bombas1[i]);
  }
  fclose(f1);
  fclose(f2);
  gtk_widget_show_all(elementos->ventana6);
}
void seguir_juego_r(GtkWidget *widget, gpointer info){ //creo una ventana para seguir jugando
    ELEMENTOS *elementos = (ELEMENTOS *)info;
    gtk_widget_hide(elementos->ventana6);
    gtk_widget_set_sensitive(elementos->ventana4,TRUE);
}
/**************************************************************************
 *  @resumen- Este procedimiento se checa si hay bombas alrededor para que de
 *  esa forma vaya contando y vaya imprimiendo en el tablero la canridad de
 *  bombas hay si no hay se ira a las funciones no_hay_bomba para comparar lo 
 *  demas
 *
 *  @autores- Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 *  @param- recibe un widget del boton accionado para que de esa forma pueda
 *  realizar la comparacion 
 ****************************************************************************/
void check_r(GtkWidget *widget, gpointer info){
  gint x=0,x1,y,w,z,u;//,t;
  const gchar *buffer;//,*buffer4;
  ELEMENTOS *elem=(ELEMENTOS *)info;
  gchar boton1[9],y1[9],z1[9],w1[9],b1[9],a1[9],c1[9],e1[9],f1[9],y4[9];
  GtkWidget *uno,*dos,*tres,*cuatro,*cinco;
  
  buffer=gtk_widget_get_name(widget);
  strcpy(boton1,buffer);
  sscanf(boton1,"%d-%d-%d-%d",&y,&w,&z,&u);
  y=y-1;
  w=w-1;
  if(w!=-1){
    sprintf(y1,"%d-%d-%d-%d",y,w,z,u);
    for(x1=0;x1<10;x1++){
      if(strcmp(elem->bombas1[x1],y1)==0){
	x++;
      }
    }
  }
  sscanf(y1,"%d-%d-%d-%d",&y,&w,&z,&u);
  z=z-1;
  u=u-1;
  if(u!=-1){
    sprintf(z1,"%d-%d-%d-%d",y,w,z,u);
    for(x1=0;x1<10;x1++){
      if(strcmp(elem->bombas1[x1],z1)==0){
	x++;
      }
    }
  }
  sscanf(y1,"%d-%d-%d-%d",&y,&w,&z,&u);
  z=z+1;
  u=u+1;
  if(u!=10){
    sprintf(w1,"%d-%d-%d-%d",y,w,z,u);
    for(x1=0;x1<10;x1++){
      if(strcmp(elem->bombas1[x1],w1)==0){
	x++;
      }
    }
  }
  sscanf(boton1,"%d-%d-%d-%d",&y,&w,&z,&u);
  z=z-1;	
  u=u-1;
  if(u!=-1){
    sprintf(a1,"%d-%d-%d-%d",y,w,z,u);
    for(x1=0;x1<10;x1++){
      if(strcmp(elem->bombas1[x1],a1)==0){
	x++;
      }
    }
  }
  sscanf(boton1,"%d-%d-%d-%d",&y,&w,&z,&u);
  z=z+1;
  u=u+1;
  if(u!=10){
    sprintf(b1,"%d-%d-%d-%d",y,w,z,u);
    for(x1=0;x1<10;x1++){
      if(strcmp(elem->bombas1[x1],b1)==0){
	x++;
      }
    }
  }
  sscanf(boton1,"%d-%d-%d-%d",&y,&w,&z,&u);
  y=y+1;
  w=w+1;
  if(w!=10){
    sprintf(c1,"%d-%d-%d-%d",y,w,z,u);
    for(x1=0;x1<10;x1++){
      if(strcmp(elem->bombas1[x1],c1)==0){
	x++;
      }
    }      
  }
  sscanf(c1,"%d-%d-%d-%d",&y,&w,&z,&u);
  z=z-1;
  u=u-1;
  if(u!=-1){
    sprintf(e1,"%d-%d-%d-%d",y,w,z,u);
    for(x1=0;x1<10;x1++){
      if(strcmp(elem->bombas1[x1],e1)==0){
	x++;
      }
    } 
  }
  sscanf(c1,"%d-%d-%d-%d",&y,&w,&z,&u);
  z=z+1;
  u=u+1;
  if(u!=10){
    sprintf(f1,"%d-%d-%d-%d",y,w,z,u);
    for(x1=0;x1<10;x1++){
      if(strcmp(elem->bombas1[x1],f1)==0){
	x++;
      }
    }
  }
  if(x==1){
    uno=gtk_image_new_from_file("1.jpg");
    gtk_button_set_image(GTK_BUTTON(widget),uno);
    //gtk_widget_set_sensitive(widget,FALSE);
    elem->x=1;
 }
  if(x==2){
    dos=gtk_image_new_from_file("2.jpg");
    gtk_button_set_image(GTK_BUTTON(widget),dos);
    //gtk_widget_set_sensitive(widget,FALSE);
    elem->x=1;
  }
  if(x==3){
    tres=gtk_image_new_from_file("3.jpg");
    gtk_button_set_image(GTK_BUTTON(widget),tres);
    //gtk_widget_set_sensitive(widget,FALSE);
    elem->x=1;
  }
  if(x==4){
    cuatro=gtk_image_new_from_file("4.jpg");
    gtk_button_set_image(GTK_BUTTON(widget),cuatro);
    //gtk_widget_set_sensitive(widget,FALSE);
    elem->x=1;
  }
  if(x==5){
    cinco=gtk_image_new_from_file("5.jpg");
    gtk_button_set_image(GTK_BUTTON(widget),cinco);
    //gtk_widget_set_sensitive(widget,FALSE);
    elem->x=1;
  }
  if(x==0){
    sscanf(elem->buffer3,"%d-%d-%d-%d",&y,&w,&z,&u);
    sprintf(y4,"%d-%d-%d-%d",y,w,z,u);
   
    no_hay_bombas_r(widget,elem);
    elem->x=1;
  }
} 

/**************************************************************************
 *  @resumen- Este procedimiento se checa si el bontan selecciondo fue bomba 
 *  en caso de que se seleccione se mostraran todas las bombas en el tablero.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 *  @param- un widget del boton accionada para hacer la comparacion
 ****************************************************************************/

void comparacion_r(GtkWidget *widget, gpointer info){
  //gint x,y,w,y1,w1,a=0;
  gint x3=0,x2,x1=0,x,y,w,y1,w1,a=0;
  const gchar *buffer,*buffer1;
  ELEMENTOS *elem=(ELEMENTOS *)info;
  gchar bomba[9], y2[9];
  buffer=gtk_widget_get_name(widget);
  elem->buffer3=gtk_widget_get_name(widget);
  elem->explo=malloc(sizeof(DATOS));
  strcpy(elem->explo->coor,buffer);
  elem->lista=g_slist_append(elem->lista,elem->explo->coor);
  elem->bomba1=gtk_image_new_from_file("bomba.jpg");
  for(x=0;x<10;x++){
      if(strcmp(buffer,elem->bombas1[x])==0){
	a=1;
	  for(x2=0;x2<81;x2++){
	    if(x1<10){
	      strcpy(bomba,elem->bombas1[x1]);
	      sscanf(bomba,"%d-%d-%d-%d",&y,&w,&y1,&w1);
	      sprintf(y2,"%d-%d-%d-%d",y,w,y1,w1);
	      buffer1=gtk_widget_get_name(elem->boton[x2]);
	      if(strcmp(y2,buffer1)==0){
		gtk_button_set_image(GTK_BUTTON(elem->boton[x2]),elem->bomba[x3]);
		x3++;
		x1++;
		gtk_widget_set_sensitive(elem->boton[x2],FALSE);
		x2=-1;
	      }
	    }
	  }
	  g_source_remove(elem->id);
	  gtk_widget_set_sensitive(elem->ventana4,FALSE);
	  gtk_widget_show_all(elem->ventana2);
      }
  }
  if(a==0){
    check_r(widget,elem);
  }
}
/**************************************************************************
 *  @resumen- Esta funcion nos creara unos contadores que al final sera
 *  nuestro timer que se mostrara desde del inicio del juego. Se aumentara cada 
 *  determinado momento.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/

gint incrementa_r(gpointer info){
  ELEMENTOS* crono = (ELEMENTOS*)info;
  gchar tiempo[60];
  if(crono->jugador->num_tiros > 0){
    crono->jugador->segundos++;
    if(crono->jugador->segundos==60){
      crono->jugador->minutos++;
      crono->jugador->segundos=0;
      if(crono->jugador->minutos==60){
	crono->jugador->horas++;
	crono->jugador->minutos=0;
      }
    }
    sprintf(tiempo,"Minutos: %d Segundos: %d",crono->jugador->minutos,crono->jugador->segundos);
    gtk_label_set_text(GTK_LABEL(crono->label_time1),tiempo);
  }
  return TRUE;
}
/*********************************************************************************
 *  @resumen- Esta funcion nos crea la bandera picandole el click derecho del mouse
 *  esto se hace creando bandera y verificar que numero entra para de esa forma 
 *  asignarle la imagen correspondiente.
 *
 *  @autores- David Parra  
 *  @fecha- 21-mayo-2015
 * 
 *  @param- se le manda el widget para de esa forma ver donde se va a poner la bandera
 ************************************************************************************/
gboolean bandera_r(GtkWidget *widget,GdkEvent *event, gpointer user_data){
  gchar *mina1;
  gint x,x1;
  GtkWidget *cuadro;
  const gchar *buffer,*buffer1;
  ELEMENTOS *elem = (ELEMENTOS *)user_data;
  mina1=malloc(sizeof(gchar));
  elem->bandera=gtk_image_new_from_file("banderita.png");
  cuadro=gtk_image_new_from_file("cuadro.jpg");
  buffer=gtk_widget_get_name(widget);
  for(x=0;x<81;x++){
    buffer1=gtk_widget_get_name(elem->boton[x]);
    if(strcmp(buffer,buffer1)==0){
      x1=x;
    }
  }
  if(event->button.button==1&&(strcmp(elem->boton1[x1],"0")==0)){
    comparacion_r(widget,elem);
    estado(widget,elem->barra_estado);
    elem->jugador->num_tiros++;

  }
  else if(event->button.button==3&&(strcmp(elem->boton1[x1],"0")==0)){
    for(x=0;x<81;x++){
      buffer1=gtk_widget_get_name(elem->boton[x]);
      if(strcmp(buffer,buffer1)==0){
	strcpy(elem->boton1[x],"1");
      }
    }
    elem->contador--;
    elem->jugador->num_tiros++;
    sprintf(mina1,"%d",elem->contador);
    gtk_label_set_text(GTK_LABEL(elem->label_mina),mina1);
    gtk_button_set_image(GTK_BUTTON(widget),elem->bandera);
  }
  else if(event->button.button==3&&(strcmp(elem->boton1[x1],"1")==0)){
    for(x=0;x<81;x++){
      buffer1=gtk_widget_get_name(elem->boton[x]);
      if(strcmp(buffer,buffer1)==0){
	strcpy(elem->boton1[x],"0");
      }
    }
    elem->contador++;
    elem->jugador->num_tiros++;
    elem->flag=0;
    sprintf(mina1,"%d",elem->contador);
    gtk_label_set_text(GTK_LABEL(elem->label_mina),mina1);
    gtk_button_set_image(GTK_BUTTON(widget),cuadro);
  }
  /*else{
    g_print("No valido\n");
    }*/
  return TRUE;
  }
/**************************************************************************
 *  @resumen- Este procedimiento nos guarda el juego manejando listas 
 *  dinamicas se guarda lo que se encuentre en el tablero y de esa forma
 *  se pueda recuperar el juego ya empezado.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 *  @param- un widget que indico que se realizara la guardada de la partida
 ****************************************************************************/
void guardar_juego_1(GtkWidget *widget, gpointer info){
  const gchar *buffer1;
  gchar *buffer2,*buffer3;
  ELEMENTOS *elementos = (ELEMENTOS *)info;
  DATOS *persona;
  FILE *f1,*f2;
  gint i;
  gpointer info1;
  gtk_widget_set_sensitive(elementos->ventana4,FALSE);
  buffer2=malloc(sizeof(gchar));
  buffer3=malloc(sizeof(gchar));
  buffer1=gtk_entry_get_text(GTK_ENTRY(elementos->textbox));
  sprintf(buffer2,"%s.bcm",buffer1);
  sprintf(buffer3,"%s1.bcm",buffer1);
  f1=fopen(buffer2,"w+b");
  f2=fopen(buffer3,"w");
  for(i=0;i<g_slist_length(elementos->lista);i++){
    info1=g_slist_nth_data(elementos->lista,i);
    persona=(DATOS*)info1;
    fwrite(persona,sizeof(DATOS),1,f1);
    // fprintf(f1,"%s",persona->coor);
  }
  for(i=0;i<10;i++){
    fprintf(f2,"%s\n",elementos->bombas1[i]);
  }
  fclose(f1);
  fclose(f2);
  gtk_widget_show_all(elementos->ventana6);
  
  Salir(NULL,NULL);
}


void lista_v(GtkWidget *widget, gpointer info){
  ELEMENTOS *elem=(ELEMENTOS *)info;
  FILE *f1,*f2;
  gchar *buffer3,*buffer5,*buffer7;
  gint i=0;
  const gchar *buffer1;
  elem->explo=malloc(sizeof(DATOS));
  buffer3=malloc(sizeof(gchar));
  buffer5=malloc(sizeof(gchar));
  buffer7=malloc(sizeof(gchar));
  buffer1=gtk_entry_get_text(GTK_ENTRY(elem->textbox1));
  sprintf(buffer3,"%s.bcm",buffer1);
  sprintf(buffer5,"%s1.bcm",buffer1);
  sprintf(buffer7,"%s2.bcm",buffer1);
  g_print("%s\n",buffer5);
  g_print("%s\n",buffer3);
  f1=fopen(buffer3,"r");
  f2=fopen(buffer5,"r");
  while(fscanf(f1,"%s",elem->explo->coor)==1){
    elem->lista=g_slist_append(elem->lista,elem->explo->coor);
    elem->explo=malloc(sizeof(DATOS));
  }
  while(fscanf(f2,"%s",elem->bombas[i])==1){
    i++;
  }
  gtk_widget_show_all(elem->ventana1);
  muestra_sig(widget,elem);
}
/**************************************************************************
 *  @resumen- En este procedimiento hacemos las ventanas del juego donde
 *  se ingresara el nombre del gugaor y una etiqueta con el nombre del juego 
 *  y del nombre de los desarrolladores.
 *
 *  @autores- David Parra y Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *  @param- elementos un puntero de toda la estructura creada al princippio del
 *  programa
 *
 ****************************************************************************/
void principal(ELEMENTOS *elementos){
  GtkWidget *caja, *etiqueta,*etiqueta1,*etiqueta2, *nuevo, *recuperar, *salir,*tabla;

  //creacion de los elementos(widgets)
  elementos->ventana=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  caja=gtk_vbox_new(FALSE,0.5);
  tabla=gtk_table_new(5,4,FALSE);
  elementos->textbox=gtk_entry_new();
  elementos->textbox1=gtk_entry_new();
  etiqueta=gtk_label_new("Bienvenido a este juego llamado BUSCAMINAS\n Desarrollado por:\n -David Eduardo Parra Mercado --192098-8\n -Daniela Requejo Fernandez --190765-9\n");
  etiqueta1=gtk_label_new("Ingrese su nombre: ");
  etiqueta2=gtk_label_new("Ingrese su nombre: ");
  nuevo=gtk_button_new_with_label("Juego Nuevo");
  recuperar=gtk_button_new_with_label("Recuperar Juego");
  salir=gtk_button_new_with_label("Salir");
  gtk_widget_set_usize(elementos->ventana,400,300);
  gtk_window_set_title(GTK_WINDOW(elementos->ventana),"Buscaminas");
  g_signal_connect(G_OBJECT(nuevo),"clicked",G_CALLBACK(nuevo_juego),elementos);
  g_signal_connect(G_OBJECT(recuperar),"clicked",G_CALLBACK(lista_v),elementos);
  g_signal_connect(G_OBJECT(salir),"clicked",G_CALLBACK(Salir),NULL);
  g_signal_connect(G_OBJECT(elementos->ventana),"delete_event",G_CALLBACK(delete_event_handler),NULL);
  g_signal_connect(G_OBJECT(elementos->ventana),"destroy",G_CALLBACK(Salir),NULL);
  gtk_table_attach_defaults(GTK_TABLE(tabla),etiqueta1,0,2,0,1);
  gtk_table_attach_defaults(GTK_TABLE(tabla),elementos->textbox,0,2,1,2);
  gtk_table_attach_defaults(GTK_TABLE(tabla),nuevo,2,4,0,2);
  gtk_table_attach_defaults(GTK_TABLE(tabla),etiqueta2,0,2,2,3);
  gtk_table_attach_defaults(GTK_TABLE(tabla),elementos->textbox1,0,2,3,4);
  gtk_table_attach_defaults(GTK_TABLE(tabla),recuperar,2,4,2,4);
  gtk_table_attach_defaults(GTK_TABLE(tabla),salir,0,4,4,5);
  gtk_box_pack_start_defaults(GTK_BOX(caja),etiqueta);
  gtk_box_pack_start_defaults(GTK_BOX(caja),tabla);
  gtk_container_add(GTK_CONTAINER(elementos->ventana),caja);

}
/**************************************************************************
 *  @resumen- Este procedimiento se crea la ventana principal del juego 
 *  con el tablero y sus correspondientes labels y menus.
 *
 *  @autores- David Parra y Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 *  @param- elementos un puntero de toda la estructura creada al principio del
 *  programa
 ****************************************************************************/
void juego(ELEMENTOS *elementos){
  GtkWidget *caja1,*image[81],*juego,*nuevo1,*recuperar1,*terminar,*herramientas,*deshacer,*rehacer,*etiqueta_minas,*etiqueta_tiempo,*menu,*menu1,*menu_bar,*top,*guardar,*contenedor3,*acerca_de,*iguardar,*inuevo,*atras,*adelante,*contenedor1,*info, *info_des,*info_des1,*menu2;
  GtkTooltips *nuevos,*guardars,*atrass,*adelantess,*infos;
  gint x,y,w;
  gchar nombres[81][9]={"0-1-0-1","0-1-1-2","0-1-2-3","0-1-3-4","0-1-4-5","0-1-5-6","0-1-6-7","0-1-7-8","0-1-8-9","1-2-0-1","1-2-1-2","1-2-2-3","1-2-3-4","1-2-4-5","1-2-5-6","1-2-6-7","1-2-7-8","1-2-8-9","2-3-0-1","2-3-1-2","2-3-2-3","2-3-3-4","2-3-4-5","2-3-5-6","2-3-6-7","2-3-7-8","2-3-8-9","3-4-0-1","3-4-1-2","3-4-2-3","3-4-3-4","3-4-4-5","3-4-5-6","3-4-6-7","3-4-7-8","3-4-8-9","4-5-0-1","4-5-1-2","4-5-2-3","4-5-3-4","4-5-4-5","4-5-5-6","4-5-6-7","4-5-7-8","4-5-8-9","5-6-0-1","5-6-1-2","5-6-2-3","5-6-3-4","5-6-4-5","5-6-5-6","5-6-6-7","5-6-7-8","5-6-8-9","6-7-0-1","6-7-1-2","6-7-2-3","6-7-3-4","6-7-4-5","6-7-5-6","6-7-6-7","6-7-7-8","6-7-8-9","7-8-0-1","7-8-1-2","7-8-2-3","7-8-3-4","7-8-4-5","7-8-5-6","7-8-6-7","7-8-7-8","7-8-8-9","8-9-0-1","8-9-1-2","8-9-2-3","8-9-3-4","8-9-4-5","8-9-5-6","8-9-6-7","8-9-7-8","8-9-8-9"};
  elementos->ventana1=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  caja1=gtk_vbox_new(FALSE,0);
  gtk_widget_set_usize(elementos->ventana1,500,600);
  contenedor3=gtk_hbox_new(FALSE,0);
  contenedor1=gtk_hbox_new(FALSE,0);
  // elementos->label=gtk_label_new(NULL);
  elementos->accel_group=gtk_accel_group_new();
  elementos->label_time=gtk_label_new(NULL);
  elementos->id = gtk_timeout_add(1000,(GSourceFunc)incrementa,(gpointer)elementos);
  elementos->barra_estado=gtk_statusbar_new();
  gtk_window_set_title(GTK_WINDOW(elementos->ventana1),"BUSCAMINAS");
  menu=gtk_menu_new();
  menu_bar=gtk_menu_bar_new();
  nuevos=gtk_tooltips_new();
  guardars=gtk_tooltips_new();
  atrass=gtk_tooltips_new();
  adelantess=gtk_tooltips_new();
  infos=gtk_tooltips_new();
  //BARRA DE MENU : JUEGO
  juego=gtk_menu_item_new_with_label("Juego");
  nuevo1=gtk_menu_item_new_with_label("Nuevo");
  guardar=gtk_menu_item_new_with_label("Guardar");
  recuperar1=gtk_menu_item_new_with_label("Recuperar");
  terminar=gtk_menu_item_new_with_label("Terminar");
  top=gtk_menu_item_new_with_label("Ranking");
  menu1=gtk_menu_new();
  //BARRA DE MENU: HERRAMIENTAS
  herramientas=gtk_menu_item_new_with_label("Herramientas");
  deshacer=gtk_menu_item_new_with_label("Deshacer");
  rehacer=gtk_menu_item_new_with_label("Rehacer");
  menu2=gtk_menu_new();
  acerca_de=gtk_menu_item_new_with_label("Acerca de...");
  info_des=gtk_menu_item_new_with_label("David Parra Mercado 192098-8");
  info_des1=gtk_menu_item_new_with_label("Daniela Requejo Fdz 190765-9"); 
  etiqueta_minas=gtk_label_new("MINAS");
  elementos->label_mina=gtk_label_new(NULL);
  etiqueta_tiempo=gtk_label_new("TIEMPO");
  elementos->tabla1=gtk_table_new(9,9,FALSE);
  inuevo=gtk_image_new_from_file("nuevo.png");
  iguardar=gtk_image_new_from_file("guardar.png");
  adelante=gtk_image_new_from_file("adelante.png");
  atras=gtk_image_new_from_file("atras.png");
  info=gtk_image_new_from_file("info.png");
  for(x=0;x<5;x++){  //craecion de los 81 botones
    elementos->herramientas[x]=gtk_button_new();
  }
  for(x=0;x<81;x++){
    elementos->boton[x]=gtk_button_new();
  }
  for(x=0;x<81;x++){
    gtk_widget_set_name(elementos->boton[x],nombres[x]);
  }
  for(x=0;x<81;x++){
    image[x]=gtk_image_new_from_file("cuadro.jpg");
  }
  for(x=0;x<81;x++){
    gtk_button_set_image(GTK_BUTTON(elementos->boton[x]),image[x]);
  }
  //cracion de la ventana del juego, en orden
  gtk_tooltips_set_tip(nuevos,elementos->herramientas[0],"Nueva Partida",NULL);
  gtk_tooltips_set_tip(guardars,elementos->herramientas[1],"Guardar Partida",NULL);
  gtk_tooltips_set_tip(atrass,elementos->herramientas[2],"Tiro Anterior",NULL);
  gtk_tooltips_set_tip(adelantess,elementos->herramientas[3],"Tiro Posterior",NULL);
  gtk_tooltips_set_tip(infos,elementos->herramientas[4],"Ayuda",NULL);
  gtk_button_set_image(GTK_BUTTON(elementos->herramientas[0]),inuevo); 
  gtk_button_set_image(GTK_BUTTON(elementos->herramientas[1]),iguardar); 
  gtk_button_set_image(GTK_BUTTON(elementos->herramientas[2]),atras);
  gtk_button_set_image(GTK_BUTTON(elementos->herramientas[3]),adelante);
  gtk_button_set_image(GTK_BUTTON(elementos->herramientas[4]),info);
  gtk_widget_add_accelerator(nuevo1,"activate",elementos->accel_group,'n',GDK_CONTROL_MASK,GTK_ACCEL_VISIBLE);
gtk_widget_add_accelerator(guardar,"activate",elementos->accel_group,'g',GDK_CONTROL_MASK,GTK_ACCEL_VISIBLE);
gtk_widget_add_accelerator(recuperar1,"activate",elementos->accel_group,'r',GDK_CONTROL_MASK,GTK_ACCEL_VISIBLE);
gtk_widget_add_accelerator(terminar,"activate",elementos->accel_group,'t',GDK_CONTROL_MASK,GTK_ACCEL_VISIBLE);
gtk_widget_add_accelerator(deshacer,"activate",elementos->accel_group,'a',GDK_CONTROL_MASK,GTK_ACCEL_VISIBLE);
gtk_widget_add_accelerator(rehacer,"activate",elementos->accel_group,'p',GDK_CONTROL_MASK,GTK_ACCEL_VISIBLE);
 gtk_widget_add_accelerator(top,"activate",elementos->accel_group,'m',GDK_CONTROL_MASK,GTK_ACCEL_VISIBLE);
  for(x=0;x<81;x++){
    //hacer los signal connect de los respectivos botones
     g_signal_connect(G_OBJECT(elementos->boton[x]),"button-press-event",G_CALLBACK(bandera),elementos);
  }
g_signal_connect(G_OBJECT(elementos->ventana1),"delete_event",G_CALLBACK(delete_event_handler),NULL);
  g_signal_connect(G_OBJECT(elementos->ventana1),"destroy",G_CALLBACK(Salir),NULL);
  g_signal_connect(G_OBJECT(nuevo1),"activate",G_CALLBACK(nuevo_juego1),elementos);
  g_signal_connect(G_OBJECT(guardar),"activate",G_CALLBACK(guardar_juego),elementos);
  g_signal_connect(G_OBJECT(top),"activate",G_CALLBACK(mostrar_top),elementos);
  g_signal_connect(G_OBJECT(guardar),"activate",G_CALLBACK(com_guardar),elementos);
  g_signal_connect(G_OBJECT(recuperar1),"activate",G_CALLBACK(mostrar_recupera),elementos);
  g_signal_connect(G_OBJECT(elementos->herramientas[0]),"clicked",G_CALLBACK(nuevo_juego1),elementos);
  g_signal_connect(G_OBJECT(elementos->herramientas[1]),"clicked",G_CALLBACK(com_guardar),elementos);
  g_signal_connect(G_OBJECT(elementos->herramientas[2]),"clicked",G_CALLBACK(atras_1),elementos);
  g_signal_connect(G_OBJECT(elementos->herramientas[3]),"clicked",G_CALLBACK(adelante_1),elementos);

  g_signal_connect(G_OBJECT(elementos->herramientas[4]),"clicked",G_CALLBACK(ayuda),elementos);
  g_signal_connect(G_OBJECT(terminar),"activate",G_CALLBACK(com_guardar),elementos);
g_signal_connect(G_OBJECT(deshacer),"activate",G_CALLBACK(atras_1),elementos);
g_signal_connect(G_OBJECT(rehacer),"activate",G_CALLBACK(adelante_1),elementos);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu),nuevo1);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu),guardar);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu),recuperar1);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu),terminar);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu1),deshacer);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu1),rehacer);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu1),top);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu2),info_des);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu2),info_des1);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(juego),menu);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(herramientas),menu1);
   gtk_menu_item_set_submenu(GTK_MENU_ITEM(acerca_de),menu2);
  gtk_menu_bar_append(GTK_MENU_BAR(menu_bar),juego);
  gtk_menu_bar_append(GTK_MENU_BAR(menu_bar),herramientas);
  gtk_menu_bar_append(GTK_MENU_BAR(menu_bar),acerca_de);
  for(x=0,w=0,y=1;x<9;x++,y++,w++){  //asignar cada boton a la tabla
    gtk_table_attach_defaults(GTK_TABLE(elementos->tabla1),elementos->boton[x],0,1,w,y);
  }
  for(x=9,w=0,y=1;x<18;x++,y++,w++){
    gtk_table_attach_defaults(GTK_TABLE(elementos->tabla1),elementos->boton[x],1,2,w,y);
  }
  for(x=18,w=0,y=1;x<27;x++,y++,w++){
    gtk_table_attach_defaults(GTK_TABLE(elementos->tabla1),elementos->boton[x],2,3,w,y);
  }
  for(x=27,w=0,y=1;x<36;x++,y++,w++){
    gtk_table_attach_defaults(GTK_TABLE(elementos->tabla1),elementos->boton[x],3,4,w,y);
  }
  for(x=36,w=0,y=1;x<45;x++,y++,w++){
    gtk_table_attach_defaults(GTK_TABLE(elementos->tabla1),elementos->boton[x],4,5,w,y);
  }
  for(x=45,w=0,y=1;x<54;x++,y++,w++){
    gtk_table_attach_defaults(GTK_TABLE(elementos->tabla1),elementos->boton[x],5,6,w,y);
  }
  for(x=54,w=0,y=1;x<63;x++,y++,w++){
    gtk_table_attach_defaults(GTK_TABLE(elementos->tabla1),elementos->boton[x],6,7,w,y);
  }
  for(x=63,w=0,y=1;x<72;x++,y++,w++){
    gtk_table_attach_defaults(GTK_TABLE(elementos->tabla1),elementos->boton[x],7,8,w,y);
  }
  for(x=72,w=0,y=1;x<81;x++,y++,w++){
    gtk_table_attach_defaults(GTK_TABLE(elementos->tabla1),elementos->boton[x],8,9,w,y);
  }
  for(x=0;x<5;x++){
    gtk_box_pack_start_defaults(GTK_BOX(contenedor1),elementos->herramientas[x]);  
  }
  gtk_box_pack_start_defaults(GTK_BOX(contenedor3),etiqueta_minas);
  gtk_box_pack_start_defaults(GTK_BOX(contenedor3),elementos->label_mina);
  gtk_box_pack_start_defaults(GTK_BOX(contenedor3),etiqueta_tiempo);
  gtk_box_pack_start_defaults(GTK_BOX(contenedor3),elementos->label_time);
  gtk_box_pack_start_defaults(GTK_BOX(caja1),menu_bar);
  gtk_box_pack_start_defaults(GTK_BOX(caja1),contenedor1);
  //gtk_box_pack_start_defaults(GTK_BOX(caja1),elementos->label);
  gtk_box_pack_start_defaults(GTK_BOX(caja1),contenedor3);
  gtk_box_pack_start_defaults(GTK_BOX(caja1),elementos->tabla1);
  gtk_box_pack_start_defaults(GTK_BOX(caja1),elementos->barra_estado);
  gtk_container_add(GTK_CONTAINER(elementos->ventana1),caja1);
  gtk_window_add_accel_group(GTK_WINDOW(elementos->ventana1),elementos->accel_group);


}
/**************************************************************************
 *  @resumen- Este procedimiento se crea la ventana principal en caso de que recupera
 *  el juego, con el tablero y sus correspondientes labels y menus.
 *
 *  @autores- David Parra y Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 *  @param- elementos un puntero de toda la estructura creada al principio del
 *  programa
 ****************************************************************************/

void juego_r(ELEMENTOS *elementos){
  GtkWidget *caja1,*image[81],*juego,*nuevo1,*recuperar1,*terminar,*herramientas,*deshacer,*rehacer,*etiqueta_minas,*etiqueta_tiempo,*menu,*menu1,*menu_bar,*guardar,*contenedor3,*acerca_de,*iguardar,*inuevo,*atras,*adelante,*contenedor1,*info;
  GtkTooltips *nuevos,*guardars,*atrass,*adelantess,*infos;
  gint x,y,w;
  gchar nombres[81][9]={"0-1-0-1","0-1-1-2","0-1-2-3","0-1-3-4","0-1-4-5","0-1-5-6","0-1-6-7","0-1-7-8","0-1-8-9","1-2-0-1","1-2-1-2","1-2-2-3","1-2-3-4","1-2-4-5","1-2-5-6","1-2-6-7","1-2-7-8","1-2-8-9","2-3-0-1","2-3-1-2","2-3-2-3","2-3-3-4","2-3-4-5","2-3-5-6","2-3-6-7","2-3-7-8","2-3-8-9","3-4-0-1","3-4-1-2","3-4-2-3","3-4-3-4","3-4-4-5","3-4-5-6","3-4-6-7","3-4-7-8","3-4-8-9","4-5-0-1","4-5-1-2","4-5-2-3","4-5-3-4","4-5-4-5","4-5-5-6","4-5-6-7","4-5-7-8","4-5-8-9","5-6-0-1","5-6-1-2","5-6-2-3","5-6-3-4","5-6-4-5","5-6-5-6","5-6-6-7","5-6-7-8","5-6-8-9","6-7-0-1","6-7-1-2","6-7-2-3","6-7-3-4","6-7-4-5","6-7-5-6","6-7-6-7","6-7-7-8","6-7-8-9","7-8-0-1","7-8-1-2","7-8-2-3","7-8-3-4","7-8-4-5","7-8-5-6","7-8-6-7","7-8-7-8","7-8-8-9","8-9-0-1","8-9-1-2","8-9-2-3","8-9-3-4","8-9-4-5","8-9-5-6","8-9-6-7","8-9-7-8","8-9-8-9"};
  elementos->ventana4=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  caja1=gtk_vbox_new(FALSE,0);
  gtk_widget_set_usize(elementos->ventana4,500,600);
  contenedor3=gtk_hbox_new(FALSE,0);
  contenedor1=gtk_hbox_new(FALSE,0);
  elementos->label1=gtk_label_new(NULL);
  elementos->label_time1=gtk_label_new(NULL);
  elementos->id1 = gtk_timeout_add(1000,(GSourceFunc)incrementa_r,(gpointer)elementos);
  elementos->barra_estado1=gtk_statusbar_new();
  gtk_window_set_title(GTK_WINDOW(elementos->ventana4),"BUSCAMINAS");
  menu=gtk_menu_new();
  menu_bar=gtk_menu_bar_new();
  nuevos=gtk_tooltips_new();
  guardars=gtk_tooltips_new();
  atrass=gtk_tooltips_new();
  adelantess=gtk_tooltips_new();
  infos=gtk_tooltips_new();
  juego=gtk_menu_item_new_with_label("Juego");
  nuevo1=gtk_menu_item_new_with_label("Nuevo");
  guardar=gtk_menu_item_new_with_label("Guardar");
  recuperar1=gtk_menu_item_new_with_label("Recuperar");
  terminar=gtk_menu_item_new_with_label("Terminar");
  menu1=gtk_menu_new();
  herramientas=gtk_menu_item_new_with_label("Herramientas");
  deshacer=gtk_menu_item_new_with_label("Deshacer");
  rehacer=gtk_menu_item_new_with_label("Rehacer");
  acerca_de=gtk_menu_item_new_with_label("Acerca de...");
  etiqueta_minas=gtk_label_new("MINAS");
  elementos->label_mina1=gtk_label_new(NULL);
  etiqueta_tiempo=gtk_label_new("TIEMPO");
  elementos->tabla1=gtk_table_new(9,9,FALSE);
  inuevo=gtk_image_new_from_file("nuevo.png");
  iguardar=gtk_image_new_from_file("guardar.png");
  adelante=gtk_image_new_from_file("adelante.png");
  atras=gtk_image_new_from_file("atras.png");
  info=gtk_image_new_from_file("info.png");
  for(x=0;x<5;x++){
    elementos->herramientas[x]=gtk_button_new();
  }
  for(x=0;x<81;x++){
    elementos->boton[x]=gtk_button_new();
  }
  for(x=0;x<81;x++){
    gtk_widget_set_name(elementos->boton[x],nombres[x]);
  }
  for(x=0;x<81;x++){
    image[x]=gtk_image_new_from_file("cuadro.jpg");
  }
  for(x=0;x<81;x++){
    gtk_button_set_image(GTK_BUTTON(elementos->boton[x]),image[x]);
  }
  gtk_tooltips_set_tip(nuevos,elementos->herramientas[0],"Nueva Partida",NULL);
  gtk_tooltips_set_tip(guardars,elementos->herramientas[1],"Guardar Partida",NULL);
  gtk_tooltips_set_tip(atrass,elementos->herramientas[2],"Tiro Anterior",NULL);
  gtk_tooltips_set_tip(adelantess,elementos->herramientas[3],"Tiro Posterior",NULL);
  gtk_tooltips_set_tip(infos,elementos->herramientas[4],"Ayuda",NULL);
  gtk_button_set_image(GTK_BUTTON(elementos->herramientas[0]),inuevo); 
  gtk_button_set_image(GTK_BUTTON(elementos->herramientas[1]),iguardar); 
  gtk_button_set_image(GTK_BUTTON(elementos->herramientas[2]),atras);
  gtk_button_set_image(GTK_BUTTON(elementos->herramientas[3]),adelante);
  gtk_button_set_image(GTK_BUTTON(elementos->herramientas[4]),info);
  for(x=0;x<81;x++){
     g_signal_connect(G_OBJECT(elementos->boton[x]),"button-press-event",G_CALLBACK(bandera_r),elementos);
  }
g_signal_connect(G_OBJECT(elementos->ventana4),"delete_event",G_CALLBACK(delete_event_handler),NULL);
  g_signal_connect(G_OBJECT(elementos->ventana4),"destroy",G_CALLBACK(Salir),NULL);
  g_signal_connect(G_OBJECT(nuevo1),"activate",G_CALLBACK(nuevo_juego1),elementos);
  g_signal_connect(G_OBJECT(guardar),"activate",G_CALLBACK(guardar_juego),elementos);
  g_signal_connect(G_OBJECT(elementos->herramientas[0]),"clicked",G_CALLBACK(nuevo_juego1),elementos);
  g_signal_connect(G_OBJECT(elementos->herramientas[1]),"clicked",G_CALLBACK(guardar_juego_r),elementos);
 g_signal_connect(G_OBJECT(elementos->herramientas[2]),"clicked",G_CALLBACK(atras_1),elementos);
  g_signal_connect(G_OBJECT(elementos->herramientas[3]),"clicked",G_CALLBACK(adelante_1),elementos);
 g_signal_connect(G_OBJECT(elementos->herramientas[4]),"clicked",G_CALLBACK(ayuda),elementos);
  g_signal_connect(G_OBJECT(terminar),"activate",G_CALLBACK(terminar_1),elementos);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu),nuevo1);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu),guardar);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu),recuperar1);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu),terminar);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu1),deshacer);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu1),rehacer);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(juego),menu);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(herramientas),menu1);
  gtk_menu_bar_append(GTK_MENU_BAR(menu_bar),juego);
  gtk_menu_bar_append(GTK_MENU_BAR(menu_bar),herramientas);
  gtk_menu_bar_append(GTK_MENU_BAR(menu_bar),acerca_de);
  for(x=0,w=0,y=1;x<9;x++,y++,w++){
    gtk_table_attach_defaults(GTK_TABLE(elementos->tabla1),elementos->boton[x],0,1,w,y);
  }
  for(x=9,w=0,y=1;x<18;x++,y++,w++){
    gtk_table_attach_defaults(GTK_TABLE(elementos->tabla1),elementos->boton[x],1,2,w,y);
  }
  for(x=18,w=0,y=1;x<27;x++,y++,w++){
    gtk_table_attach_defaults(GTK_TABLE(elementos->tabla1),elementos->boton[x],2,3,w,y);
  }
  for(x=27,w=0,y=1;x<36;x++,y++,w++){
    gtk_table_attach_defaults(GTK_TABLE(elementos->tabla1),elementos->boton[x],3,4,w,y);
  }
  for(x=36,w=0,y=1;x<45;x++,y++,w++){
    gtk_table_attach_defaults(GTK_TABLE(elementos->tabla1),elementos->boton[x],4,5,w,y);
  }
  for(x=45,w=0,y=1;x<54;x++,y++,w++){
    gtk_table_attach_defaults(GTK_TABLE(elementos->tabla1),elementos->boton[x],5,6,w,y);
  }
  for(x=54,w=0,y=1;x<63;x++,y++,w++){
    gtk_table_attach_defaults(GTK_TABLE(elementos->tabla1),elementos->boton[x],6,7,w,y);
  }
  for(x=63,w=0,y=1;x<72;x++,y++,w++){
    gtk_table_attach_defaults(GTK_TABLE(elementos->tabla1),elementos->boton[x],7,8,w,y);
  }
  for(x=72,w=0,y=1;x<81;x++,y++,w++){
    gtk_table_attach_defaults(GTK_TABLE(elementos->tabla1),elementos->boton[x],8,9,w,y);
  }
  for(x=0;x<5;x++){
    gtk_box_pack_start_defaults(GTK_BOX(contenedor1),elementos->herramientas[x]);  
  }
  gtk_box_pack_start_defaults(GTK_BOX(contenedor3),etiqueta_minas);
  gtk_box_pack_start_defaults(GTK_BOX(contenedor3),elementos->label_mina1);
  gtk_box_pack_start_defaults(GTK_BOX(contenedor3),etiqueta_tiempo);
  gtk_box_pack_start_defaults(GTK_BOX(contenedor3),elementos->label_time1);
  gtk_box_pack_start_defaults(GTK_BOX(caja1),menu_bar);
  gtk_box_pack_start_defaults(GTK_BOX(caja1),contenedor1);
  gtk_box_pack_start_defaults(GTK_BOX(caja1),elementos->label1);
  gtk_box_pack_start_defaults(GTK_BOX(caja1),contenedor3);
  gtk_box_pack_start_defaults(GTK_BOX(caja1),elementos->tabla1);
  gtk_box_pack_start_defaults(GTK_BOX(caja1),elementos->barra_estado1);
  gtk_container_add(GTK_CONTAINER(elementos->ventana4),caja1);


}

/**************************************************************************
 *  @resumen- Este procedimiento se crea la ventanauna vez que el jugador pierde.
 *  Preguntandole si quiere volver a jugar.
 *
 *  @autores- Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 *  @param- elementos un puntero de toda la estructura creada al principio del
 *  programa
 ****************************************************************************/
void perdida(ELEMENTOS *elementos){
  GtkWidget *perdiste,*nuevo2,*cancelar,*vent,*caja4;
  elementos->ventana2=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_usize(elementos->ventana2,100,100);
  gtk_window_set_title(GTK_WINDOW(elementos->ventana2),"Buscaminas");
  perdiste=gtk_label_new("Has perdido!!!! \nDeseas volver a jugar?");
  nuevo2=gtk_button_new_with_label("Juego Nuevo");
  cancelar=gtk_button_new_with_label("Salir");
  caja4=gtk_vbox_new(FALSE,0);
  vent=gtk_hbox_new(FALSE,0);
  //asignacion de las funciones a los botones
  g_signal_connect(G_OBJECT(cancelar),"clicked",G_CALLBACK(Salir),elementos);
  g_signal_connect(G_OBJECT(nuevo2),"clicked",G_CALLBACK(nuevo_juego1),elementos);
  //acomodar los elementos en orden
  gtk_box_pack_start_defaults(GTK_BOX(vent),nuevo2);
  gtk_box_pack_start_defaults(GTK_BOX(vent),cancelar);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),perdiste);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),vent);
  gtk_container_add(GTK_CONTAINER(elementos->ventana2),caja4);

}
/**************************************************************************
 *  @resumen- Este procedimiento se crea la ventana para preguntar si se
 *  desea guardar la partida.
 *
 *  @autores- Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 *  @param- elementos un puntero de toda la estructura creada al principio del
 *  programa
 ****************************************************************************/
void guardada(ELEMENTOS *elementos){
  GtkWidget *guardar,*si,*no,*caja5,*vent;
  elementos->ventana3=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_usize(elementos->ventana3,300,100);
  gtk_window_set_title(GTK_WINDOW(elementos->ventana3),"Buscaminas");
  guardar=gtk_label_new("Deseas seguir jugando??");
  si=gtk_button_new_with_label("SI!!");
  no=gtk_button_new_with_label("NO!!");
  caja5=gtk_vbox_new(FALSE,0);
  vent=gtk_hbox_new(FALSE,0);
  g_signal_connect(G_OBJECT(no),"clicked",G_CALLBACK(Salir),elementos);
  g_signal_connect(G_OBJECT(si),"clicked",G_CALLBACK(seguir_juego),elementos);
  gtk_box_pack_start_defaults(GTK_BOX(vent),si);
  gtk_box_pack_start_defaults(GTK_BOX(vent),no);
  gtk_box_pack_start_defaults(GTK_BOX(caja5),guardar);
  gtk_box_pack_start_defaults(GTK_BOX(caja5),vent);
  gtk_container_add(GTK_CONTAINER(elementos->ventana3),caja5);
}
/**************************************************************************
 *  @resumen- Este procedimiento se crea la ventana de ayuda en caso de que 
 *  el jugador la llegara a necesitar
 *
 *  @autores- Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 *  @param- elementos un puntero de toda la estructura creada al principio del
 *  programa
 ****************************************************************************/
void ventana_ayuda(ELEMENTOS *elementos){

  GtkWidget *caja1,*etiqueta,*etiqueta1,*scrollbar,*contenedor,*imagen,*imagen1,*imagen2,*imagen3,*imagen4;
 
  elementos->ventana5=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_usize(elementos->ventana5,900,600);
  caja1=gtk_vbox_new(FALSE,0.5);
 
  //creacion de un scrollbar para mover la ventana
  scrollbar=gtk_scrolled_window_new(NULL,NULL);
  gtk_widget_set_usize(scrollbar,200,100);
  gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrollbar),caja1);

 
  etiqueta=gtk_label_new("Bienvenido a la ayuda del BUSCAMINAS!! \n Al inicio del juego se abrirá una pantalla inicial donde se \n podrán observar los nombres de los creadores del juego, cuadros de texto para iniciar \ncon el juego ya que esta aplicación necesitará del nombre del jugador para poder iniciar \ncon el juego. Habiendo puesto el nombre se podrá oprimir el botón de acuerdo a lo que desea \nhacer, ya sea jugar un nuevo juego o recuperar uno hecho antes. Después aparecerá una nueva \npantalla donde ya se podrá interactuar con el juego. \n Dentro de la pantalla se tendrá tres \nopciones de menú, siendo:"); 
  etiqueta1=gtk_label_new("1. Juego \n 2. Herramientas \n 3. Acerca de (informacion de los desarroladores)\n Dentro del menú juego habrá varias opciones:\n  1.	Nuevo: en esta opción podrá empezar desde cero el juego.\n 2.	Guardar: en esta opción podrá guarda r el juego tal como lo dejo\n3.	Recuperar: en esta opción podrá recuperar el juego guardado anteriormente.\n4.	Terminar: en esta opción se podrá salir del juego.\n\n Dentro del menú Herramientas habrá varias opciones: \n 1.Deshacer: en esta opción podrá regresar a la jugada anterior que hizo.\n 2.Rehacer: en esta opción podrá regresar la jugada que quitó para continuar con su juego tal cual lo ha hecho.\n\n Dentro del menú Acerca de, podrá oprimirlo y se mostrará el nombre de los creadores de esta aplicación.\n\n Por otra parte, se tiene una barra de herramientas donde se tienen cuatro botones:\n1.	Nuevo: Iniciar desde cero el juego\n2.Guardar: Guardar el progreso del juego para así poder continuar con el después\n3.Atrás (flecha): Este botón servirá para deshacer una jugada\n4.Adelante (flecha): Este botón servirá para rehacer alguna jugada que haya quitado.");

  contenedor=gtk_hbox_new(FALSE,0);
  imagen=gtk_image_new_from_file("imagen1.png");
  imagen1=gtk_image_new_from_file("imagen2.png");
  imagen2=gtk_image_new_from_file("imagen3.png");
  imagen3=gtk_image_new_from_file("imagen4.png");
  imagen4=gtk_image_new_from_file("imagen5.png");
 
  //acomodar la ventana
  gtk_box_pack_start_defaults(GTK_BOX(caja1),etiqueta);
  gtk_box_pack_start_defaults(GTK_BOX(caja1),etiqueta1);
  gtk_box_pack_start_defaults(GTK_BOX(caja1),imagen);
  gtk_box_pack_start_defaults(GTK_BOX(caja1),imagen1);
  gtk_box_pack_start_defaults(GTK_BOX(caja1),imagen2);
  gtk_box_pack_start_defaults(GTK_BOX(caja1),imagen3);
  gtk_box_pack_start_defaults(GTK_BOX(caja1),imagen4);
  gtk_box_pack_start_defaults(GTK_BOX(contenedor),caja1);
  gtk_box_pack_start(GTK_BOX(contenedor),scrollbar,TRUE,TRUE,0);
  gtk_container_add(GTK_CONTAINER(elementos->ventana5),contenedor);
  
}
/**************************************************************************
 *  @resumen- Este procedimiento se crea la ventana de ayuda.
 *
 *  @autores- Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
void ayuda(GtkWidget *widget, gpointer info){
  ELEMENTOS *elementos = (ELEMENTOS *)info;
  gtk_widget_show_all(elementos->ventana5);
}
/**************************************************************************
 *  @resumen- Este procedimiento se crea la ventana en caso de que se haya 
 *  seleccionado la opciondel menu terminar para ver si se guarda la jugada o no.
 *
 *  @autores- Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 *  @param- elementos un puntero de toda la estructura creada al principio del
 *  programa
 ****************************************************************************/
void terminar_guardar(ELEMENTOS *elementos){

 GtkWidget *guardar,*si,*no,*caja6,*vent;

  elementos->ventana7=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_usize(elementos->ventana7,300,100);
  gtk_window_set_title(GTK_WINDOW(elementos->ventana7),"Buscaminas");
  guardar=gtk_label_new("Deseas guardar tu juego??");
  si=gtk_button_new_with_label("SI!!");
  no=gtk_button_new_with_label("NO!!");
  caja6=gtk_vbox_new(FALSE,0);
  vent=gtk_hbox_new(FALSE,0);
  g_signal_connect(G_OBJECT(no),"clicked",G_CALLBACK(Salir),elementos);
  g_signal_connect(G_OBJECT(si),"clicked",G_CALLBACK(guardar_juego_1),elementos);
  gtk_box_pack_start_defaults(GTK_BOX(vent),si);
  gtk_box_pack_start_defaults(GTK_BOX(vent),no);
  gtk_box_pack_start_defaults(GTK_BOX(caja6),guardar);
  gtk_box_pack_start_defaults(GTK_BOX(caja6),vent);
  gtk_container_add(GTK_CONTAINER(elementos->ventana7),caja6);
}
/**************************************************************************
 *  @resumen- Este procedimiento se crea la ventana terminar_guaradar
 *  @autores- Daniela Requejo 
 *  @fecha- 21-mayo-2015

 ****************************************************************************/
void terminar_1(GtkWidget *widget, gpointer info){
    ELEMENTOS *elementos = (ELEMENTOS *)info;
    gtk_widget_set_sensitive(elementos->ventana1,FALSE);
    gtk_widget_show_all(elementos->ventana7);
}
/**************************************************************************
 *  @resumen- Este procedimiento se va un paso atras de la lista para corregir
 *  alguna jugada. Se esconde el ultimo elemento y se muestra uno anterior. Se
 *  hara una impresion del tablero con las modificaciones.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
void atras_1(GtkWidget *widget, gpointer info){
  GtkWidget *image[81];
  gint x,c,x1,y;
  DATOS *persona;
  const gchar *buffer2;
  gpointer info1; 
  ELEMENTOS *elem=(ELEMENTOS *)info;
  elem->f++;
  c=g_slist_length(elem->lista);
  y=g_slist_length(elem->lista);
  c=c-elem->f;
  for(x=0;x<81;x++){
    gtk_widget_set_sensitive(elem->boton[x],TRUE);
  }
  for(x=0;x<81;x++){
    image[x]=gtk_image_new_from_file("cuadro.jpg");
  }
  for(x=0;x<81;x++){
    gtk_button_set_image(GTK_BUTTON(elem->boton[x]),image[x]);
  }
  if(elem->f>y){
    g_print("Has exedido el numero de elementos de la lista\n"); 
    estado_1(widget,elem->barra_estado);
    elem->f=g_slist_length(elem->lista);
  }else{
    for(x=0;x<c;x++){
      info1=g_slist_nth_data(elem->lista,x);
      persona=(DATOS*)info1;
      for(x1=0;x1<81;x1++){
	buffer2=gtk_widget_get_name(elem->boton[x1]);
	if(strcmp(persona->coor,buffer2)==0){
	comparacion_a(elem->boton[x1],elem);
	}
      }
    }
  }
}
/**************************************************************************
 *  @resumen- Este procedimiento se va un paso adelante de la lista para 
 *  regresar algun tiro. Se regresa al ultimo elemento. Se
 *  hara una impresion del tablero con las modificaciones.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
void adelante_1(GtkWidget *widget, gpointer info){
  gint x,c,x1;
  GtkWidget *image[81];
  DATOS *persona;
  const gchar *buffer2;
  ELEMENTOS *elem=(ELEMENTOS *)info;
  elem->f--;
  c=g_slist_length(elem->lista);
  c=c-elem->f;
  if(elem->f>=0){
    for(x=0;x<81;x++){
      image[x]=gtk_image_new_from_file("cuadro.jpg");
    }
    for(x=0;x<81;x++){
      gtk_button_set_image(GTK_BUTTON(elem->boton[x]),image[x]);
    }
  }
  if(elem->f<0){
    g_print("Ya no hay jugadas posteriores\n");
    estado_2(widget,elem->barra_estado);
    elem->f=0;
  }
  else{
    for(x=0;x<c;x++){
      info=g_slist_nth_data(elem->lista,x);
      persona=(DATOS*)info;
      for(x1=0;x1<81;x1++){
	buffer2=gtk_widget_get_name(elem->boton[x1]);
	if(strcmp(persona->coor,buffer2)==0){
	  comparacion_a(elem->boton[x1],elem);
	}
      }
    }
  }
}
/**************************************************************************
 *  @resumen- Este procedimiento hace una comparacion y guarda a cada jugador
 *  en un archivo de texto para ir mostrando los mejores tiempos con el jugador.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 *  @param - se le manda el apuntador de toda la estructura
 ****************************************************************************/
void gano(ELEMENTOS *elementos){
  gint x1,x2;
  gchar y[7];
  FILE *f1;
  const gchar *tiempo,*buffer;
  f1=fopen("Top_5","a");
  g_source_remove(elementos->id);
  tiempo=gtk_label_get_text(GTK_LABEL(elementos->label_time));
  buffer=gtk_entry_get_text(GTK_ENTRY(elementos->textbox));
  gtk_label_set_text(GTK_LABEL(elementos->label_crono),tiempo);
  sscanf(tiempo,"Minutos: %d Segundos: %d",&x1,&x2); //impresion del tiempo raelizado
  if(x1<10&&x2<10){
    sprintf(y,"0%d//0%d",x1,x2);
  }else if(x1<10){
    sprintf(y,"0%d//%d",x1,x2);
  }else {
    sprintf(y,"%d//%d",x1,x2); //conversion a caracter
  }
  fprintf(f1,"%s\n",buffer);
  fprintf(f1,"%s\n",y);
  fclose(f1);
  ordenar(elementos);
  gtk_widget_set_sensitive(elementos->ventana1,FALSE);
  gtk_widget_show_all(elementos->ventana8);
}
/**************************************************************************
 *  @resumen- Este procedimientorealiza el ordenamiento con quicksort 
 *  convirtiendo los elemntos y haciendo la comparacion para ordenarlos de menor
 *  a mayor.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
void ordenar(ELEMENTOS *elementos){
  FILE *f2,*f1;
  ARCHI *persona;
  ARCHI *personas[100];
  char *tiempo[100];
  gint x=0,x1,x2=0;
  int izquierda, derecha;
  f2=fopen("Top_5","r");
  for(x1=0;x1<100;x1++){
    personas[x1]=malloc(sizeof(ARCHI));
  }
  persona=malloc(sizeof(ARCHI));
  *tiempo=malloc(100*sizeof(char));
  for(x1=0;x1<100;x1++){
    tiempo[x1]=malloc(7*sizeof(char));
  }
  while(fscanf(f2,"%s",persona->nombre)==1){
    fscanf(f2,"%s",persona->time);
    strcpy(tiempo[x],persona->time);
    persona=malloc(sizeof(ARCHI));
    x++;
  }
  fclose(f2);
  f2=fopen("Top_5","r");
  x1=0;
  while(fscanf(f2,"%s",personas[x1]->nombre)==1){
    fscanf(f2,"%s",personas[x1]->time);
    x1++;
  }
  if(x>1){
    izquierda=0;
    derecha=x-1;
    quicksort(tiempo,izquierda,derecha);
  }
  fclose(f2);
  f1=fopen("Top_5","w");
    for(x1=0;x1<x;x1++){
      if(strcmp(tiempo[x2],personas[x1]->time)==0){
	fprintf(f1,"%s\n",personas[x1]->nombre);
	fprintf(f1,"%s\n",personas[x1]->time);
	x2++;
	x1=-1;
      }
    }
    fclose(f1);
}

/**************************************************************************
 *  @resumen- Este es el procedimento de de quocksort que recibe el arreglo para que
 *  de esa forma lo vaya ordenando de menor a mayor.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/

void quicksort(char *nombre[],int izquierda,int derecha){
  int i,j;
  char y[100],*x;

  i=izquierda;
  j=derecha;
  x=nombre[(izquierda+derecha)/2];
  do{
    while((strcmp(nombre[i],x)<0) && (i<derecha)) i++; 
    while((strcmp(nombre[j],x)>0) && (j>izquierda)) j--;
    if(i<=j)
      {
	strcpy(y,nombre[i]); 
	strcpy(nombre[i],nombre[j]);
	strcpy(nombre[j],y); 
	i++;
	j--;
      }
  }while(i<=j);

  if(izquierda<j) quicksort(nombre,izquierda,j);
  if(i<derecha) quicksort(nombre,i,derecha);
}

/**************************************************************************
 *  @resumen- Este procedimiento se hace una comparacion del arreglo de banderas 
 *  creado en esta funcion y el arreglo de bombas creado al inicio del juego
 *  , si esta coinciden mandara el mensaje de ganador de otra forma se seguira 
 *  corriendo el tiempo y se seguira jugando.
 *
 *  @autores- Daniela Requejo
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
void ganador(GtkWidget *widget, gpointer info){

  ELEMENTOS *elem = (ELEMENTOS *)info;
  const gchar *buffer;
  gchar banderas[10][9], ban[9];
  gint x,x2=0,y=0, x1=0,y2,w2,z2,u2;

  for(x=0;x<81;x++){
     if(strcmp(elem->boton1[x],"1")==0){
       buffer=gtk_widget_get_name(elem->boton[x]);
       sscanf(buffer,"%d-%d-%d-%d",&y2,&w2,&z2,&u2);
       sprintf(ban,"%d-%d-%d-%d",y2,w2,z2,u2);
       strcpy(banderas[x2],ban);
	y++;
	x2++; // se aumenta un contador para el arreglo creado de banderas
       }
    }
     for(x=0;x<10;x++){
       if(strcmp(banderas[x],elem->bombas[0])==0){
	 x1++; 
       }
       if(strcmp(banderas[x],elem->bombas[1])==0){
       x1++; 
       }
       if(strcmp(banderas[x],elem->bombas[2])==0){
	 x1++; //contador de banderas correctas
       }
      if(strcmp(banderas[x],elem->bombas[3])==0){
        x1++; }
      if(strcmp(banderas[x],elem->bombas[4])==0){
        x1++; }
      if(strcmp(banderas[x],elem->bombas[5])==0){
        x1++; }
      if(strcmp(banderas[x],elem->bombas[6])==0){
        x1++; }
      if(strcmp(banderas[x],elem->bombas[7])==0){
        x1++; }
      if(strcmp(banderas[x],elem->bombas[8])==0){
        x1++; }
      if(strcmp(banderas[x],elem->bombas[9])==0){
        x1++; }
   }
    
     if(x1==10){ //encontro las 10 bombas
    gano(elem);
  }
}
/**************************************************************************
 *  @resumen- Este procedimiento se checa si el bontan selecciondo fue bomba 
 *  en caso de que se seleccione se mostraran todas las bombas en el tablero.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 *  @param- un widget del boton accionada para hacer la comparacion
 ****************************************************************************/
void comparacion_a(GtkWidget *widget, gpointer info){
  //gint x,y,w,y1,w1,a=0;
  gint x3=0,x2,x1=0,x,y,w,y1,w1,a=0;
  const gchar *buffer,*buffer1;
  ELEMENTOS *elem=(ELEMENTOS *)info;
  gchar bomba[9], y2[9];
  buffer=gtk_widget_get_name(widget);
  elem->buffer3=gtk_widget_get_name(widget);
  elem->explo=malloc(sizeof(DATOS));
  strcpy(elem->explo->coor,buffer);
  elem->bomba1=gtk_image_new_from_file("bomba.jpg");
  for(x=0;x<10;x++){
      if(strcmp(buffer,elem->bombas[x])==0){
	a=1;
	  for(x2=0;x2<81;x2++){
	      strcpy(bomba,elem->bombas[x1]);
	      sscanf(bomba,"%d-%d-%d-%d",&y,&w,&y1,&w1);
	      sprintf(y2,"%d-%d-%d-%d",y,w,y1,w1);
	      buffer1=gtk_widget_get_name(elem->boton[x2]);
	      if(strcmp(y2,buffer1)==0){
	      gtk_button_set_image(GTK_BUTTON(elem->boton[x2]),elem->bomba[x3]);
	      x3++;
	      x1++;
	      gtk_widget_set_sensitive(elem->boton[x2],FALSE);
	      x2=-1;
	    }
	  }
	  g_source_remove(elem->id);	  
	  gtk_widget_set_sensitive(elem->ventana10,FALSE);
	  gtk_widget_show_all(elem->ventana2);
      }
    }
    if(a==0){
      check(widget,elem);
      }
}
/**************************************************************************
 *  @resumen- Este procedimiento se crea la ventada una vez ganado el juego
 *  con el tiempo realizado.
 *
 *  @autores- Daniela Requejo
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
void vetana_ganador(ELEMENTOS *elementos){

  GtkWidget *ganador1,*nuevo2,*cancelar,*vent,*caja4;
  elementos->ventana8=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_usize(elementos->ventana8,300,100);
  gtk_window_set_title(GTK_WINDOW(elementos->ventana2),"Buscaminas");
  elementos->label_crono=gtk_label_new(NULL);
  ganador1=gtk_label_new("Has ganado!!!! \nDeseas volver a jugar?");
  nuevo2=gtk_button_new_with_label("Juego Nuevo");
  cancelar=gtk_button_new_with_label("Salir");
  caja4=gtk_vbox_new(FALSE,0);
  vent=gtk_hbox_new(FALSE,0);
  g_signal_connect(G_OBJECT(cancelar),"clicked",G_CALLBACK(Salir),elementos);
  g_signal_connect(G_OBJECT(nuevo2),"clicked",G_CALLBACK(nuevo_juego1),elementos);
  gtk_box_pack_start_defaults(GTK_BOX(vent),nuevo2);
  gtk_box_pack_start_defaults(GTK_BOX(vent),cancelar);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),ganador1);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),elementos->label_crono);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),vent);
  gtk_container_add(GTK_CONTAINER(elementos->ventana8),caja4);

}
/**************************************************************************
 *  @resumen- Este procedimiento se mostrara una ventana de seguir con la partida
 *
 *  @autores- David Parra y Daniela Requejo
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/

void seguir_juego_1(GtkWidget *widget, gpointer info){
    ELEMENTOS *elementos = (ELEMENTOS *)info;
    gtk_widget_set_sensitive(elementos->ventana1,TRUE);
    gtk_widget_hide(elementos->ventana11);
}	
    
/**************************************************************************
 *  @resumen- Este procedimiento se crea una ventana donde se imprimen los
 *  5 jugadores con mejor recor de tiempo. Esto ya es creado con la funcion anteriormente 
 *  hecha con quicksort.
 *
 *  @autores- Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
void ventana_top_5(ELEMENTOS *elementos){

  GtkWidget *OK,*caja4,*titulo;//,*vent;

  elementos->ventana11=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_usize(elementos->ventana2,500,500);
  gtk_window_set_title(GTK_WINDOW(elementos->ventana2),"Buscaminas");
  titulo=gtk_label_new("TOP 5");
  elementos->top_1=gtk_label_new(NULL);
  elementos->tiempo_1=gtk_label_new(NULL);
  elementos->top_2=gtk_label_new(NULL);
  elementos->tiempo_2=gtk_label_new(NULL);
  elementos->top_3=gtk_label_new(NULL);
  elementos->tiempo_3=gtk_label_new(NULL);
  elementos->top_4=gtk_label_new(NULL);
  elementos->tiempo_4=gtk_label_new(NULL);
  elementos->top_5=gtk_label_new(NULL);
  elementos->tiempo_5=gtk_label_new(NULL);
  OK=gtk_button_new_with_label("OK");
  caja4=gtk_vbox_new(FALSE,0);
  gtk_widget_set_usize(elementos->ventana11,200,200);
  //vent=gtk_hbox_new(FALSE,0);
  g_signal_connect(G_OBJECT(OK),"clicked",G_CALLBACK(seguir_juego_1),elementos);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),titulo);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),elementos->top_1);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),elementos->tiempo_1);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),elementos->top_2);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),elementos->tiempo_2);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),elementos->top_3);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),elementos->tiempo_3);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),elementos->top_4);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),elementos->tiempo_4);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),elementos->top_5);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),elementos->tiempo_5);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),OK);
  gtk_container_add(GTK_CONTAINER(elementos->ventana11),caja4);

}
 
/**************************************************************************
 *  @resumen- Este procedimiento lee el archivo para que de esa forma solo
 *  lea los primeros cinco y lo mande a la funcion de top_5 y se puedan desplegar
 *  y se vean ordenados.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/

void mostrar_top(GtkWidget *widget, gpointer info){
  FILE *f1;
  ARCHI *personas[100]; 
  gint x1;
  ELEMENTOS *elementos = (ELEMENTOS *)info;
  f1=fopen("Top_5","r"); 
  for(x1=0;x1<100;x1++){
    personas[x1]=malloc(sizeof(ARCHI));
  }
  x1=0;
  while(fscanf(f1,"%s",personas[x1]->nombre)==1){
    fscanf(f1,"%s",personas[x1]->time); //compararacion de tirmpo y person para ver si coincide
    x1++;
  }
    gtk_label_set_text(GTK_LABEL(elementos->top_1),personas[0]->nombre);
    gtk_label_set_text(GTK_LABEL(elementos->tiempo_1),personas[0]->time);
    gtk_label_set_text(GTK_LABEL(elementos->top_2),personas[1]->nombre);
    gtk_label_set_text(GTK_LABEL(elementos->tiempo_2),personas[1]->time);
    gtk_label_set_text(GTK_LABEL(elementos->top_3),personas[2]->nombre);
    gtk_label_set_text(GTK_LABEL(elementos->tiempo_3),personas[2]->time);
    gtk_label_set_text(GTK_LABEL(elementos->top_4),personas[3]->nombre);
    gtk_label_set_text(GTK_LABEL(elementos->tiempo_4),personas[3]->time);
    gtk_label_set_text(GTK_LABEL(elementos->top_5),personas[4]->nombre);
    gtk_label_set_text(GTK_LABEL(elementos->tiempo_5),personas[4]->time);
  gtk_widget_set_sensitive(elementos->ventana1,FALSE);
  gtk_widget_show_all(elementos->ventana11);

}
/**************************************************************************
 *  @resumen- Este procedimiento se va un paso atras de la lista para corregir
 *  alguna jugada. Se esconde el ultimo elemento y se muestra uno anterior. Se
 *  hara una impresion del tablero con las modificaciones.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
void ventana_recuperar(ELEMENTOS *elementos){

 GtkWidget *nombre,*OK,*caja4;
  elementos->ventana12=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_usize(elementos->ventana2,300,100);
  gtk_window_set_title(GTK_WINDOW(elementos->ventana2),"Buscaminas");
  nombre=gtk_label_new("Escribe tu nombre:");
  elementos->textbox4=gtk_entry_new();
  OK=gtk_button_new_with_label("OK");;
  caja4=gtk_vbox_new(FALSE,0);
  //  vent=gtk_hbox_new(FALSE,0);
  g_signal_connect(G_OBJECT(OK),"clicked",G_CALLBACK(recupera_juego_4),elementos);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),nombre);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),elementos->textbox4);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),OK);
  gtk_container_add(GTK_CONTAINER(elementos->ventana12),caja4);

}
/**************************************************************************
 *  @resumen- Este procedimiento se va un paso atras de la lista para corregir
 *  alguna jugada. Se esconde el ultimo elemento y se muestra uno anterior. Se
 *  hara una impresion del tablero con las modificaciones.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 ****************************************************************************/
void ventana_copia(ELEMENTOS *elementos){

 GtkWidget *adv,*si,*no,*caja4;
  elementos->ventana13=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_usize(elementos->ventana13,300,100);
  gtk_window_set_title(GTK_WINDOW(elementos->ventana13),"Buscaminas");
  adv=gtk_label_new("Este archivo ya existe, desea reescribirlo??");
  si=gtk_button_new_with_label("SI");
  no=gtk_button_new_with_label("NO");
  caja4=gtk_vbox_new(FALSE,0);
  //vent=gtk_hbox_new(FALSE,0);
  g_signal_connect(G_OBJECT(si),"clicked",G_CALLBACK(guardar_juego),elementos);
  g_signal_connect(G_OBJECT(no),"clicked",G_CALLBACK(mostrar_nuevo),elementos);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),adv);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),si);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),no);
  gtk_container_add(GTK_CONTAINER(elementos->ventana13),caja4);
} 
/**************************************************************************
 *  @resumen- Este procedimiento crea la ventana para pedir el nombre del jugador
 *  y poder guardar su jugada.
 *
 *  @autores- Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 *  @param- un apuntador con toda la estructura creada al principio del programa
 ****************************************************************************/
void deme_nombre(ELEMENTOS *elementos){

  GtkWidget *nombre,*OK,*caja4; //*ingresa_nombre1;
  elementos->ventana14=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_usize(elementos->ventana14,300,100);
  gtk_window_set_title(GTK_WINDOW(elementos->ventana14),"Buscaminas");
  nombre=gtk_label_new("Dame tu nombre");
  elementos->textbox2=gtk_entry_new();
  OK=gtk_button_new_with_label("OK");;
  caja4=gtk_vbox_new(FALSE,0);
  // vent=gtk_hbox_new(FALSE,0);
  g_signal_connect(G_OBJECT(OK),"clicked",G_CALLBACK(guardar_juego_2),elementos);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),nombre);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),elementos->textbox2);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),OK);
  gtk_container_add(GTK_CONTAINER(elementos->ventana14),caja4);

}
/**************************************************************************
 *  @resumen- Este procedimiento crea la ventana para mostrar el mensaje de
 *  nuevo juego
 *
 *  @autores- Daniela Requejo 
 *  @fecha- 21-mayo-2015

 ****************************************************************************/
void mostrar_nuevo(GtkWidget *widget, gpointer info){
  ELEMENTOS *elementos = (ELEMENTOS *)info;
  gtk_widget_hide(elementos->ventana13);
  gtk_widget_show_all(elementos->ventana14);

}
/**************************************************************************
 *  @resumen- Este procedimiento crea la ventana para mostrar de recupera jugada.
 *
 *  @autores- Daniela Requejo 
 *  @fecha- 21-mayo-2015
 ****************************************************************************/
void mostrar_recupera(GtkWidget *widget, gpointer info){
  ELEMENTOS *elementos = (ELEMENTOS *)info;
  gtk_widget_set_sensitive(elementos->ventana1,FALSE);
  gtk_widget_show_all(elementos->ventana12);

}
/**************************************************************************
 *  @resumen- Este procedimiento crea la ventana para mostrar nombre el mensaje de
 *  max elementos realizados.
 *
 *  @autores- Daniela Requejo 
 *  @fecha- 21-mayo-2015
 ****************************************************************************/
void mostrar_nombre(GtkWidget *widget, gpointer info){
    ELEMENTOS *elementos = (ELEMENTOS *)info;
     gtk_widget_set_sensitive(elementos->ventana1,FALSE);
     gtk_widget_show_all(elementos->ventana13);

}
/**************************************************************************
 *  @resumen- Este procedimiento crea la ventana para mostrar el mensaje de
 *  max elementos realizados.
 *
 *  @autores- Daniela Requejo 
 *  @fecha- 21-mayo-2015
 ****************************************************************************/
void muestra_sig(GtkWidget *widget, gpointer info){
  ELEMENTOS *elem=(ELEMENTOS *)info;
  gtk_widget_hide(elem->ventana);
  gtk_widget_show_all(elem->ventana15);
}
void com_guardar(GtkWidget *widget, gpointer info){
  FILE *f1;
  const gchar *buffer1;
  gchar *buffer2,*buffer3;
  ELEMENTOS *elementos = (ELEMENTOS *)info;
  buffer2=malloc(sizeof(gchar));
  buffer3=malloc(sizeof(gchar));
  buffer1=gtk_entry_get_text(GTK_ENTRY(elementos->textbox));
  sprintf(buffer2,"%s.bcm",buffer1);
  sprintf(buffer3,"%s1.bcm",buffer1);
  if((f1=fopen(buffer2,"r"))==NULL){
    guardar_juego(widget,elementos);
  }else{
    mostrar_nombre(widget,elementos);
    fclose(f1);
  }
}

/**************************************************************************
 *  @resumen- Este procedimiento crea la ventana para mostrar el mensaje de
 *  max elementos realizados.
 *
 *  @autores- Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 *  @param- un apuntador con toda la estructura creada al principio del programa
 ****************************************************************************/	


void mostrar_max(GtkWidget *widget, gpointer info){
  ELEMENTOS *elem=(ELEMENTOS *)info;
  gtk_widget_hide(elem->ventana15);
  gtk_widget_show_all(elem->ventana16);
}

/**************************************************************************
 *  @resumen- Este procedimiento obtiene el tamaño de la lista  para que de esa forma la vaya 
 *  recorriendo y vaya mostrando jugada por jugada.
 *
 *  @autores- David Parra 
 *  @fecha- 21-mayo-2015
 *
 *  @param- un apuntador con toda la estructura creada al principio del programa
 ****************************************************************************/	
void sig(GtkWidget *widget, gpointer info){
  gint x1,c;
  ELEMENTOS *elem=(ELEMENTOS *)info;
  DATOS *persona;
  gpointer info1;
  gchar *mina1,*buffer4;
  const gchar *buffer2;
  c=g_slist_length(elem->lista);
  info1=g_slist_nth_data(elem->lista,elem->z);
  persona=(DATOS*)info1;
  for(x1=0;x1<81;x1++){
    buffer2=gtk_widget_get_name(elem->boton[x1]);
    if(strcmp(persona->coor,buffer2)==0){
      comparacion_a(elem->boton[x1],elem);
    }
  }
  strcpy(elem->o,"1");
  buffer4=malloc(sizeof(gchar));
  mina1=malloc(sizeof(gchar));
  //  sprintf(buffer4,"El jugador es : %s",buffer1);
  gtk_widget_hide(elem->ventana);
  gtk_label_set_text(GTK_LABEL(elem->label),buffer4);
  sprintf(mina1,"%d",elem->contador);
  gtk_label_set_text(GTK_LABEL(elem->label_mina),mina1);
  gtk_widget_hide(elem->ventana12);
  gtk_widget_hide(elem->ventana13);
  gtk_widget_hide(elem->ventana14);
  elem->z++;
  if(elem->z==c){
    mostrar_max(widget,elem);
  }
}

/**************************************************************************
 *  @resumen- Este procedimiento crea la ventana para ir viendo las jugadas del
 *  su juego.
 *
 *  @autores- Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 *  @param- un apuntador con toda la estructura creada al principio del programa
 ****************************************************************************/	

void mov_sig(ELEMENTOS *elementos){

  GtkWidget *nombre,*siguiente,*caja4;
  elementos->ventana15=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_usize(elementos->ventana15,300,100);
  gtk_window_set_title(GTK_WINDOW(elementos->ventana2),"Buscaminas");
  nombre=gtk_label_new("Siguiente para ver los movimientos de su juego");
  siguiente=gtk_button_new_with_label("Siguiente"); //boton para darle click e ir viendo la jugada
  caja4=gtk_vbox_new(FALSE,0);
  //  vent=gtk_hbox_new(FALSE,0);
  g_signal_connect(G_OBJECT(siguiente),"clicked",G_CALLBACK(sig),elementos);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),nombre);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),siguiente);
  gtk_container_add(GTK_CONTAINER(elementos->ventana15),caja4);

}
/**************************************************************************
 *  @resumen- Este procedimiento crea la ventana que ya no se tienen mas jugadas
 *  y que ahi se quedo.
 *
 *  @autores- Daniela Requejo 
 *  @fecha- 21-mayo-2015
 *
 *  @param- un apuntador con toda la estructura creada al principio del programa
 ****************************************************************************/	
void maximo_sig(ELEMENTOS *elementos){

  GtkWidget *nombre,*OK,*caja4; //*ingresa_nombre1;
  elementos->ventana16=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_usize(elementos->ventana16,300,100);
  gtk_window_set_title(GTK_WINDOW(elementos->ventana2),"Buscaminas");
  nombre=gtk_label_new("Hasta aqui llego tu juego");
  OK=gtk_button_new_with_label("OK");
  caja4=gtk_vbox_new(FALSE,0);
  // vent=gtk_hbox_new(FALSE,0);
  g_signal_connect(G_OBJECT(OK),"clicked",G_CALLBACK(recupera_juego),elementos);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),nombre);
  gtk_box_pack_start_defaults(GTK_BOX(caja4),OK);
  gtk_container_add(GTK_CONTAINER(elementos->ventana16),caja4);

}
