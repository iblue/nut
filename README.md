# New Universal Time (NUT)

A new time format for the world.

## Concept

We are using the following units:

1 day: 86400 (that is 24*60*60 seconds)
1 year: 365 days (or 366 days in a leap year)

A year begins at the day of the vernal equinox on 0 UTC (in the next few
years, the date is march 20th).

A day begins at 0:00 UTC.

The current year is 2014.

The date is given by the number of the year followed by a space followed
by the number of the current day.

The time of the day is given in ks (kiloseconds).

Example: The time this file was written is 2014 039 67.608 NUT

## Pros

* No time zones
* No summer time
* Less stuff to calculate
  * How many days are there between April, 28th 2014 and August, 6th 2014? 100.
  * How many days are there between 2014 039 and 2014 139? 100, but you
    don't need to calculate that.
  * What time is it in London, Washington, Bangladesh? The same. No time
    zones.

