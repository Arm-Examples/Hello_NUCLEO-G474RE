/*---------------------------------------------------------------------------
 * Copyright (c) 2023-2025 Arm Limited (or its affiliates). All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *---------------------------------------------------------------------------*/

#include <stdio.h>
#include "main.h"
#include "cmsis_os2.h"

// Create thread attribute to show thread name in the XRTOS viewer:
const osThreadAttr_t app_main_attr = {.name = "MainThread"};

/*-----------------------------------------------------------------------------
 * Application main thread
 *----------------------------------------------------------------------------*/
static void app_main_thread(void *argument) {
  (void)argument;

  for (int count = 0; count < 10; count++) {
    printf("Hello World %d\r\n", count);
    osDelay(1000U);
  }
  osDelay(osWaitForever);
}

/*-----------------------------------------------------------------------------
 * Application initialization
 *----------------------------------------------------------------------------*/
int app_main(void) {
  // Initialize CMSIS-RTOS2:
  osKernelInitialize();
  // Create named application main thread:
  osThreadNew(app_main_thread, NULL, &app_main_attr);
  // Start thread execution:
  osKernelStart();
  return 0;
}
