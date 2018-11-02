#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct datos{
  gchar coor[9];
}DATOS;

typedef struct arch{
  char nombre[50];
  char time[7];
}ARCHI;

typedef struct tiempo{
  gint horas;
  gint minutos;
  gint segundos;
  gint num_tiros;
  gint tiro_act;
}CRONOS;

typedef struct elementos{
  GSList *lista;
  DATOS *explo;
  GtkWidget *ventana10;
  GtkWidget *ventana11;
  GtkWidget *ventana12;
  GtkWidget *ventana13;
  GtkWidget *ventana14;
  GtkWidget *ventana15;
  GtkWidget *ventana16;
  GtkWidget *textbox;
  GtkWidget *textbox1;
  GtkWidget *textbox2;
  GtkWidget *textbox4;
  GtkWidget *label;
  GtkWidget *label1;
  GtkWidget *ventana;
  GtkWidget *ventana1;
  GtkWidget *ventana2;
  GtkWidget *ventana3;
  GtkWidget *ventana4;
  GtkWidget *ventana5;
  GtkWidget *ventana6;
  GtkWidget *ventana7;
  GtkWidget *bomba[10]; 
  GtkWidget *bomba1;
  GtkWidget *bandera;
  GtkWidget *tabla1;
  GtkWidget *tabla2;
  GtkWidget *label_time;
  GtkWidget *label_time1;
  GtkWidget *label_crono;
  GtkWidget *label_mina;
  GtkWidget *label_mina1;
  GtkWidget *boton[81];
  GtkWidget *herramientas[5];
  GtkWidget  *barra_estado;
  GtkWidget *barra_estado1;
  GtkWidget *top_1,*top_2,*top_3,*top_4,*top_5,*tiempo_1,*tiempo_2,*tiempo_3,*tiempo_4,*tiempo_5;
  gchar bombas[10][9];
  gchar bombas1[10][9];
  gchar boton1[81][2];
  gchar tipo[81][2];
  gchar o[2],b[2],h[2];
  gint flag;
  gint x,y,f,z;
  gint id,id1;
  const gchar *buffer3;
  gint contador;
  CRONOS *jugador;
  GtkWidget *ventana8;
  GtkWidget *ventana9;
  GtkAccelGroup *accel_group;
}ELEMENTOS;

