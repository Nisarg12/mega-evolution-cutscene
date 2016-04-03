#include "../../types.h"
#include "../../../gfx/gfx_resources.h"
#include "../../structs_data.h"
#include "../../tables.h"


void LZ77UnCompAnyRAM(u8 *src, u8 *dst, u8 id);
void lz77UnCompVram(void* src, void* dst);
u8 gpu_pal_alloc_new(u16);
void pal_decompress_slice_to_faded_and_unfaded(void* src, u16 start, u16 end);
void gpu_pal_upload(void);
void *malloc_and_clear(u32);


void fighter_gfx_init(u8 controller, u16 species) {
//	void *memcpy(void *str1, const void *str2, u32 n); 
	u16 oam_attr1 = (0x8004 + (0xCC * controller));
	if (!controller) {
		oam_attr1 |= 0x1000;
	}
	u16 oam_fighter[] = {0x1076, oam_attr1, (16 *(FRAME_COUNT) * controller)};
	u16 *oam = (u16 *)(0x7000000 + (8 * controller));
	u8 i;
	for (i = 0; i < 3; i ++) {
		*oam = oam_fighter[i];
		oam++;
	}
	void gpu_pal_apply(u8 *pal, u16 pal_slot, u8 pal_size);
	gpu_pal_apply(fighter_gfx[(species << 1) + 1], 16 * 16 ,32);
	lz77UnCompVram((void *)fighter_gfx[species << 1], (void *)oam_ram_partition[controller]);
}