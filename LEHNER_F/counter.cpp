/*-----------------------------------------------------------------------------
*				HTBLA-Leonding / Class: <2DHIF>
*-----------------------------------------------------------------------------
* Exercise Number: #exercise_number#
* File:			counter.cpp
* Author(s):	<Fabio Lehner>
* Due Date:		#due#
*-----------------------------------------------------------------------------
* Description:
* A counter to count up and count down.
*-----------------------------------------------------------------------------
*/
#include "counter.h"

struct CounterImplementation{
  enum Direction direction;
  int increment_value;
  int value;
  bool is_used;

};


struct CounterImplementation c1={UNDEFINED,0,0,false};
struct CounterImplementation c2={UNDEFINED,0,0,false};
struct CounterImplementation c3={UNDEFINED,0,0,false};
struct CounterImplementation c4={UNDEFINED,0,0,false};
struct CounterImplementation c5={UNDEFINED,0,0,false};
struct CounterImplementation c6={UNDEFINED,0,0,false};
struct CounterImplementation c7={UNDEFINED,0,0,false};
struct CounterImplementation c8={UNDEFINED,0,0,false};
static Counter counterPark[COUNTER_COUNT]={&c1,&c2,&c3,&c4,&c5,&c6,&c7,&c8};

Counter new_counter(enum Direction direction)
{
  for (int i = 0; i < COUNTER_COUNT; i++) {
    if (counterPark[i]->is_used == false) {

      counterPark[i]->is_used = true;
      counterPark[i]->direction = direction;
      return counterPark[i];
    }
  }
  return 0;
}

void init()
{
  for (int i = 0; i < COUNTER_COUNT; i++) {
    counterPark[i]->is_used = false;
    counterPark[i]->direction = UNDEFINED;
    counterPark[i]->increment_value = 1;
    counterPark[i]->value = 0;
  }

}

void set_direction(Counter c, enum Direction direction)
{
  c->direction = direction;
}

void set_increment_value(Counter c, int value)
{
  if (value>=0) {
    c->increment_value = value;
  }
}

bool set_value(Counter c, int value)
{
  if (c->direction == DOWN) {
    c->value = value;
    return true;
  }
  return false;
}

void increment(Counter c)
{
  if (c->direction == UP) {
    c->value += c->increment_value;
  }
  if (c->direction == DOWN) {
    c->value -= c->increment_value;
  }
}

int get_value(Counter c)
{
  return c->value;
}

int get_increment_value(Counter c)
{
  return c->increment_value;
}

enum Direction get_direction(Counter c)
{
  return c->direction;
}
