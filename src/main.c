#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"


#define MY_UUID { 0xD5, 0x6B, 0x93, 0x8B, 0x68, 0xE5, 0x47, 0xF0, 0xA9, 0x8E, 0xB0, 0x6B, 0x7D, 0x17, 0x3B, 0xA4 }
PBL_APP_INFO(MY_UUID,
             "Pebberee", "vidarramdal.com",
             1, 0, /* App version */
             DEFAULT_MENU_ICON,
             APP_INFO_STANDARD_APP);

Window window;


void handle_init(AppContextRef ctx) {
  (void)ctx;

  window_init(&window, "Match");
  window_stack_push(&window, true /* Animated */);
}

static void handle_tick(struct tm *tick_time, TimeUnits units_changed) {
}

/*static void handle_battery(BatteryChargeState charge_state) {
	static char battery_text[] = "100% batteri";
	if (charge_state.is_charging) {
		snprint(battery_text, sizeof(battery_text), "lader");
	} else {
		snprint(battery_text, sizeof(battery_text), "%d%% batteri", charge_state.charge_percent);
	}
	text_layer_set_text(battery_layer, battery_text);
}*/


void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init
  };
  tick_timer_service_subscribe(SECOND_UNIT, handle_tick);
  app_event_loop(params, &handlers);
}
