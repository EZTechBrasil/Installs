/*****************************************************************
 *
 * Copyright (C) 2009-2010 EZTech Tecnologia e Automação Ltda. 
 * All rights reserved.
 *
 * Created 01/06/2005
 * 
 * File: EZClient.h 
 * Desc: EZClient.DLL API definitions header file  
 *
 * Visual SourceSafe details 
 * =========================
 *
 * $Header: /EZController.root/EZController/EZClientDLL/EZClient.h 1     17/04/07 13:55 Kelvin Ussher $
 * $History: EZClient.h $
 * 
 * *****************  Version 1  *****************
 * User: Kelvin Ussher Date: 17/04/07   Time: 13:55
 * Created in $/EZController.root/EZController/EZClientDLL
 * 
 * 
 ******************************************************************/

#pragma once

#ifdef _ANDROID_ 

#include "Android/Headers.h"

#elif defined( __linux__ )

// #include "Linux/Headers.h"

#else


#ifdef _EZCLIENT_LIB 

#define EZ_DLL_CALL                extern "C" __attribute__ ((cdecl)) LONG 
#define EZ_DLL_BSTR                extern "C" __attribute__ ((cdecl)) wchar_t* 

#else 

#define EZ_DLL_CALL extern "C" __declspec(dllexport) LONG __stdcall
#define EZ_DLL_BSTR extern "C" __declspec(dllexport) BSTR __stdcall

#endif 


typedef BSTR*			PBSTR;

#endif 

EZ_DLL_CALL DllVersion( PBSTR pName ) ;
EZ_DLL_BSTR ResultString( LONG Res ) ;
EZ_DLL_BSTR PumpStateString( short State ) ;
EZ_DLL_BSTR DeliveryStateString( short State ) ;
EZ_DLL_BSTR DeliveryTypeString( short Type ) ;
EZ_DLL_BSTR ReserveTypeString( short Type ) ;

#ifndef _USE_MT 

EZ_DLL_CALL ServerVersion( PBSTR pName ) ;
EZ_DLL_CALL ClientLogon( LONG ClientID , short ClientType , HANDLE Event , HWND hWnd, unsigned int wMsg) ;
EZ_DLL_CALL ClientLogonEx( LONG ClientID , short ClientType , BSTR ServerName , unsigned short CallPortNo , unsigned short EventsPortNo , LONG CallTimeout, HANDLE Event , HWND hWnd, unsigned int wMsg) ;
EZ_DLL_CALL ClientLogoff() ;
EZ_DLL_CALL ClientStatus( short* pPumpsReserved , short* pdeliveriesLocked ) ;
EZ_DLL_CALL GetLicenseType( short* pLicenseType ) ;
EZ_DLL_CALL FireClientEvent( LONG EventID , BSTR EventStr ) ;
EZ_DLL_CALL CheckforManagementFtn();
EZ_DLL_CALL TestConnection() ;
EZ_DLL_CALL FireEvents();

EZ_DLL_CALL ProcessEvents() ;
EZ_DLL_CALL GetEventsCount( LONG* pCount ) ;
EZ_DLL_CALL GetNextEventType( short* pType ) ;
EZ_DLL_CALL DiscardNextEvent() ;
EZ_DLL_CALL GetNextPumpEvent( LONG* pPumpID, short* pPumpNumber, short* pState, short* pReservedFor, LONG* pReservedBy, LONG* pHoseID ,
							   short* pHoseNumber, LONG* pGradeID, PBSTR pGradeName , PBSTR pShortGradeName, short* pPriceLevel , double* pPrice, double* pVolume, 
							   double* pValue, short* pStackSize ) ;
EZ_DLL_CALL GetNextDeliveryEvent( LONG* pDeliveryID , LONG* pPumpID, short* pPumpNumber, LONG* pHoseID, short* pHoseNumber , 
								LONG* pGradeID, PBSTR pGradeName ,PBSTR pShortGradeName, short* pPriceLevel, double* pPrice, double* pVolume, double* pValue, 
								short* pDeliveryState , short* pDeliveryType, LONG* pLockedBy, LONG* pReservedBy, LONG* pAge , DATE* pCompletedDT , LONG* pAttendantID ) ;
EZ_DLL_CALL GetNextServerEvent( LONG* pEventID, PBSTR pEventText ) ;
EZ_DLL_CALL GetNextClientEvent( LONG* pClientID, LONG* pEventID, PBSTR pEventText ) ;
EZ_DLL_CALL GetNextDBLogEvent( LONG* pEventType , LONG* pDeviceID , DATE* pEventDT , PBSTR pEventText ) ;
EZ_DLL_CALL GetNextDBLogDeliveryEvent( LONG* pDeliveryID, LONG* pHoseID, short* pDeliveryState, short* pDeliveryType, double* pVolume, short* pPriceLevel, 
							 double* pPrice, double* pValue, double* pVolume2, LONG* pReservedBy , LONG* pAttendantID, DATE* pDeliveryDT ) ;
EZ_DLL_CALL GetNextDBClearDeliveryEvent( LONG* pDeliveryID, short* pDeliveryType, LONG* pClearedBY, DATE* pClearedDT, LONG* pAttendantID ) ;
EZ_DLL_CALL GetNextDBStackDeliveryEvent( LONG* pDeliveryID ) ;
EZ_DLL_CALL GetNextDBHoseETotalsEvent( LONG* pHoseID , double* pVolume , double* pValue , double* pVolumeETot , double* pValueETot ) ;
EZ_DLL_CALL GetNextDBTriggerEvent( LONG* pTableID ,LONG* pRowID ) ;
EZ_DLL_CALL GetNextDBAttendantLogonEvent( LONG* pAttendantID ,LONG* pPumpID ) ;
EZ_DLL_CALL GetNextDBAttendantLogoffEvent( LONG* pAttendantID ) ;
EZ_DLL_CALL GetNextDBTankStatusEvent( LONG* pTankID , double* pGaugeVolume , double* pGaugeTCVolume, double* pGaugeUllage, double* pGaugeTemperature , 
							          double* pGaugeLevel , double* pGaugeWaterVolume, double* pGaugeWaterLevel ) ;
EZ_DLL_CALL GetClientsCount( LONG* pCount ) ;
EZ_DLL_CALL GetPumpsCount( LONG* pCount ) ;
EZ_DLL_CALL GetPumpByNumber( LONG Number , LONG* pID ) ;
EZ_DLL_CALL GetPumpByName( BSTR Name , LONG* pID ) ;
EZ_DLL_CALL GetPumpByOrdinal( LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetPumpProperties(LONG ID , LONG* pNumber, PBSTR pName, short* pPhysicalNumber, short* pSide, short* pAddress, short* pPriceLevel1,
						      short* pPriceLevel2, short* pPriceDspFormat, short* pVolumeDspFormat, short* pValueDspFormat, short* pType,  
						      LONG* pPortID, LONG* pAttendantID, short* pAuthMode, short* pStackMode, short* pPrepayAllowed, short* pPreauthAllowed ) ;
EZ_DLL_CALL SetPumpProperties(LONG ID , LONG Number, BSTR Name, short PhysicalNumber, short Side, short Address, short PriceLevel1,
						      short PriceLevel2, short PriceDspFormat, short VolumeDspFormat, short ValueDspFormat, short Type, 
						      LONG PortID, LONG AttendantID, short AuthMode, short StackMode, short PrepayAllowed, short PreauthAllowed ) ;

EZ_DLL_CALL AddPump( LONG* pID, LONG* pNumber, BSTR Name, short PhysicalNumber, short Side, short Address, short PriceLevel1,
						        short PriceLevel2, short PriceDspFormat, short VolumeDspFormat, short ValueDspFormat, short Type, 
						        LONG PortID, LONG AttendantID, short AuthMode, short StackMode, short PrepayAllowed, short PreauthAllowed , 
								LONG SlotZigBeeID , LONG MuxSlotZigBeeID , short PriceControl , short HasPreset  ) ;

EZ_DLL_CALL DeletePump( LONG ID ) ;
EZ_DLL_CALL GetPumpHosesCount( LONG ID , LONG* pCount ) ;
EZ_DLL_CALL GetPumpHoseByNumber( LONG ID , LONG Number , LONG* pHoseID ) ;
EZ_DLL_CALL GetPumpStatus( LONG ID , short* pState, short* pReservedFor, LONG* pReservedBy, LONG* pHoseID, short* pHoseNumber , 
						   LONG* pGradeID, PBSTR pGradeName ,PBSTR pShortGradeName, short* pPriceLevel , double* pPrice , double* pVolume , double* pValue , 
						   short* pStackSize ) ;

EZ_DLL_CALL GetPumpStatusEx( LONG ID , LONG* pPumpNumber, PBSTR pPumpName, LONG* pPhysicalNumber, short* pState, short* pReservedFor, LONG* pReservedBy, LONG* pHoseID, LONG* pHoseNumber , LONG* pHosePhysicalNumber , LONG* pGradeID , 
					   LONG* pGradeNumber , PBSTR pGradeName, PBSTR pShortGradeName, short* pPriceLevel , double* pPrice , double* pVolume , double* pValue , 
					   short* pStackSize , __int64* pTag , 
					   LONG* pAttendantID , LONG* pAttendantNumber , PBSTR pAttendantName, __int64* pAttendantTag ,
					   LONG* pCardClientID , LONG* pCardClientNumber , PBSTR pCardClientName, __int64* pCardClientTag ) ;

EZ_DLL_CALL GetPumpStatusEx2( LONG ID , LONG* pPumpNumber, PBSTR pPumpName, LONG* pPhysicalNumber, short* pState, short* pReservedFor, LONG* pReservedBy, LONG* pHoseID, LONG* pHoseNumber , LONG* pHosePhysicalNumber , LONG* pGradeID , 
							  LONG* pGradeNumber , PBSTR pGradeName, PBSTR pShortGradeName, short* pPriceLevel , double* pPrice , double* pVolume , double* pValue , short* pStackSize , __int64* pTag , 
							  LONG* pAttendantID , LONG* pAttendantNumber , PBSTR pAttendantName, __int64* pAttendantTag ,
							  LONG* pCardClientID , LONG* pCardClientNumber , PBSTR pCardClientName, __int64* pCardClientTag , 
							  double* pCurFlowRate , double* pPeakFlowRate ) ;

EZ_DLL_CALL GetPumpDeliveryProperties( LONG ID , short Index , LONG* pDeliveryID , short* pType , short* pState, LONG* pHoseID, 
									   short* pHoseNum, LONG* pGradeID , PBSTR pGradeName ,PBSTR pShortGradeName, short* pPriceLevel, double* pPrice , double* pVolume , 
									   double* pValue , LONG* pLockedBy , LONG* pReservedBy , LONG* pAge , DATE* pCompletedDT , LONG* pAttendantID  ) ;
EZ_DLL_CALL GetPumpDeliveryPropertiesEx( LONG ID , short Index , LONG* pDeliveryID , short* pType , short* pState, 
										LONG* pHoseID, short* pHoseNum, 
										LONG* pGradeID, PBSTR pGradeName, PBSTR pShortGradeName , 
								        short* pPriceLevel, double* pPrice , double* pVolume , double* pValue , LONG* pLockedBy , 
									    LONG* pReservedBy , LONG* pAge , DATE* pCompletedDT , LONG* pAttendantID , 
										double* pVolumeETot , double* pVolume2ETot , double* pValueETot , __int64* pTag ) ;
EZ_DLL_CALL GetPumpDeliveryPropertiesEx2( LONG ID , short Index , LONG* pDeliveryID , short* pType , short* pState, LONG* pHoseID, short* pHoseNum, LONG* pGradeID, PBSTR pGradeName, PBSTR pShortGradeName , 
								        short* pPriceLevel, double* pPrice , double* pVolume , double* pValue , LONG* pLockedBy , 
									    LONG* pReservedBy , LONG* pAge , DATE* pCompletedDT , LONG* pAttendantID , 
										double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
										double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
										__int64* pTag , LONG * pDuration ) ;
EZ_DLL_CALL GetPumpDeliveryPropertiesEx3( LONG ID , short Index , LONG* pDeliveryID , short* pType , short* pState, 
										 LONG* pHoseID, short* pHoseNum, 
										 LONG* pGradeID, PBSTR pGradeName, PBSTR pShortGradeName , 
								        short* pPriceLevel, double* pPrice , double* pVolume , double* pValue , LONG* pLockedBy , 
									    LONG* pReservedBy , LONG* pAge , DATE* pCompletedDT , LONG* pAttendantID , 
										double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
										double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
										__int64* pTag , LONG * pDuration , LONG* pCardClientID ) ;
EZ_DLL_CALL PrepayReserve( LONG ID ) ;
EZ_DLL_CALL PrepayCancel( LONG ID  ) ;
EZ_DLL_CALL PrepayAuthorise( LONG ID , short LimitType , double Value , short Hose , short PriceLevel ) ;
EZ_DLL_CALL PreauthReserve( LONG ID ) ;
EZ_DLL_CALL PreauthCancel( LONG ID ) ;
EZ_DLL_CALL PreauthAuthorise( LONG ID , short LimitType , double Value , short Hose , short PriceLevel ) ;
EZ_DLL_CALL LoadPreset( LONG ID , short LimitType , double Value , short Hose , short PriceLevel ) ;
EZ_DLL_CALL LoadPresetWithPrice( LONG ID , short LimitType , double Value , short Hose , short PriceLevel , double Price ) ;
EZ_DLL_CALL TagAuthorise( LONG ID , __int64 Tag , short LimitType , double Value , short Hose , short PriceLevel ) ;

EZ_DLL_CALL AttendantAuthorise( LONG ID , LONG AttendantID ) ;
EZ_DLL_CALL Authorise( LONG ID ) ;
EZ_DLL_CALL CancelAuthorise( LONG ID ) ;
EZ_DLL_CALL TempStop( LONG ID ) ;
EZ_DLL_CALL ReAuthorise( LONG ID ) ;
EZ_DLL_CALL TerminateDelivery( LONG ID ) ;
EZ_DLL_CALL StackCurrentDelivery( LONG ID ) ;
EZ_DLL_CALL GetDensity( LONG ID , double* pDensity) ;
EZ_DLL_CALL EnablePump( LONG ID ) ;
EZ_DLL_CALL DisablePump( LONG ID ) ;

EZ_DLL_CALL GetHosesCount( LONG* pCount ) ;
EZ_DLL_CALL GetHoseByOrdinal( LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetHoseProperties(LONG ID , LONG* pNumber, LONG* pPumpID ,LONG* pTankID , LONG* pPhysicalNumber, 
		                      double* pMtrTheoValue , double* pMtrTheoVolume ,double* pMtrElecValue ,
				              double* pMtrElecVolume ) ;
EZ_DLL_CALL SetHoseProperties(LONG ID , LONG Number,LONG PumpID, LONG TankID , LONG PhysicalNumber, 
		                      double MtrTheoValue , double MtrTheoVolume ,double MtrElecValue ,
				              double MtrElecVolume ) ;
EZ_DLL_CALL GetHoseSummary(	LONG ID , LONG* pNumber, LONG* pPhysicalNumber,
							LONG* pPumpID, LONG* pPumpNumber, PBSTR pPumpName,
							LONG* pTankID, LONG* pTankNumber, PBSTR pTankName,
							LONG* pGradeID , LONG* pGradeNumber, PBSTR pGradeName, PBSTR pGradeShortName, PBSTR pGradeCode,
		                    double* pMtrTheoValue , double* pMtrTheoVolume ,double* pMtrElecValue , double* pMtrElecVolume ) ;

EZ_DLL_CALL GetHoseSummaryEx(	LONG ID , LONG* pNumber, LONG* pPhysicalNumber,
							LONG* pPumpID, LONG* pPumpNumber, PBSTR pPumpName,
							LONG* pTankID, LONG* pTankNumber, PBSTR pTankName,
							LONG* pGradeID , LONG* pGradeNumber, PBSTR pGradeName, PBSTR pGradeShortName, PBSTR pGradeCode,
		                    double* pMtrTheoValue , double* pMtrTheoVolume ,double* pMtrElecValue , double* pMtrElecVolume ,
							double* pPrice1 , double* pPrice2 , short* pEnabled) ;

EZ_DLL_CALL GetHoseSummaryEx2(LONG ID , LONG* pNumber, LONG* pPhysicalNumber,
							LONG* pPumpID, LONG* pPumpNumber, PBSTR pPumpName,
							LONG* pTankID, LONG* pTankNumber, PBSTR pTankName,
							LONG* pGradeID , LONG* pGradeNumber, PBSTR pGradeName, PBSTR pGradeShortName, PBSTR pGradeCode,
		                    double* pMtrTheoValue , double* pMtrTheoVolume ,double* pMtrElecValue , double* pMtrElecVolume ,
							double* pPrice1 , double* pPrice2 , double* pPrice3 , double* pPrice4 , short* pEnabled ) ;

EZ_DLL_CALL AddHose( LONG* pID, LONG* pNumber,LONG PumpID, LONG TankID , LONG PhysicalNumber, 
		                      double MtrTheoValue , double MtrTheoVolume ,double MtrElecValue ,
				              double MtrElecVolume , short UVEAntenna , double Price1 , double Price2 , double Price3 , double Price4 , short Enabled ) ;

EZ_DLL_CALL DeleteHose( LONG ID ) ;
EZ_DLL_CALL GetDeliveriesCount( LONG* pCount ) ;
EZ_DLL_CALL GetDeliveryByOrdinal( LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetAllDeliveriesCount( LONG* pCount )  ;
EZ_DLL_CALL GetAllDeliveryByOrdinal( LONG Index , LONG* pID ) ;

EZ_DLL_CALL AckDeliveryDBLog( LONG ID ) ; 
EZ_DLL_CALL GetDeliveryIDByOrdinalNotLogged( LONG Ordinal , LONG* pID ) ;
EZ_DLL_CALL GetDeliveriesCountNotLogged( LONG* pCount ) ;

EZ_DLL_CALL AckDeliveryVolLog( LONG ID ) ; 
EZ_DLL_CALL GetDeliveryIDByOrdinalNotVolLogged( LONG Ordinal , LONG* pID ) ;
EZ_DLL_CALL GetDeliveriesCountNotVolLogged( LONG* pCount ) ;

EZ_DLL_CALL GetDeliveriesCountFiltered(LONG* pCount, LONG PumpID, LONG PumpNumber, LONG HoseID, LONG HoseNumber, LONG HosePhysicalNumber, LONG GradeID, LONG GradeNumber, LONG TankID, LONG TankNumber , LONG LockedBy, LONG ReservedBy, short State, short LoggedDB , short LoggedVolumetric, short Type, __int64 Tag, LONG AttendantID, LONG AttendantNumber, __int64 AttendantTag, LONG CardClientID, LONG CardClientNumber, __int64 CardClientTag);
EZ_DLL_CALL GetDeliveryIDByOrdinalFiltered(LONG Ordinal, LONG* pID, LONG PumpID, LONG PumpNumber, LONG HoseID, LONG HoseNumber, LONG HosePhysicalNumber, LONG GradeID, LONG GradeNumber, LONG TankID, LONG TankNumber , LONG LockedBy, LONG ReservedBy, short State, short LoggedDB , short LoggedVolumetric, short Type, __int64 Tag, LONG AttendantID, LONG AttendantNumber, __int64 AttendantTag, LONG CardClientID, LONG CardClientNumber, __int64 CardClientTag);
EZ_DLL_CALL GetDeliveriesCountFilteredEx(LONG* pCount, LONG PumpID, LONG PumpNumber, LONG HoseID, LONG HoseNumber, LONG HosePhysicalNumber, LONG GradeID, LONG GradeNumber, LONG TankID, LONG TankNumber, LONG LockedBy, LONG ReservedBy, short State, short LoggedDB, short LoggedVolumetric, short Type, __int64 Tag, LONG AttendantID, LONG AttendantNumber, __int64 AttendantTag, LONG CardClientID, LONG CardClientNumber, __int64 CardClientTag, DATE StartDT, DATE EndDT);
EZ_DLL_CALL GetDeliveryIDByOrdinalFilteredEx(LONG Ordinal, LONG* pID, LONG PumpID, LONG PumpNumber, LONG HoseID, LONG HoseNumber, LONG HosePhysicalNumber, LONG GradeID, LONG GradeNumber, LONG TankID, LONG TankNumber, LONG LockedBy, LONG ReservedBy, short State, short LoggedDB, short LoggedVolumetric, short Type, __int64 Tag, LONG AttendantID, LONG AttendantNumber, __int64 AttendantTag, LONG CardClientID, LONG CardClientNumber, __int64 CardClientTag, DATE StartDT, DATE EndDT);


EZ_DLL_CALL GetDeliveryProperties( LONG ID , LONG* pHoseID ,short* pState ,short* pType ,double* pVolume ,
								   short* pPriceLevel ,double* pPrice ,double* pValue ,double* pVolume2 , 
								   DATE* pCompletedDT ,LONG* pLockedBy , LONG* pReservedBy , LONG* pAttendantID , LONG* pAge ) ;
EZ_DLL_CALL GetDeliveryPropertiesEx( LONG ID , LONG* pHoseID ,short* pState ,short* pType ,double* pVolume ,short* pPriceLevel ,
		                           double* pPrice ,double* pValue ,double* pVolume2 , DATE* pCompletedDT ,LONG* pLockedBy, LONG* pReservedBy , LONG* pAttendantID , LONG* pAge , 
								   DATE* pClearedDT ,double* pVolumeETot , double* pVolume2ETot , double* pValueETot , __int64* pTag ) ;
EZ_DLL_CALL GetDeliveryPropertiesEx2( LONG ID , LONG* pHoseID ,short* pState ,short* pType ,double* pVolume ,short* pPriceLevel ,
		                           double* pPrice ,double* pValue ,double* pVolume2 , DATE* pCompletedDT ,LONG* pLockedBy, LONG* pReservedBy , 
								   LONG* pAttendantID , LONG* pAge , DATE* pClearedDT ,
								   double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
								   double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
								   __int64* pTag , LONG * pDuration ) ;
EZ_DLL_CALL GetDeliveryPropertiesEx3( LONG ID , LONG* pHoseID ,short* pState ,short* pType ,double* pVolume ,short* pPriceLevel ,
		                           double* pPrice ,double* pValue ,double* pVolume2 , DATE* pCompletedDT ,LONG* pLockedBy, LONG* pReservedBy , 
								   LONG* pAttendantID , LONG* pAge , DATE* pClearedDT ,
								   double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
								   double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
								   __int64* pTag , LONG * pDuration , LONG* pCardClientID ) ;

EZ_DLL_CALL GetDeliveryPropertiesEx4( LONG ID , LONG* pHoseID ,short* pState ,short* pType ,double* pVolume ,short* pPriceLevel ,
										double* pPrice ,double* pValue ,double* pVolume2 , DATE* pCompletedDT ,LONG* pLockedBy, LONG* pReservedBy , 
										LONG* pAttendantID , LONG* pAge , DATE* pClearedDT ,
										double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
										double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
										__int64* pTag , LONG * pDuration , LONG* pCardClientID , double* pPeakFlowRate ) ;


EZ_DLL_CALL SetDeliveryPropertiesEx4( LONG ID , LONG HoseID ,short State ,short Type ,double Volume ,short PriceLevel ,
								   double Price ,double Value ,double Volume2 , DATE CompletedDT ,LONG LockedBy, 
								   LONG ReservedBy , LONG AttendantID , LONG Age , DATE ClearedDT , 
								   double OldVolumeETot , double OldVolume2ETot , double OldValueETot , 
								   double NewVolumeETot , double NewVolume2ETot , double NewValueETot , 
								   __int64 Tag , LONG Duration , LONG CardClientID, double PeakFlowRate ) ;

EZ_DLL_CALL GetPumpDeliveryPropertiesEx4( LONG ID , short Index , LONG* pDeliveryID , short* pType , short* pState, LONG* pHoseID, short* pHoseNum, LONG* pGradeID, PBSTR pGradeName, PBSTR pShortGradeName , 
								        short* pPriceLevel, double* pPrice , double* pVolume , double* pValue , LONG* pLockedBy , 
									    LONG* pReservedBy , LONG* pAge , DATE* pCompletedDT , LONG* pAttendantID , 
										double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
										double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
										__int64* pTag , LONG * pDuration , LONG* pCardClientID , double* pPeakFlowRate  ) ;

EZ_DLL_CALL SetDeliveryProperties( LONG ID , LONG HoseID ,short State ,short Type ,double Volume ,short PriceLevel ,
								   double Price ,double Value ,double Volume2, DATE CompletedDT ,LONG LockedBy, LONG ReservedBy , 
								   LONG AttendantID , LONG Age ) ;
EZ_DLL_CALL SetDeliveryPropertiesEx( LONG ID , LONG HoseID ,short State ,short Type ,double Volume ,short PriceLevel ,
								   double Price ,double Value ,double Volume2 , DATE CompletedDT ,LONG LockedBy, 
								   LONG ReservedBy , LONG AttendantID , LONG Age , DATE ClearedDT , double VolumeETot , double Volume2ETot , double ValueETot , __int64 Tag ) ;
EZ_DLL_CALL SetDeliveryPropertiesEx2( LONG ID , LONG HoseID ,short State ,short Type ,double Volume ,short PriceLevel ,
								   double Price ,double Value ,double Volume2 , DATE CompletedDT ,LONG LockedBy, 
								   LONG ReservedBy , LONG AttendantID , LONG Age , DATE ClearedDT , 
								   double OldVolumeETot , double OldVolume2ETot , double OldValueETot , 
								   double NewVolumeETot , double NewVolume2ETot , double NewValueETot , 
								   __int64 Tag , LONG Duration ) ;


EZ_DLL_CALL SetDeliveryPropertiesEx3( LONG ID , LONG HoseID ,short State ,short Type ,double Volume ,short PriceLevel ,
								   double Price ,double Value ,double Volume2 , DATE CompletedDT ,LONG LockedBy, 
								   LONG ReservedBy , LONG AttendantID , LONG Age , DATE ClearedDT , 
								   double OldVolumeETot , double OldVolume2ETot , double OldValueETot , 
								   double NewVolumeETot , double NewVolume2ETot , double NewValueETot , 
								   __int64 Tag , LONG Duration , LONG CardClientID ) ; 

EZ_DLL_CALL GetDeliverySummary( LONG ID , LONG* pHoseID ,LONG* pHoseNumber, LONG* pHosePhysicalNumber,
	  							LONG* pPumpID, LONG* pPumpNumber, PBSTR  pPumpName,
								LONG* pTankID, LONG* pTankNumber, PBSTR  pTankName,
								LONG* pGradeID , LONG* pGradeNumber, PBSTR  pGradeName, PBSTR  pGradeShortName, PBSTR  pGradeCode,
							    short* pState ,short* pType ,double* pVolume ,short* pPriceLevel ,
								double* pPrice ,double* pValue ,double* pVolume2 , DATE* pCompletedDT ,LONG* pLockedBy, 
								LONG* pReservedBy , LONG* pAttendantID , LONG* pAge ,DATE* pClearedDT ,
								double* pVolumeETot , double* pVolume2ETot , double* pValueETot , __int64* pTag) ;
EZ_DLL_CALL GetDeliverySummaryEx( LONG ID , LONG* pHoseID ,LONG* pHoseNumber, LONG* pHosePhysicalNumber,
	  							LONG* pPumpID, LONG* pPumpNumber, PBSTR  pPumpName,
								LONG* pTankID, LONG* pTankNumber, PBSTR  pTankName,
								LONG* pGradeID , LONG* pGradeNumber, PBSTR  pGradeName, PBSTR  pGradeShortName, PBSTR  pGradeCode,
							    short* pState ,short* pType ,double* pVolume ,short* pPriceLevel ,
		                        double* pPrice ,double* pValue ,double* pVolume2 , DATE* pCompletedDT ,LONG* pLockedBy, 
								LONG* pReservedBy , LONG* pAttendantID , LONG* pAge ,DATE* pClearedDT ,
								double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
								double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
								__int64* pTag , LONG * pDuration ) ;
EZ_DLL_CALL GetDeliverySummaryEx2( LONG ID , LONG* pHoseID ,LONG* pHoseNumber, LONG* pHosePhysicalNumber,
	  							LONG* pPumpID, LONG* pPumpNumber, PBSTR  pPumpName,
								LONG* pTankID, LONG* pTankNumber, PBSTR  pTankName,
								LONG* pGradeID , LONG* pGradeNumber, PBSTR  pGradeName, PBSTR  pGradeShortName, PBSTR  pGradeCode,
							    short* pState ,short* pType ,double* pVolume ,short* pPriceLevel ,
		                        double* pPrice ,double* pValue ,double* pVolume2 , DATE* pCompletedDT ,LONG* pLockedBy, 
								LONG* pReservedBy , LONG* pAttendantID , LONG* pAge ,DATE* pClearedDT ,
								double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
								double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
								__int64* pTag , LONG * pDuration , LONG* pAttendantNumber , PBSTR pAttendantName, __int64* pAttendantTag ,
								LONG* pCardClientID , LONG* pCardClientNumber , PBSTR pCardClientName, __int64* pCardClientTag ) ;
EZ_DLL_CALL GetDeliverySummaryEx3( LONG ID , LONG* pHoseID ,LONG* pHoseNumber, LONG* pHosePhysicalNumber,
	  							LONG* pPumpID, LONG* pPumpNumber, PBSTR  pPumpName,
								LONG* pTankID, LONG* pTankNumber, PBSTR  pTankName,
								LONG* pGradeID , LONG* pGradeNumber, PBSTR  pGradeName, PBSTR  pGradeShortName, PBSTR  pGradeCode,
							    short* pState ,short* pType ,double* pVolume ,short* pPriceLevel ,
		                        double* pPrice ,double* pValue ,double* pVolume2 , DATE* pCompletedDT ,LONG* pLockedBy, 
								LONG* pReservedBy , LONG* pAttendantID , LONG* pAge ,DATE* pClearedDT ,
								double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
								double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
								__int64* pTag , LONG * pDuration , LONG* pAttendantNumber , PBSTR pAttendantName, __int64* pAttendantTag ,
								LONG* pCardClientID , LONG* pCardClientNumber , PBSTR pCardClientName, __int64* pCardClientTag  , double* pPeakFlowRate ) ;
EZ_DLL_CALL GetDeliverySummaryEx4(LONG ID, LONG* pHoseID, LONG* pHoseNumber, LONG* pHosePhysicalNumber,
								LONG* pPumpID, LONG* pPumpNumber, PBSTR  pPumpName,
								LONG* pTankID, LONG* pTankNumber, PBSTR  pTankName,
								LONG* pGradeID, LONG* pGradeNumber, PBSTR  pGradeName, PBSTR  pGradeShortName, PBSTR  pGradeCode,
								short* pState, short* pType, double* pVolume, short* pPriceLevel,
								double* pPrice, double* pValue, double* pVolume2, DATE* pCompletedDT, LONG* pLockedBy,
								LONG* pReservedBy, LONG* pAttendantID, LONG* pAge, DATE* pClearedDT,
								double* pOldVolumeETot, double* pOldVolume2ETot, double* pOldValueETot,
								double* pNewVolumeETot, double* pNewVolume2ETot, double* pNewValueETot,
								__int64* pTag, LONG * pDuration, LONG* pAttendantNumber, PBSTR pAttendantName, __int64* pAttendantTag, PBSTR pAttendantIDNumber,
								LONG* pCardClientID, LONG* pCardClientNumber, PBSTR pCardClientName, __int64* pCardClientTag, PBSTR pCardClientIDNumber, double* pPeakFlowRate);
EZ_DLL_CALL LockDelivery( LONG ID ) ;
EZ_DLL_CALL UnlockDelivery( LONG ID ) ;
EZ_DLL_CALL ClearDelivery( LONG ID , short Type ) ;
EZ_DLL_CALL LockAndClearDelivery( LONG ID , short Type ) ;
EZ_DLL_CALL GetDuration( LONG ID , LONG* pDuration ) ;
EZ_DLL_CALL SetDeliveryExt( LONG ID , BSTR Plate , double Odometer , double Odometer2 , BSTR ExtTransactionID , BSTR DriverID , BSTR AuthID, short AuthType ) ;
EZ_DLL_CALL GetDeliveryExt( LONG ID , PBSTR pPlate , double* pOdometer , double* pOdometer2 , PBSTR pExtTransactionID , PBSTR pDriverID , PBSTR pAuthID, short* pAuthType ) ;
EZ_DLL_CALL GetGradesCount( LONG* pCount ) ;
EZ_DLL_CALL GetGradeByNumber( LONG Number , LONG* pID ) ;
EZ_DLL_CALL GetGradeByName( BSTR Name , LONG* pID ) ;
EZ_DLL_CALL GetGradeByOrdinal( LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetGradeProperties(LONG ID , LONG* pNumber, PBSTR pName , PBSTR pShortName , PBSTR pCode ) ;
EZ_DLL_CALL SetGradeProperties(LONG ID , LONG Number, BSTR Name , BSTR ShortName , BSTR Code  ) ;
EZ_DLL_CALL GetGradePropertiesEx(LONG ID , LONG* pNumber, PBSTR pName , PBSTR pShortName , PBSTR pCode , short* pType ) ;
EZ_DLL_CALL SetGradePropertiesEx(LONG ID , LONG Number, BSTR Name , BSTR ShortName , BSTR Code  , short Type ) ;
EZ_DLL_CALL AddGrade( LONG* pID, LONG* pNumber, BSTR Name , BSTR ShortName , BSTR Code  , short Type ) ;
EZ_DLL_CALL DeleteGrade( LONG ID ) ;
EZ_DLL_CALL SetGradePrice( LONG ID , short Level , double Price ) ;
EZ_DLL_CALL GetGradePrice( LONG ID , short Level , double* pPrice ) ;
EZ_DLL_CALL GetTanksCount( LONG* pCount ) ;
EZ_DLL_CALL GetTankByNumber( LONG Number , LONG* pID ) ;
EZ_DLL_CALL GetTankByName( BSTR Name , LONG* pID ) ;
EZ_DLL_CALL GetTankByOrdinal( LONG Index , LONG* pID ) ;



EZ_DLL_CALL GetTankProperties(LONG ID , LONG* pNumber, PBSTR pName , LONG* pGradeID , short* pType , double* pCapacity , double* pDiameter , 
							  double* pTheoVolume , double* pGaugeVolume , double* pGaugeTCVolume, double* pGaugeUllage, double* pGaugeTemperature , 
							  double* pGaugeLevel , double* pGaugeWaterVolume, double* pGaugeWaterLevel, LONG* pGaugeID, short* pProbeNo ) ;
EZ_DLL_CALL SetTankProperties(LONG ID , LONG Number, BSTR Name , LONG GradeID , short Type , double Capacity , double Diameter , double TheoVolume , 
		                      double GaugeVolume , double GaugeTCVolume ,double GaugeUllage ,double GaugeTemperature , double GaugeLevel , 
							  double GaugeWaterVolume, double GaugeWaterLevel, LONG GaugeID , short ProbeNo ) ;

EZ_DLL_CALL GetTankPropertiesEx(LONG ID , LONG* pNumber, PBSTR pName , LONG* pGradeID , short* pType , double* pCapacity , double* pDiameter , 
							  double* pTheoVolume , double* pGaugeVolume , double* pGaugeTCVolume, double* pGaugeUllage, double* pGaugeTemperature , 
							  double* pGaugeLevel , double* pGaugeWaterVolume, double* pGaugeWaterLevel, LONG* pGaugeID, short* pProbeNo , LONG* pGaugeAlarmsMask ) ;
EZ_DLL_CALL SetTankPropertiesEx(LONG ID , LONG Number, BSTR Name , LONG GradeID , short Type , double Capacity , double Diameter , double TheoVolume , 
		                      double GaugeVolume , double GaugeTCVolume ,double GaugeUllage ,double GaugeTemperature , double GaugeLevel , 
							  double GaugeWaterVolume, double GaugeWaterLevel, LONG GaugeID , short ProbeNo , LONG GaugeAlarmsMask ) ;

EZ_DLL_CALL GetTankPropertiesEx2(LONG ID , LONG* pNumber, PBSTR pName , LONG* pGradeID , short* pType , double* pCapacity , double* pDiameter , 
							  double* pTheoVolume , double* pGaugeVolume , double* pGaugeTCVolume, double* pGaugeUllage, double* pGaugeTemperature , 
							  double* pGaugeLevel , double* pGaugeWaterVolume, double* pGaugeWaterLevel, LONG* pGaugeID, short* pProbeNo , 
							  LONG* pGaugeAlarmsMask , LONG* pSlotZigBeeID , short* pProbeType , LONG* pProbeSerialNo) ;

EZ_DLL_CALL SetTankPropertiesEx2( LONG ID , LONG Number, BSTR Name , LONG GradeID , short Type , double Capacity , double Diameter , double TheoVolume , 
		                      double GaugeVolume , double GaugeTCVolume ,double GaugeUllage ,double GaugeTemperature , double GaugeLevel , 
							  double GaugeWaterVolume, double GaugeWaterLevel, LONG GaugeID , short ProbeNo , LONG GaugeAlarmsMask , 
							  LONG SlotZigBeeID , short ProbeType , LONG ProbeSerialNo ) ;  


EZ_DLL_CALL GetTankSummary(LONG ID , LONG* pNumber, PBSTR pName , LONG* pGradeID , 
						   LONG* pGradeNumber, PBSTR pGradeName, PBSTR pGradeShortName, PBSTR pGradeCode, 
						   short* pType , double* pCapacity , double* pDiameter , 
						   double* pTheoVolume , double* pGaugeVolume , double* pGaugeTCVolume, double* pGaugeUllage, double* pGaugeTemperature , 
						   double* pGaugeLevel , double* pGaugeWaterVolume, double* pGaugeWaterLevel, LONG* pGaugeID, short* pProbeNo ) ;

EZ_DLL_CALL GetTankSummaryEx(LONG ID , LONG* pNumber, PBSTR pName , LONG* pGradeID , 
						   LONG* pGradeNumber, PBSTR pGradeName, PBSTR pGradeShortName, PBSTR pGradeCode, 
						   short* pType , double* pCapacity , double* pDiameter , 
						   double* pTheoVolume , double* pGaugeVolume , double* pGaugeTCVolume, double* pGaugeUllage, double* pGaugeTemperature , 
						   double* pGaugeLevel , double* pGaugeWaterVolume, double* pGaugeWaterLevel, LONG* pGaugeID, short* pProbeNo , 
						   short* pState , LONG* pGaugeAlarmsMask ) ;

EZ_DLL_CALL GetTankSummaryEx2(LONG ID , LONG* pNumber, PBSTR pName , LONG* pGradeID , 
						   LONG* pGradeNumber, PBSTR pGradeName, PBSTR pGradeShortName, PBSTR pGradeCode, 
						   short* pType , double* pCapacity , double* pDiameter , 
						   double* pTheoVolume , double* pGaugeVolume , double* pGaugeTCVolume, double* pGaugeUllage, double* pGaugeTemperature , 
						   double* pGaugeLevel , double* pGaugeWaterVolume, double* pGaugeWaterLevel, LONG* pGaugeID, short* pProbeNo , 
						   short* pState , LONG* pGaugeAlarmsMask , LONG* pSlotZigBeeID , short* pProbeType , LONG* pProbeSerialNo ) ;

EZ_DLL_CALL TankDrop( LONG ID , double Volume , DATE DropDT , BSTR Terminal , BSTR DocumentType , DATE DocumentDT  , BSTR DocumentFolio , double PEMEXVolume ) ;
EZ_DLL_CALL AddTank( LONG* pID, LONG* pNumber, BSTR Name , LONG GradeID , short Type , double Capacity , double Diameter , double TheoVolume , 
		                      double GaugeVolume , double GaugeTCVolume ,double GaugeUllage ,double GaugeTemperature , double GaugeLevel , 
							  double GaugeWaterVolume, double GaugeWaterLevel, LONG PortID , short ProbeNo , LONG GaugeAlarmsMask , LONG SlotZigBeeID , short ProbeType , LONG ProbeSerialNo ) ;
EZ_DLL_CALL DeleteTank( LONG ID ) ;
EZ_DLL_CALL GetPortsCount( LONG* pCount ) ;
EZ_DLL_CALL GetPortByNumber( LONG Number , LONG* pID ) ;
EZ_DLL_CALL GetPortByName( BSTR Name , LONG* pID ) ;
EZ_DLL_CALL GetPortByOrdinal( LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetPortProperties(LONG ID , LONG* pNumber, PBSTR pName , LONG* pProtocolID , short* pDeviceType , PBSTR pSerialNo ) ;
EZ_DLL_CALL SetPortProperties(LONG ID , LONG Number, BSTR Name, LONG ProtocolID , short DeviceType , BSTR SerialNo ) ;
EZ_DLL_CALL GetAttendantsCount( LONG* pCount ) ;
EZ_DLL_CALL GetAttendantByNumber( LONG Number , LONG* pID ) ;
EZ_DLL_CALL GetAttendantByName( BSTR Name , LONG* pID ) ;
EZ_DLL_CALL GetAttendantByOrdinal( LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetAttendantProperties(LONG ID , LONG* pNumber, PBSTR pName , PBSTR pShortName , PBSTR pPassword , PBSTR pTag ) ; 
EZ_DLL_CALL SetAttendantProperties(LONG ID , LONG Number, BSTR Name , BSTR ShortName , BSTR Password , BSTR Tag ) ; 
EZ_DLL_CALL GetAttendantPropertiesEx(LONG ID , LONG* pNumber, PBSTR pName , PBSTR pShortName , PBSTR pPassword , PBSTR pTag , short* pShiftAStart , short* pShiftAEnd , short* pShiftBStart , short* pShiftBEnd , short* pType )  ;
EZ_DLL_CALL SetAttendantPropertiesEx(LONG ID , LONG Number, BSTR Name , BSTR ShortName , BSTR Password , BSTR Tag,short ShiftAStart , short ShiftAEnd , short ShiftBStart , short ShiftBEnd , short Type )  ;
EZ_DLL_CALL GetAttendantPropertiesEx2(LONG ID, LONG* pNumber, PBSTR pName, PBSTR pShortName, PBSTR pPassword, PBSTR pTag, PBSTR pIDNumber,short* pShiftAStart, short* pShiftAEnd, short* pShiftBStart, short* pShiftBEnd, short* pType);
EZ_DLL_CALL SetAttendantPropertiesEx2(LONG ID, LONG Number, BSTR Name, BSTR ShortName, BSTR Password, BSTR Tag, BSTR IDNumber,short ShiftAStart, short ShiftAEnd, short ShiftBStart, short ShiftBEnd, short Type);
EZ_DLL_CALL AddAttendant( LONG* pID, LONG* pNumber, BSTR Name, BSTR ShortName, BSTR Password, BSTR Tag, BSTR IDNumber, short ShiftAStart, short ShiftAEnd, short ShiftBStart, short ShiftBEnd, short Type);

EZ_DLL_CALL GetAttendantState( LONG ID , short* pType , short* pLoggedOn ) ;

EZ_DLL_CALL DeleteAttendant( LONG ID ) ;
EZ_DLL_CALL AttendantLogon( LONG ID , LONG PumpID ) ;
EZ_DLL_CALL AttendantLogoff( LONG ID ) ;

EZ_DLL_CALL GetCardReadsCount( LONG* pCount ) ;
EZ_DLL_CALL GetCardReadByNumber( LONG Number , LONG* pID ) ;
EZ_DLL_CALL GetCardReadByName( BSTR Name , LONG* pID ) ;
EZ_DLL_CALL GetCardReadByOrdinal( LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetCardReadProperties(LONG ID , LONG* pNumber, PBSTR pName , LONG* pPumpID , short* pType , LONG* pParentID , __int64* pTag , DATE* pTimeStamp )  ;
EZ_DLL_CALL SetCardReadProperties(LONG ID , LONG Number, BSTR Name , LONG PumpID , short Type , LONG ParentID , __int64 Tag , DATE TimeStamp)  ;
EZ_DLL_CALL DeleteCardRead( LONG ID ) ;

EZ_DLL_CALL GetCardClientsCount( LONG* pCount ) ;
EZ_DLL_CALL GetCardClientByNumber( LONG Number , LONG* pID ) ;
EZ_DLL_CALL GetCardClientByName( BSTR Name , LONG* pID ) ;
EZ_DLL_CALL GetCardClientByOrdinal( LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetCardClientProperties(LONG ID , LONG* pNumber, PBSTR pName , PBSTR pTag , short* pEnabled )  ;
EZ_DLL_CALL SetCardClientProperties(LONG ID , LONG Number, BSTR Name , BSTR Tag , short Enabled )  ;
EZ_DLL_CALL GetCardClientPropertiesEx(LONG ID , LONG* pNumber, PBSTR pName , PBSTR pTag , short* pEnabled , short* pPriceLevel, PBSTR pPlate  )  ;
EZ_DLL_CALL SetCardClientPropertiesEx(LONG ID , LONG Number, BSTR Name , BSTR Tag , short Enabled , short PriceLevel , BSTR Plate ) ;
EZ_DLL_CALL SetCardClientPropertiesEx2(LONG ID , LONG Number, BSTR Name , BSTR Tag , short Enabled , short PriceLevel , BSTR Plate , short GradeType, short CardType, short LimitType, double Limit, short EntryType, DATE ExpirationDate, LONG ParentID )  ;
EZ_DLL_CALL GetCardClientPropertiesEx2(LONG ID , LONG* pNumber, PBSTR pName , PBSTR pTag , short* pEnabled , short* pPriceLevel , PBSTR pPlate , short* pGradeType, short* pCardType, short* pLimitType, double* pLimit, short* pEntryType, DATE* pExpirationDate, LONG* pParentID )  ;
EZ_DLL_CALL GetCardClientPropertiesEx3(LONG ID, LONG* pNumber, PBSTR pName, PBSTR pTag, short* pEnabled, short* pPriceLevel, PBSTR pPlate, PBSTR pIDNumber, PBSTR pShortName, PBSTR pPassword, short* pGradeType, short* pCardType, short* pLimitType, double* pLimit, short* pEntryType, DATE* pExpirationDate, LONG* pParentID);
EZ_DLL_CALL SetCardClientPropertiesEx3(LONG ID, LONG Number, BSTR Name, BSTR Tag, short Enabled, short PriceLevel, BSTR Plate, BSTR IDNumber, BSTR ShortName, BSTR Password, short GradeType, short CardType, short LimitType, double Limit, short EntryType, DATE ExpirationDate, LONG ParentID);
EZ_DLL_CALL GetCardClientPropertiesEx4(LONG ID, LONG* pNumber, PBSTR pName, PBSTR pTag, short* pEnabled, short* pPriceLevel, PBSTR pPlate, PBSTR pIDNumber, PBSTR pShortName, PBSTR pPassword, short* pGradeType, short* pCardType, short* pLimitType, double* pLimit, short* pEntryType, DATE* pExpirationDate, LONG* pParentID, PBSTR pEZOdoSerialNo, double* pOdometer, LONG* pFactor );
EZ_DLL_CALL SetCardClientPropertiesEx4(LONG ID, LONG Number, BSTR Name, BSTR Tag, short Enabled, short PriceLevel, BSTR Plate, BSTR IDNumber, BSTR ShortName, BSTR Password, short GradeType, short CardType, short LimitType, double Limit, short EntryType, DATE ExpirationDate, LONG ParentID, BSTR EZOdoSerialNo, double Odometer, LONG Factor);
EZ_DLL_CALL AddCardClient(LONG* pID, LONG* pNumber, BSTR Name, BSTR Tag, short Enabled, short PriceLevel, BSTR Plate, BSTR IDNumber, BSTR ShortName, BSTR Password, short GradeType, short CardType, short LimitType, double Limit, short EntryType, DATE ExpirationDate, LONG ParentID, BSTR EZOdoSerialNo, double Odometer, LONG Factor);

EZ_DLL_CALL DeleteCardClient( LONG ID ) ;
EZ_DLL_CALL ScheduleBeep( LONG ID , short Pitch1 , short Duration1 , short Pitch2 , short Duration2, short Pitch3 , short Duration3, short Pitch4 , short Duration4, short Pitch5 , short Duration5  ) ;
EZ_DLL_CALL FlashLEDS( LONG ID , short PeriodMs , short Cycles )  ;
EZ_DLL_CALL EZTermPrompt( LONG ID , short PromptType , short PromptID , short Priority , short Font , short DisplayPars ,  short EnabledKeys , short MinimumDigits , short MaximumDigits , short Timeout , short X , short Y , short Intensity , BSTR Text ) ; 


EZ_DLL_CALL AllStop() ;
EZ_DLL_CALL AllAuthorise() ;
EZ_DLL_CALL AllReAuthorise() ;
EZ_DLL_CALL AllStopIfIdle() ;
EZ_DLL_CALL ReadAllTanks() ;
EZ_DLL_CALL GetAllPumpStatuses( PBSTR pStates , PBSTR pCurrentHoses , PBSTR pDeliveriesCount ) ; 
EZ_DLL_CALL GetAllStatuses( LONG Level , LONG Start , LONG End , LONG ObjID , PBSTR pStatuses ) ;
EZ_DLL_CALL AddLogEvent( LONG* pID, short DeviceType, LONG DeviceID, short EventLevel, short EventType, BSTR  EventDesc, double Volume, double Value, double ProductVolume, double ProductLevel, double WaterLevel, double Temperature, DATE GenDT );
EZ_DLL_CALL GetIniValue( BSTR Section , BSTR Key , PBSTR pValue ) ;
EZ_DLL_CALL SetIniValue( BSTR Section , BSTR Key , BSTR Value ) ; 
EZ_DLL_CALL GetIniValueEx( BSTR FileName , BSTR Section , BSTR Key , PBSTR pValue ) ; 
EZ_DLL_CALL SetIniValueEx( BSTR FileName , BSTR Section , BSTR Key , BSTR Value ) ; 
EZ_DLL_CALL SetNextDeliveryID( LONG ID ) ;
EZ_DLL_CALL GetCardType( BSTR Tag , short* pTagType , LONG* pID, PBSTR pName, LONG* pNumber  ) ;
EZ_DLL_CALL FindCard(BSTR Tag, short* pCardType, short* pTagType, LONG* pID, PBSTR pName, LONG* pNumber);
EZ_DLL_CALL AddPort(LONG* pID, LONG* pNumber, BSTR Name, LONG ProtocolID , short DeviceType , BSTR SerialNo );
EZ_DLL_CALL RemovePort( LONG ID ) ;
EZ_DLL_CALL LicenseStatus() ;
EZ_DLL_CALL CheckSocketClosed( LPARAM lParam ) ;


EZ_DLL_CALL GetNextPumpEventEx( LONG* pPumpID, short* pPumpNumber, short* pState, short* pReservedFor, LONG* pReservedBy, LONG* pHoseID ,
							    short* pHoseNumber,LONG* pGradeID, PBSTR pGradeName , PBSTR pShortGradeName, short* pPriceLevel , double* pPrice, double* pVolume, 
							    double* pValue, short* pStackSize , PBSTR pPumpName , short* pPhysicalNumber , short* pSide , short* pAddress, 
								short* pPriceLevel1 , short* pPriceLevel2 , short* pType , LONG* pPortID , short* pAuthMode , short* pStackMode ,  short* pPrepayAllowed, 
								short* pPreauthAllowed ,  short* pPriceFormat , short* pValueFormat , short* pVolumeFormat  ) ;

EZ_DLL_CALL GetNextPumpEventEx2( LONG* pPumpID, LONG* pPumpNumber, short* pState, short* pReservedFor, LONG* pReservedBy, LONG* pHoseID ,
							    LONG* pHoseNumber,LONG* pHosePhysicalNumber,LONG* pGradeID,LONG* pGradeNumber, PBSTR pGradeName , PBSTR pShortGradeName, short* pPriceLevel , double* pPrice, double* pVolume, 
							    double* pValue, short* pStackSize , PBSTR pPumpName , LONG* pPhysicalNumber , short* pSide , short* pAddress, 
								short* pPriceLevel1 , short* pPriceLevel2 , short* pType , LONG* pPortID , short* pAuthMode , short* pStackMode ,  short* pPrepayAllowed, 
								short* pPreauthAllowed ,  short* pPriceFormat , short* pValueFormat , short* pVolumeFormat , __int64* pTag , 
							    LONG* pAttendantID , LONG* pAttendantNumber , PBSTR pAttendantName, __int64* pAttendantTag ,
							    LONG* pCardClientID , LONG* pCardClientNumber , PBSTR pCardClientName, __int64* pCardClientTag  ) ;
EZ_DLL_CALL GetNextPumpEventEx3( LONG* pPumpID, LONG* pPumpNumber, short* pState, short* pReservedFor, LONG* pReservedBy, LONG* pHoseID ,
							    LONG* pHoseNumber,LONG* pHosePhysicalNumber,LONG* pGradeID,LONG* pGradeNumber, PBSTR pGradeName , PBSTR pShortGradeName, short* pPriceLevel , double* pPrice, double* pVolume, 
							    double* pValue, short* pStackSize , PBSTR pPumpName , LONG* pPhysicalNumber , short* pSide , short* pAddress, 
								short* pPriceLevel1 , short* pPriceLevel2 , short* pType , LONG* pPortID , short* pAuthMode , short* pStackMode ,  short* pPrepayAllowed, 
								short* pPreauthAllowed ,  short* pPriceFormat , short* pValueFormat , short* pVolumeFormat , __int64* pTag , 
							    LONG* pAttendantID , LONG* pAttendantNumber , PBSTR pAttendantName, __int64* pAttendantTag ,
							    LONG* pCardClientID , LONG* pCardClientNumber , PBSTR pCardClientName, __int64* pCardClientTag , 
								double* pCurFlowRate , double* pPeakFlowRate ) ;

EZ_DLL_CALL GetNextDeliveryEventEx( LONG* pDeliveryID , LONG* pPumpID, short* pPumpNumber, LONG* pHoseID, short* pHoseNumber , 
								    LONG* pGradeID, PBSTR pGradeName , PBSTR pShortGradeName, short* pPriceLevel, double* pPrice, 
									double* pVolume, double* pValue, short* pDeliveryState , 
								    short* pDeliveryType, LONG* pLockedBy, LONG* pReservedBy, LONG* pAge , DATE* pCompletedDT , 
									LONG* pAttendantID, double* pVolumeETot , double* pVolume2ETot , double* pValueETot , __int64* pTag) ;
EZ_DLL_CALL  GetNextDeliveryEventEx2( LONG* pDeliveryID , LONG* pPumpID, short* pPumpNumber, LONG* pHoseID, short* pHoseNumber , 
								     LONG* pGradeID, PBSTR pGradeName , PBSTR pShortGradeName, short* pPriceLevel, double* pPrice, 
									 double* pVolume, double* pValue, short* pDeliveryState , 
								     short* pDeliveryType, LONG* pLockedBy, LONG* pReservedBy, LONG* pAge , DATE* pCompletedDT , 
									 LONG* pAttendantID, 
									 double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
									 double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
									 __int64* pTag , LONG* pDuration ) ;
EZ_DLL_CALL  GetNextDeliveryEventEx3( LONG* pDeliveryID, 
									    LONG* pHoseID ,LONG* pHoseNumber, LONG* pHosePhysicalNumber,
	  									LONG* pPumpID, LONG* pPumpNumber, PBSTR pPumpName,
										LONG* pTankID, LONG* pTankNumber, PBSTR pTankName,
										LONG* pGradeID , LONG* pGradeNumber, PBSTR pGradeName, PBSTR pGradeShortName, PBSTR pGradeCode,
										short* pState ,short* pType ,double* pVolume ,short* pPriceLevel ,
										double* pPrice ,double* pValue ,double* pVolume2 , DATE* pCompletedDT , LONG* pLockedBy, 
										LONG* pReservedBy , LONG* pAttendantID , LONG* pAge , DATE* pClearedDT , 
										double* pOldVolumeETot, double* pOldVolume2ETot, double* pOldValueETot , 
										double* pNewVolumeETot, double* pNewVolume2ETot, double* pNewValueETot , 
										__int64* pTag , LONG* pDuration , LONG* pAttendantNumber , PBSTR AttendantName, __int64* pAttendantTag ,
										LONG* pCardClientID , LONG* pCardClientNumber , PBSTR CardClientName, __int64* pCardClientTag ) ; 
EZ_DLL_CALL  GetNextDeliveryEventEx4( LONG* pDeliveryID, LONG* pHoseID ,LONG* pHoseNumber, LONG* pHosePhysicalNumber,
	  									LONG* pPumpID, LONG* pPumpNumber, PBSTR pPumpName,
										LONG* pTankID, LONG* pTankNumber, PBSTR pTankName,
										LONG* pGradeID , LONG* pGradeNumber, PBSTR pGradeName, PBSTR pGradeShortName, PBSTR pGradeCode,
										short* pState ,short* pType ,double* pVolume ,short* pPriceLevel ,
										double* pPrice ,double* pValue ,double* pVolume2 , DATE* pCompletedDT , LONG* pLockedBy, 
										LONG* pReservedBy , LONG* pAttendantID , LONG* pAge , DATE* pClearedDT , 
										double* pOldVolumeETot, double* pOldVolume2ETot, double* pOldValueETot , 
										double* pNewVolumeETot, double* pNewVolume2ETot, double* pNewValueETot , 
										__int64* pTag , LONG* pDuration , LONG* pAttendantNumber , PBSTR AttendantName, __int64* pAttendantTag ,
										LONG* pCardClientID , LONG* pCardClientNumber , PBSTR CardClientName, __int64* pCardClientTag , double* pPeakFlowRate) ;

EZ_DLL_CALL GetNextCardReadEvent( LONG* pCardReadID , LONG* pNumber, PBSTR pName , LONG* pPumpID , short* pType , LONG* pParentID , __int64* pTag , DATE* pTimeStamp) ;
EZ_DLL_CALL GetNextDBHoseETotalsEventEx( LONG* pHoseID , double* pVolume , double* pValue , double* pVolumeETot , double* pValueETot , 
										 LONG* pHoseNumber , LONG* pHosePhysicalNumber , LONG* pPumpID , LONG* pPumpNumber , PBSTR pPumpName , 
										 LONG* pTankID , LONG* pTankNumber , PBSTR pTankName , LONG* pGradeID , PBSTR pGradeName ) ;
EZ_DLL_CALL GetNextDBTankStatusEventEx( LONG* pTankID , double* pGaugeVolume , double* pGaugeTCVolume, double* pGaugeUllage, 
									    double* pGaugeTemperature , double* pGaugeLevel , double* pGaugeWaterVolume, double* pGaugeWaterLevel , 
									    LONG* pTankNumber , PBSTR pTankName , LONG* pGradeID , PBSTR pGradeName , short*pType  , 
										double* pCapacity , double* pDiameter , LONG* pGaugeID , short* pProbeNo) ;
EZ_DLL_CALL GetNextDBTankStatusEventEx2( LONG* pTankID , double* pGaugeVolume , double* pGaugeTCVolume, double* pGaugeUllage, 
									    double* pGaugeTemperature , double* pGaugeLevel , double* pGaugeWaterVolume, double* pGaugeWaterLevel , 
									    LONG* pTankNumber , PBSTR pTankName , LONG* pGradeID , PBSTR pGradeName , short*pType  , double* pCapacity , 
										double* pDiameter , LONG* pGaugeID , short* pProbeNo , short* pState , LONG* pAlarmsMask ) ;
EZ_DLL_CALL GetNextZBEvent( LONG* pPortID , LONG* pZBID , __int64* pZBAddress, short* pResult , short* pMsgType , PBSTR pRxMsg ) ; 
EZ_DLL_CALL GetZigBeeCount( LONG* pCount ) ;
EZ_DLL_CALL GetZigBeeByNumber( LONG Number , LONG* pID ) ;
EZ_DLL_CALL GetZigBeeByName( BSTR Name , LONG* pID ) ;
EZ_DLL_CALL GetZigBeeByOrdinal( LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetZigBeeProperties(LONG ID , LONG* pNumber, PBSTR pName , short* pDeviceType , PBSTR pSerialNumber , PBSTR pNodeIdentifier , LONG* pPortID ) ;
EZ_DLL_CALL SetZigBeeProperties(LONG ID , LONG Number, BSTR Name , short DeviceType , BSTR SerialNumber , BSTR NodeIdentifier , LONG PortID ) ;
EZ_DLL_CALL AddZigBee(LONG* pID, LONG* pNumber, BSTR Name , short DeviceType , BSTR SerialNumber , BSTR NodeIdentifier , LONG PortID ) ;

EZ_DLL_CALL DeleteZigBee( LONG ID ) ;

EZ_DLL_CALL GetHosePropertiesEx(LONG ID , LONG* pNumber, LONG* pPumpID ,LONG* pTankID , LONG* pPhysicalNumber, 
		                      double* pMtrTheoValue , double* pMtrTheoVolume ,double* pMtrElecValue ,
				              double* pMtrElecVolume , short* pUVEAntenna ) ;
EZ_DLL_CALL SetHosePropertiesEx(LONG ID , LONG Number,LONG PumpID, LONG TankID , LONG PhysicalNumber, 
		                      double MtrTheoValue , double MtrTheoVolume ,double MtrElecValue ,
				              double MtrElecVolume , short UVEAntenna );
EZ_DLL_CALL GetHosePropertiesEx2(LONG ID , LONG* pNumber, LONG* pPumpID ,LONG* pTankID , LONG* pPhysicalNumber, 
		                      double* pMtrTheoValue , double* pMtrTheoVolume ,double* pMtrElecValue ,
				              double* pMtrElecVolume , short* pUVEAntenna , double* pPrice1 , double* pPrice2 , short* pEnabled ) ;

EZ_DLL_CALL GetHosePropertiesEx3(LONG ID , LONG* pNumber, LONG* pPumpID ,LONG* pTankID , LONG* pPhysicalNumber, 
		                      double* pMtrTheoValue , double* pMtrTheoVolume ,double* pMtrElecValue ,
				              double* pMtrElecVolume , short* pUVEAntenna , double* pPrice1 , double* pPrice2 , double* pPrice3 , double* pPrice4 , short* pEnabled ) ;


EZ_DLL_CALL SetHosePropertiesEx2(LONG ID , LONG Number,LONG PumpID, LONG TankID , LONG PhysicalNumber, 
		                      double MtrTheoValue , double MtrTheoVolume ,double MtrElecValue ,
				              double MtrElecVolume , short UVEAntenna , double Price1 , double Price2 , short Enabled ) ;
EZ_DLL_CALL SetHosePropertiesEx3(LONG ID , LONG Number,LONG PumpID, LONG TankID , LONG PhysicalNumber, 
		                      double MtrTheoValue , double MtrTheoVolume ,double MtrElecValue ,
				              double MtrElecVolume , short UVEAntenna , double Price1 , double Price2 , double Price3 , double Price4 , short Enabled );
EZ_DLL_CALL SetPumpPropertiesEx(LONG ID , LONG Number, BSTR Name, short PhysicalNumber, short Side, short Address, short PriceLevel1,
						        short PriceLevel2, short PriceDspFormat, short VolumeDspFormat, short ValueDspFormat, short Type, 
						        LONG PortID, LONG AttendantID, short AuthMode, short StackMode, short PrepayAllowed, short PreauthAllowed , 
								LONG SlotZigBeeID , LONG MuxSlotZigBeeID , short PriceControl , short HasPreset ) ;
EZ_DLL_CALL GetPumpPropertiesEx(LONG ID , LONG* pNumber, PBSTR pName, short* pPhysicalNumber, short* pSide, short* pAddress, short* pPriceLevel1,
						      short* pPriceLevel2, short* pPriceDspFormat, short* pVolumeDspFormat, short* pValueDspFormat, short* pType, 
						      LONG* pPortID, LONG* pAttendantID, short* pAuthMode, short* pStackMode, short* pPrepayAllowed, short* pPreauthAllowed ,
							  LONG* pSlotZigBeeID , LONG* pMuxSlotZigBeeID , short* pPriceControl , short* pHasPreset) ;
EZ_DLL_CALL GetSerialNo( LONG ID , PBSTR pSerialNo ) ; 
EZ_DLL_CALL GetDeviceDetails( LONG ID , LONG ZBID , PBSTR pSerialNo , PBSTR pBootVersion , PBSTR pFirmwareVersion ) ;
EZ_DLL_CALL ResetDevice( LONG ID , LONG ZBID ) ;
EZ_DLL_CALL RequestVersion( LONG ID , LONG ZBID ) ;
EZ_DLL_CALL SetZBCoordPan( LONG ID , __int64 Pan ) ;
EZ_DLL_CALL GetZBCoordPan( LONG ID ) ;
EZ_DLL_CALL SetHoseETotals( LONG ID , double Volume , double Value ) ;
EZ_DLL_CALL GetNextZBPanIDEvent( LONG* pPortID , __int64* pZBPanID ) ;
EZ_DLL_CALL GetNextZeroDeliveryEvent( LONG* pPumpID , LONG* pPumpNumber , LONG* pHoseID , LONG* pHoseNumber ) ;
EZ_DLL_CALL SetLineMode( LONG ID , LONG ZBID , short Mode ) ;
EZ_DLL_CALL SetHosePrices( LONG ID , short DurationType , short PriceType , double Price1 , double Price2 ) ;
EZ_DLL_CALL SetHosePricesEx( LONG ID , short DurationType , short PriceType , double Price1 , double Price2 , double Price3 , double Price4) ;
EZ_DLL_CALL GetHosePrices( LONG ID , short* pDurationType , short* pPriceType , double* pPrice1 , double* pPrice2 ) ;
EZ_DLL_CALL GetHosePricesEx( LONG ID , short* pDurationType , short* pPriceType , double* pPrice1 , double* pPrice2 , double* pPrice3 , double* pPrice4 ) ;

EZ_DLL_CALL SetPumpDefaultPriceLevel( LONG ID , short Level ) ;
EZ_DLL_CALL SetDateTime( DATE DateTime ) ;
EZ_DLL_CALL GetDateTime( DATE* pDateTime ) ;
EZ_DLL_CALL GetNextZB2GStatusEvent( LONG* pPortID , __int64* pZBAddress, short* pLQI , short* pRSSI , __int64*  pParZBAddress, short* pZBChannel , short* pMemBlocks , short* pMemFree , short* pDeviceType ) ;
EZ_DLL_CALL GetZB2GConfig( LONG ID , __int64* pPanID , LONG* pChannels , __int64* pKeyA , __int64* pKeyB ) ;

// not valid for CE 
EZ_DLL_CALL IsValidMACLicense( BSTR LicenseKey ) ;			

EZ_DLL_CALL GetLogEventCount( LONG* pCount , short DeviceType , LONG DeviceID , short EventLevel , short EventType , LONG ClearedBy, LONG  AckedBy ) ;
EZ_DLL_CALL GetLogEventByOrdinal( LONG Index , LONG* pID , short DeviceType , LONG DeviceID , short EventLevel , short EventType ,LONG  ClearedBy, LONG  AckedBy ) ;

EZ_DLL_CALL GetLogEventCountEx(LONG* pCount, short DeviceType, LONG DeviceID, short EventLevel, short EventType, LONG ClearedBy, LONG  AckedBy, DATE StartDT, DATE EndDT);
EZ_DLL_CALL GetLogEventByOrdinalEx(LONG Index, LONG* pID, short DeviceType, LONG DeviceID, short EventLevel, short EventType, LONG  ClearedBy, LONG  AckedBy, DATE StartDT, DATE EndDT);

EZ_DLL_CALL GetLogEventProperties( LONG ID , short* pDeviceType , LONG* pDeviceID , LONG* pDeviceNumber ,	PBSTR pDeviceName , short* pEventLevel ,
								   short* pEventType , PBSTR pEventDesc , DATE* pGeneratedDT , DATE* pClearedDT , LONG* pClearedBy , LONG* pAckedBy , double* pVolume ,
								   double* pValue , double* pProductVolume , double* pProductLevel , double* pWaterLevel , double* pTemperature  );
EZ_DLL_CALL SetLogEventProperties(LONG ID , short DeviceType , LONG DeviceID , LONG DeviceNumber , BSTR DeviceName , short EventLevel ,
									short EventType , BSTR  EventDesc , DATE GeneratedDT , DATE ClearedDT , LONG  ClearedBy , LONG AckedBy , double  Volume ,
									double  Value , double  ProductVolume ,	double  ProductLevel , double  WaterLevel , double  Temperature );
EZ_DLL_CALL DeleteLogEvent( LONG ID ) ;
EZ_DLL_CALL GetNextLogEventEvent( LONG* pLogEventID , short* pDeviceType , LONG* pDeviceID , LONG* pDeviceNumber ,	PBSTR pDeviceName , short* pEventLevel ,
								     short* pEventType , PBSTR pEventDesc , DATE* pGeneratedDT , DATE* pClearedDT , LONG* pClearedBy , LONG* pAckedBy , double* pVolume ,
								     double* pValue , double* pProductVolume , double* pProductLevel , double* pWaterLevel , double* pTemperature) ;

EZ_DLL_CALL ClearLogEvent( LONG ID  , LONG ClientID ) ;
EZ_DLL_CALL AckLogEvent( LONG ID  , LONG ClientID ) ;

EZ_DLL_CALL GetSensorsCount( LONG* pCount ) ;
EZ_DLL_CALL GetSensorByNumber( LONG Number , LONG* pID ) ;
EZ_DLL_CALL GetSensorByName( BSTR Name , LONG* pID ) ;
EZ_DLL_CALL GetSensorByOrdinal( LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetSensorProperties(LONG ID , LONG* pNumber, PBSTR pName , LONG* pPortID , short* pType , short* pAddress , short* pSensorNo ) ;
EZ_DLL_CALL SetSensorProperties(LONG ID , LONG Number, BSTR Name , LONG PortID , short Type, short Address , short SensorNo ) ;
EZ_DLL_CALL GetSensorPropertiesEx(LONG ID , LONG* pNumber, PBSTR pName , LONG* pPortID , short* pType , short* pAddress , short* pSensorNo , LONG* pSlotZigBeeID , LONG* pSensorSerialNo) ;
EZ_DLL_CALL SetSensorPropertiesEx(LONG ID , LONG Number, BSTR Name , LONG PortID , short Type, short Address , short SensorNo , LONG SlotZigBeeID , LONG SensorSerialNo) ;
EZ_DLL_CALL SetSensorStatus(LONG ID , short State , short IsResponding ) ;
EZ_DLL_CALL GetSensorStatus(LONG ID , short* pState , short* pIsResponding ) ;
EZ_DLL_CALL AddSensor(LONG* pID, LONG* pNumber, BSTR Name , LONG PortID , short Type, short Address , short SensorNo , LONG SlotZigBeeID , LONG SensorSerialNo ) ;
EZ_DLL_CALL DeleteSensor( LONG ID ) ;

EZ_DLL_CALL SetLogPath(BSTR Path);
EZ_DLL_CALL Log(BSTR Text);
EZ_DLL_CALL SetClientType( LONG ClientKey ) ; 

EZ_DLL_CALL GetNextSaleItemEvent(LONG* pSaleItemID, LONG* pProductID, LONG* pProductNumber, PBSTR pProductName, __int64* pProductTag, LONG* pProductGroup, PBSTR pProductGroupName, PBSTR pBarcode,
								 LONG* pPumpID, LONG* pPumpNumber, PBSTR pPumpName,
								 LONG* pAttendantID, LONG* pAttendantNumber, PBSTR pAttendantName, __int64* pAttendantTag,
								 LONG* pCardClientID, LONG* pCardClientNumber, PBSTR pCardClientName, __int64* pCardClientTag,
								 short* pPriceLevel, double* pPrice, double* pQuantity, DATE* pAddedDT, DATE* pClearedDT,
								 LONG* pLockedBy, LONG* pClearedBy, short* pLoggedDB, short* pLoggedVolumetric,
								 PBSTR pPlate, PBSTR pDriverID, PBSTR pExtTransactionID, PBSTR pAuthID, short* pAuthType);

EZ_DLL_CALL GetNextEZOdoEvent(LONG* pPortID , __int64* pZBAddress, short* pLQI , short* pRSSI , __int64* pParZBAddress , short* pZBChannel , short* pMemBlocks , short* pMemFree , short* pDeviceType,
  							  LONG* pClientID , PBSTR pClientName , __int64* pClientTag , 
							  __int64* pOdo1, LONG* pFactor1, short* pLevel1, 
							  __int64* pOdo2, LONG* pFactor2, short* pLevel2, 
							  __int64* pTag1, __int64* pTag2, __int64* pTag3, __int64* pTag4, short* pFuelTypes, PBSTR pPlate);

EZ_DLL_CALL GetNextEZTermPromptEvent( LONG* pPumpID , short* pPromptID , short* pPromptResult , PBSTR pInput ) ; 


EZ_DLL_CALL GetProductByNumber(LONG Number, LONG* pID);
EZ_DLL_CALL GetProductByName(BSTR Name, LONG* pID);
EZ_DLL_CALL GetProductProperties(LONG ID, LONG* pNumber, PBSTR pName, PBSTR pTag, short* pEnabled, PBSTR pShortName, PBSTR pBarcode, double* pPrice1, double* pPrice2, LONG* pProductGroup);
EZ_DLL_CALL SetProductProperties(LONG ID, LONG Number, BSTR Name, BSTR Tag, short Enabled, BSTR ShortName, BSTR Barcode, double Price1, double Price2, LONG ProductGroup);
EZ_DLL_CALL GetProductPropertiesEx(LONG ID, LONG* pNumber, PBSTR pName, PBSTR pTag, short* pEnabled, PBSTR pShortName, PBSTR pBarcode, LONG* pQuickCode, double* pPrice1, double* pPrice2, double* pPrice3, double* pPrice4, LONG* pProductGroup);
EZ_DLL_CALL SetProductPropertiesEx(LONG ID, LONG Number, BSTR Name, BSTR Tag, short Enabled, BSTR ShortName, BSTR Barcode, LONG QuickCode, double Price1, double Price2, double Price3, double Price4, LONG ProductGroup);
EZ_DLL_CALL GetProductPropertiesEx2(LONG ID, LONG* pNumber, PBSTR pName, PBSTR pTag, short* pEnabled, PBSTR pShortName, PBSTR pBarcode, LONG* pQuickCode, double* pPrice1, double* pPrice2, double* pPrice3, double* pPrice4, LONG* pProductGroup, DATE* pAddedDT, DATE* pUpdatedDT ) ;
EZ_DLL_CALL AddProduct(LONG* pID, LONG* pNumber, BSTR Name, BSTR Tag, short Enabled, BSTR ShortName, BSTR Barcode, LONG QuickCode, double Price1, double Price2, double Price3, double Price4, LONG ProductGroup);
EZ_DLL_CALL GetLastProductUpdated( LONG* pID , DATE* pDate ) ;
EZ_DLL_CALL DeleteProduct(LONG ID);
EZ_DLL_CALL GetProductsCount(LONG* pCount, LONG Number, BSTR Name, BSTR ShortName, BSTR Tag, BSTR Barcode, LONG ProductGroup);
EZ_DLL_CALL GetProductByOrdinal(LONG Index, LONG* pID, LONG Number, BSTR Name, BSTR ShortName, BSTR Tag, BSTR Barcode, LONG ProductGroup);

EZ_DLL_CALL GetProductsCountEx(LONG* pCount, LONG Number, BSTR Name, BSTR ShortName, BSTR Tag, BSTR Barcode, LONG QuickCode, LONG ProductGroup);
EZ_DLL_CALL GetProductByOrdinalEx(LONG Index, LONG* pID, LONG Number, BSTR Name, BSTR ShortName, BSTR Tag, BSTR Barcode, LONG QuickCode, LONG ProductGroup);

EZ_DLL_CALL GetSaleItemProperties(LONG ID, LONG* pProductID, LONG* pPumpID, LONG* pAttendantID, LONG* pCardClientID, short* pPriceLevel, double* pPrice,
	double* pQuantity, DATE* pAddedDT, DATE* pClearedDT, LONG* pLockedBy, LONG* pClearedBy, short* pLoggedDB, short* pLoggedVolumetric,
	PBSTR pPlate, PBSTR pDriverID, PBSTR pExtTransactionID, PBSTR pAuthID, short* pAuthType);

EZ_DLL_CALL SetSaleItemProperties(LONG ID, LONG ProductID, LONG PumpID, LONG AttendantID, LONG CardClientID, short PriceLevel, double Price,
	double Quantity, DATE AddedDT, DATE ClearedDT, LONG LockedBy, LONG ClearedBy, short LoggedDB, short LoggedVolumetric,
	BSTR Plate, BSTR DriverID, BSTR ExtTransactionID, BSTR AuthID, short AuthType);

EZ_DLL_CALL AddSaleItem(LONG* pID, LONG ProductID, LONG PumpID, LONG AttendantID, LONG CardClientID, short PriceLevel, double Price,
	double Quantity, DATE AddedDT, DATE ClearedDT, LONG LockedBy, LONG ClearedBy, short LoggedDB, short LoggedVolumetric,
	BSTR Plate, BSTR DriverID, BSTR ExtTransactionID, BSTR AuthID, short AuthType, __int64 CardClientTag );

EZ_DLL_CALL DeleteSaleItem(LONG ID);	 

EZ_DLL_CALL AddSaleItemEx( LONG* pID, LONG ProductID, LONG PumpID, LONG AttendantID, LONG CardClientID, short PriceLevel, double Price,
	double Quantity, DATE AddedDT, DATE ClearedDT, LONG LockedBy, LONG ClearedBy, short LoggedDB, short LoggedVolumetric,
	BSTR Plate, BSTR DriverID, BSTR ExtTransactionID, BSTR AuthID, short AuthType, __int64 CardClientTag , BSTR Barcode, __int64 AttendantTag ) ;

EZ_DLL_CALL GetSaleItemsCount(LONG* pCount, LONG ProductID, LONG ProductNumber, LONG PumpID, LONG PumpNumber, LONG AttendantID, LONG AttendantNumber, __int64 AttendantTag, LONG CardClientID, LONG CardClientNumber, __int64 CardClientTag, LONG LockedBy, LONG ClearedBy, short LoggedDB, short LoggedVolumetric);
EZ_DLL_CALL GetSaleItemByOrdinal(LONG Index, LONG* pID, LONG ProductID, LONG ProductNumber, LONG PumpID, LONG PumpNumber, LONG AttendantID, LONG AttendantNumber, __int64 AttendantTag, LONG CardClientID, LONG CardClientNumber, __int64 CardClientTag, LONG LockedBy, LONG ClearedBy, short LoggedDB, short LoggedVolumetric);

EZ_DLL_CALL GetSaleItemsCountEx(LONG* pCount, LONG ProductID, LONG ProductNumber, LONG PumpID, LONG PumpNumber, LONG AttendantID, LONG AttendantNumber, __int64 AttendantTag, LONG CardClientID, LONG CardClientNumber, __int64 CardClientTag, LONG LockedBy, LONG ClearedBy, short LoggedDB, short LoggedVolumetric, DATE StartDT, DATE EndDT);
EZ_DLL_CALL GetSaleItemByOrdinalEx(LONG Index, LONG* pID, LONG ProductID, LONG ProductNumber, LONG PumpID, LONG PumpNumber, LONG AttendantID, LONG AttendantNumber, __int64 AttendantTag, LONG CardClientID, LONG CardClientNumber, __int64 CardClientTag, LONG LockedBy, LONG ClearedBy, short LoggedDB, short LoggedVolumetric, DATE StartDT, DATE EndDT);

EZ_DLL_CALL SaleItemLock(LONG ID);
EZ_DLL_CALL SaleItemUnlock(LONG ID);
EZ_DLL_CALL SaleItemClear(LONG ID);
EZ_DLL_CALL SaleItemLockAndClear(LONG ID);
EZ_DLL_CALL SaleItemAckDBLog(LONG ID);
EZ_DLL_CALL SaleItemAckVolLog(LONG ID);
EZ_DLL_CALL GetSaleItemSummary(LONG ID, LONG* pProductID, LONG* pProductNumber, PBSTR pProductName, __int64* pProductTag, LONG* pProductGroup, PBSTR pProductGroupName, PBSTR pBarcode,
	LONG* pPumpID, LONG* pPumpNumber, PBSTR pPumpName,
	LONG* pAttendantID, LONG* pAttendantNumber, PBSTR pAttendantName, __int64* pAttendantTag,
	LONG* pCardClientID, LONG* pCardClientNumber, PBSTR pCardClientName, __int64* pCardClientTag,
	short* pPriceLevel, double* pPrice, double* pQuantity, DATE* pAddedDT, DATE* pClearedDT,
	LONG* pLockedBy, LONG* pClearedBy, short* pLoggedDB, short* pLoggedVolumetric,
	PBSTR pPlate, PBSTR pDriverID, PBSTR pExtTransactionID, PBSTR pAuthID, short* pAuthType);

EZ_DLL_CALL GetPriceSignElement( short Element , short* pElementType , LONG* pLinkID  , short* pDecimals , double* pPrice , short* pState , short* pOnTime, short* pOffTime ) ;
EZ_DLL_CALL SetPriceSignElement( short Element , short ElementType , LONG LinkID , short Decimals  , double Price , short State , short OnTime, short OffTime );

EZ_DLL_CALL GetStappingTableData(LONG ID, double* pStepSize, double* pDiameter, double* pOffset, double* pCapacity, LONG* pAlarms);
EZ_DLL_CALL SetStappingTableData(LONG ID, double StepSize, double Diameter, double Offset, double Capacity, LONG Alarms);
EZ_DLL_CALL GetStappingTableElement(LONG ID, LONG Element, short* pPasses, double* pHeight, double* pStartDelta, double* pCurDelta, double* pStartVolume, double* pCurVolume);
EZ_DLL_CALL SetStappingTableElement(LONG ID, LONG Element, short Passes, double StartDelta, double CurDelta);

EZ_DLL_CALL GetTCPIPConfig(PBSTR pIPAddress, PBSTR pNetMask, PBSTR pGateway , PBSTR pDNSServer , short* pDHCP , PBSTR pNetworkName ) ;
EZ_DLL_CALL SetTCPIPConfig(BSTR bIPAddress, BSTR bNetMask, BSTR bGateway , BSTR bDNSServer , short DHCP , BSTR bNetworkName ) ;
EZ_DLL_CALL WDReset() ;
EZ_DLL_CALL EZLicenseOP( short OPType , PBSTR pLicenseKey , short* pLicenseMask , short* pState , DATE* pExpiryDate , PBSTR pKeySerialNo , PBSTR pSerialNo ) ;
EZ_DLL_CALL WasReconnected() ;

#else 

class CEZCLProcess ;

EZ_DLL_CALL ServerVersionMT(CEZCLProcess* pCLProcess ,  PBSTR pName ) ;
EZ_DLL_CALL ClientLogonMT(CEZCLProcess** ppCLProcess ,  LONG ClientID , short ClientType , HANDLE Event , HWND hWnd, unsigned int wMsg) ;
EZ_DLL_CALL ClientLogonExMT(CEZCLProcess** ppCLProcess ,  LONG ClientID , short ClientType , BSTR ServerName , unsigned short CallPortNo , unsigned short EventsPortNo , LONG CallTimeout, HANDLE Event , HWND hWnd, unsigned int wMsg) ;

EZ_DLL_CALL GetClientEventsSocketMT(CEZCLProcess* pCLProcess, SOCKET* pHandle);
EZ_DLL_CALL GetClientCallsSocketMT(CEZCLProcess* pCLProcess, SOCKET* pHandle);

EZ_DLL_CALL ClientLogoffMT(CEZCLProcess** ppCLProcess ) ;
EZ_DLL_CALL ClientStatusMT(CEZCLProcess* pCLProcess ,  short* pPumpsReserved , short* pdeliveriesLocked ) ;
EZ_DLL_CALL GetLicenseTypeMT(CEZCLProcess* pCLProcess ,  short* pLicenseType ) ;
EZ_DLL_CALL FireClientEventMT(CEZCLProcess* pCLProcess ,  LONG EventID , BSTR EventStr ) ;
EZ_DLL_CALL CheckForManagementFtnMT(CEZCLProcess** ppCLProcess);
EZ_DLL_CALL TestConnectionMT(CEZCLProcess* pCLProcess ) ;
EZ_DLL_CALL FireEventsMT(CEZCLProcess* pCLProcess);
EZ_DLL_CALL ProcessEventsMT(CEZCLProcess* pCLProcess ) ;
EZ_DLL_CALL GetEventsCountMT(CEZCLProcess* pCLProcess ,  LONG* pCount ) ;
EZ_DLL_CALL GetNextEventTypeMT(CEZCLProcess* pCLProcess ,  short* pType ) ;
EZ_DLL_CALL DiscardNextEventMT(CEZCLProcess* pCLProcess ) ;
EZ_DLL_CALL GetNextPumpEventMT(CEZCLProcess* pCLProcess ,  LONG* pPumpID, short* pPumpNumber, short* pState, short* pReservedFor, LONG* pReservedBy, LONG* pHoseID ,
							   short* pHoseNumber, LONG* pGradeID, PBSTR pGradeName , PBSTR pShortGradeName, short* pPriceLevel , double* pPrice, double* pVolume, 
							   double* pValue, short* pStackSize ) ;
EZ_DLL_CALL GetNextDeliveryEventMT(CEZCLProcess* pCLProcess ,  LONG* pDeliveryID , LONG* pPumpID, short* pPumpNumber, LONG* pHoseID, short* pHoseNumber , 
								LONG* pGradeID, PBSTR pGradeName ,PBSTR pShortGradeName, short* pPriceLevel, double* pPrice, double* pVolume, double* pValue, 
								short* pDeliveryState , short* pDeliveryType, LONG* pLockedBy, LONG* pReservedBy, LONG* pAge , DATE* pCompletedDT , LONG* pAttendantID ) ;
EZ_DLL_CALL GetNextServerEventMT(CEZCLProcess* pCLProcess ,  LONG* pEventID, PBSTR pEventText ) ;
EZ_DLL_CALL GetNextClientEventMT(CEZCLProcess* pCLProcess ,  LONG* pClientID, LONG* pEventID, PBSTR pEventText ) ;
EZ_DLL_CALL GetNextDBLogEventMT(CEZCLProcess* pCLProcess ,  LONG* pEventType , LONG* pDeviceID , DATE* pEventDT , PBSTR pEventText ) ;
EZ_DLL_CALL GetNextDBLogDeliveryEventMT(CEZCLProcess* pCLProcess ,  LONG* pDeliveryID, LONG* pHoseID, short* pDeliveryState, short* pDeliveryType, double* pVolume, short* pPriceLevel, 
							 double* pPrice, double* pValue, double* pVolume2, LONG* pReservedBy , LONG* pAttendantID, DATE* pDeliveryDT ) ;
EZ_DLL_CALL GetNextDBClearDeliveryEventMT(CEZCLProcess* pCLProcess ,  LONG* pDeliveryID, short* pDeliveryType, LONG* pClearedBY, DATE* pClearedDT, LONG* pAttendantID ) ;
EZ_DLL_CALL GetNextDBStackDeliveryEventMT(CEZCLProcess* pCLProcess ,  LONG* pDeliveryID ) ;
EZ_DLL_CALL GetNextDBHoseETotalsEventMT(CEZCLProcess* pCLProcess ,  LONG* pHoseID , double* pVolume , double* pValue , double* pVolumeETot , double* pValueETot ) ;
EZ_DLL_CALL GetNextDBTriggerEventMT(CEZCLProcess* pCLProcess ,  LONG* pTableID ,LONG* pRowID ) ;
EZ_DLL_CALL GetNextDBAttendantLogonEventMT(CEZCLProcess* pCLProcess ,  LONG* pAttendantID ,LONG* pPumpID ) ;
EZ_DLL_CALL GetNextDBAttendantLogoffEventMT(CEZCLProcess* pCLProcess ,  LONG* pAttendantID ) ;
EZ_DLL_CALL GetNextDBTankStatusEventMT(CEZCLProcess* pCLProcess ,  LONG* pTankID , double* pGaugeVolume , double* pGaugeTCVolume, double* pGaugeUllage, double* pGaugeTemperature , 
							          double* pGaugeLevel , double* pGaugeWaterVolume, double* pGaugeWaterLevel ) ;
EZ_DLL_CALL GetClientsCountMT( CEZCLProcess* pCLProcess , LONG* pCount ) ;
EZ_DLL_CALL GetPumpsCountMT(CEZCLProcess* pCLProcess ,  LONG* pCount ) ;
EZ_DLL_CALL GetPumpByNumberMT(CEZCLProcess* pCLProcess ,  LONG Number , LONG* pID ) ;
EZ_DLL_CALL GetPumpByNameMT(CEZCLProcess* pCLProcess ,  BSTR Name , LONG* pID ) ;
EZ_DLL_CALL GetPumpByOrdinalMT(CEZCLProcess* pCLProcess ,  LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetPumpPropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName, short* pPhysicalNumber, short* pSide, short* pAddress, short* pPriceLevel1,
						      short* pPriceLevel2, short* pPriceDspFormat, short* pVolumeDspFormat, short* pValueDspFormat, short* pType,  
						      LONG* pPortID, LONG* pAttendantID, short* pAuthMode, short* pStackMode, short* pPrepayAllowed, short* pPreauthAllowed ) ;
EZ_DLL_CALL SetPumpPropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG Number, BSTR Name, short PhysicalNumber, short Side, short Address, short PriceLevel1,
						      short PriceLevel2, short PriceDspFormat, short VolumeDspFormat, short ValueDspFormat, short Type, 
						      LONG PortID, LONG AttendantID, short AuthMode, short StackMode, short PrepayAllowed, short PreauthAllowed ) ;
EZ_DLL_CALL AddPumpMT(CEZCLProcess* pCLProcess , LONG* pID, LONG* pNumber, BSTR Name, short PhysicalNumber, short Side, short Address, short PriceLevel1,
						        short PriceLevel2, short PriceDspFormat, short VolumeDspFormat, short ValueDspFormat, short Type, 
						        LONG PortID, LONG AttendantID, short AuthMode, short StackMode, short PrepayAllowed, short PreauthAllowed , 
								LONG SlotZigBeeID , LONG MuxSlotZigBeeID , short PriceControl , short HasPreset  ) ;
EZ_DLL_CALL DeletePumpMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL GetPumpHosesCountMT(CEZCLProcess* pCLProcess ,  LONG ID , LONG* pCount ) ;
EZ_DLL_CALL GetPumpHoseByNumberMT(CEZCLProcess* pCLProcess ,  LONG ID , LONG Number , LONG* pHoseID ) ;
EZ_DLL_CALL GetPumpStatusMT(CEZCLProcess* pCLProcess ,  LONG ID , short* pState, short* pReservedFor, LONG* pReservedBy, LONG* pHoseID, short* pHoseNumber , 
						   LONG* pGradeID, PBSTR pGradeName ,PBSTR pShortGradeName, short* pPriceLevel , double* pPrice , double* pVolume , double* pValue , 
						   short* pStackSize ) ;
EZ_DLL_CALL GetPumpStatusExMT( CEZCLProcess* pCLProcess , LONG ID , LONG* pPumpNumber, PBSTR pPumpName, LONG* pPhysicalNumber, 
							   short* pState, short* pReservedFor, LONG* pReservedBy, 
							   LONG* pHoseID, LONG* pHoseNumber , LONG* pHosePhysicalNumber , 
							   LONG* pGradeID , LONG* pGradeNumber , PBSTR pGradeName, PBSTR pShortGradeName, 
							   short* pPriceLevel , double* pPrice , double* pVolume , double* pValue , short* pStackSize , __int64* pTag , 
							   LONG* pAttendantID , LONG* pAttendantNumber , PBSTR pAttendantName, __int64* pAttendantTag ,
							   LONG* pCardClientID , LONG* pCardClientNumber , PBSTR pCardClientName, __int64* pCardClientTag ) ;

EZ_DLL_CALL GetPumpStatusEx2MT( CEZCLProcess* pCLProcess , LONG ID , LONG* pPumpNumber, PBSTR pPumpName, LONG* pPhysicalNumber, 
							  short* pState, short* pReservedFor, LONG* pReservedBy, 
							  LONG* pHoseID, LONG* pHoseNumber , LONG* pHosePhysicalNumber , 
							  LONG* pGradeID , LONG* pGradeNumber , PBSTR pGradeName, PBSTR pShortGradeName, 
							  short* pPriceLevel , double* pPrice , double* pVolume , double* pValue , short* pStackSize , __int64* pTag , 
							  LONG* pAttendantID , LONG* pAttendantNumber , PBSTR pAttendantName, __int64* pAttendantTag ,
							  LONG* pCardClientID , LONG* pCardClientNumber , PBSTR pCardClientName, __int64* pCardClientTag , 
							  double* pCurFlowRate , double* pPeakFlowRate ) ;

EZ_DLL_CALL GetPumpDeliveryPropertiesMT(CEZCLProcess* pCLProcess ,  LONG ID , short Index , LONG* pDeliveryID , short* pType , short* pState, LONG* pHoseID, 
									   short* pHoseNum, LONG* pGradeID , PBSTR pGradeName ,PBSTR pShortGradeName, short* pPriceLevel, double* pPrice , double* pVolume , 
									   double* pValue , LONG* pLockedBy , LONG* pReservedBy , LONG* pAge , DATE* pCompletedDT , LONG* pAttendantID  ) ;
EZ_DLL_CALL GetPumpDeliveryPropertiesExMT(CEZCLProcess* pCLProcess ,  LONG ID , short Index , LONG* pDeliveryID , short* pType , short* pState, LONG* pHoseID, short* pHoseNum, LONG* pGradeID, PBSTR pGradeName, PBSTR pShortGradeName , 
								        short* pPriceLevel, double* pPrice , double* pVolume , double* pValue , LONG* pLockedBy , 
									    LONG* pReservedBy , LONG* pAge , DATE* pCompletedDT , LONG* pAttendantID , double* pVolumeETot , double* pVolume2ETot , double* pValueETot , __int64* pTag ) ;
EZ_DLL_CALL GetPumpDeliveryPropertiesEx2MT( CEZCLProcess* pCLProcess , LONG ID , short Index , LONG* pDeliveryID , short* pType , short* pState, LONG* pHoseID, short* pHoseNum, LONG* pGradeID, PBSTR pGradeName, PBSTR pShortGradeName , 
								        short* pPriceLevel, double* pPrice , double* pVolume , double* pValue , LONG* pLockedBy , 
									    LONG* pReservedBy , LONG* pAge , DATE* pCompletedDT , LONG* pAttendantID , 
										double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
										double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
										__int64* pTag , LONG * pDuration ) ;
EZ_DLL_CALL GetPumpDeliveryPropertiesEx3MT( CEZCLProcess* pCLProcess , LONG ID , short Index , LONG* pDeliveryID , short* pType , short* pState, 
										   LONG* pHoseID, short* pHoseNum, 
										   LONG* pGradeID, PBSTR pGradeName, PBSTR pShortGradeName , 
											short* pPriceLevel, double* pPrice , double* pVolume , double* pValue , LONG* pLockedBy , 
											LONG* pReservedBy , LONG* pAge , DATE* pCompletedDT , LONG* pAttendantID , 
											double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
											double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
											__int64* pTag , LONG * pDuration , LONG* pCardClientID ) ;
EZ_DLL_CALL PrepayReserveMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL PrepayCancelMT(CEZCLProcess* pCLProcess ,  LONG ID  ) ;
EZ_DLL_CALL PrepayAuthoriseMT(CEZCLProcess* pCLProcess ,  LONG ID , short LimitType , double Value , short Hose , short PriceLevel ) ;
EZ_DLL_CALL PreauthReserveMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL PreauthCancelMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL PreauthAuthoriseMT(CEZCLProcess* pCLProcess ,  LONG ID , short LimitType , double Value , short Hose , short PriceLevel ) ;
EZ_DLL_CALL LoadPresetMT(CEZCLProcess* pCLProcess ,  LONG ID , short LimitType , double Value , short Hose , short PriceLevel ) ;
EZ_DLL_CALL LoadPresetWithPriceMT(CEZCLProcess* pCLProcess ,  LONG ID , short LimitType , double Value , short Hose , short PriceLevel , double Price ) ;
EZ_DLL_CALL TagAuthoriseMT(CEZCLProcess* pCLProcess ,  LONG ID , __int64 Tag , short LimitType , double Value , short Hose , short PriceLevel ) ;
EZ_DLL_CALL AttendantAuthoriseMT(CEZCLProcess* pCLProcess ,  LONG ID , LONG AttendantID ) ;
EZ_DLL_CALL AuthoriseMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL CancelAuthoriseMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL TempStopMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL ReAuthoriseMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL TerminateDeliveryMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL StackCurrentDeliveryMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL GetDensityMT( CEZCLProcess* pCLProcess , LONG ID , double* pDensity ) ;
EZ_DLL_CALL EnablePumpMT( CEZCLProcess* pCLProcess , LONG ID ) ;
EZ_DLL_CALL DisablePumpMT( CEZCLProcess* pCLProcess , LONG ID ) ;
EZ_DLL_CALL ExternalStartDeliveryMT( CEZCLProcess* pCLProcess , LONG ID , LONG HoseNum , LONG Age ) ;
EZ_DLL_CALL ExternalEndDeliveryMT( CEZCLProcess* pCLProcess ,  LONG ID , LONG HoseNum , double Volume, double Price, short PriceLevel, double Value, double VolumeETot, double ValueETot , __int64 iAttTag , __int64 iClientTag , LONG DeliveryID , LONG Age ) ;

EZ_DLL_CALL GetHosesCountMT(CEZCLProcess* pCLProcess ,  LONG* pCount ) ;
EZ_DLL_CALL GetHoseByOrdinalMT(CEZCLProcess* pCLProcess ,  LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetHosePropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, LONG* pPumpID ,LONG* pTankID , LONG* pPhysicalNumber, 
		                      double* pMtrTheoValue , double* pMtrTheoVolume ,double* pMtrElecValue ,
				              double* pMtrElecVolume ) ;
EZ_DLL_CALL SetHosePropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG Number,LONG PumpID, LONG TankID , LONG PhysicalNumber, 
		                      double MtrTheoValue , double MtrTheoVolume ,double MtrElecValue ,
				              double MtrElecVolume ) ;
EZ_DLL_CALL GetHoseSummaryMT(CEZCLProcess* pCLProcess , 	LONG ID , LONG* pNumber, LONG* pPhysicalNumber,
							LONG* pPumpID, LONG* pPumpNumber, PBSTR pPumpName,
							LONG* pTankID, LONG* pTankNumber, PBSTR pTankName,
							LONG* pGradeID , LONG* pGradeNumber, PBSTR pGradeName, PBSTR pGradeShortName, PBSTR pGradeCode,
		                    double* pMtrTheoValue , double* pMtrTheoVolume ,double* pMtrElecValue , double* pMtrElecVolume ) ;
EZ_DLL_CALL GetHoseSummaryExMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, LONG* pPhysicalNumber,
							LONG* pPumpID, LONG* pPumpNumber, PBSTR pPumpName,
							LONG* pTankID, LONG* pTankNumber, PBSTR pTankName,
							LONG* pGradeID , LONG* pGradeNumber, PBSTR pGradeName, PBSTR pGradeShortName, PBSTR pGradeCode,
		                    double* pMtrTheoValue , double* pMtrTheoVolume ,double* pMtrElecValue , double* pMtrElecVolume ,
							double* pPrice1 , double* pPrice2 , short* pEnabled ) ;
EZ_DLL_CALL GetHoseSummaryEx2MT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, LONG* pPhysicalNumber,
							LONG* pPumpID, LONG* pPumpNumber, PBSTR pPumpName,
							LONG* pTankID, LONG* pTankNumber, PBSTR pTankName,
							LONG* pGradeID , LONG* pGradeNumber, PBSTR pGradeName, PBSTR pGradeShortName, PBSTR pGradeCode,
		                    double* pMtrTheoValue , double* pMtrTheoVolume ,double* pMtrElecValue , double* pMtrElecVolume ,
							double* pPrice1 , double* pPrice2 , double* pPrice3 , double* pPrice4 , short* pEnabled ) ;

EZ_DLL_CALL AddHoseMT(CEZCLProcess* pCLProcess , LONG* pID, LONG* pNumber,LONG PumpID, LONG TankID , LONG PhysicalNumber, 
		                      double MtrTheoValue , double MtrTheoVolume ,double MtrElecValue ,
				              double MtrElecVolume , short UVEAntenna , double Price1 , double Price2 , double Price3 , double Price4, short Enabled ) ;

EZ_DLL_CALL DeleteHoseMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL GetDeliveriesCountMT(CEZCLProcess* pCLProcess ,  LONG* pCount ) ;
EZ_DLL_CALL GetDeliveryByOrdinalMT(CEZCLProcess* pCLProcess ,  LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetAllDeliveriesCountMT(CEZCLProcess* pCLProcess ,  LONG* pCount )  ;
EZ_DLL_CALL GetAllDeliveryByOrdinalMT(CEZCLProcess* pCLProcess ,  LONG Index , LONG* pID ) ;

EZ_DLL_CALL AckDeliveryDBLogMT(CEZCLProcess* pCLProcess , LONG ID ) ; 
EZ_DLL_CALL GetDeliveryIDByOrdinalNotLoggedMT(CEZCLProcess* pCLProcess , LONG Ordinal , LONG* pID ) ;
EZ_DLL_CALL GetDeliveriesCountNotLoggedMT(CEZCLProcess* pCLProcess , LONG* pCount ) ;

EZ_DLL_CALL GetDeliveriesCountFilteredMT(CEZCLProcess* pCLProcess,LONG* pCount, LONG PumpID, LONG PumpNumber, LONG HoseID, LONG HoseNumber, LONG HosePhysicalNumber, LONG GradeID, LONG GradeNumber, LONG TankID, LONG TankNumber , LONG LockedBy, LONG ReservedBy, short State, short LoggedDB , short LoggedVolumetric, short Type, __int64 Tag, LONG AttendantID, LONG AttendantNumber, __int64 AttendantTag, LONG CardClientID, LONG CardClientNumber, __int64 CardClientTag);
EZ_DLL_CALL GetDeliveryIDByOrdinalFilteredMT(CEZCLProcess* pCLProcess,LONG Ordinal, LONG* pID, LONG PumpID, LONG PumpNumber, LONG HoseID, LONG HoseNumber, LONG HosePhysicalNumber, LONG GradeID, LONG GradeNumber, LONG TankID, LONG TankNumber , LONG LockedBy, LONG ReservedBy, short State, short LoggedDB , short LoggedVolumetric, short Type, __int64 Tag, LONG AttendantID, LONG AttendantNumber, __int64 AttendantTag, LONG CardClientID, LONG CardClientNumber, __int64 CardClientTag);
EZ_DLL_CALL GetDeliveriesCountFilteredExMT(CEZCLProcess* pCLProcess, LONG* pCount, LONG PumpID, LONG PumpNumber, LONG HoseID, LONG HoseNumber, LONG HosePhysicalNumber, LONG GradeID, LONG GradeNumber, LONG TankID, LONG TankNumber, LONG LockedBy, LONG ReservedBy, short State, short LoggedDB, short LoggedVolumetric, short Type, __int64 Tag, LONG AttendantID, LONG AttendantNumber, __int64 AttendantTag, LONG CardClientID, LONG CardClientNumber, __int64 CardClientTag, DATE StartDT, DATE EndDT);
EZ_DLL_CALL GetDeliveryIDByOrdinalFilteredExMT(CEZCLProcess* pCLProcess, LONG Ordinal, LONG* pID, LONG PumpID, LONG PumpNumber, LONG HoseID, LONG HoseNumber, LONG HosePhysicalNumber, LONG GradeID, LONG GradeNumber, LONG TankID, LONG TankNumber, LONG LockedBy, LONG ReservedBy, short State, short LoggedDB, short LoggedVolumetric, short Type, __int64 Tag, LONG AttendantID, LONG AttendantNumber, __int64 AttendantTag, LONG CardClientID, LONG CardClientNumber, __int64 CardClientTag, DATE StartDT, DATE EndDT);

EZ_DLL_CALL AckDeliveryVolLogMT(CEZCLProcess* pCLProcess , LONG ID ) ; 
EZ_DLL_CALL GetDeliveryIDByOrdinalNotVolLoggedMT(CEZCLProcess* pCLProcess , LONG Ordinal , LONG* pID ) ;
EZ_DLL_CALL GetDeliveriesCountNotVolLoggedMT(CEZCLProcess* pCLProcess , LONG* pCount ) ;

EZ_DLL_CALL GetDeliveryPropertiesMT(CEZCLProcess* pCLProcess ,  LONG ID , LONG* pHoseID ,short* pState ,short* pType ,double* pVolume ,
								   short* pPriceLevel ,double* pPrice ,double* pValue ,double* pVolume2 , 
								   DATE* pCompletedDT ,LONG* pLockedBy , LONG* pReservedBy , LONG* pAttendantID , LONG* pAge ) ;
EZ_DLL_CALL GetDeliveryPropertiesExMT(CEZCLProcess* pCLProcess ,  LONG ID , LONG* pHoseID ,short* pState ,short* pType ,double* pVolume ,short* pPriceLevel ,
		                           double* pPrice ,double* pValue ,double* pVolume2 , DATE* pCompletedDT ,LONG* pLockedBy, LONG* pReservedBy , LONG* pAttendantID , LONG* pAge , 
								   DATE* pClearedDT ,double* pVolumeETot , double* pVolume2ETot , double* pValueETot , __int64* pTag ) ;
EZ_DLL_CALL GetDeliveryPropertiesEx2MT( CEZCLProcess* pCLProcess , LONG ID , LONG* pHoseID ,short* pState ,short* pType ,double* pVolume ,short* pPriceLevel ,
										double* pPrice ,double* pValue ,double* pVolume2 , DATE* pCompletedDT ,LONG* pLockedBy, LONG* pReservedBy , 
										LONG* pAttendantID , LONG* pAge , DATE* pClearedDT ,
										double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
										double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
										__int64* pTag , LONG * pDuration ) ;
EZ_DLL_CALL GetDeliveryPropertiesEx3MT( CEZCLProcess* pCLProcess , LONG ID , LONG* pHoseID ,short* pState ,short* pType ,double* pVolume ,short* pPriceLevel ,
										double* pPrice ,double* pValue ,double* pVolume2 , DATE* pCompletedDT ,LONG* pLockedBy, LONG* pReservedBy , 
										LONG* pAttendantID , LONG* pAge , DATE* pClearedDT ,
										double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
										double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
										__int64* pTag , LONG * pDuration , LONG* pCardClientID ) ;
EZ_DLL_CALL GetDeliveryPropertiesEx4MT( CEZCLProcess* pCLProcess , LONG ID , LONG* pHoseID ,short* pState ,short* pType ,double* pVolume ,short* pPriceLevel ,
										double* pPrice ,double* pValue ,double* pVolume2 , DATE* pCompletedDT ,LONG* pLockedBy, LONG* pReservedBy , 
										LONG* pAttendantID , LONG* pAge , DATE* pClearedDT ,
										double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
										double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
										__int64* pTag , LONG * pDuration , LONG* pCardClientID , double* pPeakFlowRate ) ;

EZ_DLL_CALL SetDeliveryPropertiesEx4MT( CEZCLProcess* pCLProcess , LONG ID , LONG HoseID ,short State ,short Type ,double Volume ,short PriceLevel ,
								   double Price ,double Value ,double Volume2 , DATE CompletedDT ,LONG LockedBy, 
								   LONG ReservedBy , LONG AttendantID , LONG Age , DATE ClearedDT , 
								   double OldVolumeETot , double OldVolume2ETot , double OldValueETot , 
								   double NewVolumeETot , double NewVolume2ETot , double NewValueETot , 
								   __int64 Tag , LONG Duration , LONG CardClientID, double PeakFlowRate ) ;
EZ_DLL_CALL GetPumpDeliveryPropertiesEx4MT( CEZCLProcess* pCLProcess , LONG ID , short Index , LONG* pDeliveryID , short* pType , short* pState, 
										   LONG* pHoseID, short* pHoseNum, 
										   LONG* pGradeID, PBSTR pGradeName, PBSTR pShortGradeName , 
								        short* pPriceLevel, double* pPrice , double* pVolume , double* pValue , LONG* pLockedBy , 
									    LONG* pReservedBy , LONG* pAge , DATE* pCompletedDT , LONG* pAttendantID , 
										double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
										double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
										__int64* pTag , LONG * pDuration , LONG* pCardClientID , double* pPeakFlowRate ) ;
EZ_DLL_CALL SetDeliveryPropertiesMT(CEZCLProcess* pCLProcess ,  LONG ID , LONG HoseID ,short State ,short Type ,double Volume ,short PriceLevel ,
								   double Price ,double Value ,double Volume2, DATE CompletedDT ,LONG LockedBy, LONG ReservedBy , 
								   LONG AttendantID , LONG Age ) ;
EZ_DLL_CALL SetDeliveryPropertiesExMT(CEZCLProcess* pCLProcess ,  LONG ID , LONG HoseID ,short State ,short Type ,double Volume ,short PriceLevel ,
								   double Price ,double Value ,double Volume2 , DATE CompletedDT ,LONG LockedBy, 
								   LONG ReservedBy , LONG AttendantID , LONG Age , DATE ClearedDT , double VolumeETot , double Volume2ETot , double ValueETot , __int64 Tag ) ;
EZ_DLL_CALL SetDeliveryPropertiesEx2MT( CEZCLProcess* pCLProcess , LONG ID , LONG HoseID ,short State ,short Type ,double Volume ,short PriceLevel ,
								   double Price ,double Value ,double Volume2 , DATE CompletedDT ,LONG LockedBy, 
								   LONG ReservedBy , LONG AttendantID , LONG Age , DATE ClearedDT , 
								   double OldVolumeETot , double OldVolume2ETot , double OldValueETot , 
								   double NewVolumeETot , double NewVolume2ETot , double NewValueETot , 
								   __int64 Tag , LONG Duration ) ;
EZ_DLL_CALL SetDeliveryPropertiesEx3MT( CEZCLProcess* pCLProcess , LONG ID , LONG HoseID ,short State ,short Type ,double Volume ,short PriceLevel ,
								   double Price ,double Value ,double Volume2 , DATE CompletedDT ,LONG LockedBy, 
								   LONG ReservedBy , LONG AttendantID , LONG Age , DATE ClearedDT , 
								   double OldVolumeETot , double OldVolume2ETot , double OldValueETot , 
								   double NewVolumeETot , double NewVolume2ETot , double NewValueETot , 
								   __int64 Tag , LONG Duration , LONG CardClientID ) ;
EZ_DLL_CALL GetDeliverySummaryMT(CEZCLProcess* pCLProcess ,  LONG ID , LONG* pHoseID ,LONG* pHoseNumber, LONG* pHosePhysicalNumber,
	  							LONG* pPumpID, LONG* pPumpNumber, PBSTR  pPumpName,
								LONG* pTankID, LONG* pTankNumber, PBSTR  pTankName,
								LONG* pGradeID , LONG* pGradeNumber, PBSTR  pGradeName, PBSTR  pGradeShortName, PBSTR  pGradeCode,
								short* pState ,short* pType ,double* pVolume ,short* pPriceLevel ,
								double* pPrice ,double* pValue ,double* pVolume2 , DATE* pCompletedDT ,LONG* pLockedBy, 
								LONG* pReservedBy , LONG* pAttendantID , LONG* pAge ,DATE* pClearedDT ,
								double* pVolumeETot , double* pVolume2ETot , double* pValueETot , __int64* pTag) ;

EZ_DLL_CALL GetDeliverySummaryExMT( CEZCLProcess* pCLProcess , LONG ID , LONG* pHoseID ,LONG* pHoseNumber, LONG* pHosePhysicalNumber,
	  							LONG* pPumpID, LONG* pPumpNumber, PBSTR  pPumpName,
								LONG* pTankID, LONG* pTankNumber, PBSTR  pTankName,
								LONG* pGradeID , LONG* pGradeNumber, PBSTR  pGradeName, PBSTR  pGradeShortName, PBSTR  pGradeCode,
							    short* pState ,short* pType ,double* pVolume ,short* pPriceLevel ,
		                        double* pPrice ,double* pValue ,double* pVolume2 , DATE* pCompletedDT ,LONG* pLockedBy, 
								LONG* pReservedBy , LONG* pAttendantID , LONG* pAge ,DATE* pClearedDT ,
								double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
								double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
								__int64* pTag , LONG * pDuration ) ;

EZ_DLL_CALL GetDeliverySummaryEx2MT( CEZCLProcess* pCLProcess , LONG ID , LONG* pHoseID ,LONG* pHoseNumber, LONG* pHosePhysicalNumber,
	  							LONG* pPumpID, LONG* pPumpNumber, PBSTR  pPumpName,
								LONG* pTankID, LONG* pTankNumber, PBSTR  pTankName,
								LONG* pGradeID , LONG* pGradeNumber, PBSTR  pGradeName, PBSTR  pGradeShortName, PBSTR  pGradeCode,
							    short* pState ,short* pType ,double* pVolume ,short* pPriceLevel ,
		                        double* pPrice ,double* pValue ,double* pVolume2 , DATE* pCompletedDT ,LONG* pLockedBy, 
								LONG* pReservedBy , LONG* pAttendantID , LONG* pAge ,DATE* pClearedDT ,
								double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
								double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
								__int64* pTag , LONG * pDuration , LONG* pAttendantNumber , PBSTR pAttendantName, __int64* pAttendantTag ,
								LONG* pCardClientID , LONG* pCardClientNumber , PBSTR pCardClientName, __int64* pCardClientTag ) ;

EZ_DLL_CALL GetDeliverySummaryEx3MT( CEZCLProcess* pCLProcess , LONG ID , LONG* pHoseID ,LONG* pHoseNumber, LONG* pHosePhysicalNumber,
	  							LONG* pPumpID, LONG* pPumpNumber, PBSTR  pPumpName,
								LONG* pTankID, LONG* pTankNumber, PBSTR  pTankName,
								LONG* pGradeID , LONG* pGradeNumber, PBSTR  pGradeName, PBSTR  pGradeShortName, PBSTR  pGradeCode,
							    short* pState ,short* pType ,double* pVolume ,short* pPriceLevel ,
		                        double* pPrice ,double* pValue ,double* pVolume2 , DATE* pCompletedDT ,LONG* pLockedBy, 
								LONG* pReservedBy , LONG* pAttendantID , LONG* pAge ,DATE* pClearedDT ,
								double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
								double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
								__int64* pTag , LONG * pDuration , LONG* pAttendantNumber , PBSTR pAttendantName, __int64* pAttendantTag ,
								LONG* pCardClientID , LONG* pCardClientNumber , PBSTR pCardClientName, __int64* pCardClientTag , double* pPeakFlowRate ) ;

EZ_DLL_CALL GetDeliverySummaryEx4MT(CEZCLProcess* pCLProcess, LONG ID, LONG* pHoseID, LONG* pHoseNumber, LONG* pHosePhysicalNumber,
								LONG* pPumpID, LONG* pPumpNumber, PBSTR  pPumpName,
								LONG* pTankID, LONG* pTankNumber, PBSTR  pTankName,
								LONG* pGradeID, LONG* pGradeNumber, PBSTR  pGradeName, PBSTR  pGradeShortName, PBSTR  pGradeCode,
								short* pState, short* pType, double* pVolume, short* pPriceLevel,
								double* pPrice, double* pValue, double* pVolume2, DATE* pCompletedDT, LONG* pLockedBy,
								LONG* pReservedBy, LONG* pAttendantID, LONG* pAge, DATE* pClearedDT,
								double* pOldVolumeETot, double* pOldVolume2ETot, double* pOldValueETot,
								double* pNewVolumeETot, double* pNewVolume2ETot, double* pNewValueETot,
								__int64* pTag, LONG * pDuration, LONG* pAttendantNumber, PBSTR pAttendantName, __int64* pAttendantTag, PBSTR pAttendantIDNumber,
								LONG* pCardClientID, LONG* pCardClientNumber, PBSTR pCardClientName, __int64* pCardClientTag, PBSTR pCardClientIDNumber, double* pPeakFlowRate);


EZ_DLL_CALL LockDeliveryMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL UnlockDeliveryMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL ClearDeliveryMT(CEZCLProcess* pCLProcess ,  LONG ID , short Type ) ;
EZ_DLL_CALL LockAndClearDeliveryMT(CEZCLProcess* pCLProcess ,  LONG ID , short Type ) ;
EZ_DLL_CALL GetDurationMT( CEZCLProcess* pCLProcess , LONG ID , LONG* pDuration ) ;
EZ_DLL_CALL SetDeliveryExtMT( CEZCLProcess* pCLProcess , LONG ID , BSTR Plate , double Odometer , double Odometer2 , BSTR ExtTransactionID , BSTR DriverID , BSTR AuthID, short AuthType ) ;
EZ_DLL_CALL GetDeliveryExtMT( CEZCLProcess* pCLProcess , LONG ID , PBSTR pPlate , double* pOdometer , double* pOdometer2 , PBSTR pExtTransactionID , PBSTR pDriverID , PBSTR pAuthID, short* pAuthType) ;
EZ_DLL_CALL GetGradesCountMT(CEZCLProcess* pCLProcess ,  LONG* pCount ) ;
EZ_DLL_CALL GetGradeByNumberMT(CEZCLProcess* pCLProcess ,  LONG Number , LONG* pID ) ;
EZ_DLL_CALL GetGradeByNameMT(CEZCLProcess* pCLProcess ,  BSTR Name , LONG* pID ) ;
EZ_DLL_CALL GetGradeByOrdinalMT(CEZCLProcess* pCLProcess ,  LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetGradePropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName , PBSTR pShortName , PBSTR pCode ) ;
EZ_DLL_CALL SetGradePropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG Number, BSTR Name , BSTR ShortName , BSTR Code  ) ;
EZ_DLL_CALL GetGradePropertiesExMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName , PBSTR pShortName , PBSTR pCode , short* pType ) ;
EZ_DLL_CALL SetGradePropertiesExMT(CEZCLProcess* pCLProcess , LONG ID , LONG Number, BSTR Name , BSTR ShortName , BSTR Code , short Type  ) ;
EZ_DLL_CALL AddGradeMT(CEZCLProcess* pCLProcess , LONG* pID, LONG* pNumber, BSTR Name , BSTR ShortName , BSTR Code , short Type  ) ;
EZ_DLL_CALL DeleteGradeMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL SetGradePriceMT(CEZCLProcess* pCLProcess ,  LONG ID , short Level , double Price ) ;
EZ_DLL_CALL GetGradePriceMT(CEZCLProcess* pCLProcess ,  LONG ID , short Level , double* pPrice ) ;
EZ_DLL_CALL GetTanksCountMT(CEZCLProcess* pCLProcess ,  LONG* pCount ) ;
EZ_DLL_CALL GetTankByNumberMT(CEZCLProcess* pCLProcess ,  LONG Number , LONG* pID ) ;
EZ_DLL_CALL GetTankByNameMT(CEZCLProcess* pCLProcess ,  BSTR Name , LONG* pID ) ;
EZ_DLL_CALL GetTankByOrdinalMT(CEZCLProcess* pCLProcess ,  LONG Index , LONG* pID ) ;


EZ_DLL_CALL GetTankPropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName , LONG* pGradeID , short* pType , double* pCapacity , double* pDiameter , 
							  double* pTheoVolume , double* pGaugeVolume , double* pGaugeTCVolume, double* pGaugeUllage, double* pGaugeTemperature , 
							  double* pGaugeLevel , double* pGaugeWaterVolume, double* pGaugeWaterLevel, LONG* pGaugeID, short* pProbeNo ) ;
EZ_DLL_CALL SetTankPropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG Number, BSTR Name , LONG GradeID , short Type , double Capacity , double Diameter , double TheoVolume , 
		                      double GaugeVolume , double GaugeTCVolume ,double GaugeUllage ,double GaugeTemperature , double GaugeLevel , 
							  double GaugeWaterVolume, double GaugeWaterLevel, LONG GaugeID , short ProbeNo ) ;

EZ_DLL_CALL GetTankPropertiesExMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName , LONG* pGradeID , short* pType , double* pCapacity , double* pDiameter , 
							  double* pTheoVolume , double* pGaugeVolume , double* pGaugeTCVolume, double* pGaugeUllage, double* pGaugeTemperature , 
							  double* pGaugeLevel , double* pGaugeWaterVolume, double* pGaugeWaterLevel, LONG* pGaugeID, short* pProbeNo , LONG* pGaugeAlarmsMask ) ;
EZ_DLL_CALL SetTankPropertiesExMT(CEZCLProcess* pCLProcess , LONG ID , LONG Number, BSTR Name , LONG GradeID , short Type , double Capacity , double Diameter , double TheoVolume , 
		                      double GaugeVolume , double GaugeTCVolume ,double GaugeUllage ,double GaugeTemperature , double GaugeLevel , 
							  double GaugeWaterVolume, double GaugeWaterLevel, LONG GaugeID , short ProbeNo , LONG GaugeAlarmsMask ) ;

EZ_DLL_CALL GetTankPropertiesEx2MT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName , LONG* pGradeID , short* pType , double* pCapacity , double* pDiameter , 
							  double* pTheoVolume , double* pGaugeVolume , double* pGaugeTCVolume, double* pGaugeUllage, double* pGaugeTemperature , 
							  double* pGaugeLevel , double* pGaugeWaterVolume, double* pGaugeWaterLevel, LONG* pGaugeID, short* pProbeNo , 
							  LONG* pGaugeAlarmsMask , LONG* pSlotZigBeeID , short* pProbeType , LONG* pProbeSerialNo) ;
EZ_DLL_CALL SetTankPropertiesEx2MT(CEZCLProcess* pCLProcess , LONG ID , LONG Number, BSTR Name , LONG GradeID , short Type , double Capacity , double Diameter , double TheoVolume , 
		                      double GaugeVolume , double GaugeTCVolume ,double GaugeUllage ,double GaugeTemperature , double GaugeLevel , 
							  double GaugeWaterVolume, double GaugeWaterLevel, LONG GaugeID , short ProbeNo , LONG GaugeAlarmsMask , LONG SlotZigBeeID , short ProbeType , LONG ProbeSerialNo) ;

EZ_DLL_CALL GetTankSummaryMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName , LONG* pGradeID , 
						   LONG* pGradeNumber, PBSTR pGradeName, PBSTR pGradeShortName, PBSTR pGradeCode, 
						   short* pType , double* pCapacity , double* pDiameter , 
						   double* pTheoVolume , double* pGaugeVolume , double* pGaugeTCVolume, double* pGaugeUllage, double* pGaugeTemperature , 
						   double* pGaugeLevel , double* pGaugeWaterVolume, double* pGaugeWaterLevel, LONG* pGaugeID, short* pProbeNo ) ;

EZ_DLL_CALL GetTankSummaryExMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName , LONG* pGradeID , 
						   LONG* pGradeNumber, PBSTR pGradeName, PBSTR pGradeShortName, PBSTR pGradeCode, 
						   short* pType , double* pCapacity , double* pDiameter , 
						   double* pTheoVolume , double* pGaugeVolume , double* pGaugeTCVolume, double* pGaugeUllage, double* pGaugeTemperature , 
						   double* pGaugeLevel , double* pGaugeWaterVolume, double* pGaugeWaterLevel, LONG* pGaugeID, short* pProbeNo , 
						   short* pState , LONG* pGaugeAlarmsMask ) ;
EZ_DLL_CALL GetTankSummaryEx2MT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName , LONG* pGradeID , 
						   LONG* pGradeNumber, PBSTR pGradeName, PBSTR pGradeShortName, PBSTR pGradeCode, 
						   short* pType , double* pCapacity , double* pDiameter , 
						   double* pTheoVolume , double* pGaugeVolume , double* pGaugeTCVolume, double* pGaugeUllage, double* pGaugeTemperature , 
						   double* pGaugeLevel , double* pGaugeWaterVolume, double* pGaugeWaterLevel, LONG* pGaugeID, short* pProbeNo , 
						   short* pState , LONG* pGaugeAlarmsMask , LONG* pSlotZigBeeID , short* pProbeType , LONG* pProbeSerialNo) ;

EZ_DLL_CALL TankDropMT(CEZCLProcess* pCLProcess ,  LONG ID , double Volume , DATE DropDT , BSTR Terminal , BSTR DocumentType , DATE DocumentDT  , BSTR DocumentFolio , double PEMEXVolume ) ;
EZ_DLL_CALL AddTankMT(CEZCLProcess* pCLProcess , LONG* pID, LONG* pNumber, BSTR Name , LONG GradeID , short Type , double Capacity , double Diameter , double TheoVolume , 
		                      double GaugeVolume , double GaugeTCVolume ,double GaugeUllage ,double GaugeTemperature , double GaugeLevel , 
							  double GaugeWaterVolume, double GaugeWaterLevel, LONG GaugeID , short ProbeNo , LONG GaugeAlarmsMask , LONG SlotZigBeeID , short ProbeType , LONG ProbeSerialNo) ;
EZ_DLL_CALL DeleteTankMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL GetPortsCountMT(CEZCLProcess* pCLProcess ,  LONG* pCount ) ;
EZ_DLL_CALL GetPortByNumberMT(CEZCLProcess* pCLProcess ,  LONG Number , LONG* pID ) ;
EZ_DLL_CALL GetPortByNameMT(CEZCLProcess* pCLProcess ,  BSTR Name , LONG* pID ) ;
EZ_DLL_CALL GetPortByOrdinalMT(CEZCLProcess* pCLProcess ,  LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetPortPropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName , LONG* pProtocolID , short* pDeviceType , PBSTR pSerialNo ) ;
EZ_DLL_CALL SetPortPropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG Number, BSTR Name, LONG ProtocolID , short DeviceType , BSTR SerialNo ) ;
EZ_DLL_CALL AddPortMT(CEZCLProcess* pCLProcess , LONG* pID, LONG* pNumber, BSTR Name, LONG ProtocolID , short DeviceType , BSTR SerialNo ) ;
EZ_DLL_CALL DeletePortMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL GetAttendantsCountMT(CEZCLProcess* pCLProcess ,  LONG* pCount ) ;
EZ_DLL_CALL GetAttendantByNumberMT(CEZCLProcess* pCLProcess ,  LONG Number , LONG* pID ) ;
EZ_DLL_CALL GetAttendantByNameMT(CEZCLProcess* pCLProcess ,  BSTR Name , LONG* pID ) ;
EZ_DLL_CALL GetAttendantByOrdinalMT(CEZCLProcess* pCLProcess ,  LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetAttendantPropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName , PBSTR pShortName , PBSTR pPassword , PBSTR pTag ) ; 
EZ_DLL_CALL SetAttendantPropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG Number, BSTR Name , BSTR ShortName , BSTR Password , BSTR Tag) ; 
EZ_DLL_CALL SetAttendantPropertiesExMT(CEZCLProcess* pCLProcess , LONG ID , LONG Number, BSTR Name , BSTR ShortName , BSTR Password , BSTR Tag , short ShiftAStart , short ShiftAEnd , short ShiftBStart , short ShiftBEnd , short Type )  ;
EZ_DLL_CALL GetAttendantPropertiesExMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName , PBSTR pShortName , PBSTR pPassword , PBSTR pTag , short* pShiftAStart , short* pShiftAEnd , short* pShiftBStart , short* pShiftBEnd , short* pType ) ; 
EZ_DLL_CALL GetAttendantPropertiesEx2MT(CEZCLProcess* pCLProcess, LONG ID, LONG* pNumber, PBSTR pName, PBSTR pShortName, PBSTR pPassword, PBSTR pTag, PBSTR pIDNumber, short* pShiftAStart, short* pShiftAEnd, short* pShiftBStart, short* pShiftBEnd, short* pType);
EZ_DLL_CALL SetAttendantPropertiesEx2MT(CEZCLProcess* pCLProcess, LONG ID, LONG Number, BSTR Name, BSTR ShortName, BSTR Password, BSTR Tag, BSTR IDNumber, short ShiftAStart, short ShiftAEnd, short ShiftBStart, short ShiftBEnd, short Type);
EZ_DLL_CALL AddAttendantMT(CEZCLProcess* pCLProcess, LONG* pID, LONG* pNumber, BSTR Name, BSTR ShortName, BSTR Password, BSTR Tag, BSTR IDNumber, short ShiftAStart, short ShiftAEnd, short ShiftBStart, short ShiftBEnd, short Type);


EZ_DLL_CALL GetAttendantStateMT(CEZCLProcess* pCLProcess , LONG ID , short* pType , short* pLoggedOn ) ;
EZ_DLL_CALL DeleteAttendantMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL AttendantLogonMT(CEZCLProcess* pCLProcess ,  LONG ID , LONG PumpID ) ;
EZ_DLL_CALL AttendantLogoffMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;

EZ_DLL_CALL GetCardReadsCountMT( CEZCLProcess* pCLProcess , LONG* pCount ) ;
EZ_DLL_CALL GetCardReadByNumberMT( CEZCLProcess* pCLProcess , LONG Number , LONG* pID ) ;
EZ_DLL_CALL GetCardReadByNameMT( CEZCLProcess* pCLProcess , BSTR Name , LONG* pID ) ;
EZ_DLL_CALL GetCardReadByOrdinalMT( CEZCLProcess* pCLProcess , LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetCardReadPropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName , LONG* pPumpID , short* pType , LONG* pParentID , __int64* pTag , DATE* pTimeStamp  )  ;
EZ_DLL_CALL SetCardReadPropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG Number, BSTR Name , LONG PumpID , short Type , LONG ParentID , __int64 Tag , DATE TimeStamp )  ;
EZ_DLL_CALL DeleteCardReadMT( CEZCLProcess* pCLProcess , LONG ID ) ;
EZ_DLL_CALL GetCardClientsCountMT( CEZCLProcess* pCLProcess , LONG* pCount ) ;
EZ_DLL_CALL GetCardClientByNumberMT( CEZCLProcess* pCLProcess , LONG Number , LONG* pID ) ;
EZ_DLL_CALL GetCardClientByNameMT( CEZCLProcess* pCLProcess , BSTR Name , LONG* pID ) ;
EZ_DLL_CALL GetCardClientByOrdinalMT( CEZCLProcess* pCLProcess , LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetCardClientPropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName , PBSTR pTag , short* pEnabled  )  ;
EZ_DLL_CALL SetCardClientPropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG Number, BSTR Name , BSTR Tag , short Enabled  )  ;
EZ_DLL_CALL SetCardClientPropertiesExMT(CEZCLProcess* pCLProcess , LONG ID , LONG Number, BSTR Name , BSTR Tag , short Enabled , short PriceLevel , BSTR Plate )  ;
EZ_DLL_CALL GetCardClientPropertiesExMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName , PBSTR pTag , short* pEnabled , short* pPriceLevel , PBSTR pPlate )  ;
EZ_DLL_CALL SetCardClientPropertiesEx2MT(CEZCLProcess* pCLProcess , LONG ID , LONG Number, BSTR Name , BSTR Tag , short Enabled , short PriceLevel , BSTR Plate , short GradeType, short CardType, short LimitType, double Limit, short EntryType, DATE ExpirationDate, LONG ParentID )  ;
EZ_DLL_CALL GetCardClientPropertiesEx2MT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName , PBSTR pTag , short* pEnabled , short* pPriceLevel , PBSTR pPlate , short* pGradeType, short* pCardType, short* pLimitType, double* pLimit, short* pEntryType, DATE* pExpirationDate, LONG* pParentID )  ;
EZ_DLL_CALL GetCardClientPropertiesEx3MT(CEZCLProcess* pCLProcess, LONG ID, LONG* pNumber, PBSTR pName, PBSTR pTag, short* pEnabled, short* pPriceLevel, PBSTR pPlate, PBSTR pIDNumber, PBSTR pShortName, PBSTR pPassword, short* pGradeType, short* pCardType, short* pLimitType, double* pLimit, short* pEntryType, DATE* pExpirationDate, LONG* pParentID);
EZ_DLL_CALL SetCardClientPropertiesEx3MT(CEZCLProcess* pCLProcess, LONG ID, LONG Number, BSTR Name, BSTR Tag, short Enabled, short PriceLevel, BSTR Plate, BSTR IDNumber, BSTR ShortName, BSTR Password, short GradeType, short CardType, short LimitType, double Limit, short EntryType, DATE ExpirationDate, LONG ParentID);
EZ_DLL_CALL GetCardClientPropertiesEx4MT(CEZCLProcess* pCLProcess, LONG ID, LONG* pNumber, PBSTR pName, PBSTR pTag, short* pEnabled, short* pPriceLevel, PBSTR pPlate, PBSTR pIDNumber, PBSTR pShortName, PBSTR pPassword, short* pGradeType, short* pCardType, short* pLimitType, double* pLimit, short* pEntryType, DATE* pExpirationDate, LONG* pParentID, PBSTR pEZOdoSerialNo, double* pOdometer, LONG* pFactor );
EZ_DLL_CALL SetCardClientPropertiesEx4MT(CEZCLProcess* pCLProcess, LONG ID, LONG Number, BSTR Name, BSTR Tag, short Enabled, short PriceLevel, BSTR Plate, BSTR IDNumber, BSTR ShortName, BSTR Password, short GradeType, short CardType, short LimitType, double Limit, short EntryType, DATE ExpirationDate, LONG ParentID, BSTR EZOdoSerialNo, double Odometer, LONG Factor );
EZ_DLL_CALL AddCardClientMT(CEZCLProcess* pCLProcess, LONG* pID, LONG* pNumber, BSTR Name, BSTR Tag, short Enabled, short PriceLevel, BSTR Plate, BSTR IDNumber, BSTR ShortName, BSTR Password, short GradeType, short CardType, short LimitType, double Limit, short EntryType, DATE ExpirationDate, LONG ParentID, BSTR EZOdoSerialNo, double Odometer, LONG Factor );
EZ_DLL_CALL DeleteCardClientMT( CEZCLProcess* pCLProcess , LONG ID ) ;

EZ_DLL_CALL AllStopMT(CEZCLProcess* pCLProcess ) ;
EZ_DLL_CALL AllAuthoriseMT(CEZCLProcess* pCLProcess ) ;
EZ_DLL_CALL AllReAuthoriseMT(CEZCLProcess* pCLProcess ) ;
EZ_DLL_CALL AllStopIfIdleMT(CEZCLProcess* pCLProcess ) ;
EZ_DLL_CALL ReadAllTanksMT(CEZCLProcess* pCLProcess ) ;
EZ_DLL_CALL GetAllPumpStatusesMT(CEZCLProcess* pCLProcess ,  PBSTR pStates , PBSTR pCurrentHoses , PBSTR pDeliveriesCount ) ; 
EZ_DLL_CALL GetAllStatusesMT( CEZCLProcess* pCLProcess , LONG Level , LONG Start , LONG End , LONG ObjID  , PBSTR pStatuses  ) ;
EZ_DLL_CALL AddLogEventMT(CEZCLProcess* pCLProcess, LONG* pID, short DeviceType, LONG DeviceID, short EventLevel, short EventType, BSTR  EventDesc, double Volume, double Value, double ProductVolume, double ProductLevel, double WaterLevel, double Temperature, DATE GenDT);

EZ_DLL_CALL GetIniValueMT(CEZCLProcess* pCLProcess ,  BSTR Section , BSTR Key , PBSTR pValue ) ; 
EZ_DLL_CALL SetIniValueMT(CEZCLProcess* pCLProcess ,  BSTR Section , BSTR Key , BSTR Value ) ; 
EZ_DLL_CALL GetIniValueExMT( CEZCLProcess* pCLProcess , BSTR FileName , BSTR Section , BSTR Key , PBSTR pValue ) ; 
EZ_DLL_CALL SetIniValueExMT( CEZCLProcess* pCLProcess , BSTR FileName , BSTR Section , BSTR Key , BSTR Value ) ; 
EZ_DLL_CALL SetNextDeliveryIDMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL RemovePortMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL LicenseStatusMT(CEZCLProcess* pCLProcess ) ;
EZ_DLL_CALL CheckSocketClosedMT(CEZCLProcess* pCLProcess ,  LPARAM lParam ) ;

EZ_DLL_CALL GetCardTypeMT( CEZCLProcess* pCLProcess , BSTR Tag , short* pTagType , LONG* pID, PBSTR pName, LONG* pNumber  ) ;
EZ_DLL_CALL FindCardMT(CEZCLProcess* pCLProcess, BSTR Tag, short* pCardType, short* pTagType, LONG* pID, PBSTR pName, LONG* pNumber);


EZ_DLL_CALL GetNextPumpEventExMT(CEZCLProcess* pCLProcess ,  LONG* pPumpID, short* pPumpNumber, short* pState, short* pReservedFor, LONG* pReservedBy, LONG* pHoseID ,
							    short* pHoseNumber,LONG* pGradeID, PBSTR pGradeName , PBSTR pShortGradeName, short* pPriceLevel , double* pPrice, double* pVolume, 
							    double* pValue, short* pStackSize , PBSTR pPumpName , short* pPhysicalNumber , short* pSide , short* pAddress, 
								short* pPriceLevel1 , short* pPriceLevel2 , short* pType , LONG* pPortID , short* pAuthMode , short* pStackMode ,  short* pPrepayAllowed, 
								short* pPreauthAllowed ,  short* pPriceFormat , short* pValueFormat , short* pVolumeFormat  ) ;

EZ_DLL_CALL GetNextDeliveryEventExMT(CEZCLProcess* pCLProcess ,  LONG* pDeliveryID , LONG* pPumpID, short* pPumpNumber, LONG* pHoseID, short* pHoseNumber , 
								    LONG* pGradeID, PBSTR pGradeName , PBSTR pShortGradeName, short* pPriceLevel, double* pPrice, 
									double* pVolume, double* pValue, short* pDeliveryState , 
								    short* pDeliveryType, LONG* pLockedBy, LONG* pReservedBy, LONG* pAge , DATE* pCompletedDT , 
									LONG* pAttendantID, double* pVolumeETot , double* pVolume2ETot , double* pValueETot , __int64* pTag) ;

EZ_DLL_CALL GetNextPumpEventEx2MT( CEZCLProcess* pCLProcess , LONG* pPumpID, LONG* pPumpNumber, short* pState, short* pReservedFor, LONG* pReservedBy, LONG* pHoseID ,
							    LONG* pHoseNumber, LONG* pHosePhysicalNumber,LONG* pGradeID,LONG* pGradeNumber, PBSTR pGradeName , PBSTR pShortGradeName, short* pPriceLevel , double* pPrice, double* pVolume, 
							    double* pValue, short* pStackSize , PBSTR pPumpName , LONG* pPhysicalNumber , short* pSide , short* pAddress, 
								short* pPriceLevel1 , short* pPriceLevel2 , short* pType , LONG* pPortID , short* pAuthMode , short* pStackMode ,  short* pPrepayAllowed, 
								short* pPreauthAllowed ,  short* pPriceFormat , short* pValueFormat , short* pVolumeFormat , __int64* pTag , 
							    LONG* pAttendantID , LONG* pAttendantNumber , PBSTR pAttendantName, __int64* pAttendantTag ,
							    LONG* pCardClientID , LONG* pCardClientNumber , PBSTR pCardClientName, __int64* pCardClientTag ) ;

EZ_DLL_CALL GetNextPumpEventEx3MT( CEZCLProcess* pCLProcess , LONG* pPumpID, LONG* pPumpNumber, short* pState, short* pReservedFor, LONG* pReservedBy, LONG* pHoseID ,
							    LONG* pHoseNumber, LONG* pHosePhysicalNumber,LONG* pGradeID,LONG* pGradeNumber, PBSTR pGradeName , PBSTR pShortGradeName, short* pPriceLevel , double* pPrice, double* pVolume, 
							    double* pValue, short* pStackSize , PBSTR pPumpName , LONG* pPhysicalNumber , short* pSide , short* pAddress, 
								short* pPriceLevel1 , short* pPriceLevel2 , short* pType , LONG* pPortID , short* pAuthMode , short* pStackMode ,  short* pPrepayAllowed, 
								short* pPreauthAllowed ,  short* pPriceFormat , short* pValueFormat , short* pVolumeFormat , __int64* pTag , 
							    LONG* pAttendantID , LONG* pAttendantNumber , PBSTR pAttendantName, __int64* pAttendantTag ,
							    LONG* pCardClientID , LONG* pCardClientNumber , PBSTR pCardClientName, __int64* pCardClientTag , 
								double* pCurFlowRate , double* pPeakFlowRate ) ;


EZ_DLL_CALL  GetNextDeliveryEventEx2MT( CEZCLProcess* pCLProcess , LONG* pDeliveryID , LONG* pPumpID, short* pPumpNumber, LONG* pHoseID, short* pHoseNumber , 
								     LONG* pGradeID, PBSTR pGradeName , PBSTR pShortGradeName, short* pPriceLevel, double* pPrice, 
									 double* pVolume, double* pValue, short* pDeliveryState , 
								     short* pDeliveryType, LONG* pLockedBy, LONG* pReservedBy, LONG* pAge , DATE* pCompletedDT , 
									 LONG* pAttendantID, 
									 double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
									 double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
									 __int64* pTag , LONG* pDuration ) ;

EZ_DLL_CALL  GetNextDeliveryEventEx3MT( CEZCLProcess* pCLProcess , LONG* pDeliveryID , LONG* pPumpID, short* pPumpNumber, LONG* pHoseID, short* pHoseNumber , 
								     LONG* pGradeID, PBSTR pGradeName , PBSTR pShortGradeName, short* pPriceLevel, double* pPrice, 
									 double* pVolume, double* pValue, short* pDeliveryState , 
								     short* pDeliveryType, LONG* pLockedBy, LONG* pReservedBy, LONG* pAge , DATE* pCompletedDT , 
									 LONG* pAttendantID, 
									 double* pOldVolumeETot , double* pOldVolume2ETot , double* pOldValueETot , 
									 double* pNewVolumeETot , double* pNewVolume2ETot , double* pNewValueETot , 
									 __int64* pTag , LONG* pDuration , LONG* pAttendantNumber , PBSTR pAttendantName, __int64* pAttendantTag ,
									 LONG* pCardClientID , LONG* pCardClientNumber , PBSTR pCardClientName, __int64* pCardClientTag ) ;

EZ_DLL_CALL  GetNextDeliveryEventEx4MT( CEZCLProcess* pCLProcess , 
									    LONG* pDeliveryID, LONG* pHoseID ,LONG* pHoseNumber, LONG* pHosePhysicalNumber,
	  									LONG* pPumpID, LONG* pPumpNumber, PBSTR pPumpName,
										LONG* pTankID, LONG* pTankNumber, PBSTR pTankName,
										LONG* pGradeID , LONG* pGradeNumber, PBSTR pGradeName, PBSTR pGradeShortName, PBSTR pGradeCode,
										short* pState ,short* pType ,double* pVolume ,short* pPriceLevel ,
										double* pPrice ,double* pValue ,double* pVolume2 , DATE* pCompletedDT , LONG* pLockedBy, 
										LONG* pReservedBy , LONG* pAttendantID , LONG* pAge , DATE* pClearedDT , 
										double* pOldVolumeETot, double* pOldVolume2ETot, double* pOldValueETot , 
										double* pNewVolumeETot, double* pNewVolume2ETot, double* pNewValueETot , 
										__int64* pTag , LONG* pDuration , LONG* pAttendantNumber , PBSTR pAttendantName, __int64* pAttendantTag ,
										LONG* pCardClientID , LONG* pCardClientNumber , PBSTR pCardClientName, __int64* pCardClientTag , double* pPeakFlowRate ) ;

EZ_DLL_CALL GetNextCardReadEventMT( CEZCLProcess* pCLProcess , LONG* pCardReadID , LONG* pNumber, PBSTR pName , LONG* pPumpID , short* pType , LONG* pParentID , __int64* pTag , DATE* pTimeStamp ) ;
EZ_DLL_CALL GetNextDBHoseETotalsEventExMT(CEZCLProcess* pCLProcess ,  LONG* pHoseID , double* pVolume , double* pValue , double* pVolumeETot , double* pValueETot , 
										 LONG* pHoseNumber , LONG* pHosePhysicalNumber , LONG* pPumpID , LONG* pPumpNumber , PBSTR pPumpName , 
										 LONG* pTankID , LONG* pTankNumber , PBSTR pTankName , LONG* pGradeID , PBSTR pGradeName ) ;
EZ_DLL_CALL GetNextDBTankStatusEventExMT(CEZCLProcess* pCLProcess ,  LONG* pTankID , double* pGaugeVolume , double* pGaugeTCVolume, double* pGaugeUllage, 
									    double* pGaugeTemperature , double* pGaugeLevel , double* pGaugeWaterVolume, double* pGaugeWaterLevel , 
									    LONG* pTankNumber , PBSTR pTankName , LONG* pGradeID , PBSTR pGradeName , short*pType  , 
										double* pCapacity , double* pDiameter , LONG* pGaugeID , short* pProbeNo) ;

EZ_DLL_CALL GetNextDBTankStatusEventEx2MT( CEZCLProcess* pCLProcess , LONG* pTankID , double* pGaugeVolume , double* pGaugeTCVolume, double* pGaugeUllage, 
									    double* pGaugeTemperature , double* pGaugeLevel , double* pGaugeWaterVolume, double* pGaugeWaterLevel , 
									    LONG* pTankNumber , PBSTR pTankName , LONG* pGradeID , PBSTR pGradeName , short*pType  , double* pCapacity , 
										double* pDiameter , LONG* pGaugeID , short* pProbeNo, short* pState , LONG* pAlarmsMask ) ;

EZ_DLL_CALL GetNextZBEventMT(CEZCLProcess* pCLProcess ,  LONG* pPortID , LONG* pZBID , __int64* pZBAddress, short* pResult , short* pMsgType , PBSTR pRxMsg ) ; 
EZ_DLL_CALL GetZigBeeCountMT(CEZCLProcess* pCLProcess ,  LONG* pCount ) ;
EZ_DLL_CALL GetZigBeeByNumberMT(CEZCLProcess* pCLProcess ,  LONG Number , LONG* pID ) ;
EZ_DLL_CALL GetZigBeeByNameMT(CEZCLProcess* pCLProcess ,  BSTR Name , LONG* pID ) ;
EZ_DLL_CALL GetZigBeeByOrdinalMT(CEZCLProcess* pCLProcess ,  LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetZigBeePropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName , short* pDeviceType , PBSTR pSerialNumber , PBSTR pNodeIdentifier , LONG* pPortID ) ;
EZ_DLL_CALL SetZigBeePropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG Number, BSTR Name , short DeviceType , BSTR SerialNumber , BSTR NodeIdentifier , LONG PortID ) ;
EZ_DLL_CALL DeleteZigBeeMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL AddZigBeeMT(CEZCLProcess* pCLProcess , LONG* pID, LONG* pNumber, BSTR Name , short DeviceType , BSTR SerialNumber , BSTR NodeIdentifier , LONG PortID ) ;

EZ_DLL_CALL GetHosePropertiesExMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, LONG* pPumpID ,LONG* pTankID , LONG* pPhysicalNumber, 
		                      double* pMtrTheoValue , double* pMtrTheoVolume ,double* pMtrElecValue ,
				              double* pMtrElecVolume , short* pUVEAntenna ) ;

EZ_DLL_CALL SetHosePropertiesExMT(CEZCLProcess* pCLProcess , LONG ID , LONG Number,LONG PumpID, LONG TankID , LONG PhysicalNumber, 
		                      double MtrTheoValue , double MtrTheoVolume ,double MtrElecValue ,
				              double MtrElecVolume , short UVEAntenna );

EZ_DLL_CALL SetHosePropertiesEx2MT(CEZCLProcess* pCLProcess , LONG ID , LONG Number,LONG PumpID, LONG TankID , LONG PhysicalNumber, 
		                      double MtrTheoValue , double MtrTheoVolume ,double MtrElecValue ,
				              double MtrElecVolume , short UVEAntenna , double Price1 , double Price2 , short Enabled ) ;

EZ_DLL_CALL GetHosePropertiesEx3MT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, LONG* pPumpID ,LONG* pTankID , LONG* pPhysicalNumber, 
		                      double* pMtrTheoValue , double* pMtrTheoVolume ,double* pMtrElecValue ,
				              double* pMtrElecVolume , short* pUVEAntenna , double* pPrice1 , double* pPrice2 , double* pPrice3 , double* pPrice4 , short* pEnabled );

EZ_DLL_CALL SetHosePropertiesEx3MT(CEZCLProcess* pCLProcess , LONG ID , LONG Number,LONG PumpID, LONG TankID , LONG PhysicalNumber, 
		                      double MtrTheoValue , double MtrTheoVolume ,double MtrElecValue ,
				              double MtrElecVolume , short UVEAntenna , double Price1 , double Price2 , double Price3 , double Price4, short Enabled );

EZ_DLL_CALL GetHosePropertiesEx2MT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, LONG* pPumpID ,LONG* pTankID , LONG* pPhysicalNumber, 
		                      double* pMtrTheoValue , double* pMtrTheoVolume ,double* pMtrElecValue ,
				              double* pMtrElecVolume , short* pUVEAntenna , double* pPrice1 , double* pPrice2 , short* pEnabled ) ;


EZ_DLL_CALL SetPumpPropertiesExMT(CEZCLProcess* pCLProcess , LONG ID , LONG Number, BSTR Name, short PhysicalNumber, short Side, short Address, short PriceLevel1,
						        short PriceLevel2, short PriceDspFormat, short VolumeDspFormat, short ValueDspFormat, short Type, 
						        LONG PortID, LONG AttendantID, short AuthMode, short StackMode, short PrepayAllowed, short PreauthAllowed , 
								LONG SlotZigBeeID , LONG MuxSlotZigBeeID , short PriceControl , short HasPreset ) ;
EZ_DLL_CALL GetPumpPropertiesExMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName, short* pPhysicalNumber, short* pSide, short* pAddress, short* pPriceLevel1,
						      short* pPriceLevel2, short* pPriceDspFormat, short* pVolumeDspFormat, short* pValueDspFormat, short* pType, 
						      LONG* pPortID, LONG* pAttendantID, short* pAuthMode, short* pStackMode, short* pPrepayAllowed, short* pPreauthAllowed ,
							  LONG* pSlotZigBeeID , LONG* pMuxSlotZigBeeID , short* pPriceControl , short* pHasPreset) ;
EZ_DLL_CALL GetSerialNoMT(CEZCLProcess* pCLProcess ,  LONG ID , PBSTR pSerialNo ) ; 
EZ_DLL_CALL GetDeviceDetailsMT(CEZCLProcess* pCLProcess ,  LONG ID , LONG ZBID , PBSTR pSerialNo , PBSTR pBootVersion , PBSTR pFirmwareVersion ) ;
EZ_DLL_CALL ResetDeviceMT(CEZCLProcess* pCLProcess ,  LONG ID , LONG ZBID ) ;
EZ_DLL_CALL RequestVersionMT(CEZCLProcess* pCLProcess ,  LONG ID , LONG ZBID ) ;
EZ_DLL_CALL ZBRegisterInterestMT(CEZCLProcess* pCLProcess ,  LONG ID , LONG ZBID ) ; 
EZ_DLL_CALL ZBExceptionRegisterInterestMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL ZBHeartBeatRegisterInterestMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL ZBSendMT(CEZCLProcess* pCLProcess ,  LONG ID , LONG ZBID, __int64 ZBAddress, short MsgType , BSTR TxMsg ) ; 
EZ_DLL_CALL GetDeviceDetailsMT(CEZCLProcess* pCLProcess ,  LONG ID , LONG ZBID , PBSTR pSerialNo , PBSTR pBootVersion , PBSTR pFirmwareVersion ) ;
EZ_DLL_CALL SetZBCoordPanMT(CEZCLProcess* pCLProcess ,  LONG ID , __int64 Pan ) ;
EZ_DLL_CALL GetZBCoordPanMT(CEZCLProcess* pCLProcess ,  LONG ID ) ;
EZ_DLL_CALL SetHoseETotalsMT(CEZCLProcess* pCLProcess ,  LONG ID , double Volume , double Value ) ;
EZ_DLL_CALL GetNextZBStatusEventMT(CEZCLProcess* pCLProcess , LONG* pPortID , LONG* pZBID , __int64* pZBAddress, short* pCondition , short* pCount , short* pStrength ) ;
EZ_DLL_CALL GetNextZBPanIDEventMT(CEZCLProcess* pCLProcess , LONG* pPortID , __int64* pZBPanID ) ;
EZ_DLL_CALL GetNextZeroDeliveryEventMT(CEZCLProcess* pCLProcess ,  LONG* pPumpID , LONG* pPumpNumber , LONG* pHoseID , LONG* pHoseNumber ) ;
EZ_DLL_CALL SetIOPinMT(CEZCLProcess* pCLProcess ,  LONG ID , LONG ZBID , short Slot , short IOPin , short Value ) ;
EZ_DLL_CALL SetHosePricesMT(CEZCLProcess* pCLProcess ,  LONG ID , short DurationType , short PriceType , double Price1 , double Price2 ) ;
EZ_DLL_CALL SetHosePricesExMT( CEZCLProcess* pCLProcess , LONG ID , short DurationType , short PriceType , double Price1 , double Price2 , double Price3 , double Price4) ;
EZ_DLL_CALL GetHosePricesMT( CEZCLProcess* pCLProcess , LONG ID , short* pDurationType , short* pPriceType , double* pPrice1 , double* pPrice2 ) ;
EZ_DLL_CALL GetHosePricesExMT( CEZCLProcess* pCLProcess , LONG ID , short* pDurationType , short* pPriceType , double* pPrice1 , double* pPrice2 , double* pPrice3 , double* pPrice4 ) ;

EZ_DLL_CALL SetPumpDefaultPriceLevelMT(CEZCLProcess* pCLProcess ,  LONG ID , short Level ) ;
EZ_DLL_CALL SetDateTimeMT( CEZCLProcess* pCLProcess , DATE DateTime ) ;
EZ_DLL_CALL GetDateTimeMT( CEZCLProcess* pCLProcess , DATE* pDateTime ) ;
EZ_DLL_CALL GetNextZBCmdEventMT(CEZCLProcess* pCLProcess , LONG* pPortID , LONG* pZBID , __int64* pZBAddress, PBSTR pRxMsg ) ;
EZ_DLL_CALL GetNextZBRawEventMT(CEZCLProcess* pCLProcess , LONG* pPortID , LONG* pZBID , __int64* pZBAddress, PBSTR pRxMsg ) ;
EZ_DLL_CALL GetNextZB2GStatusEventMT( CEZCLProcess* pCLProcess , LONG* pPortID , __int64* pZBAddress, short* pLQI , short* pRSSI , __int64*  pParZBAddress, short* pZBChannel , short* pMemBlocks , short* pMemFree , short* pDeviceType ) ;
EZ_DLL_CALL ZBSendRawMT(CEZCLProcess* pCLProcess ,  LONG ID , LONG ZBID , __int64 ZBAddress , BSTR TxMsg ) ;
EZ_DLL_CALL ZBSendCmdMT(CEZCLProcess* pCLProcess ,LONG ID , LONG ZBID , __int64 ZBAddress , BSTR TxMsg ) ;
EZ_DLL_CALL ZBCmdRegisterInterestMT(CEZCLProcess* pCLProcess , LONG ID , LONG ZBID ) ;
EZ_DLL_CALL ZBRawRegisterInterestMT(CEZCLProcess* pCLProcess , LONG ID , LONG ZBID ) ;
EZ_DLL_CALL GetZB2GConfigMT(CEZCLProcess* pCLProcess , LONG ID , __int64* pPanID , LONG* pChannels , __int64* pKeyA , __int64* pKeyB ) ;
EZ_DLL_CALL ScheduleBeepMT( CEZCLProcess* pCLProcess , LONG ID , short Pitch1 , short Duration1 , short Pitch2 , short Duration2, short Pitch3 , short Duration3, short Pitch4 , short Duration4, short Pitch5 , short Duration5 ) ;
EZ_DLL_CALL FlashLEDSMT( CEZCLProcess* pCLProcess , LONG ID , short PeriodMs , short Cycles ) ;
EZ_DLL_CALL EZTermPromptMT( CEZCLProcess* pCLProcess , LONG ID , short PromptType , short PromptID , short Priority , short Font , short DisplayPars ,  short EnabledKeys , short MinimumDigits , short MaximumDigits , short Timeout , short X , short Y , short Intensity , BSTR Text ) ; 

EZ_DLL_CALL GetLogEventCountMT( CEZCLProcess* pCLProcess , LONG* pCount , short DeviceType , LONG DeviceID , short EventLevel , short EventType ,LONG  ClearedBy ,LONG  AckedBy)  ;
EZ_DLL_CALL GetLogEventByOrdinalMT( CEZCLProcess* pCLProcess , LONG Index , LONG* pID , short DeviceType , LONG DeviceID , short EventLevel , short EventType ,LONG  ClearedBy ,LONG  AckedBy) ;
EZ_DLL_CALL GetLogEventCountExMT(CEZCLProcess* pCLProcess, LONG* pCount, short DeviceType, LONG DeviceID, short EventLevel, short EventType, LONG  ClearedBy, LONG  AckedBy, DATE StartDT, DATE EndDT);
EZ_DLL_CALL GetLogEventByOrdinalExMT(CEZCLProcess* pCLProcess, LONG Index, LONG* pID, short DeviceType, LONG DeviceID, short EventLevel, short EventType, LONG  ClearedBy, LONG  AckedBy, DATE StartDT, DATE EndDT);
EZ_DLL_CALL GetLogEventPropertiesMT(CEZCLProcess* pCLProcess , LONG ID , short* pDeviceType , LONG* pDeviceID , LONG* pDeviceNumber ,	PBSTR pDeviceName , short* pEventLevel ,
									short* pEventType , PBSTR pEventDesc , DATE* pGeneratedDT , DATE* pClearedDT , LONG* pClearedBy , LONG* pAckedBy , double* pVolume ,
									double* pValue , double* pProductVolume , double* pProductLevel , double* pWaterLevel , double* pTemperature );
EZ_DLL_CALL SetLogEventPropertiesMT(CEZCLProcess* pCLProcess , LONG ID , short DeviceType , LONG DeviceID , LONG DeviceNumber , BSTR DeviceName , short EventLevel ,
									short EventType , BSTR  EventDesc , DATE GeneratedDT , DATE ClearedDT , LONG  ClearedBy , LONG  AckedBy , double  Volume ,
									double  Value , double  ProductVolume ,	double  ProductLevel , double  WaterLevel , double  Temperature  );
EZ_DLL_CALL DeleteLogEventMT( CEZCLProcess* pCLProcess , LONG ID ) ;
EZ_DLL_CALL GetNextLogEventEventMT( CEZCLProcess* pCLProcess , LONG* pLogEventID , short* pDeviceType , LONG* pDeviceID , LONG* pDeviceNumber ,	PBSTR pDeviceName , short* pEventLevel ,
								     short* pEventType , PBSTR pEventDesc , DATE* pGeneratedDT , DATE* pClearedDT , LONG* pClearedBy , LONG* pAckedBy , double* pVolume ,
								     double* pValue , double* pProductVolume , double* pProductLevel , double* pWaterLevel , double* pTemperature) ;
EZ_DLL_CALL ClearLogEventMT( CEZCLProcess* pCLProcess , LONG ID , LONG ClientID ) ;
EZ_DLL_CALL AckLogEventMT( CEZCLProcess* pCLProcess , LONG ID , LONG ClientID ) ;
EZ_DLL_CALL AckMVCLogEventMT(CEZCLProcess* pCLProcess, LONG ID) ;


EZ_DLL_CALL GetSensorsCountMT( CEZCLProcess* pCLProcess , LONG* pCount ) ;
EZ_DLL_CALL GetSensorByNumberMT( CEZCLProcess* pCLProcess , LONG Number , LONG* pID ) ;
EZ_DLL_CALL GetSensorByNameMT( CEZCLProcess* pCLProcess , BSTR Name , LONG* pID ) ;




EZ_DLL_CALL GetSensorByOrdinalMT( CEZCLProcess* pCLProcess , LONG Index , LONG* pID ) ;
EZ_DLL_CALL GetSensorPropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName , LONG* pPortID , short* pType , short* pAddress , short* pSensorNo )  ;
EZ_DLL_CALL SetSensorPropertiesMT(CEZCLProcess* pCLProcess , LONG ID , LONG Number, BSTR Name , LONG PortID , short Type , short Address , short SensorNo )  ;
EZ_DLL_CALL GetSensorPropertiesExMT(CEZCLProcess* pCLProcess , LONG ID , LONG* pNumber, PBSTR pName , LONG* pPortID , short* pType , short* pAddress , short* pSensorNo , LONG* pSlotZigBeeID , LONG* pSensorSerialNo)  ;
EZ_DLL_CALL SetSensorPropertiesExMT(CEZCLProcess* pCLProcess , LONG ID , LONG Number, BSTR Name , LONG PortID , short Type , short Address , short SensorNo , LONG SlotZigBeeID , LONG SensorSerialNo) ;
EZ_DLL_CALL SetSensorStatusMT(CEZCLProcess* pCLProcess , LONG ID , short State , short IsResponding )  ;
EZ_DLL_CALL GetSensorStatusMT(CEZCLProcess* pCLProcess , LONG ID , short* pState , short* pIsResponding) ; 
EZ_DLL_CALL AddSensorMT(CEZCLProcess* pCLProcess , LONG* pID, LONG* pNumber, BSTR Name , LONG PortID , short Type , short Address , short SensorNo , LONG SlotZigBeeID , LONG SensorSerialNo ) ;
EZ_DLL_CALL DeleteSensorMT( CEZCLProcess* pCLProcess , LONG ID ) ;

EZ_DLL_CALL SetLogPathMT(CEZCLProcess* pCLProcess, BSTR Path);
EZ_DLL_CALL LogMT(CEZCLProcess* pCLProcess, BSTR Text);
EZ_DLL_CALL SetClientTypeMT( CEZCLProcess* pCLProcess, LONG ClientKey ) ; 
EZ_DLL_CALL GetNextSaleItemEventMT(CEZCLProcess* pCLProcess,
									LONG* pSaleItemID, LONG* pProductID, LONG* pProductNumber, PBSTR pProductName, __int64* pProductTag, LONG* pProductGroup, PBSTR pProductGroupName, PBSTR pBarcode,
									LONG* pPumpID, LONG* pPumpNumber, PBSTR pPumpName,
									LONG* pAttendantID, LONG* pAttendantNumber, PBSTR pAttendantName, __int64* pAttendantTag,
									LONG* pCardClientID, LONG* pCardClientNumber, PBSTR pCardClientName, __int64* pCardClientTag,
									short* pPriceLevel, double* pPrice, double* pQuantity, DATE* pAddedDT, DATE* pClearedDT,
									LONG* pLockedBy, LONG* pClearedBy, short* pLoggedDB, short* pLoggedVolumetric,
									PBSTR pPlate, PBSTR pDriverID, PBSTR pExtTransactionID, PBSTR pAuthID, short* pAuthType);

EZ_DLL_CALL  GetNextEZOdoEventMT(CEZCLProcess* pCLProcess, LONG* pPortID , __int64* pZBAddress, short* pLQI , short* pRSSI , __int64* pParZBAddress , short* pZBChannel , short* pMemBlocks , short* pMemFree , short* pDeviceType,
  							  LONG* pClientID , PBSTR pClientName , __int64* pClientTag , 
								__int64* pOdo1, LONG* pFactor1, short* pLevel1, 
								__int64* pOdo2, LONG* pFactor2, short* pLevel2, 
								__int64* pTag1, __int64* pTag2, __int64* pTag3, __int64* pTag4, short* pFuelTypes, PBSTR pPlate);

EZ_DLL_CALL GetNextEZTermPromptEventMT( CEZCLProcess* pCLProcess , LONG* pPumpID , short* pPromptID , short* pPromptResult , PBSTR pInput ) ;



EZ_DLL_CALL GetProductByNumberMT(CEZCLProcess* pCLProcess, LONG Number, LONG* pID);
EZ_DLL_CALL GetProductByNameMT(CEZCLProcess* pCLProcess, BSTR Name, LONG* pID);
EZ_DLL_CALL GetProductPropertiesMT(CEZCLProcess* pCLProcess, LONG ID, LONG* pNumber, PBSTR pName, PBSTR pTag, short* pEnabled, PBSTR pShortName, PBSTR pBarcode, double* pPrice1, double* pPrice2, LONG* pProductGroup);
EZ_DLL_CALL SetProductPropertiesMT(CEZCLProcess* pCLProcess, LONG ID, LONG Number, BSTR Name, BSTR Tag, short Enabled, BSTR ShortName, BSTR Barcode, double Price1, double Price2, LONG ProductGroup);
EZ_DLL_CALL GetProductPropertiesExMT(CEZCLProcess* pCLProcess, LONG ID, LONG* pNumber, PBSTR pName, PBSTR pTag, short* pEnabled, PBSTR pShortName, PBSTR pBarcode, LONG* pQuickCode, double* pPrice1, double* pPrice2, double* pPrice3, double* pPrice4, LONG* pProductGroup);
EZ_DLL_CALL SetProductPropertiesExMT(CEZCLProcess* pCLProcess, LONG ID, LONG Number, BSTR Name, BSTR Tag, short Enabled, BSTR ShortName, BSTR Barcode, LONG QuickCode, double Price1, double Price2, double Price3, double Price4, LONG ProductGroup) ;
EZ_DLL_CALL GetProductPropertiesEx2MT(CEZCLProcess* pCLProcess, LONG ID, LONG* pNumber, PBSTR pName, PBSTR pTag, short* pEnabled, PBSTR pShortName, PBSTR pBarcode, LONG* pQuickCode, double* pPrice1, double* pPrice2, double* pPrice3, double* pPrice4, LONG* pProductGroup, DATE* pAddedDT, DATE* pUpdatedDT ) ;

EZ_DLL_CALL AddProductMT(CEZCLProcess* pCLProcess, LONG* pID, LONG* pNumber, BSTR Name, BSTR Tag, short Enabled, BSTR ShortName, BSTR Barcode, LONG QuickCode, double Price1, double Price2, double Price3, double Price4, LONG ProductGroup) ;
EZ_DLL_CALL GetLastProductUpdatedMT(CEZCLProcess* pCLProcess, LONG* pID , DATE* pDate );
EZ_DLL_CALL DeleteProductMT(CEZCLProcess* pCLProcess, LONG ID);
EZ_DLL_CALL GetProductsCountMT(CEZCLProcess* pCLProcess, LONG* pCount, LONG Number, BSTR Name, BSTR ShortName, BSTR Tag, BSTR Barcode, LONG ProductGroup);
EZ_DLL_CALL GetProductByOrdinalMT(CEZCLProcess* pCLProcess, LONG Index, LONG* pID, LONG Number, BSTR Name, BSTR ShortName, BSTR Tag, BSTR Barcode, LONG ProductGroup);

EZ_DLL_CALL GetProductsCountExMT(CEZCLProcess* pCLProcess, LONG* pCount, LONG Number, BSTR Name, BSTR ShortName, BSTR Tag, BSTR Barcode, LONG QuickCode, LONG ProductGroup);
EZ_DLL_CALL GetProductByOrdinalExMT(CEZCLProcess* pCLProcess, LONG Index, LONG* pID, LONG Number, BSTR Name, BSTR ShortName, BSTR Tag, BSTR Barcode, LONG QuickCode, LONG ProductGroup);

EZ_DLL_CALL GetSaleItemPropertiesMT(CEZCLProcess* pCLProcess, LONG ID, LONG* pProductID, LONG* pPumpID, LONG* pAttendantID, LONG* pCardClientID, short* pPriceLevel, double* pPrice,
	double* pQuantity, DATE* pAddedDT, DATE* pClearedDT, LONG* pLockedBy, LONG* pClearedBy, short* pLoggedDB, short* pLoggedVolumetric,
	PBSTR pPlate, PBSTR pDriverID, PBSTR pExtTransactionID, PBSTR pAuthID, short* pAuthType);

EZ_DLL_CALL SetSaleItemPropertiesMT(CEZCLProcess* pCLProcess, LONG ID, LONG ProductID, LONG PumpID, LONG AttendantID, LONG CardClientID, short PriceLevel, double Price,
	double Quantity, DATE AddedDT, DATE ClearedDT, LONG LockedBy, LONG ClearedBy, short LoggedDB, short LoggedVolumetric,
	BSTR Plate, BSTR DriverID, BSTR ExtTransactionID, BSTR AuthID, short AuthType);

EZ_DLL_CALL AddSaleItemMT(CEZCLProcess* pCLProcess, LONG* pID, LONG ProductID, LONG PumpID, LONG AttendantID, LONG CardClientID, short PriceLevel, double Price,
	double Quantity, DATE AddedDT, DATE ClearedDT, LONG LockedBy, LONG ClearedBy, short LoggedDB, short LoggedVolumetric,
	BSTR Plate, BSTR DriverID, BSTR ExtTransactionID, BSTR AuthID, short AuthType, __int64 CardClientTag ) ;		  
	
EZ_DLL_CALL AddSaleItemMT(CEZCLProcess* pCLProcess, LONG* pID, LONG ProductID, LONG PumpID, LONG AttendantID, LONG CardClientID, short PriceLevel, double Price,
	double Quantity, DATE AddedDT, DATE ClearedDT, LONG LockedBy, LONG ClearedBy, short LoggedDB, short LoggedVolumetric,
	BSTR Plate, BSTR DriverID, BSTR ExtTransactionID, BSTR AuthID, short AuthType, __int64 CardClientTag ) ;
	

EZ_DLL_CALL DeleteSaleItemMT(CEZCLProcess* pCLProcess, LONG ID);
EZ_DLL_CALL GetSaleItemsCountMT(CEZCLProcess* pCLProcess, LONG* pCount, LONG ProductID, LONG ProductNumber, LONG PumpID, LONG PumpNumber, LONG AttendantID, LONG AttendantNumber, __int64 AttendantTag, LONG CardClientID, LONG CardClientNumber, __int64 CardClientTag, LONG LockedBy, LONG ClearedBy, short LoggedDB, short LoggedVolumetric);
EZ_DLL_CALL GetSaleItemByOrdinalMT(CEZCLProcess* pCLProcess, LONG Index, LONG* pID, LONG ProductID, LONG ProductNumber, LONG PumpID, LONG PumpNumber, LONG AttendantID, LONG AttendantNumber, __int64 AttendantTag, LONG CardClientID, LONG CardClientNumber, __int64 CardClientTag, LONG LockedBy, LONG ClearedBy, short LoggedDB, short LoggedVolumetric);
EZ_DLL_CALL GetSaleItemsCountExMT(CEZCLProcess* pCLProcess, LONG* pCount, LONG ProductID, LONG ProductNumber, LONG PumpID, LONG PumpNumber, LONG AttendantID, LONG AttendantNumber, __int64 AttendantTag, LONG CardClientID, LONG CardClientNumber, __int64 CardClientTag, LONG LockedBy, LONG ClearedBy, short LoggedDB, short LoggedVolumetric, DATE StartDT, DATE EndDT);
EZ_DLL_CALL GetSaleItemByOrdinalExMT(CEZCLProcess* pCLProcess, LONG Index, LONG* pID, LONG ProductID, LONG ProductNumber, LONG PumpID, LONG PumpNumber, LONG AttendantID, LONG AttendantNumber, __int64 AttendantTag, LONG CardClientID, LONG CardClientNumber, __int64 CardClientTag, LONG LockedBy, LONG ClearedBy, short LoggedDB, short LoggedVolumetric, DATE StartDT, DATE EndDT);

EZ_DLL_CALL SaleItemLockMT(CEZCLProcess* pCLProcess, LONG ID);
EZ_DLL_CALL SaleItemUnlockMT(CEZCLProcess* pCLProcess, LONG ID);
EZ_DLL_CALL SaleItemClearMT(CEZCLProcess* pCLProcess, LONG ID);
EZ_DLL_CALL SaleItemLockAndClearMT(CEZCLProcess* pCLProcess, LONG ID);
EZ_DLL_CALL SaleItemAckDBLogMT(CEZCLProcess* pCLProcess, LONG ID);
EZ_DLL_CALL SaleItemAckVolLogMT(CEZCLProcess* pCLProcess, LONG ID);
EZ_DLL_CALL GetSaleItemSummaryMT(CEZCLProcess* pCLProcess, LONG ID, LONG* pProductID, LONG* pProductNumber, PBSTR pProductName, __int64* pProductTag, LONG* pProductGroup, PBSTR pProductGroupName, PBSTR pBarcode,
	LONG* pPumpID, LONG* pPumpNumber, PBSTR pPumpName,
	LONG* pAttendantID, LONG* pAttendantNumber, PBSTR pAttendantName, __int64* pAttendantTag,
	LONG* pCardClientID, LONG* pCardClientNumber, PBSTR pCardClientName, __int64* pCardClientTag,
	short* pPriceLevel, double* pPrice, double* pQuantity, DATE* pAddedDT, DATE* pClearedDT,
	LONG* pLockedBy, LONG* pClearedBy, short* pLoggedDB, short* pLoggedVolumetric,
	PBSTR pPlate, PBSTR pDriverID, PBSTR pExtTransactionID, PBSTR pAuthID, short* pAuthType);

EZ_DLL_CALL GetPriceSignElementMT(CEZCLProcess* pCLProcess, short Element , short* pElementType , LONG* pLinkID  , short* pDecimals , double* pPrice, short* pState , short* pOnTime, short* pOffTime ) ;
EZ_DLL_CALL SetPriceSignElementMT(CEZCLProcess* pCLProcess, short Element , short ElementType , LONG LinkID , short Decimals  , double Price , short State , short OnTime, short OffTime );
EZ_DLL_CALL GetStappingTableDataMT(CEZCLProcess* pCLProcess, LONG ID, double* pStepSize, double* pDiameter, double* pOffset, double* pCapacity, LONG* pAlarms);
EZ_DLL_CALL SetStappingTableDataMT(CEZCLProcess* pCLProcess, LONG ID, double StepSize, double Diameter, double Offset, double Capacity, LONG Alarms);
EZ_DLL_CALL GetStappingTableElementMT(CEZCLProcess* pCLProcess, LONG ID, LONG Element, short* pPasses, double* pHeight, double* pStartDelta, double* pCurDelta, double* pStartVolume, double* pCurVolume);
EZ_DLL_CALL SetStappingTableElementMT(CEZCLProcess* pCLProcess, LONG ID, LONG Element, short Passes, double StartDelta, double CurDelta);
EZ_DLL_CALL GetTCPIPConfigMT(CEZCLProcess* pCLProcess , PBSTR pIPAddress, PBSTR pNetMask, PBSTR pGateway , PBSTR pDNSServer , short* pDHCP , PBSTR pNetworkName ) ;
EZ_DLL_CALL SetTCPIPConfigMT(CEZCLProcess* pCLProcess , BSTR bIPAddress, BSTR bNetMask, BSTR bGateway , BSTR bDNSServer , short DHCP , BSTR bNetworkName ) ;
EZ_DLL_CALL WDResetMT(CEZCLProcess* pCLProcess ,  LONG ClientID ) ;
EZ_DLL_CALL EZLicenseOPMT(CEZCLProcess* pCLProcess , short OPType , PBSTR pLicenseKey , short* pLicenseMask , short* pState , DATE* pExpiryDate , PBSTR pKeySerialNo , PBSTR pSerialNo ) ;
EZ_DLL_CALL WasReconnectedMT(CEZCLProcess* pCLProcess ) ;

#endif 

