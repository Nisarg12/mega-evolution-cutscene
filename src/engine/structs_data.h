#ifndef WRAM_STRUCTS_DATA_H
#define WRAM_STRUCTS_DATA_H

/*Walkrun state*/
struct walkrun {
	u8 bitfield;
	u8 bike;
	u8 running2;
	u8 running1;
	u8 oamid;
	u8 npcid;
	u8 lock;
	u8 gender;
	u8 xmode;
	u8 field9;
	u8 fielda;
	u8 fieldb;
	u16 fieldc;
	u16 field14;
	u8 field18;
	u8 field19;
	u16 field1A;
	u16 most_recent_override_tile;
};

extern struct walkrun walkrun_state;

 /* sav2 structure */
 struct saveblock_trainerdata {
	struct sav2 *sav2;
};

struct sav2 {
	char name[8];
	u8 gender;
	u8 padding;
	u16 trainer_id;
	u16 secret_id;
	u16 hours;
	u8 minutes;
	u8 seconds;
	u8 frames;
	u8 options_button_style;
	u8 options_text_speed;
	u8 options_battle_style[7];
	u32 field_1C;
	u8 field_20[8];
	u8 pokemon_flags_3[52];
	u8 pokemon_flags_4[52];
	u8 field_90[1044];
	u8 fourCharacters[4];
	u8 field_4A8[1008];
	u8 mapdata[1672];
	u32 bag_item_quantity_xor_value;
	u8 field_F24[127];
	u8 last_byte_in_sav2;
};
extern struct saveblock_trainerdata saveblock2;

/* vars */

struct temp_vars {
	// Only 0x8000s here
	u16 var_8000;
	u16 var_8001;
	u16 var_8002;
	u16 var_8003;
	u16 var_8004;
	u16 var_8005;
	u16 var_8006;
	u16 var_8007;
	u16 var_8008;
	u16 var_8009;
	u16 var_800A;
	u16 var_800B;
	u16 var_800D;
	u16 var_800F;
	u16 var_800C;
	u16 var_8010;
	u16 var_8011;
};
extern struct temp_vars temp_vars;

 struct pokemon {
	u32 PID;
	u32 OTID;
	char name[10];
	u16 language;
	u8 OT_name[7];
	u8 markings;
	u16 checksum;
	u16 padding_maybe;
	u8 data[48];
	u32 ailment;
	u8 level;
	u8 pokerus;
	u16 current_hp;
	u16 total_hp;
	u16 attack;
	u16 defense;
	u16 speed;
	u16 sp_attack;
	u16 sp_defense;
};

extern struct pokemon player_party[6];
extern struct pokemon opponent_party[6];

#endif /* WRAM_STRUCTS_DATA_H */
