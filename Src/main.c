/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>

void SVC_Handler_c(uint32_t* pBaseOfStackFrame);

int32_t addNums(int32_t x, int32_t y) {
	int32_t res;
	__asm volatile("MOV %0,R0": "=r"(res) ::);
	__asm volatile("SVC #36");
	return res;
}

int32_t subNums(int32_t x, int32_t y) {
	uint32_t res;
	__asm volatile("MOV %0,R0": "=r"(res) ::);
	__asm volatile("SVC #37");
	return res;

}

int32_t mulNums(int32_t x, int32_t y) {
	int32_t res;
	__asm volatile("MOV %0,R0": "=r"(res) ::);
	__asm volatile("SVC #38");
	return res;
}

int32_t divNums(int32_t x, int32_t y) {
	int32_t res;
	__asm volatile("MOV %0,R0": "=r"(res) ::);
	__asm volatile("SVC #39");
	return res;
}

int main(void)
{
	int32_t result;

	result = addNums(40, 20);
	printf("Result of Addition: %ld", result);

	result = subNums(40, 20);
	printf("Result of Subtraction: %ld", result);

	result = mulNums(40, 20);
	printf("Result of Multiplication: %ld", result);

	result = divNums(40, 20);
	printf("Result of Division: %ld", result);

    /* Loop forever */
	for(;;);
}

__attribute__ ((naked)) void SVC_Handler() {
	__asm volatile("MRS R0, MSP"); //Stores value of MSP in R0
	__asm volatile("B SVC_Handler_c"); //Branches to other SVC_Handler with R0 as parameter
}

void SVC_Handler_c(uint32_t* pBaseOfStackFrame) {
	printf("In the SVC_Handler");

	int32_t arg0, arg1, res;

	uint8_t* pReturnAddr = (uint8_t*) pBaseOfStackFrame[6]; //Address of pc which points to the next instruction After SVC Exception

	pReturnAddr -=2; //Decrement to find instruction address of SVC Exception

	uint8_t SVC_num = *pReturnAddr; //Number of SVC Exception (Least Significant Byte of OpCode)

	printf("The SVC number is : %d\n", SVC_num);

	arg0 = pBaseOfStackFrame[0]; //Value of r0;
	arg1 = pBaseOfStackFrame[1]; //Value of r1;

	switch(SVC_num) {
	case 36:
		res = arg0 + arg1;
		break;
	case 37:
		res = arg0 - arg1;
		break;
	case 38:
		res = arg0 * arg1;
		break;
	case 39:
		res = arg0 / arg1;
		break;
	default:
		printf("Error");
	}

	pBaseOfStackFrame[0] = res; //
}
