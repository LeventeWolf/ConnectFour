#ifndef CONNECTFOUR_DEBUG_H
#define CONNECTFOUR_DEBUG_H

#ifdef DEBUG
#define debug_print(format, ...) printf(format, __VA_ARGS__)
#else
#define debug_print(...)
#endif

#endif //CONNECTFOUR_DEBUG_H
