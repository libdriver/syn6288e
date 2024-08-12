/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_syn6288e.h
 * @brief     driver syn6288e header file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2024-05-30
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2024/05/30  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#ifndef DRIVER_SYN6288E_H
#define DRIVER_SYN6288E_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup syn6288e_driver syn6288e driver function
 * @brief    syn6288e driver modules
 * @{
 */

/**
 * @addtogroup syn6288e_base_driver
 * @{
 */

/**
 * @brief syn6288e sound enumeration definition
 */
typedef enum
{
    SYN6288E_SOUND_A = 'a',        /**< sound A */
    SYN6288E_SOUND_B = 'b',        /**< sound B */
    SYN6288E_SOUND_C = 'c',        /**< sound C */
    SYN6288E_SOUND_D = 'd',        /**< sound D */
    SYN6288E_SOUND_E = 'e',        /**< sound E */
    SYN6288E_SOUND_F = 'f',        /**< sound F */
    SYN6288E_SOUND_G = 'g',        /**< sound G */
    SYN6288E_SOUND_H = 'h',        /**< sound H */
    SYN6288E_SOUND_I = 'i',        /**< sound I */
    SYN6288E_SOUND_J = 'j',        /**< sound J */
    SYN6288E_SOUND_K = 'k',        /**< sound K */
    SYN6288E_SOUND_L = 'l',        /**< sound L */
    SYN6288E_SOUND_M = 'm',        /**< sound M */
    SYN6288E_SOUND_N = 'n',        /**< sound N */
    SYN6288E_SOUND_O = 'o',        /**< sound O */
    SYN6288E_SOUND_P = 'p',        /**< sound P */
    SYN6288E_SOUND_Q = 'q',        /**< sound Q */
    SYN6288E_SOUND_R = 'r',        /**< sound R */
    SYN6288E_SOUND_S = 's',        /**< sound S */
    SYN6288E_SOUND_T = 't',        /**< sound T */
    SYN6288E_SOUND_U = 'u',        /**< sound U */
    SYN6288E_SOUND_V = 'v',        /**< sound V */
    SYN6288E_SOUND_W = 'w',        /**< sound W */
    SYN6288E_SOUND_X = 'x',        /**< sound X */
    SYN6288E_SOUND_Y = 'y',        /**< sound Y */
} syn6288e_sound_t;

/**
 * @brief syn6288e message enumeration definition
 */
typedef enum
{
    SYN6288E_MESSAGE_A = 'a',        /**< message A */
    SYN6288E_MESSAGE_B = 'b',        /**< message B */
    SYN6288E_MESSAGE_C = 'c',        /**< message C */
    SYN6288E_MESSAGE_D = 'd',        /**< message D */
    SYN6288E_MESSAGE_E = 'e',        /**< message E */
    SYN6288E_MESSAGE_F = 'f',        /**< message F */
    SYN6288E_MESSAGE_G = 'g',        /**< message G */
    SYN6288E_MESSAGE_H = 'h',        /**< message H */
} syn6288e_message_t;

/**
 * @brief syn6288e ring enumeration definition
 */
typedef enum
{
    SYN6288E_RING_A = 'a',        /**< ring A */
    SYN6288E_RING_B = 'b',        /**< ring B */
    SYN6288E_RING_C = 'c',        /**< ring C */
    SYN6288E_RING_D = 'd',        /**< ring D */
    SYN6288E_RING_E = 'e',        /**< ring E */
    SYN6288E_RING_F = 'f',        /**< ring F */
    SYN6288E_RING_G = 'g',        /**< ring G */
    SYN6288E_RING_H = 'h',        /**< ring H */
    SYN6288E_RING_I = 'i',        /**< ring I */
    SYN6288E_RING_J = 'j',        /**< ring J */
    SYN6288E_RING_K = 'k',        /**< ring K */
    SYN6288E_RING_L = 'l',        /**< ring L */
    SYN6288E_RING_M = 'm',        /**< ring M */
    SYN6288E_RING_N = 'n',        /**< ring N */
    SYN6288E_RING_O = 'o',        /**< ring O */
} syn6288e_ring_t;

/**
 * @brief syn6288e type enumeration definition
 */
typedef enum
{
    SYN6288E_TYPE_GB2312  = 0x00,         /**< gb2312 type */
    SYN6288E_TYPE_GBK     = 0x01,         /**< gbk type */
    SYN6288E_TYPE_BIG5    = 0x02,         /**< big5 type */
    SYN6288E_TYPE_UNICODE = 0x03,         /**< unicode type */
} syn6288e_type_t;

/**
 * @brief syn6288e status enumeration definition
 */
typedef enum
{
    SYN6288E_STATUS_OK   = 0x00,         /**< ok status */
    SYN6288E_STATUS_BUSY = 0x01,         /**< busy status */
} syn6288e_status_t;

/**
 * @}
 */

/**
 * @addtogroup syn6288e_advance_driver
 * @{
 */

/**
 * @brief syn6288e mode enumeration definition
 */
typedef enum
{
    SYN6288E_MODE_COMMON        = (0x00),           /**< common */
    SYN6288E_MODE_BACKGROUND_1  = (1 << 3),         /**< background 1 */
    SYN6288E_MODE_BACKGROUND_2  = (2 << 3),         /**< background 2 */
    SYN6288E_MODE_BACKGROUND_3  = (3 << 3),         /**< background 3 */
    SYN6288E_MODE_BACKGROUND_4  = (4 << 3),         /**< background 4 */
    SYN6288E_MODE_BACKGROUND_5  = (5 << 3),         /**< background 5 */
    SYN6288E_MODE_BACKGROUND_6  = (6 << 3),         /**< background 6 */
    SYN6288E_MODE_BACKGROUND_7  = (7 << 3),         /**< background 7 */
    SYN6288E_MODE_BACKGROUND_8  = (8 << 3),         /**< background 8 */
    SYN6288E_MODE_BACKGROUND_9  = (9 << 3),         /**< background 9 */
    SYN6288E_MODE_BACKGROUND_10 = (10 << 3),        /**< background 10 */
    SYN6288E_MODE_BACKGROUND_11 = (11 << 3),        /**< background 11 */
    SYN6288E_MODE_BACKGROUND_12 = (12 << 3),        /**< background 12 */
    SYN6288E_MODE_BACKGROUND_13 = (13 << 3),        /**< background 13 */
    SYN6288E_MODE_BACKGROUND_14 = (14 << 3),        /**< background 14 */
    SYN6288E_MODE_BACKGROUND_15 = (15 << 3),        /**< background 15 */
} syn6288e_mode_t;


/**
 * @brief syn6288e baud rate enumeration definition
 */
typedef enum
{
    SYN6288E_BAUD_RATE_9600_BPS  = 0x00,         /**< 9600 bps */
    SYN6288E_BAUD_RATE_19200_BPS = 0x01,         /**< 19200 bps */
    SYN6288E_BAUD_RATE_38400_BPS = 0x02,         /**< 38400 bps */
} syn6288e_baud_rate_t;

/**
 * @}
 */

/**
 * @addtogroup syn6288e_base_driver
 * @{
 */

/**
 * @brief syn6288e handle structure definition
 */
typedef struct syn6288e_handle_s
{
    uint8_t (*uart_init)(void);                               /**< point to a uart_init function address */
    uint8_t (*uart_deinit)(void);                             /**< point to a uart_deinit function address */
    uint16_t (*uart_read)(uint8_t *buf, uint16_t len);        /**< point to a uart_read function address */
    uint8_t (*uart_flush)(void);                              /**< point to a uart_flush function address */
    uint8_t (*uart_write)(uint8_t *buf, uint16_t len);        /**< point to a uart_write function address */
    void (*delay_ms)(uint32_t ms);                            /**< point to a delay_ms function address */
    void (*debug_print)(const char *const fmt, ...);          /**< point to a debug_print function address */
    uint8_t type;                                             /**< text type */
    uint8_t mode;                                             /**< play mode */
    uint8_t rate;                                             /**< uart rate */
    uint8_t volume;                                           /**< play volume */
    uint8_t background_volume;                                /**< play background volume */
    uint8_t speed;                                            /**< play speed */
    uint8_t inited;                                           /**< inited flag */
    uint8_t buf[256];                                         /**< frame buf */
} syn6288e_handle_t;

/**
 * @brief syn6288e information structure definition
 */
typedef struct syn6288e_info_s
{
    char chip_name[32];                /**< chip name */
    char manufacturer_name[32];        /**< manufacturer name */
    char interface[8];                 /**< chip interface name */
    float supply_voltage_min_v;        /**< chip min supply voltage */
    float supply_voltage_max_v;        /**< chip max supply voltage */
    float max_current_ma;              /**< chip max current */
    float temperature_min;             /**< chip min operating temperature */
    float temperature_max;             /**< chip max operating temperature */
    uint32_t driver_version;           /**< driver version */
} syn6288e_info_t;

/**
 * @}
 */

/**
 * @defgroup syn6288e_link_driver syn6288e link driver function
 * @brief    syn6288e link driver modules
 * @ingroup  syn6288e_driver
 * @{
 */

/**
 * @brief     initialize syn6288e_handle_t structure
 * @param[in] HANDLE points to a syn6288e handle structure
 * @param[in] STRUCTURE is syn6288e_handle_t
 * @note      none
 */
#define DRIVER_SYN6288E_LINK_INIT(HANDLE, STRUCTURE)   memset(HANDLE, 0, sizeof(STRUCTURE))

/**
 * @brief     link uart_init function
 * @param[in] HANDLE points to a syn6288e handle structure
 * @param[in] FUC points to a uart_init function address
 * @note      none
 */
#define DRIVER_SYN6288E_LINK_UART_INIT(HANDLE, FUC)   (HANDLE)->uart_init = FUC

/**
 * @brief     link uart_deinit function
 * @param[in] HANDLE points to a syn6288e handle structure
 * @param[in] FUC points to a uart_deinit function address
 * @note      none
 */
#define DRIVER_SYN6288E_LINK_UART_DEINIT(HANDLE, FUC) (HANDLE)->uart_deinit = FUC

/**
 * @brief     link uart_read function
 * @param[in] HANDLE points to a syn6288e handle structure
 * @param[in] FUC points to a uart_read function address
 * @note      none
 */
#define DRIVER_SYN6288E_LINK_UART_READ(HANDLE, FUC)   (HANDLE)->uart_read = FUC

/**
 * @brief     link uart_write function
 * @param[in] HANDLE points to a syn6288e handle structure
 * @param[in] FUC points to a uart_write function address
 * @note      none
 */
#define DRIVER_SYN6288E_LINK_UART_WRITE(HANDLE, FUC)  (HANDLE)->uart_write = FUC

/**
 * @brief     link uart_flush function
 * @param[in] HANDLE points to a syn6288e handle structure
 * @param[in] FUC points to a uart_flush function address
 * @note      none
 */
#define DRIVER_SYN6288E_LINK_UART_FLUSH(HANDLE, FUC)  (HANDLE)->uart_flush = FUC

/**
 * @brief     link delay_ms function
 * @param[in] HANDLE points to a syn6288e handle structure
 * @param[in] FUC points to a delay_ms function address
 * @note      none
 */
#define DRIVER_SYN6288E_LINK_DELAY_MS(HANDLE, FUC)    (HANDLE)->delay_ms = FUC

/**
 * @brief     link debug_print function
 * @param[in] HANDLE points to a syn6288e handle structure
 * @param[in] FUC points to a debug_print function address
 * @note      none
 */
#define DRIVER_SYN6288E_LINK_DEBUG_PRINT(HANDLE, FUC) (HANDLE)->debug_print = FUC

/**
 * @}
 */

/**
 * @defgroup syn6288e_base_driver syn6288e base driver function
 * @brief    syn6288e base driver modules
 * @ingroup  syn6288e_driver
 * @{
 */

/**
 * @brief      get chip's information
 * @param[out] *info points to a syn6288e info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t syn6288e_info(syn6288e_info_t *info);

/**
 * @brief     initialize the chip
 * @param[in] *handle points to a syn6288e handle structure
 * @return    status code
 *            - 0 success
 *            - 1 uart initialization failed
 *            - 2 handle is NULL
 *            - 3 linked functions is NULL
 * @note      none
 */
uint8_t syn6288e_init(syn6288e_handle_t *handle);

/**
 * @brief     close the chip
 * @param[in] *handle points to a syn6288e handle structure
 * @return    status code
 *            - 0 success
 *            - 1 uart deinit failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t syn6288e_deinit(syn6288e_handle_t *handle);

/**
 * @brief     synthesis the test
 * @param[in] *handle points to a syn6288e handle structure
 * @param[in] *text points to a test buffer
 * @return    status code
 *            - 0 success
 *            - 1 synthesis text failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t syn6288e_synthesis_text(syn6288e_handle_t *handle, char *text);

/**
 * @brief     synthesis the sound
 * @param[in] *handle points to a syn6288e handle structure
 * @param[in] sound is the sound type
 * @return    status code
 *            - 0 success
 *            - 1 synthesis sound failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t syn6288e_synthesis_sound(syn6288e_handle_t *handle, syn6288e_sound_t sound);

/**
 * @brief     synthesis the message
 * @param[in] *handle points to a syn6288e handle structure
 * @param[in] message is the message type
 * @return    status code
 *            - 0 success
 *            - 1 synthesis message failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t syn6288e_synthesis_message(syn6288e_handle_t *handle, syn6288e_message_t message);

/**
 * @brief     synthesis the ring
 * @param[in] *handle points to a syn6288e handle structure
 * @param[in] ring is the ring type
 * @return    status code
 *            - 0 success
 *            - 1 synthesis ring failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t syn6288e_synthesis_ring(syn6288e_handle_t *handle, syn6288e_ring_t ring);

/**
 * @brief      get the current status
 * @param[in]  *handle points to a syn6288e handle structure
 * @param[out] *status points to a status buffer
 * @return     status code
 *             - 0 success
 *             - 1 get status failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t syn6288e_get_status(syn6288e_handle_t *handle, syn6288e_status_t *status);

/**
 * @brief     stop the chip
 * @param[in] *handle points to a syn6288e handle structure
 * @return    status code
 *            - 0 success
 *            - 1 stop failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t syn6288e_stop(syn6288e_handle_t *handle);

/**
 * @brief     pause the chip
 * @param[in] *handle points to a syn6288e handle structure
 * @return    status code
 *            - 0 success
 *            - 1 pause failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t syn6288e_pause(syn6288e_handle_t *handle);

/**
 * @brief     resume the chip
 * @param[in] *handle points to a syn6288e handle structure
 * @return    status code
 *            - 0 success
 *            - 1 resume failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t syn6288e_resume(syn6288e_handle_t *handle);

/**
 * @brief     power down the chip
 * @param[in] *handle points to a syn6288e handle structure
 * @return    status code
 *            - 0 success
 *            - 1 power down failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t syn6288e_power_down(syn6288e_handle_t *handle);

/**
 * @brief     set the chip text type
 * @param[in] *handle points to a syn6288e handle structure
 * @param[in] type is the chip text type
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t syn6288e_set_text_type(syn6288e_handle_t *handle, syn6288e_type_t type);

/**
 * @brief      get the chip text type
 * @param[in]  *handle points to a syn6288e handle structure
 * @param[out] *type points to a chip text type
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t syn6288e_get_text_type(syn6288e_handle_t *handle, syn6288e_type_t *type);

/**
 * @}
 */

/**
 * @defgroup syn6288e_advance_driver syn6288e advance driver function
 * @brief    syn6288e advance driver modules
 * @ingroup  syn6288e_driver
 * @{
 */

/**
 * @brief     set the baud rate
 * @param[in] *handle points to a syn6288e handle structure
 * @param[in] rate is the baud rate
 * @return    status code
 *            - 0 success
 *            - 1 set baud rate failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t syn6288e_set_baud_rate(syn6288e_handle_t *handle, syn6288e_baud_rate_t rate);

/**
 * @brief      get the baud rate
 * @param[in]  *handle points to a syn6288e handle structure
 * @param[out] *rate points to a baud rate buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t syn6288e_get_baud_rate(syn6288e_handle_t *handle, syn6288e_baud_rate_t *rate);

/**
 * @brief     set the chip mode
 * @param[in] *handle points to a syn6288e handle structure
 * @param[in] mode is the chip mode
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t syn6288e_set_mode(syn6288e_handle_t *handle, syn6288e_mode_t mode);

/**
 * @brief      get the chip mode
 * @param[in]  *handle points to a syn6288e handle structure
 * @param[out] *mode points to a chip mode buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t syn6288e_get_mode(syn6288e_handle_t *handle, syn6288e_mode_t *mode);

/**
 * @brief     set the chip synthesis volume
 * @param[in] *handle points to a syn6288e handle structure
 * @param[in] volume is the synthesis volume
 * @return    status code
 *            - 0 success
 *            - 1 set synthesis volume failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t syn6288e_set_synthesis_volume(syn6288e_handle_t *handle, uint8_t volume);

/**
 * @brief      get the chip synthesis volume
 * @param[in]  *handle points to a syn6288e handle structure
 * @param[out] *volume points to a synthesis volume buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t syn6288e_get_synthesis_volume(syn6288e_handle_t *handle, uint8_t *volume);

/**
 * @brief     set the synthesis background volume
 * @param[in] *handle points to a syn6288e handle structure
 * @param[in] volume is the background volume
 * @return    status code
 *            - 0 success
 *            - 1 set background volume failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t syn6288e_set_background_volume(syn6288e_handle_t *handle, uint8_t volume);

/**
 * @brief      get the chip synthesis background volume
 * @param[in]  *handle points to a syn6288e handle structure
 * @param[out] *volume points to a synthesis background volume buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t syn6288e_get_background_volume(syn6288e_handle_t *handle, uint8_t *volume);

/**
 * @brief     set the synthesis speed
 * @param[in] *handle points to a syn6288e handle structure
 * @param[in] speed is the synthesis speed
 * @return    status code
 *            - 0 success
 *            - 1 set synthesis speed failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t syn6288e_set_synthesis_speed(syn6288e_handle_t *handle, uint8_t speed);

/**
 * @brief      get the synthesis speed
 * @param[in]  *handle points to a syn6288e handle structure
 * @param[out] *speed points to a synthesis speed
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t syn6288e_get_synthesis_speed(syn6288e_handle_t *handle, uint8_t *speed);

/**
 * @}
 */

/**
 * @defgroup syn6288e_extend_driver syn6288e extend driver function
 * @brief    syn6288e extend driver modules
 * @ingroup  syn6288e_driver
 * @{
 */

/**
 * @brief     send the command to the chip
 * @param[in] *handle points to a syn6288e handle structure
 * @param[in] *command points to a command buffer
 * @return    status code
 *            - 0 success
 *            - 1 set command failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t syn6288e_set_command(syn6288e_handle_t *handle, char *command);

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
