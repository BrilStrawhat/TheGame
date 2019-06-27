#include "game.h"

pers *generate_valid_personage(pers *invalid_personage)
{
    pers *personage = generate_personage();
  
    while(!is_valid_personage(personage, invalid_personage))
    {
         free_personage(personage);
         personage = generate_personage();
    } 
    return personage;
}
