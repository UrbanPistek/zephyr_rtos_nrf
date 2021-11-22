#include <bluetooth/bluetooth.h>
#include <bluetooth/conn.h>
#include <zephyr.h>
#include <sys/printk.h>
#include <logging/log.h>

/**
 * @brief  Initialize BLE peripheral
 * @param  None
 * @return Void
 */
void ble__init_peripheral(void);