
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

If this is a new download of qmk,
Add these lines to qmk/keyboards/ergotravel/rule.mk 

RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight. 
RGBLED_NUM = 14


