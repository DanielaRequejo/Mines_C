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

extern gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer info);
extern void nuevo_juego(GtkWidget *widget, gpointer info);
extern void nuevo_juego1(GtkWidget *widget, gpointer info);
extern void recupera_juego(GtkWidget *widget, gpointer info);
extern void recupera_juego_4(GtkWidget *widget, gpointer info);
extern void Salir(GtkWidget *widget, gpointer info);
extern void comparacion(GtkWidget *widget, gpointer info);
extern void bomba(ELEMENTOS *elementos);
extern float rand9(void);
extern void check(GtkWidget *widget, gpointer info);
extern void no_hay_bombas(GtkWidget *widget, gpointer info);
extern void no_hay_bombas_1(GtkWidget *widget, gpointer info);
extern void no_hay_bombas_2(GtkWidget *widget, gpointer info);
extern void no_hay_bombas_3(GtkWidget *widget, gpointer info);
extern gint incrementa(gpointer info);
extern void estado(GtkWidget *widget, gpointer info);
extern gboolean bandera(GtkWidget *widget,GdkEvent *event, gpointer user_data);
extern void principal(ELEMENTOS *elementos);
extern void juego(ELEMENTOS *elementos);
extern void perdida(ELEMENTOS *elementos);
extern void guardada(ELEMENTOS *elementos);
extern void guardar_juego(GtkWidget *widget, gpointer info);
extern void seguir_juego(GtkWidget *widget, gpointer info);
extern void comparacion_r(GtkWidget *widget, gpointer info);
extern void check_r(GtkWidget *widget, gpointer info);
extern void no_hay_bombas_r(GtkWidget *widget, gpointer info);
extern gint incrementa_r(gpointer info);
extern gboolean bandera_r(GtkWidget *widget,GdkEvent *event, gpointer user_data);
extern void juego_r(ELEMENTOS *elementos);
extern void guardada_r(ELEMENTOS *elementos);
extern void guardar_juego_r(GtkWidget *widget, gpointer info);
extern void seguir_juego_r(GtkWidget *widget, gpointer info);
extern void guardar_juego_1(GtkWidget *widget, gpointer info);
extern void ventana_ayuda(ELEMENTOS *elementos);
extern void ayuda(GtkWidget *widget, gpointer info);
extern void terminar_guardar(ELEMENTOS *elementos);
extern void atras_1(GtkWidget *widget, gpointer info);
extern void adelante_1(GtkWidget *widget, gpointer info);
extern void terminar_1(GtkWidget *widget, gpointer info);
extern void ganador(GtkWidget *widget, gpointer info);
extern void vetana_ganador(ELEMENTOS *elementos);
extern void gano(ELEMENTOS *elementos);
extern void comparacion_a(GtkWidget *widget, gpointer info);
extern void ordenar(ELEMENTOS *elementos);
extern void quicksort(char *nombre[],int izquierda,int derecha);
extern void ventana_top_5(ELEMENTOS *elementos);
extern void mostrar_top(GtkWidget *widget, gpointer info);
extern void ventana_recuperar(ELEMENTOS *elementos);
extern void ventana_copia(ELEMENTOS *elementos);
extern void mostrar_nuevo(GtkWidget *widget, gpointer info);
extern void mostrar_recupera(GtkWidget *widget, gpointer info);
extern void com_guardar(GtkWidget *widget, gpointer info);
extern void deme_nombre(ELEMENTOS *elementos);
extern void guardar_juego_2(GtkWidget *widget, gpointer info);
extern void maximo_sig(ELEMENTOS *elementos);
extern void mov_sig(ELEMENTOS *elementos);
extern void sig(GtkWidget *widget, gpointer info);
extern void mostrar_max(GtkWidget *widget, gpointer info);
extern void muestra_sig(GtkWidget *widget, gpointer info);
extern void lista_v(GtkWidget *widget, gpointer info);

int main(int argc, char *argv[]){  
  ELEMENTOS *elementos;  
  gint x;
  gtk_init(&argc,&argv);
  elementos=malloc(sizeof(ELEMENTOS));
  elementos->lista=NULL;
  elementos->jugador=malloc(sizeof(CRONOS));
  elementos->flag=0;
  elementos->x=0  //iniciar variables en cero;
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
