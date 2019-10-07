
/**********************************************************************
 *
 *      File Name	: OrionDaq_api.h
 *
 *      Revision	: 2013.07.xx
 *
 *      Version		: Ver 1.0
 *
 *      Author		: Soo-Hong Kim
 *
 *      E - Mail	: shkim@dewetron.co.kr
 *
 *
 *      - Description -
 *
 *      The header file of OrionDaq API
 *
 *
 *		Copyright (C) Dewetron Korea, LTD.
 *
 **********************************************************************/
#ifndef __ORIONDAQ_API_H
#define __ORIONDAQ_API_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <wtypes.h>

#ifndef RT_IMPORT
    #define RT_IMPORT WINAPI
#endif


/********************************************************************************
 *
 *
 *              I. Definition of Parameters (�Ķ���� ����)
 *
 *
 ********************************************************************************/


/////////////////////////////////////////////////////////
//
// 1. Parameters for measurement setup
//    (���� ���� ���� ���� �Ķ����)
//
/////////////////////////////////////////////////////////

//----------------------------------------
// 1.1 Basic Setup Parameters
//     (���� ���� �ʼ� ���� �Ķ����)
//----------------------------------------

#define PARAM_MODE_BOARD				0x0f01			// Use to get the board state, or to set a board to the Stand-Alone mode.
														// (KOR: ���� ���� ���¸� �о���� ����, �Ǵ� ���� ������ Stand-Alone ���� �����ϱ� ���� ���)

#define PARAM_SAMPLERATE				0x0101			// Sampling Rate. This is used with PARAM_SAMPLERATE_DIVISOR.
														// (KOR: Sampling Rate. PARAM_SAMPLERATE_DIVISOR�� ���� ����)

#define PARAM_SCANSIZE					0x0102			// The number of samples for one DMA data transfer.
														// (KOR: ���� �������� ���� ũ��)

#define PARAM_SAMPLERATE_DIVISOR		0x0103			// Set the sample rate divsior for the real sample rate
														// This is used with PARAM_SAMPLERATE.
														// (KOR: PARAM_SAMPLERATE�� ���� ���� Sampling Rate ���� ���)

#define PARAM_DSAMPLERATE				0x0110			// Set the Real Sampling Rate (floating point type)
														// (KOR: ���� Sampling Rate (�ε� �Ҽ��� ���·� ���� �ѱ�))

#define PARAM_TIME_OUT					0x0a01			// Time-out interval in milliseconds.
														// (KOR: TimeOut ���� millisecond ������ ����)

#define PARAM_BUFFER_BLOCK_COUNT		0x0107			// The number of Blocks.
														// (KOR: ������ ���ۿ� ���� ������ ���ũ��)

#define PARAM_MAX_BUFFER_BLOCK_COUNT	0x0723			// The maximum number of Blocks. // ver2.0.0.6
														// (KOR: ������ �� �ִ� �ִ� ��� ũ��)




/////////////////////////////////////////////////////////
//
// 2. Parameters for ANALOG channel setup
//
/////////////////////////////////////////////////////////

//----------------------------------------
// 2.1 Sensed mode of Analog channel
//----------------------------------------
#define PARAM_USE_SENSE_MODE0			0x0511			// Sensed mode (CH0~7)
#define PARAM_USE_SENSE_MODE1			0x0512			// Sensed mode (CH8~15)
#define PARAM_USE_SENSE_MODE2			0x0513			// Sensed mode (CH16~23)
#define PARAM_USE_SENSE_MODE3			0x0514			// Sensed mode (CH24~31)


//----------------------------------------
// 2.2 Gain of Sensed mode of Analog channel
//----------------------------------------
// Can select one within MODE_GAIN_X1, MODE_GAIN_X2,MODE_GAIN_X4, and MODE_GAIN_X8
#define PARAM_SENSE_GAIN0				0x010a			// Gain of Sensed mode (CH0~7)
#define PARAM_SENSE_GAIN1				0x010b			// Gain of Sensed mode (CH8~15)
#define PARAM_SENSE_GAIN2				0x010c			// Gain of Sensed mode (CH16~23)
#define PARAM_SENSE_GAIN3				0x010d			// Gain of Sensed mode (CH24~31)


/////////////////////////////////////////////////////////
//
// 3. Parameters for COUNTER channel setup
//
/////////////////////////////////////////////////////////

//----------------------------------------
// 3.1 Reset Counter channel
//----------------------------------------
#define PARAM_CTR_RESET					0x0552			// Reset the value of Counter Channel
														// (KOR: ���õ� ī���� ä���� ���� ���� 0���� �ʱ�ȭ)


//ver2.0.0.4.super - for super counter (only for Orion-0816-5M/10M) >
//----------------------------------------
// 3.2 For Adjustable counter & Super Counter
//----------------------------------------
#define PARAM_SUPPORT_ADJ_CTR			0x0600			// Use to check if a board supports the adjustable counter or not
														// (KOR: Adjustable Counter ����� ���� ���θ� Ȯ���ϴµ� ���)

#define PARAM_SUPPORT_SUPER_CTR			0x0601			// Use to check if a board supports the super counter or not
														// (KOR: Super Counter ����� ���� ���θ� Ȯ���ϴµ� ���)

#define PARAM_MAX_SUB_CTR_CHANNELS		0x0602			// Use to get the number of sub counter channel of super counter
														// (KOR: Super Counter �� Sub counter ä�μ��� ��µ� ���)
//ver2.0.0.4.super - for super counter (only for Orion-0816-5M/10M) <




/////////////////////////////////////////////////////////
//
// 4. Parameters for DIGITAL channel setup
//
/////////////////////////////////////////////////////////
#define PARAM_USE_DIO_OUTPUT			0x0515			// Digital Channel mode : setup to input or output mode
														// (KOR: Digital Out ��뿩�� ����(DI CH8~15))




/////////////////////////////////////////////////////////
//
// 5. Parameters for External Clock setup
//
/////////////////////////////////////////////////////////
#define PARAM_USE_EXT_CLOCK				0x0502			// Select External Clock
														// (KOR: �ܺ� Ŭ���� ����Ͽ� ADC Clock���� ��������� ���θ� ����)

#define PARAM_EXT_CLOCK_MODE			0x020c			// Select a source signal and a polarity of External Clock
														// (KOR: �ܺ� Ŭ���� Source signal�� Polarity�� ����)

#define PARAM_EXT_CLOCK_DIVISOR			0x020a			// Setup the divisor value of External Clock.
														// (KOR: EXT_CLOCK ������ Source Clock�� ����� �� Divisor �� ����)



/////////////////////////////////////////////////////////
//
// 6. Parameters for External Trigger setup
//
/////////////////////////////////////////////////////////
#define PARAM_USE_EXT_TRIGGER			0x0501			// Select External Trigger
														// (KOR: �ܺ� Ʈ���Ÿ� ������� ���� ����)

#define PARAM_EXT_TRIGGER_MODE			0x0106			// Select Input/Output mode, Timebase and Polarity of External Trigger
														// (KOR: �ܺ� Ʈ���� ���� Input/Output, Timebase, Polarity ����)




/////////////////////////////////////////////////////////
//
// 7. Parameters for External Clock Out 1, 2 setup
//
/////////////////////////////////////////////////////////

//----------------------------------------
// 7.1 Use of External Clock Out
//----------------------------------------
#define PARAM_USE_CLKOUT0				0x0506			// Use External Clock Out1 (EXT_CLK1)
														// (KOR: EXT_CLK1 �� ��뿩�θ� ����)

#define PARAM_USE_CLKOUT1				0x0507			// Use External Clock Out2 (EXT_CLK2)
														// (KOR: EXT_CLK2 �� ��뿩�θ� ����)

//----------------------------------------
// 7.2 External Clock Out mode
//----------------------------------------
#define PARAM_CLKOUT0_MODE				0x0202			// Select the Polarity of External Clock Out1
														// (KOR: EXT_CLK1 ������ Source Clock�� ����� �� Polarity ����)
#define PARAM_CLKOUT1_MODE				0x0207			// Select the Polarity of External Clock Out2
														// (KOR: EXT_CLK2 ������ Source Clock�� ����� �� Polarity ����)

//----------------------------------------
// 7.3 Divisor of External Clock Out
//----------------------------------------
#define PARAM_CLKOUT0_DIVISOR			0x0201			// Setup the divisor value of External Clock Out1.
														// (KOR: EXT_CLK1 ������ Source Clock�� ����� �� Divisor �� ����)

#define PARAM_CLKOUT1_DIVISOR			0x0206			// Setup the divisor value of External Clock Out2.
														// (KOR: EXT_CLK2 ������ Source Clock�� ����� �� Divisor �� ����)




/////////////////////////////////////////////////////////
//
// 8. Parameters for the Clock Out 0, 1 setup of Expansion Counter Board
//
/////////////////////////////////////////////////////////

//----------------------------------------
// 8.1 Use of Clock Out of Expansion Counter Board
//----------------------------------------
#define PARAM_USE_CTR_CLKOUT0			0x0526			// Use Clock Out0 of Expansion Counter Board
														// (KOR: Ȯ�� ī���� ������ EX_OUT0 ���� ������� ���� ����)

#define PARAM_USE_CTR_CLKOUT1			0x0527			// Use Clock Out1 of Expansion Counter Board
														// (KOR: Ȯ�� ī���� ������ EX_OUT1 ���� ������� ���� ����)

//----------------------------------------
// 8.2 Clock Out mode of Expansion Counter Board
//----------------------------------------
#define PARAM_CTR_CLKOUT0_MODE			0x0213			// Select the source of Clock Out0 of Expansion Counter Board
														// (KOR: Ȯ�� ī���� ������ EX_OUT0�� Clock Source ����)

#define PARAM_CTR_CLKOUT1_MODE			0x0223			// Select the source of Clock Out1 of Expansion Counter Board
														// (KOR: Ȯ�� ī���� ������ EX_OUT1�� Clock Source ����)

//----------------------------------------
// 8.3 Divisor of Clock Out of Expansion Counter Board
//----------------------------------------
#define PARAM_CTR_CLKOUT0_DIVISOR_HIGH	0x0211			// Divisor of the High period of Clock Out0 pulse of Expansion Counter Board
														// (KOR: Ȯ�� ī���� ������ EX_OUT0���� ��ȣ��� �� �޽��� High �ð��� Divisor �� ����)

#define PARAM_CTR_CLKOUT1_DIVISOR_HIGH  0x0221			// Divisor of the High period of Clock Out1 pulse of Expansion Counter Board
														// (KOR: Ȯ�� ī���� ������ EX_OUT1���� ��ȣ��� �� �޽��� High �ð��� Divisor �� ����)

#define PARAM_CTR_CLKOUT0_DIVISOR_LOW	0x0212			// Divisor of the Low period of Clock Out0 pulse of Expansion Counter Board
														// (KOR: Ȯ�� ī���� ������ EX_OUT0���� ��ȣ��� �� �޽��� Low �ð��� Divisor �� ����)

#define PARAM_CTR_CLKOUT1_DIVISOR_LOW   0x0222			// Divisor of the Low period of Clock Out1 pulse of Expansion Counter Board
														// (KOR: Ȯ�� ī���� ������ EX_OUT1���� ��ȣ��� �� �޽��� Low �ð��� Divisor �� ����)




/////////////////////////////////////////////////////////
//
// 9. Parameters for CAN
//
/////////////////////////////////////////////////////////

//----------------------------------------
// 9.1 CAN Polling Time
//----------------------------------------
#define PARAM_CAN_POLLING_TIME			0x0553			// Polling time to read CAN Data (KOR: CAN �����͸� ��ٸ��� �ð� ����)

//----------------------------------------
// 9.2 CAN Error Check
//----------------------------------------
#define PARAM_CAN0_ERROR_FLAG			0x0700			// Error flag of CAN0 (KOR: CAN 0 ��Ʈ�� ���� �÷��׸� �о��)
#define PARAM_CAN1_ERROR_FLAG			0x0701			// Error flag of CAN1 (KOR: CAN 1 ��Ʈ�� ���� �÷��׸� �о��)
#define PARAM_CAN0_ERROR_COUNT			0x0702			// The number of error of CAN0 (KOR: CAN 0 ��Ʈ�� ������ ���� ������ �о��)
#define PARAM_CAN1_ERROR_COUNT			0x0703			// The number of error of CAN1 (KOR: CAN 1 ��Ʈ�� ������ ���� ������ �о��)




/////////////////////////////////////////////////////////
//
// 10. Parameters for Update
//
/////////////////////////////////////////////////////////
#define PARAM_UPDATE_ALL				0				// Update all the parameters
														// (KOR: ��� �Ķ���� �׷��� �����Ŵ)

#define PARAM_UPDATE_CLKOUT				0x0001			// Update the parameters of Clock Out 0, 1
														// (KOR: ClockOut0, ClockOut1 ���� ������ ����)

#define PARAM_UPDATE_EXT_CLOCK			0x0002			// Update the parameters of External Clock
														// (KOR: �ܺ� Ŭ���� ������ ����)

#define PARAM_UPDATE_CTR_CONTROL		0x0004			// Update the Reset of Counter channel(Update PARAM_CTR_RESET)
														// (KOR: PARAM_CTR_RESET ���� ����)

#define PARAM_UPDATE_CHANNEL_AI			0x0008			// Update the properties of AI Channel
														// (KOR: AI Channel �Ӽ� ���� ����)

#define PARAM_UPDATE_ADJ				0x0010			// Update the properties of Adjustable Counter
														// (KOR: Adjustable Counter ���� ����)




/////////////////////////////////////////////////////////
//
// 11. Parameters for Error Handling
//
/////////////////////////////////////////////////////////
#define PARAM_LAST_ERROR				0x0a02			// Read Error Code
														// (KOR: API ������ �߻��ϸ� �ش� �����ڵ带 �о��)










/********************************************************************************
 *
 *
 *                II. Definition of Mode Constants (MODE ��� ����)
 *
 *
 ********************************************************************************/

//##################################################
//
// 1. Genernal Constants
//
//##################################################

//----------------------------------------------
// 1.1 Model Number (���� �� ��ȣ)
//----------------------------------------------

//++++++++++++++++++++++++++++++++++
// Structure : BOARD_SPEC_INFO
//----------------------------------
//     @ variable name - ModelNo
//++++++++++++++++++++++++++++++++++

// DEWE-ORION-1616-10x Series
#define BOARD_ORION_1616_100            0x1110      // OROIN-1616-100
#define BOARD_ORION_1616_101            0x1111      // ORION-1616-100, CAN
#define BOARD_ORION_1616_102            0x1112      // ORION-1616-100, EXP-CNT8-TTL
#define BOARD_ORION_1616_103            0x1113      // ORION-1616-100, CAN, EXP-CNT8-TTL
#define BOARD_ORION_1616_104            0x1114      // ORION-1616-100, EXP-CNT8-ADJ
#define BOARD_ORION_1616_105            0x1115      // ORION-1616-100, CAN, EXP-CNT8-ADJ
#define BOARD_ORION_3216_100            0x2110      // OROIN-3216-100, EXP-AIN16
#define BOARD_ORION_3216_101            0x2111      // ORION-3216-100, CAN, EXP-AIN16

// DEWE-ORION-1616-50x Series
#define BOARD_ORION_1616_500            0x1120      // OROIN-1616-500
#define BOARD_ORION_1616_501            0x1121      // ORION-1616-500, CAN
#define BOARD_ORION_1616_502            0x1122      // ORION-1616-500, EXP-CNT8-TTL
#define BOARD_ORION_1616_503            0x1123      // ORION-1616-500, CAN, EXP-CNT8-TTL
#define BOARD_ORION_1616_504            0x1124      // ORION-1616-500, EXP-CNT8-ADJ
#define BOARD_ORION_1616_505            0x1125      // ORION-1616-500, CAN, EXP-CNT8-ADJ

// DEWE-ORION-0816-100x Series
#define BOARD_ORION_0816_1000           0x1140      // OROIN-0816-1000
#define BOARD_ORION_0816_1001           0x1141      // ORION-0816-1000, CAN
#define BOARD_ORION_0816_1002           0x1142      // ORION-0816-1000, EXP-CNT8-TTL
#define BOARD_ORION_0816_1003           0x1143      // ORION-0816-1000, CAN, EXP-CNT8-TTL
#define BOARD_ORION_0816_1004           0x1144      // ORION-0816-1000, EXP-CNT8-ADJ
#define BOARD_ORION_0816_1005           0x1145      // ORION-0816-1000, CAN, EXP-CNT8-ADJ

// DEWE-ORION-1616-100x Series
#define BOARD_ORION_1616_1000			0x8140		// OROIN-1616-1000
#define BOARD_ORION_1616_1001			0x8141      // ORION-1616-1000, CAN
#define BOARD_ORION_1616_1002			0x8142		// ORION-1616-1000, EXP-CNT8-TTL
#define BOARD_ORION_1616_1003			0x8143		// ORION-1616-1000, CAN, EXP-CNT8-TTL
#define BOARD_ORION_1616_1004			0x8144		// ORION-1616-1000, EXP-CNT8-ADJ
#define BOARD_ORION_1616_1005			0x8145		// ORION-1616-1000, CAN, EXP-CNT8-ADJ

// DEWE-ORION-0816-5Mx Series (Preliminary)
#define BOARD_ORION_0816_5M				0x4190		// OROIN-0816-5M0
#define BOARD_ORION_0816_5M1			0x4191      // ORION-0816-5M0, CAN

// DEWE-ORION-0816-10Mx Series (Preliminary)
#define BOARD_ORION_0816_10M			0x41A0		// OROIN-0816-10M0
#define BOARD_ORION_0816_10M1			0x41A1      // ORION-0816-10M0, CAN


//----------------------------------------------
// 1.2 Constants of Bit Flags for Model Number
//     (���� �� ����� ��Ʈ�� ���� ���)
//----------------------------------------------

//++++++++++++++++++++++++++++++++++
// Structure : BOARD_SPEC_INFO
//----------------------------------
//     @ variable name - ModelNo
//++++++++++++++++++++++++++++++++++

#define BOARD_FLAG_CH16					0x1000			// The number of Analog channels is 16 (KOR: AI ä�� ���� 16��)
#define BOARD_FLAG_CH32					0x2000			// The number of Analog channels is 32 (KOR: AI ä�� ���� 32��)
#define BOARD_FLAG_CH08					0x4000			// The number of Analog channels is 8  (KOR: AI ä�� ����  8��)
#define BOARD_FLAG_CH16_1M				0x8000			// The number of Analog channels is 16 of ORION-1616-1000
														// (KOR: ORION-1616-1000�� AI ä�� ���� 16��)

#define BOARD_FLAG_RES16				0x0100			// Resolution 16 bit

#define BOARD_FLAG_SR100                0x0010			// Max Sample Rate 100kHz
#define BOARD_FLAG_SR500                0x0020			// Max Sample Rate 500kHz
#define BOARD_FLAG_SR1M                 0x0040			// Max Sample Rate 1MHz
#define BOARD_FLAG_SR5M                 0x0090			// Max Sample Rate 5MHz
#define BOARD_FLAG_SR10M				0x00A0			// Max Sample Rate 10MHz

#define BOARD_FLAG_CAN					0x0001			// Support CAN (KOR: CAN ���� ����)
#define BOARD_FLAG_CNT                  0x0002			// The number of TTL Counter channels is 8		  (KOR: CNT 8ä�� - TTL)
#define BOARD_FLAG_CNT_ADJ	            0x0004			// The number of Adjustable Counter channels is 8 (KOR: CNT 8ä�� - ADJ)


//----------------------------------------------
// 1.3 Constants for Board State
//     (������ ���� ���� Constants)
//----------------------------------------------

//++++++++++++++++++++++++++++++++++
// Structure : BOARD_PCI_INFO
//----------------------------------
//     @ variable name - BoardMode
//++++++++++++++++++++++++++++++++++

#define MODE_BOARD_STANDALONE			0x00010000		// Single mode (default)
														// (KOR: Single mode ���� �ش� ���忡 ����(Default))

#define MODE_BOARD_MASTER				0x00010001		// Master board in case of Multi mode
														// (KOR: Multi mode ���� ������ ���忡 ����)

#define MODE_BOARD_SLAVE				0x00010002		// Slave board in case of Multi mode, and the terminal switch is off
														// (KOR: Multi mode ���� ������ ����� Terminal Switch��
														//       On �Ǿ� �ִ� ���带 ������ ���忡 ����)

#define MODE_BOARD_SLAVE_TERM			0x00010003		// Slave board in case of Multi mode, and the terminal switch is on
														// (KOR: Multi mode ���� Terminal Switch�� On �Ǿ� �ִ� ���忡 ����)

#define MODE_BOARD_SLAVE_MASTER         0x00010004		// In the multi network system environment,
														// the first board of the each systems except the first and last system
														// (KOR: Network�� ���� �����, ù��°, ������ �ý����� ������
														//       �ý����� ù��° ���带 �����ͷ� ����)




//##################################################
//
// 2. Constants for ANALOG channel setup
//
//##################################################

//----------------------------------------------
// 2.1 Gain of Analog channel
//----------------------------------------------

//++++++++++++++++++++++++++++++++++
// Structure : BOARD_CHANNEL_PROP
//----------------------------------
//     @ variable name - Gain
//++++++++++++++++++++++++++++++++++
//
// &
//
//++++++++++++++++++++++++++++++++++
// Related parameter (���� �Ķ����) :
//----------------------------------
// PARAM_SENSE_GAIN0, 1, 2, 3
//++++++++++++++++++++++++++++++++++

#define MODE_GAIN_X1                    0x00
#define MODE_GAIN_X2                    0x01
#define MODE_GAIN_X4                    0x02
#define MODE_GAIN_X8                    0x03




//##################################################
//
// 3. Constants for COUNTER channel setup
//
//##################################################

//----------------------------------------------
// 3.1 Basic Constants for Counter channel setup
//----------------------------------------------

//++++++++++++++++++++++++++++++++++
// Structure : BOARD_CTR_CHANNEL
//----------------------------------
//     @ variable name - CounterKind
//++++++++++++++++++++++++++++++++++
// Counter Type

#define MODE_CTR_SIMPLE_EVENT			0x0000			// Simple Event mode
#define MODE_CTR_GATED_EVENT			0x0001			// Gated Event mode
#define MODE_CTR_TIMER					0x0002			// Timer mode
#define MODE_CTR_SPM					0x0003			// Single Period mode
#define MODE_CTR_SPM_ZERO				0x0004			// Single Period mode(Zero)
#define MODE_CTR_SPWM					0x0005			// Single Pulse Width mode
#define MODE_CTR_SPWM_ZERO				0x0006			// Single Pulse Width mode(Zero)
#define MODE_CTR_TSESM					0x0007			// Two Pulse Edge Separation mode
#define MODE_CTR_TSESM_ZERO				0x0008			// Two Pulse Width mode(Zero)
#define MODE_CTR_ENC_X1					0x0009			// Encoder Counter(X1 mode)
#define MODE_CTR_ENC_X2					0x000A			// Encoder Counter(X2 mode)
#define MODE_CTR_ENC_X4					0x000B			// Encoder Counter(X4 mode)
#define MODE_CTR_ENC_TWO_PLS			0x000C			// Encoder Counter(A-Up/B-Down)
#define MODE_CTR_ZERO_EVENT				0x000D			// Zero Event mode


//++++++++++++++++++++++++++++++++++
// Structure : BOARD_CTR_CHANNEL
//----------------------------------
//     @ variable name - AssignedAuxPin
//						 AssignedGatePin
//						 AssignedSourcePin
//++++++++++++++++++++++++++++++++++
// Basic Input Signal fo Counter

#define MODE_CTR_PIN_NONE				0x0000			// Not select (KOR: ���� ���� ���� ����)

#define MODE_CTR_PIN_SOURCE				0x0001			// Connect SOURCE signal to the specific counter pin
														// (KOR: ī������ �Է� ��ȣ�� SOURCE ������ �Է� ���� ��ȣ ���)

#define MODE_CTR_PIN_SOURCE_PAIR		0x0002			// Connect SOURCE signal of PAIR counter to specific counter pin
														// (KOR: ī������ �Է� ��ȣ�� PAIR ī������ SOURCE ������ �Է� ���� ��ȣ ���)

#define MODE_CTR_PIN_GATE				0x0003			// Connect GATE signal to the specific counter pin
														// (KOR: ī������ �Է� ��ȣ�� GATE ������ �Է� ���� ��ȣ ���)

#define MODE_CTR_PIN_GATE_PAIR			0x0004			// Connect GATE signal of PAIR counter to the specific counter pin
														// (KOR: ī������ �Է� ��ȣ�� PAIR ī������ GATE ������ �Է� ���� ��ȣ ���)

#define MODE_CTR_PIN_AUX				0x0005			// Connect AUX signal to the specific counter pin
														// (KOR: ī������ �Է� ��ȣ�� AUX ������ �Է� ���� ��ȣ ���)

#define MODE_CTR_PIN_AUX_PAIR			0x0006			// Connect AUX signal of PAIR counter to the specific counter pin
														// (KOR: ī������ �Է� ��ȣ�� PAIR ī������ AUX ������ �Է� ���� ��ȣ ���)

#define MODE_CTR_PIN_ADC_CLK			0x0009			// Connect AI Sampling Clock to the specific counter
														// (KOR: ī������ �Է� ��ȣ�� ADC Clock ���)


//++++++++++++++++++++++++++++++++++
// Structure : BOARD_CTR_CHANNEL
//----------------------------------
//     @ variable name - AssignedAuxPin
//++++++++++++++++++++++++++++++++++
// Internal 40, 20, 10 MHz Clock

#define MODE_CTR_PIN_TIMEBASE_40M		0x000A			// Connect inner 40MHz clock (KOR: ���� 40MHz Clock�� �Է½�ȣ�� ���)
#define MODE_CTR_PIN_TIMEBASE_20M       0x000B			// Connect inner 20MHz clock (KOR: ���� 20MHz Clock�� �Է½�ȣ�� ���)
#define MODE_CTR_PIN_TIMEBASE_10M       0x000C			// Connect inner 10MHz clock (KOR: ���� 10MHz Clock�� �Է½�ȣ�� ���)


//++++++++++++++++++++++++++++++++++
// Structure : BOARD_CTR_CHANNEL
//----------------------------------
//     @ variable name - AssignedAuxPin
//						 AssignedGatePin
//						 AssignedSourcePin
//++++++++++++++++++++++++++++++++++
// MUX signal

#define MODE_CTR_PIN_MUX_EXT_TRIG		0x0700			// Connect External Trigger signal to the specific counter
														// (KOR: ī������ �Է� ��ȣ�� �ܺ� Ʈ���� ��ȣ ���)

#define MODE_CTR_PIN_MUX_EXT_CLK		0x0800			// Connect External Clock signal the specific counter
														// (KOR: ī������ �Է� ��ȣ�� �ܺ� Ŭ�� ��ȣ ���)

#define MODE_CTR_PIN_MUX_OUT_CLK1		0x0900			// Connect EXT_CLK1 signal to the specific counter
														// (KOR: ī������ �Է� ��ȣ�� EXT_CLK1 ��ȣ ���)

#define MODE_CTR_PIN_MUX_OUT_CLK2		0x0A00			// Connect EXT_CLK2 signal to the specific counter
														// (KOR: ī������ �Է� ��ȣ�� EXT_CLK2 ��ȣ ���)

#define MODE_CTR_PIN_MUX_DI6			0x1600			// Connect DI 6 signal to the specific counter
														// (KOR: ī������ �Է� ��ȣ�� DI 6 �Է� ��ȣ ���)

#define MODE_CTR_PIN_MUX_DI7			0x1700			// Connect DI 7 signal to the specific counter
														// (KOR: ī������ �Է� ��ȣ�� DI 7 �Է� ��ȣ ���)


//++++++++++++++++++++++++++++++++++
// Structure : BOARD_CTR_CHANNEL
//----------------------------------
//     @ variable name - TransferMode
//++++++++++++++++++++++++++++++++++
// Transfer mode of Counter channel
// Set inner clock when use Single-Period, Single-Pulse Width, Two-Single Edge-Separation, Frequency(Timer).
//
// KOR: ���� Ŭ�� ����
//		Single-Period, Single-Pulse Width, Two-Single Edge-Separation, Frequency(Timer) ������ ���

#define MODE_CTR_TRANMODE_80M			0x0000			// inner 80MHz Clock
#define MODE_CTR_TRANMODE_40M			0x0001			// inner 40MHz Clock
#define MODE_CTR_TRANMODE_20M			0x0002			// inner 20MHz Clock
#define MODE_CTR_TRANMODE_10M			0x0003			// inner 10MHz Clock


//++++++++++++++++++++++++++++++++++
// Structure : BOARD_CTR_CHANNEL
//----------------------------------
//     @ variable name - FilterAuxPin
//						 FilterGatePin
//						 FilterSourcePin
//++++++++++++++++++++++++++++++++++
// Digital Filter

#define MODE_CTR_FILTER_BYPASS			0x0000			// No Digital Filtering
#define MODE_CTR_FILTER_LESS_100NS		0x0001			// 100ns Digital Filter
#define MODE_CTR_FILTER_LESS_200NS		0x0002			// 200ns Digital Filter
#define MODE_CTR_FILTER_LESS_500NS		0x0003			// 500ns Digital Filter
#define MODE_CTR_FILTER_LESS_1US		0x0004			// 1us Digital Filter
#define MODE_CTR_FILTER_LESS_2US		0x0005			// 2us Digital Filter
#define MODE_CTR_FILTER_LESS_4US		0x0006			// 4us Digital Filter
#define MODE_CTR_FILTER_LESS_5US		0x0007			// 5us Digital Filter




//ver2.0.0.4.super - for super counter (only for Orion-0816-5M/10M) >
//----------------------------------------------
// 3.2 Constants for Counter channel properties
//----------------------------------------------

//++++++++++++++++++++++++++++++++++
// Structure : BOARD_SUB_CTR_CHANNEL_ATTR
//----------------------------------
//     @ variable name - CtrSigType
//++++++++++++++++++++++++++++++++++
// Input Signal of Sub Counter

#define MODE_SUB_CTR_SIG_NONE			0x00			// No input signal of Sub Counter
														// (KOR: Sub ī���Ϳ� �Է� ��ȣ ����)

#define MODE_SUB_CTR_SIG_FILTER_SRC		0x01			// Filtered Source signal of Sub Counter
														// (KOR: Sub ī���Ϳ� filtered Source ��ȣ ���)

#define MODE_SUB_CTR_SIG_FILTER_GATE	0x02			// Filtered Gate signal of Sub Counter
														// (KOR: Sub ī���Ϳ� filtered Gate ��ȣ ���)

#define MODE_SUB_CTR_SIG_ENCODER_OUT	0x03			// Encoder Out signal of Sub Counter
														// (KOR: Sub ī���Ϳ� Encoder Out ��ȣ ���)


//++++++++++++++++++++++++++++++++++
// Structure : BOARD_SUB_CTR_CHANNEL_ATTR
//----------------------------------
//     @ variable name - CtrMode
//++++++++++++++++++++++++++++++++++
// Sub Counter Type

#define MODE_SUB_CTR_MOD_NO_USE			0x00			// Not select counter mode of Sub Counter
														// (KOR: Sub ī���� Ÿ���� �������� ����)

#define MODE_SUB_CTR_MOD_SINGLE_PERIOD	0x01			// Single Period mode of Sub Counter
														// (KOR: Sub ī���� Ÿ���� Single Period mode�� ����)

#define MODE_SUB_CTR_MOD_TWO_SIG_EDGE	0x02			// Two Pulse Edge Separation mode of Sub Counter
														// (KOR: Sub ī���� Ÿ���� Two Pulse Edge Separation mode�� ����)
//ver2.0.0.4.super - for super counter (only for Orion-0816-5M/10M) <




//##################################################
//
// 4. Constants for External Clock setup
//
//##################################################

//----------------------------------------------
// 4.1 External Clock mode
//
//		//**********************************
//		// EXT_CLOCK mode is the combination of
//		// <Input/Output mode>,
//		// Input mode's <Input Source> and <Signal Edge>,
//		// Output mode's <Output Source> and <Polarity>
//
//		// KOR: �ܺ� Ŭ���� ��� ������
//		//		<Input/Output mode>,
//		//		Input mode�� <Input Source> and <Signal Edge>,
//		//		Output mode�� <Input Source>, <Polarity>��
//		//		�������� �̷����
//		//**********************************
//
//		Related Parameter (���� �Ķ����) :
//
//		PARAM_EXT_CLOCK_MODE
//
//----------------------------------------------


//************************
// 4.1.1 Input/Output mode of External Clock
//************************

#define MODE_EXT_SET_INPUT				0x00100000		// Set Exeternal Clock signal as Input mode
														// (KOR: �ܺ� Ʈ���� ��ȣ�� �Է� ���� ����)

#define MODE_EXT_SET_OUTPUT				0x00100010		// Set Exeternal Clock signal as Output mode
														// KOR: �ܺ� Ʈ���� ��ȣ�� ��� ���� ����)


//************************
// 4.1.2 Properties of External Clock Input mode
//		 (�ܺ� Ŭ���� �Է� ��� �Ӽ� ����)
//************************

// Input source signal of External Clock Input
// (�ܺ� Ŭ�� �Է��� �Է� ��ȣ ����)

#define MODE_EXT_EXTERNAL_CLK_INPUT		0x00110000		// Set the EXT_CLK pin signal as the External Clock input source
														// (KOR: �ܺ� Ŭ���� �Է� ��ȣ�� EXT_CLK ���� ��ȣ�� ����)

#define MODE_EXT_INTER_SAMPLE_CLOCK		0x00120000		// Set the ADC sampling clock as the External Clock input source
														// (KOR: �ܺ� Ŭ���� �Է� ��ȣ�� ADC ���ø� Ŭ�� ��ȣ�� ����)


// Signal Edge of External Clock
// (�ܺ� Ŭ�� �Է� ��ȣ�� Edge ����)

#define MODE_EXT_CLOCK_POS_EDGE			0x00100000		// Positive Edge
#define MODE_EXT_CLOCK_NEG_EDGE			0x00100001		// Negative Edge
#define MODE_EXT_CLOCK_BOTH_EDGE		0x00100002		// Both Edge


//************************
// 4.1.3 Properties of External Clock Output mode
//		 (�ܺ� Ŭ���� ��� ��� �Ӽ� ����)
//************************

// Output source signal of External Clock Output
// (�ܺ� Ŭ�� ����� ��� ��ȣ ����)

#define MODE_EXT_OUTPUT_SEL_DO_INT_CLK	0x00100000		// Set the ADC sampling clock signal as the External Clock output source
														// (KOR: �ܺ� Ŭ���� ��� ��ȣ�� ADC ���ø� ��ȣ�� ����)

#define MODE_EXT_OUTPUT_SEL_CLKOUT0		0x01100000		// Set the "Ext Clock Out 1" signal as the External Clock output source
														// (KOR: �ܺ� Ŭ���� ��� ��ȣ�� "Ext Clock Out 1" ��ȣ�� ����)

#define MODE_EXT_OUTPUT_SEL_CLKOUT1		0x02100000		// Set the "Ext Clock Out 2" signal as the External Clock output source
														// (KOR: �ܺ� Ŭ���� ��� ��ȣ�� "Ext Clock Out 2" ��ȣ�� ����)


// Polarity for External Clock Output
// (�ܺ� Ŭ�� ��� ��ȣ�� polarity ����)

#define MODE_EXT_OUTPUT_NORMAL			0x00100000		// Same polarity as the selected clock signal
														// (KOR: ���õ� Ŭ�� ��°� ���� polarity�� ����ϴ� ���)

#define MODE_EXT_OUTPUT_REVERSE			0x00100100		// Reversed polarity as the selected clock signal
														// (KOR: ���õ� Ŭ�� ��¿� reverse�� polarity�� ����ϴ� ���)

#define MODE_EXT_OUTPUT_CONST_LOW		0x00100200		// Low level signal

#define MODE_EXT_OUTPUT_CONST_HIGH		0x00100300		// High level signal




//##################################################
//
// 5. Constants for External Trigger setup
//
//##################################################

//----------------------------------------------
// 5.1 External Trigger mode
//
//		//**********************************
//		// EXT_TRIG mode is the combination of
//		// <Input/Output mode>,
//		// Input mode's <Start Sel mode>,
//		// Output mode's <Polarity>
//
//		// KOR: �ܺ� Ʈ������ ��� ������
//		//		<Input/Output mode>,
//		//		Input mode�� <Start Sel mode>,
//		//		Output mode�� <Polarity>��
//		//		�������� �̷����
//		//**********************************
//
//		Related parameter (���� �Ķ����) :
//
//		PARAM_EXT_TRIGGER_MODE
//
//----------------------------------------------

//************************
// 5.1.1 Input/Output mode of External Trigger
//************************

// Use "MODE_EXT_SET_INPUT", "MODE_EXT_SET_OUTPUT"
// in "4.1.1 Input/Output mode of External Clock".
//
// KOR: "4.1.1 Input/Output mode of External Clock"���� �����
//		"MODE_EXT_SET_INPUT", "MODE_EXT_SET_OUTPUT" ���


//************************
// 5.1.2 Properties of External Trigger Input mode
//		 (�ܺ� Ʈ������ �Է� ��� �Ӽ� ����)
//************************

// Start mode of Trigger Input
// (Ʈ���� �Է��� ���� ��� ����)

#define MODE_ACQ_START_MASK				0x0002000F		//
#define MODE_ACQ_START_POS_GATED		0x00020000		// Start acquistion when Trigger signal is High state (Positive Gated Start : default)
														// (KOR: Ʈ���� ��ȣ�� High(active)�� ���� ����(�⺻��))

#define MODE_ACQ_START_NEG_GATED		0x00020001		// Start acquistion when Trigger signal is Low state (Negative Gated Start : default)
														// (KOR: Ʈ���� ��ȣ�� Low(deactive)�� ���� ����(�⺻��))

#define MODE_ACQ_START_POS_EDGE			0x00020002		// Start acquistion when Trigger signal is changed from low to high (Positive Edge)
														// (KOR: Ʈ���� ��ȣ�� low���� high�� ����� �� Ʈ���ŷ� �ν��ϰ� ��������)

#define MODE_ACQ_START_NEG_EDGE			0x00020003		// Start acquistion when Trigger signal is changed from high to low (Negative Edge)
														// (KOR: Ʈ���� ��ȣ�� high���� low�� ����� �� Ʈ���ŷ� �ν��ϰ� ��������)

#define MODE_ACQ_START_BOTH_EDGE		0x00020004		// Start acquistion when Trigger signal is changed from high to low or vice versa (Both Edge)
														// (KOR: Ʈ���� ��ȣ�� high���� low �Ǵ� low���� high�� ����� �� Ʈ���ŷ� �ν��ϰ� ��������)


//************************
// 5.1.3 Properties of External Trigger Output mode
//		 (�ܺ� Ʈ������ ��� ��� �Ӽ� ����)
//************************

// Polarity of External Trigger Output
// Use "MODE_EXT_OUTPUT_NORMAL", "MODE_EXT_OUTPUT_REVERSE"
// among "Polarity" of "4.1.3 Properties of External Clock Output mode".
//
// KOR: "4.1.3 Properties of External Clock Output mode"�� "Polarity"��
//		��� �߿��� "MODE_EXT_OUTPUT_NORMAL", "MODE_EXT_OUTPUT_REVERSE" ���




//##################################################
//
// 6. Constants for External Clock Out 1, 2 setup
//
//##################################################

//----------------------------------------------
// 6.1 External Clock Out 1, 2 mode
//
//		//************************************
//		// EXT_CLOCK1,2 mode is the combination
//		// of <Timebase Input Source>, <Polarity>
//		// and <Asynch. mode>
//		//
//		// KOR: EXT_CLOCK1,2�� mode ������
//		// <Timebase Input Source>, <Polarity>,
//		// <Asynch. mode>�� �������� �̷����
//		//************************************
//
//		Related Parameter (���� �Ķ����) :
//
//		PARAM_CLKOUT0_MODE,
//		PARAM_CLKOUT1_MODE
//
//----------------------------------------------

// Timebase Input Source of External Clock Output

#define MODE_CLOCK_TIMEBASE_ADC_CLK		0x00080000		// ADC sampling clock for External Clock Output
#define MODE_CLOCK_TIMEBASE_80M			0x00080100		// 80MHz clock with divisor for External Clock Output


// Polarity of External Clock Out 1, 2

#define MODE_CLKOUT_NORMAL				0x00200000		// Same polarity as the selected clock signal
														// (KOR: ���õ� Ŭ�� ��°� ���� polarity�� ����ϴ� ���)

#define MODE_CLKOUT_REVERSE				0x00200001		// Reversed polarity as the selected clock signal
														// (KOR: ���õ� Ŭ�� ��¿� reverse�� polarity�� ����ϴ� ���)

#define MODE_CLKOUT_CONST_LOW			0x00200002		// Low level signal
#define MODE_CLKOUT_CONST_HIGH			0x00200003		// High level signal


// Asynchronization mode of Clock Out
// (Clock Out �񵿱� ��� ����)

#define MODE_CLOCK_ASYNC_NONE			0x00080000		// Synchronized signal of "Clock Out" with ADC clock (Default)
														// (KOR: ADC Ŭ���� ����ȭ�� Ŭ�� ��� (�⺻��))

#define MODE_CLOCK_ASYNC_ENABLE			0x00081000		// Asynchronized signal of "Clock Out" with ADC clock
														// (KOR: ADC Ŭ���� �񵿱�ȭ�� Ŭ�� ���)




//##################################################
//
// 8. Constants for Counter Clock Out setup of Expansion Counter Board
//
//##################################################

//----------------------------------------------
// 8.1 Counter Clock Out mode of Expansion Counter Board
//
//		Related Parameter (���� �Ķ����) :
//
//		PARAM_CTR_CLKOUT0_MODE,
//		PARAM_CTR_CLKOUT1_MODE
//
//----------------------------------------------

#define MODE_CTR_CLKOUT_SOURCE_DI_SCLK			0x00	// Use Sampling Clock x 64 for the source signal of "Counter Clock Out"
														// (KOR: "Counter Clock Out"�� Source ��ȣ�� Sampling Clock x 64�� ��ȣ ���)

#define MODE_CTR_CLKOUT_SOURCE_TIMEBASE_80M		0x01	// Use inner 80MHz Clock for the source signal of "Counter Clock Out"
														// (KOR: "Counter Clock Out"�� Source ��ȣ�� ���� 80MHz Clock ���)

#define MODE_CTR_CLKOUT_START_HIGH				0x02	// Start with High level signal
														// (KOR: "Counter Clock Out"�� ����� High Level���� �����ϵ��� ����)




//##################################################
//
// 9. Constants for CAN
//
//##################################################

//----------------------------------------------
// 9.1 CAN mode
//----------------------------------------------

//++++++++++++++++++++++++++++++++++
// Structure : BOARD_CAN_PROP
//----------------------------------
//     @ variable name - Sync_100K
//						 Sync_AI
//++++++++++++++++++++++++++++++++++

#define MODE_CAN_SYNC_100K				0x00800001		// Sync 100K
#define MODE_CAN_SYNC_AI				0x00800002		// Sync AI




//##################################################
//
// 10. Constants for Error Handling
//
//##################################################

//----------------------------------------------------------------------------
// 10.1 Error Codes Constants
//
//		Related Parameter (���� �Ķ����) :
//
//		PARAM_LAST_ERROR
//
//----------------------------------------------------------------------------

#define ERR_NONE						0				// No error
#define ERR_BOARD_NOT_FOUND				0x0101			// Cannot find DEWE-ORION Board		(KOR: DEWE-ORION Board�� ã�� ����)
#define ERR_BOARD_NOT_OPEN				0x0102			// Cannot open DEWE-ORION Board		(KOR: DEWE-ORION Board�� ���� �� �� ����)
#define ERR_BOARD_NOT_MASTER			0x0103			// Not set Master board				(KOR: Master ���尡 �����Ǿ� ��������)

#define ERR_DAQ_ALREADY_STARTED			0x0201			// RtStart() is already started		(KOR: RtStart() �Լ��� �̹� ����Ǿ���)
#define ERR_DAQ_NOT_STARTED				0x0202			// RtStart() is not started			(KOR: RtStart() �Լ��� ���۵Ǿ� ���� ����)
#define ERR_DAQ_CHANNEL_NOT_ASSIGNED	0x0203			// Channel is not assigned			(KOR: ������ ä���� ��ϵǾ� ���� ����)
#define ERR_DAQ_CANNOT_CONFIGURE		0x0204			// Cannot configure a board			(KOR: ���忡 ���������� �� �� ����)
#define ERR_DAQ_CANNOT_START			0x0205			// Cannot run RtStart()				(KOR: RtStart() �Լ��� ������ �� ����)
#define ERR_DAQ_CANNOT_UPDATE_CALINFO   0x0206			// Cannot update "CalInfo"			(KOR: CalInfo�� ������Ʈ �� �� ����)
#define ERR_DAQ_CANNOT_ASSIGN_MASTER    0x0207			// Cannot assign a board as a master. (used only for the Slave Master system)
														//									(KOR: ���带 �����ͷ� ������ �� ����. �����̺�/������ �ý��ۿ����� ����)

#define ERR_INVALID_BOARD_NO			0x0301			// Invalid board number				(KOR: �߸��� ���� ��ȣ)
#define ERR_INVALID_CHANNEL_NO			0x0302		    // Invalid channel number			(KOR: �߸��� ä�� ��ȣ)
#define ERR_INVALID_CHANNEL_COUNT		0x0303			// Invalid the number of channels	(KOR: �߸��� ä�μ��� ������)
#define ERR_INVALID_VALUE				0x0304			// Invalid parameter value			(KOR: �߸��� �Ķ���� ������)
#define ERR_INVALID_PARAM_ID			0x0305			// Invalid parameter ID				(KOR: �߸��� �Ķ���� ID)
#define ERR_INVALID_IOCTL				0x0306			// Invalid IOCTL					(KOR: �߸��� IOCTL �ڵ���)
#define ERR_NOT_SUPPORTED_FUNCTION		0x0307			// Not supported function			(KOR: �����Ǵ� �Լ��� �ƴ�)

#define ERR_DMA_CANNOT_OPEN				0x0401			// Cannot open DMA					(KOR: DMA�� ���� ����)
#define ERR_DMA_CANNOT_START			0x0402		    // Cannot start DMA					(KOR: DMA ������ ������ �� ����)

#define ERR_CAN_NOT_OPEN				0x0405			// Cannot open CAN					(KOR: CAN�� ������ �� ����)
#define ERR_CAN_CANNOT_START			0x0406			// Cannot start CAN					(KOR: CAN�� ������ �� ����)

#define ERR_MEM_BUFFER_NOT_ASSIGNED		0x0701			// Not assigned DMA buffer			(KOR: �����޸𸮰� �Ҵ� �Ǿ����� ����)
#define ERR_MEM_INVALID_BLOCK_COUNT		0x0702			// Invalid the number of Blocks		(KOR: �߸��� ���ī��Ʈ ���� ����)

#define ERR_STATUS_DMA					0x0901			// DMA Transfer	error				(KOR: DMA ���� ���� �߻�)
#define ERR_STATUS_FIFO_FULL			0x0902			// FIFO Full error					(KOR: FIFO Full ���� �߻�)
#define ERR_STATUS_INT					0x0903			// Interrupt Clear error			(KOR: Interrup ��ȣ�� Clear�ȵ�)
#define ERR_STATUS_OVERWRITE			0x0904			// Buffer Overwrite error			(KOR: �����޸� OverWrite ���� �߻�)

#define ERR_TIMEOUT						0x0a01			// Timeout error					(KOR: TimeOut ���� �߻�)

#define ERR_NOT_SUPPORT_X64_DMA_ADDR	0x0a02			// Not support x64 OS				(KOR: x64 OS �������� ����)










/********************************************************************************
 *
 *
 *              III. Definition of Structures (����ü ����)
 *
 *
 ********************************************************************************/

//==============================================================================
// 1. Structures of Board and PCI information (���� �� PCI ����)
//==============================================================================

// Board specification

typedef struct tagBOARD_SPEC_INFO {
    DWORD Reserved;
    WORD  FpgaMainVer;
    WORD  FpgaSubVer;
    DWORD ModelNo;

    DWORD MaxChannelCountAI;
    DWORD MaxChannelCountCTR;
    DWORD MaxChannelCountDI;
    DWORD MaxChannelCountCAN;

    DWORD MaxSampleRate;
    DWORD MinSampleRate;
    DWORD Resolution;
    DWORD InputVoltageRange;

    BOOLEAN SupportRs485;
    BOOLEAN SupportCTR;
    BOOLEAN SupportDI;
    BOOLEAN SupportCAN;
    BOOLEAN SupportExtTrigger;
    BOOLEAN SupportExtClock;

    BOOLEAN SupportCTR_CLKOUT;
    BOOLEAN SupportCTR_SHARED_DI;
} BOARD_SPEC_INFO, *PBOARD_SPEC_INFO;


// Hardware(Product) version infromation

typedef struct tagBOARD_CAL_INFO {
    WORD  Reserved;
    WORD  PcbVer;
    WORD  BoardType;
    WORD  SeqNo;
} BOARD_CAL_INFO, *PBOARD_CAL_INFO;


// Calibration(Production) Date

typedef struct tagBOARD_CAL_DATE {
    WORD Year;
    BYTE Month;
    BYTE Day;
} BOARD_CAL_DATE, *PBOARD_CAL_DATE;


// Calibration(Production) information

typedef struct tagBOARD_MISC_INFO {
    BOARD_CAL_INFO  MainBoard;
    BOARD_CAL_INFO  SubBoard;
    BOARD_CAL_DATE  CalDate;
    char            CalBoxSerial[16];
    char            UserName[40];
    char            UserLocation[40];
} BOARD_MISC_INFO, *PBOARD_MISC_INFO;


// PCI information

typedef struct tagBOARD_PCI_INFO {
    int     SlotNo;
    int     BusNo;
    int     BoardMode;
    BOOLEAN IsMaster;
    BOOLEAN IsTerm;
} BOARD_PCI_INFO, *PBOARD_PCI_INFO;


//==============================================================================
// 2. Structures of Channel Information
//==============================================================================

// Analog channel properties
// (KOR: AI ä���� �Ӽ� ����)

typedef struct tagBOARD_CHANNEL_PROP {
    BYTE    Gain;                   // R/W
} BOARD_CHANNEL_PROP, *PBOARD_CHANNEL_PROP;


// ver2.0.0.4.super - for super counter >
// Sub Counter channel information
// (KOR: Sub ī���� ä�� ����)

typedef struct tagBOARD_SUB_CTR_CHANNEL_ATTR {
	WORD	CtrSigType;
	WORD	CtrMode;
} BOARD_SUB_CTR_CHANNEL_ATTR, *PBOARD_SUB_CTR_CHANNEL_ATTR;
// ver2.0.0.4.super - for super counter <


// Trigger level of Adjustable Counter/Digital Input
// (KOR: CTR/DI ä���� Ʈ���� ����)

typedef struct tagBOARD_ADJ_TRG_VAL {
    int		TrgHighVal;
    int		TrgLowVal;
} BOARD_ADJ_TRG_VAL, *PBOARD_ADJ_TRG_VAL;


// DAC level of Adjustable Counter/Digital Input
// (KOR: CTR/DI ä���� DAC ����)

typedef struct tagBOARD_ADJ_DAC_VAL {
    WORD	DacHighVal;
    WORD	DacLowVal;
} BOARD_ADJ_DAC_VAL, *PBOARD_ADJ_DAC_VAL;


// Counter channel information

typedef struct tagBOARD_CTR_CHANNEL {
    int     CounterKind;

    int     AssignedAuxPin;
    int     AssignedGatePin;
    int     AssignedSourcePin;

    BOOLEAN UseCountDown;
    BOOLEAN UseUpDownSelAux;
    BOOLEAN UseInvertedAux;
    BOOLEAN UseInvertedGate;
    BOOLEAN UseInvertedSource;
    BOOLEAN UseAutoReset;

    int     FilterAuxPin;
    int     FilterGatePin;
    int     FilterSourcePin;

    BOOLEAN EncEnableZReload;
    BOOLEAN EncChannelA_High;
    BOOLEAN EncChannelB_High;

    int     TransferMode;
} BOARD_CTR_CHANNEL, *PBOARD_CTR_CHANNEL;


// Counter channel properties

typedef struct tagBOARD_CTR_CHANNEL_PROP {
    BOOLEAN SupportFilter;					// R
    BOOLEAN SupportMux;						// R
    BOOLEAN DoManualReset;					// W
    BOOLEAN SupportSubAdj;					// R

    BOOLEAN				ObsoleteCtrAdjAcCoupling[3];	// R/W
	BOARD_ADJ_TRG_VAL	ObsoleteCtrAdjTrgLevel[4];		// R/W
	BOARD_ADJ_DAC_VAL	ObsoleteCtrAdjDacVal[4];		// R
} BOARD_CTR_CHANNEL_PROP, *PBOARD_CTR_CHANNEL_PROP;


//ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M >
typedef struct tagBOARD_SUPER_CTR_CHANNEL_PROP {
    BOOLEAN SupportSubCTR_CH;				// R

	BOOLEAN EnabledCTR;						// R

	BOOLEAN UseSubCTR;						// R/W
	BOARD_SUB_CTR_CHANNEL_ATTR	SubCTR;		// R/W
} BOARD_SUPER_CTR_CHANNEL_PROP, *PBOARD_SUPER_CTR_CHANNEL_PROP;
//ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M <


// Information about Adujustable Trigger and  AC/DC Coupling functions of Counter channel
// (KOR: CTR ä���� Adujustable Trigger, AC/DC Coupling �������ο� Ʈ���� ���� ���� ����)

typedef struct tagBOARD_ADJ_CHANNEL_PROP {
    BOOLEAN SupportAdj[40];					// R
    BOOLEAN SupportAcDc[40];				// R
	BOOLEAN AdjAcCoupling[40];				// R/W
	BOARD_ADJ_TRG_VAL	AdjTrgLevel[40];	// R/W
	BOARD_ADJ_DAC_VAL	AdjDacVal[40];		// R
} BOARD_ADJ_CHANNEL_PROP, *PBOARD_ADJ_CHANNEL_PROP;


// Digital I/O channel inforamtion

typedef struct tagBOARD_DI_CHANNEL {
    BOOLEAN Use32bit;
    int     FilterDIPin[32];
} BOARD_DI_CHANNEL, *PBOARD_DI_CHANNEL;


// Digital I/O channel properties

typedef struct tagBOARD_DI_CHANNEL_PROP {
    BOOLEAN SupportFilter;          // R
    BOOLEAN SupportOutputHiByte;    // R
    BOOLEAN Support32bit;           // R    ctr_shared_di

    BOOLEAN DoOutputHiByte;         // W
    BYTE    HiByte;                 // R/W
    BYTE    LoByte;                 // R
} BOARD_DI_CHANNEL_PROP, *PBOARD_DI_CHANNEL_PROP;


//==============================================================================
// 3. Structure of Data Memory information to read
//    (�����͸� �б����� �޸� ����)
//==============================================================================

// Start address, increment value, the number of blocks to read
// (KOR: ������ �����͸� �޸𸮿��� ������ �� ������ �����ּ�, ������, ��ϰ����� ������ ����ü)

typedef struct tagBOARD_READ_DATA {
    int  *BufferPosArr;
    int  *BufferIncArr;
    int  *ReadBlockArr;
} BOARD_READ_DATA, *PBOARD_READ_DATA;


//==============================================================================
// 4. CAN, RS485 information
//==============================================================================

// CAN properties

typedef struct tagBOARD_CAN_PROP {
    BOOLEAN Enabled;				// R/W
    BOOLEAN ListenOnly;				// R/W
    int     BaudRate;				// R/W
    BOOLEAN Sync_100K;				// R/W
    BOOLEAN Sync_AI;				// R/W
} BOARD_CAN_PROP, *PBOARD_CAN_PROP;


// CAN Data frame

typedef struct tagBOARD_CAN_FRAME {
    BYTE    CanNo;
    DWORD   ArbitrationId;
    BOOLEAN IsRemote;
    BOOLEAN IsExtended;
    BYTE    DataLength;
    BYTE    Data[8];

    INT64   Timestamp;
    BYTE    Priority;
} BOARD_CAN_FRAME, *PBOARD_CAN_FRAME;


// CAN Raw Data frame

typedef struct tagBOARD_CAN_RAW_FRAME {
    DWORD Hdr;
    DWORD Pos;
    BYTE  Data[8];
} BOARD_CAN_RAW_FRAME, *PBOARD_CAN_RAW_FRAME;


// RS485 properites

typedef struct tagBOARD_RS485_PROP {
    BOOLEAN SelectSubBoard;
} BOARD_RS485_PROP, *PBOARD_RS485_PROP;



LPSTR RtGetErrorMsg(int nErrorCode, LPSTR szMsg);






/********************************************************************************
 *
 *
 *                IV. Definition of API functions (API �Լ� ����)
 *
 *
 ********************************************************************************/

#ifndef STATIC_DLL

//####################################
//
// Type Definition of API functions
//     (API �Լ� Ÿ�� ����)
//
//####################################


//==============================================================================
// 1. Intialization and information of board
//    (���� �ʱ�ȭ �� ���� ����)
//==============================================================================

typedef BOOLEAN (RT_IMPORT *PRTINITIALBOARDS)(void);
typedef int (RT_IMPORT *PRTGETBOARDCOUNT)(void);

typedef BOOLEAN (RT_IMPORT *PRTGETBOARDINFO)(int nBoardNo, PBOARD_MISC_INFO pMiscInfo);
typedef BOOLEAN (RT_IMPORT *PRTGETSPECINFO)(int nBoardNo, PBOARD_SPEC_INFO pInfo);
typedef BOOLEAN (RT_IMPORT *PRTGETPCIINFO)(int nBoardNo, PBOARD_PCI_INFO pPciInfo);


//==============================================================================
// 2. Open/Close & Start/Stop
//    (����/�ݱ� & ����/����)
//==============================================================================

// Single mode

typedef BOOLEAN (RT_IMPORT *PRTOPEN)(int nBoardNo);
typedef BOOLEAN (RT_IMPORT *PRTCLOSE)(int nBoardNo);
typedef BOOLEAN (RT_IMPORT *PRTSTART)(int nBoardNo);
typedef BOOLEAN (RT_IMPORT *PRTSTOP)(int nBoardNo);


// Multi mode

typedef BOOLEAN (RT_IMPORT *PRTSYNCSETMASTER)(int nBoardNo);
typedef BOOLEAN (RT_IMPORT *PRTSYNCSETSLAVEMASTER)(int nBoardNo);
typedef BOOLEAN (RT_IMPORT *PRTSYNCADDSLAVE)(int nBoardNo);
typedef BOOLEAN (RT_IMPORT *PRTSYNCCLOSE)(int nBoardNo);
typedef void (RT_IMPORT *PRTSYNCCLEAR)(void);
typedef BOOLEAN (RT_IMPORT *PRTSYNCSTART)(int nBoardNo);
typedef BOOLEAN (RT_IMPORT *PRTSYNCSTOP)(int nBoardNo);


//==============================================================================
// 3. Data Acquisition
//    (������ �б�)
//==============================================================================

// Single mode

typedef BOOLEAN (RT_IMPORT *PRTREAD)(int nBoardNo, int *pBufferPosAddr, int *pReadBlock);
typedef BOOLEAN (RT_IMPORT *PRTREADBLOCK)(int nBoardNo, int *pStartBlock, int *pReadBlock);
typedef BOOLEAN (RT_IMPORT *PRTREADEASY)(int nBoardNo, int *pBufferPosAddr, int nWantedBlocks,
	BOOLEAN *bSuccess, int *nScanBackLogs);
typedef BOOLEAN (RT_IMPORT *PRTREADEASYEX)(int nBoardNo, float *aChBufferArrAI[], int *aChBufferArrCTR[],
	int nWantedBlocks, BOOLEAN *bSuccess, int *nScanBackLogs, BOOLEAN bWait);
typedef BOOLEAN (RT_IMPORT *PRTGETDATA)(int nBoardNo, int aBufferPosArr[], int aBufferIncArr[], int aReadBlockArr[]);
typedef BOOLEAN (RT_IMPORT *PRTGETDATAEX)(int nBoardNo, PBOARD_READ_DATA pReadDataAI, PBOARD_READ_DATA pReadDataCTR,
																						PBOARD_READ_DATA pReadDataDI);
typedef LONGLONG (RT_IMPORT *PRTGETCURRENTPOS)(int nBoardNo);


// Multi mode

typedef BOOLEAN (RT_IMPORT *PRTSYNCREAD)(int nBoardNo, int aBufferPosArr[], int aReadBlockArr[]);
typedef BOOLEAN (RT_IMPORT *PRTSYNCREADBLOCK)(int nBoardNo, int aStartBlockArr[], int aReadBlockArr[]);
typedef BOOLEAN (RT_IMPORT *PRTSYNCREADEASY)(int nBoardNo, int aBufferPosArr[], int nWantedBlocks,
	BOOLEAN *bSuccess, int *nScanBackLogs);
typedef BOOLEAN (RT_IMPORT *PRTSYNCREADEASYEX)(int nBoardNo, float *aChBufferArrAI[], int *aChBufferArrCTR[],
    int nWantedBlocks, BOOLEAN *bSuccess, int *nScanBackLogs, BOOLEAN bWait);
typedef BOOLEAN (RT_IMPORT *PRTSYNCGETDATA)(int nBoardNo, int aBufferPosArr[], int aBufferIncArr[], int aReadBlockArr[]);
typedef BOOLEAN (RT_IMPORT *PRTSYNCGETDATAEX)(int nBoardNo, PBOARD_READ_DATA pReadDataAI, PBOARD_READ_DATA pReadDataCTR,
																							PBOARD_READ_DATA pReadDataDI);


//==============================================================================
// 4. Analog channel setup and information
//    (AI ä�� ���� �� ä�� ����)
//==============================================================================

// Single mode

typedef BOOLEAN (RT_IMPORT *PRTADDCHANNEL)(int nBoardNo, int nChannelNo);
typedef int (RT_IMPORT *PRTGETMAXCHANNELCOUNT)(int nBoardNo);
typedef int (RT_IMPORT *PRTGETCHANNELCOUNT)(int nBoardNo);
typedef int (RT_IMPORT *PRTGETCHANNELNO)(int nBoardNo, int nIndex);
typedef BOOLEAN (RT_IMPORT *PRTCLEARCHANNELS)(int nBoardNo);

typedef BOOLEAN (RT_IMPORT *PRTGETCHANNELPROP)(int nBoardNo, int nChannelNo, PBOARD_CHANNEL_PROP pProp);
typedef BOOLEAN (RT_IMPORT *PRTSETCHANNELPROP)(int nBoardNo, int nChannelNo, BOARD_CHANNEL_PROP rProp);


// Multi mode

typedef BOOLEAN (RT_IMPORT *PRTSYNCADDCHANNEL)(int nBoardNo, int nChannelNo);
typedef int (RT_IMPORT *PRTSYNCGETMAXCHANNELCOUNT)(int nBoardNo);
typedef int (RT_IMPORT *PRTSYNCGETCHANNELCOUNT)(int nBoardNo);
typedef int (RT_IMPORT *PRTSYNCGETCHANNELNO)(int nBoardNo, int nIndex);
typedef void (RT_IMPORT *PRTSYNCCLEARCHANNELS)(int nBoardNo);

typedef BOOLEAN (RT_IMPORT *PRTSYNCGETCHANNELPROP)(int nBoardNo, int nChannelNo, PBOARD_CHANNEL_PROP pProp);
typedef BOOLEAN (RT_IMPORT *PRTSYNCSETCHANNELPROP)(int nBoardNo, int nChannelNo, BOARD_CHANNEL_PROP rProp);


//==============================================================================
// 5. Counter channel setup and information
//    (Counter ä�� ���� �� ä�� ����)
//==============================================================================

// Single mode

typedef BOOLEAN (RT_IMPORT *PRTADDCHANNELCTR)(int nBoardNo, int nChannelNo, BOARD_CTR_CHANNEL rCtrInfo);
typedef int (RT_IMPORT *PRTGETMAXCHANNELCOUNTCTR)(int nBoardNo);
typedef int (RT_IMPORT *PRTGETCHANNELCOUNTCTR)(int nBoardNo);
typedef int (RT_IMPORT *PRTGETCHANNELNOCTR)(int nBoardNo, int nIndex);
typedef BOOLEAN (RT_IMPORT *PRTCLEARCHANNELSCTR)(int nBoardNo);

typedef BOOLEAN (RT_IMPORT *PRTGETCHANNELCTR)(int nBoardNo, int nChannelNo, PBOARD_CTR_CHANNEL pCtrInfo);
typedef BOOLEAN (RT_IMPORT *PRTGETCHANNELPROPCTR)(int nBoardNo, int nChannelNo, PBOARD_CTR_CHANNEL_PROP pProp);
typedef BOOLEAN (RT_IMPORT *PRTSETCHANNELPROPCTR)(int nBoardNo, int nChannelNo, BOARD_CTR_CHANNEL_PROP rProp);

//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - start ===>>>
typedef BOOLEAN (RT_IMPORT *PRTGETCHANNELPROPSUPERCTR)(int nBoardNo, int nChannelNo, PBOARD_SUPER_CTR_CHANNEL_PROP pSuperCtrProp);
typedef BOOLEAN (RT_IMPORT *PRTSETCHANNELPROPSUPERCTR)(int nBoardNo, int nChannelNo, BOARD_SUPER_CTR_CHANNEL_PROP rSuperCtrProp);
//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - end <<<===


// Multi mode

typedef BOOLEAN (RT_IMPORT *PRTSYNCADDCHANNELCTR)(int nBoardNo, int nChannelNo, BOARD_CTR_CHANNEL rCtrInfo);
typedef int (RT_IMPORT *PRTSYNCGETMAXCHANNELCOUNTCTR)(int nBoardNo);
typedef int (RT_IMPORT *PRTSYNCGETCHANNELCOUNTCTR)(int nBoardNo);
typedef int (RT_IMPORT *PRTSYNCGETCHANNELNOCTR)(int nBoardNo, int nIndex);
typedef BOOLEAN (RT_IMPORT *PRTSYNCCLEARCHANNELSCTR)(int nBoardNo);

typedef BOOLEAN (RT_IMPORT *PRTSYNCGETCHANNELCTR)(int nBoardNo, int nChannelNo, PBOARD_CTR_CHANNEL pCtrInfo);
typedef BOOLEAN (RT_IMPORT *PRTSYNCSETCHANNELPROPCTR)(int nBoardNo, int nChannelNo, BOARD_CTR_CHANNEL_PROP rProp);
typedef BOOLEAN (RT_IMPORT *PRTSYNCGETCHANNELPROPCTR)(int nBoardNo, int nChannelNo, PBOARD_CTR_CHANNEL_PROP pProp);

//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - start ===>>>
typedef BOOLEAN (RT_IMPORT *PRTSYNCGETCHANNELPROPSUPERCTR)(int nBoardNo, int nChannelNo, PBOARD_SUPER_CTR_CHANNEL_PROP pSuperCtrProp);
typedef BOOLEAN (RT_IMPORT *PRTSYNCSETCHANNELPROPSUPERCTR)(int nBoardNo, int nChannelNo, BOARD_SUPER_CTR_CHANNEL_PROP rSuperCtrProp);
//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - end <<<===


//==============================================================================
// 6. Digital I/O channel setup and information
//    (DIO ä�� ���� �� ä�� ����)
//==============================================================================

 // Single mode

typedef BOOLEAN (RT_IMPORT *PRTADDCHANNELDI)(int nBoardNo, int nChannelNo, BOARD_DI_CHANNEL rDIInfo);
typedef int (RT_IMPORT *PRTGETMAXCHANNELCOUNTDI)(int nBoardNo);
typedef int (RT_IMPORT *PRTGETCHANNELCOUNTDI)(int nBoardNo);
typedef int (RT_IMPORT *PRTGETCHANNELNODI)(int nBoardNo, int nIndex);
typedef BOOLEAN (RT_IMPORT *PRTCLEARCHANNELSDI)(int nBoardNo);

typedef BOOLEAN (RT_IMPORT *PRTGETCHANNELDI)(int nBoardNo, int nChannelNo, PBOARD_DI_CHANNEL pDIInfo);
typedef BOOLEAN (RT_IMPORT *PRTGETCHANNELPROPDI)(int nBoardNo, int nChannelNo, PBOARD_DI_CHANNEL_PROP pProp);
typedef BOOLEAN (RT_IMPORT *PRTSETCHANNELPROPDI)(int nBoardNo, int nChannelNo, BOARD_DI_CHANNEL_PROP rProp);


// Multi mode

typedef BOOLEAN (RT_IMPORT *PRTSYNCADDCHANNELDI)(int nBoardNo, int nChannelNo, BOARD_DI_CHANNEL rDIInfo);
typedef int (RT_IMPORT *PRTSYNCGETMAXCHANNELCOUNTDI)(int nBoardNo);
typedef int (RT_IMPORT *PRTSYNCGETCHANNELCOUNTDI)(int nBoardNo);
typedef int (RT_IMPORT *PRTSYNCGETCHANNELNODI)(int nBoardNo, int nIndex);
typedef BOOLEAN (RT_IMPORT *PRTSYNCCLEARCHANNELSDI)(int nBoardNo);

typedef BOOLEAN (RT_IMPORT *PRTSYNCGETCHANNELDI)(int nBoardNo, int nChannelNo, PBOARD_DI_CHANNEL pDIInfo);
typedef BOOLEAN (RT_IMPORT *PRTSYNCGETCHANNELPROPDI)(int nBoardNo, int nChannelNo, PBOARD_DI_CHANNEL_PROP pProp);
typedef BOOLEAN (RT_IMPORT *PRTSYNCSETCHANNELPROPDI)(int nBoardNo, int nChannelNo, BOARD_DI_CHANNEL_PROP rProp);


//==============================================================================
// 7. Adjustable Counter/Digital Input channel setup
//    (Adjustable Counter/DI ����)
//==============================================================================

typedef BOOLEAN (RT_IMPORT *PRTGETADJCHANNELPROP)(int nBoardNo, int nChannelNo, PBOARD_ADJ_CHANNEL_PROP pProp);
typedef BOOLEAN (RT_IMPORT *PRTSETADJCHANNELPROP)(int nBoardNo, int nChannelNo, BOARD_ADJ_CHANNEL_PROP rProp);


//==============================================================================
// 8. Parameter setup
//    (�Ķ���� ����)
//==============================================================================

// Single mode

typedef BOOLEAN (RT_IMPORT *PRTGETPARAM)(int nBoardNo, int nParamId, int *pVal);
typedef BOOLEAN (RT_IMPORT *PRTSETPARAM)(int nBoardNo, int nParamId, int nVal);
typedef BOOLEAN (RT_IMPORT *PRTUPDATEPARAMS)(int nBoardNo, int nParamIds);
typedef BOOLEAN (RT_IMPORT *PRTCONFIGURE)(int nBoardNo);


// Multi mode

typedef BOOLEAN (RT_IMPORT *PRTSYNCSETPARAM)(int nBoardNo, int nParamId, int nVal);
typedef BOOLEAN (RT_IMPORT *PRTSYNCUPDATEPARAMS)(int nBoardNo, int nParamIds);
typedef BOOLEAN (RT_IMPORT *PRTSYNCCONFIGURE)(int nBoardNo);


//==============================================================================
// 9. RS485
//==============================================================================

typedef BOOLEAN (RT_IMPORT *PRTOPENRS485)(int nBoardNo);
typedef BOOLEAN (RT_IMPORT *PRTCLOSERS485)(int nBoardNo);
typedef BOOLEAN (RT_IMPORT *PRTGETPROPRS485)(int nBoardNo, PBOARD_RS485_PROP rProp);
typedef BOOLEAN (RT_IMPORT *PRTSETPROPRS485)(int nBoardNo, BOARD_RS485_PROP rProp);
typedef BOOLEAN (RT_IMPORT *PRTREADYDATARS485)(int nBoardNo, int nTimeout, int *nReadyCount);
typedef int (RT_IMPORT *PRTREADRS485)(int nBoardNo, LPSTR pBuf, int nBufferSize);
typedef BOOLEAN (RT_IMPORT *PRTWRITERS485)(int nBoardNo, const LPSTR pBuf, int nCount);


//==============================================================================
// 10. CAN
//==============================================================================

typedef BOOLEAN (RT_IMPORT *PRTOPENCAN)(int nBoardNo);
typedef BOOLEAN (RT_IMPORT *PRTCLOSECAN)(int nBoardNo);
typedef BOOLEAN (RT_IMPORT *PRTSTARTCAN)(int nBoardNo);
typedef BOOLEAN (RT_IMPORT *PRTSTOPCAN)(int nBoardNo);
typedef BOOLEAN (RT_IMPORT *PRTGETPROPCAN)(int nBoardNo, int nCanNo, PBOARD_CAN_PROP pProp);
typedef BOOLEAN (RT_IMPORT *PRTSETPROPCAN)(int nBoardNo, int nCanNo, BOARD_CAN_PROP rProp);
typedef int (RT_IMPORT *PRTREADCAN)(int nBoardNo, PBOARD_CAN_FRAME pCanFrames, int nMaxFrameCount);
//zenith 160310 add ver2.0.0.12  - to can read Labview  start --->
typedef int (RT_IMPORT *PRTREADCANLV)(int nBoardNo, PBOARD_CAN_FRAME pCanFrames, int *pFrameCount, int MaxCount);
//zenith 160310 add ver2.0.0.12  - to can read Labview  end <---
typedef int (RT_IMPORT *PRTREADCANRAWFRAME)(int nBoardNo, PBOARD_CAN_RAW_FRAME pCanFrames);
typedef int (RT_IMPORT *PRTWRITECAN)(int nBoardNo, PBOARD_CAN_FRAME pCanFrames, int nFrameCount);


//==============================================================================
// 11. Miscellaneous(Speaker)
//==============================================================================

typedef BOOLEAN (RT_IMPORT *PRTSPEAKERON)(int nBoardNo, WORD nTone);
typedef BOOLEAN (RT_IMPORT *PRTSPEAKEROFF)(int nBoardNo);
typedef BOOLEAN (RT_IMPORT *PRTSPEAKERPLAY)(int nBoardNo, WORD nFreq, DWORD nDelay);
typedef BOOLEAN (RT_IMPORT *PRTSPEAKERONBEEP)(int nBoardNo, WORD nFreq);




//####################################
//
// Declaration of API functions
//      (API �Լ� ����)
//
//####################################

//==============================================================================
// 1. Intialization and information of board
//    (���� �ʱ�ȭ �� ���� ����)
//==============================================================================

extern PRTINITIALBOARDS					RtInitialBoards;
extern PRTGETBOARDCOUNT					RtGetBoardCount;

extern PRTGETBOARDINFO					RtGetBoardInfo;
extern PRTGETSPECINFO					RtGetSpecInfo;
extern PRTGETPCIINFO					RtGetPciInfo;


//==============================================================================
// 2. Open/Close & Start/Stop
//    (����/�ݱ� & ����/����)
//==============================================================================

// Single mode

extern PRTOPEN							RtOpen;
extern PRTCLOSE							RtClose;
extern PRTSTART							RtStart;
extern PRTSTOP							RtStop;


// Multi mode

extern PRTSYNCSETMASTER					RtSyncSetMaster;
extern PRTSYNCSETSLAVEMASTER			RtSyncSetSlaveMaster;
extern PRTSYNCADDSLAVE					RtSyncAddSlave;
extern PRTSYNCCLOSE						RtSyncClose;
extern PRTSYNCCLEAR						RtSyncClear;
extern PRTSYNCSTART						RtSyncStart;
extern PRTSYNCSTOP						RtSyncStop;


//==============================================================================
// 3. Data Acquisition
//    (������ �б�)
//==============================================================================

// Single mode

extern PRTREAD							RtRead;
extern PRTREADBLOCK						RtReadBlock;
extern PRTREADEASY						RtReadEasy;
extern PRTREADEASYEX					RtReadEasyEx;
extern PRTGETDATA						RtGetData;
extern PRTGETDATAEX						RtGetDataEx;
extern PRTGETCURRENTPOS					RtGetCurrentPos;


// Multi mode

extern PRTSYNCREAD						RtSyncRead;
extern PRTSYNCREADBLOCK					RtSyncReadBlock;
extern PRTSYNCREADEASY					RtSyncReadEasy;
extern PRTSYNCREADEASYEX				RtSyncReadEasyEx;
extern PRTSYNCGETDATA					RtSyncGetData;
extern PRTSYNCGETDATAEX					RtSyncGetDataEx;


//==============================================================================
// 4. Analog channel setup and information
//    (AI ä�� ���� �� ä�� ����)
//==============================================================================

// Single mode

extern PRTADDCHANNEL					RtAddChannel;
extern PRTGETMAXCHANNELCOUNT			RtGetMaxChannelCount;
extern PRTGETCHANNELCOUNT				RtGetChannelCount;
extern PRTGETCHANNELNO					RtGetChannelNo;
extern PRTCLEARCHANNELS					RtClearChannels;

extern PRTGETCHANNELPROP				RtGetChannelProp;
extern PRTSETCHANNELPROP				RtSetChannelProp;


// Multi mode

extern PRTSYNCADDCHANNEL				RtSyncAddChannel;
extern PRTSYNCGETMAXCHANNELCOUNT		RtSyncGetMaxChannelCount;
extern PRTSYNCGETCHANNELCOUNT			RtSyncGetChannelCount;
extern PRTSYNCGETCHANNELNO				RtSyncGetChannelNo;
extern PRTSYNCCLEARCHANNELS				RtSyncClearChannels;

extern PRTSYNCGETCHANNELPROP			RtSyncGetChannelProp;
extern PRTSYNCSETCHANNELPROP			RtSyncSetChannelProp;


//==============================================================================
// 5. Counter channel setup and information
//    (Counter ä�� ���� �� ä�� ����)
//==============================================================================

// Single mode

extern PRTADDCHANNELCTR					RtAddChannelCTR;
extern PRTGETMAXCHANNELCOUNTCTR			RtGetMaxChannelCountCTR;
extern PRTGETCHANNELCOUNTCTR			RtGetChannelCountCTR;
extern PRTGETCHANNELNOCTR				RtGetChannelNoCTR;
extern PRTCLEARCHANNELSCTR				RtClearChannelsCTR;

extern PRTGETCHANNELCTR					RtGetChannelCTR;
extern PRTGETCHANNELPROPCTR				RtGetChannelPropCTR;
extern PRTSETCHANNELPROPCTR				RtSetChannelPropCTR;

//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - start ===>>>
extern PRTGETCHANNELPROPSUPERCTR		RtGetChannelPropSuperCTR;
extern PRTSETCHANNELPROPSUPERCTR		RtSetChannelPropSuperCTR;
//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - end <<<===


// Multi mode

extern PRTSYNCADDCHANNELCTR				RtSyncAddChannelCTR;
extern PRTSYNCGETMAXCHANNELCOUNTCTR		RtSyncGetMaxChannelCountCTR;
extern PRTSYNCGETCHANNELCOUNTCTR		RtSyncGetChannelCountCTR;
extern PRTSYNCGETCHANNELNOCTR			RtSyncGetChannelNoCTR;
extern PRTSYNCCLEARCHANNELSCTR			RtSyncClearChannelsCTR;

extern PRTSYNCGETCHANNELCTR				RtSyncGetChannelCTR;
extern PRTSYNCGETCHANNELPROPCTR			RtSyncGetChannelPropCTR;
extern PRTSYNCSETCHANNELPROPCTR			RtSyncSetChannelPropCTR;

//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - start ===>>>
extern PRTSYNCGETCHANNELPROPSUPERCTR	RtSyncGetChannelPropSuperCTR;
extern PRTSYNCSETCHANNELPROPSUPERCTR	RtSyncSetChannelPropSuperCTR;
//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - end <<<===


//==============================================================================
// 6. Digital I/O channel setup and information
//    (DIO ä�� ���� �� ä�� ����)
//==============================================================================

// Single mode

extern PRTADDCHANNELDI					RtAddChannelDI;
extern PRTGETMAXCHANNELCOUNTDI			RtGetMaxChannelCountDI;
extern PRTGETCHANNELCOUNTDI				RtGetChannelCountDI;
extern PRTGETCHANNELNODI				RtGetChannelNoDI;
extern PRTCLEARCHANNELSDI				RtClearChannelsDI;

extern PRTGETCHANNELDI					RtGetChannelDI;
extern PRTGETCHANNELPROPDI				RtGetChannelPropDI;
extern PRTSETCHANNELPROPDI				RtSetChannelPropDI;


// Multi mode

extern PRTSYNCADDCHANNELDI				RtSyncAddChannelDI;
extern PRTSYNCGETMAXCHANNELCOUNTDI		RtSyncGetMaxChannelCountDI;
extern PRTSYNCGETCHANNELCOUNTDI			RtSyncGetChannelCountDI;
extern PRTSYNCGETCHANNELNODI			RtSyncGetChannelNoDI;
extern PRTSYNCCLEARCHANNELSDI			RtSyncClearChannelsDI;

extern PRTSYNCGETCHANNELDI				RtSyncGetChannelDI;
extern PRTSYNCGETCHANNELPROPDI			RtSyncGetChannelPropDI;
extern PRTSYNCSETCHANNELPROPDI			RtSyncSetChannelPropDI;


//==============================================================================
// 7. Adjustable Counter/Digital Input channel setup
//    (Adjustable Counter/DI ����)
//==============================================================================

extern PRTGETADJCHANNELPROP				RtGetAdjChannelProp;
extern PRTSETADJCHANNELPROP				RtSetAdjChannelProp;


//==============================================================================
// 8. Parameter setup
//    (�Ķ���� ����)
//==============================================================================

// Single mode

extern PRTSETPARAM						RtSetParam;
extern PRTGETPARAM						RtGetParam;
extern PRTUPDATEPARAMS					RtUpdateParams;
extern PRTCONFIGURE						RtConfigure;


// Multi mode

extern PRTSYNCSETPARAM					RtSyncSetParam;
extern PRTSYNCUPDATEPARAMS				RtSyncUpdateParams;
extern PRTSYNCCONFIGURE					RtSyncConfigure;


//==============================================================================
// 9. RS485
//==============================================================================

extern PRTOPENRS485						RtOpenRS485;
extern PRTCLOSERS485					RtCloseRS485;
extern PRTGETPROPRS485					RtGetPropRS485;
extern PRTSETPROPRS485					RtSetPropRS485;
extern PRTREADYDATARS485				RtReadyDataRS485;
extern PRTREADRS485						RtReadRS485;
extern PRTWRITERS485					RtWriteRS485;


//==============================================================================
// 10. CAN
//==============================================================================

extern PRTOPENCAN						RtOpenCAN;
extern PRTCLOSECAN						RtCloseCAN;
extern PRTSTARTCAN						RtStartCAN;
extern PRTSTOPCAN						RtStopCAN;
extern PRTGETPROPCAN					RtGetPropCAN;
extern PRTSETPROPCAN					RtSetPropCAN;
extern PRTREADCAN						RtReadCAN;
//zenith 160310 add ver2.0.0.12  - to can read Labview  start --->
extern PRTREADCANLV						RtReadCANLV;
//zenith 160310 add ver2.0.0.12  - to can read Labview  end <---
extern PRTREADCANRAWFRAME				RtReadCANRawFrame;
extern PRTWRITECAN						RtWriteCAN;



//==============================================================================
// 11. Miscellaneous(Speaker)
//==============================================================================

extern PRTSPEAKERON						RtSpeakerOn;
extern PRTSPEAKEROFF					RtSpeakerOff;
extern PRTSPEAKERPLAY					RtSpeakerPlay;
extern PRTSPEAKERONBEEP					RtSpeakerOnBeep;


//==============================================================================
// 12. DLL Load and Unload
//==============================================================================

extern BOOLEAN RTdaqLoad(void);
extern void RTdaqUnload(void);
#if 0
extern void RtCheck(BOOLEAN bOk);
#endif
extern BOOLEAN RTdaqGetLibInstance(HINSTANCE *hLibInst);
extern BOOL GetBoardName(LPSTR szName, DWORD nModelNo);


#else


//==============================================================================
// 1. Intialization and information of board
//    (���� �ʱ�ȭ �� ���� ����)
//==============================================================================

BOOLEAN RT_IMPORT RtInitialBoards(void);
int RT_IMPORT RtGetBoardCount(void);

BOOLEAN RT_IMPORT RtGetBoardInfo(int nBoardNo, PBOARD_MISC_INFO pMiscInfo);
BOOLEAN RT_IMPORT RtGetSpecInfo(int nBoardNo, PBOARD_SPEC_INFO pInfo);
BOOLEAN RT_IMPORT RtGetPciInfo(int nBoardNo, PBOARD_PCI_INFO pPciInfo);


//==============================================================================
// 2. Open/Close & Start/Stop
//    (����/�ݱ� & ����/����)
//==============================================================================

// Single mode

BOOLEAN RT_IMPORT RtOpen(int nBoardNo);
BOOLEAN RT_IMPORT RtClose(int nBoardNo);
BOOLEAN RT_IMPORT RtStart(int nBoardNo);
BOOLEAN RT_IMPORT RtStop(int nBoardNo);


// Multi mode

BOOLEAN RT_IMPORT RtSyncSetMaster(int nBoardNo);
BOOLEAN RT_IMPORT RtSyncSetSlaveMaster(int nBoardNo);
BOOLEAN RT_IMPORT RtSyncAddSlave(int nBoardNo);
BOOLEAN RT_IMPORT RtSyncClose(int nBoardNo);
void RT_IMPORT RtSyncClear(void);
BOOLEAN RT_IMPORT RtSyncStart(int nBoardNo);
BOOLEAN RT_IMPORT RtSyncStop(int nBoardNo);


//==============================================================================
// 3. Data Acquisition
//    (������ �б�)
//==============================================================================

// Single mode

BOOLEAN RT_IMPORT RtRead(int nBoardNo, int *pBufferPosAddr, int *pReadBlock);
BOOLEAN RT_IMPORT RtReadBlock(int nBoardNo, int *pStartBlock, int *pReadBlock);
BOOLEAN RT_IMPORT RtReadEasy(int nBoardNo, int *pBufferPosAddr, int nWantedBlocks,
    BOOLEAN *bSuccess, int *nScanBackLogs);
BOOLEAN RT_IMPORT RtReadEasyEx(int nBoardNo, float *aChBufferArrAI[], int *aChBufferArrCTR[],
    int nWantedBlocks, BOOLEAN *bSuccess, int *nScanBackLogs, BOOLEAN bWait = FALSE);
BOOLEAN RT_IMPORT RtGetData(int nBoardNo, int aBufferPosArr[], int aBufferIncArr[], int aReadBlockArr[]);
BOOLEAN RT_IMPORT RtGetDataEx(int nBoardNo, PBOARD_READ_DATA pReadDataAI, PBOARD_READ_DATA pReadDataCTR,
																			PBOARD_READ_DATA pReadDataDI);
LONGLONG RT_IMPORT RtGetCurrentPos(int nBoardNo);


// Multi mode

BOOLEAN RT_IMPORT RtSyncRead(int nBoardNo, int aBufferPosArr[], int aReadBlockArr[]);
BOOLEAN RT_IMPORT RtSyncReadBlock(int nBoardNo, int aStartBlockArr[], int aReadBlockArr[]);
BOOLEAN RT_IMPORT RtSyncReadEasy(int nBoardNo, int *aBufferPosAddr[], int nWantedBlocks,
    BOOLEAN *bSuccess, int *nScanBackLogs);
BOOLEAN RT_IMPORT RtSyncReadEasyEx(int nBoardNo, float *aChBufferArrAI[], int *aChBufferArrCTR[],
    int nWantedBlocks, BOOLEAN *bSuccess, int *nScanBackLogs, BOOLEAN bWait = FALSE);
BOOLEAN RT_IMPORT RtSyncGetData(int nBoardNo, int aBufferPosArr[], int aBufferIncArr[], int aReadBlockArr[]);
BOOLEAN RT_IMPORT RtSyncGetDataEx(int nBoardNo, PBOARD_READ_DATA pReadDataAI, PBOARD_READ_DATA pReadDataCTR,
																				PBOARD_READ_DATA pReadDataDI);


//==============================================================================
// 4. Analog channel setup and information
//    (AI ä�� ���� �� ä�� ����)
//==============================================================================

// Single mode

BOOLEAN RT_IMPORT RtAddChannel(int nBoardNo, int nChannelNo);
int RT_IMPORT RtGetMaxChannelCount(int nBoardNo);
int RT_IMPORT RtGetChannelCount(int nBoardNo);
int RT_IMPORT RtGetChannelNo(int nBoardNo, int nIndex);
BOOLEAN RT_IMPORT RtClearChannels(int nBoardNo);

BOOLEAN RT_IMPORT RtGetChannelProp(int nBoardNo, int nChannelNo, PBOARD_CHANNEL_PROP pProp);
BOOLEAN RT_IMPORT RtSetChannelProp(int nBoardNo, int nChannelNo, BOARD_CHANNEL_PROP rProp);


// Multi mode

BOOLEAN RT_IMPORT RtSyncAddChannel(int nBoardNo, int nChannelNo);
int RT_IMPORT RtSyncGetMaxChannelCount(int nBoardNo);
int RT_IMPORT RtSyncGetChannelCount(int nBoardNo);
int RT_IMPORT RtSyncGetChannelNo(int nBoardNo, int nIndex);
void RT_IMPORT RtSyncClearChannels(int nBoardNo);

BOOLEAN RT_IMPORT RtSyncGetChannelProp(int nBoardNo, int nChannelNo, PBOARD_CHANNEL_PROP pProp);
BOOLEAN RT_IMPORT RtSyncSetChannelProp(int nBoardNo, int nChannelNo, BOARD_CHANNEL_PROP rProp);


//==============================================================================
// 5. Counter channel setup and information
//    (Counter ä�� ���� �� ä�� ����)
//==============================================================================

// Single mode

BOOLEAN RT_IMPORT RtAddChannelCTR(int nBoardNo, int nChannelNo, BOARD_CTR_CHANNEL rCtrInfo);
int RT_IMPORT RtGetMaxChannelCountCTR(int nBoardNo);
int RT_IMPORT RtGetChannelCountCTR(int nBoardNo);
int RT_IMPORT RtGetChannelNoCTR(int nBoardNo, int nIndex);
BOOLEAN RT_IMPORT RtClearChannelsCTR(int nBoardNo);

BOOLEAN RT_IMPORT RtGetChannelCTR(int nBoardNo, int nChannelNo, PBOARD_CTR_CHANNEL pCtrInfo);
BOOLEAN RT_IMPORT RtGetChannelPropCTR(int nBoardNo, int nChannelNo, PBOARD_CTR_CHANNEL_PROP pProp);
BOOLEAN RT_IMPORT RtSetChannelPropCTR(int nBoardNo, int nChannelNo, BOARD_CTR_CHANNEL_PROP rProp);

//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - start ===>>>
BOOLEAN RT_IMPORT RtGetChannelPropSuperCTR(int nBoardNo, int nChannelNo, PBOARD_SUPER_CTR_CHANNEL_PROP pSuperCtrProp);
BOOLEAN RT_IMPORT RtSetChannelPropSuperCTR(int nBoardNo, int nChannelNo, BOARD_SUPER_CTR_CHANNEL_PROP rSuperCtrProp);
//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - end <<<===


// Multi mode

BOOLEAN RT_IMPORT RtSyncAddChannelCTR(int nBoardNo, int nChannelNo, BOARD_CTR_CHANNEL rCtrInfo);
int RT_IMPORT RtSyncGetMaxChannelCountCTR(int nBoardNo);
int RT_IMPORT RtSyncGetChannelCountCTR(int nBoardNo);
int RT_IMPORT RtSyncGetChannelNoCTR(int nBoardNo, int nIndex);
BOOLEAN RT_IMPORT RtSyncClearChannelsCTR(int nBoardNo);

BOOLEAN RT_IMPORT RtSyncGetChannelCTR(int nBoardNo, int nChannelNo, PBOARD_CTR_CHANNEL pCtrInfo);
BOOLEAN RT_IMPORT RtSyncGetChannelPropCTR(int nBoardNo, int nChannelNo, PBOARD_CTR_CHANNEL_PROP pProp);
BOOLEAN RT_IMPORT RtSyncSetChannelPropCTR(int nBoardNo, int nChannelNo, BOARD_CTR_CHANNEL_PROP rProp);

//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - start ===>>>
BOOLEAN RT_IMPORT RtSyncGetChannelPropSuperCTR(int nBoardNo, int nChannelNo, PBOARD_SUPER_CTR_CHANNEL_PROP pSuperCtrProp);
BOOLEAN RT_IMPORT RtSyncSetChannelPropSuperCTR(int nBoardNo, int nChannelNo, BOARD_SUPER_CTR_CHANNEL_PROP rSuperCtrProp);
//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - end <<<===


//==============================================================================
// 6. Digital I/O channel setup and information
//    (DIO ä�� ���� �� ä�� ����)
//==============================================================================

// Single mode

BOOLEAN RT_IMPORT RtAddChannelDI(int nBoardNo, int nChannelNo, BOARD_DI_CHANNEL rDIInfo);
int RT_IMPORT RtGetMaxChannelCountDI(int nBoardNo);
int RT_IMPORT RtGetChannelCountDI(int nBoardNo);
int RT_IMPORT RtGetChannelNoDI(int nBoardNo, int nIndex);
BOOLEAN RT_IMPORT RtClearChannelsDI(int nBoardNo);

BOOLEAN RT_IMPORT RtGetChannelDI(int nBoardNo, int nChannelNo, PBOARD_DI_CHANNEL pDIInfo);
BOOLEAN RT_IMPORT RtGetChannelPropDI(int nBoardNo, int nChannelNo, PBOARD_DI_CHANNEL_PROP pProp);
BOOLEAN RT_IMPORT RtSetChannelPropDI(int nBoardNo, int nChannelNo, BOARD_DI_CHANNEL_PROP rProp);


// Multi mode

BOOLEAN RT_IMPORT RtSyncAddChannelDI(int nBoardNo, int nChannelNo, BOARD_DI_CHANNEL rDIInfo);
int RT_IMPORT RtSyncGetMaxChannelCountDI(int nBoardNo);
int RT_IMPORT RtSyncGetChannelCountDI(int nBoardNo);
int RT_IMPORT RtSyncGetChannelNoDI(int nBoardNo, int nIndex);
BOOLEAN RT_IMPORT RtSyncClearChannelsDI(int nBoardNo);

BOOLEAN RT_IMPORT RtSyncGetChannelDI(int nBoardNo, int nChannelNo, PBOARD_DI_CHANNEL pDIInfo);
BOOLEAN RT_IMPORT RtSyncGetChannelPropDI(int nBoardNo, int nChannelNo, PBOARD_DI_CHANNEL_PROP pProp);
BOOLEAN RT_IMPORT RtSyncSetChannelPropDI(int nBoardNo, int nChannelNo, BOARD_DI_CHANNEL_PROP rProp);


//==============================================================================
// 7. Adjustable Counter/Digital Input channel setup
//    (Adjustable Counter/DI ����)
//==============================================================================

BOOLEAN RT_IMPORT RtGetAdjChannelProp(int nBoardNo, int nChannelNo, PBOARD_ADJ_CHANNEL_PROP pProp);
BOOLEAN RT_IMPORT RtSetAdjChannelProp(int nBoardNo, int nChannelNo, BOARD_ADJ_CHANNEL_PROP rProp);


//==============================================================================
// 8. Parameter setup
//    (�Ķ���� ����)
//==============================================================================

// Single mode

BOOLEAN RT_IMPORT RtGetParam(int nBoardNo, int nParamId, int *pVal);
BOOLEAN RT_IMPORT RtSetParam(int nBoardNo, int nParamId, int nVal);
BOOLEAN RT_IMPORT RtUpdateParams(int nBoardNo, int nParamIds);
BOOLEAN RT_IMPORT RtConfigure(int nBoardNo);


// Multi mode

BOOLEAN RT_IMPORT RtSyncSetParam(int nBoardNo, int nParamId, int nVal);
BOOLEAN RT_IMPORT RtSyncUpdateParams(int nBoardNo, int nParamIds);
BOOLEAN RT_IMPORT RtSyncConfigure(int nBoardNo);



//==============================================================================
// 9. RS485
//==============================================================================

BOOLEAN RT_IMPORT RtOpenRS485(int nBoardNo);
BOOLEAN RT_IMPORT RtCloseRS485(int nBoardNo);
BOOLEAN RT_IMPORT RtGetPropRS485(int nBoardNo, PBOARD_RS485_PROP rProp);
BOOLEAN RT_IMPORT RtSetPropRS485(int nBoardNo, BOARD_RS485_PROP rProp);
BOOLEAN RT_IMPORT RtReadyDataRS485(int nBoardNo, int nTimeout, int *nReadyCount);
int RT_IMPORT RtReadRS485(int nBoardNo, LPSTR pBuf, int nBufferSize);
BOOLEAN RT_IMPORT RtWriteRS485(int nBoardNo, const LPSTR pBuf, int nCount);


//==============================================================================
// 10. CAN
//==============================================================================

BOOLEAN RT_IMPORT RtOpenCAN(int nBoardNo);
BOOLEAN RT_IMPORT RtCloseCAN(int nBoardNo);
BOOLEAN RT_IMPORT RtStartCAN(int nBoardNo);
BOOLEAN RT_IMPORT RtStopCAN(int nBoardNo);
BOOLEAN RT_IMPORT RtGetPropCAN(int nBoardNo, int nCanNo, PBOARD_CAN_PROP pProp);
BOOLEAN RT_IMPORT RtSetPropCAN(int nBoardNo, int nCanNo, BOARD_CAN_PROP rProp);
int RT_IMPORT RtReadCAN(int nBoardNo, PBOARD_CAN_FRAME pCanFrames, int nMaxFrameCount);
//zenith 160310 add ver2.0.0.12  - to can read Labview  start --->
int RT_IMPORT RtReadCANLV(int nBoardNo, PBOARD_CAN_FRAME pCanFrames, int *pFrameCount, int MaxCount);
//zenith 160310 add ver2.0.0.12  - to can read Labview  end <---
int RT_IMPORT RtReadCANRawFrame(int nBoardNo, PBOARD_CAN_RAW_FRAME pCanFrames);
int RT_IMPORT RtWriteCAN(int nBoardNo, PBOARD_CAN_FRAME pCanFrames, int nFrameCount);


//==============================================================================
// 11. Miscellaneous(Speaker)
//==============================================================================

BOOLEAN RT_IMPORT RtSpeakerOn(int nBoardNo, WORD nTone);
BOOLEAN RT_IMPORT RtSpeakerOff(int nBoardNo);
BOOLEAN RT_IMPORT RtSpeakerPlay(int nBoardNo, WORD nFreq, DWORD nDelay);
BOOLEAN RT_IMPORT RtSpeakerOnBeep(int nBoardNo, WORD nFreq);

#endif  // not STATIC_DLL




#ifdef __cplusplus
}
#endif /* __cplusplus */




#endif //  OrionDaq_api.H
