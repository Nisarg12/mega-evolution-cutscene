#include "..\types.h"
#include "string_funcs.h"
#include "textboxes.h"
#include"..\character_control\buttons\buttons.h"

// draw text
void task_text_draw(u8 task_id) {
	struct task* task = &tasks[task_id];
	switch (task->priv[0]) {
		case 0:
		{
			struct rbox this_box = {0x0, 0x0, 0x2, 0x1E, 0x0D, 0x0F, 0x1, 0x20100};
			u8 r_id = rbox_get_id_something(&this_box);
			task->priv[1] = r_id;
			rboxid_clear_pixels(r_id, 0);
			rboxid_tilemap_update(r_id);
			rboxid_upload_a(r_id, 3);
			task->priv[0]++;
			break;
		}
		case 1:
		{
			if (sub_807F3A4(task_id, string_buffer, 2, 8) << 24) {
				task->priv[0]++;
			}
			break;
		}
		case 2:
		{
			u8 r_id = (task->priv[1] & 0xFF); //rbox id, byte
			rboxid_80040B8(r_id);
			rboxid_upload_a(r_id, 1);
			rboxid_8003E3C(r_id);
			task->priv[0]++;
			break;
		}
		case 3:
		{
			if (sub_807E418() == 1) {
				superstate.multipurpose_state_tracker++;
				task_del(task_id);
			}
			break;
		}
		case 4:
		{
			task->priv[0] = 0;
			break;
		}
		default:
			task->priv[0]--;
			break;
	};
	return;
}

u8 draw_text(u8 delay, char *string) {
	str_cpy(string_buffer, string);
	u8 t_id = task_add(task_text_draw, 0xA);
	tasks[t_id].priv[0] = delay;
	return t_id;
}

void multichoice_box(char **options, u8 option_number, struct rbox* box, u8 state_id) {
	u8 box_id = rbox_get_id_something(box);
	box_curved(box_id, 1);
	rboxid_clear_pixels(box_id, 0x11);
	u8 i;
	for (i = 0; i < option_number; i++) {
		box_print(box_id, 2, 8, (1 + (16 * i)), 1, 0, options[i]);
	}
	u8 f_id = fboxid_get_field(2, 1);
	sub_810F7D8(box_id, 2, 0, 1, f_id +2, 2, 0);
	rboxid_upload_a(box_id, 3);
	u8 t_id = task_add(wait_select +1, 1);
	tasks[t_id].priv[13] = box_id;
	tasks[t_id].priv[0] = state_id;
	tasks[t_id].priv[1] = option_number;
}

void wait_select(u8 task_id) {
	struct task *task = &tasks[task_id];
	u16 option = sub_810FA04();
	if (option == -1) { 
		return;
	} else {
		if (option < task->priv[1]) {
			temp_vars.var_800D = option;
			sub_0812FFF0(task_id); //normally sets another task, but we del task
			task_del(task_id);
			superstate.multipurpose_state_tracker = task->priv[0];
		}
		return;
	}

}
	
void msg_normal (char *str){
	//  Bg_id, x,    y,   w,    h,  color, leave, leave
	struct rbox msg_normal = {0, 2, 15, 0x19, 0x4, rboxes[0].pal_id, 0x1, 0};
	u8 box_id = rbox_get_id_something(&msg_normal);
	box_curved(box_id, 1);
	rboxid_tilemap_update(box_id);
	rboxid_clear_pixels(box_id, 17);
	box_related_one(box_id, 2, str, 1, 0, 2, 1, 3);
	rboxid_upload_a(box_id, 3);
}