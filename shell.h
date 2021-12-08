#ifndef _SHELL_H_
#define _SHELL_H_
/*
 * File: "shell.h"
 * Author(s): Imanol Asolo    <3848@holbertonschool.com>
 *            Andrés Medina   <3371@holbertonschool.com>
 *            Alex   Arévalo  <3915@holbertonschool.com>
 */

/*DELIMITER MACROS*/
#define NORM_DELIMS " \t\a\r\n"
#define PATH_DELIMS ":"
#define LOGIC_DELIMS "&|;"

/*SWITCH VARIABLES FOR SEPARATORS*/
#define NO_SEPARATOR '\0'
#define AND_LOGIC_SEP '&'
#define OR_LOGIC_SEP '|'
#define COMMAND_SEP ';'


/*LIBRARIES*/
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


/*STRUCTURES*/

/**
 * struct command_s -   Structure of each node.
 * @prev_valid:         Check if previous command was successful.
 * @separator:          Used for character that separates each command.
 * @command:            Points to the first char in the stream.
 * @next:               Address of next node.
 */
typedef struct command_s
{
int                     prev_valid;
char                    separator;
char                  **command;
struct command_s       *next;
} command_t;

/**
 * struct sequence_s -     Structure of sequence.
 * @head:               Pointer to the first node.
 * @tail:               Pointer to the head+1 node.
 */
typedef struct sequence_s
{
command_t              *head, *tail;
} sequence_t;
/**
 * struct history_s -   Structure of history sequence.
 * @command:            Holds the command from getline().
 * @priority_number:    Holds the number coorelated
 *                      to the command input order.
 * @next:               Pointer to the next node.
 */

typedef struct history_s
{
char                   *command;
int                     priority_number;
struct history_s       *next;
} history_t;
/**
 * struct his_q_s -     Structure of sequence
 * @head:               Pointer to the first node
 * @tail:               Pointer to the head+1 node
 */

typedef struct his_q_s
{
history_t              *head, *tail;
} his_q_t;

/*MAIN*/
int                     start_shell(char **environ, char *exec_name);
sequence_t                *parse_string(char *input_str);
int                     execute_commands(his_q_t *his_q, sequence_t *command_q,
	char *envp[], char *exec_name);
char                   *get_file_path(char *filename, char *envp[]);

/*MEMORY FREE*/
void                    free_token_list(char **tokens);
void                    free_command_sequence(sequence_t *command_q);
void                    free_command(command_t *command);

/*COMMANDS QUEUE*/
command_t              *create_command(char separator, char **command);
char                  **strtow(char *str, char *delims);
int                     is_delim(char ch, char *delims);
sequence_t                *make_sequence();

/*QUEUE USAGE*/
int                insequence(sequence_t *seq, char separator, char **command);
command_t              *disequence(sequence_t *seq);
void                    print_queue(sequence_t *seq);

/*HISTORY QUEUE*/
history_t              *create_history_t(char *command, int set_p_no);
void                    free_history_node(history_t *node);
void                    free_history_queue(his_q_t *seq);

/*HISTORY INSEQUENCE/DISEQUENCE*/
his_q_t                *get_history();
his_q_t                *create_h_queue();
int                     h_enqueue(his_q_t *seq, char *command);
history_t              *h_dequeue(his_q_t *seq);
void                    write_h_queue(his_q_t *seq, int fd);

/*WRITING/LOADING HISTORY*/
void                    write_queue_to_file(his_q_t *seq, char **env);

/*ENVIRONMENT*/
extern char **environ;
						/*Functions used inside env.c*/
int is_name_env(char *token, char *env_name);
void advance_env(char **env_token);

/*CUSTOM FUNCS 4 CUSTOM COMMANDS */
void       exit_shell(his_q_t *his_q, sequence_t *seq, int status, char **env);
int                     print_env(char *envp[]);

/*SIGNALS HANDLING*/
void                    signal_handler(int sig_num);
int                     register_signal_handlers(void);

/*CUSTOM STDLIB FUNCTIONS*/
int                    _atoi(char *str);
int                    _strlen(char *str);
char                   *get_int(int num);
char                   *_getenv(char *env_name, char **environ);
char                   *combine_path(char *dir, char *file);

/*PRINT ERRORS*/
void                    print_no_file_error(char *executable_name);
void                    print_perm_denied(char *executable_name);
void                    print_signal_reg_error(void);
void                    print_prompt(void);
void                    print_newline(void);

/*TOKENIZE FUNCTIONS*/
int                     is_delim(char ch, char *delims);
int                     get_word_length(char *str, char *delims);
int                     get_word_count(char *str, char *delims);
char                   *get_next_word(char *str, char *delims);
char                  **strtow(char *str, char *delims);

/*STRING PARSER*/
int                     is_logic(char *token);
char         **get_command_tokens(char **raw_tokens, int beg_ind, int end_ind);

/*EXECUTE COMMANDS*/
int                     can_execute(command_t *command);
int                     is_custom_command(char *token);
int      execute_custom_command(command_t *, char **, his_q_t *, sequence_t *);
int           execute_normal_command(command_t *command, char *envp[], char *);

#endif /*_SHELL_H_*/
