
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
//#include "stdafx.h"	// Visual Studio setup : 
						//		C/C++ -> Precompiled headers -> 
						//		Create/Use Precompiled Header -> "Not Using Precompiled Header"

#include "OrionDaq_api.h"

#include <wtypes.h>
#include <shlwapi.h>

#ifndef RT_IMPORT
    #define RT_IMPORT WINAPI
#endif


#ifndef STATIC_DLL 


#ifdef RTDAQ_API_X64
	#define RTDAQ_DLL_NAME      "dwdaq_api_x64.dll"
#else
	#define RTDAQ_DLL_NAME      "dwdaq_api.dll"
#endif

//---------------------------------------------------------------------------


/********************************************************************************
 *
 *
 *                IV. Definition of API functions (API 함수 정의)
 *
 *
 ********************************************************************************/

//####################################
//
// Definition of API function type 
//     (API 함수 타입 정의)
//
//####################################


//==============================================================================
// 1. Intialization and information of board 
//    (보드 초기화 및 보드 정보)
//==============================================================================
PRTINITIALBOARDS				RtInitialBoards;
PRTGETBOARDCOUNT				RtGetBoardCount;

PRTGETBOARDINFO					RtGetBoardInfo;
PRTGETSPECINFO					RtGetSpecInfo;
PRTGETPCIINFO					RtGetPciInfo;


//==============================================================================
// 2. Open/Close & Start/Stop
//    (열기/닫기 & 시작/종료)
//==============================================================================

 // Single mode

PRTOPEN							RtOpen;
PRTCLOSE						RtClose;
PRTSTART						RtStart;
PRTSTOP							RtStop;


// Multi mode

PRTSYNCSETMASTER				RtSyncSetMaster;
PRTSYNCSETSLAVEMASTER			RtSyncSetSlaveMaster;
PRTSYNCADDSLAVE					RtSyncAddSlave;
PRTSYNCCLOSE					RtSyncClose;
PRTSYNCCLEAR					RtSyncClear;
PRTSYNCSTART					RtSyncStart;
PRTSYNCSTOP						RtSyncStop;


//==============================================================================
// 3. Data Acquisition
//    (데이터 읽기)
//==============================================================================

// Single mode

PRTREAD							RtRead;
PRTREADBLOCK					RtReadBlock;
PRTREADEASY						RtReadEasy;
PRTREADEASYEX					RtReadEasyEx;
PRTGETDATA						RtGetData;
PRTGETDATAEX					RtGetDataEx;
PRTGETCURRENTPOS				RtGetCurrentPos;


// Multi mode

PRTSYNCREAD						RtSyncRead;
PRTSYNCREADBLOCK				RtSyncReadBlock;
PRTSYNCREADEASY					RtSyncReadEasy;
PRTSYNCREADEASYEX				RtSyncReadEasyEx;
PRTSYNCGETDATA					RtSyncGetData;
PRTSYNCGETDATAEX				RtSyncGetDataEx;


//==============================================================================
// 4. Analog channel setup and information
//    (AI 채널 설정 및 채널 정보)
//==============================================================================

// Single mode

PRTADDCHANNEL					RtAddChannel;
PRTGETMAXCHANNELCOUNT			RtGetMaxChannelCount;
PRTGETCHANNELCOUNT				RtGetChannelCount;
PRTGETCHANNELNO					RtGetChannelNo;
PRTCLEARCHANNELS				RtClearChannels;

PRTGETCHANNELPROP				RtGetChannelProp;
PRTSETCHANNELPROP				RtSetChannelProp;
	

// Multi mode

PRTSYNCADDCHANNEL				RtSyncAddChannel;
PRTSYNCGETMAXCHANNELCOUNT		RtSyncGetMaxChannelCount;
PRTSYNCGETCHANNELCOUNT			RtSyncGetChannelCount;
PRTSYNCGETCHANNELNO				RtSyncGetChannelNo;
PRTSYNCCLEARCHANNELS			RtSyncClearChannels;

PRTSYNCGETCHANNELPROP			RtSyncGetChannelProp;
PRTSYNCSETCHANNELPROP			RtSyncSetChannelProp;


//==============================================================================
// 5. Counter channel setup and information
//    (Counter 채널 설정 및 채널 정보)
//==============================================================================

// Single mode

PRTADDCHANNELCTR				RtAddChannelCTR;
PRTGETMAXCHANNELCOUNTCTR		RtGetMaxChannelCountCTR;
PRTGETCHANNELCOUNTCTR			RtGetChannelCountCTR;
PRTGETCHANNELNOCTR				RtGetChannelNoCTR;
PRTCLEARCHANNELSCTR				RtClearChannelsCTR;

PRTGETCHANNELCTR				RtGetChannelCTR;
PRTGETCHANNELPROPCTR			RtGetChannelPropCTR;
PRTSETCHANNELPROPCTR			RtSetChannelPropCTR;

//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - start ===>>>
PRTGETCHANNELPROPSUPERCTR		RtGetChannelPropSuperCTR;
PRTSETCHANNELPROPSUPERCTR		RtSetChannelPropSuperCTR;
//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - end <<<===


// Multi mode

PRTSYNCADDCHANNELCTR			RtSyncAddChannelCTR;
PRTSYNCGETMAXCHANNELCOUNTCTR	RtSyncGetMaxChannelCountCTR;
PRTSYNCGETCHANNELCOUNTCTR		RtSyncGetChannelCountCTR;
PRTSYNCGETCHANNELNOCTR			RtSyncGetChannelNoCTR;
PRTSYNCCLEARCHANNELSCTR			RtSyncClearChannelsCTR;

PRTSYNCGETCHANNELCTR			RtSyncGetChannelCTR;
PRTSYNCGETCHANNELPROPCTR		RtSyncGetChannelPropCTR;
PRTSYNCSETCHANNELPROPCTR		RtSyncSetChannelPropCTR;

//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - start ===>>>
PRTSYNCGETCHANNELPROPSUPERCTR	RtSyncGetChannelPropSuperCTR;
PRTSYNCSETCHANNELPROPSUPERCTR	RtSyncSetChannelPropSuperCTR;
//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - end <<<===


//==============================================================================
// 6. Digital I/O channel setup and information
//    (DIO 채널 설정 및 채널 정보)
//==============================================================================

// Single mode

PRTADDCHANNELDI					RtAddChannelDI;
PRTGETMAXCHANNELCOUNTDI			RtGetMaxChannelCountDI;
PRTGETCHANNELCOUNTDI			RtGetChannelCountDI;
PRTGETCHANNELNODI				RtGetChannelNoDI;
PRTCLEARCHANNELSDI				RtClearChannelsDI;

PRTGETCHANNELDI					RtGetChannelDI;
PRTGETCHANNELPROPDI				RtGetChannelPropDI;
PRTSETCHANNELPROPDI				RtSetChannelPropDI;


// Multi mode

PRTSYNCADDCHANNELDI				RtSyncAddChannelDI;
PRTSYNCGETMAXCHANNELCOUNTDI		RtSyncGetMaxChannelCountDI;
PRTSYNCGETCHANNELCOUNTDI		RtSyncGetChannelCountDI;
PRTSYNCGETCHANNELNODI			RtSyncGetChannelNoDI;
PRTSYNCCLEARCHANNELSDI			RtSyncClearChannelsDI;

PRTSYNCGETCHANNELDI				RtSyncGetChannelDI;
PRTSYNCGETCHANNELPROPDI			RtSyncGetChannelPropDI;
PRTSYNCSETCHANNELPROPDI			RtSyncSetChannelPropDI;


//==============================================================================
// 7. Adjustable Counter/Digital Input channel setup
//    (Adjustable Counter/DI 설정)
//==============================================================================

PRTGETADJCHANNELPROP			RtGetAdjChannelProp;
PRTSETADJCHANNELPROP			RtSetAdjChannelProp;


//==============================================================================
// 8. Parameter setup 
//    (파라미터 설정)
//==============================================================================

// Single mode

PRTGETPARAM						RtGetParam;
PRTSETPARAM						RtSetParam;
PRTUPDATEPARAMS					RtUpdateParams;
PRTCONFIGURE					RtConfigure;


// Multi mode

PRTSYNCSETPARAM					RtSyncSetParam;
PRTSYNCUPDATEPARAMS				RtSyncUpdateParams;
PRTSYNCCONFIGURE				RtSyncConfigure;


//==============================================================================
// 9. RS485
//==============================================================================

PRTOPENRS485					RtOpenRS485;
PRTCLOSERS485					RtCloseRS485;
PRTGETPROPRS485					RtGetPropRS485;
PRTSETPROPRS485					RtSetPropRS485;
PRTREADYDATARS485				RtReadyDataRS485;
PRTREADRS485					RtReadRS485;
PRTWRITERS485					RtWriteRS485;


//==============================================================================
// 10. CAN
//==============================================================================

PRTOPENCAN						RtOpenCAN;
PRTCLOSECAN						RtCloseCAN;
PRTSTARTCAN						RtStartCAN;
PRTSTOPCAN						RtStopCAN;
PRTGETPROPCAN					RtGetPropCAN;
PRTSETPROPCAN					RtSetPropCAN;
PRTREADCAN						RtReadCAN;
//zenith 160310 add ver2.0.0.12  - to can read Labview  start --->
PRTREADCANLV					RtReadCANLV;
//zenith 160310 add ver2.0.0.12  - to can read Labview  end <---
PRTREADCANRAWFRAME				RtReadCANRawFrame;
PRTWRITECAN						RtWriteCAN;


//==============================================================================
// 11. Miscellaneous(Speaker)
//==============================================================================

PRTSPEAKERON					RtSpeakerOn;   
PRTSPEAKEROFF					RtSpeakerOff;   
PRTSPEAKERPLAY					RtSpeakerPlay;   
PRTSPEAKERONBEEP				RtSpeakerOnBeep;   




/******************************************
* Dll Dynamic Load/Unload
******************************************/
static BOOLEAN     bLoaded;
static HINSTANCE   hLib;




// Get the DLL instance
BOOLEAN RTdaqGetLibInstance(HINSTANCE *hLibInst)
{
	if (bLoaded) {
		*hLibInst = hLib;
		return TRUE;;
	}

	*hLibInst = NULL;
	return FALSE;
}




// Load DLL
BOOLEAN RTdaqLoad(void) 
{
    // 모듈로드
	hLib = LoadLibrary(TEXT(RTDAQ_DLL_NAME));
    if (hLib)
        bLoaded = TRUE;
    else
        bLoaded = FALSE;

    if (bLoaded) {

//==============================================================================
// 1. Intialization and information of board 
//    (보드 초기화 및 보드 정보)
//==============================================================================

		RtInitialBoards				= (PRTINITIALBOARDS)			GetProcAddress(hLib, "RtInitialBoards");
        RtGetBoardCount				= (PRTGETBOARDCOUNT)			GetProcAddress(hLib, "RtGetBoardCount");
                                                                
		RtGetBoardInfo				= (PRTGETBOARDINFO)				GetProcAddress(hLib, "RtGetBoardInfo");
		RtGetSpecInfo				= (PRTGETSPECINFO)				GetProcAddress(hLib, "RtGetSpecInfo");
		RtGetPciInfo				= (PRTGETPCIINFO)				GetProcAddress(hLib, "RtGetPciInfo");


//==============================================================================
// 2. Open/Close & Start/Stop
//    (열기/닫기 & 시작/종료)
//==============================================================================

		// Single mode

		RtOpen						= (PRTOPEN)						GetProcAddress(hLib, "RtOpen");
		RtClose						= (PRTCLOSE)					GetProcAddress(hLib, "RtClose");
		RtStart						= (PRTSTART)					GetProcAddress(hLib, "RtStart");
		RtStop						= (PRTSTOP)						GetProcAddress(hLib, "RtStop");


		// Multi mode

		RtSyncSetMaster				= (PRTSYNCSETMASTER)			GetProcAddress(hLib, "RtSyncSetMaster");
		RtSyncSetSlaveMaster		= (PRTSYNCSETSLAVEMASTER)		GetProcAddress(hLib, "RtSyncSetSlaveMaster");
		RtSyncAddSlave				= (PRTSYNCADDSLAVE)				GetProcAddress(hLib, "RtSyncAddSlave");
		RtSyncClose					= (PRTSYNCCLOSE)				GetProcAddress(hLib, "RtSyncClose");
		RtSyncClear					= (PRTSYNCCLEAR)				GetProcAddress(hLib, "RtSyncClear");
		RtSyncStart					= (PRTSYNCSTART)				GetProcAddress(hLib, "RtSyncStart");
		RtSyncStop					= (PRTSYNCSTOP)					GetProcAddress(hLib, "RtSyncStop");


//==============================================================================
// 3. Data Acquisition
//    (데이터 읽기)
//==============================================================================

		// Single mode

		RtRead						= (PRTREAD)						GetProcAddress(hLib, "RtRead");
		RtReadBlock					= (PRTREADBLOCK)				GetProcAddress(hLib, "RtReadBlock");
		RtReadEasy					= (PRTREADEASY)					GetProcAddress(hLib, "RtReadEasy");
		RtReadEasyEx				= (PRTREADEASYEX)				GetProcAddress(hLib, "RtReadEasyEx");
		RtGetData					= (PRTGETDATA)					GetProcAddress(hLib, "RtGetData");
		RtGetDataEx					= (PRTGETDATAEX)				GetProcAddress(hLib, "RtGetDataEx");
		RtGetCurrentPos             = (PRTGETCURRENTPOS )           GetProcAddress(hLib, "RtGetCurrentPos");

		
		// Multi mode

		RtSyncRead					= (PRTSYNCREAD)					GetProcAddress(hLib, "RtSyncRead");
		RtSyncReadBlock				= (PRTSYNCREADBLOCK)			GetProcAddress(hLib, "RtSyncReadBlock");
		RtSyncReadEasy				= (PRTSYNCREADEASY)				GetProcAddress(hLib, "RtSyncReadEasy");
		RtSyncReadEasyEx			= (PRTSYNCREADEASYEX)			GetProcAddress(hLib, "RtSyncReadEasyEx");
		RtSyncGetData				= (PRTSYNCGETDATA)				GetProcAddress(hLib, "RtSyncGetData");
		RtSyncGetDataEx				= (PRTSYNCGETDATAEX)			GetProcAddress(hLib, "RtSyncGetDataEx");


//==============================================================================
// 4. Analog channel setup and information
//    (AI 채널 설정 및 채널 정보)
//==============================================================================

		// Single mode

		RtAddChannel				= (PRTADDCHANNEL)				GetProcAddress(hLib, "RtAddChannel");
		RtGetMaxChannelCount		= (PRTGETMAXCHANNELCOUNT)		GetProcAddress(hLib, "RtGetMaxChannelCount");
		RtGetChannelCount			= (PRTGETCHANNELCOUNT)			GetProcAddress(hLib, "RtGetChannelCount");
		RtGetChannelNo				= (PRTGETCHANNELNO)				GetProcAddress(hLib, "RtGetChannelNo");
		RtClearChannels				= (PRTCLEARCHANNELS)			GetProcAddress(hLib, "RtClearChannels");

		RtGetChannelProp			= (PRTGETCHANNELPROP)			GetProcAddress(hLib, "RtGetChannelProp");
		RtSetChannelProp			= (PRTSETCHANNELPROP)			GetProcAddress(hLib, "RtSetChannelProp");

		
		// Multi mode

		RtSyncAddChannel			= (PRTSYNCADDCHANNEL)			GetProcAddress(hLib, "RtSyncAddChannel");
		RtSyncGetMaxChannelCount	= (PRTSYNCGETMAXCHANNELCOUNT)	GetProcAddress(hLib, "RtSyncGetMaxChannelCount");
		RtSyncGetChannelCount		= (PRTSYNCGETCHANNELCOUNT)		GetProcAddress(hLib, "RtSyncGetChannelCount");
		RtSyncGetChannelNo			= (PRTSYNCGETCHANNELNO)			GetProcAddress(hLib, "RtSyncGetChannelNo");
		RtSyncClearChannels			= (PRTSYNCCLEARCHANNELS)		GetProcAddress(hLib, "RtSyncClearChannels");

		RtSyncGetChannelProp		= (PRTSYNCGETCHANNELPROP)		GetProcAddress(hLib, "RtSyncGetChannelProp");
		RtSyncSetChannelProp		= (PRTSYNCSETCHANNELPROP)		GetProcAddress(hLib, "RtSyncSetChannelProp");


//==============================================================================
// 5. Counter channel setup and information
//    (Counter 채널 설정 및 채널 정보)
//==============================================================================

		// Single mode

		RtAddChannelCTR             = (PRTADDCHANNELCTR)            GetProcAddress(hLib, "RtAddChannelCTR");
		RtGetMaxChannelCountCTR     = (PRTGETMAXCHANNELCOUNTCTR)    GetProcAddress(hLib, "RtGetMaxChannelCountCTR");
		RtGetChannelCountCTR        = (PRTGETCHANNELCOUNTCTR)       GetProcAddress(hLib, "RtGetChannelCountCTR");
		RtGetChannelNoCTR           = (PRTGETCHANNELNOCTR)          GetProcAddress(hLib, "RtGetChannelNoCTR");
		RtClearChannelsCTR          = (PRTCLEARCHANNELSCTR)         GetProcAddress(hLib, "RtClearChannelsCTR");

		RtGetChannelCTR             = (PRTGETCHANNELCTR)            GetProcAddress(hLib, "RtGetChannelCTR");
		RtGetChannelPropCTR         = (PRTGETCHANNELPROPCTR)        GetProcAddress(hLib, "RtGetChannelPropCTR");
		RtSetChannelPropCTR         = (PRTSETCHANNELPROPCTR)        GetProcAddress(hLib, "RtSetChannelPropCTR");

//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - start ===>>>
		RtGetChannelPropSuperCTR	= (PRTGETCHANNELPROPSUPERCTR)        GetProcAddress(hLib, "RtGetChannelPropSuperCTR");
		RtSetChannelPropSuperCTR	= (PRTSETCHANNELPROPSUPERCTR)        GetProcAddress(hLib, "RtSetChannelPropSuperCTR");
//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - end <<<===


		// Multi mode

		RtSyncAddChannelCTR			= (PRTSYNCADDCHANNELCTR)		GetProcAddress(hLib, "RtSyncAddChannelCTR");
		RtSyncGetMaxChannelCountCTR	= (PRTSYNCGETMAXCHANNELCOUNTCTR)GetProcAddress(hLib, "RtSyncGetMaxChannelCountCTR");
		RtSyncGetChannelCountCTR	= (PRTSYNCGETCHANNELCOUNTCTR)	GetProcAddress(hLib, "RtSyncGetChannelCountCTR");
		RtSyncGetChannelNoCTR		= (PRTSYNCGETCHANNELNOCTR)		GetProcAddress(hLib, "RtSyncGetChannelNoCTR");
		RtSyncClearChannelsCTR		= (PRTSYNCCLEARCHANNELSCTR)		GetProcAddress(hLib, "RtSyncClearChannelsCTR");

		RtSyncGetChannelCTR         = (PRTSYNCGETCHANNELCTR)		GetProcAddress(hLib, "RtSyncGetChannelCTR");
		RtSyncGetChannelPropCTR		= (PRTSYNCGETCHANNELPROPCTR)	GetProcAddress(hLib, "RtSyncGetChannelPropCTR");
		RtSyncSetChannelPropCTR		= (PRTSYNCSETCHANNELPROPCTR)	GetProcAddress(hLib, "RtSyncSetChannelPropCTR");

//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - start ===>>>
		RtSyncGetChannelPropSuperCTR	= (PRTSYNCGETCHANNELPROPSUPERCTR)	GetProcAddress(hLib, "RtSyncGetChannelPropSuperCTR");
		RtSyncSetChannelPropSuperCTR	= (PRTSYNCSETCHANNELPROPSUPERCTR)	GetProcAddress(hLib, "RtSyncSetChannelPropSuperCTR");
//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - end <<<===


//==============================================================================
// 6. Digital I/O channel setup and information
//    (DIO 채널 설정 및 채널 정보)
//==============================================================================

		// Single mode

		RtAddChannelDI				= (PRTADDCHANNELDI)				GetProcAddress(hLib, "RtAddChannelDI");
		RtGetMaxChannelCountDI		= (PRTGETMAXCHANNELCOUNTDI)		GetProcAddress(hLib, "RtGetMaxChannelCountDI");
		RtGetChannelCountDI			= (PRTGETCHANNELCOUNTDI)		GetProcAddress(hLib, "RtGetChannelCountDI");
		RtGetChannelNoDI			= (PRTGETCHANNELNODI)			GetProcAddress(hLib, "RtGetChannelNoDI");
		RtClearChannelsDI			= (PRTCLEARCHANNELSDI)			GetProcAddress(hLib, "RtClearChannelsDI");

		RtGetChannelDI				= (PRTGETCHANNELDI)				GetProcAddress(hLib, "RtGetChannelDI");
		RtGetChannelPropDI			= (PRTGETCHANNELPROPDI)			GetProcAddress(hLib, "RtGetChannelPropDI");
		RtSetChannelPropDI			= (PRTSETCHANNELPROPDI)			GetProcAddress(hLib, "RtSetChannelPropDI");


		// Multi mode

		RtSyncAddChannelDI			= (PRTSYNCADDCHANNELDI)			GetProcAddress(hLib, "RtSyncAddChannelDI");
		RtSyncGetMaxChannelCountDI	= (PRTSYNCGETMAXCHANNELCOUNTDI)	GetProcAddress(hLib, "RtSyncGetMaxChannelCountDI");
		RtSyncGetChannelCountDI		= (PRTSYNCGETCHANNELCOUNTDI)	GetProcAddress(hLib, "RtSyncGetChannelCountDI");
		RtSyncGetChannelNoDI		= (PRTSYNCGETCHANNELNODI)		GetProcAddress(hLib, "RtSyncGetChannelNoDI");
		RtSyncClearChannelsDI		= (PRTSYNCCLEARCHANNELSDI)		GetProcAddress(hLib, "RtSyncClearChannelsDI");

		RtSyncGetChannelDI			= (PRTSYNCGETCHANNELDI)			GetProcAddress(hLib, "RtSyncGetChannelDI");
		RtSyncGetChannelPropDI		= (PRTSYNCGETCHANNELPROPDI)		GetProcAddress(hLib, "RtSyncGetChannelPropDI");
		RtSyncSetChannelPropDI		= (PRTSYNCSETCHANNELPROPDI)		GetProcAddress(hLib, "RtSyncSetChannelPropDI");


//==============================================================================
// 7. Adjustable Counter/Digital Input channel setup
//    (Adjustable Counter/DI 설정)
//==============================================================================

		RtGetAdjChannelProp			= (PRTGETADJCHANNELPROP)		GetProcAddress(hLib, "RtGetAdjChannelProp");
		RtSetAdjChannelProp			= (PRTSETADJCHANNELPROP)		GetProcAddress(hLib, "RtSetAdjChannelProp");


//==============================================================================
// 8. Parameter setup 
//    (파라미터 설정)
//==============================================================================

		// Single mode

		RtGetParam					= (PRTGETPARAM)					GetProcAddress(hLib, "RtGetParam");
		RtSetParam					= (PRTSETPARAM)					GetProcAddress(hLib, "RtSetParam");
		RtUpdateParams				= (PRTUPDATEPARAMS)				GetProcAddress(hLib, "RtUpdateParams");
		RtConfigure					= (PRTCONFIGURE)				GetProcAddress(hLib, "RtConfigure");


		// Multi mode

		RtSyncSetParam				= (PRTSYNCSETPARAM)				GetProcAddress(hLib, "RtSyncSetParam");
		RtSyncUpdateParams			= (PRTSYNCUPDATEPARAMS)			GetProcAddress(hLib, "RtSyncUpdateParams");
		RtSyncConfigure				= (PRTSYNCCONFIGURE)			GetProcAddress(hLib, "RtSyncConfigure");


//==============================================================================
// 9. RS485
//==============================================================================

		RtOpenRS485					= (PRTOPENRS485)				GetProcAddress(hLib, "RtOpenRS485");
		RtCloseRS485				= (PRTCLOSERS485)				GetProcAddress(hLib, "RtCloseRS485");
		RtGetPropRS485				= (PRTGETPROPRS485)				GetProcAddress(hLib, "RtGetPropRS485");
		RtSetPropRS485				= (PRTSETPROPRS485)				GetProcAddress(hLib, "RtSetPropRS485");
		RtReadyDataRS485			= (PRTREADYDATARS485)			GetProcAddress(hLib, "RtReadyDataRS485");
		RtReadRS485					= (PRTREADRS485)				GetProcAddress(hLib, "RtReadRS485");
		RtWriteRS485				= (PRTWRITERS485)				GetProcAddress(hLib, "RtWriteRS485");


//==============================================================================
// 10. CAN
//==============================================================================

		RtOpenCAN					= (PRTOPENCAN)					GetProcAddress(hLib, "RtOpenCAN");
		RtCloseCAN					= (PRTCLOSECAN)					GetProcAddress(hLib, "RtCloseCAN");
		RtStartCAN					= (PRTSTARTCAN)					GetProcAddress(hLib, "RtStartCAN");
		RtStopCAN					= (PRTSTOPCAN)					GetProcAddress(hLib, "RtStopCAN");
		RtGetPropCAN				= (PRTGETPROPCAN)				GetProcAddress(hLib, "RtGetPropCAN");
		RtSetPropCAN				= (PRTSETPROPCAN)				GetProcAddress(hLib, "RtSetPropCAN");
		RtReadCAN					= (PRTREADCAN)					GetProcAddress(hLib, "RtReadCAN");
//zenith 160310 add ver2.0.0.12  - to can read Labview  start --->
		RtReadCANLV					= (PRTREADCANLV)				GetProcAddress(hLib, "RtReadCANLV");
//zenith 160310 add ver2.0.0.12  - to can read Labview  end <---
		RtReadCANRawFrame			= (PRTREADCANRAWFRAME)			GetProcAddress(hLib, "RtReadCANRawFrame");
		RtWriteCAN					= (PRTWRITECAN)					GetProcAddress(hLib, "RtWriteCAN");


//==============================================================================
// 11. Miscellaneous(Speaker)
//==============================================================================
	
		RtSpeakerOn					= (PRTSPEAKERON)				GetProcAddress(hLib, "RtSpeakerOn");
		RtSpeakerOff				= (PRTSPEAKEROFF)				GetProcAddress(hLib, "RtSpeakerOff");
		RtSpeakerPlay				= (PRTSPEAKERPLAY)				GetProcAddress(hLib, "RtSpeakerPlay");
		RtSpeakerOnBeep				= (PRTSPEAKERONBEEP)			GetProcAddress(hLib, "RtSpeakerOnBeep");
	}

    return bLoaded;
}




// Unload DLL
void RTdaqUnload(void)
{
	if (bLoaded) {
		FreeLibrary(hLib);

//==============================================================================
// 1. Intialization and information of board 
//    (보드 초기화 및 보드 정보)
//==============================================================================

		RtInitialBoards				= NULL;
		RtGetBoardCount				= NULL;
                                
		RtGetBoardInfo				= NULL;
		RtGetSpecInfo				= NULL;
		RtGetPciInfo				= NULL;


//==============================================================================
// 2. Open/Close & Start/Stop
//    (열기/닫기 & 시작/종료)
//==============================================================================

		// Single mode

		RtOpen						= NULL;
		RtClose						= NULL;
		RtStart						= NULL;
		RtStop						= NULL;


		// Multi mode
		
		RtSyncSetMaster				= NULL;
		RtSyncSetSlaveMaster		= NULL;
		RtSyncAddSlave				= NULL;
		RtSyncClear					= NULL;
                                
		RtSyncClose					= NULL;
		RtSyncStart					= NULL;
		RtSyncStop					= NULL;


//==============================================================================
// 3. Data Acquisition
//    (데이터 읽기)
//==============================================================================

		// Single mode
		
		RtRead						= NULL;
		RtReadBlock					= NULL;
		RtReadEasy					= NULL;
		RtReadEasyEx				= NULL;
		RtGetData					= NULL;
		RtGetDataEx					= NULL;
		RtGetCurrentPos				= NULL; 


		// Multi mode
		
		RtSyncRead					= NULL;
		RtSyncReadBlock				= NULL;
		RtSyncReadEasy				= NULL;
		RtSyncReadEasyEx			= NULL;
		RtSyncGetData				= NULL;
		RtSyncGetDataEx				= NULL;


//==============================================================================
// 4. Analog channel setup and information
//    (AI 채널 설정 및 채널 정보)
//==============================================================================

		// Single mode

		RtAddChannel				= NULL;
		RtGetMaxChannelCount		= NULL;
		RtGetChannelCount			= NULL;
		RtGetChannelNo				= NULL;
		RtClearChannels				= NULL;
                                  
		RtGetChannelProp			= NULL;
		RtSetChannelProp			= NULL;


		// Multi  mode

		RtSyncAddChannel			= NULL;
		RtSyncGetMaxChannelCount	= NULL;
		RtSyncGetChannelCount		= NULL;
		RtSyncGetChannelNo			= NULL;
		RtSyncClearChannels			= NULL;

		RtSyncGetChannelProp		= NULL;
		RtSyncSetChannelProp		= NULL;


//==============================================================================
// 5. Counter channel setup and information
//    (Counter 채널 설정 및 채널 정보)
//==============================================================================

		// Single mode

		RtAddChannelCTR				= NULL;
		RtGetMaxChannelCountCTR		= NULL;
		RtGetChannelCountCTR		= NULL;
		RtGetChannelNoCTR			= NULL;
		RtClearChannelsCTR			= NULL;

		RtGetChannelCTR				= NULL;
		RtGetChannelPropCTR			= NULL;
		RtSetChannelPropCTR			= NULL;

//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - start ===>>>
		RtGetChannelPropSuperCTR	= NULL;
		RtSetChannelPropSuperCTR	= NULL;
//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - end <<<===


		// Multi mode

		RtSyncAddChannelCTR			= NULL;
		RtSyncGetMaxChannelCountCTR	= NULL;
		RtSyncGetChannelCountCTR	= NULL;
		RtSyncGetChannelNoCTR		= NULL;
		RtSyncClearChannelsCTR      = NULL;

		RtSyncGetChannelCTR         = NULL;
		RtSyncSetChannelPropCTR     = NULL;
		RtSyncGetChannelPropCTR     = NULL;

//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - start ===>>>
		RtSyncGetChannelPropSuperCTR	= NULL;
		RtSyncSetChannelPropSuperCTR	= NULL;
//shkim130925 - add - ver2.0.0.4.super - to support SUPER COUNTER, Only for 0816-5M/10M - end <<<===


//==============================================================================
// 6. Digital I/O channel setup and information
//    (DIO 채널 설정 및 채널 정보)
//==============================================================================

		// Single mode

		RtAddChannelDI				= NULL;
		RtGetMaxChannelCountDI		= NULL;
		RtGetChannelCountDI			= NULL;
		RtGetChannelNoDI			= NULL;
		RtClearChannelsDI			= NULL;

		RtGetChannelDI				= NULL;
		RtGetChannelPropDI			= NULL;
		RtSetChannelPropDI			= NULL;


		// Multi mode

		RtSyncAddChannelDI			= NULL;
		RtSyncGetMaxChannelCountDI	= NULL;
		RtSyncGetChannelCountDI		= NULL;
		RtSyncGetChannelNoDI		= NULL;
		RtSyncClearChannelsDI		= NULL;

		RtSyncGetChannelDI			= NULL;
		RtSyncGetChannelPropDI		= NULL;
		RtSyncSetChannelPropDI		= NULL;


//==============================================================================
// 7. Adjustable Counter/Digital Input channel setup
//    (Adjustable Counter/DI 설정)
//==============================================================================

		RtGetAdjChannelProp			= NULL;
		RtSetAdjChannelProp			= NULL;


//==============================================================================
// 8. Parameter setup 
//    (파라미터 설정)
//==============================================================================

		// Single mode

		RtGetParam					= NULL;
		RtSetParam					= NULL;
		RtUpdateParams				= NULL;
		RtConfigure					= NULL;


		// Multi mode

		RtSyncSetParam				= NULL;
		RtSyncUpdateParams			= NULL;
		RtSyncConfigure				= NULL;


//==============================================================================
// 9. RS485
//==============================================================================

		RtOpenRS485					= NULL;
		RtCloseRS485				= NULL;
		RtGetPropRS485				= NULL;
		RtSetPropRS485				= NULL;
		RtReadyDataRS485			= NULL;
		RtReadRS485					= NULL;
		RtWriteRS485				= NULL;


//==============================================================================
// 10. CAN
//==============================================================================

		RtOpenCAN					= NULL;
		RtCloseCAN					= NULL;
		RtStartCAN					= NULL;
		RtStopCAN					= NULL;
		RtGetPropCAN				= NULL;
		RtSetPropCAN				= NULL;
		RtReadCAN					= NULL;
//zenith 160310 add ver2.0.0.12  - to can read Labview  start --->
		RtReadCANLV					= NULL;
//zenith 160310 add ver2.0.0.12  - to can read Labview  end <---
		RtReadCANRawFrame			= NULL;
		RtWriteCAN					= NULL;


//==============================================================================
// 11. Miscellaneous(Speaker)
//==============================================================================

		RtSpeakerOn					= NULL;
		RtSpeakerOff				= NULL;
		RtSpeakerPlay				= NULL;
		RtSpeakerOnBeep				= NULL;


		bLoaded = FALSE;
		hLib    = 0;
	}
}

#endif  // not STATIC_DLL




// Get error messages

LPSTR RtGetErrorMsg(int nErrorCode, LPSTR szMsg)
{
  switch (nErrorCode) {
    case ERR_NONE:
        szMsg[0] = NULL;
        break;
    case ERR_BOARD_NOT_FOUND:
        StrCpy(szMsg, "Board not Found");
        break;
    case ERR_BOARD_NOT_OPEN:
        StrCpy(szMsg, "Cannot open Board");
        break;
    case ERR_BOARD_NOT_MASTER:
        StrCpy(szMsg, "Master Board not Exists");
        break;
    case ERR_DAQ_ALREADY_STARTED:
        StrCpy(szMsg, "Acq. already started");
        break;
    case ERR_DAQ_NOT_STARTED:
        StrCpy(szMsg, "Acq. not started");
        break;
    case ERR_DAQ_CHANNEL_NOT_ASSIGNED:
        StrCpy(szMsg, "Must added channel 1 or more");
        break;
    case ERR_DAQ_CANNOT_CONFIGURE:
        StrCpy(szMsg, "Cannot Configure");
        break;
    case ERR_DAQ_CANNOT_START:
        StrCpy(szMsg, "Cannot Start");
        break;
    case ERR_INVALID_BOARD_NO:
        StrCpy(szMsg, "Invalid Board No.");
        break;
    case ERR_INVALID_CHANNEL_NO:
        StrCpy(szMsg, "Invalid Channel No.");
        break;
    case ERR_INVALID_CHANNEL_COUNT:
        StrCpy(szMsg, "Invalid Channel Count");
        break;
    case ERR_INVALID_VALUE:
        StrCpy(szMsg, "Invalid parameter Value");
        break;
    case ERR_INVALID_PARAM_ID:
        StrCpy(szMsg, "Invalid parameter ID");
        break;
    case ERR_INVALID_IOCTL:
        StrCpy(szMsg, "Invalid IOCTL CODE");
        break;

    case ERR_DMA_CANNOT_OPEN:
        StrCpy(szMsg, "Cannot open DMA");
        break;
    case ERR_DMA_CANNOT_START:
        StrCpy(szMsg, "Cannot start DMA");
        break;

    case ERR_MEM_BUFFER_NOT_ASSIGNED:
        StrCpy(szMsg, "Not Assigned DMA Buffer");
        break;
    case ERR_MEM_INVALID_BLOCK_COUNT:
        StrCpy(szMsg, "Invalid block count");
        break;

    case ERR_STATUS_DMA:
        StrCpy(szMsg, "DMA Error");
        break;
    case ERR_STATUS_FIFO_FULL:  
        StrCpy(szMsg, "FIFO Full Error");
        break;
    case ERR_STATUS_INT:
        StrCpy(szMsg, "Interrupt is not Cleared");
        break;
    case ERR_STATUS_OVERWRITE:
        StrCpy(szMsg, "Buffer Overwrite");
        break;
    case ERR_TIMEOUT:
        StrCpy(szMsg, "Timeout");
        break;

    case ERR_NOT_SUPPORT_X64_DMA_ADDR:
        StrCpy(szMsg, "Cannot support 64bit DMA Address");
        break;

    default:
        StrCpy(szMsg, "Unknown Error");
    }

  return szMsg;
}

#if 0
void RtCheck(BOOLEAN bOk)
{
  char szMsg[255];
  int  nErr;

  if (bOk) return;

  RtGetParam(0, PARAM_LAST_ERROR, &nErr);
  if (nErr == ERR_NONE)
      return;
  else if (RtGetErrorMsg(nErr, szMsg) != NULL)
    throw szMsg;
}
#endif

typedef struct tagBOARDNAME {
    DWORD ModelNo;
    CHAR  Name[80];
} BOARDNAME, *PBOARDNAME;

BOOL GetBoardName(LPSTR szName, DWORD nModelNo)
{
    int i;
	BOARDNAME aBoardNames[30] = {

		//
        {BOARD_ORION_1616_100, "ORION-1616-100"},
        {BOARD_ORION_1616_101, "ORION-1616-101"},
        {BOARD_ORION_1616_102, "ORION-1616-102"},
        {BOARD_ORION_1616_103, "ORION-1616-103"},
        {BOARD_ORION_1616_104, "ORION-1616-104"},
        {BOARD_ORION_1616_105, "ORION-1616-105"},
        {BOARD_ORION_3216_100, "ORION-3216-100"},
        {BOARD_ORION_3216_101, "ORION-3216-101"},
		
		//
		{BOARD_ORION_1616_500, "ORION-1616-500"},
        {BOARD_ORION_1616_501, "ORION-1616-501"},
        {BOARD_ORION_1616_502, "ORION-1616-502"},
        {BOARD_ORION_1616_503, "ORION-1616-503"},
        {BOARD_ORION_1616_504, "ORION-1616-504"},
        {BOARD_ORION_1616_505, "ORION-1616-505"},

		//
		{BOARD_ORION_0816_1000, "ORION-0816-1000"},
        {BOARD_ORION_0816_1001, "ORION-0816-1001"},
        {BOARD_ORION_0816_1002, "ORION-0816-1002"},
        {BOARD_ORION_0816_1003, "ORION-0816-1003"},
        {BOARD_ORION_0816_1004, "ORION-0816-1004"},
        {BOARD_ORION_0816_1005, "ORION-0816-1005"},

		//
        {BOARD_ORION_1616_1000, "ORION-1616-1000"},
        {BOARD_ORION_1616_1001, "ORION-1616-1001"},
        {BOARD_ORION_1616_1002, "ORION-1616-1002"},
        {BOARD_ORION_1616_1003, "ORION-1616-1003"},
        {BOARD_ORION_1616_1004, "ORION-1616-1004"},
        {BOARD_ORION_1616_1005, "ORION-1616-1005"},

		//
		{BOARD_ORION_0816_5M,   "ORION-0816-5M"},
        {BOARD_ORION_0816_5M1,  "ORION-0816-5M1"},

		//
		{BOARD_ORION_0816_10M,  "ORION-0816-10M"},
        {BOARD_ORION_0816_10M1, "ORION-0816-10M1"},
    };

	for (i = 0; i < sizeof(aBoardNames) / sizeof(BOARDNAME); i++) {
		
		if (nModelNo == aBoardNames[i].ModelNo) {
            StrCpy(szName, aBoardNames[i].Name);
            return TRUE;
        }
    }

    StrCpy(szName, "ORION-DAQ");
    return FALSE;
}

