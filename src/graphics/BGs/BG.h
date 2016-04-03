#ifndef BG_H
#define BG_H

// 0x04000000
struct REG_DISPCNT {
	u16 mode : 3;
	u16 GBC_mode : 1;
	u16 frame_select : 1;
	u16 hblank_oam_process : 1;
	u16 sprite_tile_mapping : 1;
	u16 screen_blank : 1;
	u16 BG0_enable : 1;
	u16 BG1_enable : 1;
	u16 BG2_enable : 1;
	u16 BG3_enable : 1;
	u16 sprite_enable : 1;
	u16 win0_enable : 1;
	u16 win1_enable : 1;
	u16 oam_win_enable : 1;
};
extern struct REG_DISPCNT REG_DISPCNT;
u16 *DISPCNT = (u16 *)0x04000000;
// 0x04000004
struct REG_DISPSTAT {
	u8 vertical_refresh : 1;
	u8 horizontal_refresh : 1;
	u8 vcount_trigger : 1;
	u8 vblank_irq : 1;
	u8 hblank_irq : 1;
	u8 unused : 2;
	u8 vcount_line_trigger;
};
extern struct REG_DISPSTAT REG_DISPSTAT;

// 0x04000006
extern u16 *REG_vcount;

// 0x04000008 - 0x0400000E
struct REG_BGCNT {
	u16 priority : 2;
	u16 char_index : 2; // 0x6000000 + char_index * 0x4000
	u16 padding : 2;
	u16 mosiac : 1;
	u16 color : 1; // 256 or 16
	u16 map_index : 5;
	u16 screen_over : 1;
	u16 size : 2;
	/* 
	For "text" backgrounds: 
	  00 : 256x256 (32x32 tiles) 
	  01 : 512x256 (64x32 tiles) 
	  10 : 256x512 (32x64 tiles) 
	  11 : 512x512 (64x64 tiles) 

	  For rotational backgrounds: 
	  00 : 128x128 (16x16 tiles) 
	  01 : 256x256 (32x32 tiles) 
	  10 : 512x512 (64x64 tiles)
	  11 : 1024x1024 (128x128 tiles)
		  
	*/
};

struct REG_BGCNT BG_CNT[4];
u16 *REG_BG0CNT = (u16 *) 0x04000008;
u16 *REG_BG1CNT = (u16 *) 0x0400000A;
u16 *REG_BG2CNT = (u16 *) 0x0400000C;
u16 *REG_BG3CNT = (u16 *) 0x0400000E;


// 0x04000010 - 0x0400001E
/* BGHOFS & BGVOFS */
struct REG_BG_POS {
	u32 x_pos : 10;
	u32 x_pad : 6;
	u32 y_pos : 10;
	u32 y_pad : 6;
};

struct REG_BG_POS BG_POS[4];


/* This contains the 2x2 matrix controlling rotation and scaling of rotscale 
   BGs in video mode 1 and mode 2. Namely BG2 and BG3. Along with other things */
   /* |PA    PB|
      |PC    PD| */
// 0x04000020 - 0x04000036
struct REG_BG_ROTSCALE {
	s16 BG2_PA; // 0x04000020 - 0x04000026
	s16 BG2_PB;
	s16 BG2_PC;
	s16 BG2_PD; 
	s32 REG_BG_X; // 0x04000028 - 0x0400002F
	s32 REG_BG_Y;	
	
	s16 BG3_PA; // 0x04000030 - 0x04000036
	s16 BG3_PB;
	s16 BG3_PC;
	s16 BG3_PD;
	s32 BG3_X; // 0x04000038 - 0x0400003C
	s32 BG3_Y;	
};

extern struct REG_BG_ROTSCALE BG_ROTSCALE;

// 0x04000040 - 0x0400004A
struct WIN_REG_SIZE {
	// horizontal length = delta x
	u8 win0_x2;
	u8 win0_x1;
	u8 win1_x2;
	u8 win1_x1;
	// vertical length = delta y
	u8 win0_y2;
	u8 win0_y1;
	u8 win1_y2;
	u8 win1_y1;
};
	
struct REG_WIN_IN {
	u16 BG0_win0 : 1;
	u16 BG1_win0 : 1;
	u16 BG2_win0 : 1;
	u16 BG3_win0 : 1;
	u16 oams_win0 : 1;
	u16 blend_win0 : 1;
	u16 padding_win0 : 2;
	u16 BG0_win1 : 1;
	u16 BG1_win1 : 1;
	u16 BG2_win1 : 1;
	u16 BG3_win1 : 1;
	u16 oams_win1 : 1;
	u16 blend_win1 : 1;
	u16 padding_win1 : 2;	
};

struct REG_WIN_OUT {
	u16 BG0_win0 : 1;
	u16 BG1_win0 : 1;
	u16 BG2_win0 : 1;
	u16 BG3_win0 : 1;
	u16 oams_win0 : 1;
	u16 blend_win0 : 1;
	u16 padding_win0 : 2;
	u16 BG0_win1 : 1;
	u16 BG1_win1 : 1;
	u16 BG2_win1 : 1;
	u16 BG3_win1 : 1;
	u16 oams_win1 : 1;
	u16 blend_win1 : 1;
	u16 padding_win1 : 2;
};

extern struct WIN_REG WIN_REG;

// 0x0400004C
struct REG_MOSAIC {
	u16 BG_x_len : 4;
	u16 BG_y_len : 4;
	u16 OAM_x_len : 4;
	u16 OAM_y_len : 4;
};

extern struct REG_MOSAIC REG_MOSAIC;

// 0x04000050
struct REG_BLDMOD {
	u16 blend_BG0_s : 1;
	u16 blend_BG1_s : 1;
	u16 blend_BG2_s : 1;
	u16 blend_BG3_s : 1;
	u16 blend_OAM_s : 1;
	u16 blend_backdrop_s : 1; // ???
	u16 blend_mode : 2;
	u16 blend_BG0_t : 1;
	u16 blend_BG1_t : 1;
	u16 blend_BG2_t : 1;
	u16 blend_BG3_t : 1;
	u16 blend_OAM_t : 1;
	u16 blend_backdrop_t : 1; // ???
};

extern struct REG_BLD_MOD BLD_MOD;

// 0x04000052
struct REG_COLEV {
	u16 coeff_a_source : 5;
	u16 coeff_a_padding : 3;
	u16 coeff_b_source : 5;
	u16 coeff_b_padding :3;
	
};

// 0x04000054
struct REG_COLEY {
	u16 light_dark_multiplier : 5;
	u16 padding : 11;
};

void gpu_sync_bg_show(u8);
void gpu_sync_bg_hide(u8);
void bgid_mod_x_offset(u8 bgid, u16 delta, u8 dir);
void bgid_mod_y_offset(u8 bgid, u16 delta, u8 dir);


#endif /* BG_H */
