#!/bin/sh
PATH='/Users/lcabanes/Documents/branche_algo_et_IA/projet_lem_in'
mkdir ${PATH}/tmp_dir
mv ${PATH}/lem_in.h ${PATH}/tmp_dir/
mv ${PATH}/srcs_lem_in/li_allocate_map.c ${PATH}/tmp_dir/
mv ${PATH}/srcs_lem_in/li_bellman_ford.c ${PATH}/tmp_dir/
mv ${PATH}/srcs_lem_in/li_bhandari.c ${PATH}/tmp_dir/
mv ${PATH}/srcs_lem_in/li_memory_liberator.c ${PATH}/tmp_dir/
mv ${PATH}/srcs_lem_in/li_shorten_map_pipes.c ${PATH}/tmp_dir/
mv ${PATH}/ebauche_order_rooms/lem_in.h ${PATH}/srcs_lem_in/
mv ${PATH}/ebauche_order_rooms/li_allocate_map.c ${PATH}/srcs_lem_in/
mv ${PATH}/ebauche_order_rooms/li_bellman_ford.c ${PATH}/srcs_lem_in/
mv ${PATH}/ebauche_order_rooms/li_bhandari.c ${PATH}/srcs_lem_in/
mv ${PATH}/ebauche_order_rooms/li_memory_liberator.c ${PATH}/srcs_lem_in/
mv ${PATH}/ebauche_order_rooms/li_shorten_map_pipes.c ${PATH}/srcs_lem_in/
rm -d ${PATH}/ebauche_order_rooms
mv ${PATH}/tmp_dir ${PATH}/ebauche_order_rooms
