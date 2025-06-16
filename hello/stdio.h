/*
 *    SPDX-FileCopyrightText: 2025 João Pedro Gomes <joaop.gomes@usp.br>
 *   
 *    SPDX-License-Identifier: GPL-3.0-or-later
 *
 *  This file is a derivative of SYSeg (https://gitlab.com/monaco/syseg)
 *  and includes modifications made by the following author(s):
 *  João Pedro Gomes <joaop.gomes@usp.br>
 */

#ifndef E8_H
#define E8_H

void __attribute__((fastcall, naked)) printf(const char *); 
int __attribute__((fastcall, naked)) rtc_read(void); 

#endif	
