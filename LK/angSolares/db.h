
#ifndef __algoritmo_duffie_beckman
#define __algoritmo_duffie_beckman

typedef struct {

  //----------Variables de entrada----------
  int anno;	      /* cuatro digitos */
  int mes;	      /* 1 al 12 */
  int dia;	      /* dos digitos */
  int hora;	      /* 0 a  24 */
  int minuto;	      /* 0 a  59 */
  double segundo;     /* 0 to <60 */
  int metodo;	      /* 1:cooper, 2:spencer */
  double latitud;     /* latitud del observador (+N del ecuador) */
  double Lloc;	      /* longitud local */
  double Lst;	      /* meriadiano estandar, huso horario * 15 */


  //----------Variables de intermedias----------
  int N;			/* d'ia del a~no */
  double B;
  double declinacion;
  double E;			/* ecuaci'on del tiempo */
  double HMS;			/* tiempo en horas */
  double omega;			/* 'angulo solar  */
  double omega_s;		/* 'angulo de amanecer y anochecer */
  double dt;			/* tiempo solar - tiempo local */

  //----------Variables de salida----------
  double cenit;			/* 'angulo cenital */
  double acimut;		/* 'angulo acimutal, desde el sur-oeste */

} db_data;

//-------------- Funciones utiles --------------
double r2d(double radianes);
double d2r(double grados);
double h2r(double horas);
double h2d(double horas);
double r2s(double radianes);
double hms(int hora, int minuto, int segundo);

int dda(int mes, int dia);	/* dia del año */
double B(int N);
double delta(int N, double B, int metodo);
double EdT(double B);
double omega(double HMS);
double omega_s(double latitud, double declinacion);
double theta_z(double latitud, double declinacion, double omega);
double gamma_s(double latitud, double declinacion, double omega, double cenit);

//Calculate SPA output values (in structure) based on input values passed in structure
int db_calculate(db_data *db);
int db_ang(db_data *db);

#endif
