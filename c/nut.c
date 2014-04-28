/*
 * FIXME: Quick hack. Compile with
 * cc -O2 -Werror -o nut nut.c
 */
#include <time.h>
#include <malloc.h>

/* day of the vernal equinox. march, 20th */
#define EQUINOX 79

typedef struct {
  unsigned short year;
  unsigned short day;
  unsigned int seconds;
} nut_t;

typedef struct tm tm_t;


nut_t* time_to_nut(tm_t* time) {
  nut_t* ret = malloc(sizeof(nut_t));

  ret->year = time->tm_year + 1900;
  ret->day = time->tm_yday - (EQUINOX-1);
  if(time->tm_yday < EQUINOX) {
    ret->year--;
    ret->day += 365; // FIXME: Breaks if last year is a leap year.
  }

  ret->seconds = time->tm_sec + time->tm_min*60 + time->tm_hour*3600;

  return ret;
}

int year(time_t time) {
}

int main(void) {
  time_t t = time(NULL);
  tm_t* ts  = gmtime(&t);
  nut_t* nut = time_to_nut(ts);

  printf("%d %03d %02d.%03d NUT\n", nut->year, nut->day, nut->seconds/1000, nut->seconds % 1000);

  return 0;
}
