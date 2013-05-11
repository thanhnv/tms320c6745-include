/*
 * memories.h
 *
 *  Created on: May 7, 2013
 *      Author: NGUYEN
 */
 
#ifndef __COMMAND_H
#define __COMMAND_H

/* the Field MaKe macro */
#define FIELDMAKE(PER_REG_FIELD, val)                                         \
    (((val) << PER_REG_FIELD##_SHIFT) & PER_REG_FIELD##_MASK)
    
/* the Field EXTract macro */
#define FIELDEXTRACT(reg, PER_REG_FIELD)                                        \
    (((reg) & PER_REG_FIELD##_MASK) >> ##PER_REG_FIELD##_SHIFT)

/* the Field INSert macro */
#define FIELDINSERT(reg, PER_REG_FIELD, val)                                   \
    ((reg) = ((reg) & ~PER_REG_FIELD##_MASK)                          \
    | FIELDMAKE(PER_REG_FIELD, val))


/*
*	the "token" macros 
*/

/* the Field MaKe (Token) macro */
#define FIELDMAKETOKEN(PER_REG_FIELD, TOKEN)                                      \
    FIELDMAKE(PER_REG_FIELD, PER_REG_FIELD##_##TOKEN)

/* the Field INSert (Token) macro */
#define FIELDINSERTTOKEN(reg, PER_REG_FIELD, TOKEN)                                \
    FIELDINSERT((reg), PER_REG_FIELD, PER_REG_FIELD##_##TOKEN)


#endif
