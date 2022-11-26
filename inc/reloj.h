#include <stdint.h>
#include <stdbool.h>

typedef struct reloj_s * reloj_t;

reloj_t CrearReloj(uint16_t ticks_por_segundo);

bool TraerHoraReloj(reloj_t reloj, uint8_t * tiempo, uint8_t size);

void ConfigurarReloj(reloj_t reloj, uint8_t const * const tiempo, uint8_t size);

void NuevoTickReloj(reloj_t reloj);