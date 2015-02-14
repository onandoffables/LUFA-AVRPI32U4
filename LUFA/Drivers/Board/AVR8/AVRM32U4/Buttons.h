/*
             LUFA Library
     Copyright (C) Dean Camera, 2011.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2011  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *  \brief Board specific Buttons driver header for the AVRM32U4.
 *  \copydetails Group_Buttons_AVRM32U4
 *
 *  \note This file should not be included directly. It is automatically included as needed by the Buttons driver
 *        dispatch header located in LUFA/Drivers/Board/Buttons.h.
 */

/** \ingroup Group_Buttons
 *  \defgroup Group_Buttons_AVRM32U4 AVRM32U4
 *  \brief Board specific Buttons driver header for the AVRM32U4.
 *
 *  Board specific Buttons driver header for the AVRM32U4.
 *
 *  @{
 */

#ifndef __BUTTONS_AVRM32U4_H__
#define __BUTTONS_AVRM32U4_H__

	/* Includes: */
		#include "../../../LUFA/Common/Common.h"

	/* Enable C linkage for C++ Compilers: */
		#if defined(__cplusplus)
			extern "C" {
		#endif

	/* Preprocessor Checks: */
		#if !defined(__INCLUDE_FROM_BUTTONS_H)
			#error Do not include this file directly. Include LUFA/Drivers/Board/Buttons.h instead.
		#endif

	/* Public Interface - May be used in end-application: */
		/* Macros: */
			#define BUTTON_MASK          ((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7))
			#define BUTTON2_MASK         ((1 << 6) | (1 << 7))
			#define BUTTON3_MASK         ((1 << 6) | (1 << 7))
			
			/** Button mask for the buttons on the board. */
			#define BUTTONS_BUTTON1      (1 << 0)
			#define BUTTONS_BUTTON2      (1 << 1)
			#define BUTTONS_BUTTON3      (1 << 2)
			#define BUTTONS_BUTTON4      (1 << 3)
			#define BUTTONS_BUTTON5      (1 << 4)
			#define BUTTONS_BUTTON6      (1 << 5)
			#define BUTTONS_BUTTON7      (1 << 6)
			#define BUTTONS_BUTTON8      (1 << 7)
			
			// buttons2
			#define BUTTONS_BUTTON9      (1 << 6)
			#define BUTTONS_BUTTON10     (1 << 7)
			
			// buttons3
			#define BUTTONS_BUTTON11     (1 << 6)
			#define BUTTONS_BUTTON12     (1 << 7)
			

		/* Inline Functions: */
		#if !defined(__DOXYGEN__)
			static inline void Buttons_Init(void)
			{
				DDRB  &= ~BUTTON_MASK;
				PORTB |=  BUTTON_MASK;
				
				DDRF  &= ~BUTTON2_MASK;
				PORTF |=  BUTTON2_MASK;
				
				DDRC  &= ~BUTTON3_MASK;
				PORTC |=  BUTTON3_MASK;
			}

			static inline uint8_t Buttons_GetStatus(void) ATTR_WARN_UNUSED_RESULT;
			static inline uint8_t Buttons_GetStatus(void)
			{
				return (uint8_t)(~PINB & BUTTON_MASK);
			}
			
			static inline uint8_t Buttons2_GetStatus(void) ATTR_WARN_UNUSED_RESULT;
			static inline uint8_t Buttons2_GetStatus(void)
			{
				return (uint8_t)(~PINF & BUTTON2_MASK);
			}
			
			static inline uint8_t Buttons3_GetStatus(void) ATTR_WARN_UNUSED_RESULT;
			static inline uint8_t Buttons3_GetStatus(void)
			{
				return (uint8_t)(~PINC & BUTTON3_MASK);
			}
		#endif

	/* Disable C linkage for C++ Compilers: */
		#if defined(__cplusplus)
			}
		#endif

#endif

/** @} */

