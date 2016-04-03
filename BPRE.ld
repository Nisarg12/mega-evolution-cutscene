
/*
 * Data
 */
 
opponent_party = 0x0202402C;
player_party = 0x02024284;
opponent_character = 0x0203C000;
player_character = 0x0203C014;


/* IO register related */
REG_DISPCNT = 0x04000000;
REG_DISPSTAT = 0x04000004;
REG_vcount = 0x04000006;
BG_CNT = 0x04000008;
BG_POS = 0x04000010;
BG_ROTSCALE = 0x04000020;
WIN_REG = 0x04000040;
REG_MOSAIC = 0x0400004C;
BLD_MOD = 0x04000050;
REG_COLEV = 0x04000052;
REG_COLEY = 0x04000054;
lcd_io_set = 0x08000A38|1;
gpu_bg_config_set_field = 0x080019E4|1;
gpu_pal_apply = 0x080703EC|1;



/* engine related */ 

gpu_pal_alloc_new = 0x080089B8|1;
malloc_and_clear = 0x08002BB0|1;
pal_decompress_slice_to_faded_and_unfaded = 0x080703A8|1;
help_system_disable__sp198 = 0x0812B478|1;
walkrun_state = 0x02037078|1;
mem_set = 0x081E5ED8|1;
memset = 0x081E5ED8|1;
lz77UnCompVram = 0x081E3B6C|1;
c2_exit_to_overworld_1_continue_scripts_and_music = 0x080568C4|1;
vblank_handler_set = 0x080006F4|1;
hblank_handler_set = 0x08000700|1;
CpuSet = 0x081E3B64|1;
tasks_init = 0x080773BC|1;
task_exec = 0x08077578|1;
task_add = 0x0807741C|1;
task_del = 0x08077508|1;
set_callback2 = 0x08000544|1;
set_callback1 = 0x080565E0|1;
dp12_abort = 0x08087E64|1;
copy_queue_process = 0x08007610|1;
__aeabi_idiv = 0x081E4684|1;
__aeabi_uidiv = 0x081E4684|1;
memcpy = 0x081E5E78|1;
tasks = 0x03005090;
superstate = 0x30030F0;
temp_vars = 0x20370B8;
saveblock2 = 0x0300500C;
objc_exec = 0x08006B5C|1;
obj_sync_something = 0x08006BA8|1;
rand = 0x08044EC8|1;
get_attr = 0x0803FBE8|1;


/* box related funcs */
 
remoboxes_acknowledge = 0x08002C28|1;
rboxes = 0x20204B4;
rboxes_free = 0x08003ECC|1;
rboxid_clear_pixels = 0x0800445C|1;
rboxid_tilemap_update = 0x08003FA0|1;
rboxid_upload_a = 0x08003F20|1;
rboxid_80040B8 = 0x080040B8|1;
rboxid_8003E3C = 0x08003E3C|1;
fboxid_get_field = 0x080F79D8|1;
sub_810F7D8 = 0x0810F7D8|1;
box_curved = 0x080F7768|1;
box_related_one = 0x080F6CD0|1;
remoid_a_pressed_maybe = 0x08002E64|1;
sub_0812FFF0 = 0x0812FFF0|1;
sub_807F3A4 = 0x0807F3A4|1;
sub_810FA04 = 0x0810FA04|1;
box_print = 0x0812E51C|1;
rbox_get_id_something = 0x08003CE4|1;

/* string funcs */

str_cpy = 0x08008D84|1;
buffer1 = 0x02022100;
buffer2 = 0x02021CD0;
buffer3 = 0x02021CF0;
buffer4 = 0x02021D04;
string_buffer = 0x02021D18;
fmt_int_10 = 0x08008E78|1;
gf_strcat = 0x08008DA4 |1;


/* OAM related */
objects = 0x0202063C;
obj_and_aux_reset_all = 0x08006B10|1;
gpu_sprites_upload = 0x08007320|1;
gpu_tile_obj_decompress_alloc_tag_and_upload_2 = 0x0800EBCC|1;
gpu_pal_obj_alloc_tag_and_apply = 0x08008928|1;
obj_ids_to_display = 0x02021800;
oac_nullsub = 0x0810BB89;
template_instanciate_forward_search = 0x08006F8C|1;
template_instanciate_reverse_search = 0x08006FE0|1;
gpu_tile_obj_decompress_alloc_tag_and_upload = 0x0800F035;

/* BG related */

gpu_sync_bg_show = 0x080019BC|1;
gpu_sync_bg_hide = 0x080019D0|1;
bgid_mod_x_offset = 0x08001B90|1;
bgid_get_x_offset = 0x08001CCC|1;
bgid_mod_y_offset = 0x08001D08|1;
bgid_get_y_offset = 0x08001E44|1;
bg_vram_setup = 0x08001658|1;
overworld_free_bgmaps = 0x080563F0|1;
gpu_tile_bg_drop_all_sets = 0x08001618|1;

/* Pals related */

pal_fade_control_and_dead_struct_reset = 0x08070528|1;
palette_bg_faded_fill_black = 0x0807DB38 |1;
gpu_pal_apply = 0x080703EC|1;
gpu_pal_upload = 0x08070474|1;
gpu_pal_allocator_reset = 0x080088F0|1;
fade_screen = 0x08070588|1;
palette_bg_faded_fill_white = 0x0807DB14|1;

/* nick name related */

sub_8131168 = 0x08131168|1;
namer = 0x809D954|1;
sub_807E418 = 0x0807E418|1;
sub_80F8268 = 0x080F8268|1;
map_loading_iteration_2_link = 0x08056D44|1;
set_overworld = 0x805F060|1;
nick_name = 0x0203998C;

/* Audio related */
current_map_music_set = 0x08071A74|1;
audio_play = 0x080722CC|1;
