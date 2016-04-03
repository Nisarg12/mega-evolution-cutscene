#include "types.h"
#include "character_control\buttons\buttons.h"
#include "character_control\controls\player_movement.c"
#include ".\graphics\BGs\BG.c"
//#include ".\graphics\OBJs\oam.c"
#include ".\text\textboxes.h"
#include "..\gfx\gfx_resources.h"
#include "engine\tasks.h"
#include "character_control.c"

/* Funcs */
void overworld_free_bgmaps(void);
void pal_fade_control_and_dead_struct_reset(void);
void gpu_tile_bg_drop_all_sets(u8);
void palette_bg_faded_fill_black(void);
void vblank_handler_set(u8);
void hblank_handler_set(u8);
void CpuSet(void *src, void *dst, uint mode);
void obj_and_aux_reset_all(void);
void tasks_init(void);
void gpu_pal_allocator_reset(void);
void set_callback2(super_callback);
void gpu_sync_bg_hide(u8);
void gpu_sprites_upload(void);
void copy_queue_process(void);
void gpu_pal_upload(void);
void fade_screen(u32, u8, u8, u8, u32);
void help_system_disable__sp198(void);
void current_map_music_set(u16);
void remoboxes_acknowledge(void);
void task_exec(void);
void objc_exec(void);
void obj_sync_something(void);
void audio_play(u8);

void vblank_cb() {
	// deals with copying data from FR's high level structs in
	// WRAM into approriate RAM addresses.
	//gpu_sprites_upload();
	//copy_queue_process();
	gpu_pal_upload();
}

// reset screen attributes
void setup() {
	// callbacks
	vblank_handler_set(0);
	hblank_handler_set(0);
	set_callback2((super_callback)0x812EB11);
	// BGs
	overworld_free_bgmaps();
	gpu_tile_bg_drop_all_sets(0);
	int src_zero = 0;
	CpuSet(&src_zero, (void *)0x6000000, (uint)0x5006000);
	// pals
	pal_fade_control_and_dead_struct_reset();
	palette_bg_faded_fill_black();
	pal_fade_control_and_dead_struct_reset();
	gpu_pal_allocator_reset();
	*gpu_pal_tag_search_lower_boundary = 0;
	// objs
	obj_and_aux_reset_all();
	// tasks
	tasks_init();
	// more BG setup 
	superstate.callback_vblank = vblank_cb;
	setup_ioregs_bg();
	bgid_mod_x_offset(0, 0, 0);
    bgid_mod_y_offset(0, 0, 0);
	bgid_mod_x_offset(1, 0, 0);
    bgid_mod_y_offset(1, 0, 0);
	bgid_mod_x_offset(2, 0, 0);
    bgid_mod_y_offset(2, 0, 0);
	bgid_mod_x_offset(3, 0, 0);
    bgid_mod_y_offset(3, 0, 0);
	remoboxes_acknowledge();
	rboxes_free();
}

u16 bgid_get_y_offset(u8);
u16 bgid_get_x_offset(u8);

void sky_scroll(u8 task_id) {
	bgid_mod_x_offset(0, bgid_get_x_offset(0) + 64, 0);
}


extern void test();

void battle_ground_make() {
	task_exec();
	objc_exec();
	obj_sync_something();
	//tilemaps_sync();
	switch (superstate.multipurpose_state_tracker) {
		case 0:
		{
			temp_vars.var_8001 = 0;
			/*// REG_DISPCNT setup
			REG_DISPCNT.mode = 2;
			REG_DISPCNT.GBC_mode = 0;
			REG_DISPCNT.frame_select = 0;
			REG_DISPCNT.hblank_oam_process = 0;
			REG_DISPCNT.sprite_tile_mapping = 0; //2d or 3d mapping
			REG_DISPCNT.screen_blank = 0;
			REG_DISPCNT.BG0_enable = 1;
			REG_DISPCNT.BG1_enable = 1;
			REG_DISPCNT.BG2_enable = 1;
			REG_DISPCNT.BG3_enable = 0;
			REG_DISPCNT.sprite_enable = 1;
			REG_DISPCNT.win0_enable = 0;
			REG_DISPCNT.win1_enable = 0;
			REG_DISPCNT.oam_win_enable = 0;
			temp_vars.var_8000 = *DISPCNT;
			
			// REG_BGCNT
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
			BG_CNT[1].color = 1;
			lcd_io_set(0x50, 0x2F00);
			lcd_io_set(0x52, 0x0F);*/
			test();
			superstate.multipurpose_state_tracker++;
			break;
		}
		case 1:
		{
			// load VRAM BG background
			u8 bg_config_data[16] = {0xF0, 0x11, 0x0, 0x0, 0xE5, 0x09, 0x0, 0x0, 0xDA, 0x21, 0x0, 0x0, 0xCF, 0x31, 0x0, 0x0};
			void bg_vram_setup(u8, u8 *, u8);
			// mode, setup, amount of bgs to config
			bg_vram_setup(0, (u8 *)&bg_config_data, 4);
			set_bg(0, (u8 *)sky_tiles, (u8 *)sky_map, (u8 *)sky_pal, 6, 32);
			set_bg(1, (u8 *)tree_tiles, (u8 *)tree_map, (u8 *)tree_pal, 0, 160);
			superstate.multipurpose_state_tracker++;
			break;
		}
		case 2:
		{
			// wtb better clouds
			task_add(sky_scroll, 0x1);
			superstate.multipurpose_state_tracker++;
			break;
		}
		case 3:
		{
			void gpu_bg_config_set_field(u8, u8, u8);
			gpu_bg_config_set_field(0, 5, 1);
			superstate.multipurpose_state_tracker++;
			break;
		}
		case 4:
		{
			make_player(0);
			make_opponent(0);
			superstate.multipurpose_state_tracker++;
			break;
		}
		case 5:
		{
			player_char_movement();
			break;
		}
		case 99:
		{
			// waitstate + next command buffer
			player_movement_buffer();
			break;
		}
		default:
			break;
	};


}

void zinit_scene() {
	superstate.multipurpose_state_tracker = 0;
	help_system_disable__sp198();
	setup();
	superstate.callback1 = (super_callback)(battle_ground_make + 1);
	superstate.callback2 = 0;
};
