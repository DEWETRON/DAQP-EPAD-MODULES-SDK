
/**********************************************************************
 *
 *      File Name   : OrionDsa_api.h
 *
 *      Revision    : 2012.12.07.
 *
 *      Version     : Ver 1.1
 *
 *      Author      : Soo-Hong Kim
 *
 *      E - Mail    : shkim@dewetron.co.kr
 *
 *
 *      - Description -
 *
 *      The header file of OrionDsa API
 *
 *
 *      Copyright (C) Dewetron Korea, LTD.
 *
 **********************************************************************/
#ifndef __ORIONDSA_API_H__
#define __ORIONDSA_API_H__


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
#define PARAM_MODE_BOARD                0x0f01          // Use to get the board state, or to set a board to the Stand-Alone mode.
                                                        // (KOR: ���� ���� ���¸� �о���� ����, �Ǵ� ���� ������ Stand-Alone ���� �����ϱ� ���� ���)

#define PARAM_SAMPLERATE                0x0101          // Sampling Rate. This is used with PARAM_SAMPLERATE_DIVISOR.
                                                        // (KOR: Sampling Rate. PARAM_SAMPLERATE_DIVISOR�� ���� ����)

#define PARAM_BLOCKSIZE                  0x0102          // The number of samples for one DMA data transfer.
                                                        // (KOR: ���� �������� ���� ũ��)

#define PARAM_SAMPLERATE_DIVISOR        0x0103          // Set the sample rate divsior for the real sample rate
                                                        // This is used with PARAM_SAMPLERATE.
                                                        // (KOR: PARAM_SAMPLERATE�� ���� ���� Sampling Rate ���� ���)

#define PARAM_DSAMPLERATE               0x0110          // Set the Real Sampling Rate (floating point type)
                                                        // (KOR: ���� Sampling Rate (�ε� �Ҽ��� ���·� ���� �ѱ�))

#define PARAM_TIME_OUT                  0x0a01          // Time-out interval in milliseconds.
                                                        // (KOR: TimeOut ���� millisecond ������ ����)

#define PARAM_BUFFER_BLOCK_COUNT        0x0107          // The number of Blocks.
                                                        // (KOR: ������ ���ۿ� ���� ������ ���ũ��)

#define PARAM_MAX_BUFFER_BLOCK_COUNT    0x0723          // The maximum number of Blocks. // ver4.0.0.4.z
                                                        // (KOR: ������ �� �ִ� �ִ� ��� ũ��)

//----------------------------------------
// 1.2 ADC Sync mode parameter
//----------------------------------------
#define PARAM_ADC_CLOCK_SYNC_MODE       0x0240          // Select a signal to synchronize with ADC Clock
                                                        // (KOR: ADC Clock �߻��� ���⸦ ���� ��ȣ�� ����)

//----------------------------------------
// 1.3 External PLL Clock Parameter
//----------------------------------------
#define PARAM_USE_EXT_PLL_CLOCK         0x0529          // Use an external PLL clock
                                                        // (KOR: �ܺ� PLL clock�� ����Ͽ� ������ ��� ����)




/////////////////////////////////////////////////////////
//
// 2. Parameters for ANALOG channel setup
//
/////////////////////////////////////////////////////////

//----------------------------------------
// 2.1 Packed mode of Analog channels
//----------------------------------------
#define PARAM_USE_PACKED                0x0503          // Packet mode of analog input channels
                                                        // (KOR: AI ä�ο��� ������ ���� �� Packet mode ��뿩�� ����)

//----------------------------------------
// 2.2 Sensed mode of Analog channel (only for Orion-1622, Orion-3222)
//----------------------------------------
#define PARAM_USE_SENSE_MODE1           0x0600          // Sensed mode (CH0~7)
#define PARAM_USE_SENSE_MODE2           0x0601          // Sensed mode (CH8~15)
#define PARAM_USE_SENSE_MODE3           0x0602          // Sensed mode (CH16~23)
#define PARAM_USE_SENSE_MODE4           0x0603          // Sensed mode (CH24~31)


#define PARAM_NUM_AI_SKIP               0x0505          // ver3.0.0.27


/////////////////////////////////////////////////////////
//
// 3. Parameters for COUNTER channel setup
//
/////////////////////////////////////////////////////////
#define PARAM_CTR_RESET                 0x0552          // Reset the value of Counter Channel
                                                        // (KOR: ���õ� ī���� ä���� ���� ���� 0���� �ʱ�ȭ)




/////////////////////////////////////////////////////////
//
// 4. Parameters for DIGITAL channel setup
//
/////////////////////////////////////////////////////////
#define PARAM_USE_DIO_OUTPUT            0x0515          // Digital Channel mode : setup to input or output mode
                                                        // (KOR: Digital Out ��뿩�� ����(DI CH8~15))




/////////////////////////////////////////////////////////
//
// 5. Parameters for External Clock setup
//
/////////////////////////////////////////////////////////
#define PARAM_USE_EXT_CLOCK             0x0502          // Select External Clock
                                                        // (KOR: �ܺ� Ŭ���� ����Ͽ� ADC Clock���� ��������� ���θ� ����)

#define PARAM_EXT_CLOCK_MODE            0x020c          // Select a source signal and a polarity of External Clock
                                                        // (KOR: �ܺ� Ŭ���� Source signal�� Polarity�� ����)




/////////////////////////////////////////////////////////
//
// 6. Parameters for External Trigger setup
//
/////////////////////////////////////////////////////////
#define PARAM_USE_EXT_TRIGGER           0x0501          // Select External Trigger
                                                        // (KOR: �ܺ� Ʈ���Ÿ� ������� ���� ����)

#define PARAM_EXT_TRIGGER_MODE          0x0106          // Select Input/Output mode, Timebase and Polarity of External Trigger
                                                        // (KOR: �ܺ� Ʈ���� ���� Input/Output, Timebase, Polarity ����)




/////////////////////////////////////////////////////////
//
// 7. Parameters for External Clock Out 1, 2 setup
//
/////////////////////////////////////////////////////////

//----------------------------------------
// 7.1 Use of External Clock Out
//----------------------------------------
#define PARAM_USE_CLKOUT0               0x0506          // Use External Clock Out1 (EXT_CLK1)
                                                        // (KOR: EXT_CLK1 �� ��뿩�θ� ����)

#define PARAM_USE_CLKOUT1               0x0507          // Use External Clock Out2 (EXT_CLK2)
                                                        // (KOR: EXT_CLK2 �� ��뿩�θ� ����)

//----------------------------------------
// 7.2 External Clock Out mode
//----------------------------------------
#define PARAM_CLKOUT0_MODE              0x0202          // Select the Polarity of External Clock Out1
                                                        // (KOR: EXT_CLK1 ������ Source Clock�� ����� �� Polarity ����)
#define PARAM_CLKOUT1_MODE              0x0207          // Select the Polarity of External Clock Out2
                                                        // (KOR: EXT_CLK2 ������ Source Clock�� ����� �� Polarity ����)

//----------------------------------------
// 7.3 Divisor of External Clock Out
//----------------------------------------
#define PARAM_CLKOUT0_DIVISOR           0x0201          // Setup the divisor value of External Clock Out1. Only for Orion-1624E !
                                                        // (KOR: EXT_CLK1 ������ Source Clock�� ����� �� Divisor �� ����. Only for Orion-1624E)

#define PARAM_CLKOUT1_DIVISOR           0x0206          // Setup the divisor value of External Clock Out2. Only for Orion-1624E !
                                                        // (KOR: EXT_CLK2 ������ Source Clock�� ����� �� Divisor �� ����. Only for Orion-1624E)

#define PARAM_CLKOUT0_MULTIPLIER        0x0203          // Obsolete ! This is not supported...
#define PARAM_CLKOUT1_MULTIPLIER        0x0208          // Obsolete ! This is not supported...




/////////////////////////////////////////////////////////
//
// 8. Parameters for Internal Div Sig 0, 1, 2 setup
//
/////////////////////////////////////////////////////////

//----------------------------------------
// 8.1 Internal Div Sig mode
//----------------------------------------
#define PARAM_DIV_SIG0_MODE             0x0232
#define PARAM_DIV_SIG1_MODE             0x0235
#define PARAM_DIV_SIG2_MODE             0x0238

//----------------------------------------
// 8.2 Divisor and Multiplier of Internal Div Sig
//----------------------------------------
#define PARAM_DIV_SIG0_DIVISOR          0x0231
#define PARAM_DIV_SIG1_DIVISOR          0x0234
#define PARAM_DIV_SIG2_DIVISOR          0x0237
#define PARAM_DIV_SIG0_MULTIPLIER       0x0233
#define PARAM_DIV_SIG1_MULTIPLIER       0x0236
#define PARAM_DIV_SIG2_MULTIPLIER       0x0239




/////////////////////////////////////////////////////////
//
// 9. Parameters for the Clock Out 0, 1 setup of Expansion Counter Board
//
/////////////////////////////////////////////////////////

//----------------------------------------
// 9.1 Use of Clock Out of Expansion Counter Board
//----------------------------------------
#define PARAM_USE_CTR_CLKOUT0           0x0526          // Use Clock Out0 of Expansion Counter Board
                                                        // (KOR: Ȯ�� ī���� ������ EX_OUT0 ���� ������� ���� ����)

#define PARAM_USE_CTR_CLKOUT1           0x0527          // Use Clock Out1 of Expansion Counter Board
                                                        // (KOR: Ȯ�� ī���� ������ EX_OUT1 ���� ������� ���� ����)

//----------------------------------------
// 9.2 Clock Out mode of Expansion Counter Board
//----------------------------------------
#define PARAM_CTR_CLKOUT0_MODE          0x0213          // Select the source of Clock Out0 of Expansion Counter Board
                                                        // (KOR: Ȯ�� ī���� ������ EX_OUT0�� Clock Source ����)

#define PARAM_CTR_CLKOUT1_MODE          0x0223          // Select the source of Clock Out1 of Expansion Counter Board
                                                        // (KOR: Ȯ�� ī���� ������ EX_OUT1�� Clock Source ����)

//----------------------------------------
// 9.3 Divisor of Clock Out of Expansion Counter Board
//----------------------------------------
#define PARAM_CTR_CLKOUT0_DIVISOR_HIGH  0x0211          // Divisor of the High period of Clock Out0 pulse of Expansion Counter Board
                                                        // (KOR: Ȯ�� ī���� ������ EX_OUT0���� ��ȣ��� �� �޽��� High �ð��� Divisor �� ����)

#define PARAM_CTR_CLKOUT1_DIVISOR_HIGH  0x0221          // Divisor of the High period of Clock Out1 pulse of Expansion Counter Board
                                                        // (KOR: Ȯ�� ī���� ������ EX_OUT1���� ��ȣ��� �� �޽��� High �ð��� Divisor �� ����)

#define PARAM_CTR_CLKOUT0_DIVISOR_LOW   0x0212          // Divisor of the Low period of Clock Out0 pulse of Expansion Counter Board
                                                        // (KOR: Ȯ�� ī���� ������ EX_OUT0���� ��ȣ��� �� �޽��� Low �ð��� Divisor �� ����)

#define PARAM_CTR_CLKOUT1_DIVISOR_LOW   0x0222          // Divisor of the Low period of Clock Out1 pulse of Expansion Counter Board
                                                        // (KOR: Ȯ�� ī���� ������ EX_OUT1���� ��ȣ��� �� �޽��� Low �ð��� Divisor �� ����)




/////////////////////////////////////////////////////////
//
// 10. Parameters for CAN
//
/////////////////////////////////////////////////////////

//----------------------------------------
// 10.1 CAN Polling Time
//----------------------------------------
#define PARAM_CAN_POLLING_TIME          0x0553          // Polling time to read CAN Data (KOR: CAN �����͸� ��ٸ��� �ð� ����)

//----------------------------------------
// 10.2 CAN Error Check
//----------------------------------------
#define PARAM_CAN0_ERROR_FLAG           0x0700          // Error flag of CAN0 (KOR: CAN 0 ��Ʈ�� ���� �÷��׸� �о��)
#define PARAM_CAN1_ERROR_FLAG           0x0701          // Error flag of CAN1 (KOR: CAN 1 ��Ʈ�� ���� �÷��׸� �о��)
#define PARAM_CAN0_ERROR_COUNT          0x0702          // The number of error of CAN0 (KOR: CAN 0 ��Ʈ�� ������ ���� ������ �о��)
#define PARAM_CAN1_ERROR_COUNT          0x0703          // The number of error of CAN1 (KOR: CAN 1 ��Ʈ�� ������ ���� ������ �о��)




/////////////////////////////////////////////////////////
//
// 11. Parameters for Update
//
/////////////////////////////////////////////////////////
#define PARAM_UPDATE_ALL                0               // Update all the parameters
                                                        // (KOR: ��� �Ķ���� �׷��� �����Ŵ)

#define PARAM_UPDATE_CLKOUT             0x0001          // Update the parameters of Clock Out 0, 1
                                                        // (KOR: ClockOut0, ClockOut1 ���� ������ ����)

#define PARAM_UPDATE_EXT_CLOCK          0x0002          // Update the parameters of External Clock
                                                        // (KOR: �ܺ� Ŭ���� ������ ����)

#define PARAM_UPDATE_CTR_CONTROL        0x0004          // Update the Reset of Counter channel(Update PARAM_CTR_RESET)
                                                        // (KOR: PARAM_CTR_RESET ���� ����)

#define PARAM_UPDATE_CHANNEL_AI         0x0008          // Update the properties of AI Channel
                                                        // (KOR: AI Channel �Ӽ� ���� ����)

#define PARAM_UPDATE_ADJ                0x0010          // Update the properties of Adjustable Counter
                                                        // (KOR: Adjustable Counter ���� ����)




/////////////////////////////////////////////////////////
//
// 12. Parameters for Error Handling
//
/////////////////////////////////////////////////////////
#define PARAM_LAST_ERROR                0x0a02          // Read Error Code
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

// DEWE-ORION-1624 Series
#define BOARD_ORION_1624_200            0x1210          // ORION-1624-200
#define BOARD_ORION_1624_201            0x1211          // ORION-1624-200, CAN
#define BOARD_ORION_1624_202            0x1214          // ORION-1624-200, EXP-CNT8-TTL
#define BOARD_ORION_1624_203            0x1215          // ORION-1624-200, EXP-CNT8-TTL, CAN
#define BOARD_ORION_1624_204            0x1290          // ORION-1624-200, EXP-CNT8-ADJ
#define BOARD_ORION_1624_205            0x1291          // ORION-1624-200, EXP-CNT8-ADJ, CAN
#define BOARD_ORION_1624_206            0x1212          // ORION-1624-200, CNT6
#define BOARD_ORION_1624_207            0x1213          // ORION-1624-200, CNT6, CAN

// DEWE-ORION-1622 Series
#define BOARD_ORION_1622_100            0x1420          // OROIN-1622-100
#define BOARD_ORION_1622_101            0x1421          // ORION-1622-100, CAN
#define BOARD_ORION_1622_102            0x1424          // ORION-1622-100, EXP-CNT8-TTL
#define BOARD_ORION_1622_103            0x1425          // ORION-1622-100, EXP-CNT8-TTL, CAN
#define BOARD_ORION_1622_104            0x14a0          // ORION-1622-100, EXP-CNT8-ADJ
#define BOARD_ORION_1622_105            0x14a1          // ORION-1622-100, EXP-CNT8-ADJ, CAN
#define BOARD_ORION_1622_106            0x1422          // ORION-1622-100, CNT6
#define BOARD_ORION_1622_107            0x1423          // ORION-1622-100, CNT6, CAN
#define BOARD_ORION_3222_100            0x2420          // ORION-3222-100
#define BOARD_ORION_3222_101            0x2421          // ORION-3222-100 CAN

// DEWE-ORION-0824 Series
#define BOARD_ORION_0824_200            0x4210          // ORION-0824-200
#define BOARD_ORION_0824_201            0x4211          // ORION-0824-200, CAN
#define BOARD_ORION_0824_202            0x4214          // ORION-0824-200, EXP-CNT8-TTL
#define BOARD_ORION_0824_203            0x4215          // ORION-0824-200, EXP-CNT8-TTL, CAN
#define BOARD_ORION_0824_204            0x4290          // ORION-0824-200, EXP-CNT8-ADJ
#define BOARD_ORION_0824_205            0x4291          // ORION-0824-200, EXP-CNT8-ADJ, CAN

// DEWE-ORION-0424
#define BOARD_ORION_0424_200            0x8210          // ORION-0424-200

// DEWE-ORION-1624 OLD version Series
#define BOARD_ORION_1624                0x121a          // ORION-1624
#define BOARD_ORION_1624E               0x121b          // ORION-1624E
#define BOARD_ORION_1624_CNT            0x121c          // ORION-1624E + CNT


//----------------------------------------------
// 1.2 Constants of Bit Flags for Model Number
//     (���� �� ����� ��Ʈ�� ���� ���)
//----------------------------------------------

//++++++++++++++++++++++++++++++++++
// Structure : BOARD_SPEC_INFO
//----------------------------------
//     @ variable name - ModelNo
//++++++++++++++++++++++++++++++++++

#define BOARD_FLAG_CH16                 0x1000          // The number of Analog channels is 16 (KOR: AI ä�� ���� 16��)
#define BOARD_FLAG_CH32                 0x2000          // The number of Analog channels is 32 (KOR: AI ä�� ���� 32��)
#define BOARD_FLAG_CH08                 0x4000          // The number of Analog channels is 8  (KOR: AI ä�� ����  8��)
#define BOARD_FLAG_CH04                 0x8000          // The number of Analog channels is 4  (KOR: AI ä�� ����  4��)
#define BOARD_FLAG_RES16                0x0100          // Resolution 16 bit
#define BOARD_FLAG_RES22                0x0400          // Resolution 22 bit
#define BOARD_FLAG_RES24                0x0200          // Resolution 24 bit
#define BOARD_FLAG_CNT6                 0x0002          // The number of Counter channels is 6            (KOR: CNT 6ä��)
#define BOARD_FLAG_CNT8                 0x0004          // The number of TTL Counter channels is 8        (KOR: CNT 8ä�� - TTL)
#define BOARD_FLAG_CNT8_ADJ             0x0080          // The number of Adjustable Counter channels is 8 (KOR: CNT 8ä�� - ADJ)
#define BOARD_FLAG_SR100                0x0020          // Max Sample Rate 100kHz
#define BOARD_FLAG_SR200                0x0010          // Max Sample Rate 200kHz
#define BOARD_FLAG_CAN                  0x0001          // Support CAN (KOR: CAN ���� ����)


//----------------------------------------------
// 1.3 Constants for Board State
//     (������ ���� ���� Constants)
//----------------------------------------------

//++++++++++++++++++++++++++++++++++
// Structure : BOARD_PCI_INFO
//----------------------------------
//     @ variable name - BoardMode
//++++++++++++++++++++++++++++++++++

#define MODE_BOARD_STANDALONE           0x00010000      // Single mode (default)
                                                        // (KOR: Single mode ���� �ش� ���忡 ����(Default))

#define MODE_BOARD_MASTER               0x00010001      // Master board in case of Multi mode
                                                        // (KOR: Multi mode ���� ������ ���忡 ����)

#define MODE_BOARD_SLAVE                0x00010002      // Slave board in case of Multi mode, and the terminal switch is off
                                                        // (KOR: Multi mode ���� ������ ����� Terminal Switch��
                                                        //       On �Ǿ� �ִ� ���带 ������ ���忡 ����)

#define MODE_BOARD_SLAVE_TERM           0x00010003      // Slave board in case of Multi mode, and the terminal switch is on
                                                        // (KOR: Multi mode ���� Terminal Switch�� On �Ǿ� �ִ� ���忡 ����)

#define MODE_BOARD_SLAVE_MASTER         0x00010004      // In the multi network system environment,
                                                        // the first board of the each systems except the first and last system
                                                        // (KOR: Network�� ���� �����, ù��°, ������ �ý����� ������
                                                        //       �ý����� ù��° ���带 �����ͷ� ����)

#define MODE_BOARD_SLAVE_TERM_MASTER    0x00010005      // In the multi network system environment, the first board of the last system
                                                        // (KOR: Network�� ���� �����, ������ �ý����� ù��° ���带 �����ͷ� ����)




//##################################################
//
// 2. Constants for measurement setup
//    (���� ���� ���� ���� ���)
//
//##################################################

//----------------------------------------------
// 2.1 ADC Sync mode
//
//      Related Parameter (���� �Ķ����) :
//
//      PARAM_ADC_CLOCK_SYNC_MODE
//
//----------------------------------------------

#define MODE_ADC_CLK_SYNC_DEFAULT       0x00080000      // Select no signal to synchronize with ADC Clock
                                                        // (KOR: ADC Clock�� ���⸦ ���� ��ȣ�� �������� ����)

#define MODE_ADC_CLK_SYNC_F0_INT_SIG0   0x00080100      // Select Int Sig0 to synchronize with ADC Clock
                                                        // (KOR: ADC Clock�� ���⸦ ���� ��ȣ�� INT_Sig0 ��ȣ ��� ���)

#define MODE_ADC_CLK_SYNC_F0_INT_SIG1   0x00080200      // Select Int Sig1 to synchronize with ADC Clock
                                                        // (KOR: ADC Clock�� ���⸦ ���� ��ȣ�� INT_Sig1 ��ȣ ��� ���)

#define MODE_ADC_CLK_SYNC_F0_INT_SIG2   0x00080400      // Select Int Sig2 to synchronize with ADC Clock
                                                        // (KOR: ADC Clock�� ���⸦ ���� ��ȣ�� INT_Sig2 ��ȣ ��� ���)




//##################################################
//
// 3. Constants for ANALOG channel setup
//
//##################################################

//----------------------------------------------
// 3.1 Gain of Analog channel (Only for Packed mode)
//----------------------------------------------

//++++++++++++++++++++++++++++++++++
// Structure : BOARD_CHANNEL_PROP
//----------------------------------
//     @ variable name - Gain
//++++++++++++++++++++++++++++++++++

#define MODE_GAIN_X1                    0x00
#define MODE_GAIN_X2                    0x01
#define MODE_GAIN_X4                    0x02
#define MODE_GAIN_X8                    0x03
#define MODE_GAIN_X16                   0x04

#define CHANNEL_GROUP_MIN               0x08
#define CHANNEL_GROUP_MAX               0x10



//----------------------------------------------
// 3.3 AC/DC Coupling of Analog channel
// (ORION-DSA-0824 Series, ORION-DSA-0424 Only)
//----------------------------------------------

//++++++++++++++++++++++++++++++++++
// Structure : BOARD_CHANNEL_AI_AMP
//----------------------------------
//     @ variable name - AcCoupling
//++++++++++++++++++++++++++++++++++

#define AI_AMP_AC_COUPLING_3P4          0x0000          // AC Coupling -> 3.4Hz
#define AI_AMP_AC_COUPLING_0P15         0x0001          // AC Coupling -> 0.15Hz
#define AI_AMP_DC_COUPLING              0x0002          // DC Coupling




//----------------------------------------------
// 3.4 AMP Gain of Analog channel
//----------------------------------------------

//++++++++++++++++++++++++++++++++++
// Structure : BOARD_CHANNEL_AI_AMP
//----------------------------------
//     @ variable name - Gain
//++++++++++++++++++++++++++++++++++

#define AI_AMP_GAIN_1                   0x0000          // Amp_Gain -> x1
#define AI_AMP_GAIN_5                   0x0001          // Amp_Gain -> x5
#define AI_AMP_GAIN_20                  0x0002          // Amp_Gain -> x20
#define AI_AMP_GAIN_100                 0x0003          // Amp_Gain -> x100




//##################################################
//
// 4. Constants for COUNTER channel setup
//
//##################################################

//----------------------------------------------
// 4.1 Basic Constants for Counter channel setup
//----------------------------------------------

//++++++++++++++++++++++++++++++++++
// Structure : BOARD_CTR_CHANNEL
//----------------------------------
//     @ variable name - CounterKind
//++++++++++++++++++++++++++++++++++
// Counter Type

#define MODE_CTR_SIMPLE_EVENT           0x0000          // Simple Event mode
#define MODE_CTR_GATED_EVENT            0x0001          // Gated Event mode
#define MODE_CTR_TIMER                  0x0002          // Timer mode
#define MODE_CTR_SPM                    0x0003          // Single Period mode
#define MODE_CTR_SPM_ZERO               0x0004          // Single Period mode(Zero)
#define MODE_CTR_SPWM                   0x0005          // Single Pulse Width mode
#define MODE_CTR_SPWM_ZERO              0x0006          // Single Pulse Width mode(Zero)
#define MODE_CTR_TSESM                  0x0007          // Two Pulse Edge Separation mode
#define MODE_CTR_TSESM_ZERO             0x0008          // Two Pulse Width mode(Zero)
#define MODE_CTR_ENC_X1                 0x0009          // Encoder Counter(X1 mode)
#define MODE_CTR_ENC_X2                 0x000a          // Encoder Counter(X2 mode)
#define MODE_CTR_ENC_X4                 0x000b          // Encoder Counter(X4 mode)
#define MODE_CTR_ENC_TWO_PLS            0x000c          // Encoder Counter(A-Up/B-Down)
#define MODE_CTR_ZERO_EVENT             0x000D          // Zero Event mode


//++++++++++++++++++++++++++++++++++
// Structure : BOARD_CTR_CHANNEL
//----------------------------------
//     @ variable name - AssignedAuxPin
//                       AssignedGatePin
//                       AssignedSourcePin
//++++++++++++++++++++++++++++++++++
// Basic Input Signal fo Counter

#define MODE_CTR_PIN_NONE               0x0000          // Not select (KOR: ���� ���� ���� ����)

#define MODE_CTR_PIN_SOURCE             0x0001          // Connect SOURCE signal to the specific counter pin
                                                        // (KOR: ī������ �Է� ��ȣ�� SOURCE ������ �Է� ���� ��ȣ ���)

#define MODE_CTR_PIN_SOURCE_PAIR        0x0002          // Connect SOURCE signal of PAIR counter to specific counter pin
                                                        // (KOR: ī������ �Է� ��ȣ�� PAIR ī������ SOURCE ������ �Է� ���� ��ȣ ���)

#define MODE_CTR_PIN_GATE               0x0003          // Connect GATE signal to the specific counter pin
                                                        // (KOR: ī������ �Է� ��ȣ�� GATE ������ �Է� ���� ��ȣ ���)

#define MODE_CTR_PIN_GATE_PAIR          0x0004          // Connect GATE signal of PAIR counter to the specific counter pin
                                                        // (KOR: ī������ �Է� ��ȣ�� PAIR ī������ GATE ������ �Է� ���� ��ȣ ���)

#define MODE_CTR_PIN_AUX                0x0005          // Connect AUX signal to the specific counter pin
                                                        // (KOR: ī������ �Է� ��ȣ�� AUX ������ �Է� ���� ��ȣ ���)

#define MODE_CTR_PIN_AUX_PAIR           0x0006          // Connect AUX signal of PAIR counter to the specific counter pin
                                                        // (KOR: ī������ �Է� ��ȣ�� PAIR ī������ AUX ������ �Է� ���� ��ȣ ���)

#define MODE_CTR_PIN_ADC_CLK            0x0009          // Connect AI Sampling Clock to the specific counter
                                                        // (KOR: ī������ �Է� ��ȣ�� ADC Clock ���)


//++++++++++++++++++++++++++++++++++
// Structure : BOARD_CTR_CHANNEL
//----------------------------------
//     @ variable name - AssignedAuxPin
//++++++++++++++++++++++++++++++++++
// Internal 40, 20, 10 MHz Clock

#define MODE_CTR_PIN_TIMEBASE_40M       0x000A          // Connect inner 40MHz clock (KOR: ���� 40MHz Clock�� �Է½�ȣ�� ���)
#define MODE_CTR_PIN_TIMEBASE_20M       0x000B          // Connect inner 20MHz clock (KOR: ���� 20MHz Clock�� �Է½�ȣ�� ���)
#define MODE_CTR_PIN_TIMEBASE_10M       0x000C          // Connect inner 10MHz clock (KOR: ���� 10MHz Clock�� �Է½�ȣ�� ���)


//++++++++++++++++++++++++++++++++++
// Structure : BOARD_CTR_CHANNEL
//----------------------------------
//     @ variable name - AssignedAuxPin
//                       AssignedGatePin
//                       AssignedSourcePin
//++++++++++++++++++++++++++++++++++
// MUX signal

#define MODE_CTR_PIN_MUX_EXT_TRIG       0x0600          // Connect External Trigger signal to the specific counter
                                                        // (KOR: ī������ �Է� ��ȣ�� �ܺ� Ʈ���� ��ȣ ���)

#define MODE_CTR_PIN_MUX_EXT_CLK        0x0700          // Connect External Clock signal the specific counter
                                                        // (KOR: ī������ �Է� ��ȣ�� �ܺ� Ŭ�� ��ȣ ���)

#define MODE_CTR_PIN_MUX_DIV_EXT_CLK1   0x0800          // Connect EXT_CLK1 signal to the specific counter
                                                        // (KOR: ī������ �Է� ��ȣ�� EXT_CLK1 ��ȣ ���)

#define MODE_CTR_PIN_MUX_DIV_EXT_CLK2   0x0900          // Connect EXT_CLK2 signal to the specific counter
                                                        // (KOR: ī������ �Է� ��ȣ�� EXT_CLK2 ��ȣ ���)

#define MODE_CTR_PIN_MUX_DI6            0x1600          // Connect DI 6 signal to the specific counter
                                                        // (KOR: ī������ �Է� ��ȣ�� DI 6 �Է� ��ȣ ���)

#define MODE_CTR_PIN_MUX_DI7            0x1700          // Connect DI 7 signal to the specific counter
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
//      Single-Period, Single-Pulse Width, Two-Single Edge-Separation, Frequency(Timer) ������ ���

#define MODE_CTR_TRANMODE_80M           0x0000          // inner 80MHz Clock
#define MODE_CTR_TRANMODE_40M           0x0001          // inner 40MHz Clock
#define MODE_CTR_TRANMODE_20M           0x0002          // inner 20MHz Clock
#define MODE_CTR_TRANMODE_10M           0x0003          // inner 10MHz Clock


//++++++++++++++++++++++++++++++++++
// Structure : BOARD_CTR_CHANNEL
//----------------------------------
//     @ variable name - FilterAuxPin
//                       FilterGatePin
//                       FilterSourcePin
//++++++++++++++++++++++++++++++++++
// Digital Filter

#define MODE_CTR_FILTER_BYPASS          0x0000          // No Digital Filtering
#define MODE_CTR_FILTER_LESS_100NS      0x0001          // 100ns Digital Filter
#define MODE_CTR_FILTER_LESS_200NS      0x0002          // 200ns Digital Filter
#define MODE_CTR_FILTER_LESS_500NS      0x0003          // 500ns Digital Filter
#define MODE_CTR_FILTER_LESS_1US        0x0004          // 1us Digital Filter
#define MODE_CTR_FILTER_LESS_2US        0x0005          // 2us Digital Filter
#define MODE_CTR_FILTER_LESS_4US        0x0006          // 4us Digital Filter
#define MODE_CTR_FILTER_LESS_5US        0x0007          // 5us Digital Filter




//----------------------------------------------
// 4.2 Constants for Counter channel properties
//----------------------------------------------

//++++++++++++++++++++++++++++++++++
// Structure : BOARD_SUB_CTR_CHANNEL_ATTR
//----------------------------------
//     @ variable name - CtrSigType
//++++++++++++++++++++++++++++++++++
// Input Signal of Sub Counter

#define MODE_SUB_CTR_SIG_NONE           0x00            // No input signal of Sub Counter
                                                        // (KOR: Sub ī���Ϳ� �Է� ��ȣ ����)

#define MODE_SUB_CTR_SIG_FILTER_SRC     0x01            // Filtered Source signal of Sub Counter
                                                        // (KOR: Sub ī���Ϳ� filtered Source ��ȣ ���)

#define MODE_SUB_CTR_SIG_FILTER_GATE    0x02            // Filtered Gate signal of Sub Counter
                                                        // (KOR: Sub ī���Ϳ� filtered Gate ��ȣ ���)

#define MODE_SUB_CTR_SIG_ENCODER_OUT    0x03            // Encoder Out signal of Sub Counter
                                                        // (KOR: Sub ī���Ϳ� Encoder Out ��ȣ ���)


//++++++++++++++++++++++++++++++++++
// Structure : BOARD_SUB_CTR_CHANNEL_ATTR
//----------------------------------
//     @ variable name - CtrMode
//++++++++++++++++++++++++++++++++++
// Sub Counter Type

#define MODE_SUB_CTR_MOD_NO_USE         0x00            // Not select counter mode of Sub Counter
                                                        // (KOR: Sub ī���� Ÿ���� �������� ����)

#define MODE_SUB_CTR_MOD_SINGLE_PERIOD  0x01            // Single Period mode of Sub Counter
                                                        // (KOR: Sub ī���� Ÿ���� Single Period mode�� ����)

#define MODE_SUB_CTR_MOD_TWO_SIG_EDGE   0x02            // Two Pulse Edge Separation mode of Sub Counter
                                                        // (KOR: Sub ī���� Ÿ���� Two Pulse Edge Separation mode�� ����)




//##################################################
//
// 5. Constants for External Clock setup
//
//##################################################

//----------------------------------------------
// 5.1 External Clock mode
//
//      //************************************
//      // EXT_CLOCK mode is the combination of
//      // <Input Source> and <Polarity>
//      //
//      // KOR: �ܺ� Ŭ�� ���� <Input Source> ��
//      //      <Polarity>�� �������� �̷����
//      //************************************
//
//      Related Parameter (���� �Ķ����) :
//
//      PARAM_EXT_CLOCK_MODE
//
//----------------------------------------------

// Input sources for "External Clock Out", "External Trigger Out", "EXT_CLK1,2 Out"
// These are also used for "INT_SIG0,1,2"
//
// KOR: Clock Output�� �Է����� ����� ��ȣ(Input Source) ����
//      "External Clock Out", "External Trigger Out", "EXT_CLK1,2 Out"�� ���� ���
//      "INT_SIG0,1,2" ������ ���

#define MODE_CLOCK_IN_SEL_MASK          0x0008F000      //
#define MODE_CLOCK_IN_SEL_12M8          0x00080000      // 12.8MHz Clock
#define MODE_CLOCK_IN_SEL_MCLK          0x00081000      // MCLK (Master clock)
#define MODE_CLOCK_IN_SEL_SCLK          0x00082000      // SCLK (Serial clock)
#define MODE_CLOCK_IN_SEL_ADC_CLK       0x00083000      // Reversed ADC clock
#define MODE_CLOCK_IN_SEL_CONT_LRCLK    0x00084000      // Sampling Clock
#define MODE_CLOCK_IN_SEL_ZERO_2        0x00085000      // '0'
#define MODE_CLOCK_IN_SEL_2D_EXT_ACQ    0x00086000      // External Trigger signal
#define MODE_CLOCK_IN_SEL_2D_EXT_CLK    0x00087000      // External Clock signal
#define MODE_CLOCK_IN_SEL_2D_DIV_EXCLK1 0x00088000      // EXT_CLK1 signal
#define MODE_CLOCK_IN_SEL_2D_DIV_EXCLK2 0x00089000      // EXT_CLK2 signal
#define MODE_CLOCK_IN_SEL_F0_INT_SIG0   0x0008A000      // INT_Sig0 signal
#define MODE_CLOCK_IN_SEL_F0_INT_SIG1   0x0008B000      // INT_Sig1 signal
#define MODE_CLOCK_IN_SEL_F0_INT_SIG2   0x0008C000      // INT_Sig2 signal
#define MODE_CLOCK_IN_SEL_MO_SRC_SEL0   0x0008D000      // Counter channel 0 Source signal
#define MODE_CLOCK_IN_SEL_MO_SRC_SEL1   0x0008E000      // Counter channel 1 Source signal
#define MODE_CLOCK_IN_SEL_MO_START_ACQ  0x0008F000      // Start acquisition signal


// Polarity for  "External Clock Out" and "External Trigger Out"
// Remark - "EXT_CLK1,2 Out" use MODE_CLKOUT_NORMAL(...) as Polarity setup
//
// KOR: Clock Output�� �Է����� ����� ��ȣ�� Polarity ����
//      "External Clock Out"�� "External Trigger Out"�� ���� ���
//      ���� - "EXT_CLK1,2 Out"���� MODE_CLKOUT_NORMAL(...) �� ���

#define MODE_EXT_OUTPUT_NORMAL          0x00100000      // Same polarity as the selected clock signal
                                                        // (KOR: ���õ� Ŭ�� ��°� ���� polarity�� ����ϴ� ���)

#define MODE_EXT_OUTPUT_REVERSE         0x00100100      // Reversed polarity as the selected clock signal
                                                        // (KOR: ���õ� Ŭ�� ��¿� reverse�� polarity�� ����ϴ� ���)

#define MODE_EXT_OUTPUT_CONST_LOW       0x00100200      // Low level signal

#define MODE_EXT_OUTPUT_CONST_HIGH      0x00100400      // High level signal

#define MODE_EXT_OUTPUT_MULTIPLY        0x00100800      // Mutiplied signal of the selected clock signal
                                                        // (KOR: ���õ� Ŭ���� ����ڰ� ������ ����ŭ ����� ����ϴ� ���)




//##################################################
//
// 6. Constants for External Trigger setup
//
//##################################################

//----------------------------------------------
// 6.1 External Trigger mode
//
//      //**********************************
//      // EXT_TRIG mode is the combination of
//      // <Input/Output mode>,
//      // Input mode's <Start Sel mode> and <Input Pin>,
//      // Output mode's <Input Source> and <Polarity>
//
//      // KOR: �ܺ� Ʈ������ ��� ������
//      //      <Input/Output mode>,
//      //      Input mode�� <Start Sel mode>, <Input Pin>,
//      //      Output mode�� <Input Source>, <Polarity>��
//      //      �������� �̷����
//      //**********************************
//
//      Related parameter (���� �Ķ����) :
//
//      PARAM_EXT_TRIGGER_MODE
//
//----------------------------------------------

//************************
// 6.1.1 Input/Output mode of External Trigger
//************************
#define MODE_EXT_SET_INPUT              0x00100000      // Set Exeternal Trigger signal as Input mode
                                                        // (KOR: �ܺ� Ʈ���� ��ȣ�� �Է� ���� ����)

#define MODE_EXT_SET_OUTPUT             0x00100010      // Set Exeternal Trigger signal as Output mode
                                                        // KOR: �ܺ� Ʈ���� ��ȣ�� ��� ���� ����)


//************************
// 6.1.2 Properties of External Trigger Input mode
//       (�ܺ� Ʈ������ �Է� ��� �Ӽ� ����)
//************************

// Start mode of Trigger Input
// (Ʈ���� �Է��� ���� ��� ����)

#define MODE_ACQ_START_MASK             0x0002000F      //
#define MODE_ACQ_START_GATED            0x00020000      // Start acquistion when Trigger signal is High state (Gated Start : default)
                                                        // (KOR: Ʈ���� ��ȣ�� High(active)�� ���� ����(�⺻��))

#define MODE_ACQ_START_POS_EDGE         0x00020001      // Start acquistion when Trigger signal is changed from low to high (Positive Edge)
                                                        // (KOR: Ʈ���� ��ȣ�� low���� high�� ����� �� Ʈ���ŷ� �ν��ϰ� ��������)

#define MODE_ACQ_START_NEG_EDGE         0x00020002      // Start acquistion when Trigger signal is changed from high to low (Negative Edge)
                                                        // (KOR: Ʈ���� ��ȣ�� high���� low�� ����� �� Ʈ���ŷ� �ν��ϰ� ��������)

#define MODE_ACQ_START_BOTH_EDGE        0x00020003      // Start acquistion when Trigger signal is changed from high to low or vice versa (Both Edge)
                                                        // (KOR: Ʈ���� ��ȣ�� high���� low �Ǵ� low���� high�� ����� �� Ʈ���ŷ� �ν��ϰ� ��������)


// Input source signal of External Trigger Input
// (�ܺ� Ʈ���� �Է��� �Է� ��ȣ ����)

#define MODE_EXT_TRG_ISEL_MASK          0xF0020000      //
#define MODE_EXT_TRG_ISEL_DEFAULT       0x00020000      // Not select (default)

#define MODE_EXT_TRG_ISEL_2D_EXT_ACQ    0x60020000      // External Trigger signal
                                                        // (KOR: External Trigger ���� ��ȣ�� �ܺ� Ʈ���� �Է� ��ȣ�� ���)

#define MODE_EXT_TRG_ISEL_2D_EXT_CLOCK  0x70020000      // External Clock signal
                                                        // (KOR: External Clock ���� ��ȣ�� �ܺ� Ʈ���� �Է� ��ȣ�� ���)

#define MODE_EXT_TRG_ISEL_2D_DIV_CLK1   0x80020000      // EXT_CLK1 signal
                                                        // (KOR: EXT_CLK1 ���� ��ȣ�� �ܺ� Ʈ���� �Է� ��ȣ�� ���)

#define MODE_EXT_TRG_ISEL_2D_DIV_CLK2   0x90020000      // EXT_CLK2 signal
                                                        // (KOR: EXT_CLK2 ���� ��ȣ�� �ܺ� Ʈ���� �Է� ��ȣ�� ���)


//************************
// 6.1.3 Properties of External Trigger Output mode
//       (�ܺ� Ʈ������ ��� ��� �Ӽ� ����)
//************************

// Input source singal of External Trigger Output
// Use MODE_CLOCK_IN_SEL_12M8(...) togehter with "EXT_CLOCK", "EXT_CLK1,2"
//
// KOR: Trigger Output�� �Է� ��ȣ ����
//      MODE_CLOCK_IN_SEL_12M8(...)�� "EXT_CLOCK", "EXT_CLK1,2"�� �Բ� ���


// Polarity of External Trigger Output
// Use MODE_EXT_OUTPUT_NORMAL(...) together with "EXT_CLOCK"
//
// KOR: Trigger Output�� Polarity
//      MODE_EXT_OUTPUT_NORMAL(...)�� "EXT_CLOCK"�� �Բ� ���




//##################################################
//
// 7. Constants for External Clock Out 1, 2 setup
//
//##################################################

//----------------------------------------------
// 7.1 External Clock Out 1, 2 mode
//
//      //************************************
//      // EXT_CLOCK1,2 mode is the combination
//      // of <Input Source> and <Polarity>
//      //
//      // KOR: EXT_CLOCK1,2�� mode ������
//      // <Input Source>, <Polarity>��
//      // �������� �̷����
//      //************************************
//
//      Related Parameter (���� �Ķ����) :
//
//      PARAM_CLKOUT0_MODE,
//      PARAM_CLKOUT1_MODE
//
//----------------------------------------------

// Input  Source of External Clock Output
// Use MODE_CLOCK_IN_SEL_12M8(...) together with "EXT_CLOCK", "EXT_TRIGGER"
//
// KOR: External Clock Output�� �Է� ��ȣ ����
//      MODE_CLOCK_IN_SEL_12M8(...)�� "EXT_CLOCK", "EXT_TRIGGER"�� �Բ� ���


// Polarity of External Clock Out 1, 2

#define MODE_CLKOUT_NORMAL              0x00200000      // Same polarity as the selected clock signal
                                                        // (KOR: ���õ� Ŭ�� ��°� ���� polarity�� ����ϴ� ���)

#define MODE_CLKOUT_REVERSE             0x00200001      // Reversed polarity as the selected clock signal
                                                        // (KOR: ���õ� Ŭ�� ��¿� reverse�� polarity�� ����ϴ� ���)

#define MODE_CLKOUT_CONST_LOW           0x00200002      // Low level signal
#define MODE_CLKOUT_CONST_HIGH          0x00200004      // High level signal
#define MODE_CLKOUT_MULTIPLY            0x00200008      // Mutiplied signal of the selected clock signal (Only for Orion-1624E)
                                                        // (KOR: ���õ� Ŭ���� ����ڰ� ������ ����ŭ ����� ����ϴ� ���)
                                                        // Orion-1624E ���� ��� ����




//##################################################
//
// 8. Constants for Internal Div Sig 0, 1, 2 setup
//
//##################################################

//----------------------------------------------
// 8.1 Internal Div Sig 0, 1, 2 mode
//
//      //*******************************************************
//      // INT_DIV_SIG0,1,2 mode is the combination of
//      // <Input Source>, <Inverted>, <Async Selection>
//      //
//      // KOR: INT_DIV_SIG0,1,2�� mode ������
//      //      <Input Source>, <Inverted>, <Async Selection>��
//      //      �������� �̷����
//      //*******************************************************
//
//      Related Parameter (���� �Ķ����) :
//
//      PARAM_DIV_SIG0_MODE,
//      PARAM_DIV_SIG1_MODE,
//      PARAM_DIV_SIG2_MODE
//
//----------------------------------------------

// Input source of INT_DIV_SIG0,1,2
// Use MODE_CLOCK_IN_SEL_12M8(...) together with "EXT_CLOCK", "EXT_TRIGGER", "EXT_CLK1,2"
//
// KOR: INT_DIV_SIG0,1,2�� �Է� ��ȣ ����
//      MODE_CLOCK_IN_SEL_12M8(...)�� "EXT_CLOCK", "EXT_TRIGGER", "EXT_CLK1,2"�� �Բ� ���


// Start signal level of Clock Out

#define MODE_CLOCK_START_LOW            0x00080000      // Start with Low level signal
#define MODE_CLOCK_START_HIGH           0x00080010      // Start with High level signal


// Asynchronization mode of Clock Out
// (Clock Out �񵿱� ��� ����)

#define MODE_CLOCK_ASYNC_NONE           0x00080000      // Synchronized signal of "Clock Out" with ADC clock (Default)
                                                        // (KOR: ADC Ŭ���� ����ȭ�� Ŭ�� ��� (�⺻��))

#define MODE_CLOCK_ASYNC_ENABLE         0x00080080      // Asynchronized signal of "Clock Out" with ADC clock
                                                        // (KOR: ADC Ŭ���� �񵿱�ȭ�� Ŭ�� ���)


// Multiplier of Master Clock(MCLK) for Clock Out
// It can be applied only when Input Source is MCLK
// Use it together with "PARAM_DIV_SIG0(1,2)_MULTIPLIER"
//
// KOR: Clock Out�� MCLK�� ���� Multiplier ����
//      Input Source �� MCLK�� ��쿡�� �����
//      "PARAM_DIV_SIG0(1,2)_MULTIPLIER"�� �Բ� ���

#define MODE_CLKOUT_X2                  0x01            // MCLK x 2
#define MODE_CLKOUT_X4                  0x02            // MCLK x 4
#define MODE_CLKOUT_X8                  0x03            // MCLK x 8
#define MODE_CLKOUT_X16                 0x04            // MCLK x 16
#define MODE_CLKOUT_X32                 0x05            // MCLK x 32




//##################################################
//
// 9. Constants for Counter Clock Out setup of Expansion Counter Board
//
//##################################################

//----------------------------------------------
// 9.1 Counter Clock Out mode of Expansion Counter Board
//
//      Related Parameter (���� �Ķ����) :
//
//      PARAM_CTR_CLKOUT0_MODE,
//      PARAM_CTR_CLKOUT1_MODE
//
//----------------------------------------------

#define MODE_CTR_CLKOUT_SOURCE_DI_SCLK          0x00    // Use Sampling Clock x 64 for the source signal of "Counter Clock Out"
                                                        // (KOR: "Counter Clock Out"�� Source ��ȣ�� Sampling Clock x 64�� ��ȣ ���)

#define MODE_CTR_CLKOUT_SOURCE_TIMEBASE_80M     0x01    // Use inner 80MHz Clock for the source signal of "Counter Clock Out"
                                                        // (KOR: "Counter Clock Out"�� Source ��ȣ�� ���� 80MHz Clock ���)

#define MODE_CTR_CLKOUT_START_HIGH              0x02    // Start with High level signal
                                                        // (KOR: "Counter Clock Out"�� ����� High Level���� �����ϵ��� ����)




//##################################################
//
// 10. Constants for CAN
//
//##################################################

//----------------------------------------------
// 10.1 CAN mode
//----------------------------------------------

//++++++++++++++++++++++++++++++++++
// Structure : BOARD_CAN_PROP
//----------------------------------
//     @ variable name - Sync_100K
//                       Sync_AI
//++++++++++++++++++++++++++++++++++

#define MODE_CAN_SYNC_100K              0x00800001      // Sync 100K
#define MODE_CAN_SYNC_AI                0x00800002      // Sync AI




//##################################################
//
// 11. Constants for RS485
//
//##################################################

//----------------------------------------------
// 11.1 RS485 Baud Rate
//----------------------------------------------

//++++++++++++++++++++++++++++++++++
// Structure : BOARD_RS485_PROP
//----------------------------------
//     @ variable name - BaudRate
//++++++++++++++++++++++++++++++++++

#define MODE_BAUDRATE_9600              0x00            // Baudrate 9600 bps
#define MODE_BAUDRATE_19200             0x01            // Baudrate 19200 bps
#define MODE_BAUDRATE_38400             0x02            // Baudrate 38400 bps
#define MODE_BAUDRATE_57600             0x03            // Baudrate 57600 bps
#define MODE_BAUDRATE_115200            0x04            // Baudrate 115200 bps




//##################################################
//
// 12. Constants for Error Handling
//
//##################################################

//----------------------------------------------------------------------------
// 12.1 Error Codes Constants
//
//      Related Parameter (���� �Ķ����) :
//
//      PARAM_LAST_ERROR
//
//----------------------------------------------------------------------------

#define ERR_NONE                        0x0             // No error
#define ERR_BOARD_NOT_FOUND             0x0101          // Cannot find DEWE-ORION Board     (KOR: DEWE-ORION Board�� ã�� ����)
#define ERR_BOARD_NOT_OPEN              0x0102          // Cannot open DEWE-ORION Board     (KOR: DEWE-ORION Board�� ���� �� �� ����)
#define ERR_BOARD_NOT_MASTER            0x0103          // Not set Master board             (KOR: Master ���尡 �����Ǿ� ��������)

#define ERR_DAQ_ALREADY_STARTED         0x0201          // RtStart() is already started     (KOR: RtStart() �Լ��� �̹� ����Ǿ���)
#define ERR_DAQ_NOT_STARTED             0x0202          // RtStart() is not started         (KOR: RtStart() �Լ��� ���۵Ǿ� ���� ����)
#define ERR_DAQ_CHANNEL_NOT_ASSIGNED    0x0203          // Channel is not assigned          (KOR: ������ ä���� ��ϵǾ� ���� ����)
#define ERR_DAQ_CANNOT_CONFIGURE        0x0204          // Cannot configure a board         (KOR: ���忡 ���������� �� �� ����)
#define ERR_DAQ_CANNOT_START            0x0205          // Cannot run RtStart()             (KOR: RtStart() �Լ��� ������ �� ����)
#define ERR_DAQ_CANNOT_UPDATE_CALINFO   0x0206          // Cannot update "CalInfo"          (KOR: CalInfo�� ������Ʈ �� �� ����)

#define ERR_INVALID_BOARD_NO            0x0301          // Invalid board number             (KOR: �߸��� ���� ��ȣ)
#define ERR_INVALID_CHANNEL_NO          0x0302          // Invalid channel number           (KOR: �߸��� ä�� ��ȣ)
#define ERR_INVALID_CHANNEL_COUNT       0x0303          // Invalid the number of channels   (KOR: �߸��� ä�μ��� ������)
#define ERR_INVALID_VALUE               0x0304          // Invalid parameter value          (KOR: �߸��� �Ķ���� ������)
#define ERR_INVALID_PARAM_ID            0x0305          // Invalid parameter ID             (KOR: �߸��� �Ķ���� ID)
#define ERR_INVALID_IOCTL               0x0306          // Invalid IOCTL                    (KOR: �߸��� IOCTL �ڵ���)
#define ERR_NOT_SUPPORTED_FUNCTION      0x0307          // Not supported function           (KOR: �����Ǵ� �Լ��� �ƴ�)

#define ERR_DMA_CANNOT_OPEN             0x0401          // Cannot open DMA                  (KOR: DMA�� ���� ����)
#define ERR_DMA_CANNOT_START            0x0402          // Cannot start DMA                 (KOR: DMA ������ ������ �� ����)

#define ERR_MEM_BUFFER_NOT_ASSIGNED     0x0701          // Not assigned DMA buffer          (KOR: �����޸𸮰� �Ҵ� �Ǿ����� ����)
#define ERR_MEM_INVALID_BLOCK_COUNT     0x0702          // Invalid the number of Blocks     (KOR: �߸��� ���ī��Ʈ ���� ����)

#define ERR_STATUS_DMA                  0x0901          // DMA Transfer error               (KOR: DMA ���� ���� �߻�)
#define ERR_STATUS_FIFO_FULL            0x0902          // FIFO Full error                  (KOR: FIFO Full ���� �߻�)
#define ERR_STATUS_INT                  0x0903          // Interrupt Clear error            (KOR: Interrup ��ȣ�� Clear�ȵ�)
#define ERR_STATUS_OVERWRITE            0x0904          // Buffer Overwrite error           (KOR: �����޸� OverWrite ���� �߻�)

#define ERR_TIMEOUT                     0x0a01          // Timeout error                    (KOR: TimeOut ���� �߻�)

#define ERR_NOT_SUPPORT_X64_DMA_ADDR    0x0a02          // Not support x64 OS               (KOR: x64 OS �������� ����)










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
    DWORD       Reserved;
    WORD        FpgaMainVer;
    WORD        FpgaSubVer;
    DWORD       ModelNo;
    DWORD       MaxChannelCountAI;
    DWORD       MaxChannelCountCTR;
    DWORD       MaxChannelCountSubCTR;
    DWORD       MaxChannelCountDI;
    DWORD       MaxChannelCountCAN;
    DWORD       MaxSampleRate;
    DWORD       MinSampleRate;
    DWORD       Resolution;
    DWORD       InputVoltageRange;
    BOOLEAN     SupportRs485;
    BOOLEAN     SupportCTR;
    BOOLEAN     SupportDI;
    BOOLEAN     SupportCAN;
    BOOLEAN     SupportExtTrigger;
    BOOLEAN     SupportExtClock;
    BOOLEAN     SupportCTR_ClkOut;
    BOOLEAN     SupportCTR_SharedDI;
    BOOLEAN     SupportAI_AMP;
    BOOLEAN     FreeParam1;
    BOOLEAN     FreeParam2;
    BOOLEAN     SupportSubCTR;
    BOOLEAN     SupportExtPLLClock;
} BOARD_SPEC_INFO, *PBOARD_SPEC_INFO;


// Hardware(Product) version infromation

typedef struct tagBOARD_CAL_INFO {
    WORD Reserved;
    WORD PcbVer;
    WORD BoardType;
    WORD SeqNo;
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

// AMP propertiess of Analog channel (Only for ORION-0824, ORION-0424)
// (KOR: AI ä���� AMP �Ӽ� ����)

typedef struct tagBOARD_CHANNEL_AI_AMP {
    WORD        AcCoupling;
    WORD        Gain;
    BOOLEAN     CurrentOff;
    BOOLEAN     SingleEnded;
} BOARD_CHANNEL_AI_AMP, *PBOARD_CHANNEL_AI_AMP;


// Analog channel properties
// (KOR: AI ä���� �Ӽ� ����)

typedef struct tagBOARD_CHANNEL_PROP {
    BOOLEAN     EnabledPacked;      // R
    BOOLEAN     SupportAmp;         // R
    BYTE        Gain;               // R/W
    BOARD_CHANNEL_AI_AMP Amp;       // W
} BOARD_CHANNEL_PROP, *PBOARD_CHANNEL_PROP;


// ICP propertiess of Analog channel (Only for ORION-0824, ORION-0424)
// (KOR: AI ä���� ICP �Ӽ�)

typedef struct tagBOARD_AI_CHANNEL_PROP_ICP {
    WORD    ICPControl;             // R/W - 4mV / 8mV
    WORD    ICPStatus;              // R
} BOARD_AI_CHANNEL_PROP_ICP, *PBOARD_AI_CHANNEL_PROP_ICP;


// Sub Counter channel information
// (KOR: Sub ī���� ä�� ����)

typedef struct tagBOARD_SUB_CTR_CHANNEL_ATTR {
    WORD    CtrSigType;
    WORD    CtrMode;
} BOARD_SUB_CTR_CHANNEL_ATTR, *PBOARD_SUB_CTR_CHANNEL_ATTR;


// Trigger level of Adjustable Counter/Digital Input
// (KOR: CTR/DI ä���� Ʈ���� ����)

typedef struct tagBOARD_ADJ_TRG_VAL {
    int     TrgHighVal;
    int     TrgLowVal;
} BOARD_ADJ_TRG_VAL, *PBOARD_ADJ_TRG_VAL;


// DAC level of Adjustable Counter/Digital Input
// (KOR: CTR/DI ä���� DAC ����)

typedef struct tagBOARD_ADJ_DAC_VAL {
    WORD    DacHighVal;
    WORD    DacLowVal;
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
    BOOLEAN UseMainCTR;
    BOOLEAN UseSubCTR;
    BOARD_SUB_CTR_CHANNEL_ATTR SubCTR;
} BOARD_CTR_CHANNEL, *PBOARD_CTR_CHANNEL;


// Counter channel properties

typedef struct tagBOARD_CTR_CHANNEL_PROP {
    BOOLEAN SupportFilter;                          // R
    BOOLEAN SupportMux;                             // R
    BOOLEAN SupportSubCTR_CH;                       // R
    BOOLEAN EnabledCTR;                             // R
    BOOLEAN EnabledMainCTR;                         // R
    BOOLEAN EnabledSubCTR;                          // R
    BOOLEAN DoManualReset;                          // W
    BOOLEAN SupportCtrAdj;                          // R
    BOOLEAN ObsoleteCtrAdjAcCoupling[3];            // R/W
    BOARD_ADJ_TRG_VAL ObsoleteCtrAdjTrgLevel[4];    // R/W
    BOARD_ADJ_DAC_VAL ObsoleteCtrAdjDacVal[4];      // R
} BOARD_CTR_CHANNEL_PROP, *PBOARD_CTR_CHANNEL_PROP;


// Information about Adujustable Trigger and  AC/DC Coupling functions of Counter channel
// (KOR: CTR ä���� Adujustable Trigger, AC/DC Coupling �������ο� Ʈ���� ���� ���� ����)

typedef struct tagBOARD_ADJ_CHANNEL_PROP {
    BOOLEAN SupportAdj[40];                 // R
    BOOLEAN SupportAcDc[40];                // R
    BOOLEAN AdjAcCoupling[40];              // R/W
    BOARD_ADJ_TRG_VAL AdjTrgLevel[40];      // R/W
    BOARD_ADJ_DAC_VAL AdjDacVal[40];        // R
} BOARD_ADJ_CHANNEL_PROP, *PBOARD_ADJ_CHANNEL_PROP;


// Digital I/O channel inforamtion

typedef struct tagBOARD_DI_CHANNEL {
    BOOLEAN Use32bit;
    int     FilterDIPin[32];
} BOARD_DI_CHANNEL, *PBOARD_DI_CHANNEL;


// Digital I/O channel properties

typedef struct tagBOARD_DI_CHANNEL_PROP {
    BOOLEAN SupportFilter;                  // R
    BOOLEAN SupportOutputHiByte;            // R
    BOOLEAN Support32bit;                   // R
    BOOLEAN FreeParam1;
    BOOLEAN DoOutputHiByte;                 // W
    BYTE    HiByte;                         // R/W
    BYTE    LoByte;                         // R
    WORD    FreeParam2[8][2];               // W
} BOARD_DI_CHANNEL_PROP, *PBOARD_DI_CHANNEL_PROP;


//==============================================================================
// 3. Structure of Data Memory information to read
//    (�����͸� �б����� �޸� ����)
//==============================================================================

// Start address, increment value, the number of blocks to read
// (KOR: ������ �����͸� �޸𸮿��� ������ �� ������ �����ּ�, ������, ��ϰ����� ������ ����ü)

typedef struct tagBOARD_READ_DATA {
    int *BufferPosArr;
    int *BufferIncArr;
    int *ReadBlockArr;
} BOARD_READ_DATA, *PBOARD_READ_DATA;

typedef struct tagBOARD_READ_DATA_ADV {
    int *BufferPosArr;
    int *BufferIncArr;
    int *ReadBlockArr;
    int *BufferAbsStartPosArr;
    int *BufferAbsEndPosArr;
} BOARD_READ_DATA_ADV, *PBOARD_READ_DATA_ADV;

//==============================================================================
// 4. CAN, RS485 information
//==============================================================================

// CAN properties

typedef struct tagBOARD_CAN_PROP {
    BOOLEAN Enabled;                    // R/W
    BOOLEAN ListenOnly;                 // R/W
    int     BaudRate;                   // R/W
    BOOLEAN Sync_100K;                  // R/W
    BOOLEAN Sync_AI;                    // R/W
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
    int     BaudRate;               // R/W
    BOOLEAN SelectSubBoard;         // R/W
} BOARD_RS485_PROP, *PBOARD_RS485_PROP;










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
typedef BOOLEAN (RT_IMPORT *PRTGETSPECINFO)(int nBoardNo, PBOARD_SPEC_INFO pInfo);
typedef BOOLEAN (RT_IMPORT *PRTGETPCIINFO)(int nBoardNo, PBOARD_PCI_INFO pPciInfo);
typedef BOOLEAN (RT_IMPORT *PRTGETBOARDINFO)(int nBoardNo, PBOARD_MISC_INFO pMiscInfo);


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
typedef BOOLEAN (RT_IMPORT *PRTGETDATA)(int nBoardNo, int aBufferPosArr[], int aBufferIncArr[], int aReadBlockArr[]);
typedef BOOLEAN (RT_IMPORT *PRTGETDATAEX)(int nBoardNo, PBOARD_READ_DATA pReadDataAI, PBOARD_READ_DATA pReadDataCTR, PBOARD_READ_DATA pReadDataDI);
typedef BOOLEAN (RT_IMPORT *PRTGETDATAEX1)(int nBoardNo, PBOARD_READ_DATA_ADV pReadDataAI, PBOARD_READ_DATA_ADV pReadDataCTR, PBOARD_READ_DATA_ADV pReadDataDI);
typedef LONGLONG (RT_IMPORT *PRTGETCURRENTPOS)(int nBoardNo);


// Multi mode

typedef BOOLEAN (RT_IMPORT *PRTSYNCREAD)(int nBoardNo, int aBufferPosArr[], int aReadBlockArr[]);
typedef BOOLEAN (RT_IMPORT *PRTSYNCGETDATA)(int nBoardNo, int aBufferPosArr[], int aBufferIncArr[], int aReadBlockArr[]);
typedef BOOLEAN (RT_IMPORT *PRTSYNCGETDATAEX)(int nBoardNo, PBOARD_READ_DATA pReadDataAI, PBOARD_READ_DATA pReadDataCTR, PBOARD_READ_DATA pReadDataDI);
typedef BOOLEAN(RT_IMPORT *PRTSYNCGETDATAEX1)(int nBoardNo, PBOARD_READ_DATA_ADV pReadDataAI, PBOARD_READ_DATA_ADV pReadDataCTR, PBOARD_READ_DATA_ADV pReadDataDI);


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
typedef BOOLEAN (RT_IMPORT *PRTGETAICHANNELPROPICP)(int nBoardNo, int nChannelNo, PBOARD_AI_CHANNEL_PROP_ICP pProp);
typedef BOOLEAN (RT_IMPORT *PRTSETAICHANNELPROPICP)(int nBoardNo, int nChannelNo, BOARD_AI_CHANNEL_PROP_ICP rProp);
typedef float (RT_IMPORT *PRTGETCHANNELFACTOR)(int nBoardNo, int nChannelNo);
typedef int (RT_IMPORT *PRTGETCHANNELOFFSET)(int nBoardNo, int nChannelNo);


// Multi mode

typedef BOOLEAN (RT_IMPORT *PRTSYNCADDCHANNEL)(int nBoardNo, int nChannelNo);
typedef int (RT_IMPORT *PRTSYNCGETMAXCHANNELCOUNT)(int nBoardNo);
typedef int (RT_IMPORT *PRTSYNCGETCHANNELCOUNT)(int nBoardNo);
typedef int (RT_IMPORT *PRTSYNCGETCHANNELNO)(int nBoardNo, int nIndex);
typedef BOOLEAN (RT_IMPORT *PRTSYNCCLEARCHANNELS)(int nBoardNo);
typedef BOOLEAN (RT_IMPORT *PRTSYNCGETCHANNELPROP)(int nBoardNo, int nChannelNo, PBOARD_CHANNEL_PROP pProp);
typedef BOOLEAN (RT_IMPORT *PRTSYNCSETCHANNELPROP)(int nBoardNo, int nChannelNo, BOARD_CHANNEL_PROP rProp);
typedef BOOLEAN (RT_IMPORT *PRTSYNCGETAICHANNELPROPICP)(int nBoardNo, int nChannelNo, PBOARD_AI_CHANNEL_PROP_ICP pProp);
typedef BOOLEAN (RT_IMPORT *PRTSYNCSETAICHANNELPROPICP)(int nBoardNo, int nChannelNo, BOARD_AI_CHANNEL_PROP_ICP rProp);
typedef float (RT_IMPORT *PRTSYNCGETCHANNELFACTOR)(int nBoardNo , int nChannelNo);
typedef int (RT_IMPORT *PRTSYNCGETCHANNELOFFSET)(int nBoardNo , int nChannelNo);


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


// Multi mode

typedef BOOLEAN (RT_IMPORT *PRTSYNCADDCHANNELCTR)(int nBoardNo, int nChannelNo, BOARD_CTR_CHANNEL rCtrInfo);
typedef int (RT_IMPORT *PRTSYNCGETMAXCHANNELCOUNTCTR)(int nBoardNo);
typedef int (RT_IMPORT *PRTSYNCGETCHANNELCOUNTCTR)(int nBoardNo);
typedef int (RT_IMPORT *PRTSYNCGETCHANNELNOCTR)(int nBoardNo, int nIndex);
typedef BOOLEAN (RT_IMPORT *PRTSYNCCLEARCHANNELSCTR)(int nBoardNo);
typedef BOOLEAN (RT_IMPORT *PRTSYNCGETCHANNELCTR)(int nBoardNo, int nChannelNo, PBOARD_CTR_CHANNEL pCtrInfo);
typedef BOOLEAN (RT_IMPORT *PRTSYNCGETCHANNELPROPCTR)(int nBoardNo, int nChannelNo, PBOARD_CTR_CHANNEL_PROP pProp);
typedef BOOLEAN (RT_IMPORT *PRTSYNCSETCHANNELPROPCTR)(int nBoardNo, int nChannelNo, BOARD_CTR_CHANNEL_PROP rProp);


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

typedef BOOLEAN (RT_IMPORT *PRTSETPARAM)(int nBoardNo, int nParamId, int nVal);
typedef BOOLEAN (RT_IMPORT *PRTGETPARAM)(int nBoardNo, int nParamId, int *pVal);
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
typedef int (RT_IMPORT *PRTREADCANRAWFRAME)(int nBoardNo, PBOARD_CAN_RAW_FRAME pCanFrames);
typedef int (RT_IMPORT *PRTWRITECAN)(int nBoardNo, PBOARD_CAN_FRAME pCanFrames, int nFrameCount);


//==============================================================================
// 11. Miscellaneous(Speaker)
//==============================================================================

typedef int (RT_IMPORT *PRTSPEAKERON)(int nBoardNo, WORD nTone);
typedef int (RT_IMPORT *PRTSPEAKEROFF)(int nBoardNo);
typedef int (RT_IMPORT *PRTSPEAKERPLAY)(int nBoardNo, WORD nFreq, DWORD nDelay);
typedef int (RT_IMPORT *PRTSPEAKERONBEEP)(int nBoardNo, WORD nFreq);




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

extern PRTINITIALBOARDS                 RtInitialBoards;

extern PRTGETBOARDCOUNT                 RtGetBoardCount;

extern PRTGETSPECINFO                   RtGetSpecInfo;
extern PRTGETPCIINFO                    RtGetPciInfo;
extern PRTGETBOARDINFO                  RtGetBoardInfo;


//==============================================================================
// 2. Open/Close & Start/Stop
//    (����/�ݱ� & ����/����)
//==============================================================================

// Single mode

extern PRTOPEN                          RtOpen;
extern PRTCLOSE                         RtClose;
extern PRTSTART                         RtStart;
extern PRTSTOP                          RtStop;


// Multi mode

extern PRTSYNCSETMASTER                 RtSyncSetMaster;
extern PRTSYNCSETSLAVEMASTER            RtSyncSetSlaveMaster;
extern PRTSYNCADDSLAVE                  RtSyncAddSlave;
extern PRTSYNCCLOSE                     RtSyncClose;
extern PRTSYNCCLEAR                     RtSyncClear;
extern PRTSYNCSTART                     RtSyncStart;
extern PRTSYNCSTOP                      RtSyncStop;


//==============================================================================
// 3. Data Acquisition
//    (������ �б�)
//==============================================================================

// Single mode

extern PRTREAD                          RtRead;
extern PRTGETDATA                       RtGetData;
extern PRTGETDATAEX                     RtGetDataEx;
extern PRTGETDATAEX1                     RtGetDataEx1;
extern PRTGETCURRENTPOS                 RtGetCurrentPos;


// Multi mode

extern PRTSYNCREAD                      RtSyncRead;
extern PRTSYNCGETDATA                   RtSyncGetData;
extern PRTSYNCGETDATAEX                 RtSyncGetDataEx;
extern PRTSYNCGETDATAEX1                 RtSyncGetDataEx1;


//==============================================================================
// 4. Analog channel setup and information
//    (AI ä�� ���� �� ä�� ����)
//==============================================================================

// Single mode

extern PRTADDCHANNEL                    RtAddChannel;
extern PRTGETMAXCHANNELCOUNT            RtGetMaxChannelCount;
extern PRTGETCHANNELCOUNT               RtGetChannelCount;
extern PRTGETCHANNELNO                  RtGetChannelNo;
extern PRTCLEARCHANNELS                 RtClearChannels;

extern PRTGETCHANNELPROP                RtGetChannelProp;
extern PRTSETCHANNELPROP                RtSetChannelProp;

extern PRTGETAICHANNELPROPICP           RtGetAIChannelPropICP;
extern PRTSETAICHANNELPROPICP           RtSetAIChannelPropICP;

extern PRTGETCHANNELFACTOR              RtGetChannelFactor;
extern PRTGETCHANNELOFFSET              RtGetChannelOffset;


// Multi mode

extern PRTSYNCADDCHANNEL                RtSyncAddChannel;
extern PRTSYNCGETMAXCHANNELCOUNT        RtSyncGetMaxChannelCount;
extern PRTSYNCGETCHANNELCOUNT           RtSyncGetChannelCount;
extern PRTSYNCGETCHANNELNO              RtSyncGetChannelNo;
extern PRTSYNCCLEARCHANNELS             RtSyncClearChannels;

extern PRTSYNCGETCHANNELPROP            RtSyncGetChannelProp;
extern PRTSYNCSETCHANNELPROP            RtSyncSetChannelProp;

extern PRTSYNCGETAICHANNELPROPICP       RtSyncGetAIChannelPropICP;
extern PRTSYNCSETAICHANNELPROPICP       RtSyncSetAIChannelPropICP;

extern PRTSYNCGETCHANNELFACTOR          RtSyncGetChannelFactor;
extern PRTSYNCGETCHANNELOFFSET          RtSyncGetChannelOffset;


//==============================================================================
// 5. Counter channel setup and information
//    (Counter ä�� ���� �� ä�� ����)
//==============================================================================

// Single mode

extern PRTADDCHANNELCTR                 RtAddChannelCTR;
extern PRTGETMAXCHANNELCOUNTCTR         RtGetMaxChannelCountCTR;
extern PRTGETCHANNELCOUNTCTR            RtGetChannelCountCTR;
extern PRTGETCHANNELNOCTR               RtGetChannelNoCTR;
extern PRTCLEARCHANNELSCTR              RtClearChannelsCTR;

extern PRTGETCHANNELCTR                 RtGetChannelCTR;
extern PRTGETCHANNELPROPCTR             RtGetChannelPropCTR;
extern PRTSETCHANNELPROPCTR             RtSetChannelPropCTR;


// Multi mode

extern PRTSYNCADDCHANNELCTR             RtSyncAddChannelCTR;
extern PRTSYNCGETMAXCHANNELCOUNTCTR     RtSyncGetMaxChannelCountCTR;
extern PRTSYNCGETCHANNELCOUNTCTR        RtSyncGetChannelCountCTR;
extern PRTSYNCGETCHANNELNOCTR           RtSyncGetChannelNoCTR;
extern PRTSYNCCLEARCHANNELSCTR          RtSyncClearChannelsCTR;

extern PRTSYNCGETCHANNELCTR             RtSyncGetChannelCTR;
extern PRTSYNCGETCHANNELPROPCTR         RtSyncGetChannelPropCTR;
extern PRTSYNCSETCHANNELPROPCTR         RtSyncSetChannelPropCTR;


//==============================================================================
// 6. Digital I/O channel setup and information
//    (DIO ä�� ���� �� ä�� ����)
//==============================================================================

// Single mode

extern PRTADDCHANNELDI                  RtAddChannelDI;
extern PRTGETMAXCHANNELCOUNTDI          RtGetMaxChannelCountDI;
extern PRTGETCHANNELCOUNTDI             RtGetChannelCountDI;
extern PRTGETCHANNELNODI                RtGetChannelNoDI;
extern PRTCLEARCHANNELSDI               RtClearChannelsDI;

extern PRTGETCHANNELDI                  RtGetChannelDI;
extern PRTGETCHANNELPROPDI              RtGetChannelPropDI;
extern PRTSETCHANNELPROPDI              RtSetChannelPropDI;


// Multi mode

extern PRTSYNCADDCHANNELDI              RtSyncAddChannelDI;
extern PRTSYNCGETMAXCHANNELCOUNTDI      RtSyncGetMaxChannelCountDI;
extern PRTSYNCGETCHANNELCOUNTDI         RtSyncGetChannelCountDI;
extern PRTSYNCGETCHANNELNODI            RtSyncGetChannelNoDI;
extern PRTSYNCCLEARCHANNELSDI           RtSyncClearChannelsDI;

extern PRTSYNCGETCHANNELDI              RtSyncGetChannelDI;
extern PRTSYNCGETCHANNELPROPDI          RtSyncGetChannelPropDI;
extern PRTSYNCSETCHANNELPROPDI          RtSyncSetChannelPropDI;


//==============================================================================
// 7. Adjustable Counter/Digital Input channel setup
//    (Adjustable Counter/DI ����)
//==============================================================================

extern PRTGETADJCHANNELPROP             RtGetAdjChannelProp;
extern PRTSETADJCHANNELPROP             RtSetAdjChannelProp;


//==============================================================================
// 8. Parameter setup
//    (�Ķ���� ����)
//==============================================================================

// Single mode

extern PRTSETPARAM                      RtSetParam;
extern PRTGETPARAM                      RtGetParam;
extern PRTUPDATEPARAMS                  RtUpdateParams;
extern PRTCONFIGURE                     RtConfigure;


// Multi mode

extern PRTSYNCSETPARAM                  RtSyncSetParam;
extern PRTSYNCUPDATEPARAMS              RtSyncUpdateParams;
extern PRTSYNCCONFIGURE                 RtSyncConfigure;


//==============================================================================
// 9. RS485
//==============================================================================

extern PRTOPENRS485                     RtOpenRS485;
extern PRTCLOSERS485                    RtCloseRS485;
extern PRTGETPROPRS485                  RtGetPropRS485;
extern PRTSETPROPRS485                  RtSetPropRS485;
extern PRTREADYDATARS485                RtReadyDataRS485;
extern PRTREADRS485                     RtReadRS485;
extern PRTWRITERS485                    RtWriteRS485;


//==============================================================================
// 10. CAN
//==============================================================================

extern PRTOPENCAN                       RtOpenCAN;
extern PRTCLOSECAN                      RtCloseCAN;
extern PRTSTARTCAN                      RtStartCAN;
extern PRTSTOPCAN                       RtStopCAN;
extern PRTGETPROPCAN                    RtGetPropCAN;
extern PRTSETPROPCAN                    RtSetPropCAN;
extern PRTREADCAN                       RtReadCAN;
extern PRTREADCANRAWFRAME               RtReadCANRawFrame;
extern PRTWRITECAN                      RtWriteCAN;


//==============================================================================
// 11. Miscellaneous(Speaker)
//==============================================================================

extern PRTSPEAKERON                     RtSpeakerOn;
extern PRTSPEAKEROFF                    RtSpeakerOff;
extern PRTSPEAKERPLAY                   RtSpeakerPlay;
extern PRTSPEAKERONBEEP                 RtSpeakerOnBeep;


//==============================================================================
// 12. DLL Load and Unload
//==============================================================================

extern BOOLEAN RTdaqLoad(void);
extern void RTdaqUnload(void);
#if 0
extern void RtCheck(BOOLEAN bOk);
#endif
extern LPSTR RtGetErrorMsg(int nErrorCode, LPSTR szMsg);
extern BOOLEAN RTdaqGetLibInstance(HINSTANCE *hLibInst);


#else   // else of "#ifndef STATIC_DLL"


//==============================================================================
// 1. Intialization and information of board
//    (���� �ʱ�ȭ �� ���� ����)
//==============================================================================

BOOLEAN RT_IMPORT RtInitialBoards(void);
int RT_IMPORT RtGetBoardCount(void);
BOOLEAN RT_IMPORT RtGetSpecInfo(int nBoardNo, PBOARD_SPEC_INFO pInfo);
BOOLEAN RT_IMPORT RtGetPciInfo(int nBoardNo, PBOARD_PCI_INFO pPciInfo);
BOOLEAN RT_IMPORT RtGetBoardInfo(int nBoardNo, PBOARD_MISC_INFO pMiscInfo);


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
BOOLEAN RT_IMPORT RtGetData(int nBoardNo, int aBufferPosArr[], int aBufferIncArr[], int aReadBlockArr[]);
BOOLEAN RT_IMPORT RtGetDataEx(int nBoardNo, PBOARD_READ_DATA pReadDataAI, PBOARD_READ_DATA pReadDataCTR);
BOOLEAN RT_IMPORT RtGetDataEx1(int nBoardNo, PBOARD_READ_DATA_ADV pReadDataAI, PBOARD_READ_DATA_ADV pReadDataCTR);
LONGLONG RT_IMPORT RtGetCurrentPos(int nBoardNo);


// Multi mode

BOOLEAN RT_IMPORT RtSyncRead(int nBoardNo, int aBufferPosArr[], int aReadBlockArr[]);
BOOLEAN RT_IMPORT RtSyncGetData(int nBoardNo, int aBufferPosArr[], int aBufferIncArr[], int aReadBlockArr[]);
BOOLEAN RT_IMPORT RtSyncGetDataEx(int nBoardNo, PBOARD_READ_DATA pReadDataAI, PBOARD_READ_DATA pReadDataCTR, PBOARD_READ_DATA pReadDataDI);
BOOLEAN RT_IMPORT RtSyncGetDataEx1(int nBoardNo, PBOARD_READ_DATA_ADV pReadDataAI, PBOARD_READ_DATA_ADV pReadDataCTR, PBOARD_READ_DATA_ADV pReadDataDI);


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
BOOLEAN RT_IMPORT RtGetAIChannelPropICP(int nBoardNo, int nChannelNo, PBOARD_AI_CHANNEL_PROP_ICP pProp);
BOOLEAN RT_IMPORT RtSetAIChannelPropICP(int nBoardNo, int nChannelNo, BOARD_AI_CHANNEL_PROP_ICP rProp);
float RT_IMPORT RtGetChannelFactor(int nBoardNo, int nChannelNo);
int RT_IMPORT RtGetChannelOffset(int nBoardNo, int nChannelNo);


// Multi mode

BOOLEAN RT_IMPORT RtSyncAddChannel(int nBoardNo, int nChannelNo);
int RT_IMPORT RtSyncGetMaxChannelCount(int nBoardNo);
int RT_IMPORT RtSyncGetChannelCount(int nBoardNo);
int RT_IMPORT RtSyncGetChannelNo(int nBoardNo, int nIndex);
BOOLEAN RT_IMPORT RtSyncClearChannels(int nBoardNo);
BOOLEAN RT_IMPORT RtSyncGetChannelProp(int nBoardNo, int nChannelNo, PBOARD_CHANNEL_PROP pProp);
BOOLEAN RT_IMPORT RtSyncSetChannelProp(int nBoardNo, int nChannelNo, BOARD_CHANNEL_PROP rProp);
BOOLEAN RT_IMPORT RtSyncGetAIChannelPropICP(int nBoardNo, int nChannelNo, PBOARD_AI_CHANNEL_PROP_ICP pProp);
BOOLEAN RT_IMPORT RtSyncSetAIChannelPropICP(int nBoardNo, int nChannelNo, BOARD_AI_CHANNEL_PROP_ICP rProp);
float RT_IMPORT RtSyncGetChannelFactor(int nBoardNo, int nChannelNo);
int RT_IMPORT RtSyncGetChannelOffset(int nBoardNo, int nChannelNo);


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


// Multi mode

BOOLEAN RT_IMPORT RtSyncAddChannelCTR(int nBoardNo, int nChannelNo, BOARD_CTR_CHANNEL rCtrInfo);
int RT_IMPORT RtSyncGetMaxChannelCountCTR(int nBoardNo);
int RT_IMPORT RtSyncGetChannelCountCTR(int nBoardNo);
int RT_IMPORT RtSyncGetChannelNoCTR(int nBoardNo, int nIndex);
BOOLEAN RT_IMPORT RtSyncClearChannelsCTR(int nBoardNo);
BOOLEAN RT_IMPORT RtSyncGetChannelCTR(int nBoardNo, int nChannelNo, PBOARD_CTR_CHANNEL pCtrInfo);
BOOLEAN RT_IMPORT RtSyncGetChannelPropCTR(int nBoardNo, int nChannelNo, PBOARD_CTR_CHANNEL_PROP pProp);
BOOLEAN RT_IMPORT RtSyncSetChannelPropCTR(int nBoardNo, int nChannelNo, BOARD_CTR_CHANNEL_PROP rProp);


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
BOOLEAN RT_IMPORT RtSyncClearChannelsDI(int nBoardNo);
int RT_IMPORT RtSyncGetChannelNoDI(int nBoardNo, int nIndex);
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

BOOLEAN RT_IMPORT RtSetParam(int nBoardNo, int nParamId, int nVal);
BOOLEAN RT_IMPORT RtGetParam(int nBoardNo, int nParamId, int *pVal);
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
BOOLEAN RT_IMPORT RtGetPropRS485(int nBoardNo, PBOARD_RS485_PROP pInfo);
BOOLEAN RT_IMPORT RtSetPropRS485(int nBoardNo, BOARD_RS485_PROP pInfo);
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
int RT_IMPORT RtReadCANRawFrame(int nBoardNo, PBOARD_CAN_RAW_FRAME pCanFrames);
int RT_IMPORT RtWriteCAN(int nBoardNo, PBOARD_CAN_FRAME pCanFrames, int nFrameCount);


//==============================================================================
// 11. Miscellaneous(Speaker)
//==============================================================================

BOOLEAN RT_IMPORT RtSpeakerOn(int nBoardNo, WORD nTone);
BOOLEAN RT_IMPORT RtSpeakerOff(int nBoardNo);
BOOLEAN RT_IMPORT RtSpeakerPlay(int nBoardNo, WORD nFreq, DWORD nDelay);
BOOLEAN RT_IMPORT RtSpeakerOnBeep(int nBoardNo, WORD nFreq);

#endif  // end of "#ifndef STATIC_DLL"




#ifdef __cplusplus
}
#endif /* __cplusplus */




#endif //  OrionDsa_api.H



