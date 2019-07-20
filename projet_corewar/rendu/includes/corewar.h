/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:15:35 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/21 00:41:27 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"

# define IS_DUMP(str)	ft_strequ(str, "-dump")
# define IS_N(str)		ft_strequ(str, "-n")
# define IS_V(str)		(ft_strequ(str, "-v") || ft_strequ(str, "--verbose"))
# define IS_C(str)		(ft_strequ(str, "-c") || ft_strequ(str, "--colors"))
# define IS_HELP(str)	(ft_strequ(str, "-h") || ft_strequ(str, "--help"))
# define IS_CHAMP(str)	ft_strstr(str, ".cor")

# define OPT_DUMP		(1)
# define OPT_N			(1 << 1)
# define OPT_V			(1 << 2)
# define OPT_C			(1 << 3)
# define OPT_1			(1 << 4)
# define OPT_2			(1 << 5)
# define OPT_3			(1 << 6)
# define OPT_4			(1 << 7)

# define INDEX(pc)		((pc) % MEM_SIZE)
# define IS_VALID_OP_CODE(op)		((op) > 0x0 && (op) <= 0x10)

# define LIVE		{{0x80, 0, 0}, {0}, {0}}
# define LD			{{0x80, 0xc0, 0}, {0x10, 0, 0}, {0}}
# define ST			{{0x40, 0, 0}, {0x10, 0x30, 0}, {0}}
# define ADD		{{0x40, 0, 0}, {0x10, 0, 0}, {0x4, 0, 0}}
# define SUB		{{0x40, 0, 0}, {0x10, 0, 0}, {0x4, 0, 0}}
# define AND		{{0x40, 0x80, 0xc0}, {0x10, 0x20, 0x30}, {0x4, 0x8, 0xc}}
# define OR			{{0x40, 0x80, 0xc0}, {0x10, 0x20, 0x30}, {0x4, 0x8, 0xc}}
# define XOR		{{0x40, 0x80, 0xc0}, {0x10, 0x20, 0x30}, {0x4, 0x8, 0xc}}
# define ZJMP		{{0x80, 0, 0}, {0}, {0}}
# define LDI		{{0x40, 0x80, 0xc0}, {0x10, 0x20, 0}, {0x4, 0, 0}}
# define STI		{{0x40, 0, 0}, {0x10, 0x20, 0x30}, {0x4, 0x8, 0}}
# define FORK		{{0x80, 0, 0}, {0}, {0}}
# define LLD		{{0x80, 0xc0, 0}, {0x10, 0, 0}, {0}}
# define LLDI		{{0x40, 0x80, 0xc0}, {0x10, 0x20, 0}, {0x4, 0, 0}}
# define LFORK		{{0x80, 0, 0}, {0}, {0}}
# define AFF		{{0x40, 0, 0}, {0}, {0}}

# define BOLDGREEN		"\033[01m\033[32m"
# define BOLDBLUE		"\033[01m\033[34m"
# define BOLDRED		"\033[01m\033[31m"
# define BOLDMAGENTA	"\033[01m\033[35m"

typedef struct			s_champion
{
	unsigned int		*r;
	unsigned short		pc;
	int					carry;
	int					cycle_to_wait;

	int					go;
	unsigned char		op;
	unsigned char		ocp;
	unsigned short		src;
	int					*av;

	size_t				live;
	int					is_dead;
	int					token;
	int					id;
	char				*name;
	char				*comment;
	unsigned char		*process;
	int					size;
	int					*n;
	struct s_champion	*next;
	struct s_champion	**start;
	struct s_champion	**last;
}						t_champ;

/*
**	option
**	0    0    0    0      0    0    0    0
**	4    3    2    1     -c   -v   -n   -dump
*/
typedef struct			s_environment
{
	unsigned char		*memory;
	unsigned char		option;
	unsigned char		force_token;
	int					cycle_to_dump;
	int					cycle;
	int					cycle_to_die;
	unsigned char		last_alive;
	int					total_live;
	t_champ				**tab;
}						t_env;

/*
**	global
*/
t_env					g_env;
t_champ					*g_champ;
static char				*g_color[5] = {NULL,\
	BOLDGREEN, BOLDBLUE, BOLDRED, BOLDMAGENTA};

/*
**	main.c
*/
int						main(int ac, char **av);

/*
**	init.c
*/
void					init_env(void);
t_champ					*init_champ(char exist);
t_champ					*init_fork(t_champ *champ);

/*
**	input.c
*/
void					check_input(char *str, char next_is_int);

/*
**	champion.c
*/
void					add_champion(void);
void					edit_name_comment(int fd, int size, char which);
void					edit_size(int fd);
void					edit_process(int fd);

/*
**	process.c
*/
void					init_process(int fd);
void					add_process_to_memory(int gap, int token);

/*
**	play.c
*/
void					play(int i, int cycle_to_check);

/*
**	decode.c
*/
int						*disassemble(unsigned char ocp, unsigned char op,\
		int ac, unsigned short *pc);
int						is_dir_code(unsigned short *pc, unsigned char op);

/*
**	tools.c
*/
int						checksum(unsigned char ocp, unsigned char op, int ac);
int						isolate_2bit(unsigned char ocp, int i);
void					write_memory(unsigned short i, int val);
int						read_4byte(unsigned short i);
short					read_2byte(unsigned short i);

/*
**	outputs.c
*/
void					introduce(t_champ **tab);
void					usage(void);

/*
**	exit.c
*/
void					kill(int error, char *str);
void					dump(void);
void					winner(t_champ **tab, int token);
void					free_all(void);

void					live(t_champ *champ, int *av, unsigned char ocp,\
		unsigned short pc);
void					ld(t_champ *champ, int *av, unsigned char ocp,\
		unsigned short pc);
void					st(t_champ *champ, int *av, unsigned char ocp,\
		unsigned short pc);
void					add(t_champ *champ, int *av, unsigned char ocp,\
		unsigned short pc);
void					sub(t_champ *champ, int *av, unsigned char ocp,\
		unsigned short pc);
void					and_(t_champ *champ, int *av, unsigned char ocp,\
		unsigned short pc);
void					or_(t_champ *champ, int *av, unsigned char ocp,\
		unsigned short pc);
void					xor_(t_champ *champ, int *av, unsigned char ocp,\
		unsigned short pc);
void					zjmp(t_champ *champ, int *av, unsigned char ocp,\
		unsigned short pc);
void					ldi(t_champ *champ, int *av, unsigned char ocp,\
		unsigned short pc);
void					sti(t_champ *champ, int *av, unsigned char ocp,\
		unsigned short pc);
void					fork_(t_champ *champ, int *av, unsigned char ocp,\
		unsigned short pc);
void					lld(t_champ *champ, int *av, unsigned char ocp,\
		unsigned short pc);
void					lldi(t_champ *champ, int *av, unsigned char ocp,\
		unsigned short pc);
void					lfork(t_champ *champ, int *av, unsigned char ocp,\
		unsigned short pc);
void					aff(t_champ *champ, int *av, unsigned char ocp,\
		unsigned short pc);

void					print_test(void);

#endif

/*
** # define LIVE			{0x2, 0, 0}
** # define LD				{0x3, 0x1, 0}
** # define ST             {0x1, 0x3, 0}
** # define ADD			{0x1, 0x1, 0x1}
** # define SUB			{0x1, 0x1, 0x1}
** # define AND			{0x3, 0x3, 0x1}
** # define OR				{0x3, 0x3, 0x1}
** # define XOR			{0x3, 0x3, 0x1}
** # define ZJMP			{0x2, 0, 0}
** # define LDI			{0x3, 0x3, 0x1}
** # define STI			{0x1, 0x3, 0x3}
** # define FORK			{0x2, 0 ,0}
** # define LLD			{0x3, 0x1, 0}
** # define LLDI			{0x3, 0x3, 0x1}
** # define LFORK			{0x2, 0, 0}
** # define AFF			{0x1, 0, 0}
**
** # define LIVE			{0x80, 0, 0}
** # define LD				{0xc0, 0x10, 0}
** # define ST             {0x40, 0x30, 0}
** # define ADD			{0x40, 0x10, 0x4}
** # define SUB			{0x40, 0x10, 0x4}
** # define AND			{0xc0, 0x30, 0x4}
** # define OR				{0xc0, 0x30, 0x4}
** # define XOR			{0xc0, 0x30, 0x4}
** # define ZJMP			{0x80, 0, 0}
** # define LDI			{0xc0, 0x30, 0x4}
** # define STI			{0x40, 0x30, 0xc}
** # define FORK			{0x80, 0 ,0}
** # define LLD			{0xc0, 0x10, 0}
** # define LLDI			{0xc0, 0x30, 0x4}
** # define LFORK			{0x80, 0, 0}
** # define AFF			{0x40, 0, 0}
*/
