#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define BUFSIZE_TOK 128
#define DELIM_TOK " \t\r\n\a"


/**
 * struct data - holds all relevant runtime data
 * @argv: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **argv;
	char *input;
	char **args;
	int stat;
	int counter;
	char **_environ;
	char *pid;
} data_struct;

/**
 * struct link_sep_s - single linked list
 * @separator: ; | &
 * @next: next node
 * 
 * Description: single linked list to store separators
 */
typedef struct link_sep_s
{
	char separator;
	struct link_sep_s *next;
} link_sep;

/**
 * struct link_line_s - single linked list
 * @line: command line
 * @next: next node
 * 
 * Description: single linked list to store command lines
 */
typedef struct link_line_s
{
	char *line;
	struct link_line_s *next;
} link_line;

/**
 * struct link_var_r - single linked list
 * @v_len: len of the variable
 * @val: value of the variable
 * @len_val: len of the value
 * @next: next node
 * 
 * Description: single linked list to store variables
 */
typedef struct link_var_r
{
	int v_len;
	char *val;
	int len_val;
	struct link_var_r *next;
} link_var;

/**
 * struct bn_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @g: data type pointer function.
 */
typedef struct bn_s
{
	char *name;
	int (*g)(data_struct *d_sh);
} bn_t;

/* aux_lists.c */
link_sep *add_sep_node_end(link_sep **head, char sep);
void free_link_sep(link_sep **head);
link_line *add_line_node_end(link_line **head, char *line);
void free_link_line(link_line **head);

/* aux_lists2.c */
link_var *add_rvar_node(link_var **head, int lvar, char *var, int lval);
void free_rvar_list(link_var **head);

/* _str functions */
char *_cat(char *dest, const char *src);
char *_cpy(char *dest, char *src);
int _cmp(char *s1, char *s2);
char *_chr(char *str, char c);
int _spn(char *str, char *accept);

/* _mem.c */
void _memcpy(void *new, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int size_o, unsigned int size_n);
char **_realloc_d(char **ptr, unsigned int size_o, unsigned int size_n);

/* _str2.c */
char *_strdup(const char *str);
int _len(const char *str);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *str);

/* _str3.c */
void rev_string(char *str);

/* check_syntax_error.c */
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(data_struct *d_sh, char *input, int i, int bool);
int check_syntax_error(data_struct *d_sh, char *input);

/* shell_loop.c */
char *del_comments(char *in);
void shell_loop(data_struct *d_sh);

/* readline.c */
char *readline(int *i_eof);

/* split.c */
char *swap_char(char *input, int bool);
void add_nodes(link_sep **head_s, link_line **head_l, char *input);
void go_next(link_sep **list_s, link_line **list_l, data_struct *d_sh);
int split_commands(data_struct *d_sh, char *input);
char **split_line(char *input);

/* stringvar_rep.c */
void conf_env(link_var **h, char *in, data_struct *data);
int conf_vars(link_var **h, char *in, char *st, data_struct *data);
char *string_rep(link_var **head, char *input, char *new_input, int nlen);
char *stringvar_rep(char *input, data_struct *d_sh);

/* get_line.c */
void assign_line(char **lineptr, size_t *n, char *buf, size_t size_b);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* fnd_cmd */
int fnd_cmd(data_struct *d_sh);

/* cmd_exec.c */
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(data_struct *d_sh);
int check_error_cmd(char *dir, data_struct *d_sh);
int cmd_exec(data_struct *d_sh);

/* env1.c */
char *get_env(const char *name, char **_environ);
int _env(data_struct *d_sh);

/* env2.c */
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, data_struct *d_sh);
int _cmpenv(data_struct *d_sh);
int _delenv(data_struct *d_sh);

/* cd.c */
void cd_dot(data_struct *d_sh);
void cd_to(data_struct *d_sh);
void cd_previous(data_struct *d_sh);
void cd_to_home(data_struct *d_sh);

/* change_cd.c */
int change_cd(data_struct *d_sh);

/* _bn_cmd */
int (*_bn_cmd(char *cmd))(data_struct *d_sh);

/* _exit.c */
int sh_exit(data_struct *d_sh);

/* _stdlib.c */
int get_len(int n);
char *_atos(int n);
int _atoi(char *str);


char *cat_cd(data_struct *, char *, char *, char *);
char *cd_error(data_struct *d_sh);
char *error_not_found(data_struct *d_sh);
char *error_sh_exit(data_struct *d_sh);


char *error_get_alias(char **args);
char *err_msg(data_struct *d_sh);
char *error_syntax(char **args);
char *error_permission(char **args);
char *path_perm_err(data_struct *d_sh);


/* call_error.c */
int call_error(data_struct *d_sh, int eval);

/* sig_handl.c */
void sig_handl(int sig);

/* _help.c */
void _help_env(void);
void _help_cmpenv(void);
void _help_delenv(void);
void _help_general(void);
void _help_exit(void);

/* _help2.c */
void _help(void);
void _help_alias(void);
void _help_cd(void);

int get_help(data_struct *d_sh);

#endif
