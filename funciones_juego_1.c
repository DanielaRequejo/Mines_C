#include "biblioteca.h"

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
    if(y<4){
      no_hay_bombas(widget,elem);}
    else if(y>4){
      no_hay_bombas_3(widget,elem);}
    else if(y<4&&z<9){
      no_hay_bombas_2(widget,elem);
    }else if(y>4&&z<9){
      no_hay_bombas_1(widget,elem);
    }else{
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
