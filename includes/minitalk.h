/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:07:42 by mda-enca          #+#    #+#             */
/*   Updated: 2025/09/18 17:08:04 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include <bits/types.h>

//Utils//
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *str);
bool	check_null(char *str);
bool	check_digits(int c);
int		ft_atoi(const char *nptr);

//Server//
void	handle_sig(int sig, siginfo_t *info, void *ctx);
char	*add_char(char *initial_str, char char_to_add, int pid);

//Client//
void	send_char(char c, int current_bit, int pid);
void	sig_handler(int sig, siginfo_t *info, void *context);
void	send_message(int pid, char *message);

#endif
