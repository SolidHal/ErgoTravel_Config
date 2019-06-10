
Made using QMK Configurator beta
https://yanfali.github.io/qmk_configurator/#/ergotravel/rev1/LAYOUT

Flash by copying the "keymap-*" folder into qmk/keyboards/ergotravel/keymaps/ as "solidhal-normal-modifiers" or "solidhal-hold-modifiers"
and running 

sudo make ergotravel/rev1:solidhal-normal-modifiers:avrdude

or

sudo make ergotravel/rev1:solidhal-hold-modifiers:avrdude

from the qmk folder


Make sure to re-add the underglow function, which was borrowed from here:
https://www.reddit.com/r/olkb/comments/6t1vdu/update_layeractivated_rgb_underglow/
https://github.com/AGausmann/qmk_firmware/blob/agausmann-v3.x/keyboards/nyquist/keymaps/agausmann/keymap.c


The color picker here works well: https://web.archive.org/web/20160125221210/http://www.w3schools.com/tags/ref_colorpicker.asp



The color function can be added by putting these around PROGMEM keymaps in keymap.c:

+++ b/solidhal-normal-modifiers/keymap.c
@@ -0,0 +1,40 @@
+#include QMK_KEYBOARD_H
+#ifdef RGBLIGHT_ENABLE
+#include "rgblight.h"
+#endif
+

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { yadayadayada }

+
+void matrix_scan_user(void) {
+  #ifdef RGBLIGHT_ENABLE
+
+  static uint8_t old_layer = 255;
+  uint8_t new_layer = biton32(layer_state);
+
+  if (old_layer != new_layer) {
+    switch (new_layer) {
+      case 0:
+        rgblight_setrgb(102, 0, 102);
+	//rgblight_setrgb(102, 0, 204);        
+	break;
+      case 1:
+        rgblight_setrgb(0x00, 0xA0, 0xFF);
+        break;
+      case 2:
+        rgblight_setrgb(0xFF, 0x00, 0x00);
+        break;
+      case 3:
+        rgblight_setrgb(0xFF, 0x20, 0x00);
+        break;
+    }
+
+    old_layer = new_layer;
+  }
+
+  #endif //RGBLIGHT_ENABLE
+}




If this is a new download of qmk,
Add these lines to qmk/keyboards/ergotravel/rule.mk 

RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight. 
RGBLED_NUM = 14


