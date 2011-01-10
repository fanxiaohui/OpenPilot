/**
 ******************************************************************************
 * @addtogroup UAVObjects OpenPilot UAVObjects
 * @{ 
 * @addtogroup ActuatorSettings ActuatorSettings 
 * @brief Settings for the @ref ActuatorModule that controls the channel assignments for the mixer based on AircraftType
 *
 * Autogenerated files and functions for ActuatorSettings Object
 
 * @{ 
 *
 * @file       actuatorsettings.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @brief      Implementation of the ActuatorSettings object. This file has been 
 *             automatically generated by the UAVObjectGenerator.
 * 
 * @note       Object definition file: actuatorsettings.xml. 
 *             This is an automatically generated file.
 *             DO NOT modify manually.
 *
 * @see        The GNU Public License (GPL) Version 3
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef ACTUATORSETTINGS_H
#define ACTUATORSETTINGS_H

// Object constants
#define ACTUATORSETTINGS_OBJID 844831578U
#define ACTUATORSETTINGS_NAME "ActuatorSettings"
#define ACTUATORSETTINGS_METANAME "ActuatorSettingsMeta"
#define ACTUATORSETTINGS_ISSINGLEINST 1
#define ACTUATORSETTINGS_ISSETTINGS 1
#define ACTUATORSETTINGS_NUMBYTES sizeof(ActuatorSettingsData)

// Object access macros
/**
 * @function ActuatorSettingsGet(dataOut)
 * @brief Populate a ActuatorSettingsData object
 * @param[out] dataOut 
 */
#define ActuatorSettingsGet(dataOut) UAVObjGetData(ActuatorSettingsHandle(), dataOut)
#define ActuatorSettingsSet(dataIn) UAVObjSetData(ActuatorSettingsHandle(), dataIn)
#define ActuatorSettingsInstGet(instId, dataOut) UAVObjGetInstanceData(ActuatorSettingsHandle(), instId, dataOut)
#define ActuatorSettingsInstSet(instId, dataIn) UAVObjSetInstanceData(ActuatorSettingsHandle(), instId, dataIn)
#define ActuatorSettingsConnectQueue(queue) UAVObjConnectQueue(ActuatorSettingsHandle(), queue, EV_MASK_ALL_UPDATES)
#define ActuatorSettingsConnectCallback(cb) UAVObjConnectCallback(ActuatorSettingsHandle(), cb, EV_MASK_ALL_UPDATES)
#define ActuatorSettingsCreateInstance() UAVObjCreateInstance(ActuatorSettingsHandle())
#define ActuatorSettingsRequestUpdate() UAVObjRequestUpdate(ActuatorSettingsHandle())
#define ActuatorSettingsRequestInstUpdate(instId) UAVObjRequestInstanceUpdate(ActuatorSettingsHandle(), instId)
#define ActuatorSettingsUpdated() UAVObjUpdated(ActuatorSettingsHandle())
#define ActuatorSettingsInstUpdated(instId) UAVObjUpdated(ActuatorSettingsHandle(), instId)
#define ActuatorSettingsGetMetadata(dataOut) UAVObjGetMetadata(ActuatorSettingsHandle(), dataOut)
#define ActuatorSettingsSetMetadata(dataIn) UAVObjSetMetadata(ActuatorSettingsHandle(), dataIn)
#define ActuatorSettingsReadOnly(dataIn) UAVObjReadOnly(ActuatorSettingsHandle())

// Object data
typedef struct {
    uint8_t FixedWingRoll1;
    uint8_t FixedWingRoll2;
    uint8_t FixedWingPitch1;
    uint8_t FixedWingPitch2;
    uint8_t FixedWingYaw;
    uint8_t FixedWingThrottle;
    uint8_t VTOLMotorN;
    uint8_t VTOLMotorNE;
    uint8_t VTOLMotorE;
    uint8_t VTOLMotorSE;
    uint8_t VTOLMotorS;
    uint8_t VTOLMotorSW;
    uint8_t VTOLMotorW;
    uint8_t VTOLMotorNW;
    int16_t ChannelUpdateFreq[2];
    int16_t ChannelMax[8];
    int16_t ChannelNeutral[8];
    int16_t ChannelMin[8];
    uint8_t ChannelType[8];
    uint8_t ChannelAddr[8];

} __attribute__((packed)) ActuatorSettingsData;

// Field information
// Field FixedWingRoll1 information
/* Enumeration options for field FixedWingRoll1 */
typedef enum { ACTUATORSETTINGS_FIXEDWINGROLL1_CHANNEL1=0, ACTUATORSETTINGS_FIXEDWINGROLL1_CHANNEL2=1, ACTUATORSETTINGS_FIXEDWINGROLL1_CHANNEL3=2, ACTUATORSETTINGS_FIXEDWINGROLL1_CHANNEL4=3, ACTUATORSETTINGS_FIXEDWINGROLL1_CHANNEL5=4, ACTUATORSETTINGS_FIXEDWINGROLL1_CHANNEL6=5, ACTUATORSETTINGS_FIXEDWINGROLL1_CHANNEL7=6, ACTUATORSETTINGS_FIXEDWINGROLL1_CHANNEL8=7, ACTUATORSETTINGS_FIXEDWINGROLL1_NONE=8 } ActuatorSettingsFixedWingRoll1Options;
// Field FixedWingRoll2 information
/* Enumeration options for field FixedWingRoll2 */
typedef enum { ACTUATORSETTINGS_FIXEDWINGROLL2_CHANNEL1=0, ACTUATORSETTINGS_FIXEDWINGROLL2_CHANNEL2=1, ACTUATORSETTINGS_FIXEDWINGROLL2_CHANNEL3=2, ACTUATORSETTINGS_FIXEDWINGROLL2_CHANNEL4=3, ACTUATORSETTINGS_FIXEDWINGROLL2_CHANNEL5=4, ACTUATORSETTINGS_FIXEDWINGROLL2_CHANNEL6=5, ACTUATORSETTINGS_FIXEDWINGROLL2_CHANNEL7=6, ACTUATORSETTINGS_FIXEDWINGROLL2_CHANNEL8=7, ACTUATORSETTINGS_FIXEDWINGROLL2_NONE=8 } ActuatorSettingsFixedWingRoll2Options;
// Field FixedWingPitch1 information
/* Enumeration options for field FixedWingPitch1 */
typedef enum { ACTUATORSETTINGS_FIXEDWINGPITCH1_CHANNEL1=0, ACTUATORSETTINGS_FIXEDWINGPITCH1_CHANNEL2=1, ACTUATORSETTINGS_FIXEDWINGPITCH1_CHANNEL3=2, ACTUATORSETTINGS_FIXEDWINGPITCH1_CHANNEL4=3, ACTUATORSETTINGS_FIXEDWINGPITCH1_CHANNEL5=4, ACTUATORSETTINGS_FIXEDWINGPITCH1_CHANNEL6=5, ACTUATORSETTINGS_FIXEDWINGPITCH1_CHANNEL7=6, ACTUATORSETTINGS_FIXEDWINGPITCH1_CHANNEL8=7, ACTUATORSETTINGS_FIXEDWINGPITCH1_NONE=8 } ActuatorSettingsFixedWingPitch1Options;
// Field FixedWingPitch2 information
/* Enumeration options for field FixedWingPitch2 */
typedef enum { ACTUATORSETTINGS_FIXEDWINGPITCH2_CHANNEL1=0, ACTUATORSETTINGS_FIXEDWINGPITCH2_CHANNEL2=1, ACTUATORSETTINGS_FIXEDWINGPITCH2_CHANNEL3=2, ACTUATORSETTINGS_FIXEDWINGPITCH2_CHANNEL4=3, ACTUATORSETTINGS_FIXEDWINGPITCH2_CHANNEL5=4, ACTUATORSETTINGS_FIXEDWINGPITCH2_CHANNEL6=5, ACTUATORSETTINGS_FIXEDWINGPITCH2_CHANNEL7=6, ACTUATORSETTINGS_FIXEDWINGPITCH2_CHANNEL8=7, ACTUATORSETTINGS_FIXEDWINGPITCH2_NONE=8 } ActuatorSettingsFixedWingPitch2Options;
// Field FixedWingYaw information
/* Enumeration options for field FixedWingYaw */
typedef enum { ACTUATORSETTINGS_FIXEDWINGYAW_CHANNEL1=0, ACTUATORSETTINGS_FIXEDWINGYAW_CHANNEL2=1, ACTUATORSETTINGS_FIXEDWINGYAW_CHANNEL3=2, ACTUATORSETTINGS_FIXEDWINGYAW_CHANNEL4=3, ACTUATORSETTINGS_FIXEDWINGYAW_CHANNEL5=4, ACTUATORSETTINGS_FIXEDWINGYAW_CHANNEL6=5, ACTUATORSETTINGS_FIXEDWINGYAW_CHANNEL7=6, ACTUATORSETTINGS_FIXEDWINGYAW_CHANNEL8=7, ACTUATORSETTINGS_FIXEDWINGYAW_NONE=8 } ActuatorSettingsFixedWingYawOptions;
// Field FixedWingThrottle information
/* Enumeration options for field FixedWingThrottle */
typedef enum { ACTUATORSETTINGS_FIXEDWINGTHROTTLE_CHANNEL1=0, ACTUATORSETTINGS_FIXEDWINGTHROTTLE_CHANNEL2=1, ACTUATORSETTINGS_FIXEDWINGTHROTTLE_CHANNEL3=2, ACTUATORSETTINGS_FIXEDWINGTHROTTLE_CHANNEL4=3, ACTUATORSETTINGS_FIXEDWINGTHROTTLE_CHANNEL5=4, ACTUATORSETTINGS_FIXEDWINGTHROTTLE_CHANNEL6=5, ACTUATORSETTINGS_FIXEDWINGTHROTTLE_CHANNEL7=6, ACTUATORSETTINGS_FIXEDWINGTHROTTLE_CHANNEL8=7, ACTUATORSETTINGS_FIXEDWINGTHROTTLE_NONE=8 } ActuatorSettingsFixedWingThrottleOptions;
// Field VTOLMotorN information
/* Enumeration options for field VTOLMotorN */
typedef enum { ACTUATORSETTINGS_VTOLMOTORN_CHANNEL1=0, ACTUATORSETTINGS_VTOLMOTORN_CHANNEL2=1, ACTUATORSETTINGS_VTOLMOTORN_CHANNEL3=2, ACTUATORSETTINGS_VTOLMOTORN_CHANNEL4=3, ACTUATORSETTINGS_VTOLMOTORN_CHANNEL5=4, ACTUATORSETTINGS_VTOLMOTORN_CHANNEL6=5, ACTUATORSETTINGS_VTOLMOTORN_CHANNEL7=6, ACTUATORSETTINGS_VTOLMOTORN_CHANNEL8=7, ACTUATORSETTINGS_VTOLMOTORN_NONE=8 } ActuatorSettingsVTOLMotorNOptions;
// Field VTOLMotorNE information
/* Enumeration options for field VTOLMotorNE */
typedef enum { ACTUATORSETTINGS_VTOLMOTORNE_CHANNEL1=0, ACTUATORSETTINGS_VTOLMOTORNE_CHANNEL2=1, ACTUATORSETTINGS_VTOLMOTORNE_CHANNEL3=2, ACTUATORSETTINGS_VTOLMOTORNE_CHANNEL4=3, ACTUATORSETTINGS_VTOLMOTORNE_CHANNEL5=4, ACTUATORSETTINGS_VTOLMOTORNE_CHANNEL6=5, ACTUATORSETTINGS_VTOLMOTORNE_CHANNEL7=6, ACTUATORSETTINGS_VTOLMOTORNE_CHANNEL8=7, ACTUATORSETTINGS_VTOLMOTORNE_NONE=8 } ActuatorSettingsVTOLMotorNEOptions;
// Field VTOLMotorE information
/* Enumeration options for field VTOLMotorE */
typedef enum { ACTUATORSETTINGS_VTOLMOTORE_CHANNEL1=0, ACTUATORSETTINGS_VTOLMOTORE_CHANNEL2=1, ACTUATORSETTINGS_VTOLMOTORE_CHANNEL3=2, ACTUATORSETTINGS_VTOLMOTORE_CHANNEL4=3, ACTUATORSETTINGS_VTOLMOTORE_CHANNEL5=4, ACTUATORSETTINGS_VTOLMOTORE_CHANNEL6=5, ACTUATORSETTINGS_VTOLMOTORE_CHANNEL7=6, ACTUATORSETTINGS_VTOLMOTORE_CHANNEL8=7, ACTUATORSETTINGS_VTOLMOTORE_NONE=8 } ActuatorSettingsVTOLMotorEOptions;
// Field VTOLMotorSE information
/* Enumeration options for field VTOLMotorSE */
typedef enum { ACTUATORSETTINGS_VTOLMOTORSE_CHANNEL1=0, ACTUATORSETTINGS_VTOLMOTORSE_CHANNEL2=1, ACTUATORSETTINGS_VTOLMOTORSE_CHANNEL3=2, ACTUATORSETTINGS_VTOLMOTORSE_CHANNEL4=3, ACTUATORSETTINGS_VTOLMOTORSE_CHANNEL5=4, ACTUATORSETTINGS_VTOLMOTORSE_CHANNEL6=5, ACTUATORSETTINGS_VTOLMOTORSE_CHANNEL7=6, ACTUATORSETTINGS_VTOLMOTORSE_CHANNEL8=7, ACTUATORSETTINGS_VTOLMOTORSE_NONE=8 } ActuatorSettingsVTOLMotorSEOptions;
// Field VTOLMotorS information
/* Enumeration options for field VTOLMotorS */
typedef enum { ACTUATORSETTINGS_VTOLMOTORS_CHANNEL1=0, ACTUATORSETTINGS_VTOLMOTORS_CHANNEL2=1, ACTUATORSETTINGS_VTOLMOTORS_CHANNEL3=2, ACTUATORSETTINGS_VTOLMOTORS_CHANNEL4=3, ACTUATORSETTINGS_VTOLMOTORS_CHANNEL5=4, ACTUATORSETTINGS_VTOLMOTORS_CHANNEL6=5, ACTUATORSETTINGS_VTOLMOTORS_CHANNEL7=6, ACTUATORSETTINGS_VTOLMOTORS_CHANNEL8=7, ACTUATORSETTINGS_VTOLMOTORS_NONE=8 } ActuatorSettingsVTOLMotorSOptions;
// Field VTOLMotorSW information
/* Enumeration options for field VTOLMotorSW */
typedef enum { ACTUATORSETTINGS_VTOLMOTORSW_CHANNEL1=0, ACTUATORSETTINGS_VTOLMOTORSW_CHANNEL2=1, ACTUATORSETTINGS_VTOLMOTORSW_CHANNEL3=2, ACTUATORSETTINGS_VTOLMOTORSW_CHANNEL4=3, ACTUATORSETTINGS_VTOLMOTORSW_CHANNEL5=4, ACTUATORSETTINGS_VTOLMOTORSW_CHANNEL6=5, ACTUATORSETTINGS_VTOLMOTORSW_CHANNEL7=6, ACTUATORSETTINGS_VTOLMOTORSW_CHANNEL8=7, ACTUATORSETTINGS_VTOLMOTORSW_NONE=8 } ActuatorSettingsVTOLMotorSWOptions;
// Field VTOLMotorW information
/* Enumeration options for field VTOLMotorW */
typedef enum { ACTUATORSETTINGS_VTOLMOTORW_CHANNEL1=0, ACTUATORSETTINGS_VTOLMOTORW_CHANNEL2=1, ACTUATORSETTINGS_VTOLMOTORW_CHANNEL3=2, ACTUATORSETTINGS_VTOLMOTORW_CHANNEL4=3, ACTUATORSETTINGS_VTOLMOTORW_CHANNEL5=4, ACTUATORSETTINGS_VTOLMOTORW_CHANNEL6=5, ACTUATORSETTINGS_VTOLMOTORW_CHANNEL7=6, ACTUATORSETTINGS_VTOLMOTORW_CHANNEL8=7, ACTUATORSETTINGS_VTOLMOTORW_NONE=8 } ActuatorSettingsVTOLMotorWOptions;
// Field VTOLMotorNW information
/* Enumeration options for field VTOLMotorNW */
typedef enum { ACTUATORSETTINGS_VTOLMOTORNW_CHANNEL1=0, ACTUATORSETTINGS_VTOLMOTORNW_CHANNEL2=1, ACTUATORSETTINGS_VTOLMOTORNW_CHANNEL3=2, ACTUATORSETTINGS_VTOLMOTORNW_CHANNEL4=3, ACTUATORSETTINGS_VTOLMOTORNW_CHANNEL5=4, ACTUATORSETTINGS_VTOLMOTORNW_CHANNEL6=5, ACTUATORSETTINGS_VTOLMOTORNW_CHANNEL7=6, ACTUATORSETTINGS_VTOLMOTORNW_CHANNEL8=7, ACTUATORSETTINGS_VTOLMOTORNW_NONE=8 } ActuatorSettingsVTOLMotorNWOptions;
// Field ChannelUpdateFreq information
/* Number of elements for field ChannelUpdateFreq */
#define ACTUATORSETTINGS_CHANNELUPDATEFREQ_NUMELEM 2
// Field ChannelMax information
/* Number of elements for field ChannelMax */
#define ACTUATORSETTINGS_CHANNELMAX_NUMELEM 8
// Field ChannelNeutral information
/* Number of elements for field ChannelNeutral */
#define ACTUATORSETTINGS_CHANNELNEUTRAL_NUMELEM 8
// Field ChannelMin information
/* Number of elements for field ChannelMin */
#define ACTUATORSETTINGS_CHANNELMIN_NUMELEM 8
// Field ChannelType information
/* Enumeration options for field ChannelType */
typedef enum { ACTUATORSETTINGS_CHANNELTYPE_PWM=0, ACTUATORSETTINGS_CHANNELTYPE_MK=1, ACTUATORSETTINGS_CHANNELTYPE_ASTEC4=2 } ActuatorSettingsChannelTypeOptions;
/* Number of elements for field ChannelType */
#define ACTUATORSETTINGS_CHANNELTYPE_NUMELEM 8
// Field ChannelAddr information
/* Number of elements for field ChannelAddr */
#define ACTUATORSETTINGS_CHANNELADDR_NUMELEM 8


// Generic interface functions
int32_t ActuatorSettingsInitialize();
UAVObjHandle ActuatorSettingsHandle();

#endif // ACTUATORSETTINGS_H

/**
 * @}
 * @}
 */
