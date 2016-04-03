#ifndef TEXTBOXES_H
#define TEXTBOXES_H

#include "../types.h"
#include "../engine/tasks.h"
#include "../structs_data.h"

/* Rboxes */
struct rbox {
	u8 bg_id;
	u8 x;
	u8 y;
	u8 w;
	u8 h;
	u8 pal_id;
	u16 vram_tile_offset;
	u32 pixels;
 };
 
 extern struct rbox rboxes[32];

 // dual choice rbox
struct rbox msg_dual_choice = {0x0, 0x14, 0x7, 0x5, 0x4, 0xF, 0x174, 0x6020200};


u8 rbox_get_id_something(struct rbox*);
void rboxid_clear_pixels(u8, u8);
void rboxid_tilemap_update(u8);
void rboxid_upload_a(u8, u8);
void rboxid_80040B8(u8);
void rboxid_8003E3C(u8);
u8 fboxid_get_field(u8, u8);
void box_print(u8, u8, u8, u8, u8, u8, char*);
void sub_810F7D8(u8, u8, u8, u8, u8, u8, u8);
void box_curved(u8, u8);
void box_related_one(u8, u8, char *, u8, u8, u8, u8, u8);
u8 remoid_a_pressed_maybe(u8);
void sub_0812FFF0(u8);
void rboxes_free(void);
void msg_normal(char *);
void wait_select(u8);
void multichoice_box(char **, u8, struct rbox *,u8);
u8 sub_807F3A4(u8, char *, u8, u8);
u16 sub_810FA04(void);
u8 sub_807E418(void);

#endif /* TEXTBOXES_H */