#include "../../types.h"
#include "BG.h"


u8 *gpu_pal_tag_search_lower_boundary = (u8 *)0x03003E58;

void gpu_pal_apply(u8 *, u16, u8);
void lz77UnCompVram(void *src, void *dst);


void lcd_io_set(u32, u32);

void setup_ioregs_bg() {
	u8 i;
	for (i = 0; i < 4; i ++) {
		BG_CNT[i].priority = i;
		BG_CNT[i].char_index = i;
		BG_CNT[i].padding = 0;
		BG_CNT[i].mosiac = 0;
		BG_CNT[i].color = 0;
		BG_CNT[i].map_index = (0x1F - i);
		BG_CNT[i].screen_over = 0;
		BG_CNT[i].size = 0;
		
	}
	
	
	lcd_io_set(0x50, 0x2F00);
	lcd_io_set(0x52, 0x0F);
}


// copy BG into area
void set_bg(u8 bg_id, u8 *gfx, u8 *tile_map, u8 *pal, u8 pal_slot, u8 pal_size) {
	void *char_base = (void *)0x6000000 + (0x4000 * bg_id);
	void *map_base = (void *)0x6000000 + (0xF800 - (0x800 * bg_id));
	lz77UnCompVram(gfx, char_base);
	lz77UnCompVram(tile_map, map_base);
	gpu_pal_apply(pal, pal_slot * 16, pal_size);
	gpu_sync_bg_show(bg_id);
}

void load_trainer_bg(u8 gender) {
	if (gender) {
		// girl
		//set_bg(2, (u8 *)&hero2_tiles, (u8 *)hero2_map, (u8 *)hero2_pal, 0, 0x20);
	} else {
		// boy
		//set_bg(2, (u8 *)&hero1_tiles, (u8 *)hero1_map, (u8 *)hero1_pal, 0, 0x20); 
	}
}