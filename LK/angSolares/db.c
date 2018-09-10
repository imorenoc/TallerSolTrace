
#include <math.h>
#include <stdlib.h>
#include "db.h"

#define PI         3.1415926535897932384626433832795028841971

/* Funciones basicas */
/* ---------------------------------------------------------------------- */

/* radianes a grados */
double r2d(double radianes){
  return (180.0/PI)*radianes;
}

/* grados a radianes */
double d2r(double grados){
  return (PI/180.0)*grados;
}

/* horas a radianes */
double h2r(double horas){
  return horas*PI*12.0;
}
/* horas a grados */
double h2d(double horas){
  return horas*180.0/12.0;
}

/* radianes a segundos */
double r2s(double radianes){
  return radianes*12.0/PI*3600.0;
}

/* hora + min + seg, en horas */
double hms(int hora, int minuto, int segundo){
  return hora + minuto/60.0 + segundo/3600.0;
}

/* Validaci'on */
/* ---------------------------------------------------------------------- */
int validate_inputs(db_data *db)
{
    if ((db->anno        < -2000) || (db->anno        > 6000)) return 1;
    if ((db->mes         < 1    ) || (db->mes       > 12  )) return 2;
    if ((db->dia         < 1    ) || (db->dia         > 31  )) return 3;
    if ((db->hora        < 0    ) || (db->hora        > 24  )) return 4;
    if ((db->minuto      < 0    ) || (db->minuto      > 59  )) return 5;
    if ((db->segundo     < 0    ) || (db->segundo      >=60  )) return 6;

    if (fabs(db->latitud)      > 90      ) return 7;

    return 0;
}

/* Funciones del calculo de */
/* ---------------------------------------------------------------------- */
const int MES[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

// dia del año
int dda(int mes, int dia)
{
  return MES[mes - 1] + dia ;
}

double B(int N){
  return 2.0*PI*(N-1)/365.0;	/* radianes */
}

/* Declinaci'on */
double delta(int N, double B, int metodo){
  double decl;

  switch(metodo){
  case 1:			/* cooper */
    decl = 23.45 * sin(2.0*PI*(284 + N)/365.0);
    decl = d2r(decl);
    break;
  case 2:			/* spencer */
    decl = 0.006918-0.399912*cos(B)+0.070257*sin(B)- 0.006758*cos(2.0*B)+ 0.000907*sin(2.0*B)- 0.002697*cos(3.0*B)+0.001480*sin(3.0*B);
    break;
  }
  return decl;
}

/* Ecuación del tiempo [minutos] */
double EdT(double B){
  return 229.2 * (0.000075 + 0.001868*cos(B) - 0.032077*sin(B) - 0.014615*cos(2*B) - 0.04089*sin(2*B));
}

/* omega [radianes]*/
double omega(double HMS){	/* HMS en tiempo solar */
  return d2r(15.0*(HMS-12.0));
}

/* 'angulo de amanecer y anochecer [hrs]*/
double omega_s(double latitud, double declinacion){
  double x;
  x = acos( tan( d2r(latitud) )*tan(declinacion) );
  x = r2d(x)/15.0;  
  return x;
}

/* Direfencia entre tiempo solar y estandar [min]*/
double dtiempo(double E, double Lst, double Lloc){
  return 4.0*(Lst - Lloc) + E;
}

/* 'angulo cenital [radianes] */
double theta_z(double latitud, double declinacion, double omega){
  latitud = d2r(latitud);
  return acos( cos(latitud)*cos(declinacion)*cos(omega) + sin(latitud)*sin(declinacion));
}

/* 'angulo acimital */
double gamma_s(double latitud, double declinacion, double omega, double cenit){
  double Ss, Cs, x, g;
  latitud = d2r(latitud);
  Ss = sin(omega)*cos(declinacion)/sin(cenit);
  Cs = (sin(latitud)*cos(declinacion)*cos(omega) - cos(latitud)*sin(declinacion) )/ sin(cenit);
  x = sin(omega)*cos(declinacion)/( sin(latitud)*cos(omega)*cos(declinacion) - cos(latitud)*sin(declinacion));
  g = atan(x);
  if(Cs >= 0)
      return g;
  else if(Cs < 0 & Ss < 0)
      return g - PI;
  else if(Cs < 0 & Ss > 0)
      return g + PI;
  return 0;
}

/* calculo de los 'angulos solare */
/* ---------------------------------------------------------------------- */
int db_calculate(db_data *db){
    int result;

    result = validate_inputs(db);
    //Sobre las funciones

    db->N = dda(db->mes, db->dia);
    db->B = B(db->N);
    db->declinacion = delta(db->N, db->B, db->metodo);
    db->E = EdT(db->B);
    db->HMS = hms(db->hora, db->minuto, db->segundo);
    db->omega = omega(db->HMS);
    db->omega_s = omega_s(db->latitud, db->declinacion);
    db->dt = dtiempo(db->E, db->Lst, db->Lloc);
    db->cenit = theta_z(db->latitud, db->declinacion, db->omega);
    db->acimut = gamma_s(db->latitud, db->declinacion, db->omega, db->cenit);
    return result;
}

int db_ang(db_data *db){
  //db->HMS = hms(db->hora, db->minuto, db->segundo);
  db->omega = omega(db->HMS);
  db->cenit = theta_z(db->latitud, db->declinacion, db->omega);
  db->acimut = gamma_s(db->latitud, db->declinacion, db->omega, db->cenit);
  return 0;
}
