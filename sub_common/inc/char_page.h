/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_page.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:51:04 by clsaad            #+#    #+#             */
/*   Updated: 2021/05/31 13:51:05 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_PAGE_H
# define CHAR_PAGE_H

# include <stdint.h>

char	get_char(uint8_t page, uint8_t charid);
char	*get_char_page(uint8_t page);
char	conv_char(char c, uint8_t *page);

char	*page1(void);
char	*page2(void);
char	*page3(void);
char	*page4(void);
char	*page5(void);
char	*page6(void);
char	*page7(void);

#endif // CHAR_PAGE_H
