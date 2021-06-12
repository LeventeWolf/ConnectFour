#ifndef CONNECTFOUR_DEBUG_H
#define CONNECTFOUR_DEBUG_H

#ifdef DEBUG
#define DEBUG 1
#define debug_printf(format, ...) printf(format, __VA_ARGS__)
#else
#define DEBUG 0
#define debug_printf(...)
#endif

#endif //CONNECTFOUR_DEBUG_H
