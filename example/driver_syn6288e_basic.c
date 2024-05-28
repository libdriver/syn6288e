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
 * @file      driver_syn6288e_basic.c
 * @brief     driver syn6288e basic source file
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

#include "driver_syn6288e_basic.h"

static syn6288e_handle_t gs_handle;        /**< syn6288e handle */

/**
 * @brief  basic example init
 * @return status code
 *         - 0 success
 *         - 1 init failed
 * @note   none
 */
uint8_t syn6288e_basic_init(void)
{
    uint8_t res;
    
    /* link interface function */
    DRIVER_SYN6288E_LINK_INIT(&gs_handle, syn6288e_handle_t);
    DRIVER_SYN6288E_LINK_UART_INIT(&gs_handle, syn6288e_interface_uart_init);
    DRIVER_SYN6288E_LINK_UART_DEINIT(&gs_handle, syn6288e_interface_uart_deinit);
    DRIVER_SYN6288E_LINK_UART_READ(&gs_handle, syn6288e_interface_uart_read);
    DRIVER_SYN6288E_LINK_UART_WRITE(&gs_handle, syn6288e_interface_uart_write);
    DRIVER_SYN6288E_LINK_UART_FLUSH(&gs_handle, syn6288e_interface_uart_flush);
    DRIVER_SYN6288E_LINK_DELAY_MS(&gs_handle, syn6288e_interface_delay_ms);
    DRIVER_SYN6288E_LINK_DEBUG_PRINT(&gs_handle, syn6288e_interface_debug_print);
    
    /* syn6288e init */
    res = syn6288e_init(&gs_handle);
    if (res != 0)
    {
        syn6288e_interface_debug_print("syn6288e: init failed.\n");
        
        return 1;
    }
#if (SYN6288E_BASIC_SEND_CONFIG == 1)
    
    /* set defalut baud rate */
    res = syn6288e_set_baud_rate(&gs_handle, SYN6288E_BASIC_DEFAULT_BAUD_RATE);
    if (res != 0)
    {
        syn6288e_interface_debug_print("syn6288e: set baud rate failed.\n");
        (void)syn6288e_deinit(&gs_handle);
        
        return 1;
    }
    syn6288e_interface_delay_ms(100);
    
    /* set defalut mode */
    res = syn6288e_set_mode(&gs_handle, SYN6288E_BASIC_DEFAULT_MODE);
    if (res != 0)
    {
        syn6288e_interface_debug_print("syn6288e: set mode failed.\n");
        (void)syn6288e_deinit(&gs_handle);
        
        return 1;
    }
    syn6288e_interface_delay_ms(100);
    
    /* set defalut text type */
    res = syn6288e_set_text_type(&gs_handle, SYN6288E_BASIC_DEFAULT_TEXT_TYPE);
    if (res != 0)
    {
        syn6288e_interface_debug_print("syn6288e: set text type failed.\n");
        (void)syn6288e_deinit(&gs_handle);
        
        return 1;
    }
    syn6288e_interface_delay_ms(100);
    
    /* set defalut synthesis volume */
    res = syn6288e_set_synthesis_volume(&gs_handle, SYN6288E_BASIC_DEFAULT_SYNTHESIS_VOLUME);
    if (res != 0)
    {
        syn6288e_interface_debug_print("syn6288e: set synthesis volume failed.\n");
        (void)syn6288e_deinit(&gs_handle);
        
        return 1;
    }
    syn6288e_interface_delay_ms(100);
    
    /* set defalut background volume */
    res = syn6288e_set_background_volume(&gs_handle, SYN6288E_BASIC_DEFAULT_BACKGROUND_VOLUME);
    if (res != 0)
    {
        syn6288e_interface_debug_print("syn6288e: set background volume failed.\n");
        (void)syn6288e_deinit(&gs_handle);
        
        return 1;
    }
    syn6288e_interface_delay_ms(100);
    
    /* set defalut synthesis speed */
    res = syn6288e_set_synthesis_speed(&gs_handle, SYN6288E_BASIC_DEFAULT_SYNTHESIS_SPEED);
    if (res != 0)
    {
        syn6288e_interface_debug_print("syn6288e: set synthesis speed failed.\n");
        (void)syn6288e_deinit(&gs_handle);
        
        return 1;
    }
    syn6288e_interface_delay_ms(100);
#endif
    
    return 0;
}

/**
 * @brief     basic example synthesis
 * @param[in] *text points to a text buffer
 * @return    status code
 *            - 0 success
 *            - 1 synthesis failed
 * @note      none
 */
uint8_t syn6288e_basic_synthesis(char *text)
{
    uint8_t res;
    syn6288e_status_t status;

    /* get status */
    res = syn6288e_get_status(&gs_handle, &status);
    if (res != 0)
    {
        return 1;
    }
    
    /* check status */
    if (status == SYN6288E_STATUS_BUSY)
    {
        return 1;
    }
    
    /* synthesis text */
    if (syn6288e_synthesis_text(&gs_handle, text) != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief  basic example sync
 * @return status code
 *         - 0 success
 *         - 1 sync failed
 * @note   none
 */
uint8_t syn6288e_basic_sync(void)
{
    uint8_t res;
    syn6288e_status_t status;
    
    status = SYN6288E_STATUS_BUSY;
    while (status == SYN6288E_STATUS_BUSY)
    {
        syn6288e_interface_delay_ms(500);
        res = syn6288e_get_status(&gs_handle, &status);
        if (res != 0)
        {
            return 1;
        }
    }
    
    return 0;
}

/**
 * @brief  basic example deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t syn6288e_basic_deinit(void)
{
    /* deinit syn6288e */
    if (syn6288e_deinit(&gs_handle) != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
