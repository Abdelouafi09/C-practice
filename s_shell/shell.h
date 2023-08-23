#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

#define INF_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}



/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct arg_info - struct to stock pseudo-arguements to use on functions,
 *
 *@arg: str arguements
 *@argv: array of str from arg
 *@argc: arg count
 *@cmd_path: path for the current command
 *@line_count: error count
 *@err_int: error index for exit functions
 *@line_count_flag: on count the input line
 *@file_name: program filename
 *@env: local copy of environ (linked list)
 *@history: history node
 *@alias: alias node
 *@mod_environ: custom modified copy of environ from LL env
 *@env_changed: environ changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: pointer to cmd_buf
 *@cmd_buf_type: CMD_type ;, &&,||
 *@readfd: read line input's fd
 *@histcount: history count
 */
typedef struct arg_info
{
	char *arg;
	char **argv;
	char *cmd_path;
	int argc;
	unsigned int line_count;
	int err_int;
	int line_count_flag;
	char *file_name;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **mod_environ;
	int env_changed;
	int status;
	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} inf;


/*############################################################################*/




/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096




/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(inf *);
} builtin_table;


/* toem_shloop.c */
int hsh(inf *, char **);
int find_builtin(inf *);
void find_cmd(inf *);
void fork_cmd(inf *);

/* toem_parser.c */
int is_cmd(inf *, char *);
char *dup_chars(char *, int, int);
char *find_path(inf *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* toem_errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* toem_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* toem_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* toem_exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* toem_tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* toem_realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int bfree(void **);

/* toem_atoi.c */
int interactive(inf *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* toem_errors1.c */
int _erratoi(char *);
void print_error(inf *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* toem_builtin.c */
int _myexit(inf *);
int _mycd(inf *);
int _myhelp(inf *);

/* toem_builtin1.c */
int _myhistory(inf *);
int _myalias(inf *);

/*toem_getline.c */
ssize_t get_input(inf *);
int _getline(inf *, char **, size_t *);
void sigintHandler(int);

/* toem_getinfo.c */
void clear_info(inf *);
void set_info(inf *, char **);
void free_info(inf *, int);

/* toem_environ.c */
char *_getenv(inf *, const char *);
int _myenv(inf *);
int _mysetenv(inf *);
int _myunsetenv(inf *);
int populate_env_list(inf *);

/* toem_getenv.c */
char **get_environ(inf *);
int _unsetenv(inf *, char *);
int _setenv(inf *, char *, char *);

/* toem_history.c */
char *get_history_file(inf *info);
int write_history(inf *info);
int read_history(inf *info);
int build_history_list(inf *info, char *buf, int linecount);
int renumber_history(inf *info);

/* toem_lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* toem_lists1.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* toem_vars.c */
int is_chain(inf *, char *, size_t *);
void check_chain(inf *, char *, size_t *, size_t, size_t);
int replace_alias(inf *);
int replace_vars(inf *);
int replace_string(char **, char *);

#endif
