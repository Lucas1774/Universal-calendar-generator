#include <stdio.h>
#include <stdlib.h>

int main(){
  int mes, anyo, diasdelmes, mesparazeller, anyoparazeller, siglo, anyodelsiglo, a, b, c, diadelasemanadeldia1, dia, diadelasemana;
  typedef int tipovector[];
  tipovector diasdelosmeses={0,31,28,31,30,31,30,31,31,30,31,30,31};
  const char punto[]=".";
  const char barra[]="|";

//obtenerfecha
  printf("%cMes (1..12)?",168);
  scanf("%d",&mes);
  printf("%cA%co?",168,164);
  scanf("%d",&anyo);

//calculardiasdelmes
  if((anyo%4==0&&anyo%100!=0)||anyo%400==0){
      diasdelosmeses[2]=29;
    }
  diasdelmes=diasdelosmeses[mes];
  
//calculardiadelasemanadeldia1
  if (mes==1||mes==2){
    mesparazeller=mes+12;
    anyoparazeller=anyo-1;
  } else{
    mesparazeller=mes;
    anyoparazeller=anyo;
  }
  siglo=anyoparazeller/100;
  anyodelsiglo=anyoparazeller%100;
  a=(13*(mesparazeller+1))/5;
  b=anyodelsiglo/4;
  c=siglo/4;
  diadelasemanadeldia1=(1+(a)+(anyodelsiglo)+(b)+(c)-(2*siglo))%7;
  if(diadelasemanadeldia1<0){
    diadelasemanadeldia1=diadelasemanadeldia1+7;
  }
  diadelasemanadeldia1=((diadelasemanadeldia1+5)%7)+1;

//imprimirencabezado
  if (mes==1)       {printf("ENERO                  %d\n",anyo);
  }else if (mes==2) {printf("FEBRERO                %d\n",anyo);
  }else if (mes==3) {printf("MARZO                  %d\n",anyo);
  }else if (mes==4) {printf("ABRIL                  %d\n",anyo);
  }else if (mes==5) {printf("MAYO                   %d\n",anyo);
  }else if (mes==6) {printf("JUNIO                  %d\n",anyo);
  }else if (mes==7) {printf("JULIO                  %d\n",anyo);
  }else if (mes==8) {printf("AGOSTO                 %d\n",anyo);
  }else if (mes==9) {printf("SEPTIEMBRE             %d\n",anyo);
  }else if (mes==10){printf("OCTUBRE                %d\n",anyo);
  }else if (mes==11){printf("NOVIEMBRE              %d\n",anyo);
  }else             {printf("DICIEMBRE              %d\n",anyo);
  }
  printf("===========================\n");
  printf("LU  MA  MI  JU  VI | SA  DO\n");
  printf("===========================\n");

//imprimircuerpo
  for(int i=0;i<=diasdelmes+1;i++){
    dia=i;
    if (dia==0){
      diadelasemana=1;
      for(int i=1;i<diadelasemanadeldia1;i++){
        if (diadelasemana==1){
          printf("%2s",punto);
        } else if (diadelasemana==6){
          printf("%3s",punto);
        } else{
          printf("%4s",punto);
        }
        if(diadelasemana==5){
          printf("%2s",barra);
        }
        diadelasemana++;
      }
    } else if (dia==diasdelmes+1){
      if (diadelasemana!=1){
        for(int i=0;diadelasemana<=7;i++){
          if (diadelasemana==6){
            printf("%3s",punto);
          } else{
            printf("%4s",punto);
          }
          if(diadelasemana==5){
            printf("%2s",barra);
          }
          diadelasemana++;
        }
      }
    } else {
      if (diadelasemana==1){
        printf("%2d",dia);
      } else if  (diadelasemana==6){
        printf("%3d",dia);
      } else {
        printf("%4d",dia);
      }
      if (diadelasemana==5){
        printf("%2s",barra);
      }
      if (diadelasemana==7){
        printf("\n");
        diadelasemana=0;
      }
      diadelasemana++;
    }
  }
}
