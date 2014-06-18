/********************************************************
 * DO NOT CHANGE THIS FILE, IT IS GENERATED AUTOMATICALY*
 ********************************************************/

/* Copyright 2008, 2009 Mariano Cerdeiro
 * Copyright 2014, ACSE & CADIEEL
 *      ACSE: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/
 *      CADIEEL: http://www.cadieel.org.ar
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief FreeOSEK Os Generated Internal Configuration Implementation File
 **
 ** \file Os_Internal_Cfg.c
 **
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_Os
 ** @{ */
/** \addtogroup FreeOSEK_Os_Internal
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20090719 v0.1.2 MaCe rename file to Os_
 * 20090128 v0.1.1 MaCe add OSEK_MEMMAP check
 * 20080713 v0.1.0 MaCe initial version
 */

/*==================[inclusions]=============================================*/
#include "Os_Internal.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/
/** \brief InitTask stack */
uint8 StackTaskInitTask[1024];
/** \brief TaskA stack */
uint8 StackTaskTaskA[1024];
/** \brief TaskB stack */
uint8 StackTaskTaskB[1024];
/** \brief TaskC stack */
uint8 StackTaskTaskC[1024];

/** \brief InitTask context */
TaskContextType ContextTaskInitTask;
/** \brief TaskA context */
TaskContextType ContextTaskTaskA;
/** \brief TaskB context */
TaskContextType ContextTaskTaskB;
/** \brief TaskC context */
TaskContextType ContextTaskTaskC;

/** \brief Ready List for Priority 3 */
TaskType ReadyList3[1];

/** \brief Ready List for Priority 2 */
TaskType ReadyList2[1];

/** \brief Ready List for Priority 1 */
TaskType ReadyList1[1];

/** \brief Ready List for Priority 0 */
TaskType ReadyList0[1];

const AlarmType OSEK_ALARMLIST_HardwareCounter[1] = {
	IncrementSWCounter, /* this alarm has to be incremented with this counter */
};

const AlarmType OSEK_ALARMLIST_SoftwareCounter[1] = {
	ActivateTaskC, /* this alarm has to be incremented with this counter */
};


/*==================[external data definition]===============================*/
/* FreeOSEK to configured priority table
 *
 * This table show the relationship between the user selected
 * priorities and the OpenOSE priorities:
 *
 * User P.			Osek P.
 * 10					3
 * 8					2
 * 5					1
 * 1					0
 */

const TaskConstType TasksConst[TASKS_COUNT] = {
	/* Task InitTask */
	{
 		OSEK_TASK_InitTask,	/* task entry point */
		&ContextTaskInitTask, /* pointer to task context */
		StackTaskInitTask, /* pointer stack memory */
		1024, /* stack size */
		0, /* task priority */
		1, /* task max activations */
		{
			0, /* basic task */
			1, /* preemtive task */
			0
		}, /* task const flags */
		0 , /* events mask */
		0 /* resources mask */
	},
	/* Task TaskA */
	{
 		OSEK_TASK_TaskA,	/* task entry point */
		&ContextTaskTaskA, /* pointer to task context */
		StackTaskTaskA, /* pointer stack memory */
		1024, /* stack size */
		1, /* task priority */
		1, /* task max activations */
		{
			1, /* extended task */
			1, /* preemtive task */
			0
		}, /* task const flags */
		0 | Event1 , /* events mask */
		0 | ( 1 << Res1 ) /* resources mask */
	},
	/* Task TaskB */
	{
 		OSEK_TASK_TaskB,	/* task entry point */
		&ContextTaskTaskB, /* pointer to task context */
		StackTaskTaskB, /* pointer stack memory */
		1024, /* stack size */
		2, /* task priority */
		1, /* task max activations */
		{
			0, /* basic task */
			1, /* preemtive task */
			0
		}, /* task const flags */
		0 , /* events mask */
		0 | ( 1 << Res1 ) /* resources mask */
	},
	/* Task TaskC */
	{
 		OSEK_TASK_TaskC,	/* task entry point */
		&ContextTaskTaskC, /* pointer to task context */
		StackTaskTaskC, /* pointer stack memory */
		1024, /* stack size */
		3, /* task priority */
		1, /* task max activations */
		{
			0, /* basic task */
			1, /* preemtive task */
			0
		}, /* task const flags */
		0 , /* events mask */
		0 /* resources mask */
	}
};

/** \brief TaskVar Array */
TaskVariableType TasksVar[TASKS_COUNT];

/** \brief List of Auto Start Tasks in Application Mode AppMode1 */
const TaskType TasksAppModeAppMode1[2]  = {
	InitTask,
	TaskC
};
/** \brief List of Auto Start Tasks in Application Mode AppMode2 */
const TaskType TasksAppModeAppMode2[1]  = {
	TaskA
};
/** \brief AutoStart Array */
const AutoStartType AutoStart[2]  = {
	/* Application Mode AppMode1 */
	{
		2, /* Total Auto Start Tasks in this Application Mode */
		(TaskRefType)TasksAppModeAppMode1 /* Pointer to the list of Auto Start Stacks on this Application Mode */
	},
	/* Application Mode AppMode2 */
	{
		1, /* Total Auto Start Tasks in this Application Mode */
		(TaskRefType)TasksAppModeAppMode2 /* Pointer to the list of Auto Start Stacks on this Application Mode */
	}
};

const ReadyConstType ReadyConst[4] = { 
	{
		1, /* Length of this ready list */
		ReadyList3 /* Pointer to the Ready List */
	},
	{
		1, /* Length of this ready list */
		ReadyList2 /* Pointer to the Ready List */
	},
	{
		1, /* Length of this ready list */
		ReadyList1 /* Pointer to the Ready List */
	},
	{
		1, /* Length of this ready list */
		ReadyList0 /* Pointer to the Ready List */
	}
};

/** TODO replace next line with: 
 ** ReadyVarType ReadyVar[4] ; */
ReadyVarType ReadyVar[4];

/** \brief Resources Priorities */
const TaskPriorityType ResourcesPriority[1]  = {
	2
};
/** TODO replace next line with: 
 ** AlarmVarType AlarmsVar[2]; */
AlarmVarType AlarmsVar[2];

const AlarmConstType AlarmsConst[2]  = {
	{
		OSEK_COUNTER_SoftwareCounter, /* Counter */
		ACTIVATETASK, /* Alarm action */
		{
			NULL, /* no callback */
			TaskC, /* TaskID */
			0, /* no event */
			0 /* no counter */
		},
	},
	{
		OSEK_COUNTER_HardwareCounter, /* Counter */
		INCREMENT, /* Alarm action */
		{
			NULL, /* no callback */
			0, /* no task id */
			0, /* no event */
			OSEK_COUNTER_SoftwareCounter /* counter */
		},
	}
};

const AutoStartAlarmType AutoStartAlarm[ALARM_AUTOSTART_COUNT] = {
  {
		AppMode1, /* Application Mode */
		IncrementSWCounter, /* Alarms */
		1, /* Alarm Time */
		1 /* Alarm Time */
	}
};

CounterVarType CountersVar[2];

const CounterConstType CountersConst[2] = {
	{
		1, /* quantity of alarms for this counter */
		(AlarmType*)OSEK_ALARMLIST_HardwareCounter, /* alarms list */
		100, /* max allowed value */
		1, /* min cycle */
		1 /* ticks per base */
	},
	{
		1, /* quantity of alarms for this counter */
		(AlarmType*)OSEK_ALARMLIST_SoftwareCounter, /* alarms list */
		1000, /* max allowed value */
		1, /* min cycle */
		1 /* ticks per base */
	}
};


/** TODO replace the next line with
 ** uint8 ApplicationMode; */
uint8 ApplicationMode;

/** TODO replace the next line with
 ** uint8 ErrorHookRunning; */
uint8 ErrorHookRunning;

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
void OSEK_ISR2_IsrName(void)
{
	//PreIsr2(IsrName);
	OSEK_ISR_IsrName();
	//PostIsr2(IsrName);
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
