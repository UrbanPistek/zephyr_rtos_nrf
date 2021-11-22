#include "ble.h"

LOG_MODULE_REGISTER(ble, LOG_LEVEL_INF);

static void connected(struct bt_conn *conn, uint8_t err);
static void disconnected(struct bt_conn *conn, uint8_t err);

// Struct with function pointers to callback functions
static struct bt_conn_cb conn_callbacks = {
    .connected = connected,
    .disconnected = disconnected,
};

static const struct bt_data ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL))
};

/**
 * @brief  Initialize BLE
 * @param  conn
 * @param  err
 */
static void connected(struct bt_conn *conn, uint8_t err){
    
    char addr[BT_ADDR_LE_STR_LEN];
	if (err) {
		LOG_INF("Connection failed (err 0x%02x)\n", err);
		return;
	}

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));
	LOG_INF("Connected: %s\n", addr);
}

/**
 * @brief  Disconnect BLE Callback
 * @param  None
 */
static void disconnected(struct bt_conn *conn, uint8_t err){
    
    char addr[BT_ADDR_LE_STR_LEN];
    if (err) {
		LOG_INF("Disconnect failed (err %d)\n", err);
		return;
	}

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));
	LOG_INF("Disconnected: %s\n", addr);

}

void ble__init_peripheral(void){

    LOG_INF("Initializing BLE\n");

    int err;

	err = bt_enable(NULL);
	if (err) {
		LOG_INF("Bluetooth init failed (err %d)\n", err);
		return;
	}

    // Create callbacks for handling connection and disconnection events
    bt_conn_cb_register(&conn_callbacks);

    // Start advertising
    err = bt_le_adv_start(BT_LE_ADV_CONN_NAME, ad, ARRAY_SIZE(ad), NULL, 0);
	if (err) {
		LOG_INF("Advertising failed to start (err %d)\n", err);
		return;
	}

	LOG_INF("Advertising successfully started\n");

    //Register services
}