/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguidoni <uguidoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:10:33 by uguidoni          #+#    #+#             */
/*   Updated: 2024/08/20 12:40:55 by judetre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <curses.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

typedef struct s_environment
{
	char	**env;
	char	**export;
	int		value;
}			t_environment;

typedef struct s_sort
{
	char			*content;
	int				index;
	struct s_sort	*next;
}					t_sort;

typedef struct s_a_line_browse
{
	char	*a_line;
	int		i;
	int		sucses;
	int		exit_code;
}			t_a_line_browse;

typedef struct s_set_tab_value
{
	int	i;
	int	k;
	int	j;
	int	check;
}			t_set_tab_value;

typedef struct s_redirect
{
	char	**path;
	char	*cmdpath;
	char	*fd_name;
	int		pipefd[2];
	int		save_stdin;
	int		save_stdout;
	int		fd_in;
	int		fd_out;
	int		fd_redirect;
	int		fd_here_on;
	int		i;
}			t_redirect;

typedef struct s_line
{
	char	***tab_a_line;
	char	*a_line;
	char	*a_line2;
	int		*tab_sep;
	char	*getcwd_free;
	int		i;
	int		exit_code;
	int		exit_pipe_check;
}			t_line;

extern int	g_global;

//main
int		ft_check(t_line *s_line, char *cmd);
//signal---------------------------------------
void	ft_sig(void);
void	ft_catc(void);
void	ft_sig_quote(void);
void	ft_sig_handle(void);
//utils ---------------------------------------
char	**ft_tabcpy(char **tab, int size);
char	*ft_str_sup_char(char *str, char c);
int		ft_if_env(char **env, char *var);
int		str_skip_char(char *str, char c, int i);
int		ft_lequal(char *str);
int		ft_lequal2(char *str);
int		ft_icmp(int i1, int i2);
int		ft_lfirstparam(char *str);
int		ft_strlen_tab(char	**tab);
int		ft_strlen_tab2(char	***tab);
char	*ft_after_equal(char *str);
char	*ft_cut(char *str, char c, int count);
char	**ft_tabdup(char **tab);
//put_export, put_env
int		ft_add_envvar_export(char *str, t_environment *s_env, int i, int pass);
int		ft_add_envvar2_export(char *str, t_environment *s_env, int i, int pass);
int		ft_add_envvar2_env(char *str, t_environment *s_env, int i);
int		ft_add_envvar_env(char *str, t_environment *s_env, int i);
int		ft_putexport(char *str, t_environment *s_env, t_line *s_line);
int		ft_putexport_prev(char *str, t_environment *s_env, t_line *s_line);
int		ft_putenv(char *str, t_environment *s_env);
int		ft_join_env(char *str, t_environment *s_env, char *temp);
int		ft_join_export(char *str, t_environment *s_env, int pass);
int		ft_add_envvar_export(char *str, t_environment *s_env, int i, int pass);
//heredoc---------------------------------------
char	*ft_heredoc(char *a_line, t_environment *s_env);
//heredoc utils
int		ft_look_spac(char *str);
int		ft_look_spac2(char *str);
char	*ft_clen_here(char *str);
int		ft_index_here(t_sort *here);
//handles---------------------------------------
char	*ft_handles_operator(t_a_line_browse *browse,
			char **env, int i, int and);
//hendles quote
char	*ft_handles_quote(t_line *s_line, t_environment *s_env);
//hendles utils
int		ft_str_c_number(char *str, char *c);
char	*ft_str_add_char(char *str, char *c);
char	*ft_deljoin(char *str1, char *str2);
char	*ft_supchar(char *str, int start, char *strsup);
int		ft_quote_skip_char(char *a_line, int i);
int		ft_quote_skip(t_line *s_line, int i);
char	*ft_new_a_line(t_a_line_browse *browse, char *env, int size, int i);
//hendles fork
char	*ft_write_term(char *a_line, t_environment *s_env, char *c,
			int here_on);
char	*ft_write_term_sav(char *a_line, t_environment *s_env, char *c,
			int here_on);
//hendles str utils
int		ft_str_c_number(char *str, char *c);
char	*ft_str_add_char(char *str, char *c);
char	*ft_deljoin(char *str1, char *str2);
char	*ft_supchar(char *str, int start, char *strsup);
//hendles fork utils
void	ft_fillsave(char *a_line, char *name);
char	*ft_returnsave(void);
void	ft_exit_hear(char *line, char *tmp, char *a_line);
int		check_stop_condition(char *tmp, char *stop, int here_on);
//hendles split
char	**ft_handles_split(char *s, char c);
//hendles split utils
char	*ft_set_tmp(char *tmp, char *str, int i, int j);
size_t	ft_count_words(char *s, char c);
char	*ft_substr_split(char *s, unsigned int st, size_t l, char **t);
//set_tab
char	*ft_set_a_line_tab(t_line *s_line, t_a_line_browse browse,
			t_environment *s_env);
void	ft_set_sep(t_line *s_line, t_set_tab_value *set_value,
			t_environment *s_env, t_a_line_browse browse);
int		*ft_realloc_int_tab(t_line *s_line, t_environment *s_env,
			t_a_line_browse browse);
char	***ft_realloc_tab(char ***t_tab, t_line *s_line, t_environment *s_env,
			t_a_line_browse browse);
void	ft_check_redirections(t_line *s_line, t_set_tab_value *set_value,
			t_environment *s_env, t_a_line_browse browse);

//env, export    ---------------------------------------
void	ft_env(char **env, char *a_line, t_line *s_line);
char	*ft_getenv(char *arg, char **env);
void	ft_export(char *a_line, t_environment *s_env, t_line *s_line, int i);
void	ft_print_export(t_environment *s_env, int i);
void	ft_export_pipe(char *a_line, t_environment *s_env, t_line *s_line,
			t_redirect *s_redirect);
//unset
void	ft_unset(char *a_line, t_environment *s_env, t_line *s_line);
//execve ---------------------------------------
void	ft_execve(t_line *s_line, t_environment *s_env);
char	*ft_executable(char *cmd);
char	*ft_access(char **path, char *cmd, char *cmd_next);
char	*ft_path(t_line *s_line, t_environment *s_env, t_redirect *s_redirect,
			int check);
void	ft_execve2(t_line *s_line, t_environment *s_env, char **path,
			char **cmd);
//execve utils
void	ft_print_error(char *cmd);
char	*ft_access(char **path, char *cmd, char *cmd_next);
void	ft_free_double_tab(char **tab, int i);
int		ft_check_builtin(char *tmp);
char	**handle_cmd_without_space(t_line *s_line, char **path);
//execve functions
char	*ft_path(t_line *s_line, t_environment *s_env,
			t_redirect *s_redirect, int check);
int		ft_parsing(char *a_line);
char	*ft_executable(char *cmd);
//CDM    ---------------------------------------
//cd
void	ft_cd(t_line *s_line, t_environment *s_env);
void	ft_cd_pipe(char *a_line, t_line *s_line, t_environment *s_env,
			t_redirect *s_redirect);
//echo
void	ft_echo(char *a_line, t_line *s_line);
//exit  ---------------------------------------
void	ft_exit(t_line *s_line, t_environment *s_env);
int		ft_exit_pipe(t_line *s_line, t_environment *s_env,
			t_redirect *s_redirect);
int		ft_exit_no_params(t_line *s_line);
//sort   ---------------------------------------
t_sort	*ft_sortnew(char *content);
t_sort	*ft_sortlast(t_sort *lst);
void	ft_sortadd_back(t_sort **lst, t_sort *new);
void	ft_sortfree(t_sort **lst);
int		ft_strcmp(char *s1, char *s2);
//sort2
t_sort	*indexsort(t_sort *lst);
char	**ft_sort_export(char **tab);
//exec	---------------------------------------
void	ft_reset_a_line(t_line *s_line);
void	ft_exec(t_line *s_line, t_environment *s_env);
void	ft_set_a_line2(t_line *s_line, t_redirect *s_redirect);
//exec_error
int		ft_exec_error(t_line *s_line);
int		ft_point_error(char *cmd, char *cmd_next);
//exec_pipe
void	handle_builtin_commands(t_redirect *s_redirect, t_line *s_line,
			t_environment *s_env);
int		is_builtin_command_lst(char *cmd);
char	*ft_access_pipe(char **path, char *cmd, char *cmd_next);
void	ft_call_funcs_pipe(t_redirect *s_redirect, t_line *s_line,
			t_environment *s_env);
int		ft_redirection(t_redirect *s_redirect, t_line *s_line,
			t_environment *s_env, int i);
int		ft_redirection2(t_redirect *s_redirect, t_line *s_line,
			t_environment *s_env, int i);
int		ft_redirection_weird(t_redirect *s_redirect, t_line *s_line,
			t_environment *s_env, int i);
char	*ft_fd_load(void);
//exec utils
int		is_builtin_command(char *cmd, const char *builtin);
void	ft_call_funcs_pipe(t_redirect *s_redirect, t_line *s_line,
			t_environment *s_env);
void	ft_set_a_line2(t_line *s_line, t_redirect *s_redirect);
int		ft_white_list(t_line *s_line, int i);
void	ft_call_funcs(t_line *s_line, t_environment *s_env);
//exec cmd
void	ft_pipe(t_redirect *s_redirect, t_line *s_line, t_environment *s_env);
//exec lastcmd
void	ft_lastcmd(t_redirect *s_redirect, t_line *s_line,
			t_environment *s_env);
//free
void	ft_free_env2(char **env);
void	ft_free_env(t_environment *s_env);
void	ft_free_tab_a_line(char ***tab_a_line);
void	ft_free_s_line(t_line *s_line, int f);
void	ft_free_pipe(t_redirect *s_pipe);
void	ft_free_env3(char **env);
//free2
void	ft_free_child(t_redirect *s_redirect, t_line *s_line,
			t_environment *s_env, int i);
//malloc protection, other protections
void	ft_malloc_error(t_line *s_line, t_environment *s_env,
			t_redirect *s_redirect);
void	ft_malloc_error_s_line(t_line *s_line);
void	ft_malloc_error_s_env(t_environment *s_env);
void	ft_malloc_error_s_redirect(t_redirect *s_redirect);
void	ft_malloc_error_set_tab(t_line *s_line, t_environment *s_env,
			t_redirect *s_redirect, t_a_line_browse browse);
void	ft_fork_error(t_line *s_line, t_environment *s_env,
			t_redirect *s_redirect);
void	ft_dup_error(t_line *s_line, t_environment *s_env,
			t_redirect *s_redirect);
void	ft_dup2_error(t_line *s_line, t_environment *s_env,
			t_redirect *s_redirect);
void	ft_pipe_error(t_line *s_line, t_environment *s_env,
			t_redirect *s_redirect);

#endif
