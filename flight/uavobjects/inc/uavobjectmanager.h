/**
 ******************************************************************************
 * @addtogroup UAVObjects OpenPilot UAVObjects
 * @{
 * @addtogroup UAV Object Manager
 * @brief The core UAV Objects functions, most of which are wrappered by
 * autogenerated defines
 * @{
 *
 * @file       uavobjectmanager.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @brief      Include files of the uavobjectlist library
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

#ifndef UAVOBJECTMANAGER_H
#define UAVOBJECTMANAGER_H

#define UAVOBJ_ALL_INSTANCES                   0xFFFF
#define UAVOBJ_MAX_INSTANCES                   1000

/*
 * Shifts and masks used to read/write metadata flags.
 */
#define UAVOBJ_ACCESS_SHIFT                    0
#define UAVOBJ_GCS_ACCESS_SHIFT                1
#define UAVOBJ_TELEMETRY_ACKED_SHIFT           2
#define UAVOBJ_GCS_TELEMETRY_ACKED_SHIFT       3
#define UAVOBJ_TELEMETRY_UPDATE_MODE_SHIFT     4
#define UAVOBJ_GCS_TELEMETRY_UPDATE_MODE_SHIFT 6
#define UAVOBJ_LOGGING_UPDATE_MODE_SHIFT       8
#define UAVOBJ_UPDATE_MODE_MASK                0x3

typedef void *UAVObjHandle;

#define MetaObjectId(id) ((id) + 1)

/**
 * Object update mode, used by multiple modules (e.g. telemetry and logger)
 */
typedef enum {
    UPDATEMODE_MANUAL    = 0, /** Manually update object, by calling the updated() function */
    UPDATEMODE_PERIODIC  = 1, /** Automatically update object at periodic intervals */
    UPDATEMODE_ONCHANGE  = 2, /** Only update object when its data changes */
    UPDATEMODE_THROTTLED = 3 /** Object is updated on change, but not more often than the interval time */
} UAVObjUpdateMode;

/**
 * Object metadata, each object has a meta object that holds its metadata. The metadata define
 * properties for each object and can be used by multiple modules (e.g. telemetry and logger)
 *
 * The object metadata flags are packed into a single 16 bit integer.
 * The bits in the flag field are defined as:
 *
 *   Bit(s)  Name                     Meaning
 *   ------  ----                     -------
 *      0    access                   Defines the access level for the local transactions (readonly=1 and readwrite=0)
 *      1    gcsAccess                Defines the access level for the local GCS transactions (readonly=1 and readwrite=0), not used in the flight s/w
 *      2    telemetryAcked           Defines if an ack is required for the transactions of this object (1:acked, 0:not acked)
 *      3    gcsTelemetryAcked        Defines if an ack is required for the transactions of this object (1:acked, 0:not acked)
 *    4-5    telemetryUpdateMode      Update mode used by the telemetry module (UAVObjUpdateMode)
 *    6-7    gcsTelemetryUpdateMode   Update mode used by the GCS (UAVObjUpdateMode)
 *    8-9    loggingUpdateMode        Update mode used by the logging module (UAVObjUpdateMode)
 */
typedef struct {
    uint16_t flags; /** Defines flags for update and logging modes and whether an update should be ACK'd (bits defined above) */
    uint16_t telemetryUpdatePeriod; /** Update period used by the telemetry module (only if telemetry mode is PERIODIC) */
    uint16_t gcsTelemetryUpdatePeriod; /** Update period used by the GCS (only if telemetry mode is PERIODIC) */
    uint16_t loggingUpdatePeriod; /** Update period used by the logging module (only if logging mode is PERIODIC) */
} __attribute__((packed)) UAVObjMetadata;

/**
 * Event types generated by the objects.
 */
typedef enum {
    EV_NONE     = 0x00, /** No event */
    EV_UNPACKED = 0x01, /** Object data updated by unpacking */
    EV_UPDATED  = 0x02, /** Object data updated by changing the data structure */
    EV_UPDATED_MANUAL   = 0x04, /** Object update event manually generated */
    EV_UPDATED_PERIODIC = 0x08, /** Object update from periodic event */
    EV_LOGGING_MANUAL   = 0x10, /** Object update event manually generated */
    EV_LOGGING_PERIODIC = 0x20, /** Object update from periodic event */
    EV_UPDATE_REQ = 0x40 /** Request to update object data */
} UAVObjEventType;

/**
 * Helper macros for event masks
 */
#define EV_MASK_ALL         0
#define EV_MASK_ALL_UPDATES (EV_UNPACKED | EV_UPDATED | EV_UPDATED_MANUAL | EV_UPDATED_PERIODIC | EV_LOGGING_MANUAL | EV_LOGGING_PERIODIC)

/**
 * Access types
 */
typedef enum {
    ACCESS_READWRITE = 0,
    ACCESS_READONLY  = 1
} UAVObjAccessType;

/**
 * Event message, this structure is sent in the event queue each time an event is generated
 */
typedef struct {
    UAVObjHandle    obj;
    uint16_t        instId;
    UAVObjEventType event;
} UAVObjEvent;

/**
 * Event callback, this function is called when an event is invoked. The function
 * will be executed in the event task. The ev parameter should be copied if needed
 * after the function returns.
 */
typedef void (*UAVObjEventCallback)(UAVObjEvent *ev);

/**
 * Callback used to initialize the object fields to their default values.
 */
typedef void (*UAVObjInitializeCallback)(UAVObjHandle obj_handle, uint16_t instId);

/**
 * Event manager statistics
 */
typedef struct {
    uint32_t eventQueueErrors;
    uint32_t eventCallbackErrors;
    uint32_t lastCallbackErrorID;
    uint32_t lastQueueErrorID;
} UAVObjStats;

int32_t UAVObjInitialize();
void UAVObjGetStats(UAVObjStats *statsOut);
void UAVObjClearStats();
UAVObjHandle UAVObjRegister(uint32_t id, bool isSingleInstance, bool isSettings, bool isPriority, uint32_t num_bytes, UAVObjInitializeCallback initCb);
UAVObjHandle UAVObjGetByID(uint32_t id);
uint32_t UAVObjGetID(UAVObjHandle obj);
uint32_t UAVObjGetNumBytes(UAVObjHandle obj);
uint16_t UAVObjGetNumInstances(UAVObjHandle obj);
UAVObjHandle UAVObjGetLinkedObj(UAVObjHandle obj);
uint16_t UAVObjCreateInstance(UAVObjHandle obj_handle, UAVObjInitializeCallback initCb);
bool UAVObjIsSingleInstance(UAVObjHandle obj);
bool UAVObjIsMetaobject(UAVObjHandle obj);
bool UAVObjIsSettings(UAVObjHandle obj);
bool UAVObjIsPriority(UAVObjHandle obj);
int32_t UAVObjUnpack(UAVObjHandle obj_handle, uint16_t instId, const uint8_t *dataIn);
int32_t UAVObjPack(UAVObjHandle obj_handle, uint16_t instId, uint8_t *dataOut);
uint8_t UAVObjUpdateCRC(UAVObjHandle obj_handle, uint16_t instId, uint8_t crc);
int32_t UAVObjSave(UAVObjHandle obj_handle, uint16_t instId);
int32_t UAVObjLoad(UAVObjHandle obj_handle, uint16_t instId);
int32_t UAVObjDelete(UAVObjHandle obj_handle, uint16_t instId);
#if defined(PIOS_INCLUDE_SDCARD)
int32_t UAVObjSaveToFile(UAVObjHandle obj_handle, uint16_t instId, FILEINFO *file);
int32_t UAVObjLoadFromFile(UAVObjHandle obj_handle, FILEINFO *file);
#endif
int32_t UAVObjSaveSettings();
int32_t UAVObjLoadSettings();
int32_t UAVObjDeleteSettings();
int32_t UAVObjSaveMetaobjects();
int32_t UAVObjLoadMetaobjects();
int32_t UAVObjDeleteMetaobjects();
int32_t UAVObjSetData(UAVObjHandle obj_handle, const void *dataIn);
int32_t UAVObjSetDataField(UAVObjHandle obj_handle, const void *dataIn, uint32_t offset, uint32_t size);
int32_t UAVObjGetData(UAVObjHandle obj_handle, void *dataOut);
int32_t UAVObjGetDataField(UAVObjHandle obj_handle, void *dataOut, uint32_t offset, uint32_t size);
int32_t UAVObjSetInstanceData(UAVObjHandle obj_handle, uint16_t instId, const void *dataIn);
int32_t UAVObjSetInstanceDataField(UAVObjHandle obj_handle, uint16_t instId, const void *dataIn, uint32_t offset, uint32_t size);
int32_t UAVObjGetInstanceData(UAVObjHandle obj_handle, uint16_t instId, void *dataOut);
int32_t UAVObjGetInstanceDataField(UAVObjHandle obj_handle, uint16_t instId, void *dataOut, uint32_t offset, uint32_t size);
int32_t UAVObjSetMetadata(UAVObjHandle obj_handle, const UAVObjMetadata *dataIn);
int32_t UAVObjGetMetadata(UAVObjHandle obj_handle, UAVObjMetadata *dataOut);
uint8_t UAVObjGetMetadataAccess(const UAVObjMetadata *dataOut);
UAVObjAccessType UAVObjGetAccess(const UAVObjMetadata *dataOut);
void UAVObjSetAccess(UAVObjMetadata *dataOut, UAVObjAccessType mode);
UAVObjAccessType UAVObjGetGcsAccess(const UAVObjMetadata *dataOut);
void UAVObjSetGcsAccess(UAVObjMetadata *dataOut, UAVObjAccessType mode);
uint8_t UAVObjGetTelemetryAcked(const UAVObjMetadata *dataOut);
void UAVObjSetTelemetryAcked(UAVObjMetadata *dataOut, uint8_t val);
uint8_t UAVObjGetGcsTelemetryAcked(const UAVObjMetadata *dataOut);
void UAVObjSetGcsTelemetryAcked(UAVObjMetadata *dataOut, uint8_t val);
UAVObjUpdateMode UAVObjGetTelemetryUpdateMode(const UAVObjMetadata *dataOut);
void UAVObjSetTelemetryUpdateMode(UAVObjMetadata *dataOut, UAVObjUpdateMode val);
UAVObjUpdateMode UAVObjGetGcsTelemetryUpdateMode(const UAVObjMetadata *dataOut);
void UAVObjSetTelemetryGcsUpdateMode(UAVObjMetadata *dataOut, UAVObjUpdateMode val);
UAVObjUpdateMode UAVObjGetLoggingUpdateMode(const UAVObjMetadata *dataOut);
void UAVObjSetLoggingUpdateMode(UAVObjMetadata *dataOut, UAVObjUpdateMode val);
int8_t UAVObjReadOnly(UAVObjHandle obj);
int32_t UAVObjConnectQueue(UAVObjHandle obj_handle, xQueueHandle queue, uint8_t eventMask);
int32_t UAVObjDisconnectQueue(UAVObjHandle obj_handle, xQueueHandle queue);
int32_t UAVObjConnectCallback(UAVObjHandle obj_handle, UAVObjEventCallback cb, uint8_t eventMask);
int32_t UAVObjDisconnectCallback(UAVObjHandle obj_handle, UAVObjEventCallback cb);
void UAVObjRequestUpdate(UAVObjHandle obj);
void UAVObjRequestInstanceUpdate(UAVObjHandle obj_handle, uint16_t instId);
void UAVObjUpdated(UAVObjHandle obj);
void UAVObjInstanceUpdated(UAVObjHandle obj_handle, uint16_t instId);
void UAVObjLogging(UAVObjHandle obj);
void UAVObjInstanceLogging(UAVObjHandle obj_handle, uint16_t instId);
void UAVObjIterate(void (*iterator)(UAVObjHandle obj));
void UAVObjInstanceWriteToLog(UAVObjHandle obj_handle, uint16_t instId);

#endif // UAVOBJECTMANAGER_H

/**
 * @}
 * @}
 */
