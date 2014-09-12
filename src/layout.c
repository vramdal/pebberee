#include "layout.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_bitham_42_medium_numbers;
static GFont s_res_bitham_30_black;
static GFont s_res_gothic_14;
static GBitmap *s_res_action_select_icon;
static GBitmap *s_res_action_play_icon;
static TextLayer *clockLayer;
static TextLayer *scoreLayer;
static TextLayer *periodLayer;
static TextLayer *bookingsHeading;
static TextLayer *homeBookingsLayer;
static TextLayer *awayBookingsLayer;
static ActionBarLayer *defaultActionBar;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorBlack);
  window_set_fullscreen(s_window, false);
  
  s_res_bitham_42_medium_numbers = fonts_get_system_font(FONT_KEY_BITHAM_42_MEDIUM_NUMBERS);
  s_res_bitham_30_black = fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK);
  s_res_gothic_14 = fonts_get_system_font(FONT_KEY_GOTHIC_14);
  s_res_action_select_icon = gbitmap_create_with_resource(RESOURCE_ID_ACTION_SELECT_ICON);
  s_res_action_play_icon = gbitmap_create_with_resource(RESOURCE_ID_ACTION_PLAY_ICON);
  // clockLayer
  clockLayer = text_layer_create(GRect(-1, 47, 121, 45));
  text_layer_set_background_color(clockLayer, GColorClear);
  text_layer_set_text_color(clockLayer, GColorWhite);
  text_layer_set_text(clockLayer, "00:00");
  text_layer_set_text_alignment(clockLayer, GTextAlignmentCenter);
  text_layer_set_font(clockLayer, s_res_bitham_42_medium_numbers);
  layer_add_child(window_get_root_layer(s_window), (Layer *)clockLayer);
  
  // scoreLayer
  scoreLayer = text_layer_create(GRect(1, 0, 119, 31));
  text_layer_set_background_color(scoreLayer, GColorClear);
  text_layer_set_text_color(scoreLayer, GColorWhite);
  text_layer_set_text(scoreLayer, "0 - 0");
  text_layer_set_text_alignment(scoreLayer, GTextAlignmentCenter);
  text_layer_set_font(scoreLayer, s_res_bitham_30_black);
  layer_add_child(window_get_root_layer(s_window), (Layer *)scoreLayer);
  
  // periodLayer
  periodLayer = text_layer_create(GRect(0, 35, 121, 15));
  text_layer_set_text(periodLayer, "First half");
  text_layer_set_text_alignment(periodLayer, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)periodLayer);
  
  // bookingsHeading
  bookingsHeading = text_layer_create(GRect(0, 93, 121, 15));
  text_layer_set_text(bookingsHeading, "Bookings");
  text_layer_set_text_alignment(bookingsHeading, GTextAlignmentCenter);
  text_layer_set_font(bookingsHeading, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)bookingsHeading);
  
  // homeBookingsLayer
  homeBookingsLayer = text_layer_create(GRect(0, 109, 58, 40));
  text_layer_set_background_color(homeBookingsLayer, GColorClear);
  text_layer_set_text_color(homeBookingsLayer, GColorWhite);
  text_layer_set_text(homeBookingsLayer, "Text layer");
  text_layer_set_font(homeBookingsLayer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)homeBookingsLayer);
  
  // awayBookingsLayer
  awayBookingsLayer = text_layer_create(GRect(66, 108, 54, 41));
  text_layer_set_background_color(awayBookingsLayer, GColorClear);
  text_layer_set_text_color(awayBookingsLayer, GColorWhite);
  text_layer_set_text(awayBookingsLayer, "Text layer");
  text_layer_set_text_alignment(awayBookingsLayer, GTextAlignmentRight);
  text_layer_set_font(awayBookingsLayer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)awayBookingsLayer);
  
  // defaultActionBar
  defaultActionBar = action_bar_layer_create();
  action_bar_layer_add_to_window(defaultActionBar, s_window);
  action_bar_layer_set_background_color(defaultActionBar, GColorWhite);
  action_bar_layer_set_icon(defaultActionBar, BUTTON_ID_UP, s_res_action_select_icon);
  action_bar_layer_set_icon(defaultActionBar, BUTTON_ID_SELECT, s_res_action_play_icon);
  action_bar_layer_set_icon(defaultActionBar, BUTTON_ID_DOWN, s_res_action_select_icon);
  layer_add_child(window_get_root_layer(s_window), (Layer *)defaultActionBar);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(clockLayer);
  text_layer_destroy(scoreLayer);
  text_layer_destroy(periodLayer);
  text_layer_destroy(bookingsHeading);
  text_layer_destroy(homeBookingsLayer);
  text_layer_destroy(awayBookingsLayer);
  action_bar_layer_destroy(defaultActionBar);
  gbitmap_destroy(s_res_action_select_icon);
  gbitmap_destroy(s_res_action_play_icon);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_layout(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_layout(void) {
  window_stack_remove(s_window, true);
}
