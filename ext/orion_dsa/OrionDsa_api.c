
/**********************************************************************
 *
 *      File Name	: OrionDsa_api.h
 *
 *      Revision	: 2012.12.07.
 *
 *      Version		: Ver 1.1
 *
 *      Author		: Soo-Hong Kim
 *
 *      E - Mail	: shkim@dewetron.co.kr
 *
 *
 *      - Description -
 *
 *      The header file of OrionDsa API
 *
 *
 *		Copyright (C) Dewetron Korea, LTD.
 *
 **********************************************************************/
//#include "stdafx.h"	// Visual Studio setup :
						//		C/C++ -> Precompiled headers ->
						//		Create/Use Precompiled Header -> "Not Using Precompiled Header"

#include "OrionDsa_api.h"

#include <wtypes.h>

#ifndef RT_IMPORT
	#define RT_IMPORT WINAPI
#endif



#ifndef STATIC_DLL

//
#ifdef RTDAQ_API_X64
	#define RTDAQ_DLL_NAME      "DWdsa_api_x64.dll"
#else
	#define RTDAQ_DLL_NAME      "DWdsa_api.dll"
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

PRTGETSPECINFO					RtGetSpecInfo;
PRTGETPCIINFO					RtGetPciInfo;
PRTGETBOARDINFO					RtGetBoardInfo;


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
PRTGETDATA						RtGetData;
PRTGETDATAEX					RtGetDataEx;
PRTGETDATAEX1					RtGetDataEx1;
PRTGETCURRENTPOS				RtGetCurrentPos;


// Multi mode

PRTSYNCREAD						RtSyncRead;
PRTSYNCGETDATA					RtSyncGetData;
PRTSYNCGETDATAEX				RtSyncGetDataEx;
PRTSYNCGETDATAEX1				RtSyncGetDataEx1;


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

PRTGETAICHANNELPROPICP			RtGetAIChannelPropICP;
PRTSETAICHANNELPROPICP			RtSetAIChannelPropICP;

PRTGETCHANNELFACTOR				RtGetChannelFactor;
PRTGETCHANNELOFFSET				RtGetChannelOffset;


// Multi mode

PRTSYNCADDCHANNEL				RtSyncAddChannel;
PRTSYNCGETMAXCHANNELCOUNT		RtSyncGetMaxChannelCount;
PRTSYNCGETCHANNELCOUNT			RtSyncGetChannelCount;
PRTSYNCGETCHANNELNO				RtSyncGetChannelNo;
PRTSYNCCLEARCHANNELS			RtSyncClearChannels;

PRTSYNCGETCHANNELPROP			RtSyncGetChannelProp;
PRTSYNCSETCHANNELPROP			RtSyncSetChannelProp;

PRTSYNCGETAICHANNELPROPICP		RtSyncGetAIChannelPropICP;
PRTSYNCSETAICHANNELPROPICP		RtSyncSetAIChannelPropICP;

PRTSYNCGETCHANNELFACTOR			RtSyncGetChannelFactor;
PRTSYNCGETCHANNELOFFSET			RtSyncGetChannelOffset;


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


// Multi mode

PRTSYNCADDCHANNELCTR			RtSyncAddChannelCTR;
PRTSYNCGETMAXCHANNELCOUNTCTR	RtSyncGetMaxChannelCountCTR;
PRTSYNCGETCHANNELCOUNTCTR		RtSyncGetChannelCountCTR;
PRTSYNCGETCHANNELNOCTR			RtSyncGetChannelNoCTR;
PRTSYNCCLEARCHANNELSCTR			RtSyncClearChannelsCTR;

PRTSYNCGETCHANNELCTR			RtSyncGetChannelCTR;
PRTSYNCGETCHANNELPROPCTR		RtSyncGetChannelPropCTR;
PRTSYNCSETCHANNELPROPCTR		RtSyncSetChannelPropCTR;


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
//	hLib = LoadLibrary(RTDAQ_DLL_NAME);
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

		RtGetSpecInfo				= (PRTGETSPECINFO)				GetProcAddress(hLib, "RtGetSpecInfo");
		RtGetPciInfo				= (PRTGETPCIINFO)				GetProcAddress(hLib, "RtGetPciInfo");
		RtGetBoardInfo				= (PRTGETBOARDINFO)				GetProcAddress(hLib, "RtGetBoardInfo");


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
		RtGetData					= (PRTGETDATA)					GetProcAddress(hLib, "RtGetData");
		RtGetDataEx					= (PRTGETDATAEX)				GetProcAddress(hLib, "RtGetDataEx");
        RtGetDataEx1                = (PRTGETDATAEX1)               GetProcAddress(hLib, "RtGetDataEx1");
		RtGetCurrentPos				= (PRTGETCURRENTPOS)			GetProcAddress(hLib, "RtGetCurrentPos");


		// Multi mode

		RtSyncRead					= (PRTSYNCREAD)					GetProcAddress(hLib, "RtSyncRead");
		RtSyncGetData				= (PRTSYNCGETDATA)				GetProcAddress(hLib, "RtSyncGetData");
		RtSyncGetDataEx				= (PRTSYNCGETDATAEX)			GetProcAddress(hLib, "RtSyncGetDataEx");
        RtSyncGetDataEx1            = (PRTSYNCGETDATAEX1)           GetProcAddress(hLib, "RtSyncGetDataEx1");


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

		RtGetAIChannelPropICP		= (PRTGETAICHANNELPROPICP)		GetProcAddress(hLib, "RtGetAIChannelPropICP");
		RtSetAIChannelPropICP		= (PRTSETAICHANNELPROPICP)		GetProcAddress(hLib, "RtSetAIChannelPropICP");

		RtGetChannelFactor			= (PRTGETCHANNELFACTOR)			GetProcAddress(hLib, "RtGetChannelFactor");
		RtGetChannelOffset			= (PRTGETCHANNELOFFSET)			GetProcAddress(hLib, "RtGetChannelOffset");


		// Multi mode

		RtSyncAddChannel			= (PRTSYNCADDCHANNEL)			GetProcAddress(hLib, "RtSyncAddChannel");
		RtSyncGetMaxChannelCount	= (PRTSYNCGETMAXCHANNELCOUNT)	GetProcAddress(hLib, "RtSyncGetMaxChannelCount");
		RtSyncGetChannelCount		= (PRTSYNCGETCHANNELCOUNT)		GetProcAddress(hLib, "RtSyncGetChannelCount");
		RtSyncGetChannelNo			= (PRTSYNCGETCHANNELNO)			GetProcAddress(hLib, "RtSyncGetChannelNo");
		RtSyncClearChannels			= (PRTSYNCCLEARCHANNELS)		GetProcAddress(hLib, "RtSyncClearChannels");

		RtSyncGetChannelProp		= (PRTSYNCGETCHANNELPROP)		GetProcAddress(hLib, "RtSyncGetChannelProp");
		RtSyncSetChannelProp		= (PRTSYNCSETCHANNELPROP)		GetProcAddress(hLib, "RtSyncSetChannelProp");

		RtSyncGetAIChannelPropICP	= (PRTSYNCGETAICHANNELPROPICP)	GetProcAddress(hLib, "RtSyncGetAIChannelPropICP");
		RtSyncSetAIChannelPropICP	= (PRTSYNCSETAICHANNELPROPICP)	GetProcAddress(hLib, "RtSyncSetAIChannelPropICP");

		RtSyncGetChannelFactor      =  (PRTSYNCGETCHANNELFACTOR)	GetProcAddress(hLib, "RtSyncGetChannelFactor");
		RtSyncGetChannelOffset      =  (PRTSYNCGETCHANNELOFFSET)	GetProcAddress(hLib, "RtSyncGetChannelOffset");


//==============================================================================
// 5. Counter channel setup and information
//    (Counter 채널 설정 및 채널 정보)
//==============================================================================

		// Single mode

		RtAddChannelCTR				= (PRTADDCHANNELCTR)			GetProcAddress(hLib, "RtAddChannelCTR");
		RtGetMaxChannelCountCTR		= (PRTGETMAXCHANNELCOUNTCTR)	GetProcAddress(hLib, "RtGetMaxChannelCountCTR");
		RtGetChannelCountCTR		= (PRTGETCHANNELCOUNTCTR)		GetProcAddress(hLib, "RtGetChannelCountCTR");
		RtGetChannelNoCTR			= (PRTGETCHANNELNOCTR)			GetProcAddress(hLib, "RtGetChannelNoCTR");
		RtClearChannelsCTR			= (PRTCLEARCHANNELSCTR)			GetProcAddress(hLib, "RtClearChannelsCTR");

		RtGetChannelCTR				= (PRTGETCHANNELCTR)			GetProcAddress(hLib, "RtGetChannelCTR");
		RtGetChannelPropCTR			= (PRTGETCHANNELPROPCTR)		GetProcAddress(hLib, "RtGetChannelPropCTR");
		RtSetChannelPropCTR			= (PRTSETCHANNELPROPCTR)		GetProcAddress(hLib, "RtSetChannelPropCTR");


		// Multi mode

		RtSyncAddChannelCTR			= (PRTSYNCADDCHANNELCTR)		GetProcAddress(hLib, "RtSyncAddChannelCTR");
		RtSyncGetMaxChannelCountCTR	= (PRTSYNCGETMAXCHANNELCOUNTCTR)GetProcAddress(hLib, "RtSyncGetMaxChannelCountCTR");
		RtSyncGetChannelCountCTR	= (PRTSYNCGETCHANNELCOUNTCTR)	GetProcAddress(hLib, "RtSyncGetChannelCountCTR");
		RtSyncGetChannelNoCTR		= (PRTSYNCGETCHANNELNOCTR)		GetProcAddress(hLib, "RtSyncGetChannelNoCTR");
		RtSyncClearChannelsCTR		= (PRTSYNCCLEARCHANNELSCTR)		GetProcAddress(hLib, "RtSyncClearChannelsCTR");

		RtSyncGetChannelCTR			= (PRTSYNCGETCHANNELCTR)		GetProcAddress(hLib, "RtSyncGetChannelCTR");
		RtSyncGetChannelPropCTR		= (PRTSYNCGETCHANNELPROPCTR)	GetProcAddress(hLib, "RtSyncGetChannelPropCTR");
		RtSyncSetChannelPropCTR		= (PRTSYNCSETCHANNELPROPCTR)	GetProcAddress(hLib, "RtSyncSetChannelPropCTR");


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
		RtSyncSetChannelPropDI		= (PRTSYNCSETCHANNELPROPDI)		GetProcAddress(hLib, "RtSyncSetChannelPropDI");
		RtSyncGetChannelPropDI		= (PRTSYNCGETCHANNELPROPDI)		GetProcAddress(hLib, "RtSyncGetChannelPropDI");


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

		RtInitialBoards             =  NULL;
		RtGetBoardCount             =  NULL;

		RtGetSpecInfo               =  NULL;
		RtGetPciInfo                =  NULL;
		RtGetBoardInfo              =  NULL;


//==============================================================================
// 2. Open/Close & Start/Stop
//    (열기/닫기 & 시작/종료)
//==============================================================================

		// Single mode

		RtOpen                      =  NULL;
		RtClose                     =  NULL;
		RtStart                     =  NULL;
		RtStop                      =  NULL;


		// Multi mode

		RtSyncSetMaster             =  NULL;
		RtSyncSetSlaveMaster        =  NULL;
		RtSyncAddSlave              =  NULL;
		RtSyncClear                 =  NULL;

		RtSyncClose                 =  NULL;
		RtSyncStart                 =  NULL;
		RtSyncStop                  =  NULL;


//==============================================================================
// 3. Data Acquisition
//    (데이터 읽기)
//==============================================================================

		// Single mode

		RtRead                      =  NULL;
		RtGetData                   =  NULL;
		RtGetDataEx                 =  NULL;
        RtGetDataEx1                =  NULL;

		RtGetCurrentPos             =  NULL;


		// Multi mode

		RtSyncRead                  =  NULL;
		RtSyncGetData               =  NULL;
		RtSyncGetDataEx             =  NULL;
        RtSyncGetDataEx1            =  NULL;


//==============================================================================
// 4. Analog channel setup and information
//    (AI 채널 설정 및 채널 정보)
//==============================================================================

		// Single mode

		RtAddChannel                =  NULL;
		RtGetMaxChannelCount        =  NULL;
		RtGetChannelCount           =  NULL;
		RtGetChannelNo              =  NULL;
		RtClearChannels             =  NULL;

		RtGetChannelProp            =  NULL;
		RtSetChannelProp            =  NULL;

		RtGetAIChannelPropICP       =  NULL;
		RtSetAIChannelPropICP       =  NULL;

		RtGetChannelFactor          =  NULL;
		RtGetChannelOffset          =  NULL;


		// Multi  mode

		RtSyncAddChannel            =  NULL;
		RtSyncGetMaxChannelCount    =  NULL;
		RtSyncGetChannelCount       =  NULL;
		RtSyncGetChannelNo          =  NULL;
		RtSyncClearChannels         =  NULL;

		RtSyncGetChannelProp        =  NULL;
		RtSyncSetChannelProp        =  NULL;

		RtSyncGetAIChannelPropICP	=  NULL;
		RtSyncSetAIChannelPropICP	=  NULL;

		RtSyncGetChannelFactor      =  NULL;
		RtSyncGetChannelOffset      =  NULL;


//==============================================================================
// 5. Counter channel setup and information
//    (Counter 채널 설정 및 채널 정보)
//==============================================================================

		// Single mode

		RtAddChannelCTR             =  NULL;
		RtGetMaxChannelCountCTR     =  NULL;
		RtGetChannelCountCTR        =  NULL;
		RtGetChannelNoCTR           =  NULL;
		RtClearChannelsCTR          =  NULL;

		RtGetChannelCTR             =  NULL;
		RtGetChannelPropCTR         =  NULL;
		RtSetChannelPropCTR         =  NULL;


		// Multi mode

		RtSyncAddChannelCTR         =  NULL;
		RtSyncGetMaxChannelCountCTR =  NULL;
		RtSyncGetChannelCountCTR    =  NULL;
		RtSyncGetChannelNoCTR       =  NULL;
		RtSyncClearChannelsCTR      =  NULL;

		RtSyncGetChannelCTR         =  NULL;
		RtSyncGetChannelPropCTR     =  NULL;
		RtSyncSetChannelPropCTR     =  NULL;


//==============================================================================
// 6. Digital I/O channel setup and information
//    (DIO 채널 설정 및 채널 정보)
//==============================================================================

		 // Single mode

		RtAddChannelDI              =  NULL;
		RtGetMaxChannelCountDI      =  NULL;
		RtGetChannelCountDI         =  NULL;
		RtGetChannelNoDI            =  NULL;
		RtClearChannelsDI           =  NULL;

		RtGetChannelDI              =  NULL;
		RtGetChannelPropDI          =  NULL;
		RtSetChannelPropDI          =  NULL;


		 // Multi mode

		RtSyncAddChannelDI          =  NULL;
		RtSyncGetMaxChannelCountDI  =  NULL;
		RtSyncGetChannelCountDI     =  NULL;
		RtSyncGetChannelNoDI        =  NULL;
		RtSyncClearChannelsDI       =  NULL;

		RtSyncGetChannelDI          =  NULL;
		RtSyncGetChannelPropDI      =  NULL;
		RtSyncSetChannelPropDI      =  NULL;


//==============================================================================
// 7. Adjustable Counter/Digital Input channel setup
//    (Adjustable Counter/DI 설정)
//==============================================================================

		RtGetAdjChannelProp         =  NULL;
		RtSetAdjChannelProp         =  NULL;


//==============================================================================
// 8. Parameter setup
//    (파라미터 설정)
//==============================================================================

		// Single mode

		RtGetParam                  =  NULL;
		RtSetParam                  =  NULL;
		RtUpdateParams              =  NULL;
		RtConfigure                 =  NULL;


		// Multi mode

		RtSyncSetParam              =  NULL;
		RtSyncUpdateParams          =  NULL;
		RtSyncConfigure             =  NULL;


//==============================================================================
// 9. RS485
//==============================================================================

		RtOpenRS485                 =  NULL;
		RtCloseRS485                =  NULL;
		RtGetPropRS485              =  NULL;
		RtSetPropRS485              =  NULL;
		RtReadyDataRS485            =  NULL;
		RtReadRS485                 =  NULL;
		RtWriteRS485                =  NULL;


//==============================================================================
// 10. CAN
//==============================================================================

		RtOpenCAN                   =  NULL;
		RtCloseCAN                  =  NULL;
		RtStartCAN                  =  NULL;
		RtStopCAN                   =  NULL;
		RtSetPropCAN                =  NULL;
		RtGetPropCAN                =  NULL;
		RtReadCAN                   =  NULL;
		RtReadCANRawFrame			=  NULL;
		RtWriteCAN                  =  NULL;


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
#endif





// Get error messages

LPSTR RtGetErrorMsg(int nErrorCode, LPSTR szMsg)
{
  switch (nErrorCode) {
    case ERR_NONE:
        szMsg[0] = NULL;
        break;
    case ERR_BOARD_NOT_FOUND:
        strcpy(szMsg, "Board not Found");
        break;
    case ERR_BOARD_NOT_OPEN:
        strcpy(szMsg, "Cannot open Board");
        break;
    case ERR_BOARD_NOT_MASTER:
        strcpy(szMsg, "Master Board not Exists");
        break;
    case ERR_DAQ_ALREADY_STARTED:
        strcpy(szMsg, "Acq. already started");
        break;
    case ERR_DAQ_NOT_STARTED:
        strcpy(szMsg, "Acq. not started");
        break;
    case ERR_DAQ_CHANNEL_NOT_ASSIGNED:
        strcpy(szMsg, "Must added channel 1 or more");
        break;
    case ERR_DAQ_CANNOT_CONFIGURE:
        strcpy(szMsg, "Cannot Configure");
        break;
    case ERR_DAQ_CANNOT_START:
        strcpy(szMsg, "Cannot Start");
        break;
    case ERR_DAQ_CANNOT_UPDATE_CALINFO:
        strcpy(szMsg, "Cannot update cal. Info");
        break;
    case ERR_INVALID_BOARD_NO:
        strcpy(szMsg, "Invalid Board No.");
        break;
    case ERR_INVALID_CHANNEL_NO:
        strcpy(szMsg, "Invalid Channel No.");
        break;
    case ERR_INVALID_CHANNEL_COUNT:
        strcpy(szMsg, "Invalid Channel Count");
        break;
    case ERR_INVALID_VALUE:
        strcpy(szMsg, "Invalid parameter Value");
        break;
    case ERR_INVALID_PARAM_ID:
        strcpy(szMsg, "Invalid parameter ID");
        break;
    case ERR_INVALID_IOCTL:
        strcpy(szMsg, "Invalid IOCTL CODE");
        break;
    case ERR_NOT_SUPPORTED_FUNCTION:
        strcpy(szMsg, "Cannot supported function");
        break;
    case ERR_DMA_CANNOT_OPEN:
        strcpy(szMsg, "Cannot open DMA");
        break;
    case ERR_DMA_CANNOT_START:
        strcpy(szMsg, "Cannot start DMA");
        break;
    case ERR_MEM_BUFFER_NOT_ASSIGNED:
        strcpy(szMsg, "Not Assigned DMA Buffer");
        break;
    case ERR_MEM_INVALID_BLOCK_COUNT:
        strcpy(szMsg, "Invalid block count");
        break;
    case ERR_STATUS_DMA:
        strcpy(szMsg, "DMA Error");
        break;
    case ERR_STATUS_FIFO_FULL:
        strcpy(szMsg, "FIFO Full Error");
        break;
    case ERR_STATUS_INT:
        strcpy(szMsg, "Interrupt is not Cleared");
        break;
    case ERR_STATUS_OVERWRITE:
        strcpy(szMsg, "Buffer Overwrite");
        break;
    case ERR_TIMEOUT:
        strcpy(szMsg, "Timeout");
        break;
    case ERR_NOT_SUPPORT_X64_DMA_ADDR:
        strcpy(szMsg, "Cannot support x64 DMA");
        break;
    default:
        strcpy(szMsg, "Unknown Error");
    }

  return szMsg;
}


// Check error
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
