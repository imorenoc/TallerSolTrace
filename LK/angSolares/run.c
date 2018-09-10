// Compilar como
// gcc -lm run.c db.c
//---------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "db.h"

int main (int argc, char *argv[])
{
  char s_file[80];
  db_data db;  		/* declara la estructura db_data */
  int result;
  FILE *f;

  db.anno	= atoi(argv[1]);
  //db.mes	= atoi(argv[2]);
  db.dia      = atoi(argv[2]);
  db.hora     = 12;
  db.minuto   = atoi(argv[3]);
  db.segundo  = atoi(argv[4]);
  db.latitud	= atof(argv[5]);
  db.Lloc     = atof(argv[6]);  /* longitud local, +Oeste */
  db.Lst      = atof(argv[7]);  /* meriadiano estandar, huso horario * 15 */
  db.metodo   = atoi(argv[8]);  /* 1:cooper, 2:spencer */

  sprintf(s_file, "data.dat");
  f = fopen(s_file, "w");

  fprintf(f,"%s\n", "## mes hora acimut cenit s[0] s[1] s[2]");
  for (db.mes = 1; db.mes < 13; db.mes++) {
    result = db_calculate(&db);
    if (result == 0){ // Si no hay errores bd se ejecuta
      /* hora solar */
      for (db.HMS = 0.5; db.HMS < 24; db.HMS = db.HMS + 0.1) {
	db_ang(&db);
	// x-Este
	// y-Norte
	// z-Cenit
	fprintf(f, "%d\t%f\t%f\t%f\t%f\t%f\t%f\n", db.mes, db.HMS, r2d(db.acimut), r2d(db.cenit),\
		sin(db.cenit)*cos(db.acimut), sin(db.cenit)*sin(db.acimut), cos(db.cenit) );
	}
    } else printf("Error de DB: %d\n", result);
    fprintf(f, "\n\n");
  }
  return 0;
}
