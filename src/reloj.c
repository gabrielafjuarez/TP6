#include "reloj.h"
#include <string.h>

#define SIZE_TIEMPO 6
#define VALOR_INICIAL 0
#define UNIDAD_SEGUNDOS 5

struct reloj_s{
    bool valida;
    uint16_t ticks_por_segundo;
    uint16_t cuenta_ticks;
    uint8_t tiempo[SIZE_TIEMPO];
};

static struct reloj_s instancias;

//pongo la hora en cero
reloj_t CrearReloj(uint16_t ticks_por_segundo){
    instancias.valida = false;
    instancias.ticks_por_segundo = ticks_por_segundo;
    instancias.cuenta_ticks =0;
    memset(instancias.tiempo, VALOR_INICIAL, SIZE_TIEMPO);
    return &instancias;
}

bool TraerHoraReloj(reloj_t reloj, uint8_t * tiempo, uint8_t size){
    memcpy(tiempo, reloj->tiempo, size);
    return reloj->valida;
}

void ConfigurarReloj(reloj_t reloj, uint8_t const * const tiempo, uint8_t size){
    memcpy(reloj->tiempo, tiempo, size);
    reloj->valida = true;
}

void NuevoTickReloj(reloj_t reloj){
    reloj->cuenta_ticks++;
    if(reloj->cuenta_ticks == reloj->ticks_por_segundo){
        reloj->cuenta_ticks =0;
        reloj->tiempo[UNIDAD_SEGUNDOS]++;//los segundos estan en el 5to lugar del arreglo
        if (reloj->tiempo[UNIDAD_SEGUNDOS] == 10){
            reloj->tiempo[UNIDAD_SEGUNDOS] = 0;
            reloj->tiempo[4]++;
        }
    }
}